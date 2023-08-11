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
#include "substrate_types_V8.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V8 0
#define PD_CALL_BALANCES_V8 2
#define PD_CALL_COMPANYRESERVE_V8 11
#define PD_CALL_INTERNATIONALRESERVE_V8 12
#define PD_CALL_USARESERVE_V8 13
#define PD_CALL_VESTING_V8 14
#define PD_CALL_MANDATE_V8 15
#define PD_CALL_TECHNICALCOMMITTEE_V8 16
#define PD_CALL_TECHNICALMEMBERSHIP_V8 17
#define PD_CALL_COLLATORSELECTION_V8 19
#define PD_CALL_SESSION_V8 23
#define PD_CALL_POLKADOTXCM_V8 35
#define PD_CALL_XTOKENS_V8 36
#define PD_CALL_UTILITY_V8 40
#define PD_CALL_MULTISIG_V8 41
#define PD_CALL_UNIQUES_V8 42
#define PD_CALL_PREIMAGE_V8 43
#define PD_CALL_ALLOCATIONS_V8 51
#define PD_CALL_ALLOCATIONSORACLES_V8 52
#define PD_CALL_DAORESERVE_V8 60
#define PD_CALL_CONTRACTS_V8 62

#define PD_CALL_SESSION_SET_KEYS_V8 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V8_t;

#define PD_CALL_SESSION_PURGE_KEYS_V8 1
typedef struct {
} pd_session_purge_keys_V8_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V8 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V8_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_POLKADOTXCM_TELEPORT_ASSETS_V8 1
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_teleport_assets_V8_t;
#define PD_CALL_POLKADOTXCM_RESERVE_TRANSFER_ASSETS_V8 2
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_reserve_transfer_assets_V8_t;
#define PD_CALL_POLKADOTXCM_LIMITED_RESERVE_TRANSFER_ASSETS_V8 8
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_polkadotxcm_limited_reserve_transfer_assets_V8_t;
#define PD_CALL_POLKADOTXCM_LIMITED_TELEPORT_ASSETS_V8 9
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_polkadotxcm_limited_teleport_assets_V8_t;
#define PD_CALL_POLKADOTXCM_FORCE_SUSPENSION_V8 10
typedef struct {
    pd_bool_t suspended;
} pd_polkadotxcm_force_suspension_V8_t;
#define PD_CALL_XTOKENS_TRANSFER_V8 0
typedef struct {
    pd_CurrencyId_t currency_id;
    pd_Balance_t amount;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_V8_t;
#define PD_CALL_XTOKENS_TRANSFER_MULTIASSET_V8 1
typedef struct {
    pd_BoxVersionedMultiAsset_t asset;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_multiasset_V8_t;
#define PD_CALL_XTOKENS_TRANSFER_WITH_FEE_V8 2
typedef struct {
    pd_CurrencyId_t currency_id;
    pd_Balance_t amount;
    pd_Balance_t fee;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_with_fee_V8_t;
#define PD_CALL_XTOKENS_TRANSFER_MULTIASSET_WITH_FEE_V8 3
typedef struct {
    pd_BoxVersionedMultiAsset_t asset;
    pd_BoxVersionedMultiAsset_t fee;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_multiasset_with_fee_V8_t;
#define PD_CALL_XTOKENS_TRANSFER_MULTIASSETS_V8 5
typedef struct {
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_item;
    pd_BoxVersionedMultiLocation_t dest;
    pd_WeightLimit_t dest_weight_limit;
} pd_xtokens_transfer_multiassets_V8_t;
#endif

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V8 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V8_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V8 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V8_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V8 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V8_t;

#define PD_CALL_COMPANYRESERVE_SPEND_V8 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_companyreserve_spend_V8_t;

#define PD_CALL_COMPANYRESERVE_TIP_V8 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_companyreserve_tip_V8_t;

#define PD_CALL_COMPANYRESERVE_APPLY_AS_V8 2
typedef struct {
    pd_Call_t call;
} pd_companyreserve_apply_as_V8_t;

#define PD_CALL_INTERNATIONALRESERVE_SPEND_V8 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_internationalreserve_spend_V8_t;

#define PD_CALL_INTERNATIONALRESERVE_TIP_V8 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_internationalreserve_tip_V8_t;

#define PD_CALL_INTERNATIONALRESERVE_APPLY_AS_V8 2
typedef struct {
    pd_Call_t call;
} pd_internationalreserve_apply_as_V8_t;

#define PD_CALL_USARESERVE_SPEND_V8 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_usareserve_spend_V8_t;

#define PD_CALL_USARESERVE_TIP_V8 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_usareserve_tip_V8_t;

#define PD_CALL_USARESERVE_APPLY_AS_V8 2
typedef struct {
    pd_Call_t call;
} pd_usareserve_apply_as_V8_t;

#define PD_CALL_VESTING_CLAIM_V8 0
typedef struct {
} pd_vesting_claim_V8_t;

#define PD_CALL_VESTING_ADD_VESTING_SCHEDULE_V8 1
typedef struct {
    pd_LookupasStaticLookupSource_t dest;
    pd_VestingScheduleOf_t schedule;
} pd_vesting_add_vesting_schedule_V8_t;

#define PD_CALL_VESTING_CANCEL_ALL_VESTING_SCHEDULES_V8 2
typedef struct {
    pd_LookupasStaticLookupSource_t who;
    pd_LookupasStaticLookupSource_t funds_collector;
} pd_vesting_cancel_all_vesting_schedules_V8_t;

#define PD_CALL_VESTING_RENOUNCE_V8 3
typedef struct {
    pd_LookupasStaticLookupSource_t who;
} pd_vesting_renounce_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V8 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_technicalcommittee_set_members_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V8 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V8 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V8 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V8 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V8_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V8 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V8 0
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_add_member_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V8 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_remove_member_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V8 2
typedef struct {
    pd_AccountIdLookupOfT_t remove;
    pd_AccountIdLookupOfT_t add;
} pd_technicalmembership_swap_member_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V8 3
typedef struct {
    pd_VecAccountId_t members;
} pd_technicalmembership_reset_members_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V8 4
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_technicalmembership_change_key_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V8 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_set_prime_V8_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V8 6
typedef struct {
} pd_technicalmembership_clear_prime_V8_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V8 0
typedef struct {
    pd_VecAccountId_t new_;
} pd_collatorselection_set_invulnerables_V8_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V8 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V8_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V8 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V8_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V8 3
typedef struct {
} pd_collatorselection_register_as_candidate_V8_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V8 4
typedef struct {
} pd_collatorselection_leave_intent_V8_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V8 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V8_t;

#define PD_CALL_UNIQUES_CREATE_V8 0
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t admin;
} pd_uniques_create_V8_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V8 1
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V8_t;

#define PD_CALL_UNIQUES_DESTROY_V8 2
typedef struct {
    pd_CollectionId_t collection;
    pd_DestroyWitness_t witness;
} pd_uniques_destroy_V8_t;

#define PD_CALL_UNIQUES_MINT_V8 3
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t owner;
} pd_uniques_mint_V8_t;

#define PD_CALL_UNIQUES_BURN_V8 4
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionAccountIdLookupOfT_t check_owner;
} pd_uniques_burn_V8_t;

#define PD_CALL_UNIQUES_TRANSFER_V8 5
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t dest;
} pd_uniques_transfer_V8_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V8 6
typedef struct {
    pd_CollectionId_t collection;
    pd_VecItemId_t items;
} pd_uniques_redeposit_V8_t;

#define PD_CALL_UNIQUES_FREEZE_V8 7
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_freeze_V8_t;

#define PD_CALL_UNIQUES_THAW_V8 8
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_thaw_V8_t;

#define PD_CALL_UNIQUES_FREEZE_COLLECTION_V8 9
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_freeze_collection_V8_t;

#define PD_CALL_UNIQUES_THAW_COLLECTION_V8 10
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_thaw_collection_V8_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V8 11
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
} pd_uniques_transfer_ownership_V8_t;

#define PD_CALL_UNIQUES_SET_TEAM_V8 12
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
} pd_uniques_set_team_V8_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V8 13
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
} pd_uniques_approve_transfer_V8_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V8 14
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionAccountIdLookupOfT_t maybe_check_delegate;
} pd_uniques_cancel_approval_V8_t;

#define PD_CALL_UNIQUES_FORCE_ITEM_STATUS_V8 15
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_item_status_V8_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V8 16
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_BoundedVecu8_t key;
    pd_BoundedVecu8_t value;
} pd_uniques_set_attribute_V8_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V8 17
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_BoundedVecu8_t key;
} pd_uniques_clear_attribute_V8_t;

#define PD_CALL_UNIQUES_SET_METADATA_V8 18
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_BoundedVecu8_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V8_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V8 19
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_clear_metadata_V8_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_METADATA_V8 20
typedef struct {
    pd_CollectionId_t collection;
    pd_BoundedVecu8_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_collection_metadata_V8_t;

#define PD_CALL_UNIQUES_CLEAR_COLLECTION_METADATA_V8 21
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_clear_collection_metadata_V8_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V8 22
typedef struct {
    pd_OptionCollectionId_t maybe_collection;
} pd_uniques_set_accept_ownership_V8_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_MAX_SUPPLY_V8 23
typedef struct {
    pd_CollectionId_t collection;
    pd_u32_t max_supply;
} pd_uniques_set_collection_max_supply_V8_t;

#define PD_CALL_UNIQUES_SET_PRICE_V8 24
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionBalanceOf_t price;
    pd_OptionAccountIdLookupOfT_t whitelisted_buyer;
} pd_uniques_set_price_V8_t;

#define PD_CALL_UNIQUES_BUY_ITEM_V8 25
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_BalanceOf_t bid_price;
} pd_uniques_buy_item_V8_t;

#define PD_CALL_UNIQUES_CREATE_WITH_EXTRA_DEPOSIT_LIMIT_V8 26
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t admin;
    pd_BalanceOf_t limit;
} pd_uniques_create_with_extra_deposit_limit_V8_t;

#define PD_CALL_UNIQUES_MINT_WITH_EXTRA_DEPOSIT_V8 27
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t owner;
    pd_BalanceOf_t deposit;
} pd_uniques_mint_with_extra_deposit_V8_t;

#define PD_CALL_UNIQUES_UPDATE_EXTRA_DEPOSIT_LIMIT_V8 28
typedef struct {
    pd_CollectionId_t collection;
    pd_BalanceOf_t limit;
} pd_uniques_update_extra_deposit_limit_V8_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V8 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V8_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V8 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V8_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V8 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V8_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V8 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V8_t;

#define PD_CALL_ALLOCATIONS_BATCH_V8 0
typedef struct {
    pd_VecTupleAccountIdBalanceOf_t batch;
} pd_allocations_batch_V8_t;

#define PD_CALL_ALLOCATIONS_SET_CURVE_STARTING_BLOCK_V8 1
typedef struct {
    pd_BlockNumber_t curve_start;
} pd_allocations_set_curve_starting_block_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_ADD_MEMBER_V8 0
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_allocationsoracles_add_member_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_REMOVE_MEMBER_V8 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_allocationsoracles_remove_member_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_SWAP_MEMBER_V8 2
typedef struct {
    pd_AccountIdLookupOfT_t remove;
    pd_AccountIdLookupOfT_t add;
} pd_allocationsoracles_swap_member_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_RESET_MEMBERS_V8 3
typedef struct {
    pd_VecAccountId_t members;
} pd_allocationsoracles_reset_members_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_CHANGE_KEY_V8 4
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_allocationsoracles_change_key_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_SET_PRIME_V8 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_allocationsoracles_set_prime_V8_t;

#define PD_CALL_ALLOCATIONSORACLES_CLEAR_PRIME_V8 6
typedef struct {
} pd_allocationsoracles_clear_prime_V8_t;

#define PD_CALL_DAORESERVE_SPEND_V8 0
typedef struct {
    pd_AccountId_t to;
    pd_BalanceOf_t amount;
} pd_daoreserve_spend_V8_t;

#define PD_CALL_DAORESERVE_TIP_V8 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_daoreserve_tip_V8_t;

#define PD_CALL_DAORESERVE_APPLY_AS_V8 2
typedef struct {
    pd_Call_t call;
} pd_daoreserve_apply_as_V8_t;

#define PD_CALL_CONTRACTS_CALL_OLD_WEIGHT_V8 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_old_weight_V8_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_OLD_WEIGHT_V8 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_old_weight_V8_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_OLD_WEIGHT_V8 2
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_old_weight_V8_t;

#define PD_CALL_CONTRACTS_UPLOAD_CODE_V8 3
typedef struct {
    pd_Vecu8_t code;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Determinism_t determinism;
} pd_contracts_upload_code_V8_t;

#define PD_CALL_CONTRACTS_REMOVE_CODE_V8 4
typedef struct {
    pd_CodeHash_t code_hash;
} pd_contracts_remove_code_V8_t;

#define PD_CALL_CONTRACTS_SET_CODE_V8 5
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CodeHash_t code_hash;
} pd_contracts_set_code_V8_t;

#define PD_CALL_CONTRACTS_CALL_V8 6
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_V8_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V8 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_V8_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V8 8
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V8_t;

#endif

typedef union {
    pd_session_set_keys_V8_t session_set_keys_V8;
    pd_session_purge_keys_V8_t session_purge_keys_V8;
    pd_utility_force_batch_V8_t utility_force_batch_V8;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_polkadotxcm_teleport_assets_V8_t polkadotxcm_teleport_assets_V8;
    pd_polkadotxcm_reserve_transfer_assets_V8_t polkadotxcm_reserve_transfer_assets_V8;
    pd_polkadotxcm_limited_reserve_transfer_assets_V8_t polkadotxcm_limited_reserve_transfer_assets_V8;
    pd_polkadotxcm_limited_teleport_assets_V8_t polkadotxcm_limited_teleport_assets_V8;
    pd_polkadotxcm_force_suspension_V8_t polkadotxcm_force_suspension_V8;
    pd_xtokens_transfer_V8_t xtokens_transfer_V8;
    pd_xtokens_transfer_multiasset_V8_t xtokens_transfer_multiasset_V8;
    pd_xtokens_transfer_with_fee_V8_t xtokens_transfer_with_fee_V8;
    pd_xtokens_transfer_multiasset_with_fee_V8_t xtokens_transfer_multiasset_with_fee_V8;
    pd_xtokens_transfer_multiassets_V8_t xtokens_transfer_multiassets_V8;
#endif
    pd_balances_force_unreserve_V8_t balances_force_unreserve_V8;
    pd_balances_upgrade_accounts_V8_t balances_upgrade_accounts_V8;
    pd_balances_force_set_balance_V8_t balances_force_set_balance_V8;
    pd_companyreserve_spend_V8_t companyreserve_spend_V8;
    pd_companyreserve_tip_V8_t companyreserve_tip_V8;
    pd_companyreserve_apply_as_V8_t companyreserve_apply_as_V8;
    pd_internationalreserve_spend_V8_t internationalreserve_spend_V8;
    pd_internationalreserve_tip_V8_t internationalreserve_tip_V8;
    pd_internationalreserve_apply_as_V8_t internationalreserve_apply_as_V8;
    pd_usareserve_spend_V8_t usareserve_spend_V8;
    pd_usareserve_tip_V8_t usareserve_tip_V8;
    pd_usareserve_apply_as_V8_t usareserve_apply_as_V8;
    pd_vesting_claim_V8_t vesting_claim_V8;
    pd_vesting_add_vesting_schedule_V8_t vesting_add_vesting_schedule_V8;
    pd_vesting_cancel_all_vesting_schedules_V8_t vesting_cancel_all_vesting_schedules_V8;
    pd_vesting_renounce_V8_t vesting_renounce_V8;
    pd_technicalcommittee_set_members_V8_t technicalcommittee_set_members_V8;
    pd_technicalcommittee_execute_V8_t technicalcommittee_execute_V8;
    pd_technicalcommittee_propose_V8_t technicalcommittee_propose_V8;
    pd_technicalcommittee_vote_V8_t technicalcommittee_vote_V8;
    pd_technicalcommittee_disapprove_proposal_V8_t technicalcommittee_disapprove_proposal_V8;
    pd_technicalcommittee_close_V8_t technicalcommittee_close_V8;
    pd_technicalmembership_add_member_V8_t technicalmembership_add_member_V8;
    pd_technicalmembership_remove_member_V8_t technicalmembership_remove_member_V8;
    pd_technicalmembership_swap_member_V8_t technicalmembership_swap_member_V8;
    pd_technicalmembership_reset_members_V8_t technicalmembership_reset_members_V8;
    pd_technicalmembership_change_key_V8_t technicalmembership_change_key_V8;
    pd_technicalmembership_set_prime_V8_t technicalmembership_set_prime_V8;
    pd_technicalmembership_clear_prime_V8_t technicalmembership_clear_prime_V8;
    pd_collatorselection_set_invulnerables_V8_t collatorselection_set_invulnerables_V8;
    pd_collatorselection_set_desired_candidates_V8_t collatorselection_set_desired_candidates_V8;
    pd_collatorselection_set_candidacy_bond_V8_t collatorselection_set_candidacy_bond_V8;
    pd_collatorselection_register_as_candidate_V8_t collatorselection_register_as_candidate_V8;
    pd_collatorselection_leave_intent_V8_t collatorselection_leave_intent_V8;
    pd_utility_with_weight_V8_t utility_with_weight_V8;
    pd_uniques_create_V8_t uniques_create_V8;
    pd_uniques_force_create_V8_t uniques_force_create_V8;
    pd_uniques_destroy_V8_t uniques_destroy_V8;
    pd_uniques_mint_V8_t uniques_mint_V8;
    pd_uniques_burn_V8_t uniques_burn_V8;
    pd_uniques_transfer_V8_t uniques_transfer_V8;
    pd_uniques_redeposit_V8_t uniques_redeposit_V8;
    pd_uniques_freeze_V8_t uniques_freeze_V8;
    pd_uniques_thaw_V8_t uniques_thaw_V8;
    pd_uniques_freeze_collection_V8_t uniques_freeze_collection_V8;
    pd_uniques_thaw_collection_V8_t uniques_thaw_collection_V8;
    pd_uniques_transfer_ownership_V8_t uniques_transfer_ownership_V8;
    pd_uniques_set_team_V8_t uniques_set_team_V8;
    pd_uniques_approve_transfer_V8_t uniques_approve_transfer_V8;
    pd_uniques_cancel_approval_V8_t uniques_cancel_approval_V8;
    pd_uniques_force_item_status_V8_t uniques_force_item_status_V8;
    pd_uniques_set_attribute_V8_t uniques_set_attribute_V8;
    pd_uniques_clear_attribute_V8_t uniques_clear_attribute_V8;
    pd_uniques_set_metadata_V8_t uniques_set_metadata_V8;
    pd_uniques_clear_metadata_V8_t uniques_clear_metadata_V8;
    pd_uniques_set_collection_metadata_V8_t uniques_set_collection_metadata_V8;
    pd_uniques_clear_collection_metadata_V8_t uniques_clear_collection_metadata_V8;
    pd_uniques_set_accept_ownership_V8_t uniques_set_accept_ownership_V8;
    pd_uniques_set_collection_max_supply_V8_t uniques_set_collection_max_supply_V8;
    pd_uniques_set_price_V8_t uniques_set_price_V8;
    pd_uniques_buy_item_V8_t uniques_buy_item_V8;
    pd_uniques_create_with_extra_deposit_limit_V8_t uniques_create_with_extra_deposit_limit_V8;
    pd_uniques_mint_with_extra_deposit_V8_t uniques_mint_with_extra_deposit_V8;
    pd_uniques_update_extra_deposit_limit_V8_t uniques_update_extra_deposit_limit_V8;
    pd_preimage_note_preimage_V8_t preimage_note_preimage_V8;
    pd_preimage_unnote_preimage_V8_t preimage_unnote_preimage_V8;
    pd_preimage_request_preimage_V8_t preimage_request_preimage_V8;
    pd_preimage_unrequest_preimage_V8_t preimage_unrequest_preimage_V8;
    pd_allocations_batch_V8_t allocations_batch_V8;
    pd_allocations_set_curve_starting_block_V8_t allocations_set_curve_starting_block_V8;
    pd_allocationsoracles_add_member_V8_t allocationsoracles_add_member_V8;
    pd_allocationsoracles_remove_member_V8_t allocationsoracles_remove_member_V8;
    pd_allocationsoracles_swap_member_V8_t allocationsoracles_swap_member_V8;
    pd_allocationsoracles_reset_members_V8_t allocationsoracles_reset_members_V8;
    pd_allocationsoracles_change_key_V8_t allocationsoracles_change_key_V8;
    pd_allocationsoracles_set_prime_V8_t allocationsoracles_set_prime_V8;
    pd_allocationsoracles_clear_prime_V8_t allocationsoracles_clear_prime_V8;
    pd_daoreserve_spend_V8_t daoreserve_spend_V8;
    pd_daoreserve_tip_V8_t daoreserve_tip_V8;
    pd_daoreserve_apply_as_V8_t daoreserve_apply_as_V8;
    pd_contracts_call_old_weight_V8_t contracts_call_old_weight_V8;
    pd_contracts_instantiate_with_code_old_weight_V8_t contracts_instantiate_with_code_old_weight_V8;
    pd_contracts_instantiate_old_weight_V8_t contracts_instantiate_old_weight_V8;
    pd_contracts_upload_code_V8_t contracts_upload_code_V8;
    pd_contracts_remove_code_V8_t contracts_remove_code_V8;
    pd_contracts_set_code_V8_t contracts_set_code_V8;
    pd_contracts_call_V8_t contracts_call_V8;
    pd_contracts_instantiate_with_code_V8_t contracts_instantiate_with_code_V8;
    pd_contracts_instantiate_V8_t contracts_instantiate_V8;
#endif
} pd_MethodBasic_V8_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V8 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V8_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V8 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V8_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V8 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V8_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V8 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V8_t;

#define PD_CALL_BALANCES_TRANSFER_V8 7
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V8_t;

#define PD_CALL_UTILITY_BATCH_V8 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V8_t;

#define PD_CALL_UTILITY_BATCH_ALL_V8 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V8_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V8 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V8_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V8 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V8_t;

#define PD_CALL_SYSTEM_SET_CODE_V8 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V8_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V8 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V8_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V8 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V8_t;

#define PD_CALL_BALANCES_SET_BALANCE_DEPRECATED_V8 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t old_reserved;
} pd_balances_set_balance_deprecated_V8_t;

#define PD_CALL_MANDATE_APPLY_V8 0
typedef struct {
    pd_Call_t call;
} pd_mandate_apply_V8_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V8 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V8_t;

#define PD_CALL_MULTISIG_AS_MULTI_V8 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V8_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V8 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V8_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V8 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V8_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V8_t balances_transfer_allow_death_V8;
    pd_balances_force_transfer_V8_t balances_force_transfer_V8;
    pd_balances_transfer_keep_alive_V8_t balances_transfer_keep_alive_V8;
    pd_balances_transfer_all_V8_t balances_transfer_all_V8;
    pd_balances_transfer_V8_t balances_transfer_V8;
    pd_utility_batch_V8_t utility_batch_V8;
    pd_utility_batch_all_V8_t utility_batch_all_V8;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V8_t system_remark_V8;
    pd_system_set_heap_pages_V8_t system_set_heap_pages_V8;
    pd_system_set_code_V8_t system_set_code_V8;
    pd_system_set_code_without_checks_V8_t system_set_code_without_checks_V8;
    pd_system_remark_with_event_V8_t system_remark_with_event_V8;
    pd_balances_set_balance_deprecated_V8_t balances_set_balance_deprecated_V8;
    pd_mandate_apply_V8_t mandate_apply_V8;
    pd_multisig_as_multi_threshold_1_V8_t multisig_as_multi_threshold_1_V8;
    pd_multisig_as_multi_V8_t multisig_as_multi_V8;
    pd_multisig_approve_as_multi_V8_t multisig_approve_as_multi_V8;
    pd_multisig_cancel_as_multi_V8_t multisig_cancel_as_multi_V8;
#endif
} pd_MethodNested_V8_t;

typedef union {
    pd_MethodBasic_V8_t basic;
    pd_MethodNested_V8_t nested;
} pd_Method_V8_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
