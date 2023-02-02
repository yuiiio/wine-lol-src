/*
 * Win32 ODBC functions
 *
 * Copyright 1999 Xiang Li, Corel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * NOTES:
 *   Proxy ODBC driver manager.  This manager delegates all ODBC 
 *   calls to a real ODBC driver manager named by the environment 
 *   variable LIB_ODBC_DRIVER_MANAGER, or to libodbc.so if the
 *   variable is not set.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "windef.h"
#include "winbase.h"
#include "winternl.h"
#include "winreg.h"
#include "wine/debug.h"

#include "sql.h"
#include "sqltypes.h"
#include "sqlext.h"

WINE_DEFAULT_DEBUG_CHANNEL(odbc);


/*************************************************************************
 *				SQLAllocConnect           [ODBC32.001]
 */
SQLRETURN WINAPI SQLAllocConnect(SQLHENV EnvironmentHandle, SQLHDBC *ConnectionHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, ConnectionHandle %p)\n", EnvironmentHandle, ConnectionHandle);
    *ConnectionHandle = SQL_NULL_HDBC;
    return ret;
}

/*************************************************************************
 *				SQLAllocEnv           [ODBC32.002]
 */
SQLRETURN WINAPI SQLAllocEnv(SQLHENV *EnvironmentHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p)\n", EnvironmentHandle);

    *EnvironmentHandle = SQL_NULL_HENV;

    return ret;
}

/*************************************************************************
 *				SQLAllocHandle           [ODBC32.024]
 */
SQLRETURN WINAPI SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, InputHandle %p, OutputHandle %p)\n", HandleType, InputHandle, OutputHandle);

    *OutputHandle = 0;
    return ret;
}

/*************************************************************************
 *				SQLAllocStmt           [ODBC32.003]
 */
SQLRETURN WINAPI SQLAllocStmt(SQLHDBC ConnectionHandle, SQLHSTMT *StatementHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, StatementHandle %p)\n", ConnectionHandle, StatementHandle);

    *StatementHandle = SQL_NULL_HSTMT;
    return ret;
}

/*************************************************************************
 *				SQLAllocHandleStd           [ODBC32.077]
 */
SQLRETURN WINAPI SQLAllocHandleStd(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, InputHandle %p, OutputHandle %p)\n", HandleType, InputHandle, OutputHandle);

    *OutputHandle = 0;
    return ret;
}

static const char *debugstr_sqllen( SQLLEN len )
{
#ifdef _WIN64
    return wine_dbg_sprintf( "%Id", len );
#else
    return wine_dbg_sprintf( "%d", len );
#endif
}

/*************************************************************************
 *				SQLBindCol           [ODBC32.004]
 */
SQLRETURN WINAPI SQLBindCol(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
                            SQLPOINTER TargetValue, SQLLEN BufferLength, SQLLEN *StrLen_or_Ind)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ColumnNumber %d, TargetType %d, TargetValue %p, BufferLength %s, StrLen_or_Ind %p)\n",
          StatementHandle, ColumnNumber, TargetType, TargetValue, debugstr_sqllen(BufferLength), StrLen_or_Ind);

    return ret;
}

static const char *debugstr_sqlulen( SQLULEN len )
{
#ifdef _WIN64
    return wine_dbg_sprintf( "%Iu", len );
#else
    return wine_dbg_sprintf( "%u", len );
#endif
}

/*************************************************************************
 *				SQLBindParam           [ODBC32.025]
 */
SQLRETURN WINAPI SQLBindParam(SQLHSTMT StatementHandle, SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                              SQLSMALLINT ParameterType, SQLULEN LengthPrecision, SQLSMALLINT ParameterScale,
                              SQLPOINTER ParameterValue, SQLLEN *StrLen_or_Ind)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ParameterNumber %d, ValueType %d, ParameterType %d, LengthPrecision %s,"
          " ParameterScale %d, ParameterValue %p, StrLen_or_Ind %p)\n", StatementHandle, ParameterNumber, ValueType,
          ParameterType, debugstr_sqlulen(LengthPrecision), ParameterScale, ParameterValue, StrLen_or_Ind);

    return ret;
}

/*************************************************************************
 *				SQLCancel           [ODBC32.005]
 */
SQLRETURN WINAPI SQLCancel(SQLHSTMT StatementHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p)\n", StatementHandle);

    return ret;
}

/*************************************************************************
 *				SQLCloseCursor           [ODBC32.026]
 */
SQLRETURN WINAPI SQLCloseCursor(SQLHSTMT StatementHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p)\n", StatementHandle);

    return ret;
}

/*************************************************************************
 *				SQLColAttribute           [ODBC32.027]
 */
SQLRETURN WINAPI SQLColAttribute(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber,
                                 SQLUSMALLINT FieldIdentifier, SQLPOINTER CharacterAttribute,
                                 SQLSMALLINT BufferLength, SQLSMALLINT *StringLength,
                                 SQLLEN *NumericAttribute)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ColumnNumber %d, FieldIdentifier %d, CharacterAttribute %p, BufferLength %d,"
          " StringLength %p, NumericAttribute %p)\n", StatementHandle, ColumnNumber, FieldIdentifier,
          CharacterAttribute, BufferLength, StringLength, NumericAttribute);

    return ret;
}

/*************************************************************************
 *				SQLColumns           [ODBC32.040]
 */
SQLRETURN WINAPI SQLColumns(SQLHSTMT StatementHandle, SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                            SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName,
                            SQLSMALLINT NameLength3, SQLCHAR *ColumnName, SQLSMALLINT NameLength4)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CatalogName %s, NameLength1 %d, SchemaName %s, NameLength2 %d, TableName %s,"
          " NameLength3 %d, ColumnName %s, NameLength4 %d)\n", StatementHandle,
          debugstr_an((const char *)CatalogName, NameLength1), NameLength1,
          debugstr_an((const char *)SchemaName, NameLength2), NameLength2,
          debugstr_an((const char *)TableName, NameLength3), NameLength3,
          debugstr_an((const char *)ColumnName, NameLength4), NameLength4);

    return ret;
}

/*************************************************************************
 *				SQLConnect           [ODBC32.007]
 */
SQLRETURN WINAPI SQLConnect(SQLHDBC ConnectionHandle, SQLCHAR *ServerName, SQLSMALLINT NameLength1,
                            SQLCHAR *UserName, SQLSMALLINT NameLength2, SQLCHAR *Authentication,
                            SQLSMALLINT NameLength3)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, ServerName %s, NameLength1 %d, UserName %s, NameLength2 %d, Authentication %s,"
          " NameLength3 %d)\n", ConnectionHandle,
          debugstr_an((const char *)ServerName, NameLength1), NameLength1,
          debugstr_an((const char *)UserName, NameLength2), NameLength2,
          debugstr_an((const char *)Authentication, NameLength3), NameLength3);

    return ret;
}

/*************************************************************************
 *				SQLCopyDesc           [ODBC32.028]
 */
SQLRETURN WINAPI SQLCopyDesc(SQLHDESC SourceDescHandle, SQLHDESC TargetDescHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(SourceDescHandle %p, TargetDescHandle %p)\n", SourceDescHandle, TargetDescHandle);

    return ret;
}

/*************************************************************************
 *				SQLDataSources           [ODBC32.057]
 */
SQLRETURN WINAPI SQLDataSources(SQLHENV EnvironmentHandle, SQLUSMALLINT Direction, SQLCHAR *ServerName,
                                SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1, SQLCHAR *Description,
                                SQLSMALLINT BufferLength2, SQLSMALLINT *NameLength2)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Direction %d, ServerName %p, BufferLength1 %d, NameLength1 %p, Description %p,"
          " BufferLength2 %d, NameLength2 %p)\n", EnvironmentHandle, Direction, ServerName, BufferLength1,
          NameLength1, Description, BufferLength2, NameLength2);

    return ret;
}

SQLRETURN WINAPI SQLDataSourcesA(SQLHENV EnvironmentHandle, SQLUSMALLINT Direction, SQLCHAR *ServerName,
                                 SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1, SQLCHAR *Description,
                                 SQLSMALLINT BufferLength2, SQLSMALLINT *NameLength2)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Direction %d, ServerName %p, BufferLength1 %d, NameLength1 %p, Description %p,"
          " BufferLength2 %d, NameLength2 %p)\n", EnvironmentHandle, Direction, ServerName, BufferLength1,
          NameLength1, Description, BufferLength2, NameLength2);

    return ret;
}

/*************************************************************************
 *				SQLDescribeCol           [ODBC32.008]
 */
SQLRETURN WINAPI SQLDescribeCol(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName,
                                SQLSMALLINT BufferLength, SQLSMALLINT *NameLength, SQLSMALLINT *DataType,
                                SQLULEN *ColumnSize, SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ColumnNumber %d, ColumnName %p, BufferLength %d, NameLength %p, DataType %p,"
          " ColumnSize %p, DecimalDigits %p, Nullable %p)\n", StatementHandle, ColumnNumber, ColumnName,
          BufferLength, NameLength, DataType, ColumnSize, DecimalDigits, Nullable);

    return ret;
}

/*************************************************************************
 *				SQLDisconnect           [ODBC32.009]
 */
SQLRETURN WINAPI SQLDisconnect(SQLHDBC ConnectionHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p)\n", ConnectionHandle);

    return ret;
}

/*************************************************************************
 *				SQLEndTran           [ODBC32.029]
 */
SQLRETURN WINAPI SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT CompletionType)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p, CompletionType %d)\n", HandleType, Handle, CompletionType);

    return ret;
}

/*************************************************************************
 *				SQLError           [ODBC32.010]
 */
SQLRETURN WINAPI SQLError(SQLHENV EnvironmentHandle, SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,
                          SQLCHAR *Sqlstate, SQLINTEGER *NativeError, SQLCHAR *MessageText,
                          SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, ConnectionHandle %p, StatementHandle %p, Sqlstate %p, NativeError %p,"
          " MessageText %p, BufferLength %d, TextLength %p)\n", EnvironmentHandle, ConnectionHandle,
          StatementHandle, Sqlstate, NativeError, MessageText, BufferLength, TextLength);

    return ret;
}

/*************************************************************************
 *				SQLExecDirect           [ODBC32.011]
 */
SQLRETURN WINAPI SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, StatementText %s, TextLength %d)\n", StatementHandle,
          debugstr_an((const char *)StatementText, TextLength), TextLength);

    return ret;
}

/*************************************************************************
 *				SQLExecute           [ODBC32.012]
 */
SQLRETURN WINAPI SQLExecute(SQLHSTMT StatementHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p)\n", StatementHandle);

    return ret;
}

/*************************************************************************
 *				SQLFetch           [ODBC32.013]
 */
SQLRETURN WINAPI SQLFetch(SQLHSTMT StatementHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p)\n", StatementHandle);

    return ret;
}

/*************************************************************************
 *				SQLFetchScroll          [ODBC32.030]
 */
SQLRETURN WINAPI SQLFetchScroll(SQLHSTMT StatementHandle, SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, FetchOrientation %d, FetchOffset %s)\n", StatementHandle, FetchOrientation,
          debugstr_sqllen(FetchOffset));

    return ret;
}

/*************************************************************************
 *				SQLFreeConnect           [ODBC32.014]
 */
SQLRETURN WINAPI SQLFreeConnect(SQLHDBC ConnectionHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p)\n", ConnectionHandle);

    return ret;
}

/*************************************************************************
 *				SQLFreeEnv           [ODBC32.015]
 */
SQLRETURN WINAPI SQLFreeEnv(SQLHENV EnvironmentHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p)\n", EnvironmentHandle);

    return ret;
}

/*************************************************************************
 *				SQLFreeHandle           [ODBC32.031]
 */
SQLRETURN WINAPI SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p)\n", HandleType, Handle);

    return ret;
}

/*************************************************************************
 *				SQLFreeStmt           [ODBC32.016]
 */
SQLRETURN WINAPI SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Option %d)\n", StatementHandle, Option);

    return ret;
}

/*************************************************************************
 *				SQLGetConnectAttr           [ODBC32.032]
 */
SQLRETURN WINAPI SQLGetConnectAttr(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                   SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Attribute %d, Value %p, BufferLength %d, StringLength %p)\n", ConnectionHandle,
          Attribute, Value, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetConnectOption       [ODBC32.042]
 */
SQLRETURN WINAPI SQLGetConnectOption(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLPOINTER Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Option %d, Value %p)\n", ConnectionHandle, Option, Value);

    return ret;
}

/*************************************************************************
 *				SQLGetCursorName           [ODBC32.017]
 */
SQLRETURN WINAPI SQLGetCursorName(SQLHSTMT StatementHandle, SQLCHAR *CursorName, SQLSMALLINT BufferLength,
                                  SQLSMALLINT *NameLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CursorName %p, BufferLength %d, NameLength %p)\n", StatementHandle, CursorName,
          BufferLength, NameLength);

    return ret;
}

/*************************************************************************
 *				SQLGetData           [ODBC32.043]
 */
SQLRETURN WINAPI SQLGetData(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
                            SQLPOINTER TargetValue, SQLLEN BufferLength, SQLLEN *StrLen_or_Ind)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ColumnNumber %d, TargetType %d, TargetValue %p, BufferLength %s, StrLen_or_Ind %p)\n",
          StatementHandle, ColumnNumber, TargetType, TargetValue, debugstr_sqllen(BufferLength), StrLen_or_Ind);

    return ret;
}

/*************************************************************************
 *				SQLGetDescField           [ODBC32.033]
 */
SQLRETURN WINAPI SQLGetDescField(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
                                 SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, FieldIdentifier %d, Value %p, BufferLength %d, StringLength %p)\n",
          DescriptorHandle, RecNumber, FieldIdentifier, Value, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetDescRec           [ODBC32.034]
 */
SQLRETURN WINAPI SQLGetDescRec(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLCHAR *Name,
                               SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLSMALLINT *Type,
                               SQLSMALLINT *SubType, SQLLEN *Length, SQLSMALLINT *Precision,
                               SQLSMALLINT *Scale, SQLSMALLINT *Nullable)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, Name %p, BufferLength %d, StringLength %p, Type %p, SubType %p,"
          " Length %p, Precision %p, Scale %p, Nullable %p)\n", DescriptorHandle, RecNumber, Name, BufferLength,
          StringLength, Type, SubType, Length, Precision, Scale, Nullable);

    return ret;
}

/*************************************************************************
 *				SQLGetDiagField           [ODBC32.035]
 */
SQLRETURN WINAPI SQLGetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber,
                                 SQLSMALLINT DiagIdentifier, SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
                                 SQLSMALLINT *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p, RecNumber %d, DiagIdentifier %d, DiagInfo %p, BufferLength %d,"
          " StringLength %p)\n", HandleType, Handle, RecNumber, DiagIdentifier, DiagInfo, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetDiagRec           [ODBC32.036]
 */
SQLRETURN WINAPI SQLGetDiagRec(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber,
                               SQLCHAR *Sqlstate, SQLINTEGER *NativeError, SQLCHAR *MessageText,
                               SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p, RecNumber %d, Sqlstate %p, NativeError %p, MessageText %p, BufferLength %d,"
          " TextLength %p)\n", HandleType, Handle, RecNumber, Sqlstate, NativeError, MessageText, BufferLength,
          TextLength);

    return ret;
}

/*************************************************************************
 *				SQLGetEnvAttr           [ODBC32.037]
 */
SQLRETURN WINAPI SQLGetEnvAttr(SQLHENV EnvironmentHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                               SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Attribute %d, Value %p, BufferLength %d, StringLength %p)\n",
          EnvironmentHandle, Attribute, Value, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetFunctions           [ODBC32.044]
 */
SQLRETURN WINAPI SQLGetFunctions(SQLHDBC ConnectionHandle, SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, FunctionId %d, Supported %p)\n", ConnectionHandle, FunctionId, Supported);

    return ret;
}

/*************************************************************************
 *				SQLGetInfo           [ODBC32.045]
 */
SQLRETURN WINAPI SQLGetInfo(SQLHDBC ConnectionHandle, SQLUSMALLINT InfoType, SQLPOINTER InfoValue,
                            SQLSMALLINT BufferLength, SQLSMALLINT *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle, %p, InfoType %d, InfoValue %p, BufferLength %d, StringLength %p)\n", ConnectionHandle,
          InfoType, InfoValue, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetStmtAttr           [ODBC32.038]
 */
SQLRETURN WINAPI SQLGetStmtAttr(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Attribute %d, Value %p, BufferLength %d, StringLength %p)\n", StatementHandle,
          Attribute, Value, BufferLength, StringLength);

    if (!Value)
    {
        WARN("Unexpected NULL Value return address\n");
        return SQL_ERROR;
    }

    return ret;
}

/*************************************************************************
 *				SQLGetStmtOption           [ODBC32.046]
 */
SQLRETURN WINAPI SQLGetStmtOption(SQLHSTMT StatementHandle, SQLUSMALLINT Option, SQLPOINTER Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Option %d, Value %p)\n", StatementHandle, Option, Value);

    return ret;
}

/*************************************************************************
 *				SQLGetTypeInfo           [ODBC32.047]
 */
SQLRETURN WINAPI SQLGetTypeInfo(SQLHSTMT StatementHandle, SQLSMALLINT DataType)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, DataType %d)\n", StatementHandle, DataType);

    return ret;
}

/*************************************************************************
 *				SQLNumResultCols           [ODBC32.018]
 */
SQLRETURN WINAPI SQLNumResultCols(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ColumnCount %p)\n", StatementHandle, ColumnCount);

    return ret;
}

/*************************************************************************
 *				SQLParamData           [ODBC32.048]
 */
SQLRETURN WINAPI SQLParamData(SQLHSTMT StatementHandle, SQLPOINTER *Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Value %p)\n", StatementHandle, Value);

    return ret;
}

/*************************************************************************
 *				SQLPrepare           [ODBC32.019]
 */
SQLRETURN WINAPI SQLPrepare(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, StatementText %s, TextLength %d)\n", StatementHandle,
          debugstr_an((const char *)StatementText, TextLength), TextLength);

    return ret;
}

/*************************************************************************
 *				SQLPutData           [ODBC32.049]
 */
SQLRETURN WINAPI SQLPutData(SQLHSTMT StatementHandle, SQLPOINTER Data, SQLLEN StrLen_or_Ind)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Data %p, StrLen_or_Ind %s)\n", StatementHandle, Data, debugstr_sqllen(StrLen_or_Ind));

    return ret;
}

/*************************************************************************
 *				SQLRowCount           [ODBC32.020]
 */
SQLRETURN WINAPI SQLRowCount(SQLHSTMT StatementHandle, SQLLEN *RowCount)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, RowCount %p)\n", StatementHandle, RowCount);

    return ret;
}

/*************************************************************************
 *				SQLSetConnectAttr           [ODBC32.039]
 */
SQLRETURN WINAPI SQLSetConnectAttr(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                   SQLINTEGER StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Attribute %d, Value %p, StringLength %d)\n", ConnectionHandle, Attribute, Value,
          StringLength);

    return ret;
}

/*************************************************************************
 *				SQLSetConnectOption           [ODBC32.050]
 */
SQLRETURN WINAPI SQLSetConnectOption(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLULEN Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Option %d, Value %s)\n", ConnectionHandle, Option, debugstr_sqlulen(Value));

    return ret;
}

/*************************************************************************
 *				SQLSetCursorName           [ODBC32.021]
 */
SQLRETURN WINAPI SQLSetCursorName(SQLHSTMT StatementHandle, SQLCHAR *CursorName, SQLSMALLINT NameLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CursorName %s, NameLength %d)\n", StatementHandle,
          debugstr_an((const char *)CursorName, NameLength), NameLength);

    return ret;
}

/*************************************************************************
 *				SQLSetDescField           [ODBC32.073]
 */
SQLRETURN WINAPI SQLSetDescField(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
                                 SQLPOINTER Value, SQLINTEGER BufferLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, FieldIdentifier %d, Value %p, BufferLength %d)\n", DescriptorHandle,
          RecNumber, FieldIdentifier, Value, BufferLength);

    return ret;
}

/*************************************************************************
 *				SQLSetDescRec           [ODBC32.074]
 */
SQLRETURN WINAPI SQLSetDescRec(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT Type,
                               SQLSMALLINT SubType, SQLLEN Length, SQLSMALLINT Precision, SQLSMALLINT Scale,
                               SQLPOINTER Data, SQLLEN *StringLength, SQLLEN *Indicator)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, Type %d, SubType %d, Length %s, Precision %d, Scale %d, Data %p,"
          " StringLength %p, Indicator %p)\n", DescriptorHandle, RecNumber, Type, SubType, debugstr_sqllen(Length),
          Precision, Scale, Data, StringLength, Indicator);

    return ret;
}

/*************************************************************************
 *				SQLSetEnvAttr           [ODBC32.075]
 */
SQLRETURN WINAPI SQLSetEnvAttr(SQLHENV EnvironmentHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                               SQLINTEGER StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Attribute %d, Value %p, StringLength %d)\n", EnvironmentHandle, Attribute, Value,
          StringLength);

    return ret;
}

/*************************************************************************
 *				SQLSetParam           [ODBC32.022]
 */
SQLRETURN WINAPI SQLSetParam(SQLHSTMT StatementHandle, SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                             SQLSMALLINT ParameterType, SQLULEN LengthPrecision, SQLSMALLINT ParameterScale,
                             SQLPOINTER ParameterValue, SQLLEN *StrLen_or_Ind)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ParameterNumber %d, ValueType %d, ParameterType %d, LengthPrecision %s,"
          " ParameterScale %d, ParameterValue %p, StrLen_or_Ind %p)\n", StatementHandle, ParameterNumber, ValueType,
          ParameterType, debugstr_sqlulen(LengthPrecision), ParameterScale, ParameterValue, StrLen_or_Ind);

    return ret;
}

/*************************************************************************
 *				SQLSetStmtAttr           [ODBC32.076]
 */
SQLRETURN WINAPI SQLSetStmtAttr(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                SQLINTEGER StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Attribute %d, Value %p, StringLength %d)\n", StatementHandle, Attribute, Value,
          StringLength);

    return ret;
}

/*************************************************************************
 *				SQLSetStmtOption           [ODBC32.051]
 */
SQLRETURN WINAPI SQLSetStmtOption(SQLHSTMT StatementHandle, SQLUSMALLINT Option, SQLULEN Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Option %d, Value %s)\n", StatementHandle, Option, debugstr_sqlulen(Value));

    return ret;
}

/*************************************************************************
 *				SQLSpecialColumns           [ODBC32.052]
 */
SQLRETURN WINAPI SQLSpecialColumns(SQLHSTMT StatementHandle, SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName,
                                   SQLSMALLINT NameLength1, SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
                                   SQLCHAR *TableName, SQLSMALLINT NameLength3, SQLUSMALLINT Scope,
                                   SQLUSMALLINT Nullable)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, IdentifierType %d, CatalogName %s, NameLength1 %d, SchemaName %s, NameLength2 %d,"
          " TableName %s, NameLength3 %d, Scope %d, Nullable %d)\n", StatementHandle, IdentifierType,
          debugstr_an((const char *)CatalogName, NameLength1), NameLength1,
          debugstr_an((const char *)SchemaName, NameLength2), NameLength2,
          debugstr_an((const char *)TableName, NameLength3), NameLength3, Scope, Nullable);

    return ret;
}

/*************************************************************************
 *				SQLStatistics           [ODBC32.053]
 */
SQLRETURN WINAPI SQLStatistics(SQLHSTMT StatementHandle, SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                               SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName,
                               SQLSMALLINT NameLength3, SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CatalogName %s, NameLength1 %d SchemaName %s, NameLength2 %d, TableName %s"
          " NameLength3 %d, Unique %d, Reserved %d)\n", StatementHandle,
          debugstr_an((const char *)CatalogName, NameLength1), NameLength1,
          debugstr_an((const char *)SchemaName, NameLength2), NameLength2,
          debugstr_an((const char *)TableName, NameLength3), NameLength3, Unique, Reserved);

    return ret;
}

/*************************************************************************
 *				SQLTables           [ODBC32.054]
 */
SQLRETURN WINAPI SQLTables(SQLHSTMT StatementHandle, SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                           SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName,
                           SQLSMALLINT NameLength3, SQLCHAR *TableType, SQLSMALLINT NameLength4)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CatalogName %s, NameLength1 %d, SchemaName %s, NameLength2 %d, TableName %s,"
          " NameLength3 %d, TableType %s, NameLength4 %d)\n", StatementHandle,
          debugstr_an((const char *)CatalogName, NameLength1), NameLength1,
          debugstr_an((const char *)SchemaName, NameLength2), NameLength2,
          debugstr_an((const char *)TableName, NameLength3), NameLength3,
          debugstr_an((const char *)TableType, NameLength4), NameLength4);

    return ret;
}

/*************************************************************************
 *				SQLTransact           [ODBC32.023]
 */
SQLRETURN WINAPI SQLTransact(SQLHENV EnvironmentHandle, SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, ConnectionHandle %p, CompletionType %d)\n", EnvironmentHandle, ConnectionHandle,
          CompletionType);

    return ret;
}

/*************************************************************************
 *				SQLBrowseConnect           [ODBC32.055]
 */
SQLRETURN WINAPI SQLBrowseConnect(SQLHDBC hdbc, SQLCHAR *szConnStrIn, SQLSMALLINT cbConnStrIn,
                                  SQLCHAR *szConnStrOut, SQLSMALLINT cbConnStrOutMax,
                                  SQLSMALLINT *pcbConnStrOut)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hdbc %p, szConnStrIn %s, cbConnStrIn %d, szConnStrOut %p, cbConnStrOutMax %d, pcbConnStrOut %p)\n",
          hdbc, debugstr_an((const char *)szConnStrIn, cbConnStrIn), cbConnStrIn, szConnStrOut, cbConnStrOutMax,
          pcbConnStrOut);

    return ret;
}

/*************************************************************************
 *				SQLBulkOperations           [ODBC32.078]
 */
SQLRETURN WINAPI SQLBulkOperations(SQLHSTMT StatementHandle, SQLSMALLINT Operation)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Operation %d)\n", StatementHandle, Operation);

    return ret;
}

/*************************************************************************
 *				SQLColAttributes           [ODBC32.006]
 */
SQLRETURN WINAPI SQLColAttributes(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLUSMALLINT fDescType,
                                  SQLPOINTER rgbDesc, SQLSMALLINT cbDescMax, SQLSMALLINT *pcbDesc,
                                  SQLLEN *pfDesc)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, icol %d, fDescType %d, rgbDesc %p, cbDescMax %d, pcbDesc %p, pfDesc %p)\n", hstmt, icol,
          fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc);

    return ret;
}

/*************************************************************************
 *				SQLColumnPrivileges           [ODBC32.056]
 */
SQLRETURN WINAPI SQLColumnPrivileges(SQLHSTMT hstmt, SQLCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                     SQLCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLCHAR *szTableName,
                                     SQLSMALLINT cbTableName, SQLCHAR *szColumnName, SQLSMALLINT cbColumnName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szTableName %s,"
          " cbTableName %d, szColumnName %s, cbColumnName %d)\n", hstmt,
          debugstr_an((const char *)szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_an((const char *)szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_an((const char *)szTableName, cbTableName), cbTableName,
          debugstr_an((const char *)szColumnName, cbColumnName), cbColumnName);

    return ret;
}

/*************************************************************************
 *				SQLDescribeParam          [ODBC32.058]
 */
SQLRETURN WINAPI SQLDescribeParam(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT *pfSqlType,
                                  SQLULEN *pcbParamDef, SQLSMALLINT *pibScale, SQLSMALLINT *pfNullable)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, ipar %d, pfSqlType %p, pcbParamDef %p, pibScale %p, pfNullable %p)\n", hstmt, ipar,
          pfSqlType, pcbParamDef, pibScale, pfNullable);

    return ret;
}

/*************************************************************************
 *				SQLExtendedFetch           [ODBC32.059]
 */
SQLRETURN WINAPI SQLExtendedFetch(SQLHSTMT hstmt, SQLUSMALLINT fFetchType, SQLLEN irow, SQLULEN *pcrow,
                                  SQLUSMALLINT *rgfRowStatus)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, fFetchType %d, irow %s, pcrow %p, rgfRowStatus %p)\n", hstmt, fFetchType, debugstr_sqllen(irow),
          pcrow, rgfRowStatus);

    return ret;
}

/*************************************************************************
 *				SQLForeignKeys           [ODBC32.060]
 */
SQLRETURN WINAPI SQLForeignKeys(SQLHSTMT hstmt, SQLCHAR *szPkCatalogName, SQLSMALLINT cbPkCatalogName,
                                SQLCHAR *szPkSchemaName, SQLSMALLINT cbPkSchemaName, SQLCHAR *szPkTableName,
                                SQLSMALLINT cbPkTableName, SQLCHAR *szFkCatalogName,
                                SQLSMALLINT cbFkCatalogName, SQLCHAR *szFkSchemaName,
                                SQLSMALLINT cbFkSchemaName, SQLCHAR *szFkTableName, SQLSMALLINT cbFkTableName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szPkCatalogName %s, cbPkCatalogName %d, szPkSchemaName %s, cbPkSchemaName %d,"
          " szPkTableName %s, cbPkTableName %d, szFkCatalogName %s, cbFkCatalogName %d, szFkSchemaName %s,"
          " cbFkSchemaName %d, szFkTableName %s, cbFkTableName %d)\n", hstmt,
          debugstr_an((const char *)szPkCatalogName, cbPkCatalogName), cbPkCatalogName,
          debugstr_an((const char *)szPkSchemaName, cbPkSchemaName), cbPkSchemaName,
          debugstr_an((const char *)szPkTableName, cbPkTableName), cbPkTableName,
          debugstr_an((const char *)szFkCatalogName, cbFkCatalogName), cbFkCatalogName,
          debugstr_an((const char *)szFkSchemaName, cbFkSchemaName), cbFkSchemaName,
          debugstr_an((const char *)szFkTableName, cbFkTableName), cbFkTableName);

    return ret;
}

/*************************************************************************
 *				SQLMoreResults           [ODBC32.061]
 */
SQLRETURN WINAPI SQLMoreResults(SQLHSTMT StatementHandle)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(%p)\n", StatementHandle);

    return ret;
}

/*************************************************************************
 *				SQLNativeSql           [ODBC32.062]
 */
SQLRETURN WINAPI SQLNativeSql(SQLHDBC hdbc, SQLCHAR *szSqlStrIn, SQLINTEGER cbSqlStrIn, SQLCHAR *szSqlStr,
                              SQLINTEGER cbSqlStrMax, SQLINTEGER *pcbSqlStr)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hdbc %p, szSqlStrIn %s, cbSqlStrIn %d, szSqlStr %p, cbSqlStrMax %d, pcbSqlStr %p)\n", hdbc,
          debugstr_an((const char *)szSqlStrIn, cbSqlStrIn), cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr);

    return ret;
}

/*************************************************************************
 *				SQLNumParams           [ODBC32.063]
 */
SQLRETURN WINAPI SQLNumParams(SQLHSTMT hstmt, SQLSMALLINT *pcpar)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, pcpar %p)\n", hstmt, pcpar);

    return ret;
}

/*************************************************************************
 *				SQLParamOptions           [ODBC32.064]
 */
SQLRETURN WINAPI SQLParamOptions(SQLHSTMT hstmt, SQLULEN crow, SQLULEN *pirow)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, crow %s, pirow %p)\n", hstmt, debugstr_sqlulen(crow), pirow);

    return ret;
}

/*************************************************************************
 *				SQLPrimaryKeys           [ODBC32.065]
 */
SQLRETURN WINAPI SQLPrimaryKeys(SQLHSTMT hstmt, SQLCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                SQLCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLCHAR *szTableName,
                                SQLSMALLINT cbTableName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szTableName %s,"
          " cbTableName %d)\n", hstmt,
          debugstr_an((const char *)szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_an((const char *)szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_an((const char *)szTableName, cbTableName), cbTableName);

    return ret;
}

/*************************************************************************
 *				SQLProcedureColumns           [ODBC32.066]
 */
SQLRETURN WINAPI SQLProcedureColumns(SQLHSTMT hstmt, SQLCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                     SQLCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLCHAR *szProcName,
                                     SQLSMALLINT cbProcName, SQLCHAR *szColumnName, SQLSMALLINT cbColumnName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szProcName %s,"
          " cbProcName %d, szColumnName %s, cbColumnName %d)\n", hstmt,
          debugstr_an((const char *)szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_an((const char *)szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_an((const char *)szProcName, cbProcName), cbProcName,
          debugstr_an((const char *)szColumnName, cbColumnName), cbColumnName);

    return ret;
}

/*************************************************************************
 *				SQLProcedures           [ODBC32.067]
 */
SQLRETURN WINAPI SQLProcedures(SQLHSTMT hstmt, SQLCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                               SQLCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLCHAR *szProcName,
                               SQLSMALLINT cbProcName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szProcName %s,"
          " cbProcName %d)\n", hstmt,
          debugstr_an((const char *)szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_an((const char *)szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_an((const char *)szProcName, cbProcName), cbProcName);

    return ret;
}

/*************************************************************************
 *				SQLSetPos           [ODBC32.068]
 */
SQLRETURN WINAPI SQLSetPos(SQLHSTMT hstmt, SQLSETPOSIROW irow, SQLUSMALLINT fOption, SQLUSMALLINT fLock)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, irow %s, fOption %d, fLock %d)\n", hstmt, debugstr_sqlulen(irow), fOption, fLock);

    return ret;
}

/*************************************************************************
 *				SQLTablePrivileges           [ODBC32.070]
 */
SQLRETURN WINAPI SQLTablePrivileges(SQLHSTMT hstmt, SQLCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                    SQLCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLCHAR *szTableName,
                                    SQLSMALLINT cbTableName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szTableName %s,"
          " cbTableName %d)\n", hstmt,
          debugstr_an((const char *)szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_an((const char *)szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_an((const char *)szTableName, cbTableName), cbTableName);

    return ret;
}

/*************************************************************************
 *				SQLDrivers           [ODBC32.071]
 */
SQLRETURN WINAPI SQLDrivers(SQLHENV EnvironmentHandle, SQLUSMALLINT fDirection, SQLCHAR *szDriverDesc,
                            SQLSMALLINT cbDriverDescMax, SQLSMALLINT *pcbDriverDesc,
                            SQLCHAR *szDriverAttributes, SQLSMALLINT cbDriverAttrMax,
                            SQLSMALLINT *pcbDriverAttr)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Direction %d, szDriverDesc %p, cbDriverDescMax %d, pcbDriverDesc %p,"
          " DriverAttributes %p, cbDriverAttrMax %d, pcbDriverAttr %p)\n", EnvironmentHandle, fDirection,
          szDriverDesc, cbDriverDescMax, pcbDriverDesc, szDriverAttributes, cbDriverAttrMax, pcbDriverAttr);

    return ret;
}

/*************************************************************************
 *				SQLBindParameter           [ODBC32.072]
 */
SQLRETURN WINAPI SQLBindParameter(SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fParamType,
                                  SQLSMALLINT fCType, SQLSMALLINT fSqlType, SQLULEN cbColDef,
                                  SQLSMALLINT ibScale, SQLPOINTER rgbValue, SQLLEN cbValueMax,
                                  SQLLEN *pcbValue)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, ipar %d, fParamType %d, fCType %d, fSqlType %d, cbColDef %s, ibScale %d, rgbValue %p,"
          " cbValueMax %s, pcbValue %p)\n", hstmt, ipar, fParamType, fCType, fSqlType, debugstr_sqlulen(cbColDef),
          ibScale, rgbValue, debugstr_sqllen(cbValueMax), pcbValue);

    return ret;
}

/*************************************************************************
 *				SQLDriverConnect           [ODBC32.041]
 */
SQLRETURN WINAPI SQLDriverConnect(SQLHDBC hdbc, SQLHWND hwnd, SQLCHAR *ConnectionString, SQLSMALLINT Length,
                                  SQLCHAR *conn_str_out, SQLSMALLINT conn_str_out_max,
                                  SQLSMALLINT *ptr_conn_str_out, SQLUSMALLINT driver_completion)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hdbc %p, hwnd %p, ConnectionString %s, Length %d, conn_str_out %p, conn_str_out_max %d,"
          " ptr_conn_str_out %p, driver_completion %d)\n", hdbc, hwnd,
          debugstr_an((const char *)ConnectionString, Length), Length, conn_str_out, conn_str_out_max,
          ptr_conn_str_out, driver_completion);

    return ret;
}

/*************************************************************************
 *				SQLSetScrollOptions           [ODBC32.069]
 */
SQLRETURN WINAPI SQLSetScrollOptions(SQLHSTMT statement_handle, SQLUSMALLINT f_concurrency, SQLLEN crow_keyset,
                                     SQLUSMALLINT crow_rowset)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(statement_handle %p, f_concurrency %d, crow_keyset %s, crow_rowset %d)\n", statement_handle,
          f_concurrency, debugstr_sqllen(crow_keyset), crow_rowset);

    return ret;
}

/*************************************************************************
 *				SQLColAttributesW          [ODBC32.106]
 */
SQLRETURN WINAPI SQLColAttributesW(SQLHSTMT hstmt, SQLUSMALLINT icol, SQLUSMALLINT fDescType,
                                   SQLPOINTER rgbDesc, SQLSMALLINT cbDescMax, SQLSMALLINT *pcbDesc,
                                   SQLLEN *pfDesc)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, icol %d, fDescType %d, rgbDesc %p, cbDescMax %d, pcbDesc %p, pfDesc %p)\n", hstmt, icol,
          fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc);

    return ret;
}

/*************************************************************************
 *				SQLConnectW          [ODBC32.107]
 */
SQLRETURN WINAPI SQLConnectW(SQLHDBC ConnectionHandle, WCHAR *ServerName, SQLSMALLINT NameLength1,
                             WCHAR *UserName, SQLSMALLINT NameLength2, WCHAR *Authentication,
                             SQLSMALLINT NameLength3)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, ServerName %s, NameLength1 %d, UserName %s, NameLength2 %d, Authentication %s,"
          " NameLength3 %d)\n", ConnectionHandle, debugstr_wn(ServerName, NameLength1), NameLength1,
          debugstr_wn(UserName, NameLength2), NameLength2, debugstr_wn(Authentication, NameLength3), NameLength3);

    return ret;
}

/*************************************************************************
 *				SQLDescribeColW          [ODBC32.108]
 */
SQLRETURN WINAPI SQLDescribeColW(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, WCHAR *ColumnName,
                                 SQLSMALLINT BufferLength, SQLSMALLINT *NameLength, SQLSMALLINT *DataType,
                                 SQLULEN *ColumnSize, SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable)
{
    SQLSMALLINT dummy;
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, ColumnNumber %d, ColumnName %p, BufferLength %d, NameLength %p, DataType %p,"
          " ColumnSize %p, DecimalDigits %p, Nullable %p)\n", StatementHandle, ColumnNumber, ColumnName,
          BufferLength, NameLength, DataType, ColumnSize, DecimalDigits, Nullable);

    if (!NameLength) NameLength = &dummy; /* workaround for drivers that don't accept NULL NameLength */

    return ret;
}

/*************************************************************************
 *				SQLErrorW          [ODBC32.110]
 */
SQLRETURN WINAPI SQLErrorW(SQLHENV EnvironmentHandle, SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,
                           WCHAR *Sqlstate, SQLINTEGER *NativeError, WCHAR *MessageText,
                           SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, ConnectionHandle %p, StatementHandle %p, Sqlstate %p, NativeError %p,"
          " MessageText %p, BufferLength %d, TextLength %p)\n", EnvironmentHandle, ConnectionHandle,
          StatementHandle, Sqlstate, NativeError, MessageText, BufferLength, TextLength);

    return ret;
}

/*************************************************************************
 *				SQLExecDirectW          [ODBC32.111]
 */
SQLRETURN WINAPI SQLExecDirectW(SQLHSTMT StatementHandle, WCHAR *StatementText, SQLINTEGER TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, StatementText %s, TextLength %d)\n", StatementHandle,
          debugstr_wn(StatementText, TextLength), TextLength);

    return ret;
}

/*************************************************************************
 *				SQLGetCursorNameW          [ODBC32.117]
 */
SQLRETURN WINAPI SQLGetCursorNameW(SQLHSTMT StatementHandle, WCHAR *CursorName, SQLSMALLINT BufferLength,
                                   SQLSMALLINT *NameLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CursorName %p, BufferLength %d, NameLength %p)\n", StatementHandle, CursorName,
          BufferLength, NameLength);

    return ret;
}

/*************************************************************************
 *				SQLPrepareW          [ODBC32.119]
 */
SQLRETURN WINAPI SQLPrepareW(SQLHSTMT StatementHandle, WCHAR *StatementText, SQLINTEGER TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, StatementText %s, TextLength %d)\n", StatementHandle,
          debugstr_wn(StatementText, TextLength), TextLength);

    return ret;
}

/*************************************************************************
 *				SQLSetCursorNameW          [ODBC32.121]
 */
SQLRETURN WINAPI SQLSetCursorNameW(SQLHSTMT StatementHandle, WCHAR *CursorName, SQLSMALLINT NameLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CursorName %s, NameLength %d)\n", StatementHandle,
          debugstr_wn(CursorName, NameLength), NameLength);

    return ret;
}

/*************************************************************************
 *				SQLColAttributeW          [ODBC32.127]
 */
SQLRETURN WINAPI SQLColAttributeW(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber,
                                  SQLUSMALLINT FieldIdentifier, SQLPOINTER CharacterAttribute,
                                  SQLSMALLINT BufferLength, SQLSMALLINT *StringLength,
                                  SQLLEN *NumericAttribute)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("StatementHandle %p ColumnNumber %d FieldIdentifier %d CharacterAttribute %p BufferLength %d"
          " StringLength %p NumericAttribute %p\n", StatementHandle, ColumnNumber, FieldIdentifier,
          CharacterAttribute, BufferLength, StringLength, NumericAttribute);

    return ret;
}

/*************************************************************************
 *				SQLGetConnectAttrW          [ODBC32.132]
 */
SQLRETURN WINAPI SQLGetConnectAttrW(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                    SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Attribute %d, Value %p, BufferLength %d, StringLength %p)\n", ConnectionHandle,
          Attribute, Value, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetDescFieldW          [ODBC32.133]
 */
SQLRETURN WINAPI SQLGetDescFieldW(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
                                  SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, FieldIdentifier %d, Value %p, BufferLength %d, StringLength %p)\n",
          DescriptorHandle, RecNumber, FieldIdentifier, Value, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetDescRecW          [ODBC32.134]
 */
SQLRETURN WINAPI SQLGetDescRecW(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, WCHAR *Name,
                                SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLSMALLINT *Type,
                                SQLSMALLINT *SubType, SQLLEN *Length, SQLSMALLINT *Precision,
                                SQLSMALLINT *Scale, SQLSMALLINT *Nullable)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, Name %p, BufferLength %d, StringLength %p, Type %p, SubType %p,"
          " Length %p, Precision %p, Scale %p, Nullable %p)\n", DescriptorHandle, RecNumber, Name, BufferLength,
          StringLength, Type, SubType, Length, Precision, Scale, Nullable);

    return ret;
}

/*************************************************************************
 *				SQLGetDiagFieldW          [ODBC32.135]
 */
SQLRETURN WINAPI SQLGetDiagFieldW(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber,
                                  SQLSMALLINT DiagIdentifier, SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
                                  SQLSMALLINT *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p, RecNumber %d, DiagIdentifier %d, DiagInfo %p, BufferLength %d,"
          " StringLength %p)\n", HandleType, Handle, RecNumber, DiagIdentifier, DiagInfo, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetDiagRecW           [ODBC32.136]
 */
SQLRETURN WINAPI SQLGetDiagRecW(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber,
                                WCHAR *Sqlstate, SQLINTEGER *NativeError, WCHAR *MessageText,
                                SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p, RecNumber %d, Sqlstate %p, NativeError %p, MessageText %p, BufferLength %d,"
          " TextLength %p)\n", HandleType, Handle, RecNumber, Sqlstate, NativeError, MessageText, BufferLength,
          TextLength);

    return ret;
}

/*************************************************************************
 *				SQLGetStmtAttrW          [ODBC32.138]
 */
SQLRETURN WINAPI SQLGetStmtAttrW(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                 SQLINTEGER BufferLength, SQLINTEGER *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Attribute %d, Value %p, BufferLength %d, StringLength %p)\n", StatementHandle,
          Attribute, Value, BufferLength, StringLength);

    if (!Value)
    {
        WARN("Unexpected NULL Value return address\n");
        return SQL_ERROR;
    }

    return ret;
}

/*************************************************************************
 *				SQLSetConnectAttrW          [ODBC32.139]
 */
SQLRETURN WINAPI SQLSetConnectAttrW(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                    SQLINTEGER StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Attribute %d, Value %p, StringLength %d)\n", ConnectionHandle, Attribute, Value,
          StringLength);

    return ret;
}

/*************************************************************************
 *				SQLColumnsW          [ODBC32.140]
 */
SQLRETURN WINAPI SQLColumnsW(SQLHSTMT StatementHandle, WCHAR *CatalogName, SQLSMALLINT NameLength1,
                             WCHAR *SchemaName, SQLSMALLINT NameLength2, WCHAR *TableName,
                             SQLSMALLINT NameLength3, WCHAR *ColumnName, SQLSMALLINT NameLength4)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CatalogName %s, NameLength1 %d, SchemaName %s, NameLength2 %d, TableName %s,"
          " NameLength3 %d, ColumnName %s, NameLength4 %d)\n", StatementHandle,
          debugstr_wn(CatalogName, NameLength1), NameLength1, debugstr_wn(SchemaName, NameLength2), NameLength2,
          debugstr_wn(TableName, NameLength3), NameLength3, debugstr_wn(ColumnName, NameLength4), NameLength4);

    FIXME("Returning %d\n", ret);
    return ret;
}

/*************************************************************************
 *				SQLDriverConnectW          [ODBC32.141]
 */
SQLRETURN WINAPI SQLDriverConnectW(SQLHDBC ConnectionHandle, SQLHWND WindowHandle, WCHAR *InConnectionString,
                                   SQLSMALLINT Length, WCHAR *OutConnectionString, SQLSMALLINT BufferLength,
                                   SQLSMALLINT *Length2, SQLUSMALLINT DriverCompletion)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, WindowHandle %p, InConnectionString %s, Length %d, OutConnectionString %p,"
          " BufferLength %d, Length2 %p, DriverCompletion %d)\n", ConnectionHandle, WindowHandle,
          debugstr_wn(InConnectionString, Length), Length, OutConnectionString, BufferLength, Length2,
          DriverCompletion);

    return ret;
}

/*************************************************************************
 *				SQLGetConnectOptionW      [ODBC32.142]
 */
SQLRETURN WINAPI SQLGetConnectOptionW(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLPOINTER Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Option %d, Value %p)\n", ConnectionHandle, Option, Value);

    return ret;
}

/*************************************************************************
 *				SQLGetInfoW          [ODBC32.145]
 */
SQLRETURN WINAPI SQLGetInfoW(SQLHDBC ConnectionHandle, SQLUSMALLINT InfoType, SQLPOINTER InfoValue,
                             SQLSMALLINT BufferLength, SQLSMALLINT *StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle, %p, InfoType %d, InfoValue %p, BufferLength %d, StringLength %p)\n", ConnectionHandle,
          InfoType, InfoValue, BufferLength, StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetTypeInfoW          [ODBC32.147]
 */
SQLRETURN WINAPI SQLGetTypeInfoW(SQLHSTMT StatementHandle, SQLSMALLINT DataType)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, DataType %d)\n", StatementHandle, DataType);

    return ret;
}

/*************************************************************************
 *				SQLSetConnectOptionW          [ODBC32.150]
 */
SQLRETURN WINAPI SQLSetConnectOptionW(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLLEN Value)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(ConnectionHandle %p, Option %d, Value %s)\n", ConnectionHandle, Option, debugstr_sqllen(Value));

    return ret;
}

/*************************************************************************
 *				SQLSpecialColumnsW          [ODBC32.152]
 */
SQLRETURN WINAPI SQLSpecialColumnsW(SQLHSTMT StatementHandle, SQLUSMALLINT IdentifierType,
                                    SQLWCHAR *CatalogName, SQLSMALLINT NameLength1, SQLWCHAR *SchemaName,
                                    SQLSMALLINT NameLength2, SQLWCHAR *TableName, SQLSMALLINT NameLength3,
                                    SQLUSMALLINT Scope, SQLUSMALLINT Nullable)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, IdentifierType %d, CatalogName %s, NameLength1 %d, SchemaName %s, NameLength2 %d,"
          " TableName %s, NameLength3 %d, Scope %d, Nullable %d)\n", StatementHandle, IdentifierType,
          debugstr_wn(CatalogName, NameLength1), NameLength1, debugstr_wn(SchemaName, NameLength2), NameLength2,
          debugstr_wn(TableName, NameLength3), NameLength3, Scope, Nullable);

    return ret;
}

/*************************************************************************
 *				SQLStatisticsW          [ODBC32.153]
 */
SQLRETURN WINAPI SQLStatisticsW(SQLHSTMT StatementHandle, SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
                                SQLWCHAR *SchemaName, SQLSMALLINT NameLength2, SQLWCHAR *TableName,
                                SQLSMALLINT NameLength3, SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CatalogName %s, NameLength1 %d SchemaName %s, NameLength2 %d, TableName %s"
          " NameLength3 %d, Unique %d, Reserved %d)\n", StatementHandle,
          debugstr_wn(CatalogName, NameLength1), NameLength1, debugstr_wn(SchemaName, NameLength2), NameLength2,
          debugstr_wn(TableName, NameLength3), NameLength3, Unique, Reserved);

    return ret;
}

/*************************************************************************
 *				SQLTablesW          [ODBC32.154]
 */
SQLRETURN WINAPI SQLTablesW(SQLHSTMT StatementHandle, SQLWCHAR *CatalogName, SQLSMALLINT NameLength1,
                            SQLWCHAR *SchemaName, SQLSMALLINT NameLength2, SQLWCHAR *TableName,
                            SQLSMALLINT NameLength3, SQLWCHAR *TableType, SQLSMALLINT NameLength4)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, CatalogName %s, NameLength1 %d, SchemaName %s, NameLength2 %d, TableName %s,"
          " NameLength3 %d, TableType %s, NameLength4 %d)\n", StatementHandle,
          debugstr_wn(CatalogName, NameLength1), NameLength1, debugstr_wn(SchemaName, NameLength2), NameLength2,
          debugstr_wn(TableName, NameLength3), NameLength3, debugstr_wn(TableType, NameLength4), NameLength4);

    return ret;
}

/*************************************************************************
 *				SQLBrowseConnectW          [ODBC32.155]
 */
SQLRETURN WINAPI SQLBrowseConnectW(SQLHDBC hdbc, SQLWCHAR *szConnStrIn, SQLSMALLINT cbConnStrIn,
                                   SQLWCHAR *szConnStrOut, SQLSMALLINT cbConnStrOutMax,
                                   SQLSMALLINT *pcbConnStrOut)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hdbc %p, szConnStrIn %s, cbConnStrIn %d, szConnStrOut %p, cbConnStrOutMax %d, pcbConnStrOut %p)\n",
          hdbc, debugstr_wn(szConnStrIn, cbConnStrIn), cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut);

    return ret;
}

/*************************************************************************
 *				SQLColumnPrivilegesW          [ODBC32.156]
 */
SQLRETURN WINAPI SQLColumnPrivilegesW(SQLHSTMT hstmt, SQLWCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                      SQLWCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLWCHAR *szTableName,
                                      SQLSMALLINT cbTableName, SQLWCHAR *szColumnName, SQLSMALLINT cbColumnName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szTableName %s,"
          " cbTableName %d, szColumnName %s, cbColumnName %d)\n", hstmt,
          debugstr_wn(szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_wn(szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_wn(szTableName, cbTableName), cbTableName,
          debugstr_wn(szColumnName, cbColumnName), cbColumnName);

    return ret;
}

/*************************************************************************
 *				SQLDataSourcesW          [ODBC32.157]
 */
SQLRETURN WINAPI SQLDataSourcesW(SQLHENV EnvironmentHandle, SQLUSMALLINT Direction, WCHAR *ServerName,
                                 SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1, WCHAR *Description,
                                 SQLSMALLINT BufferLength2, SQLSMALLINT *NameLength2)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Direction %d, ServerName %p, BufferLength1 %d, NameLength1 %p, Description %p,"
          " BufferLength2 %d, NameLength2 %p)\n", EnvironmentHandle, Direction, ServerName, BufferLength1,
          NameLength1, Description, BufferLength2, NameLength2);

    return ret;
}

/*************************************************************************
 *				SQLForeignKeysW          [ODBC32.160]
 */
SQLRETURN WINAPI SQLForeignKeysW(SQLHSTMT hstmt, SQLWCHAR *szPkCatalogName, SQLSMALLINT cbPkCatalogName,
                                 SQLWCHAR *szPkSchemaName, SQLSMALLINT cbPkSchemaName, SQLWCHAR *szPkTableName,
                                 SQLSMALLINT cbPkTableName, SQLWCHAR *szFkCatalogName,
                                 SQLSMALLINT cbFkCatalogName, SQLWCHAR *szFkSchemaName,
                                 SQLSMALLINT cbFkSchemaName, SQLWCHAR *szFkTableName, SQLSMALLINT cbFkTableName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szPkCatalogName %s, cbPkCatalogName %d, szPkSchemaName %s, cbPkSchemaName %d,"
          " szPkTableName %s, cbPkTableName %d, szFkCatalogName %s, cbFkCatalogName %d, szFkSchemaName %s,"
          " cbFkSchemaName %d, szFkTableName %s, cbFkTableName %d)\n", hstmt,
          debugstr_wn(szPkCatalogName, cbPkCatalogName), cbPkCatalogName,
          debugstr_wn(szPkSchemaName, cbPkSchemaName), cbPkSchemaName,
          debugstr_wn(szPkTableName, cbPkTableName), cbPkTableName,
          debugstr_wn(szFkCatalogName, cbFkCatalogName), cbFkCatalogName,
          debugstr_wn(szFkSchemaName, cbFkSchemaName), cbFkSchemaName,
          debugstr_wn(szFkTableName, cbFkTableName), cbFkTableName);

    return ret;
}

/*************************************************************************
 *				SQLNativeSqlW          [ODBC32.162]
 */
SQLRETURN WINAPI SQLNativeSqlW(SQLHDBC hdbc, SQLWCHAR *szSqlStrIn, SQLINTEGER cbSqlStrIn, SQLWCHAR *szSqlStr,
                               SQLINTEGER cbSqlStrMax, SQLINTEGER *pcbSqlStr)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hdbc %p, szSqlStrIn %s, cbSqlStrIn %d, szSqlStr %p, cbSqlStrMax %d, pcbSqlStr %p)\n", hdbc,
          debugstr_wn(szSqlStrIn, cbSqlStrIn), cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr);

    return ret;
}

/*************************************************************************
 *				SQLPrimaryKeysW          [ODBC32.165]
 */
SQLRETURN WINAPI SQLPrimaryKeysW(SQLHSTMT hstmt, SQLWCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                 SQLWCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLWCHAR *szTableName,
                                 SQLSMALLINT cbTableName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szTableName %s,"
          " cbTableName %d)\n", hstmt,
          debugstr_wn(szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_wn(szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_wn(szTableName, cbTableName), cbTableName);

    return ret;
}

/*************************************************************************
 *				SQLProcedureColumnsW          [ODBC32.166]
 */
SQLRETURN WINAPI SQLProcedureColumnsW(SQLHSTMT hstmt, SQLWCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                      SQLWCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLWCHAR *szProcName,
                                      SQLSMALLINT cbProcName, SQLWCHAR *szColumnName, SQLSMALLINT cbColumnName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szProcName %s,"
          " cbProcName %d, szColumnName %s, cbColumnName %d)\n", hstmt,
          debugstr_wn(szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_wn(szSchemaName, cbSchemaName), cbSchemaName,
          debugstr_wn(szProcName, cbProcName), cbProcName,
          debugstr_wn(szColumnName, cbColumnName), cbColumnName);

    return ret;
}

/*************************************************************************
 *				SQLProceduresW          [ODBC32.167]
 */
SQLRETURN WINAPI SQLProceduresW(SQLHSTMT hstmt, SQLWCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                SQLWCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLWCHAR *szProcName,
                                SQLSMALLINT cbProcName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szProcName %s,"
          " cbProcName %d)\n", hstmt, debugstr_wn(szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_wn(szSchemaName, cbSchemaName), cbSchemaName, debugstr_wn(szProcName, cbProcName), cbProcName);

    return ret;
}

/*************************************************************************
 *				SQLTablePrivilegesW          [ODBC32.170]
 */
SQLRETURN WINAPI SQLTablePrivilegesW(SQLHSTMT hstmt, SQLWCHAR *szCatalogName, SQLSMALLINT cbCatalogName,
                                     SQLWCHAR *szSchemaName, SQLSMALLINT cbSchemaName, SQLWCHAR *szTableName,
                                     SQLSMALLINT cbTableName)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(hstmt %p, szCatalogName %s, cbCatalogName %d, szSchemaName %s, cbSchemaName %d, szTableName %s,"
          " cbTableName %d)\n", hstmt, debugstr_wn(szCatalogName, cbCatalogName), cbCatalogName,
          debugstr_wn(szSchemaName, cbSchemaName), cbSchemaName, debugstr_wn(szTableName, cbTableName), cbTableName);

    return ret;
}

/*************************************************************************
 *				SQLDriversW          [ODBC32.171]
 */
SQLRETURN WINAPI SQLDriversW(SQLHENV EnvironmentHandle, SQLUSMALLINT fDirection, SQLWCHAR *szDriverDesc,
                             SQLSMALLINT cbDriverDescMax, SQLSMALLINT *pcbDriverDesc,
                             SQLWCHAR *szDriverAttributes, SQLSMALLINT cbDriverAttrMax,
                             SQLSMALLINT *pcbDriverAttr)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(EnvironmentHandle %p, Direction %d, szDriverDesc %p, cbDriverDescMax %d, pcbDriverDesc %p,"
          " DriverAttributes %p, cbDriverAttrMax %d, pcbDriverAttr %p)\n", EnvironmentHandle, fDirection,
          szDriverDesc, cbDriverDescMax, pcbDriverDesc, szDriverAttributes, cbDriverAttrMax, pcbDriverAttr);

    return ret;
}

/*************************************************************************
 *				SQLSetDescFieldW          [ODBC32.173]
 */
SQLRETURN WINAPI SQLSetDescFieldW(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
                                  SQLPOINTER Value, SQLINTEGER BufferLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(DescriptorHandle %p, RecNumber %d, FieldIdentifier %d, Value %p, BufferLength %d)\n", DescriptorHandle,
          RecNumber, FieldIdentifier, Value, BufferLength);

    return ret;
}

/*************************************************************************
 *				SQLSetStmtAttrW          [ODBC32.176]
 */
SQLRETURN WINAPI SQLSetStmtAttrW(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER Value,
                                 SQLINTEGER StringLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(StatementHandle %p, Attribute %d, Value %p, StringLength %d)\n", StatementHandle, Attribute, Value,
          StringLength);

    return ret;
}

/*************************************************************************
 *				SQLGetDiagRecA           [ODBC32.236]
 */
SQLRETURN WINAPI SQLGetDiagRecA(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber,
                                SQLCHAR *Sqlstate, SQLINTEGER *NativeError, SQLCHAR *MessageText,
                                SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
{
    SQLRETURN ret = SQL_ERROR;

    FIXME("(HandleType %d, Handle %p, RecNumber %d, Sqlstate %p, NativeError %p, MessageText %p, BufferLength %d,"
          " TextLength %p)\n", HandleType, Handle, RecNumber, Sqlstate, NativeError, MessageText, BufferLength,
          TextLength);

    return ret;
}
