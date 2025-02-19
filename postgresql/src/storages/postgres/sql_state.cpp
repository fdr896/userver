#include <userver/storages/postgres/sql_state.hpp>

#include <unordered_map>
#include <unordered_set>

#include <boost/multiprecision/integer.hpp>

USERVER_NAMESPACE_BEGIN

namespace storages::postgres {

namespace {

// Data was generated by userver/scripts/postgres/pg_sql_codes.py
const std::unordered_map<std::string_view, SqlState> kCodeStrToState{
    //@{
    /** @name Class 00 — Successful Completion */
    {"00000", SqlState::kSuccessfulCompletion},
    //@}
    //@{
    /** @name Class 01 — Warning */
    {"01000", SqlState::kWarning},
    {"0100C", SqlState::kDynamicResultSetsReturned},
    {"01008", SqlState::kImplicitZeroBitPadding},
    {"01003", SqlState::kNullValueEliminatedInSetFunction},
    {"01007", SqlState::kPrivilegeNotGranted},
    {"01006", SqlState::kPrivilegeNotRevoked},
    {"01004", SqlState::kStringDataRightTruncationWarn},
    {"01P01", SqlState::kDeprecatedFeature},
    //@}
    //@{
    /** @name Class 02 — No Data (this is also a warning class per the SQL
       standard) */
    {"02000", SqlState::kNoData},
    {"02001", SqlState::kNoAdditionalDynamicResultSetsReturned},
    //@}
    //@{
    /** @name Class 03 — SQL Statement Not Yet Complete */
    {"03000", SqlState::kSqlStatementNotYetComplete},
    //@}
    //@{
    /** @name Class 08 — Connection Exception */
    {"08000", SqlState::kConnectionException},
    {"08003", SqlState::kConnectionDoesNotExist},
    {"08006", SqlState::kConnectionFailure},
    {"08001", SqlState::kSqlclientUnableToEstablishSqlconnection},
    {"08004", SqlState::kSqlserverRejectedEstablishmentOfSqlconnection},
    {"08007", SqlState::kTransactionResolutionUnknown},
    {"08P01", SqlState::kProtocolViolation},
    //@}
    //@{
    /** @name Class 09 — Triggered Action Exception */
    {"09000", SqlState::kTriggeredActionException},
    //@}
    //@{
    /** @name Class 0A — Feature Not Supported */
    {"0A000", SqlState::kFeatureNotSupported},
    //@}
    //@{
    /** @name Class 0B — Invalid Transaction Initiation */
    {"0B000", SqlState::kInvalidTransactionInitiation},
    //@}
    //@{
    /** @name Class 0F — Locator Exception */
    {"0F000", SqlState::kLocatorException},
    {"0F001", SqlState::kInvalidLocatorSpecification},
    //@}
    //@{
    /** @name Class 0L — Invalid Grantor */
    {"0L000", SqlState::kInvalidGrantor},
    {"0LP01", SqlState::kInvalidGrantOperation},
    //@}
    //@{
    /** @name Class 0P — Invalid Role Specification */
    {"0P000", SqlState::kInvalidRoleSpecification},
    //@}
    //@{
    /** @name Class 0Z — Diagnostics Exception */
    {"0Z000", SqlState::kDiagnosticsException},
    {"0Z002", SqlState::kStackedDiagnosticsAccessedWithoutActiveHandler},
    //@}
    //@{
    /** @name Class 20 — Case Not Found */
    {"20000", SqlState::kCaseNotFound},
    //@}
    //@{
    /** @name Class 21 — Cardinality Violation */
    {"21000", SqlState::kCardinalityViolation},
    //@}
    //@{
    /** @name Class 22 — Data Exception */
    {"22000", SqlState::kDataException},
    {"2202E", SqlState::kArraySubscriptError},
    {"22021", SqlState::kCharacterNotInRepertoire},
    {"22008", SqlState::kDatetimeFieldOverflow},
    {"22012", SqlState::kDivisionByZero},
    {"22005", SqlState::kErrorInAssignment},
    {"2200B", SqlState::kEscapeCharacterConflict},
    {"22022", SqlState::kIndicatorOverflow},
    {"22015", SqlState::kIntervalFieldOverflow},
    {"2201E", SqlState::kInvalidArgumentForLogarithm},
    {"22014", SqlState::kInvalidArgumentForNtileFunction},
    {"22016", SqlState::kInvalidArgumentForNthValueFunction},
    {"2201F", SqlState::kInvalidArgumentForPowerFunction},
    {"2201G", SqlState::kInvalidArgumentForWidthBucketFunction},
    {"22018", SqlState::kInvalidCharacterValueForCast},
    {"22007", SqlState::kInvalidDatetimeFormat},
    {"22019", SqlState::kInvalidEscapeCharacter},
    {"2200D", SqlState::kInvalidEscapeOctet},
    {"22025", SqlState::kInvalidEscapeSequence},
    {"22P06", SqlState::kNonstandardUseOfEscapeCharacter},
    {"22010", SqlState::kInvalidIndicatorParameterValue},
    {"22023", SqlState::kInvalidParameterValue},
    {"22013", SqlState::kInvalidPrecedingOrFollowingSize},
    {"2201B", SqlState::kInvalidRegularExpression},
    {"2201W", SqlState::kInvalidRowCountInLimitClause},
    {"2201X", SqlState::kInvalidRowCountInResultOffsetClause},
    {"2202H", SqlState::kInvalidTablesampleArgument},
    {"2202G", SqlState::kInvalidTablesampleRepeat},
    {"22009", SqlState::kInvalidTimeZoneDisplacementValue},
    {"2200C", SqlState::kInvalidUseOfEscapeCharacter},
    {"2200G", SqlState::kMostSpecificTypeMismatch},
    {"22004", SqlState::kNullValueNotAllowed},
    {"22002", SqlState::kNullValueNoIndicatorParameter},
    {"22003", SqlState::kNumericValueOutOfRange},
    {"2200H", SqlState::kSequenceGeneratorLimitExceeded},
    {"22026", SqlState::kStringDataLengthMismatch},
    {"22001", SqlState::kStringDataRightTruncation},
    {"22011", SqlState::kSubstringError},
    {"22027", SqlState::kTrimError},
    {"22024", SqlState::kUnterminatedCString},
    {"2200F", SqlState::kZeroLengthCharacterString},
    {"22P01", SqlState::kFloatingPointException},
    {"22P02", SqlState::kInvalidTextRepresentation},
    {"22P03", SqlState::kInvalidBinaryRepresentation},
    {"22P04", SqlState::kBadCopyFileFormat},
    {"22P05", SqlState::kUntranslatableCharacter},
    {"2200L", SqlState::kNotAnXmlDocument},
    {"2200M", SqlState::kInvalidXmlDocument},
    {"2200N", SqlState::kInvalidXmlContent},
    {"2200S", SqlState::kInvalidXmlComment},
    {"2200T", SqlState::kInvalidXmlProcessingInstruction},
    {"22030", SqlState::kDuplicateJsonObjectKeyValue},
    {"22032", SqlState::kInvalidJsonText},
    {"22033", SqlState::kInvalidSqlJsonSubscript},
    {"22034", SqlState::kMoreThanOneSqlJsonItem},
    {"22035", SqlState::kNoSqlJsonItem},
    {"22036", SqlState::kNonNumericSqlJsonItem},
    {"22037", SqlState::kNonUniqueKeysInAJsonObject},
    {"22038", SqlState::kSingletonSqlJsonItemRequired},
    {"22039", SqlState::kSqlJsonArrayNotFound},
    {"2203A", SqlState::kSqlJsonMemberNotFound},
    {"2203B", SqlState::kSqlJsonNumberNotFound},
    {"2203C", SqlState::kSqlJsonObjectNotFound},
    {"2203D", SqlState::kTooManyJsonArrayElements},
    {"2203E", SqlState::kTooManyJsonObjectMembers},
    {"2203F", SqlState::kSqlJsonScalarRequired},
    //@}
    //@{
    /** @name Class 23 — Integrity Constraint Violation */
    {"23000", SqlState::kIntegrityConstraintViolation},
    {"23001", SqlState::kRestrictViolation},
    {"23502", SqlState::kNotNullViolation},
    {"23503", SqlState::kForeignKeyViolation},
    {"23505", SqlState::kUniqueViolation},
    {"23514", SqlState::kCheckViolation},
    {"23P01", SqlState::kExclusionViolation},
    //@}
    //@{
    /** @name Class 24 — Invalid Cursor State */
    {"24000", SqlState::kInvalidCursorState},
    //@}
    //@{
    /** @name Class 25 — Invalid Transaction State */
    {"25000", SqlState::kInvalidTransactionState},
    {"25001", SqlState::kActiveSqlTransaction},
    {"25002", SqlState::kBranchTransactionAlreadyActive},
    {"25008", SqlState::kHeldCursorRequiresSameIsolationLevel},
    {"25003", SqlState::kInappropriateAccessModeForBranchTransaction},
    {"25004", SqlState::kInappropriateIsolationLevelForBranchTransaction},
    {"25005", SqlState::kNoActiveSqlTransactionForBranchTransaction},
    {"25006", SqlState::kReadOnlySqlTransaction},
    {"25007", SqlState::kSchemaAndDataStatementMixingNotSupported},
    {"25P01", SqlState::kNoActiveSqlTransaction},
    {"25P02", SqlState::kInFailedSqlTransaction},
    {"25P03", SqlState::kIdleInTransactionSessionTimeout},
    //@}
    //@{
    /** @name Class 26 — Invalid SQL Statement Name */
    {"26000", SqlState::kInvalidSqlStatementName},
    //@}
    //@{
    /** @name Class 27 — Triggered Data Change Violation */
    {"27000", SqlState::kTriggeredDataChangeViolation},
    //@}
    //@{
    /** @name Class 28 — Invalid Authorization Specification */
    {"28000", SqlState::kInvalidAuthorizationSpecification},
    {"28P01", SqlState::kInvalidPassword},
    //@}
    //@{
    /** @name Class 2B — Dependent Privilege Descriptors Still Exist */
    {"2B000", SqlState::kDependentPrivilegeDescriptorsStillExist},
    {"2BP01", SqlState::kDependentObjectsStillExist},
    //@}
    //@{
    /** @name Class 2D — Invalid Transaction Termination */
    {"2D000", SqlState::kInvalidTransactionTermination},
    //@}
    //@{
    /** @name Class 2F — SQL Routine Exception */
    {"2F000", SqlState::kSqlRoutineException},
    {"2F005", SqlState::kFunctionExecutedNoReturnStatement},
    {"2F002", SqlState::kModifyingSqlDataNotPermitted},
    {"2F003", SqlState::kProhibitedSqlStatementAttempted},
    {"2F004", SqlState::kReadingSqlDataNotPermitted},
    //@}
    //@{
    /** @name Class 34 — Invalid Cursor Name */
    {"34000", SqlState::kInvalidCursorName},
    //@}
    //@{
    /** @name Class 38 — External Routine Exception */
    {"38000", SqlState::kExternalRoutineException},
    {"38001", SqlState::kContainingSqlNotPermitted},
    {"38002", SqlState::kModifyingSqlDataNotPermittedEx},
    {"38003", SqlState::kProhibitedSqlStatementAttemptedEx},
    {"38004", SqlState::kReadingSqlDataNotPermittedEx},
    //@}
    //@{
    /** @name Class 39 — External Routine Invocation Exception */
    {"39000", SqlState::kExternalRoutineInvocationException},
    {"39001", SqlState::kInvalidSqlstateReturned},
    {"39004", SqlState::kNullValueNotAllowedEx},
    {"39P01", SqlState::kTriggerProtocolViolated},
    {"39P02", SqlState::kSrfProtocolViolated},
    {"39P03", SqlState::kEventTriggerProtocolViolated},
    //@}
    //@{
    /** @name Class 3B — Savepoint Exception */
    {"3B000", SqlState::kSavepointException},
    {"3B001", SqlState::kInvalidSavepointSpecification},
    //@}
    //@{
    /** @name Class 3D — Invalid Catalog Name */
    {"3D000", SqlState::kInvalidCatalogName},
    //@}
    //@{
    /** @name Class 3F — Invalid Schema Name */
    {"3F000", SqlState::kInvalidSchemaName},
    //@}
    //@{
    /** @name Class 40 — Transaction Rollback */
    {"40000", SqlState::kTransactionRollback},
    {"40002", SqlState::kTransactionIntegrityConstraintViolation},
    {"40001", SqlState::kSerializationFailure},
    {"40003", SqlState::kStatementCompletionUnknown},
    {"40P01", SqlState::kDeadlockDetected},
    //@}
    //@{
    /** @name Class 42 — Syntax Error or Access Rule Violation */
    {"42000", SqlState::kSyntaxErrorOrAccessRuleViolation},
    {"42601", SqlState::kSyntaxError},
    {"42501", SqlState::kInsufficientPrivilege},
    {"42846", SqlState::kCannotCoerce},
    {"42803", SqlState::kGroupingError},
    {"42P20", SqlState::kWindowingError},
    {"42P19", SqlState::kInvalidRecursion},
    {"42830", SqlState::kInvalidForeignKey},
    {"42602", SqlState::kInvalidName},
    {"42622", SqlState::kNameTooLong},
    {"42939", SqlState::kReservedName},
    {"42804", SqlState::kDatatypeMismatch},
    {"42P18", SqlState::kIndeterminateDatatype},
    {"42P21", SqlState::kCollationMismatch},
    {"42P22", SqlState::kIndeterminateCollation},
    {"42809", SqlState::kWrongObjectType},
    {"428C9", SqlState::kGeneratedAlways},
    {"42703", SqlState::kUndefinedColumn},
    {"42883", SqlState::kUndefinedFunction},
    {"42P01", SqlState::kUndefinedTable},
    {"42P02", SqlState::kUndefinedParameter},
    {"42704", SqlState::kUndefinedObject},
    {"42701", SqlState::kDuplicateColumn},
    {"42P03", SqlState::kDuplicateCursor},
    {"42P04", SqlState::kDuplicateDatabase},
    {"42723", SqlState::kDuplicateFunction},
    {"42P05", SqlState::kDuplicatePreparedStatement},
    {"42P06", SqlState::kDuplicateSchema},
    {"42P07", SqlState::kDuplicateTable},
    {"42712", SqlState::kDuplicateAlias},
    {"42710", SqlState::kDuplicateObject},
    {"42702", SqlState::kAmbiguousColumn},
    {"42725", SqlState::kAmbiguousFunction},
    {"42P08", SqlState::kAmbiguousParameter},
    {"42P09", SqlState::kAmbiguousAlias},
    {"42P10", SqlState::kInvalidColumnReference},
    {"42611", SqlState::kInvalidColumnDefinition},
    {"42P11", SqlState::kInvalidCursorDefinition},
    {"42P12", SqlState::kInvalidDatabaseDefinition},
    {"42P13", SqlState::kInvalidFunctionDefinition},
    {"42P14", SqlState::kInvalidPreparedStatementDefinition},
    {"42P15", SqlState::kInvalidSchemaDefinition},
    {"42P16", SqlState::kInvalidTableDefinition},
    {"42P17", SqlState::kInvalidObjectDefinition},
    //@}
    //@{
    /** @name Class 44 — WITH CHECK OPTION Violation */
    {"44000", SqlState::kWithCheckOptionViolation},
    //@}
    //@{
    /** @name Class 53 — Insufficient Resources */
    {"53000", SqlState::kInsufficientResources},
    {"53100", SqlState::kDiskFull},
    {"53200", SqlState::kOutOfMemory},
    {"53300", SqlState::kTooManyConnections},
    {"53400", SqlState::kConfigurationLimitExceeded},
    //@}
    //@{
    /** @name Class 54 — Program Limit Exceeded */
    {"54000", SqlState::kProgramLimitExceeded},
    {"54001", SqlState::kStatementTooComplex},
    {"54011", SqlState::kTooManyColumns},
    {"54023", SqlState::kTooManyArguments},
    //@}
    //@{
    /** @name Class 55 — Object Not In Prerequisite State */
    {"55000", SqlState::kObjectNotInPrerequisiteState},
    {"55006", SqlState::kObjectInUse},
    {"55P02", SqlState::kCantChangeRuntimeParam},
    {"55P03", SqlState::kLockNotAvailable},
    {"55P04", SqlState::kUnsafeNewEnumValueUsage},
    //@}
    //@{
    /** @name Class 57 — Operator Intervention */
    {"57000", SqlState::kOperatorIntervention},
    {"57014", SqlState::kQueryCancelled},
    {"57P01", SqlState::kAdminShutdown},
    {"57P02", SqlState::kCrashShutdown},
    {"57P03", SqlState::kCannotConnectNow},
    {"57P04", SqlState::kDatabaseDropped},
    //@}
    //@{
    /** @name Class 58 — System Error (errors external to  */
    {"58000", SqlState::kSystemError},
    {"58030", SqlState::kIoError},
    {"58P01", SqlState::kUndefinedFile},
    {"58P02", SqlState::kDuplicateFile},
    //@}
    //@{
    /** @name Class 72 — Snapshot Failure */
    {"72000", SqlState::kSnapshotTooOld},
    //@}
    //@{
    /** @name Class F0 — Configuration File Error */
    {"F0000", SqlState::kConfigFileError},
    {"F0001", SqlState::kLockFileExists},
    //@}
    //@{
    /** @name Class HV — Foreign Data Wrapper Error (SQL/MED) */
    {"HV000", SqlState::kFdwError},
    {"HV005", SqlState::kFdwColumnNameNotFound},
    {"HV002", SqlState::kFdwDynamicParameterValueNeeded},
    {"HV010", SqlState::kFdwFunctionSequenceError},
    {"HV021", SqlState::kFdwInconsistentDescriptorInformation},
    {"HV024", SqlState::kFdwInvalidAttributeValue},
    {"HV007", SqlState::kFdwInvalidColumnName},
    {"HV008", SqlState::kFdwInvalidColumnNumber},
    {"HV004", SqlState::kFdwInvalidDataType},
    {"HV006", SqlState::kFdwInvalidDataTypeDescriptors},
    {"HV091", SqlState::kFdwInvalidDescriptorFieldIdentifier},
    {"HV00B", SqlState::kFdwInvalidHandle},
    {"HV00C", SqlState::kFdwInvalidOptionIndex},
    {"HV00D", SqlState::kFdwInvalidOptionName},
    {"HV090", SqlState::kFdwInvalidStringLengthOrBufferLength},
    {"HV00A", SqlState::kFdwInvalidStringFormat},
    {"HV009", SqlState::kFdwInvalidUseOfNullPointer},
    {"HV014", SqlState::kFdwTooManyHandles},
    {"HV001", SqlState::kFdwOutOfMemory},
    {"HV00P", SqlState::kFdwNoSchemas},
    {"HV00J", SqlState::kFdwOptionNameNotFound},
    {"HV00K", SqlState::kFdwReplyHandle},
    {"HV00Q", SqlState::kFdwSchemaNotFound},
    {"HV00R", SqlState::kFdwTableNotFound},
    {"HV00L", SqlState::kFdwUnableToCreateExecution},
    {"HV00M", SqlState::kFdwUnableToCreateReply},
    {"HV00N", SqlState::kFdwUnableToEstablishConnection},
    //@}
    //@{
    /** @name Class P0 — PL/pgSQL Error */
    {"P0000", SqlState::kPlpgsqlError},
    {"P0001", SqlState::kRaiseException},
    {"P0002", SqlState::kNoDataFound},
    {"P0003", SqlState::kTooManyRows},
    {"P0004", SqlState::kAssertFailure},
    //@}
    //@{
    /** @name Class XX — Internal Error */
    {"XX000", SqlState::kInternalError},
    {"XX001", SqlState::kDataCorrupted},
    {"XX002", SqlState::kIndexCorrupted},
    //@}
};

// clang format makes it inconvenient to read with several values per line
// clang-format off
const std::unordered_set<SqlState> kStateWhitelist{
    //@{
    /** @name Class 00 — Successful Completion */
    SqlState::kSuccessfulCompletion,
    //@}
    //@{
    /** @name Class 01 — Warning */
    SqlState::kWarning,
    SqlState::kDynamicResultSetsReturned,
    SqlState::kImplicitZeroBitPadding,
    SqlState::kNullValueEliminatedInSetFunction,
    SqlState::kPrivilegeNotGranted,
    SqlState::kPrivilegeNotRevoked,
    SqlState::kStringDataRightTruncationWarn,
    SqlState::kDeprecatedFeature,
    //@}
    //@{
    /** @name Misc errors that are logged to LOG_WARNING instead of LOG_ERROR */
    SqlState::kUniqueViolation,
    SqlState::kForeignKeyViolation,
    SqlState::kDuplicatePreparedStatement,
    //@}
};
// clang-format on

}  // namespace

SqlStateClass GetSqlStateClass(SqlState sql_state) {
    auto bits = boost::multiprecision::msb(static_cast<std::uint64_t>(sql_state));
    auto res = static_cast<SqlStateClass>(std::uint64_t{1} << bits);
    if (SqlStateClass::kWarning < res && res < SqlStateClass::kNoData) {
        return SqlStateClass::kWarning;
    }
    return res;
}

SqlState SqlStateFromString(std::string_view s) {
    auto f = kCodeStrToState.find(s);
    if (f != kCodeStrToState.end()) {
        return f->second;
    }
    return SqlState::kUnknownState;
}

bool IsWhitelistedState(SqlState sql_state) { return kStateWhitelist.count(sql_state) != 0; }

}  // namespace storages::postgres

USERVER_NAMESPACE_END
