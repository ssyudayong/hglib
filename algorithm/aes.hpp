

#pragma once

#define AES_CALCMINSIZE(s) ( ( (size_t)s / 16 ) + (( ( (size_t)s % 16 ) == 0 ) ? 0 : 16 ) )

namespace hg { namespace algorithm { 
	class aes
	{
	public:
		typedef enum : int
		{
			aes128=128,
			aes192=192,
			aes256=256
		} key_size;
	public:
		aes(hg::algorithm::aes::key_size ks = aes256);
		hg::error_code encrypt(const void * plaintext, void * cipher);
		hg::error_code encrypt(const void * plaintext, size_t plaintextsize, void * cipher);
		hg::error_code decrypt(const void * cipher, void *plaintext);
		hg::error_code decrypt(const void * cipher, size_t ciphersize, void *plaintext);
		hg::error_code encrypt_cbc(const void * plaintext, size_t size, void * cipher);
		hg::error_code decrypt_cbc(const void * cipher, size_t size, void *plaintext);
	public:
		void set_key(const void * key, size_t size);
		void set_iv(const void * iv, size_t size);
		void reset_iv();
	private:
		unsigned long m_key_schedule[64];
		unsigned char m_iv[16];
		unsigned char m_temp_iv[16];
		int m_keysize;
	};
} }