/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V7 0
#define PD_CALL_BALANCES_V7 2
#define PD_CALL_COMPANYRESERVE_V7 11
#define PD_CALL_INTERNATIONALRESERVE_V7 12
#define PD_CALL_USARESERVE_V7 13
#define PD_CALL_VESTING_V7 14
#define PD_CALL_MANDATE_V7 15
#define PD_CALL_TECHNICALCOMMITTEE_V7 16
#define PD_CALL_TECHNICALMEMBERSHIP_V7 17
#define PD_CALL_COLLATORSELECTION_V7 19
#define PD_CALL_SESSION_V7 23
#define PD_CALL_POLKADOTXCM_V7 35
#define PD_CALL_XTOKENS_V7 36
#define PD_CALL_UTILITY_V7 40
#define PD_CALL_MULTISIG_V7 41
#define PD_CALL_UNIQUES_V7 42
#define PD_CALL_PREIMAGE_V7 43
#define PD_CALL_ALLOCATIONS_V7 51
#define PD_CALL_ALLOCATIONSORACLES_V7 52
#define PD_CALL_DAORESERVE_V7 60
#define PD_CALL_CONTRACTS_V7 62

#define PD_CALL_BALANCES_TRANSFER_ALL_V7 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V7_t;

#define PD_CALL_SESSION_SET_KEYS_V7 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V7_t;

#define PD_CALL_SESSION_PURGE_KEYS_V7 1
typedef struct {
} pd_session_purge_keys_V7_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V7 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_POLKADOTXCM_TELEPORT_ASSETS_V7 1
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_teleport_assets_V7_t;
#define PD_CALL_POLKADOTXCM_RESERVE_TRANSFER_ASSETS_V7 2
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_reserve_transfer_assets_V7_t;
#define PD_CALL_POLKADOTXCM_LIMITED_RESERVE_TRANSFER_ASSETS_V7 8
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_polkadotxcm_limited_reserve_transfer_assets_V7_t;
#define PD_CALL_POLKADOTXCM_LIMITED_TELEPORT_ASSETS_V7 9
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_polkadotxcm_limited_teleport_assets_V7_t;
#define PD_CALL_XTOKENS_TRANSFER_V7 0
typedef struct {
    pd_CurrencyId_t currency_id;
    pd_Balance_t amount;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_V7_t;
#define PD_CALL_XTOKENS_TRANSFER_MULTIASSET_V7 1
typedef struct {
    pd_BoxVersionedMultiAsset_t asset;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_multiasset_V7_t;
#define PD_CALL_XTOKENS_TRANSFER_WITH_FEE_V7 2
typedef struct {
    pd_CurrencyId_t currency_id;
    pd_Balance_t amount;
    pd_Balance_t fee;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_with_fee_V7_t;
#define PD_CALL_XTOKENS_TRANSFER_MULTIASSET_WITH_FEE_V7 3
typedef struct {
    pd_BoxVersionedMultiAsset_t asset;
    pd_BoxVersionedMultiAsset_t fee;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_multiasset_with_fee_V7_t;
#define PD_CALL_XTOKENS_TRANSFER_MULTIASSETS_V7 5
typedef struct {
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_item;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_multiassets_V7_t;
#endif

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V7 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V7_t;

#define PD_CALL_COMPANYRESERVE_SPEND_V7 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_companyreserve_spend_V7_t;

#define PD_CALL_COMPANYRESERVE_TIP_V7 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_companyreserve_tip_V7_t;

#define PD_CALL_COMPANYRESERVE_APPLY_AS_V7 2
typedef struct {
    pd_Call_t call;
} pd_companyreserve_apply_as_V7_t;

#define PD_CALL_INTERNATIONALRESERVE_SPEND_V7 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_internationalreserve_spend_V7_t;

#define PD_CALL_INTERNATIONALRESERVE_TIP_V7 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_internationalreserve_tip_V7_t;

#define PD_CALL_INTERNATIONALRESERVE_APPLY_AS_V7 2
typedef struct {
    pd_Call_t call;
} pd_internationalreserve_apply_as_V7_t;

#define PD_CALL_USARESERVE_SPEND_V7 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_usareserve_spend_V7_t;

#define PD_CALL_USARESERVE_TIP_V7 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_usareserve_tip_V7_t;

#define PD_CALL_USARESERVE_APPLY_AS_V7 2
typedef struct {
    pd_Call_t call;
} pd_usareserve_apply_as_V7_t;

#define PD_CALL_VESTING_CLAIM_V7 0
typedef struct {
} pd_vesting_claim_V7_t;

#define PD_CALL_VESTING_ADD_VESTING_SCHEDULE_V7 1
typedef struct {
    pd_LookupasStaticLookupSource_t dest;
    pd_VestingScheduleOf_t schedule;
} pd_vesting_add_vesting_schedule_V7_t;

#define PD_CALL_VESTING_CANCEL_ALL_VESTING_SCHEDULES_V7 2
typedef struct {
    pd_LookupasStaticLookupSource_t who;
    pd_LookupasStaticLookupSource_t funds_collector;
} pd_vesting_cancel_all_vesting_schedules_V7_t;

#define PD_CALL_VESTING_RENOUNCE_V7 3
typedef struct {
    pd_LookupasStaticLookupSource_t who;
} pd_vesting_renounce_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V7 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_technicalcommittee_set_members_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V7 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V7 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V7 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_OLD_WEIGHT_V7 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_old_weight_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V7 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V7_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V7 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V7 0
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_add_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V7 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_remove_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V7 2
typedef struct {
    pd_AccountIdLookupOfT_t remove;
    pd_AccountIdLookupOfT_t add;
} pd_technicalmembership_swap_member_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V7 3
typedef struct {
    pd_VecAccountId_t members;
} pd_technicalmembership_reset_members_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V7 4
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_technicalmembership_change_key_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V7 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_set_prime_V7_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V7 6
typedef struct {
} pd_technicalmembership_clear_prime_V7_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V7 0
typedef struct {
    pd_VecAccountId_t new_;
} pd_collatorselection_set_invulnerables_V7_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V7 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V7_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V7 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V7_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V7 3
typedef struct {
} pd_collatorselection_register_as_candidate_V7_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V7 4
typedef struct {
} pd_collatorselection_leave_intent_V7_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V7 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V7_t;

#define PD_CALL_UNIQUES_CREATE_V7 0
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t admin;
} pd_uniques_create_V7_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V7 1
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V7_t;

#define PD_CALL_UNIQUES_DESTROY_V7 2
typedef struct {
    pd_CollectionId_t collection;
    pd_DestroyWitness_t witness;
} pd_uniques_destroy_V7_t;

#define PD_CALL_UNIQUES_MINT_V7 3
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t owner;
} pd_uniques_mint_V7_t;

#define PD_CALL_UNIQUES_BURN_V7 4
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionAccountIdLookupOfT_t check_owner;
} pd_uniques_burn_V7_t;

#define PD_CALL_UNIQUES_TRANSFER_V7 5
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t dest;
} pd_uniques_transfer_V7_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V7 6
typedef struct {
    pd_CollectionId_t collection;
    pd_VecItemId_t items;
} pd_uniques_redeposit_V7_t;

#define PD_CALL_UNIQUES_FREEZE_V7 7
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_freeze_V7_t;

#define PD_CALL_UNIQUES_THAW_V7 8
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_thaw_V7_t;

#define PD_CALL_UNIQUES_FREEZE_COLLECTION_V7 9
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_freeze_collection_V7_t;

#define PD_CALL_UNIQUES_THAW_COLLECTION_V7 10
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_thaw_collection_V7_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V7 11
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
} pd_uniques_transfer_ownership_V7_t;

#define PD_CALL_UNIQUES_SET_TEAM_V7 12
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
} pd_uniques_set_team_V7_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V7 13
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
} pd_uniques_approve_transfer_V7_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V7 14
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionAccountIdLookupOfT_t maybe_check_delegate;
} pd_uniques_cancel_approval_V7_t;

#define PD_CALL_UNIQUES_FORCE_ITEM_STATUS_V7 15
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_item_status_V7_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V7 16
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_BoundedVecu8_t key;
    pd_BoundedVecu8_t value;
} pd_uniques_set_attribute_V7_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V7 17
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_BoundedVecu8_t key;
} pd_uniques_clear_attribute_V7_t;

#define PD_CALL_UNIQUES_SET_METADATA_V7 18
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_BoundedVecu8_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V7_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V7 19
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_clear_metadata_V7_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_METADATA_V7 20
typedef struct {
    pd_CollectionId_t collection;
    pd_BoundedVecu8_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_collection_metadata_V7_t;

#define PD_CALL_UNIQUES_CLEAR_COLLECTION_METADATA_V7 21
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_clear_collection_metadata_V7_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V7 22
typedef struct {
    pd_OptionCollectionId_t maybe_collection;
} pd_uniques_set_accept_ownership_V7_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_MAX_SUPPLY_V7 23
typedef struct {
    pd_CollectionId_t collection;
    pd_u32_t max_supply;
} pd_uniques_set_collection_max_supply_V7_t;

#define PD_CALL_UNIQUES_SET_PRICE_V7 24
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionItemPrice_t price;
    pd_OptionAccountIdLookupOfT_t whitelisted_buyer;
} pd_uniques_set_price_V7_t;

#define PD_CALL_UNIQUES_BUY_ITEM_V7 25
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_ItemPrice_t bid_price;
} pd_uniques_buy_item_V7_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V7 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V7_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V7 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V7_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V7 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V7_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V7 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V7_t;

#define PD_CALL_ALLOCATIONS_BATCH_V7 0
typedef struct {
    pd_VecTupleAccountIdBalanceOf_t batch;
} pd_allocations_batch_V7_t;

#define PD_CALL_ALLOCATIONS_SET_CURVE_STARTING_BLOCK_V7 1
typedef struct {
    pd_BlockNumber_t curve_start;
} pd_allocations_set_curve_starting_block_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_ADD_MEMBER_V7 0
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_allocationsoracles_add_member_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_REMOVE_MEMBER_V7 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_allocationsoracles_remove_member_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_SWAP_MEMBER_V7 2
typedef struct {
    pd_AccountIdLookupOfT_t remove;
    pd_AccountIdLookupOfT_t add;
} pd_allocationsoracles_swap_member_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_RESET_MEMBERS_V7 3
typedef struct {
    pd_VecAccountId_t members;
} pd_allocationsoracles_reset_members_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_CHANGE_KEY_V7 4
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_allocationsoracles_change_key_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_SET_PRIME_V7 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_allocationsoracles_set_prime_V7_t;

#define PD_CALL_ALLOCATIONSORACLES_CLEAR_PRIME_V7 6
typedef struct {
} pd_allocationsoracles_clear_prime_V7_t;

#define PD_CALL_DAORESERVE_SPEND_V7 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_daoreserve_spend_V7_t;

#define PD_CALL_DAORESERVE_TIP_V7 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_daoreserve_tip_V7_t;

#define PD_CALL_DAORESERVE_APPLY_AS_V7 2
typedef struct {
    pd_Call_t call;
} pd_daoreserve_apply_as_V7_t;

#define PD_CALL_CONTRACTS_CALL_OLD_WEIGHT_V7 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_old_weight_V7_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_OLD_WEIGHT_V7 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_old_weight_V7_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_OLD_WEIGHT_V7 2
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_old_weight_V7_t;

#define PD_CALL_CONTRACTS_UPLOAD_CODE_V7 3
typedef struct {
    pd_Vecu8_t code;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Determinism_t determinism;
} pd_contracts_upload_code_V7_t;

#define PD_CALL_CONTRACTS_REMOVE_CODE_V7 4
typedef struct {
    pd_CodeHash_t code_hash;
} pd_contracts_remove_code_V7_t;

#define PD_CALL_CONTRACTS_SET_CODE_V7 5
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CodeHash_t code_hash;
} pd_contracts_set_code_V7_t;

#define PD_CALL_CONTRACTS_CALL_V7 6
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_V7_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V7 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_V7_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V7 8
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V7_t;

#endif

typedef union {
    pd_balances_transfer_all_V7_t balances_transfer_all_V7;
    pd_session_set_keys_V7_t session_set_keys_V7;
    pd_session_purge_keys_V7_t session_purge_keys_V7;
    pd_utility_force_batch_V7_t utility_force_batch_V7;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_polkadotxcm_teleport_assets_V7_t polkadotxcm_teleport_assets_V7;
    pd_polkadotxcm_reserve_transfer_assets_V7_t polkadotxcm_reserve_transfer_assets_V7;
    pd_polkadotxcm_limited_reserve_transfer_assets_V7_t polkadotxcm_limited_reserve_transfer_assets_V7;
    pd_polkadotxcm_limited_teleport_assets_V7_t polkadotxcm_limited_teleport_assets_V7;
    pd_xtokens_transfer_V7_t xtokens_transfer_V7;
    pd_xtokens_transfer_multiasset_V7_t xtokens_transfer_multiasset_V7;
    pd_xtokens_transfer_with_fee_V7_t xtokens_transfer_with_fee_V7;
    pd_xtokens_transfer_multiasset_with_fee_V7_t xtokens_transfer_multiasset_with_fee_V7;
    pd_xtokens_transfer_multiassets_V7_t xtokens_transfer_multiassets_V7;
#endif
    pd_balances_force_unreserve_V7_t balances_force_unreserve_V7;
    pd_companyreserve_spend_V7_t companyreserve_spend_V7;
    pd_companyreserve_tip_V7_t companyreserve_tip_V7;
    pd_companyreserve_apply_as_V7_t companyreserve_apply_as_V7;
    pd_internationalreserve_spend_V7_t internationalreserve_spend_V7;
    pd_internationalreserve_tip_V7_t internationalreserve_tip_V7;
    pd_internationalreserve_apply_as_V7_t internationalreserve_apply_as_V7;
    pd_usareserve_spend_V7_t usareserve_spend_V7;
    pd_usareserve_tip_V7_t usareserve_tip_V7;
    pd_usareserve_apply_as_V7_t usareserve_apply_as_V7;
    pd_vesting_claim_V7_t vesting_claim_V7;
    pd_vesting_add_vesting_schedule_V7_t vesting_add_vesting_schedule_V7;
    pd_vesting_cancel_all_vesting_schedules_V7_t vesting_cancel_all_vesting_schedules_V7;
    pd_vesting_renounce_V7_t vesting_renounce_V7;
    pd_technicalcommittee_set_members_V7_t technicalcommittee_set_members_V7;
    pd_technicalcommittee_execute_V7_t technicalcommittee_execute_V7;
    pd_technicalcommittee_propose_V7_t technicalcommittee_propose_V7;
    pd_technicalcommittee_vote_V7_t technicalcommittee_vote_V7;
    pd_technicalcommittee_close_old_weight_V7_t technicalcommittee_close_old_weight_V7;
    pd_technicalcommittee_disapprove_proposal_V7_t technicalcommittee_disapprove_proposal_V7;
    pd_technicalcommittee_close_V7_t technicalcommittee_close_V7;
    pd_technicalmembership_add_member_V7_t technicalmembership_add_member_V7;
    pd_technicalmembership_remove_member_V7_t technicalmembership_remove_member_V7;
    pd_technicalmembership_swap_member_V7_t technicalmembership_swap_member_V7;
    pd_technicalmembership_reset_members_V7_t technicalmembership_reset_members_V7;
    pd_technicalmembership_change_key_V7_t technicalmembership_change_key_V7;
    pd_technicalmembership_set_prime_V7_t technicalmembership_set_prime_V7;
    pd_technicalmembership_clear_prime_V7_t technicalmembership_clear_prime_V7;
    pd_collatorselection_set_invulnerables_V7_t collatorselection_set_invulnerables_V7;
    pd_collatorselection_set_desired_candidates_V7_t collatorselection_set_desired_candidates_V7;
    pd_collatorselection_set_candidacy_bond_V7_t collatorselection_set_candidacy_bond_V7;
    pd_collatorselection_register_as_candidate_V7_t collatorselection_register_as_candidate_V7;
    pd_collatorselection_leave_intent_V7_t collatorselection_leave_intent_V7;
    pd_utility_with_weight_V7_t utility_with_weight_V7;
    pd_uniques_create_V7_t uniques_create_V7;
    pd_uniques_force_create_V7_t uniques_force_create_V7;
    pd_uniques_destroy_V7_t uniques_destroy_V7;
    pd_uniques_mint_V7_t uniques_mint_V7;
    pd_uniques_burn_V7_t uniques_burn_V7;
    pd_uniques_transfer_V7_t uniques_transfer_V7;
    pd_uniques_redeposit_V7_t uniques_redeposit_V7;
    pd_uniques_freeze_V7_t uniques_freeze_V7;
    pd_uniques_thaw_V7_t uniques_thaw_V7;
    pd_uniques_freeze_collection_V7_t uniques_freeze_collection_V7;
    pd_uniques_thaw_collection_V7_t uniques_thaw_collection_V7;
    pd_uniques_transfer_ownership_V7_t uniques_transfer_ownership_V7;
    pd_uniques_set_team_V7_t uniques_set_team_V7;
    pd_uniques_approve_transfer_V7_t uniques_approve_transfer_V7;
    pd_uniques_cancel_approval_V7_t uniques_cancel_approval_V7;
    pd_uniques_force_item_status_V7_t uniques_force_item_status_V7;
    pd_uniques_set_attribute_V7_t uniques_set_attribute_V7;
    pd_uniques_clear_attribute_V7_t uniques_clear_attribute_V7;
    pd_uniques_set_metadata_V7_t uniques_set_metadata_V7;
    pd_uniques_clear_metadata_V7_t uniques_clear_metadata_V7;
    pd_uniques_set_collection_metadata_V7_t uniques_set_collection_metadata_V7;
    pd_uniques_clear_collection_metadata_V7_t uniques_clear_collection_metadata_V7;
    pd_uniques_set_accept_ownership_V7_t uniques_set_accept_ownership_V7;
    pd_uniques_set_collection_max_supply_V7_t uniques_set_collection_max_supply_V7;
    pd_uniques_set_price_V7_t uniques_set_price_V7;
    pd_uniques_buy_item_V7_t uniques_buy_item_V7;
    pd_preimage_note_preimage_V7_t preimage_note_preimage_V7;
    pd_preimage_unnote_preimage_V7_t preimage_unnote_preimage_V7;
    pd_preimage_request_preimage_V7_t preimage_request_preimage_V7;
    pd_preimage_unrequest_preimage_V7_t preimage_unrequest_preimage_V7;
    pd_allocations_batch_V7_t allocations_batch_V7;
    pd_allocations_set_curve_starting_block_V7_t allocations_set_curve_starting_block_V7;
    pd_allocationsoracles_add_member_V7_t allocationsoracles_add_member_V7;
    pd_allocationsoracles_remove_member_V7_t allocationsoracles_remove_member_V7;
    pd_allocationsoracles_swap_member_V7_t allocationsoracles_swap_member_V7;
    pd_allocationsoracles_reset_members_V7_t allocationsoracles_reset_members_V7;
    pd_allocationsoracles_change_key_V7_t allocationsoracles_change_key_V7;
    pd_allocationsoracles_set_prime_V7_t allocationsoracles_set_prime_V7;
    pd_allocationsoracles_clear_prime_V7_t allocationsoracles_clear_prime_V7;
    pd_daoreserve_spend_V7_t daoreserve_spend_V7;
    pd_daoreserve_tip_V7_t daoreserve_tip_V7;
    pd_daoreserve_apply_as_V7_t daoreserve_apply_as_V7;
    pd_contracts_call_old_weight_V7_t contracts_call_old_weight_V7;
    pd_contracts_instantiate_with_code_old_weight_V7_t contracts_instantiate_with_code_old_weight_V7;
    pd_contracts_instantiate_old_weight_V7_t contracts_instantiate_old_weight_V7;
    pd_contracts_upload_code_V7_t contracts_upload_code_V7;
    pd_contracts_remove_code_V7_t contracts_remove_code_V7;
    pd_contracts_set_code_V7_t contracts_set_code_V7;
    pd_contracts_call_V7_t contracts_call_V7;
    pd_contracts_instantiate_with_code_V7_t contracts_instantiate_with_code_V7;
    pd_contracts_instantiate_V7_t contracts_instantiate_V7;
#endif
} pd_MethodBasic_V7_t;

#define PD_CALL_BALANCES_TRANSFER_V7 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V7_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V7 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V7_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V7 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V7_t;

#define PD_CALL_UTILITY_BATCH_V7 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V7_t;

#define PD_CALL_UTILITY_BATCH_ALL_V7 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V7 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V7_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V7 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_V7 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V7 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V7_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V7 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V7_t;

#define PD_CALL_BALANCES_SET_BALANCE_V7 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V7_t;

#define PD_CALL_MANDATE_APPLY_V7 0
typedef struct {
    pd_Call_t call;
} pd_mandate_apply_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V7 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_V7 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V7_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V7 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V7_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V7 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V7_t;

#endif

typedef union {
    pd_balances_transfer_V7_t balances_transfer_V7;
    pd_balances_force_transfer_V7_t balances_force_transfer_V7;
    pd_balances_transfer_keep_alive_V7_t balances_transfer_keep_alive_V7;
    pd_utility_batch_V7_t utility_batch_V7;
    pd_utility_batch_all_V7_t utility_batch_all_V7;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V7_t system_remark_V7;
    pd_system_set_heap_pages_V7_t system_set_heap_pages_V7;
    pd_system_set_code_V7_t system_set_code_V7;
    pd_system_set_code_without_checks_V7_t system_set_code_without_checks_V7;
    pd_system_remark_with_event_V7_t system_remark_with_event_V7;
    pd_balances_set_balance_V7_t balances_set_balance_V7;
    pd_mandate_apply_V7_t mandate_apply_V7;
    pd_multisig_as_multi_threshold_1_V7_t multisig_as_multi_threshold_1_V7;
    pd_multisig_as_multi_V7_t multisig_as_multi_V7;
    pd_multisig_approve_as_multi_V7_t multisig_approve_as_multi_V7;
    pd_multisig_cancel_as_multi_V7_t multisig_cancel_as_multi_V7;
#endif
} pd_MethodNested_V7_t;

typedef union {
    pd_MethodBasic_V7_t basic;
    pd_MethodNested_V7_t nested;
} pd_Method_V7_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
