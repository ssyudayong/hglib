


#pragma once

#ifndef _HG_DB_DATABASE_HPP_
#define _HG_DB_DATABASE_HPP_

namespace hg { namespace db {
	
	
	// https://docs.microsoft.com/zh-cn/sql/ado/reference/ado-api/datatypeenum?view=sql-server-2017
	// http://www.w3school.com.cn/ado/app_datatypeenum.asp
	typedef enum : int
	{
		AdArray 	=0x2000, 	//��־ֵ������һ���������͵ĳ�����ָʾ�����������͵�����ʼ�ս��ʹ�á� �������� ADOX��
		adBigInt 	=20, 	//ָʾ�� 8 �ֽ��з��ŵ�����(�� DBTYPE_I8)��
		adBinary 	=128, 	//ָʾһ��������ֵ(DBTYPE_BYTES)��
		adBoolean 	=11, 	//ָʾ����ֵ(DBTYPE_BOOL)��
		adBSTR 	=8, 	//ָʾ�� null ��β���ַ���(Unicode) (DBTYPE_BSTR)��
		adChapter 	=136, 	//ָʾ���ڱ�ʶ���м�(DBTYPE_HCHAPTER) �е��е� 4 �ֽ���ֵ��
		adChar 	=129, 	//ָʾһ���ַ���ֵ(DBTYPE_STR)��
		adCurrency 	=6, 	//��ʾ����ֵ(DBTYPE_CY)�� ������С����Ĵ����ĸ������Ҳ�Ķ������֡� ���洢�ڰ� 10, 000 ���ŵ� 8 �ֽ��з���������
		adDate 	=7, 	//ָʾ����ֵ(DBTYPE_DATE)�� ���ڴ洢Ϊ˫�����ͣ����е������������� 1899 �� 12 �� 30 ��������������С��������һ��Ĳ��֡�
		adDBDate 	=133, 	//ָʾ����ֵ(yyyymmdd) (DBTYPE_DBDATE)��
		adDBTime 	=134, 	//ָʾʱ��ֵ(hhmmss) (DBTYPE_DBTIME)��
		adDBTimeStamp 	=135, 	//ָʾ���� / ʱ��� ��yyyymmddhhmmss ������ billionths �ķ�����ʽ��(DBTYPE_DBTIMESTAMP)��
		adDecimal 	=14, 	//ָʾ���й̶��ľ��Ⱥ�С��λ��(DBTYPE_DECIMAL) �ľ�ȷ��ֵ��
		adDouble 	=5, 	//ָʾһ��˫���ȸ���ֵ(DBTYPE_R8)��
		adEmpty 	=0, 	//δָ���κ�ֵ(DBTYPE_EMPTY)��
		adError 	=10, 	//��ʾ 32 λ�������(DBTYPE_ERROR)��
		adFileTime 	=64, 	//ָʾ��(DBTYPE_FILETIME) 1601 �� 1 �� 1 �ձ�ʾ�� 100 ��΢������� 64 λֵ��
		adGUID 	=72, 	//ָʾȫ��Ψһ��ʶ��(GUID) (DBTYPE_GUID)��
		adIDispatch 	=9, 	//ָʾһ��ָ��IDispatch COM ����(DBTYPE_IDISPATCH) �ϵĽӿڡ�
							// ��ע��ADO ��ǰ��֧�ִ��������͡� ʹ��������ܻᵼ�²���Ԥ֪�Ľ����
		adInteger 	=3, 	//ָʾһ�� 4 �ֽ��з��ŵ�����(DBTYPE_I4)��
		adIUnknown 	=13, 	//ָʾһ��ָ��IUnknown COM ����(DBTYPE_IUNKNOWN) �ϵĽӿڡ�
							// ��ע��ADO ��ǰ��֧�ִ��������͡� ʹ��������ܻᵼ�²���Ԥ֪�Ľ����
		adLongVarBinary 	=205, 	//ָʾ���ȵĶ�����ֵ��
		adLongVarChar 	=201, 	//ָʾһ�����ַ���ֵ��
		adLongVarWChar 	=203, 	//ָʾһ����ʱ���� null ��β�� Unicode �ַ���ֵ��
		adNumeric 	=131, 	//ָʾ���й̶��ľ��Ⱥ�С��λ��(DBTYPE_NUMERIC) �ľ�ȷ��ֵ��
		adPropVariant 	=138, 	//ָʾ�Զ��� PROPVARIANT(DBTYPE_PROP_VARIANT)��
		adSingle 	=4, 	//ָʾһ�������ȸ���ֵ(DBTYPE_R4)��
		adSmallInt 	=2, 	//ָʾ�����ֽ��з��ŵ�����(DBTYPE_I2)��
		adTinyInt 	=16, 	//ָʾһ�����ֽ��з��ŵ�����(DBTYPE_I1)��
		adUnsignedBigInt 	=21, 	//ָʾһ�� 8 �ֽ��޷��ŵ�����(DBTYPE_UI8)��
		adUnsignedInt 	=19, 	//ָʾ�� 4 �ֽ��޷��ŵ�����(DBTYPE_UI4)��
		adUnsignedSmallInt 	=18, 	//ָʾ�����ֽ��޷��ŵ�����(DBTYPE_UI2)��
		adUnsignedTinyInt 	=17, 	//ָʾһ�����ֽ��޷��ŵ�����(DBTYPE_UI1)��
		adUserDefined 	=132, 	//ָʾ�û�������� �����⣬dbtype_udt ������
		adVarBinary 	=204, 	//ָʾһ��������ֵ��
		adVarChar 	=200, 	//ָʾһ���ַ���ֵ��
		adVariant 	=12, 	//ָʾ�Զ���Variant(DBTYPE_VARIANT)����ע��ADO ��ǰ��֧�ִ��������͡� ʹ��������ܻᵼ�²���Ԥ֪�Ľ����
		adVarNumeric 	=139, 	//ָʾ����ֵ��
		adVarWChar 	=202, 	//ָʾ�� null ��β�� Unicode �ַ��ַ�����
		adWChar 	=130, 	//ָʾ�� null ��β Unicode �ַ����ַ���(DBTYPE_WSTR)��
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
