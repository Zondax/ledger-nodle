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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V5.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V5 0
#define PD_CALL_TIMESTAMP_V5 1
#define PD_CALL_BALANCES_V5 2
#define PD_CALL_COMPANYRESERVE_V5 11
#define PD_CALL_INTERNATIONALRESERVE_V5 12
#define PD_CALL_USARESERVE_V5 13
#define PD_CALL_VESTING_V5 14
#define PD_CALL_MANDATE_V5 15
#define PD_CALL_TECHNICALCOMMITTEE_V5 16
#define PD_CALL_TECHNICALMEMBERSHIP_V5 17
#define PD_CALL_VALIDATORSSET_V5 21
#define PD_CALL_SESSION_V5 23
#define PD_CALL_DMPQUEUE_V5 33
#define PD_CALL_UTILITY_V5 40
#define PD_CALL_MULTISIG_V5 41
#define PD_CALL_UNIQUES_V5 42
#define PD_CALL_PREIMAGE_V5 43
#define PD_CALL_ALLOCATIONS_V5 51
#define PD_CALL_ALLOCATIONSORACLES_V5 52
#define PD_CALL_DAORESERVE_V5 60

#define PD_CALL_BALANCES_TRANSFER_ALL_V5 4
typedef struct {
    pd_LookupasStaticLookupSource_V5_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V5_t;

#define PD_CALL_SESSION_SET_KEYS_V5 0
typedef struct {
    pd_Keys_V5_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V5_t;

#define PD_CALL_SESSION_PURGE_KEYS_V5 1
typedef struct {
} pd_session_purge_keys_V5_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V5 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V5_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V5 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V5_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V5 5
typedef struct {
    pd_LookupasStaticLookupSource_V5_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V5_t;

#define PD_CALL_COMPANYRESERVE_SPEND_V5 0
typedef struct {
    pd_AccountId_V5_t to;
    pd_BalanceOf_t amount;
} pd_companyreserve_spend_V5_t;

#define PD_CALL_COMPANYRESERVE_TIP_V5 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_companyreserve_tip_V5_t;

#define PD_CALL_COMPANYRESERVE_APPLY_AS_V5 2
typedef struct {
    pd_Call_t call;
} pd_companyreserve_apply_as_V5_t;

#define PD_CALL_INTERNATIONALRESERVE_SPEND_V5 0
typedef struct {
    pd_AccountId_V5_t to;
    pd_BalanceOf_t amount;
} pd_internationalreserve_spend_V5_t;

#define PD_CALL_INTERNATIONALRESERVE_TIP_V5 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_internationalreserve_tip_V5_t;

#define PD_CALL_INTERNATIONALRESERVE_APPLY_AS_V5 2
typedef struct {
    pd_Call_t call;
} pd_internationalreserve_apply_as_V5_t;

#define PD_CALL_USARESERVE_SPEND_V5 0
typedef struct {
    pd_AccountId_V5_t to;
    pd_BalanceOf_t amount;
} pd_usareserve_spend_V5_t;

#define PD_CALL_USARESERVE_TIP_V5 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_usareserve_tip_V5_t;

#define PD_CALL_USARESERVE_APPLY_AS_V5 2
typedef struct {
    pd_Call_t call;
} pd_usareserve_apply_as_V5_t;

#define PD_CALL_VESTING_CLAIM_V5 0
typedef struct {
} pd_vesting_claim_V5_t;

#define PD_CALL_VESTING_ADD_VESTING_SCHEDULE_V5 1
typedef struct {
    pd_LookupasStaticLookupSource_V5_t dest;
    pd_VestingScheduleOf_V5_t schedule;
} pd_vesting_add_vesting_schedule_V5_t;

#define PD_CALL_VESTING_CANCEL_ALL_VESTING_SCHEDULES_V5 2
typedef struct {
    pd_LookupasStaticLookupSource_V5_t who;
    pd_LookupasStaticLookupSource_V5_t funds_collector;
} pd_vesting_cancel_all_vesting_schedules_V5_t;

#define PD_CALL_VESTING_RENOUNCE_V5 3
typedef struct {
    pd_LookupasStaticLookupSource_V5_t who;
} pd_vesting_renounce_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V5 0
typedef struct {
    pd_VecAccountId_V5_t new_members;
    pd_OptionAccountId_V5_t prime;
    pd_MemberCount_V5_t old_count;
} pd_technicalcommittee_set_members_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V5 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V5 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V5 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V5 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V5_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V5 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V5 0
typedef struct {
    pd_AccountId_V5_t who;
} pd_technicalmembership_add_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V5 1
typedef struct {
    pd_AccountId_V5_t who;
} pd_technicalmembership_remove_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V5 2
typedef struct {
    pd_AccountId_V5_t remove;
    pd_AccountId_V5_t add;
} pd_technicalmembership_swap_member_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V5 3
typedef struct {
    pd_VecAccountId_V5_t members;
} pd_technicalmembership_reset_members_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V5 4
typedef struct {
    pd_AccountId_V5_t new_;
} pd_technicalmembership_change_key_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V5 5
typedef struct {
    pd_AccountId_V5_t who;
} pd_technicalmembership_set_prime_V5_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V5 6
typedef struct {
} pd_technicalmembership_clear_prime_V5_t;

#define PD_CALL_VALIDATORSSET_ADD_MEMBER_V5 0
typedef struct {
    pd_AccountId_V5_t who;
} pd_validatorsset_add_member_V5_t;

#define PD_CALL_VALIDATORSSET_REMOVE_MEMBER_V5 1
typedef struct {
    pd_AccountId_V5_t who;
} pd_validatorsset_remove_member_V5_t;

#define PD_CALL_VALIDATORSSET_SWAP_MEMBER_V5 2
typedef struct {
    pd_AccountId_V5_t remove;
    pd_AccountId_V5_t add;
} pd_validatorsset_swap_member_V5_t;

#define PD_CALL_VALIDATORSSET_RESET_MEMBERS_V5 3
typedef struct {
    pd_VecAccountId_V5_t members;
} pd_validatorsset_reset_members_V5_t;

#define PD_CALL_VALIDATORSSET_CHANGE_KEY_V5 4
typedef struct {
    pd_AccountId_V5_t new_;
} pd_validatorsset_change_key_V5_t;

#define PD_CALL_VALIDATORSSET_SET_PRIME_V5 5
typedef struct {
    pd_AccountId_V5_t who;
} pd_validatorsset_set_prime_V5_t;

#define PD_CALL_VALIDATORSSET_CLEAR_PRIME_V5 6
typedef struct {
} pd_validatorsset_clear_prime_V5_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V5 0
typedef struct {
    pd_OverweightIndex_V5_t index;
    pd_Weight_V5_t weight_limit;
} pd_dmpqueue_service_overweight_V5_t;

#define PD_CALL_UNIQUES_CREATE_V5 0
typedef struct {
    pd_LookupasStaticLookupSource_V5_t admin;
} pd_uniques_create_V5_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V5 1
typedef struct {
    pd_LookupasStaticLookupSource_V5_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V5_t;

#define PD_CALL_UNIQUES_TRY_INCREMENT_ID_V5 2
typedef struct {
} pd_uniques_try_increment_id_V5_t;

#define PD_CALL_UNIQUES_DESTROY_V5 3
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_DestroyWitness_V5_t witness;
} pd_uniques_destroy_V5_t;

#define PD_CALL_UNIQUES_MINT_V5 4
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_LookupasStaticLookupSource_V5_t owner;
} pd_uniques_mint_V5_t;

#define PD_CALL_UNIQUES_BURN_V5 5
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_OptionLookupasStaticLookupSource_V5_t check_owner;
} pd_uniques_burn_V5_t;

#define PD_CALL_UNIQUES_TRANSFER_V5 6
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_LookupasStaticLookupSource_V5_t dest;
} pd_uniques_transfer_V5_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V5 7
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_VecItemId_V5_t items;
} pd_uniques_redeposit_V5_t;

#define PD_CALL_UNIQUES_FREEZE_V5 8
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
} pd_uniques_freeze_V5_t;

#define PD_CALL_UNIQUES_THAW_V5 9
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
} pd_uniques_thaw_V5_t;

#define PD_CALL_UNIQUES_FREEZE_COLLECTION_V5 10
typedef struct {
    pd_CollectionId_V5_t collection;
} pd_uniques_freeze_collection_V5_t;

#define PD_CALL_UNIQUES_THAW_COLLECTION_V5 11
typedef struct {
    pd_CollectionId_V5_t collection;
} pd_uniques_thaw_collection_V5_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V5 12
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_LookupasStaticLookupSource_V5_t owner;
} pd_uniques_transfer_ownership_V5_t;

#define PD_CALL_UNIQUES_SET_TEAM_V5 13
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_LookupasStaticLookupSource_V5_t issuer;
    pd_LookupasStaticLookupSource_V5_t admin;
    pd_LookupasStaticLookupSource_V5_t freezer;
} pd_uniques_set_team_V5_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V5 14
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_LookupasStaticLookupSource_V5_t delegate;
} pd_uniques_approve_transfer_V5_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V5 15
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_OptionLookupasStaticLookupSource_V5_t maybe_check_delegate;
} pd_uniques_cancel_approval_V5_t;

#define PD_CALL_UNIQUES_FORCE_ITEM_STATUS_V5 16
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_LookupasStaticLookupSource_V5_t owner;
    pd_LookupasStaticLookupSource_V5_t issuer;
    pd_LookupasStaticLookupSource_V5_t admin;
    pd_LookupasStaticLookupSource_V5_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_item_status_V5_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V5 17
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_OptionItemId_V5_t maybe_item;
    pd_BoundedVecu8_V5_t key;
    pd_BoundedVecu8_V5_t value;
} pd_uniques_set_attribute_V5_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V5 18
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_OptionItemId_V5_t maybe_item;
    pd_BoundedVecu8_V5_t key;
} pd_uniques_clear_attribute_V5_t;

#define PD_CALL_UNIQUES_SET_METADATA_V5 19
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_BoundedVecu8_V5_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V5_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V5 20
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
} pd_uniques_clear_metadata_V5_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_METADATA_V5 21
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_BoundedVecu8_V5_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_collection_metadata_V5_t;

#define PD_CALL_UNIQUES_CLEAR_COLLECTION_METADATA_V5 22
typedef struct {
    pd_CollectionId_V5_t collection;
} pd_uniques_clear_collection_metadata_V5_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V5 23
typedef struct {
    pd_OptionCollectionId_V5_t maybe_collection;
} pd_uniques_set_accept_ownership_V5_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_MAX_SUPPLY_V5 24
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_u32_t max_supply;
} pd_uniques_set_collection_max_supply_V5_t;

#define PD_CALL_UNIQUES_SET_PRICE_V5 25
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_OptionItemPrice_V5_t price;
    pd_OptionLookupasStaticLookupSource_V5_t whitelisted_buyer;
} pd_uniques_set_price_V5_t;

#define PD_CALL_UNIQUES_BUY_ITEM_V5 26
typedef struct {
    pd_CollectionId_V5_t collection;
    pd_ItemId_V5_t item;
    pd_ItemPrice_V5_t bid_price;
} pd_uniques_buy_item_V5_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V5 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V5_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V5 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V5_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V5 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V5_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V5 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V5_t;

#define PD_CALL_ALLOCATIONS_BATCH_V5 0
typedef struct {
    pd_VecTupleAccountIdBalanceOf_V5_t batch;
} pd_allocations_batch_V5_t;

#define PD_CALL_ALLOCATIONS_SET_CURVE_STARTING_BLOCK_V5 1
typedef struct {
    pd_BlockNumber_t curve_start;
} pd_allocations_set_curve_starting_block_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_ADD_MEMBER_V5 0
typedef struct {
    pd_AccountId_V5_t who;
} pd_allocationsoracles_add_member_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_REMOVE_MEMBER_V5 1
typedef struct {
    pd_AccountId_V5_t who;
} pd_allocationsoracles_remove_member_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_SWAP_MEMBER_V5 2
typedef struct {
    pd_AccountId_V5_t remove;
    pd_AccountId_V5_t add;
} pd_allocationsoracles_swap_member_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_RESET_MEMBERS_V5 3
typedef struct {
    pd_VecAccountId_V5_t members;
} pd_allocationsoracles_reset_members_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_CHANGE_KEY_V5 4
typedef struct {
    pd_AccountId_V5_t new_;
} pd_allocationsoracles_change_key_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_SET_PRIME_V5 5
typedef struct {
    pd_AccountId_V5_t who;
} pd_allocationsoracles_set_prime_V5_t;

#define PD_CALL_ALLOCATIONSORACLES_CLEAR_PRIME_V5 6
typedef struct {
} pd_allocationsoracles_clear_prime_V5_t;

#define PD_CALL_DAORESERVE_SPEND_V5 0
typedef struct {
    pd_AccountId_V5_t to;
    pd_BalanceOf_t amount;
} pd_daoreserve_spend_V5_t;

#define PD_CALL_DAORESERVE_TIP_V5 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_daoreserve_tip_V5_t;

#define PD_CALL_DAORESERVE_APPLY_AS_V5 2
typedef struct {
    pd_Call_t call;
} pd_daoreserve_apply_as_V5_t;

#endif

typedef union {
    pd_balances_transfer_all_V5_t balances_transfer_all_V5;
    pd_session_set_keys_V5_t session_set_keys_V5;
    pd_session_purge_keys_V5_t session_purge_keys_V5;
    pd_utility_force_batch_V5_t utility_force_batch_V5;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V5_t timestamp_set_V5;
    pd_balances_force_unreserve_V5_t balances_force_unreserve_V5;
    pd_companyreserve_spend_V5_t companyreserve_spend_V5;
    pd_companyreserve_tip_V5_t companyreserve_tip_V5;
    pd_companyreserve_apply_as_V5_t companyreserve_apply_as_V5;
    pd_internationalreserve_spend_V5_t internationalreserve_spend_V5;
    pd_internationalreserve_tip_V5_t internationalreserve_tip_V5;
    pd_internationalreserve_apply_as_V5_t internationalreserve_apply_as_V5;
    pd_usareserve_spend_V5_t usareserve_spend_V5;
    pd_usareserve_tip_V5_t usareserve_tip_V5;
    pd_usareserve_apply_as_V5_t usareserve_apply_as_V5;
    pd_vesting_claim_V5_t vesting_claim_V5;
    pd_vesting_add_vesting_schedule_V5_t vesting_add_vesting_schedule_V5;
    pd_vesting_cancel_all_vesting_schedules_V5_t vesting_cancel_all_vesting_schedules_V5;
    pd_vesting_renounce_V5_t vesting_renounce_V5;
    pd_technicalcommittee_set_members_V5_t technicalcommittee_set_members_V5;
    pd_technicalcommittee_execute_V5_t technicalcommittee_execute_V5;
    pd_technicalcommittee_propose_V5_t technicalcommittee_propose_V5;
    pd_technicalcommittee_vote_V5_t technicalcommittee_vote_V5;
    pd_technicalcommittee_close_V5_t technicalcommittee_close_V5;
    pd_technicalcommittee_disapprove_proposal_V5_t technicalcommittee_disapprove_proposal_V5;
    pd_technicalmembership_add_member_V5_t technicalmembership_add_member_V5;
    pd_technicalmembership_remove_member_V5_t technicalmembership_remove_member_V5;
    pd_technicalmembership_swap_member_V5_t technicalmembership_swap_member_V5;
    pd_technicalmembership_reset_members_V5_t technicalmembership_reset_members_V5;
    pd_technicalmembership_change_key_V5_t technicalmembership_change_key_V5;
    pd_technicalmembership_set_prime_V5_t technicalmembership_set_prime_V5;
    pd_technicalmembership_clear_prime_V5_t technicalmembership_clear_prime_V5;
    pd_validatorsset_add_member_V5_t validatorsset_add_member_V5;
    pd_validatorsset_remove_member_V5_t validatorsset_remove_member_V5;
    pd_validatorsset_swap_member_V5_t validatorsset_swap_member_V5;
    pd_validatorsset_reset_members_V5_t validatorsset_reset_members_V5;
    pd_validatorsset_change_key_V5_t validatorsset_change_key_V5;
    pd_validatorsset_set_prime_V5_t validatorsset_set_prime_V5;
    pd_validatorsset_clear_prime_V5_t validatorsset_clear_prime_V5;
    pd_dmpqueue_service_overweight_V5_t dmpqueue_service_overweight_V5;
    pd_uniques_create_V5_t uniques_create_V5;
    pd_uniques_force_create_V5_t uniques_force_create_V5;
    pd_uniques_try_increment_id_V5_t uniques_try_increment_id_V5;
    pd_uniques_destroy_V5_t uniques_destroy_V5;
    pd_uniques_mint_V5_t uniques_mint_V5;
    pd_uniques_burn_V5_t uniques_burn_V5;
    pd_uniques_transfer_V5_t uniques_transfer_V5;
    pd_uniques_redeposit_V5_t uniques_redeposit_V5;
    pd_uniques_freeze_V5_t uniques_freeze_V5;
    pd_uniques_thaw_V5_t uniques_thaw_V5;
    pd_uniques_freeze_collection_V5_t uniques_freeze_collection_V5;
    pd_uniques_thaw_collection_V5_t uniques_thaw_collection_V5;
    pd_uniques_transfer_ownership_V5_t uniques_transfer_ownership_V5;
    pd_uniques_set_team_V5_t uniques_set_team_V5;
    pd_uniques_approve_transfer_V5_t uniques_approve_transfer_V5;
    pd_uniques_cancel_approval_V5_t uniques_cancel_approval_V5;
    pd_uniques_force_item_status_V5_t uniques_force_item_status_V5;
    pd_uniques_set_attribute_V5_t uniques_set_attribute_V5;
    pd_uniques_clear_attribute_V5_t uniques_clear_attribute_V5;
    pd_uniques_set_metadata_V5_t uniques_set_metadata_V5;
    pd_uniques_clear_metadata_V5_t uniques_clear_metadata_V5;
    pd_uniques_set_collection_metadata_V5_t uniques_set_collection_metadata_V5;
    pd_uniques_clear_collection_metadata_V5_t uniques_clear_collection_metadata_V5;
    pd_uniques_set_accept_ownership_V5_t uniques_set_accept_ownership_V5;
    pd_uniques_set_collection_max_supply_V5_t uniques_set_collection_max_supply_V5;
    pd_uniques_set_price_V5_t uniques_set_price_V5;
    pd_uniques_buy_item_V5_t uniques_buy_item_V5;
    pd_preimage_note_preimage_V5_t preimage_note_preimage_V5;
    pd_preimage_unnote_preimage_V5_t preimage_unnote_preimage_V5;
    pd_preimage_request_preimage_V5_t preimage_request_preimage_V5;
    pd_preimage_unrequest_preimage_V5_t preimage_unrequest_preimage_V5;
    pd_allocations_batch_V5_t allocations_batch_V5;
    pd_allocations_set_curve_starting_block_V5_t allocations_set_curve_starting_block_V5;
    pd_allocationsoracles_add_member_V5_t allocationsoracles_add_member_V5;
    pd_allocationsoracles_remove_member_V5_t allocationsoracles_remove_member_V5;
    pd_allocationsoracles_swap_member_V5_t allocationsoracles_swap_member_V5;
    pd_allocationsoracles_reset_members_V5_t allocationsoracles_reset_members_V5;
    pd_allocationsoracles_change_key_V5_t allocationsoracles_change_key_V5;
    pd_allocationsoracles_set_prime_V5_t allocationsoracles_set_prime_V5;
    pd_allocationsoracles_clear_prime_V5_t allocationsoracles_clear_prime_V5;
    pd_daoreserve_spend_V5_t daoreserve_spend_V5;
    pd_daoreserve_tip_V5_t daoreserve_tip_V5;
    pd_daoreserve_apply_as_V5_t daoreserve_apply_as_V5;
#endif
} pd_MethodBasic_V5_t;

#define PD_CALL_BALANCES_TRANSFER_V5 0
typedef struct {
    pd_LookupasStaticLookupSource_V5_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V5_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V5 2
typedef struct {
    pd_LookupasStaticLookupSource_V5_t source;
    pd_LookupasStaticLookupSource_V5_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V5_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V5 3
typedef struct {
    pd_LookupasStaticLookupSource_V5_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V5_t;

#define PD_CALL_UTILITY_BATCH_V5 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V5_t;

#define PD_CALL_UTILITY_BATCH_ALL_V5 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V5_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V5 0
typedef struct {
    pd_Perbill_V5_t ratio;
} pd_system_fill_block_V5_t;

#define PD_CALL_SYSTEM_REMARK_V5 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V5_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V5 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V5_t;

#define PD_CALL_SYSTEM_SET_CODE_V5 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V5_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V5 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V5_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V5 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V5_t;

#define PD_CALL_BALANCES_SET_BALANCE_V5 1
typedef struct {
    pd_LookupasStaticLookupSource_V5_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V5_t;

#define PD_CALL_MANDATE_APPLY_V5 0
typedef struct {
    pd_Call_t call;
} pd_mandate_apply_V5_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V5 0
typedef struct {
    pd_VecAccountId_V5_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V5_t;

#define PD_CALL_MULTISIG_AS_MULTI_V5 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V5_t other_signatories;
    pd_OptionTimepoint_V5_t maybe_timepoint;
    pd_OpaqueCall_V5_t call;
    pd_bool_t store_call;
    pd_Weight_V5_t max_weight;
} pd_multisig_as_multi_V5_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V5 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V5_t other_signatories;
    pd_OptionTimepoint_V5_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V5_t max_weight;
} pd_multisig_approve_as_multi_V5_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V5 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V5_t other_signatories;
    pd_Timepoint_V5_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V5_t;

#endif

typedef union {
    pd_balances_transfer_V5_t balances_transfer_V5;
    pd_balances_force_transfer_V5_t balances_force_transfer_V5;
    pd_balances_transfer_keep_alive_V5_t balances_transfer_keep_alive_V5;
    pd_utility_batch_V5_t utility_batch_V5;
    pd_utility_batch_all_V5_t utility_batch_all_V5;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V5_t system_fill_block_V5;
    pd_system_remark_V5_t system_remark_V5;
    pd_system_set_heap_pages_V5_t system_set_heap_pages_V5;
    pd_system_set_code_V5_t system_set_code_V5;
    pd_system_set_code_without_checks_V5_t system_set_code_without_checks_V5;
    pd_system_remark_with_event_V5_t system_remark_with_event_V5;
    pd_balances_set_balance_V5_t balances_set_balance_V5;
    pd_mandate_apply_V5_t mandate_apply_V5;
    pd_multisig_as_multi_threshold_1_V5_t multisig_as_multi_threshold_1_V5;
    pd_multisig_as_multi_V5_t multisig_as_multi_V5;
    pd_multisig_approve_as_multi_V5_t multisig_approve_as_multi_V5;
    pd_multisig_cancel_as_multi_V5_t multisig_cancel_as_multi_V5;
#endif
} pd_MethodNested_V5_t;

typedef union {
    pd_MethodBasic_V5_t basic;
    pd_MethodNested_V5_t nested;
} pd_Method_V5_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
