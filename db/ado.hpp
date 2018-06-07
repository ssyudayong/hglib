#pragma once

#include "hg\db\database.hpp"
#include "hg\buffer.hpp"

namespace hg { namespace db { namespace ado{
	namespace errors
	{
		typedef enum
		{
			adSuccess=0,
			adErrProviderFailed = 3000,
			adErrInvalidArgument = 3001,
			adErrOpeningFile = 3002,
			adErrReadFile = 3003,
			adErrWriteFile = 3004,
			adErrNoCurrentRecord = 3021,
			adErrIllegalOperation = 3219,
			adErrCantChangeProvider = 3220,
			adErrInTransaction = 3246,
			adErrFeatureNotAvailable = 3251,
			adErrItemNotFound = 3265,
			adErrObjectInCollection = 3367,
			adErrObjectNotSet = 3420,
			adErrDataConversion = 3421,
			adErrObjectClosed = 3704,
			adErrObjectOpen = 3705,
			adErrProviderNotFound = 3706,
			adErrBoundToCommand = 3707,
			adErrInvalidParamInfo = 3708,
			adErrInvalidConnection = 3709,
			adErrNotReentrant = 3710,
			adErrStillExecuting = 3711,
			adErrOperationCancelled = 3712,
			adErrStillConnecting = 3713,
			adErrInvalidTransaction = 3714,
			adErrNotExecuting = 3715,
			adErrUnsafeOperation = 3716,
			adwrnSecurityDialog = 3717,
			adwrnSecurityDialogHeader = 3718,
			adErrIntegrityViolation = 3719,
			adErrPermissionDenied = 3720,
			adErrDataOverflow = 3721,
			adErrSchemaViolation = 3722,
			adErrSignMismatch = 3723,
			adErrCantConvertvalue = 3724,
			adErrCantCreate = 3725,
			adErrColumnNotOnThisRow = 3726,
			adErrURLDoesNotExist = 3727,
			adErrTreePermissionDenied = 3728,
			adErrInvalidURL = 3729,
			adErrResourceLocked = 3730,
			adErrResourceExists = 3731,
			adErrCannotComplete = 3732,
			adErrVolumeNotFound = 3733,
			adErrOutOfSpace = 3734,
			adErrResourceOutOfScope = 3735,
			adErrUnavailable = 3736,
			adErrURLNamedRowDoesNotExist = 3737,
			adErrDelResOutOfScope = 3738,
			adErrPropInvalidColumn = 3739,
			adErrPropInvalidOption = 3740,
			adErrPropInvalidValue = 3741,
			adErrPropConflicting = 3742,
			adErrPropNotAllSettable = 3743,
			adErrPropNotSet = 3744,
			adErrPropNotSettable = 3745,
			adErrPropNotSupported = 3746,
			adErrCatalogNotSet = 3747,
			adErrCantChangeConnection = 3748,
			adErrFieldsUpdateFailed = 3749,
			adErrDenyNotSupported = 3750,
			adErrDenyTypeNotSupported = 3751,
			adErrProviderNotSpecified = 3753,
			adErrConnectionStringTooLong = 3754
		}error_code;
	}
	namespace field_status
	{
		typedef enum : long
		{
			adFieldAlreadyExists 	=26, 	//ָʾָ�����ֶ��Ѵ��ڡ�
			adFieldBadStatus 	=12, 	//ָʾ�� ADO ������Ч��״ֵ̬��OLE DB ���ʽӿڡ� ���ܵ�ԭ����� OLE DB 1.0 �� 1.1 �ṩ�������ϲ���ȷ��ֵ��״̬��
			adFieldCannotComplete 	=20, 	//ָʾָ���� URL �ķ�����Դ�޷���ɸò�����
			adFieldCannotDeleteSource 	=23, 	//ָʾ���ƶ������������������Ƶ���λ�ã����޷�ɾ��Դ��
			adFieldCantConvertValue 	=2, 	//ָʾ���ֶβ��ܼ�����洢�����ᶪʧ���ݡ�
			adFieldCantCreate 	=7, 	//ָʾ�����ṩ���򳬹������� �����ֶ�����������������ܲ�����ֶΡ�
			adFieldDataOverflow 	=6, 	//ָʾ���ṩ���򷵻ص���������ֶε��������͡�
			adFieldDefault 	=13, 	//ָʾ��������ʱ��ʹ�ø��ֶε�Ĭ��ֵ��
			adFieldDoesNotExist 	=16, 	//ָʾָ�����ֶβ����ڡ�
			adFieldIgnore 	=15, 	//ָʾ��Դ����������ֵʱ�������ֶΡ� �ṩ���������κ�ֵ��
			adFieldIntegrityViolation 	=10, 	//ָʾ�����޸��ֶΣ���Ϊ���Ǽ����������ʵ�塣
			adFieldInvalidURL 	=17, 	//ָʾ����Դ URL ������Ч�ַ���
			adFieldIsNull 	=3, 	//ָʾ�ṩ���򷵻������� VT_NULL �ı���ֵ���ֶβ�Ϊ�ա�
			adFieldOK 	=0, 	//Ĭ��ֵ�� ָʾ�ѳɹ���ӻ�ɾ���ֶΡ�
			adFieldOutOfSpace 	=22, 	//ָʾ�ṩ�����޷���ȡ�㹻�Ĵ洢�ռ�������ƶ����Ʋ�����
			adFieldPendingChange 	=0x40000, 	//ָʾ�ֶξ�����ɾ�������������ӣ����ܾ��в�ͬ���������ͣ�����ǰ״̬���ֶε�ֵ��adFieldOK�Ѹ��ġ� ���޸ĵ��ֶε�������ʽ�ֶκ�ļ��ϸ��µ��÷�����
			adFieldPendingDelete 	=0x20000,	//ָʾɾ����������Ҫ���õ�״̬�� �ֶ��ѱ��Ϊɾ���ֶκ�ļ��ϸ��µ��÷�����
			adFieldPendingInsert 	=0x10000, 	//ָʾ׷�Ӳ�������Ҫ���õ�״̬�� �ֶα��ΪҪ��ӵ��ֶκ�ļ��ϸ��µ��÷�����
			adFieldPendingUnknown 	=0x80000, 	//ָʾ�ṩ�����޷�ȷ��Ҫ������Щ���������ֶ�״̬��
			adFieldPendingUnknownDelete 	=0x100000, 	//ָʾ�ṩ������ȷ���ĸ���������Ҫ���õ��ֶ�״̬���ֶΣ���ɾ�����ֶκ�ļ��ϸ��µ��÷�����
			adFieldPermissionDenied 	=9, 	//ָʾ�����޸��ֶΣ���Ϊ��������Ϊֻ���ġ�
			adFieldReadOnly 	=24, 	//ָʾ����Դ�е��ֶζ���Ϊֻ����
			adFieldResourceExists 	=19, 	//ָʾ�ṩ�����޷�ִ�иò�������Ϊ��Ŀ�� URL �Ѵ��ڵĶ��󣬲��Ҳ����Ը��Ǹö���
			adFieldResourceLocked 	=18, 	//ָʾ�ṩ�����޷�ִ�иò�������Ϊ����Դ�ѱ�һ����������Ӧ�ó�������������
			adFieldResourceOutOfScope 	=25, 	//��ʾԴ��Ŀ��� URL �ĵ�ǰ��¼��������֮�⡣
			adFieldSchemaViolation 	=11, 	//ָʾֵΥ���˸��ֶε�����Դ�ܹ�Լ����
			adFieldSignMismatch 	=5, 	//ָʾ�ṩ���򷵻ص�����ֵ��ǩ������ ADO �ֶ�ֵ�������������޷��š�
			adFieldTruncated 	=4, 	//ָʾ������Դ��ȡ����ʱ���ɱ䳤�������ѱ��ضϡ�
			adFieldUnavailable 	=8, 	//ָʾ�ṩ�����޷�������Դ��ȡ����ʱȷ����ֵ�� ���磬�ոմ������С� �е�Ĭ��ֵ�����ã���һ���µ�ֵδ��δָ��һ����
			adFieldVolumeNotFound 	=21 	//ָʾ�ṩ�������Ҳ����� URL ��ʾ�Ĵ洢��
		}value_type;
	}
	namespace data_type
	{
		// https://docs.microsoft.com/zh-cn/sql/ado/reference/ado-api/datatypeenum?view=sql-server-2017
		// http://www.w3school.com.cn/ado/app_datatypeenum.asp
		typedef enum : int
		{
			AdArray            = 0x2000, 	//��־ֵ������һ���������͵ĳ�����ָʾ�����������͵�����ʼ�ս��ʹ�á� �������� ADOX��
			adBigInt           = 20, 	    //ָʾ�� 8 �ֽ��з��ŵ�����(�� DBTYPE_I8)��
			adBinary           = 128, 	    //ָʾһ��������ֵ(DBTYPE_BYTES)��
			adBoolean          = 11, 	    //ָʾ����ֵ(DBTYPE_BOOL)��
			adBSTR             = 8, 	    //ָʾ�� null ��β���ַ���(Unicode) (DBTYPE_BSTR)��
			adChapter          = 136, 	    //ָʾ���ڱ�ʶ���м�(DBTYPE_HCHAPTER) �е��е� 4 �ֽ���ֵ��
			adChar             = 129, 	    //ָʾһ���ַ���ֵ(DBTYPE_STR)��
			adCurrency         = 6, 	    //��ʾ����ֵ(DBTYPE_CY)�� ������С����Ĵ����ĸ������Ҳ�Ķ������֡� ���洢�ڰ� 10, 000 ���ŵ� 8 �ֽ��з���������
			adDate             = 7, 	    //ָʾ����ֵ(DBTYPE_DATE)�� ���ڴ洢Ϊ˫�����ͣ����е������������� 1899 �� 12 �� 30 ��������������С��������һ��Ĳ��֡�
			adDBDate           = 133, 	    //ָʾ����ֵ(yyyymmdd) (DBTYPE_DBDATE)��
			adDBTime           = 134, 	    //ָʾʱ��ֵ(hhmmss) (DBTYPE_DBTIME)��
			adDBTimeStamp      = 135, 	    //ָʾ���� / ʱ��� ��yyyymmddhhmmss ������ billionths �ķ�����ʽ��(DBTYPE_DBTIMESTAMP)��
			adDecimal          = 14, 	    //ָʾ���й̶��ľ��Ⱥ�С��λ��(DBTYPE_DECIMAL) �ľ�ȷ��ֵ��
			adDouble           = 5, 	    //ָʾһ��˫���ȸ���ֵ(DBTYPE_R8)��
			adEmpty            = 0, 	    //δָ���κ�ֵ(DBTYPE_EMPTY)��
			adError            = 10, 	    //��ʾ 32 λ�������(DBTYPE_ERROR)��
			adFileTime         = 64, 	    //ָʾ��(DBTYPE_FILETIME) 1601 �� 1 �� 1 �ձ�ʾ�� 100 ��΢������� 64 λֵ��
			adGUID             = 72, 	    //ָʾȫ��Ψһ��ʶ��(GUID) (DBTYPE_GUID)��
			adIDispatch        = 9, 	    //ָʾһ��ָ��IDispatch COM ����(DBTYPE_IDISPATCH) �ϵĽӿڡ���ע��ADO ��ǰ��֧�ִ��������͡� ʹ��������ܻᵼ�²���Ԥ֪�Ľ����
			adInteger          = 3, 	    //ָʾһ�� 4 �ֽ��з��ŵ�����(DBTYPE_I4)��
			adIUnknown         = 13, 	    //ָʾһ��ָ��IUnknown COM ����(DBTYPE_IUNKNOWN) �ϵĽӿڡ���ע��ADO ��ǰ��֧�ִ��������͡� ʹ��������ܻᵼ�²���Ԥ֪�Ľ����
			adLongVarBinary    = 205, 	    //ָʾ���ȵĶ�����ֵ��
			adLongVarChar      = 201, 	    //ָʾһ�����ַ���ֵ��
			adLongVarWChar     = 203, 	    //ָʾһ����ʱ���� null ��β�� Unicode �ַ���ֵ��
			adNumeric          = 131, 	    //ָʾ���й̶��ľ��Ⱥ�С��λ��(DBTYPE_NUMERIC) �ľ�ȷ��ֵ��
			adPropVariant      = 138, 	    //ָʾ�Զ��� PROPVARIANT(DBTYPE_PROP_VARIANT)��
			adSingle           = 4, 	    //ָʾһ�������ȸ���ֵ(DBTYPE_R4)��
			adSmallInt         = 2, 	    //ָʾ�����ֽ��з��ŵ�����(DBTYPE_I2)��
			adTinyInt          = 16, 	    //ָʾһ�����ֽ��з��ŵ�����(DBTYPE_I1)��
			adUnsignedBigInt   = 21, 	    //ָʾһ�� 8 �ֽ��޷��ŵ�����(DBTYPE_UI8)��
			adUnsignedInt      = 19, 	    //ָʾ�� 4 �ֽ��޷��ŵ�����(DBTYPE_UI4)��
			adUnsignedSmallInt = 18, 	    //ָʾ�����ֽ��޷��ŵ�����(DBTYPE_UI2)��
			adUnsignedTinyInt  = 17, 	    //ָʾһ�����ֽ��޷��ŵ�����(DBTYPE_UI1)��
			adUserDefined      = 132, 	    //ָʾ�û�������� �����⣬dbtype_udt ������
			adVarBinary        = 204, 	    //ָʾһ��������ֵ��
			adVarChar          = 200, 	    //ָʾһ���ַ���ֵ��
			adVariant          = 12, 	    //ָʾ�Զ���Variant(DBTYPE_VARIANT)����ע��ADO ��ǰ��֧�ִ��������͡� ʹ��������ܻᵼ�²���Ԥ֪�Ľ����
			adVarNumeric       = 139, 	    //ָʾ����ֵ��
			adVarWChar         = 202, 	    //ָʾ�� null ��β�� Unicode �ַ��ַ�����
			adWChar            = 130, 	    //ָʾ�� null ��β Unicode �ַ����ַ���(DBTYPE_WSTR)��
		} value_type;
	}
	namespace connect_mode
	{
		// https://docs.microsoft.com/en-us/sql/ado/reference/ado-api/connectmodeenum?view=sql-server-2017
		typedef enum
		{
			//Constant 			 Value 		 Description
			adModeRead			 = 1, 		 //Indicates read - only permissions.
			adModeReadWrite		 = 3, 		 //Indicates read / write permissions.
			adModeRecursive		 = 0x400000, //Used in conjunction with the other **ShareDeny** values(adModeShareDenyNone, adModeShareDenyWrite, or adModeShareDenyRead) to propagate sharing restrictions to all sub - records of the current Record.It has no affect if the Record does not have any children.A run - time error is generated if it is used with adModeShareDenyNone only.However, it can be used with adModeShareDenyNone when combined with other values.For example, you can use "adModeRead Or adModeShareDenyNone Or adModeRecursive".
			adModeShareDenyNone  = 16, 		 //Allows others to open a connection with any permissions.Neither read nor write access can be denied to others.
			adModeShareDenyRead  = 4, 		 //Prevents others from opening a connection with read permissions.
			adModeShareDenyWrite = 8,	 	 //Prevents others from opening a connection with write permissions.
			adModeShareExclusive = 12, 		 //Prevents others from opening a connection.
			adModeUnknown		 = 0, 		 //Default.Indicates that the permissions have not yet been set or cannot be determined.
			adModeWrite			 = 2 		 //Indicates write - only permissions.
		} valuetype;
	}
	namespace cursor_location
	{
		typedef enum
		{
			adUseClient =3,	// Uses client - side cursors supplied by a local cursor library.
							// Local cursor services often will allow many features that driver - supplied cursors may not, 
							// so using this setting may provide an advantage with respect to features that will be enabled.
							// For backward compatibility, the synonym adUseClientBatch is also supported.
			adUseNone   =1,	// Does not use cursor services. 
							// (This constant is obsolete and appears solely for the sake of backward compatibility.)
			adUseServer =2 	//Default.
							// Uses cursors supplied by the data provider or driver.
							// These cursors are sometimes very flexible and allow for additional sensitivity 
							// to changes others make to the data source.However, 
							// some features of the The Microsoft Cursor Service for OLE DB, such as disassociated
							// Recordset objects, cannot be simulated with server - side cursors and 
							// these features will be unavailable with this setting.
		}value_type;
	}
	namespace cursor_type
	{
		typedef enum
		{
			adOpenUnspecified = -1,
			adOpenForwardOnly = 0,
			adOpenKeyset      = 1,
			adOpenDynamic     = 2,
			adOpenStatic      = 3
		}value_type;
	}
	namespace cursor_option
	{
		typedef enum
		{
			adHoldRecords    = 256,
			adMovePrevious   = 512,
			adAddNew         = 16778240,
			adDelete         = 16779264,
			adUpdate         = 16809984,
			adBookmark       = 8192,
			adApproxPosition = 16384,
			adUpdateBatch    = 65536,
			adResync         = 131072,
			adNotify         = 262144,
			adFind           = 524288,
			adSeek           = 4194304,
			adIndex          = 8388608
		} value_type;
	}
	namespace lock_type
	{
		typedef enum
		{
			adLockUnspecified     = -1,
			adLockReadOnly        = 1,
			adLockPessimistic     = 2,
			adLockOptimistic      = 3,
			adLockBatchOptimistic = 4
		}value_type;
	}
	namespace execute_option
	{
		typedef enum
		{
			adOptionUnspecified     = -1,
			adAsyncExecute          = 16,
			adAsyncFetch            = 32,
			adAsyncFetchNonBlocking = 64,
			adExecuteNoRecords      = 128,
			adExecuteStream         = 1024,
			adExecuteRecord         = 2048
		}value_type;
	}
	namespace connect_option
	{
		typedef enum
		{
			adConnectUnspecified = -1,
			adAsyncConnect = 16
		}value_type;
	}
	namespace object_state
	{
		typedef enum
		{
			adStateClosed = 0,
			adStateOpen = 1,
			adStateConnecting = 2,
			adStateExecuting = 4,
			adStateFetching = 8
		}value_type;
	}
	namespace field_attribute
	{
		typedef enum
		{
			adFldUnspecified = -1,
			adFldMayDefer = 2,
			adFldUpdatable = 4,
			adFldUnknownUpdatable = 8,
			adFldFixed = 16,
			adFldIsNullable = 32,
			adFldMayBeNull = 64,
			adFldLong = 128,
			adFldRowID = 256,
			adFldRowVersion = 512,
			adFldCacheDeferred = 4096,
			adFldIsChapter = 8192,
			adFldNegativeScale = 16384,
			adFldKeyColumn = 32768,
			adFldIsRowURL = 65536,
			adFldIsDefaultStream = 131072,
			adFldIsCollection = 262144
		}value_type;
	}
	namespace edit_mode
	{
		typedef enum
		{
			adEditNone = 0,
			adEditInProgress = 1,
			adEditAdd = 2,
			adEditDelete = 4
		}value_type;
	}
	namespace record_status
	{
		typedef enum
		{
			adRecOK = 0,
			adRecNew = 1,
			adRecModified = 2,
			adRecDeleted = 4,
			adRecUnmodified = 8,
			adRecInvalid = 16,
			adRecMultipleChanges = 64,
			adRecPendingChanges = 128,
			adRecCanceled = 256,
			adRecCantRelease = 1024,
			adRecConcurrencyViolation = 2048,
			adRecIntegrityViolation = 4096,
			adRecMaxChangesExceeded = 8192,
			adRecObjectOpen = 16384,
			adRecOutOfMemory = 32768,
			adRecPermissionDenied = 65536,
			adRecSchemaViolation = 131072,
			adRecDBDeleted = 262144
		}value_type;
	}
	namespace command_type
	{
		typedef enum
		{
			adCmdUnspecified = -1,
			adCmdUnknown = 8,
			adCmdText = 1,
			adCmdTable = 2,
			adCmdStoredProc = 4,
			adCmdFile = 256,
			adCmdTableDirect = 512
		}value_type;
	}
	namespace schema_id
	{
		enum : long
		{
			adSchemaProviderSpecific = -1,
			adSchemaAsserts = 0,
			adSchemaCatalogs = 1,
			adSchemaCharacterSets = 2,
			adSchemaCollations = 3,
			adSchemaColumns = 4,
			adSchemaCheckConstraints = 5,
			adSchemaConstraintColumnUsage = 6,
			adSchemaConstraintTableUsage = 7,
			adSchemaKeyColumnUsage = 8,
			adSchemaReferentialContraints = 9,
			adSchemaReferentialConstraints = 9,
			adSchemaTableConstraints = 10,
			adSchemaColumnsDomainUsage = 11,
			adSchemaIndexes = 12,
			adSchemaColumnPrivileges = 13,
			adSchemaTablePrivileges = 14,
			adSchemaUsagePrivileges = 15,
			adSchemaProcedures = 16,
			adSchemaSchemata = 17,
			adSchemaSQLLanguages = 18,
			adSchemaStatistics = 19,
			adSchemaTables = 20,
			adSchemaTranslations = 21,
			adSchemaProviderTypes = 22,
			adSchemaViews = 23,
			adSchemaViewColumnUsage = 24,
			adSchemaViewTableUsage = 25,
			adSchemaProcedureParameters = 26,
			adSchemaForeignKeys = 27,
			adSchemaPrimaryKeys = 28,
			adSchemaProcedureColumns = 29,
			adSchemaDBInfoKeywords = 30,
			adSchemaDBInfoLiterals = 31,
			adSchemaCubes = 32,
			adSchemaDimensions = 33,
			adSchemaHierarchies = 34,
			adSchemaLevels = 35,
			adSchemaMeasures = 36,
			adSchemaProperties = 37,
			adSchemaMembers = 38,
			adSchemaTrustees = 39,
			adSchemaFunctions = 40,
			adSchemaActions = 41,
			adSchemaCommands = 42,
			adSchemaSets = 43
		};
	}
	namespace isolation_level
	{
		enum : long
		{
			adXactUnspecified = -1,
			adXactChaos = 16,
			adXactReadUncommitted = 256,
			adXactBrowse = 256,
			adXactCursorStability = 4096,
			adXactReadCommitted = 4096,
			adXactRepeatableRead = 65536,
			adXactSerializable = 1048576,
			adXactIsolated = 1048576
		};
	}
	namespace impl
	{
		class connection_impl;
		typedef std::shared_ptr<connection_impl> connection_impl_sp;
		class recordset_impl;
		typedef std::shared_ptr<recordset_impl> recordset_impl_sp;
		class command_impl;
		typedef std::shared_ptr<command_impl> command_impl_sp;
		class parameter_impl;
		typedef std::shared_ptr<parameter_impl> parameter_impl_sp;
	}

	typedef struct
	{
		long id;
		std::wstring desc;
	} ado_error;

	typedef std::vector<ado_error> ado_error_list;
	typedef std::shared_ptr<ado_error_list> ado_error_list_sp;
	
	class Recordset;
	typedef std::shared_ptr<Recordset> RecordsetSP;
	typedef std::shared_ptr<Recordset> recordset_sp;

	class Connection
	{	
	public:
		Connection();
		virtual ~Connection();
		ado_error_list_sp get_errors();
		void set_mode(hg::db::ado::connect_mode::valuetype value);
		void set_connectstring(const std::wstring& value);
		void set_timeout(long value);
		long get_timeout();
		long get_isolation_level();
		void set_isolation_level(long value);
		size_t errors_count();
		bool OpenAccessFile(
			const std::wstring& filename,
			const std::wstring& username,
			const std::wstring& password);
		long open(
			const std::wstring &connectstring,
			const std::wstring& userid,
			const std::wstring &password,
			connect_option::value_type opt = connect_option::adConnectUnspecified);
		long close();
		recordset_sp execute(const std::wstring& commandtext, long & lines, long opt);
		bool Open();
		void Close();
		bool IsOpen();
		void RefreshCache();
		void BeginTransaction();
		void CommitTransaction();
		void RollbackTransaction();
		bool get_all_tablename(std::vector<std::wstring> &list);
		bool get_table_fieldinfo_list(const std::wstring& tablename, std::vector<hg::db::field_info> &list);
		bool get_table_fieldinfo_list_a(const std::wstring& tablename, std::vector<hg::db::field_info> &list);
		impl::connection_impl_sp impl();
		bool refresh_cache(hg::error_code &ec);
		static bool compact_database(const std::wstring& src, const std::wstring& desc, hg::error_code &ec);
	private:
		impl::connection_impl_sp m_impl;
		std::wstring m_ProviderStr;
		std::wstring m_User;
		std::wstring m_Password;
		std::wstring m_FileName;
	};

	class Recordset
	{
	public:
		Recordset(impl::recordset_impl_sp rssp);
		virtual ~Recordset();
		void Close();
		bool IsOpen();
		bool Eof();
		bool Bof();
		bool Empty();
		void First();
		void Next();
		void Prev();
		void Last();
		bool FieldValueIsNull(const std::wstring &fieldname);
		bool FieldValueIsEmpty(const std::wstring &fieldname);
		bool field_is_numeric(const std::wstring &fieldname);
		hg::db::ado::data_type::value_type get_field_type(const std::wstring &fieldname);
		void GetFieldValue(const std::wstring &fieldname, int &value);
		void GetFieldValue(const std::wstring &fieldname, long &value);
		void GetFieldValue(const std::wstring &fieldname, unsigned long &value);
		void GetFieldValue(const std::wstring &fieldname, double &value);
		void GetFieldValue(const std::wstring &fieldname, std::wstring &value);
		void GetFieldValue(const std::wstring &fieldname, wchar_t * value, size_t maxsize);
		void GetFieldValue(const std::wstring &fieldname, SYSTEMTIME &value);
		bool get_field_value(const std::wstring &fieldname, hg::sys_time& value);
		bool get_field_value(const std::wstring &fieldname, std::wstring &value);
		bool get_field_value(const std::wstring &fieldname, double &value);
		bool get_field_value(const std::wstring &fieldname, size_t &value);
		bool get_field_value(const std::wstring &fieldname, bool &value);
		void GetFieldValue(const std::wstring &fieldname, bool &value);
		void GetFieldValue(const std::wstring &fieldname, void *value, size_t maxsize, size_t &datasize);
		hg::error_code get_fieldvalue(const std::wstring &fieldname, double &value);
		hg::error_code get_fieldvalue(const std::wstring &fieldname, hg::buffer &value);
		std::size_t RecordCount();
		size_t properties_count();
		size_t fields_count();
		std::wstring field_name(long index);
		data_type::value_type field_type(long index);
		size_t field_actual_length(long index);
		size_t field_defined_length(long index);
		field_status::value_type field_status(long index);
		cursor_location::value_type get_cursor_location();
		void set_cursor_location(cursor_location::value_type value);
		impl::recordset_impl_sp impl();
	private:
		impl::recordset_impl_sp m_impl;
		//Connection& m_Connection;
	};
	class Command
	{
	public:
		typedef enum
		{
			ctCmdUnspecified = -1,
			ctCmdUnknown     = 8,
			ctCmdText        = 1,
			ctCmdTable       = 2,
			ctCmdStoredProc  = 4,
			ctCmdFile        = 256,
			ctCmdTableDirect = 512
		} CommandType;
	public:
		Command(Connection& c);
		virtual ~Command();
		bool Execute(int &lines);
		void SetSqlText(const std::wstring& sql);
		void SetCommandType(CommandType value);
		void SetTimeout(long value);
		bool AddParam(const std::wstring& strName, void * value, size_t size);
		bool AddParam(const std::wstring& strName, const SYSTEMTIME &value);
		bool add_param(const std::wstring& strName, const hg::sys_time &value);
		bool AddParam(const std::wstring& strName, const std::wstring& value);
		bool AddParam(const std::wstring& strName, double value);
		bool AddParam(const std::wstring& strName, bool value);
		bool AddParam(const std::wstring& strName, int value);
		bool AddParam(const std::wstring& strName, size_t value);
		RecordsetSP Open();
		RecordsetSP open_schema(int id, const std::wstring& name);
	private:
		impl::command_impl_sp m_impl;
		Connection& m_Connection;
	};
	//class Parameter
	//{
	//public:
	//	Parameter(int nType, long lSize, int nDirection, const std::wstring& strName);
	//	virtual ~Parameter();
	//private:
	//	impl::parameter_impl_sp m_impl;
	//};
}}}


