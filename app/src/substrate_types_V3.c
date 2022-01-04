/*******************************************************************************
*  (c) 2019 Zondax GmbH
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
#include "substrate_dispatch_V3.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readCompactMemberCount_V3(parser_context_t* c, pd_CompactMemberCount_V3_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V3(parser_context_t* c, pd_CompactMoment_V3_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactProposalIndex_V3(parser_context_t* c, pd_CompactProposalIndex_V3_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactWeight_V3(parser_context_t* c, pd_CompactWeight_V3_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId_V3(parser_context_t* c, pd_AccountId_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAmendment_V3(parser_context_t* c, pd_Amendment_V3_t* v)
{
    CHECK_ERROR(_readCall(c, &v->call))
    return parser_ok;
}

parser_error_t _readBabeEquivocationProof_V3(parser_context_t* c, pd_BabeEquivocationProof_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCertificateId_V3(parser_context_t* c, pd_CertificateId_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration_V3(parser_context_t* c, pd_ChangesTrieConfiguration_V3_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCodeHash_V3(parser_context_t* c, pd_CodeHash_V3_t* v)
{
    CHECK_ERROR(_readHash(c, &v->hash))
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V3(parser_context_t* c, pd_CompactAccountIndex_V3_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readGrandpaEquivocationProof_V3(parser_context_t* c, pd_GrandpaEquivocationProof_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V3(parser_context_t* c, pd_KeyOwnerProof_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V3(parser_context_t* c, pd_KeyValue_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V3(parser_context_t* c, pd_Key_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V3(parser_context_t* c, pd_Keys_V3_t* v) {
    GEN_DEF_READARRAY(4 * 32)
}

parser_error_t _readLookupSource_V3(parser_context_t* c, pd_LookupSource_V3_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V3(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V3(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
    case 4: // Address20
        GEN_DEF_READARRAY(20)
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount_V3(parser_context_t* c, pd_MemberCount_V3_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readOpaqueCall_V3(parser_context_t* c, pd_OpaqueCall_V3_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readPerbill_V3(parser_context_t* c, pd_Perbill_V3_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPeriod_V3(parser_context_t* c, pd_Period_V3_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPriority_V3(parser_context_t* c, pd_Priority_V3_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V3(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readSchedule_V3(parser_context_t* c, pd_Schedule_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readSignature_V3(parser_context_t* c, pd_Signature_V3_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readStreamDependency_V3(parser_context_t* c, pd_StreamDependency_V3_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTimepoint_V3(parser_context_t* c, pd_Timepoint_V3_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readVestingScheduleOf_V3(parser_context_t* c, pd_VestingScheduleOf_V3_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBlockNumber(c, &v->start))
    CHECK_ERROR(_readBlockNumber(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->period_count))
    CHECK_ERROR(_readBalance(c, &v->balance));
    return parser_ok;
}

parser_error_t _readWeight_V3(parser_context_t* c, pd_Weight_V3_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readVecAccountId_V3(parser_context_t* c, pd_VecAccountId_V3_t* v) {
    GEN_DEF_READVECTOR(AccountId_V3)
}

parser_error_t _readVecKeyValue_V3(parser_context_t* c, pd_VecKeyValue_V3_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V3)
}

parser_error_t _readVecKey_V3(parser_context_t* c, pd_VecKey_V3_t* v) {
    GEN_DEF_READVECTOR(Key_V3)
}

parser_error_t _readVecVestingScheduleOf_V3(parser_context_t* c, pd_VecVestingScheduleOf_V3_t* v) {
    GEN_DEF_READVECTOR(VestingScheduleOf_V3)
}

parser_error_t _readOptionAccountId_V3(parser_context_t* c, pd_OptionAccountId_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration_V3(parser_context_t* c, pd_OptionChangesTrieConfiguration_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V3(parser_context_t* c, pd_OptionPeriod_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V3(parser_context_t* c, pd_OptionTimepoint_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V3(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactMemberCount_V3(
    const pd_CompactMemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V3(
    const pd_CompactMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex_V3(
    const pd_CompactProposalIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactWeight_V3(
    const pd_CompactWeight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId_V3(
    const pd_AccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAmendment_V3(
    const pd_Amendment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBabeEquivocationProof_V3(
    const pd_BabeEquivocationProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCertificateId_V3(
    const pd_CertificateId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChangesTrieConfiguration_V3(
    const pd_ChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCodeHash_V3(
    const pd_CodeHash_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringHash(&v->hash, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactAccountIndex_V3(
    const pd_CompactAccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringGrandpaEquivocationProof_V3(
    const pd_GrandpaEquivocationProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V3(
    const pd_KeyOwnerProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V3(
    const pd_KeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V3(
    const pd_Key_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V3(
    const pd_Keys_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLookupSource_V3(
    const pd_LookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V3(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V3(&v->index, outValue, outValueLen, pageIdx, pageCount))
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

parser_error_t _toStringMemberCount_V3(
    const pd_MemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOpaqueCall_V3(
    const pd_OpaqueCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPerbill_V3(
    const pd_Perbill_V3_t* v,
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

parser_error_t _toStringPeriod_V3(
    const pd_Period_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPriority_V3(
    const pd_Priority_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V3(&v->dependency, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringStreamDependency_V3(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSchedule_V3(
    const pd_Schedule_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSignature_V3(
    const pd_Signature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringStreamDependency_V3(
    const pd_StreamDependency_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTimepoint_V3(
    const pd_Timepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVestingScheduleOf_V3(
    const pd_VestingScheduleOf_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringBlockNumber(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBlockNumber(&v->period, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringu32(&v->period_count, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBlockNumber(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringu32(&v->period_count, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringWeight_V3(
    const pd_Weight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountId_V3(
    const pd_VecAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V3);
}

parser_error_t _toStringVecKeyValue_V3(
    const pd_VecKeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V3);
}

parser_error_t _toStringVecKey_V3(
    const pd_VecKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V3);
}

parser_error_t _toStringVecVestingScheduleOf_V3(
    const pd_VecVestingScheduleOf_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VestingScheduleOf_V3);
}

parser_error_t _toStringOptionAccountId_V3(
    const pd_OptionAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration_V3(
    const pd_OptionChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V3(
    const pd_OptionPeriod_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V3(
    const pd_OptionTimepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
