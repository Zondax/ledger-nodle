/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#include "substrate_methods_V5.h"
#include "substrate_types_V5.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountIdLookupOfT_V5(parser_context_t* c, pd_AccountIdLookupOfT_V5_t* v);
parser_error_t _readAccountId_V5(parser_context_t* c, pd_AccountId_V5_t* v);
parser_error_t _readBoundedVecu8_V5(parser_context_t* c, pd_BoundedVecu8_V5_t* v);
parser_error_t _readCodeHash_V5(parser_context_t* c, pd_CodeHash_V5_t* v);
parser_error_t _readCollectionId_V5(parser_context_t* c, pd_CollectionId_V5_t* v);
parser_error_t _readCompactAccountIndex_V5(parser_context_t* c, pd_CompactAccountIndex_V5_t* v);
parser_error_t _readDestroyWitness_V5(parser_context_t* c, pd_DestroyWitness_V5_t* v);
parser_error_t _readItemId_V5(parser_context_t* c, pd_ItemId_V5_t* v);
parser_error_t _readItemPrice_V5(parser_context_t* c, pd_ItemPrice_V5_t* v);
parser_error_t _readKeys_V5(parser_context_t* c, pd_Keys_V5_t* v);
parser_error_t _readLookupasStaticLookupSource_V5(parser_context_t* c, pd_LookupasStaticLookupSource_V5_t* v);
parser_error_t _readMemberCount_V5(parser_context_t* c, pd_MemberCount_V5_t* v);
parser_error_t _readOpaqueCall_V5(parser_context_t* c, pd_OpaqueCall_V5_t* v);
parser_error_t _readOptionAccountIdLookupOfT_V5(parser_context_t* c, pd_OptionAccountIdLookupOfT_V5_t* v);
parser_error_t _readOptionAccountId_V5(parser_context_t* c, pd_OptionAccountId_V5_t* v);
parser_error_t _readOptionCollectionId_V5(parser_context_t* c, pd_OptionCollectionId_V5_t* v);
parser_error_t _readOptionItemId_V5(parser_context_t* c, pd_OptionItemId_V5_t* v);
parser_error_t _readOptionItemPrice_V5(parser_context_t* c, pd_OptionItemPrice_V5_t* v);
parser_error_t _readOptionTimepoint_V5(parser_context_t* c, pd_OptionTimepoint_V5_t* v);
parser_error_t _readOverweightIndex_V5(parser_context_t* c, pd_OverweightIndex_V5_t* v);
parser_error_t _readPerbill_V5(parser_context_t* c, pd_Perbill_V5_t* v);
parser_error_t _readTimepoint_V5(parser_context_t* c, pd_Timepoint_V5_t* v);
parser_error_t _readTupleAccountIdBalanceOf_V5(parser_context_t* c, pd_TupleAccountIdBalanceOf_V5_t* v);
parser_error_t _readVecAccountId_V5(parser_context_t* c, pd_VecAccountId_V5_t* v);
parser_error_t _readVecItemId_V5(parser_context_t* c, pd_VecItemId_V5_t* v);
parser_error_t _readVecTupleAccountIdBalanceOf_V5(parser_context_t* c, pd_VecTupleAccountIdBalanceOf_V5_t* v);
parser_error_t _readVestingScheduleOf_V5(parser_context_t* c, pd_VestingScheduleOf_V5_t* v);
parser_error_t _readWeight_V5(parser_context_t* c, pd_Weight_V5_t* v);

// toString functions
parser_error_t _toStringAccountIdLookupOfT_V5(
    const pd_AccountIdLookupOfT_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V5(
    const pd_AccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V5(
    const pd_BoundedVecu8_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V5(
    const pd_CodeHash_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCollectionId_V5(
    const pd_CollectionId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V5(
    const pd_CompactAccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V5(
    const pd_DestroyWitness_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemId_V5(
    const pd_ItemId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemPrice_V5(
    const pd_ItemPrice_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V5(
    const pd_Keys_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V5(
    const pd_LookupasStaticLookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V5(
    const pd_MemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V5(
    const pd_OpaqueCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountIdLookupOfT_V5(
    const pd_OptionAccountIdLookupOfT_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V5(
    const pd_OptionAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCollectionId_V5(
    const pd_OptionCollectionId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemId_V5(
    const pd_OptionItemId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemPrice_V5(
    const pd_OptionItemPrice_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V5(
    const pd_OptionTimepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V5(
    const pd_OverweightIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V5(
    const pd_Perbill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V5(
    const pd_Timepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdBalanceOf_V5(
    const pd_TupleAccountIdBalanceOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V5(
    const pd_VecAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecItemId_V5(
    const pd_VecItemId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdBalanceOf_V5(
    const pd_VecTupleAccountIdBalanceOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingScheduleOf_V5(
    const pd_VestingScheduleOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V5(
    const pd_Weight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
