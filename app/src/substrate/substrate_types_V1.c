/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readBoxCallOrHashOfT_V1(parser_context_t* c, pd_BoxCallOrHashOfT_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxPalletsOrigin_V1(parser_context_t* c, pd_BoxPalletsOrigin_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCompactAccountIndex_V1(parser_context_t* c, pd_CompactAccountIndex_V1_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readKeyValue_V1(parser_context_t* c, pd_KeyValue_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V1(parser_context_t* c, pd_Key_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLookupasStaticLookupSource_V1(parser_context_t* c, pd_LookupasStaticLookupSource_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V1(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V1(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount_V1(parser_context_t* c, pd_MemberCount_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readOpaqueCall_V1(parser_context_t* c, pd_OpaqueCall_V1_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readParachainInherentData_V1(parser_context_t* c, pd_ParachainInherentData_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readTimepoint_V1(parser_context_t* c, pd_Timepoint_V1_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readUpwardMessage_V1(parser_context_t* c, pd_UpwardMessage_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVestingScheduleOf_V1(parser_context_t* c, pd_VestingScheduleOf_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBlockNumber(c, &v->start))
    CHECK_ERROR(_readBlockNumber(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->period_count))
    CHECK_ERROR(_readBalance(c, &v->balance));
    return parser_ok;
}

parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readschedulePeriodBlockNumber_V1(parser_context_t* c, pd_schedulePeriodBlockNumber_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readschedulePriority_V1(parser_context_t* c, pd_schedulePriority_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v) {
    GEN_DEF_READVECTOR(AccountId_V1)
}

parser_error_t _readVecKeyValue_V1(parser_context_t* c, pd_VecKeyValue_V1_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V1)
}

parser_error_t _readVecKey_V1(parser_context_t* c, pd_VecKey_V1_t* v) {
    GEN_DEF_READVECTOR(Key_V1)
}

parser_error_t _readVecVestingScheduleOf_V1(parser_context_t* c, pd_VecVestingScheduleOf_V1_t* v) {
    GEN_DEF_READVECTOR(VestingScheduleOf_V1)
}

parser_error_t _readOptionAccountId_V1(parser_context_t* c, pd_OptionAccountId_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V1(parser_context_t* c, pd_OptionTimepoint_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionschedulePeriodBlockNumber_V1(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readschedulePeriodBlockNumber_V1(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V1(
    const pd_AccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBoxCallOrHashOfT_V1(
    const pd_BoxCallOrHashOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxPalletsOrigin_V1(
    const pd_BoxPalletsOrigin_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCompactAccountIndex_V1(
    const pd_CompactAccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringKeyValue_V1(
    const pd_KeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V1(
    const pd_Key_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V1(
    const pd_Keys_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLookupasStaticLookupSource_V1(
    const pd_LookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V1(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V1(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMemberCount_V1(
    const pd_MemberCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOpaqueCall_V1(
    const pd_OpaqueCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringParachainInherentData_V1(
    const pd_ParachainInherentData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringTimepoint_V1(
    const pd_Timepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUpwardMessage_V1(
    const pd_UpwardMessage_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVestingScheduleOf_V1(
    const pd_VestingScheduleOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringBlockNumber(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBlockNumber(&v->period, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringu32(&v->period_count, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBlockNumber(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringu32(&v->period_count, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringWeight_V1(
    const pd_Weight_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringschedulePeriodBlockNumber_V1(
    const pd_schedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringschedulePriority_V1(
    const pd_schedulePriority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVecAccountId_V1(
    const pd_VecAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V1);
}

parser_error_t _toStringVecKeyValue_V1(
    const pd_VecKeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V1);
}

parser_error_t _toStringVecKey_V1(
    const pd_VecKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V1);
}

parser_error_t _toStringVecVestingScheduleOf_V1(
    const pd_VecVestingScheduleOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VestingScheduleOf_V1);
}

parser_error_t _toStringOptionAccountId_V1(
    const pd_OptionAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V1(
    const pd_OptionTimepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionschedulePeriodBlockNumber_V1(
    const pd_OptionschedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringschedulePeriodBlockNumber_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
