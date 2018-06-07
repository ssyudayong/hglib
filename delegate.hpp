

#pragma once

namespace hg
{
	namespace details
	{
		template<int... Idcs> class hgindices {};
		template<int N, int... Idcs> struct hgindicesbuilder : hgindicesbuilder<N - 1, N - 1, Idcs...> {};
		template<int... Idcs> struct hgindicesbuilder<0, Idcs...> { typedef hgindices<Idcs...> indices; };
		template<class... Args> class hgdelegatearguments
		{
		public:
			hgdelegatearguments(Args&&... args) : m_args(std::forward_as_tuple(std::forward<Args>(args)...)) {}
		public:
			std::tuple<Args&&...> m_args;
		};

		class hgdelegatedatainterface abstract
		{
		public:
			virtual void call(void*) = 0;
			virtual void call_with_bound_args() = 0;
			virtual void bind_args(void*) = 0;
		protected:
			void* m_pBound_args;
		};
		template<class...Args> class hgdelegatedata : public hgdelegatedatainterface {};

		template<class R, class O, class... Args> class hgdelegatedata<R, O, R(Args...)> : public hgdelegatedatainterface
		{
		public:
			typedef R(O::*M)(Args...);
			hgdelegatedata(O* pObj, M pMethod) : m_pObj(pObj), m_pMethod(pMethod) {}
			template<class...Args>
			void operator()(Args... args) { (m_pObj->*m_pMethod)(std::forward<Args>(args)...); }
			void call(void* pArgs) override { invoker(typename hgindicesbuilder<sizeof...(Args)>::indices(), pArgs); }
			template<int...Idcs>
			void invoker(hgindices<Idcs...>, void* pArgs)
			{
				auto pArguments = static_cast<hgdelegatearguments<Args...>*>(pArgs);
				(m_pObj->*m_pMethod)(std::get<Idcs>(pArguments->m_args)...);
			}
		public:
			hgdelegatedata(O* pObj, M pMethod, Args&&... argsToBind) : m_pObj(pObj), m_pMethod(pMethod)
			{
				bind_args(new hgdelegatearguments<Args&&...>(std::forward<Args>(argsToBind)...));
			}
			virtual void bind_args(void* argsToBind) override
			{
				if (argsToBind != m_pBound_args)
				{
					delete m_pBound_args;
					m_pBound_args = argsToBind;
				}
			}
			void call_with_bound_args() override
			{
				invoker(typename hgindicesbuilder<sizeof...(Args)>::indices(), m_pBound_args);
			}
		private:
			O * m_pObj;
			M  m_pMethod;
		};

		template<class R, class... Args> class hgdelegatedata<R, R(*)(Args...)> : public hgdelegatedatainterface
		{
		public:
			typedef R(*F)(Args...);
			hgdelegatedata(F pF) : m_pF(pF) {}
			template<class...Args>
			void operator()(Args... args)
			{
				m_pF(args...);
			}
			void call(void* pArgs) override
			{
				invoker(typename hgindicesbuilder<sizeof...(Args)>::indices(), pArgs);
			}
			template<int...Idcs>
			void invoker(hgindices<Idcs...>, void* pArgs)
			{
				auto pArguments = static_cast<hgdelegatearguments<Args...>*>(pArgs);
				m_pF(std::get<Idcs>(pArguments->m_args)...);
			}
		public:
			hgdelegatedata(F pF, Args&&... argsToBind) : m_pF(pF)
			{
				bind_args(new hgdelegatearguments<Args&&...>(std::forward<Args>(argsToBind)...));
			}
			virtual void bind_args(void* argsToBind) override
			{
				if (argsToBind != m_pBound_args)
				{
					delete m_pBound_args;
					m_pBound_args = argsToBind;
				}
			}
			void call_with_bound_args() override
			{
				invoker(typename hgindicesbuilder<sizeof...(Args)>::indices(), m_pBound_args);
			}
		private:
			F m_pF;
		};

		template<class...Args> class hgdelegatebase
		{
		public:
			hgdelegatebase() = default;
			template<class R, class O>
			explicit hgdelegatebase(O* pObj, R(O::*M)(Args...)) { bind(pObj, M); }
			template<class R, class O, class...ArgsToBind>
			explicit hgdelegatebase(O* m_pObj, R(O::*M)(Args...), ArgsToBind&&... argsToBind)
			{
				bind(m_pObj, M, std::forward<ArgsToBind>(argsToBind)...);
			}
			template<class R>
			explicit hgdelegatebase(R(*F)(Args...)) { bind(F); }
			template<class R, class...ArgsToBind>
			explicit hgdelegatebase(R(*F)(Args...), ArgsToBind&&... argsToBind)
			{
				bind(F, std::forward<ArgsToBind>(argsToBind)...);
			}
		public:
			template<class R, class O>
			void bind(O* pObj, R(O::*M)(Args...))
			{
				m_data = new hgdelegatedata<R, O, R(Args...)>(pObj, M);
			}
			template<class R, class O, class...ArgsToBind>
			void bind(O* pObj, R(O::*M)(Args...), ArgsToBind&&... argsToBind)
			{
				m_data = new hgdelegatedata<R, O, R(Args...)>(pObj, M, std::forward<ArgsToBind>(argsToBind)...);
			}
			template<class R>
			void bind(R(*F)(Args...))
			{
				m_data = new hgdelegatedata<R, R(*)(Args...)>(F);
			}
			template<class R, class...ArgsToBind>
			void bind(R(*F)(Args...), ArgsToBind&&... args)
			{
				m_data = new hgdelegatedata<R, R(*)(Args...)>(F, std::forward<ArgsToBind>(args)...);
			}
		public:
			void operator()(Args&&... args)
			{
				m_data->call(new hgdelegatearguments<Args...>(std::forward<Args>(args)...));
			}
			void bind_args(Args&&... args)
			{
				m_data->bind_args(new hgdelegatearguments<Args...>(std::forward<Args>(args)...));
			}
			void call_with_bound_args() { m_data->call_with_bound_args(); }
		private:
			hgdelegatedatainterface * m_data;
		};
	}

	template<class ...dArgs>
	class delegate
	{
	public:
		template<class R, class O>
		void add(O* pObj, R(O::*M)(dArgs...)) { m_delegates.emplace_back(details::hgdelegatebase<dArgs...>(pObj, M)); }
		template<class...cArgs>
		void add(cArgs&&... args) { m_delegates.emplace_back(std::forward<cArgs>(args)...); }
		void launch() { for (auto& d : m_delegates) { d.call_with_bound_args(); } }
		void operator()(dArgs... args) { for (auto& eh : m_delegates) { eh(std::forward<dArgs>(args)...); } }
	public:
		details::hgdelegatebase<dArgs...>& operator[](unsigned int idx) { return m_delegates[idx]; }
	private:
		std::vector<details::hgdelegatebase<dArgs...>> m_delegates;
	};
}