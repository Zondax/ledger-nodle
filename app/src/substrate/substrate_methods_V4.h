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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V4 0
#define PD_CALL_TIMESTAMP_V4 1
#define PD_CALL_BALANCES_V4 2
#define PD_CALL_COMPANYRESERVE_V4 11
#define PD_CALL_INTERNATIONALRESERVE_V4 12
#define PD_CALL_USARESERVE_V4 13
#define PD_CALL_VESTING_V4 14
#define PD_CALL_MANDATE_V4 15
#define PD_CALL_TECHNICALCOMMITTEE_V4 16
#define PD_CALL_TECHNICALMEMBERSHIP_V4 17
#define PD_CALL_VALIDATORSSET_V4 21
#define PD_CALL_SESSION_V4 23
#define PD_CALL_UTILITY_V4 40
#define PD_CALL_MULTISIG_V4 41
#define PD_CALL_UNIQUES_V4 42
#define PD_CALL_PREIMAGE_V4 43
#define PD_CALL_ALLOCATIONS_V4 51
#define PD_CALL_ALLOCATIONSORACLES_V4 52

#define PD_CALL_BALANCES_TRANSFER_ALL_V4 4
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V4_t;

#define PD_CALL_SESSION_SET_KEYS_V4 0
typedef struct {
    pd_Keys_V4_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V4_t;

#define PD_CALL_SESSION_PURGE_KEYS_V4 1
typedef struct {
} pd_session_purge_keys_V4_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V4 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V4_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V4 5
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V4_t;

#define PD_CALL_COMPANYRESERVE_SPEND_V4 0
typedef struct {
    pd_AccountId_V4_t to;
    pd_BalanceOf_t amount;
} pd_companyreserve_spend_V4_t;

#define PD_CALL_COMPANYRESERVE_TIP_V4 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_companyreserve_tip_V4_t;

#define PD_CALL_COMPANYRESERVE_APPLY_AS_V4 2
typedef struct {
    pd_Call_t call;
} pd_companyreserve_apply_as_V4_t;

#define PD_CALL_INTERNATIONALRESERVE_SPEND_V4 0
typedef struct {
    pd_AccountId_V4_t to;
    pd_BalanceOf_t amount;
} pd_internationalreserve_spend_V4_t;

#define PD_CALL_INTERNATIONALRESERVE_TIP_V4 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_internationalreserve_tip_V4_t;

#define PD_CALL_INTERNATIONALRESERVE_APPLY_AS_V4 2
typedef struct {
    pd_Call_t call;
} pd_internationalreserve_apply_as_V4_t;

#define PD_CALL_USARESERVE_SPEND_V4 0
typedef struct {
    pd_AccountId_V4_t to;
    pd_BalanceOf_t amount;
} pd_usareserve_spend_V4_t;

#define PD_CALL_USARESERVE_TIP_V4 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_usareserve_tip_V4_t;

#define PD_CALL_USARESERVE_APPLY_AS_V4 2
typedef struct {
    pd_Call_t call;
} pd_usareserve_apply_as_V4_t;

#define PD_CALL_VESTING_CLAIM_V4 0
typedef struct {
} pd_vesting_claim_V4_t;

#define PD_CALL_VESTING_ADD_VESTING_SCHEDULE_V4 1
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_VestingScheduleOf_V4_t schedule;
} pd_vesting_add_vesting_schedule_V4_t;

#define PD_CALL_VESTING_CANCEL_ALL_VESTING_SCHEDULES_V4 2
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_LookupasStaticLookupSource_V4_t funds_collector;
} pd_vesting_cancel_all_vesting_schedules_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V4 0
typedef struct {
    pd_VecAccountId_V4_t new_members;
    pd_OptionAccountId_V4_t prime;
    pd_MemberCount_V4_t old_count;
} pd_technicalcommittee_set_members_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V4 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V4 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V4 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V4 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V4 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V4 0
typedef struct {
    pd_AccountId_V4_t who;
} pd_technicalmembership_add_member_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V4 1
typedef struct {
    pd_AccountId_V4_t who;
} pd_technicalmembership_remove_member_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V4 2
typedef struct {
    pd_AccountId_V4_t remove;
    pd_AccountId_V4_t add;
} pd_technicalmembership_swap_member_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V4 3
typedef struct {
    pd_VecAccountId_V4_t members;
} pd_technicalmembership_reset_members_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V4 4
typedef struct {
    pd_AccountId_V4_t new_;
} pd_technicalmembership_change_key_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V4 5
typedef struct {
    pd_AccountId_V4_t who;
} pd_technicalmembership_set_prime_V4_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V4 6
typedef struct {
} pd_technicalmembership_clear_prime_V4_t;

#define PD_CALL_VALIDATORSSET_ADD_MEMBER_V4 0
typedef struct {
    pd_AccountId_V4_t who;
} pd_validatorsset_add_member_V4_t;

#define PD_CALL_VALIDATORSSET_REMOVE_MEMBER_V4 1
typedef struct {
    pd_AccountId_V4_t who;
} pd_validatorsset_remove_member_V4_t;

#define PD_CALL_VALIDATORSSET_SWAP_MEMBER_V4 2
typedef struct {
    pd_AccountId_V4_t remove;
    pd_AccountId_V4_t add;
} pd_validatorsset_swap_member_V4_t;

#define PD_CALL_VALIDATORSSET_RESET_MEMBERS_V4 3
typedef struct {
    pd_VecAccountId_V4_t members;
} pd_validatorsset_reset_members_V4_t;

#define PD_CALL_VALIDATORSSET_CHANGE_KEY_V4 4
typedef struct {
    pd_AccountId_V4_t new_;
} pd_validatorsset_change_key_V4_t;

#define PD_CALL_VALIDATORSSET_SET_PRIME_V4 5
typedef struct {
    pd_AccountId_V4_t who;
} pd_validatorsset_set_prime_V4_t;

#define PD_CALL_VALIDATORSSET_CLEAR_PRIME_V4 6
typedef struct {
} pd_validatorsset_clear_prime_V4_t;

#define PD_CALL_UNIQUES_CREATE_V4 0
typedef struct {
    pd_ClassId_V4_t class_;
    pd_LookupasStaticLookupSource_V4_t admin;
} pd_uniques_create_V4_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V4 1
typedef struct {
    pd_ClassId_V4_t class_;
    pd_LookupasStaticLookupSource_V4_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V4_t;

#define PD_CALL_UNIQUES_DESTROY_V4 2
typedef struct {
    pd_ClassId_V4_t class_;
    pd_DestroyWitness_V4_t witness;
} pd_uniques_destroy_V4_t;

#define PD_CALL_UNIQUES_MINT_V4 3
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
    pd_LookupasStaticLookupSource_V4_t owner;
} pd_uniques_mint_V4_t;

#define PD_CALL_UNIQUES_BURN_V4 4
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
    pd_OptionLookupasStaticLookupSource_V4_t check_owner;
} pd_uniques_burn_V4_t;

#define PD_CALL_UNIQUES_TRANSFER_V4 5
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
    pd_LookupasStaticLookupSource_V4_t dest;
} pd_uniques_transfer_V4_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V4 6
typedef struct {
    pd_ClassId_V4_t class_;
    pd_VecInstanceId_V4_t instances;
} pd_uniques_redeposit_V4_t;

#define PD_CALL_UNIQUES_FREEZE_V4 7
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
} pd_uniques_freeze_V4_t;

#define PD_CALL_UNIQUES_THAW_V4 8
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
} pd_uniques_thaw_V4_t;

#define PD_CALL_UNIQUES_FREEZE_CLASS_V4 9
typedef struct {
    pd_ClassId_V4_t class_;
} pd_uniques_freeze_class_V4_t;

#define PD_CALL_UNIQUES_THAW_CLASS_V4 10
typedef struct {
    pd_ClassId_V4_t class_;
} pd_uniques_thaw_class_V4_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V4 11
typedef struct {
    pd_ClassId_V4_t class_;
    pd_LookupasStaticLookupSource_V4_t owner;
} pd_uniques_transfer_ownership_V4_t;

#define PD_CALL_UNIQUES_SET_TEAM_V4 12
typedef struct {
    pd_ClassId_V4_t class_;
    pd_LookupasStaticLookupSource_V4_t issuer;
    pd_LookupasStaticLookupSource_V4_t admin;
    pd_LookupasStaticLookupSource_V4_t freezer;
} pd_uniques_set_team_V4_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V4 13
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
    pd_LookupasStaticLookupSource_V4_t delegate;
} pd_uniques_approve_transfer_V4_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V4 14
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
    pd_OptionLookupasStaticLookupSource_V4_t maybe_check_delegate;
} pd_uniques_cancel_approval_V4_t;

#define PD_CALL_UNIQUES_FORCE_ASSET_STATUS_V4 15
typedef struct {
    pd_ClassId_V4_t class_;
    pd_LookupasStaticLookupSource_V4_t owner;
    pd_LookupasStaticLookupSource_V4_t issuer;
    pd_LookupasStaticLookupSource_V4_t admin;
    pd_LookupasStaticLookupSource_V4_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_asset_status_V4_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V4 16
typedef struct {
    pd_ClassId_V4_t class_;
    pd_OptionInstanceId_V4_t maybe_instance;
    pd_BoundedVecu8_V4_t key;
    pd_BoundedVecu8_V4_t value;
} pd_uniques_set_attribute_V4_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V4 17
typedef struct {
    pd_ClassId_V4_t class_;
    pd_OptionInstanceId_V4_t maybe_instance;
    pd_BoundedVecu8_V4_t key;
} pd_uniques_clear_attribute_V4_t;

#define PD_CALL_UNIQUES_SET_METADATA_V4 18
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
    pd_BoundedVecu8_V4_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V4_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V4 19
typedef struct {
    pd_ClassId_V4_t class_;
    pd_InstanceId_V4_t instance;
} pd_uniques_clear_metadata_V4_t;

#define PD_CALL_UNIQUES_SET_CLASS_METADATA_V4 20
typedef struct {
    pd_ClassId_V4_t class_;
    pd_BoundedVecu8_V4_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_class_metadata_V4_t;

#define PD_CALL_UNIQUES_CLEAR_CLASS_METADATA_V4 21
typedef struct {
    pd_ClassId_V4_t class_;
} pd_uniques_clear_class_metadata_V4_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V4 22
typedef struct {
    pd_OptionClassId_V4_t maybe_class;
} pd_uniques_set_accept_ownership_V4_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V4 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V4_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V4 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V4_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V4 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V4_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V4 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V4_t;

#define PD_CALL_ALLOCATIONS_BATCH_V4 0
typedef struct {
    pd_VecTupleAccountIdBalanceOf_V4_t batch;
} pd_allocations_batch_V4_t;

#define PD_CALL_ALLOCATIONS_ALLOCATE_V4 1
typedef struct {
    pd_AccountId_V4_t to;
    pd_Balance_t amount;
    pd_Vecu8_t proof;
} pd_allocations_allocate_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_ADD_MEMBER_V4 0
typedef struct {
    pd_AccountId_V4_t who;
} pd_allocationsoracles_add_member_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_REMOVE_MEMBER_V4 1
typedef struct {
    pd_AccountId_V4_t who;
} pd_allocationsoracles_remove_member_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_SWAP_MEMBER_V4 2
typedef struct {
    pd_AccountId_V4_t remove;
    pd_AccountId_V4_t add;
} pd_allocationsoracles_swap_member_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_RESET_MEMBERS_V4 3
typedef struct {
    pd_VecAccountId_V4_t members;
} pd_allocationsoracles_reset_members_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_CHANGE_KEY_V4 4
typedef struct {
    pd_AccountId_V4_t new_;
} pd_allocationsoracles_change_key_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_SET_PRIME_V4 5
typedef struct {
    pd_AccountId_V4_t who;
} pd_allocationsoracles_set_prime_V4_t;

#define PD_CALL_ALLOCATIONSORACLES_CLEAR_PRIME_V4 6
typedef struct {
} pd_allocationsoracles_clear_prime_V4_t;

#endif

typedef union {
    pd_balances_transfer_all_V4_t balances_transfer_all_V4;
    pd_session_set_keys_V4_t session_set_keys_V4;
    pd_session_purge_keys_V4_t session_purge_keys_V4;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V4_t timestamp_set_V4;
    pd_balances_force_unreserve_V4_t balances_force_unreserve_V4;
    pd_companyreserve_spend_V4_t companyreserve_spend_V4;
    pd_companyreserve_tip_V4_t companyreserve_tip_V4;
    pd_companyreserve_apply_as_V4_t companyreserve_apply_as_V4;
    pd_internationalreserve_spend_V4_t internationalreserve_spend_V4;
    pd_internationalreserve_tip_V4_t internationalreserve_tip_V4;
    pd_internationalreserve_apply_as_V4_t internationalreserve_apply_as_V4;
    pd_usareserve_spend_V4_t usareserve_spend_V4;
    pd_usareserve_tip_V4_t usareserve_tip_V4;
    pd_usareserve_apply_as_V4_t usareserve_apply_as_V4;
    pd_vesting_claim_V4_t vesting_claim_V4;
    pd_vesting_add_vesting_schedule_V4_t vesting_add_vesting_schedule_V4;
    pd_vesting_cancel_all_vesting_schedules_V4_t vesting_cancel_all_vesting_schedules_V4;
    pd_technicalcommittee_set_members_V4_t technicalcommittee_set_members_V4;
    pd_technicalcommittee_execute_V4_t technicalcommittee_execute_V4;
    pd_technicalcommittee_propose_V4_t technicalcommittee_propose_V4;
    pd_technicalcommittee_vote_V4_t technicalcommittee_vote_V4;
    pd_technicalcommittee_close_V4_t technicalcommittee_close_V4;
    pd_technicalcommittee_disapprove_proposal_V4_t technicalcommittee_disapprove_proposal_V4;
    pd_technicalmembership_add_member_V4_t technicalmembership_add_member_V4;
    pd_technicalmembership_remove_member_V4_t technicalmembership_remove_member_V4;
    pd_technicalmembership_swap_member_V4_t technicalmembership_swap_member_V4;
    pd_technicalmembership_reset_members_V4_t technicalmembership_reset_members_V4;
    pd_technicalmembership_change_key_V4_t technicalmembership_change_key_V4;
    pd_technicalmembership_set_prime_V4_t technicalmembership_set_prime_V4;
    pd_technicalmembership_clear_prime_V4_t technicalmembership_clear_prime_V4;
    pd_validatorsset_add_member_V4_t validatorsset_add_member_V4;
    pd_validatorsset_remove_member_V4_t validatorsset_remove_member_V4;
    pd_validatorsset_swap_member_V4_t validatorsset_swap_member_V4;
    pd_validatorsset_reset_members_V4_t validatorsset_reset_members_V4;
    pd_validatorsset_change_key_V4_t validatorsset_change_key_V4;
    pd_validatorsset_set_prime_V4_t validatorsset_set_prime_V4;
    pd_validatorsset_clear_prime_V4_t validatorsset_clear_prime_V4;
    pd_uniques_create_V4_t uniques_create_V4;
    pd_uniques_force_create_V4_t uniques_force_create_V4;
    pd_uniques_destroy_V4_t uniques_destroy_V4;
    pd_uniques_mint_V4_t uniques_mint_V4;
    pd_uniques_burn_V4_t uniques_burn_V4;
    pd_uniques_transfer_V4_t uniques_transfer_V4;
    pd_uniques_redeposit_V4_t uniques_redeposit_V4;
    pd_uniques_freeze_V4_t uniques_freeze_V4;
    pd_uniques_thaw_V4_t uniques_thaw_V4;
    pd_uniques_freeze_class_V4_t uniques_freeze_class_V4;
    pd_uniques_thaw_class_V4_t uniques_thaw_class_V4;
    pd_uniques_transfer_ownership_V4_t uniques_transfer_ownership_V4;
    pd_uniques_set_team_V4_t uniques_set_team_V4;
    pd_uniques_approve_transfer_V4_t uniques_approve_transfer_V4;
    pd_uniques_cancel_approval_V4_t uniques_cancel_approval_V4;
    pd_uniques_force_asset_status_V4_t uniques_force_asset_status_V4;
    pd_uniques_set_attribute_V4_t uniques_set_attribute_V4;
    pd_uniques_clear_attribute_V4_t uniques_clear_attribute_V4;
    pd_uniques_set_metadata_V4_t uniques_set_metadata_V4;
    pd_uniques_clear_metadata_V4_t uniques_clear_metadata_V4;
    pd_uniques_set_class_metadata_V4_t uniques_set_class_metadata_V4;
    pd_uniques_clear_class_metadata_V4_t uniques_clear_class_metadata_V4;
    pd_uniques_set_accept_ownership_V4_t uniques_set_accept_ownership_V4;
    pd_preimage_note_preimage_V4_t preimage_note_preimage_V4;
    pd_preimage_unnote_preimage_V4_t preimage_unnote_preimage_V4;
    pd_preimage_request_preimage_V4_t preimage_request_preimage_V4;
    pd_preimage_unrequest_preimage_V4_t preimage_unrequest_preimage_V4;
    pd_allocations_batch_V4_t allocations_batch_V4;
    pd_allocations_allocate_V4_t allocations_allocate_V4;
    pd_allocationsoracles_add_member_V4_t allocationsoracles_add_member_V4;
    pd_allocationsoracles_remove_member_V4_t allocationsoracles_remove_member_V4;
    pd_allocationsoracles_swap_member_V4_t allocationsoracles_swap_member_V4;
    pd_allocationsoracles_reset_members_V4_t allocationsoracles_reset_members_V4;
    pd_allocationsoracles_change_key_V4_t allocationsoracles_change_key_V4;
    pd_allocationsoracles_set_prime_V4_t allocationsoracles_set_prime_V4;
    pd_allocationsoracles_clear_prime_V4_t allocationsoracles_clear_prime_V4;
#endif
} pd_MethodBasic_V4_t;

#define PD_CALL_BALANCES_TRANSFER_V4 0
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V4_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V4 2
typedef struct {
    pd_LookupasStaticLookupSource_V4_t source;
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V4_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V4 3
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V4_t;

#define PD_CALL_UTILITY_BATCH_V4 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V4_t;

#define PD_CALL_UTILITY_BATCH_ALL_V4 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V4 0
typedef struct {
    pd_Perbill_V4_t ratio;
} pd_system_fill_block_V4_t;

#define PD_CALL_SYSTEM_REMARK_V4 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V4_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V4 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_V4 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V4 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V4_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V4 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V4_t;

#define PD_CALL_BALANCES_SET_BALANCE_V4 1
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V4_t;

#define PD_CALL_MANDATE_APPLY_V4 0
typedef struct {
    pd_Call_t call;
} pd_mandate_apply_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V4 0
typedef struct {
    pd_VecAccountId_V4_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_V4 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_OpaqueCall_V4_t call;
    pd_bool_t store_call;
    pd_Weight_V4_t max_weight;
} pd_multisig_as_multi_V4_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V4 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V4_t max_weight;
} pd_multisig_approve_as_multi_V4_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V4 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_Timepoint_V4_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V4_t;

#endif

typedef union {
    pd_balances_transfer_V4_t balances_transfer_V4;
    pd_balances_force_transfer_V4_t balances_force_transfer_V4;
    pd_balances_transfer_keep_alive_V4_t balances_transfer_keep_alive_V4;
    pd_utility_batch_V4_t utility_batch_V4;
    pd_utility_batch_all_V4_t utility_batch_all_V4;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V4_t system_fill_block_V4;
    pd_system_remark_V4_t system_remark_V4;
    pd_system_set_heap_pages_V4_t system_set_heap_pages_V4;
    pd_system_set_code_V4_t system_set_code_V4;
    pd_system_set_code_without_checks_V4_t system_set_code_without_checks_V4;
    pd_system_remark_with_event_V4_t system_remark_with_event_V4;
    pd_balances_set_balance_V4_t balances_set_balance_V4;
    pd_mandate_apply_V4_t mandate_apply_V4;
    pd_multisig_as_multi_threshold_1_V4_t multisig_as_multi_threshold_1_V4;
    pd_multisig_as_multi_V4_t multisig_as_multi_V4;
    pd_multisig_approve_as_multi_V4_t multisig_approve_as_multi_V4;
    pd_multisig_cancel_as_multi_V4_t multisig_cancel_as_multi_V4;
#endif
} pd_MethodNested_V4_t;

typedef union {
    pd_MethodBasic_V4_t basic;
    pd_MethodNested_V4_t nested;
} pd_Method_V4_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
