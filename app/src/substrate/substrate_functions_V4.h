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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V4.h"
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V4(parser_context_t* c, pd_AccountId_V4_t* v);
parser_error_t _readBoundedVecu8_V4(parser_context_t* c, pd_BoundedVecu8_V4_t* v);
parser_error_t _readClassId_V4(parser_context_t* c, pd_ClassId_V4_t* v);
parser_error_t _readCompactAccountIndex_V4(parser_context_t* c, pd_CompactAccountIndex_V4_t* v);
parser_error_t _readDestroyWitness_V4(parser_context_t* c, pd_DestroyWitness_V4_t* v);
parser_error_t _readInstanceId_V4(parser_context_t* c, pd_InstanceId_V4_t* v);
parser_error_t _readKeys_V4(parser_context_t* c, pd_Keys_V4_t* v);
parser_error_t _readLookupasStaticLookupSource_V4(parser_context_t* c, pd_LookupasStaticLookupSource_V4_t* v);
parser_error_t _readMemberCount_V4(parser_context_t* c, pd_MemberCount_V4_t* v);
parser_error_t _readOpaqueCall_V4(parser_context_t* c, pd_OpaqueCall_V4_t* v);
parser_error_t _readOptionAccountId_V4(parser_context_t* c, pd_OptionAccountId_V4_t* v);
parser_error_t _readOptionClassId_V4(parser_context_t* c, pd_OptionClassId_V4_t* v);
parser_error_t _readOptionInstanceId_V4(parser_context_t* c, pd_OptionInstanceId_V4_t* v);
parser_error_t _readOptionLookupasStaticLookupSource_V4(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V4_t* v);
parser_error_t _readOptionTimepoint_V4(parser_context_t* c, pd_OptionTimepoint_V4_t* v);
parser_error_t _readPerbill_V4(parser_context_t* c, pd_Perbill_V4_t* v);
parser_error_t _readTimepoint_V4(parser_context_t* c, pd_Timepoint_V4_t* v);
parser_error_t _readTupleAccountIdBalanceOf_V4(parser_context_t* c, pd_TupleAccountIdBalanceOf_V4_t* v);
parser_error_t _readVecAccountId_V4(parser_context_t* c, pd_VecAccountId_V4_t* v);
parser_error_t _readVecInstanceId_V4(parser_context_t* c, pd_VecInstanceId_V4_t* v);
parser_error_t _readVecTupleAccountIdBalanceOf_V4(parser_context_t* c, pd_VecTupleAccountIdBalanceOf_V4_t* v);
parser_error_t _readVestingScheduleOf_V4(parser_context_t* c, pd_VestingScheduleOf_V4_t* v);
parser_error_t _readWeight_V4(parser_context_t* c, pd_Weight_V4_t* v);

// toString functions
parser_error_t _toStringAccountId_V4(
    const pd_AccountId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V4(
    const pd_BoundedVecu8_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassId_V4(
    const pd_ClassId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V4(
    const pd_CompactAccountIndex_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V4(
    const pd_DestroyWitness_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstanceId_V4(
    const pd_InstanceId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V4(
    const pd_Keys_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V4(
    const pd_LookupasStaticLookupSource_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V4(
    const pd_MemberCount_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V4(
    const pd_OpaqueCall_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V4(
    const pd_OptionAccountId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionClassId_V4(
    const pd_OptionClassId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionInstanceId_V4(
    const pd_OptionInstanceId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionLookupasStaticLookupSource_V4(
    const pd_OptionLookupasStaticLookupSource_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V4(
    const pd_OptionTimepoint_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V4(
    const pd_Perbill_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V4(
    const pd_Timepoint_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdBalanceOf_V4(
    const pd_TupleAccountIdBalanceOf_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V4(
    const pd_VecAccountId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecInstanceId_V4(
    const pd_VecInstanceId_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdBalanceOf_V4(
    const pd_VecTupleAccountIdBalanceOf_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V4(
    const pd_VestingScheduleOf_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V4(
    const pd_Weight_V4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
