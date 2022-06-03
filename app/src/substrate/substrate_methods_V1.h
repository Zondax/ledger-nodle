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
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_TIMESTAMP_V1 1
#define PD_CALL_BALANCES_V1 2
#define PD_CALL_COMPANYRESERVE_V1 11
#define PD_CALL_INTERNATIONALRESERVE_V1 12
#define PD_CALL_USARESERVE_V1 13
#define PD_CALL_VESTING_V1 14
#define PD_CALL_MANDATE_V1 15
#define PD_CALL_TECHNICALCOMMITTEE_V1 16
#define PD_CALL_TECHNICALMEMBERSHIP_V1 17
#define PD_CALL_VALIDATORSSET_V1 21
#define PD_CALL_SESSION_V1 23
#define PD_CALL_UTILITY_V1 40
#define PD_CALL_MULTISIG_V1 41
#define PD_CALL_UNIQUES_V1 42
#define PD_CALL_PREIMAGE_V1 43
#define PD_CALL_EMERGENCYSHUTDOWN_V1 50
#define PD_CALL_ALLOCATIONS_V1 51
#define PD_CALL_ALLOCATIONSORACLES_V1 52

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_COMPANYRESERVE_SPEND_V1 0
typedef struct {
    pd_AccountId_V1_t to;
    pd_BalanceOf_t amount;
} pd_companyreserve_spend_V1_t;

#define PD_CALL_COMPANYRESERVE_TIP_V1 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_companyreserve_tip_V1_t;

#define PD_CALL_COMPANYRESERVE_APPLY_AS_V1 2
typedef struct {
    pd_Call_t call;
} pd_companyreserve_apply_as_V1_t;

#define PD_CALL_INTERNATIONALRESERVE_SPEND_V1 0
typedef struct {
    pd_AccountId_V1_t to;
    pd_BalanceOf_t amount;
} pd_internationalreserve_spend_V1_t;

#define PD_CALL_INTERNATIONALRESERVE_TIP_V1 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_internationalreserve_tip_V1_t;

#define PD_CALL_INTERNATIONALRESERVE_APPLY_AS_V1 2
typedef struct {
    pd_Call_t call;
} pd_internationalreserve_apply_as_V1_t;

#define PD_CALL_USARESERVE_SPEND_V1 0
typedef struct {
    pd_AccountId_V1_t to;
    pd_BalanceOf_t amount;
} pd_usareserve_spend_V1_t;

#define PD_CALL_USARESERVE_TIP_V1 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_usareserve_tip_V1_t;

#define PD_CALL_USARESERVE_APPLY_AS_V1 2
typedef struct {
    pd_Call_t call;
} pd_usareserve_apply_as_V1_t;

#define PD_CALL_VESTING_CLAIM_V1 0
typedef struct {
} pd_vesting_claim_V1_t;

#define PD_CALL_VESTING_ADD_VESTING_SCHEDULE_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_VestingScheduleOf_V1_t schedule;
} pd_vesting_add_vesting_schedule_V1_t;

#define PD_CALL_VESTING_CANCEL_ALL_VESTING_SCHEDULES_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_LookupasStaticLookupSource_V1_t funds_collector;
    pd_bool_t limit_to_free_balance;
} pd_vesting_cancel_all_vesting_schedules_V1_t;

#define PD_CALL_VESTING_OVERWRITE_VESTING_SCHEDULES_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_VecVestingScheduleOf_V1_t new_schedules;
} pd_vesting_overwrite_vesting_schedules_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_members;
    pd_OptionAccountId_V1_t prime;
    pd_MemberCount_V1_t old_count;
} pd_technicalcommittee_set_members_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V1 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_add_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_remove_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountId_V1_t remove;
    pd_AccountId_V1_t add;
} pd_technicalmembership_swap_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_technicalmembership_reset_members_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t new_;
} pd_technicalmembership_change_key_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V1 5
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_set_prime_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V1 6
typedef struct {
} pd_technicalmembership_clear_prime_V1_t;

#define PD_CALL_VALIDATORSSET_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_validatorsset_add_member_V1_t;

#define PD_CALL_VALIDATORSSET_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_validatorsset_remove_member_V1_t;

#define PD_CALL_VALIDATORSSET_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountId_V1_t remove;
    pd_AccountId_V1_t add;
} pd_validatorsset_swap_member_V1_t;

#define PD_CALL_VALIDATORSSET_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_validatorsset_reset_members_V1_t;

#define PD_CALL_VALIDATORSSET_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t new_;
} pd_validatorsset_change_key_V1_t;

#define PD_CALL_VALIDATORSSET_SET_PRIME_V1 5
typedef struct {
    pd_AccountId_V1_t who;
} pd_validatorsset_set_prime_V1_t;

#define PD_CALL_VALIDATORSSET_CLEAR_PRIME_V1 6
typedef struct {
} pd_validatorsset_clear_prime_V1_t;

#define PD_CALL_UNIQUES_CREATE_V1 0
typedef struct {
    pd_ClassId_V1_t class_;
    pd_LookupasStaticLookupSource_V1_t admin;
} pd_uniques_create_V1_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V1 1
typedef struct {
    pd_ClassId_V1_t class_;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V1_t;

#define PD_CALL_UNIQUES_DESTROY_V1 2
typedef struct {
    pd_ClassId_V1_t class_;
    pd_DestroyWitness_V1_t witness;
} pd_uniques_destroy_V1_t;

#define PD_CALL_UNIQUES_MINT_V1 3
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
    pd_LookupasStaticLookupSource_V1_t owner;
} pd_uniques_mint_V1_t;

#define PD_CALL_UNIQUES_BURN_V1 4
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
    pd_OptionLookupasStaticLookupSource_V1_t check_owner;
} pd_uniques_burn_V1_t;

#define PD_CALL_UNIQUES_TRANSFER_V1 5
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
    pd_LookupasStaticLookupSource_V1_t dest;
} pd_uniques_transfer_V1_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V1 6
typedef struct {
    pd_ClassId_V1_t class_;
    pd_VecInstanceId_V1_t instances;
} pd_uniques_redeposit_V1_t;

#define PD_CALL_UNIQUES_FREEZE_V1 7
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
} pd_uniques_freeze_V1_t;

#define PD_CALL_UNIQUES_THAW_V1 8
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
} pd_uniques_thaw_V1_t;

#define PD_CALL_UNIQUES_FREEZE_CLASS_V1 9
typedef struct {
    pd_ClassId_V1_t class_;
} pd_uniques_freeze_class_V1_t;

#define PD_CALL_UNIQUES_THAW_CLASS_V1 10
typedef struct {
    pd_ClassId_V1_t class_;
} pd_uniques_thaw_class_V1_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V1 11
typedef struct {
    pd_ClassId_V1_t class_;
    pd_LookupasStaticLookupSource_V1_t owner;
} pd_uniques_transfer_ownership_V1_t;

#define PD_CALL_UNIQUES_SET_TEAM_V1 12
typedef struct {
    pd_ClassId_V1_t class_;
    pd_LookupasStaticLookupSource_V1_t issuer;
    pd_LookupasStaticLookupSource_V1_t admin;
    pd_LookupasStaticLookupSource_V1_t freezer;
} pd_uniques_set_team_V1_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V1 13
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
    pd_LookupasStaticLookupSource_V1_t delegate;
} pd_uniques_approve_transfer_V1_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V1 14
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
    pd_OptionLookupasStaticLookupSource_V1_t maybe_check_delegate;
} pd_uniques_cancel_approval_V1_t;

#define PD_CALL_UNIQUES_FORCE_ASSET_STATUS_V1 15
typedef struct {
    pd_ClassId_V1_t class_;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_LookupasStaticLookupSource_V1_t issuer;
    pd_LookupasStaticLookupSource_V1_t admin;
    pd_LookupasStaticLookupSource_V1_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_asset_status_V1_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V1 16
typedef struct {
    pd_ClassId_V1_t class_;
    pd_OptionInstanceId_V1_t maybe_instance;
    pd_BoundedVecu8_V1_t key;
    pd_BoundedVecu8_V1_t value;
} pd_uniques_set_attribute_V1_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V1 17
typedef struct {
    pd_ClassId_V1_t class_;
    pd_OptionInstanceId_V1_t maybe_instance;
    pd_BoundedVecu8_V1_t key;
} pd_uniques_clear_attribute_V1_t;

#define PD_CALL_UNIQUES_SET_METADATA_V1 18
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
    pd_BoundedVecu8_V1_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V1_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V1 19
typedef struct {
    pd_ClassId_V1_t class_;
    pd_InstanceId_V1_t instance;
} pd_uniques_clear_metadata_V1_t;

#define PD_CALL_UNIQUES_SET_CLASS_METADATA_V1 20
typedef struct {
    pd_ClassId_V1_t class_;
    pd_BoundedVecu8_V1_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_class_metadata_V1_t;

#define PD_CALL_UNIQUES_CLEAR_CLASS_METADATA_V1 21
typedef struct {
    pd_ClassId_V1_t class_;
} pd_uniques_clear_class_metadata_V1_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V1 22
typedef struct {
    pd_OptionClassId_V1_t maybe_class;
} pd_uniques_set_accept_ownership_V1_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V1 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V1_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V1 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V1_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V1 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V1_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V1 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V1_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_V1 0
typedef struct {
} pd_emergencyshutdown_toggle_V1_t;

#define PD_CALL_ALLOCATIONS_ALLOCATE_V1 0
typedef struct {
    pd_AccountId_V1_t to;
    pd_Balance_t amount;
    pd_Vecu8_t proof;
} pd_allocations_allocate_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_allocationsoracles_add_member_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_allocationsoracles_remove_member_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountId_V1_t remove;
    pd_AccountId_V1_t add;
} pd_allocationsoracles_swap_member_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_allocationsoracles_reset_members_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t new_;
} pd_allocationsoracles_change_key_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_SET_PRIME_V1 5
typedef struct {
    pd_AccountId_V1_t who;
} pd_allocationsoracles_set_prime_V1_t;

#define PD_CALL_ALLOCATIONSORACLES_CLEAR_PRIME_V1 6
typedef struct {
} pd_allocationsoracles_clear_prime_V1_t;

#endif

typedef union {
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_companyreserve_spend_V1_t companyreserve_spend_V1;
    pd_companyreserve_tip_V1_t companyreserve_tip_V1;
    pd_companyreserve_apply_as_V1_t companyreserve_apply_as_V1;
    pd_internationalreserve_spend_V1_t internationalreserve_spend_V1;
    pd_internationalreserve_tip_V1_t internationalreserve_tip_V1;
    pd_internationalreserve_apply_as_V1_t internationalreserve_apply_as_V1;
    pd_usareserve_spend_V1_t usareserve_spend_V1;
    pd_usareserve_tip_V1_t usareserve_tip_V1;
    pd_usareserve_apply_as_V1_t usareserve_apply_as_V1;
    pd_vesting_claim_V1_t vesting_claim_V1;
    pd_vesting_add_vesting_schedule_V1_t vesting_add_vesting_schedule_V1;
    pd_vesting_cancel_all_vesting_schedules_V1_t vesting_cancel_all_vesting_schedules_V1;
    pd_vesting_overwrite_vesting_schedules_V1_t vesting_overwrite_vesting_schedules_V1;
    pd_technicalcommittee_set_members_V1_t technicalcommittee_set_members_V1;
    pd_technicalcommittee_execute_V1_t technicalcommittee_execute_V1;
    pd_technicalcommittee_propose_V1_t technicalcommittee_propose_V1;
    pd_technicalcommittee_vote_V1_t technicalcommittee_vote_V1;
    pd_technicalcommittee_close_V1_t technicalcommittee_close_V1;
    pd_technicalcommittee_disapprove_proposal_V1_t technicalcommittee_disapprove_proposal_V1;
    pd_technicalmembership_add_member_V1_t technicalmembership_add_member_V1;
    pd_technicalmembership_remove_member_V1_t technicalmembership_remove_member_V1;
    pd_technicalmembership_swap_member_V1_t technicalmembership_swap_member_V1;
    pd_technicalmembership_reset_members_V1_t technicalmembership_reset_members_V1;
    pd_technicalmembership_change_key_V1_t technicalmembership_change_key_V1;
    pd_technicalmembership_set_prime_V1_t technicalmembership_set_prime_V1;
    pd_technicalmembership_clear_prime_V1_t technicalmembership_clear_prime_V1;
    pd_validatorsset_add_member_V1_t validatorsset_add_member_V1;
    pd_validatorsset_remove_member_V1_t validatorsset_remove_member_V1;
    pd_validatorsset_swap_member_V1_t validatorsset_swap_member_V1;
    pd_validatorsset_reset_members_V1_t validatorsset_reset_members_V1;
    pd_validatorsset_change_key_V1_t validatorsset_change_key_V1;
    pd_validatorsset_set_prime_V1_t validatorsset_set_prime_V1;
    pd_validatorsset_clear_prime_V1_t validatorsset_clear_prime_V1;
    pd_uniques_create_V1_t uniques_create_V1;
    pd_uniques_force_create_V1_t uniques_force_create_V1;
    pd_uniques_destroy_V1_t uniques_destroy_V1;
    pd_uniques_mint_V1_t uniques_mint_V1;
    pd_uniques_burn_V1_t uniques_burn_V1;
    pd_uniques_transfer_V1_t uniques_transfer_V1;
    pd_uniques_redeposit_V1_t uniques_redeposit_V1;
    pd_uniques_freeze_V1_t uniques_freeze_V1;
    pd_uniques_thaw_V1_t uniques_thaw_V1;
    pd_uniques_freeze_class_V1_t uniques_freeze_class_V1;
    pd_uniques_thaw_class_V1_t uniques_thaw_class_V1;
    pd_uniques_transfer_ownership_V1_t uniques_transfer_ownership_V1;
    pd_uniques_set_team_V1_t uniques_set_team_V1;
    pd_uniques_approve_transfer_V1_t uniques_approve_transfer_V1;
    pd_uniques_cancel_approval_V1_t uniques_cancel_approval_V1;
    pd_uniques_force_asset_status_V1_t uniques_force_asset_status_V1;
    pd_uniques_set_attribute_V1_t uniques_set_attribute_V1;
    pd_uniques_clear_attribute_V1_t uniques_clear_attribute_V1;
    pd_uniques_set_metadata_V1_t uniques_set_metadata_V1;
    pd_uniques_clear_metadata_V1_t uniques_clear_metadata_V1;
    pd_uniques_set_class_metadata_V1_t uniques_set_class_metadata_V1;
    pd_uniques_clear_class_metadata_V1_t uniques_clear_class_metadata_V1;
    pd_uniques_set_accept_ownership_V1_t uniques_set_accept_ownership_V1;
    pd_preimage_note_preimage_V1_t preimage_note_preimage_V1;
    pd_preimage_unnote_preimage_V1_t preimage_unnote_preimage_V1;
    pd_preimage_request_preimage_V1_t preimage_request_preimage_V1;
    pd_preimage_unrequest_preimage_V1_t preimage_unrequest_preimage_V1;
    pd_emergencyshutdown_toggle_V1_t emergencyshutdown_toggle_V1;
    pd_allocations_allocate_V1_t allocations_allocate_V1;
    pd_allocationsoracles_add_member_V1_t allocationsoracles_add_member_V1;
    pd_allocationsoracles_remove_member_V1_t allocationsoracles_remove_member_V1;
    pd_allocationsoracles_swap_member_V1_t allocationsoracles_swap_member_V1;
    pd_allocationsoracles_reset_members_V1_t allocationsoracles_reset_members_V1;
    pd_allocationsoracles_change_key_V1_t allocationsoracles_change_key_V1;
    pd_allocationsoracles_set_prime_V1_t allocationsoracles_set_prime_V1;
    pd_allocationsoracles_clear_prime_V1_t allocationsoracles_clear_prime_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_MANDATE_APPLY_V1 0
typedef struct {
    pd_Call_t call;
} pd_mandate_apply_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_mandate_apply_V1_t mandate_apply_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
