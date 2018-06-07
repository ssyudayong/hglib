


#pragma once

#ifndef _HG_DB_DATABASE_HPP_
#define _HG_DB_DATABASE_HPP_

namespace hg { namespace db {
	
	
	// https://docs.microsoft.com/zh-cn/sql/ado/reference/ado-api/datatypeenum?view=sql-server-2017
	// http://www.w3school.com.cn/ado/app_datatypeenum.asp
	typedef enum : int
	{
		AdArray 	=0x2000, 	//标志值，与另一个数据类型的常量，指示其他数据类型的数组始终结合使用。 不适用于 ADOX。
		adBigInt 	=20, 	//指示的 8 字节有符号的整数(是 DBTYPE_I8)。
		adBinary 	=128, 	//指示一个二进制值(DBTYPE_BYTES)。
		adBoolean 	=11, 	//指示布尔值(DBTYPE_BOOL)。
		adBSTR 	=8, 	//指示以 null 结尾的字符串(Unicode) (DBTYPE_BSTR)。
		adChapter 	=136, 	//指示用于标识子行集(DBTYPE_HCHAPTER) 中的行的 4 字节章值。
		adChar 	=129, 	//指示一个字符串值(DBTYPE_STR)。
		adCurrency 	=6, 	//表示货币值(DBTYPE_CY)。 货币是小数点的带有四个数字右侧的定点数字。 它存储在按 10, 000 缩放的 8 字节有符号整数。
		adDate 	=7, 	//指示日期值(DBTYPE_DATE)。 日期存储为双精度型，其中的整个部分是自 1899 年 12 月 30 日以来的天数的小数部分是一天的部分。
		adDBDate 	=133, 	//指示日期值(yyyymmdd) (DBTYPE_DBDATE)。
		adDBTime 	=134, 	//指示时间值(hhmmss) (DBTYPE_DBTIME)。
		adDBTimeStamp 	=135, 	//指示日期 / 时间戳 （yyyymmddhhmmss 加上以 billionths 的分数形式）(DBTYPE_DBTIMESTAMP)。
		adDecimal 	=14, 	//指示具有固定的精度和小数位数(DBTYPE_DECIMAL) 的精确数值。
		adDouble 	=5, 	//指示一个双精度浮点值(DBTYPE_R8)。
		adEmpty 	=0, 	//未指定任何值(DBTYPE_EMPTY)。
		adError 	=10, 	//表示 32 位错误代码(DBTYPE_ERROR)。
		adFileTime 	=64, 	//指示从(DBTYPE_FILETIME) 1601 年 1 月 1 日表示的 100 毫微秒隔数的 64 位值。
		adGUID 	=72, 	//指示全局唯一标识符(GUID) (DBTYPE_GUID)。
		adIDispatch 	=9, 	//指示一个指向IDispatch COM 对象(DBTYPE_IDISPATCH) 上的接口。
							// 请注意ADO 当前不支持此数据类型。 使用情况可能会导致不可预知的结果。
		adInteger 	=3, 	//指示一个 4 字节有符号的整数(DBTYPE_I4)。
		adIUnknown 	=13, 	//指示一个指向IUnknown COM 对象(DBTYPE_IUNKNOWN) 上的接口。
							// 请注意ADO 当前不支持此数据类型。 使用情况可能会导致不可预知的结果。
		adLongVarBinary 	=205, 	//指示长度的二进制值。
		adLongVarChar 	=201, 	//指示一个长字符串值。
		adLongVarWChar 	=203, 	//指示一个长时间以 null 结尾的 Unicode 字符串值。
		adNumeric 	=131, 	//指示具有固定的精度和小数位数(DBTYPE_NUMERIC) 的精确数值。
		adPropVariant 	=138, 	//指示自动化 PROPVARIANT(DBTYPE_PROP_VARIANT)。
		adSingle 	=4, 	//指示一个单精度浮点值(DBTYPE_R4)。
		adSmallInt 	=2, 	//指示两个字节有符号的整数(DBTYPE_I2)。
		adTinyInt 	=16, 	//指示一个单字节有符号的整数(DBTYPE_I1)。
		adUnsignedBigInt 	=21, 	//指示一个 8 字节无符号的整数(DBTYPE_UI8)。
		adUnsignedInt 	=19, 	//指示的 4 字节无符号的整数(DBTYPE_UI4)。
		adUnsignedSmallInt 	=18, 	//指示两个字节无符号的整数(DBTYPE_UI2)。
		adUnsignedTinyInt 	=17, 	//指示一个单字节无符号的整数(DBTYPE_UI1)。
		adUserDefined 	=132, 	//指示用户定义变量 （以外，dbtype_udt 还）。
		adVarBinary 	=204, 	//指示一个二进制值。
		adVarChar 	=200, 	//指示一个字符串值。
		adVariant 	=12, 	//指示自动化Variant(DBTYPE_VARIANT)。请注意ADO 当前不支持此数据类型。 使用情况可能会导致不可预知的结果。
		adVarNumeric 	=139, 	//指示数字值。
		adVarWChar 	=202, 	//指示以 null 结尾的 Unicode 字符字符串。
		adWChar 	=130, 	//指示以 null 结尾 Unicode 字符的字符串(DBTYPE_WSTR)。
	} datatype;
	typedef struct
	{
		std::wstring name;
		datatype	 type;
		size_t		 defined_size;
	}field_info;
	//typedef std::vector<field_info> field_info_list;
} }

#endif // _HG_DB_DATABASE_HPP_
