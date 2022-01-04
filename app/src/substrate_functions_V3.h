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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V3.h"
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V3(parser_context_t* c, pd_AccountId_V3_t* v);
parser_error_t _readAmendment_V3(parser_context_t* c, pd_Amendment_V3_t* v);
parser_error_t _readBabeEquivocationProof_V3(parser_context_t* c, pd_BabeEquivocationProof_V3_t* v);
parser_error_t _readCertificateId_V3(parser_context_t* c, pd_CertificateId_V3_t* v);
parser_error_t _readChangesTrieConfiguration_V3(parser_context_t* c, pd_ChangesTrieConfiguration_V3_t* v);
parser_error_t _readCodeHash_V3(parser_context_t* c, pd_CodeHash_V3_t* v);
parser_error_t _readCompactAccountIndex_V3(parser_context_t* c, pd_CompactAccountIndex_V3_t* v);
parser_error_t _readCompactMemberCount_V3(parser_context_t* c, pd_CompactMemberCount_V3_t* v);
parser_error_t _readCompactMoment_V3(parser_context_t* c, pd_CompactMoment_V3_t* v);
parser_error_t _readCompactProposalIndex_V3(parser_context_t* c, pd_CompactProposalIndex_V3_t* v);
parser_error_t _readCompactWeight_V3(parser_context_t* c, pd_CompactWeight_V3_t* v);
parser_error_t _readGrandpaEquivocationProof_V3(parser_context_t* c, pd_GrandpaEquivocationProof_V3_t* v);
parser_error_t _readKeyOwnerProof_V3(parser_context_t* c, pd_KeyOwnerProof_V3_t* v);
parser_error_t _readKeyValue_V3(parser_context_t* c, pd_KeyValue_V3_t* v);
parser_error_t _readKey_V3(parser_context_t* c, pd_Key_V3_t* v);
parser_error_t _readKeys_V3(parser_context_t* c, pd_Keys_V3_t* v);
parser_error_t _readLookupSource_V3(parser_context_t* c, pd_LookupSource_V3_t* v);
parser_error_t _readMemberCount_V3(parser_context_t* c, pd_MemberCount_V3_t* v);
parser_error_t _readOpaqueCall_V3(parser_context_t* c, pd_OpaqueCall_V3_t* v);
parser_error_t _readOptionAccountId_V3(parser_context_t* c, pd_OptionAccountId_V3_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V3(parser_context_t* c, pd_OptionChangesTrieConfiguration_V3_t* v);
parser_error_t _readOptionPeriod_V3(parser_context_t* c, pd_OptionPeriod_V3_t* v);
parser_error_t _readOptionTimepoint_V3(parser_context_t* c, pd_OptionTimepoint_V3_t* v);
parser_error_t _readPerbill_V3(parser_context_t* c, pd_Perbill_V3_t* v);
parser_error_t _readPeriod_V3(parser_context_t* c, pd_Period_V3_t* v);
parser_error_t _readPriority_V3(parser_context_t* c, pd_Priority_V3_t* v);
parser_error_t _readSchedule_V3(parser_context_t* c, pd_Schedule_V3_t* v);
parser_error_t _readSignature_V3(parser_context_t* c, pd_Signature_V3_t* v);
parser_error_t _readStreamDependency_V3(parser_context_t* c, pd_StreamDependency_V3_t* v);
parser_error_t _readTimepoint_V3(parser_context_t* c, pd_Timepoint_V3_t* v);
parser_error_t _readVecAccountId_V3(parser_context_t* c, pd_VecAccountId_V3_t* v);
parser_error_t _readVecKeyValue_V3(parser_context_t* c, pd_VecKeyValue_V3_t* v);
parser_error_t _readVecKey_V3(parser_context_t* c, pd_VecKey_V3_t* v);
parser_error_t _readVecVestingScheduleOf_V3(parser_context_t* c, pd_VecVestingScheduleOf_V3_t* v);
parser_error_t _readVestingScheduleOf_V3(parser_context_t* c, pd_VestingScheduleOf_V3_t* v);
parser_error_t _readWeight_V3(parser_context_t* c, pd_Weight_V3_t* v);

// toString functions
parser_error_t _toStringAccountId_V3(
    const pd_AccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAmendment_V3(
    const pd_Amendment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V3(
    const pd_BabeEquivocationProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCertificateId_V3(
    const pd_CertificateId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V3(
    const pd_ChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V3(
    const pd_CodeHash_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V3(
    const pd_CompactAccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMemberCount_V3(
    const pd_CompactMemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V3(
    const pd_CompactMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactProposalIndex_V3(
    const pd_CompactProposalIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactWeight_V3(
    const pd_CompactWeight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V3(
    const pd_GrandpaEquivocationProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V3(
    const pd_KeyOwnerProof_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V3(
    const pd_KeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V3(
    const pd_Key_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V3(
    const pd_Keys_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V3(
    const pd_LookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V3(
    const pd_MemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V3(
    const pd_OpaqueCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V3(
    const pd_OptionAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V3(
    const pd_OptionChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V3(
    const pd_OptionPeriod_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V3(
    const pd_OptionTimepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V3(
    const pd_Perbill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V3(
    const pd_Period_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V3(
    const pd_Priority_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSchedule_V3(
    const pd_Schedule_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V3(
    const pd_Signature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V3(
    const pd_StreamDependency_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V3(
    const pd_Timepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V3(
    const pd_VecAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V3(
    const pd_VecKeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V3(
    const pd_VecKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVestingScheduleOf_V3(
    const pd_VecVestingScheduleOf_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V3(
    const pd_VestingScheduleOf_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V3(
    const pd_Weight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
