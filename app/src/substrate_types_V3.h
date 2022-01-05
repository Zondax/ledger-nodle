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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V3_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V3_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V3_t;

typedef struct {
    uint64_t value;
} pd_Period_V3_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V3_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V3_t;

typedef struct {
    pd_BlockNumber_t start;
    pd_BlockNumber_t period;
    uint32_t period_count;
    pd_Balance_t balance;
} pd_VestingScheduleOf_V3_t;

typedef struct {
    pd_Call_t call;
} pd_Amendment_V3_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V3_t id;
        pd_CompactAccountIndex_V3_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupSource_V3_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V3_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V3_t contained;
} pd_OptionChangesTrieConfiguration_V3_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V3_t contained;
} pd_OptionTimepoint_V3_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V3_t dependency;
} pd_Priority_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVestingScheduleOf_V3_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BabeEquivocationProof_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CertificateId_V3_t;

typedef compactInt_t pd_CompactMemberCount_V3_t;

typedef compactInt_t pd_CompactMoment_V3_t;

typedef compactInt_t pd_CompactProposalIndex_V3_t;

typedef compactInt_t pd_CompactWeight_V3_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_GrandpaEquivocationProof_V3_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V3_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V3_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V3_t contained;
} pd_OptionAccountId_V3_t;

typedef struct {
    uint8_t some;
    pd_Period_V3_t contained;
} pd_OptionPeriod_V3_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V3_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Schedule_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V3_t;

typedef struct {
    uint64_t value;
} pd_Weight_V3_t;

#ifdef __cplusplus
}
#endif
