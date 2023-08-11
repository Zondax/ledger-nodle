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

#include "substrate_dispatch_V8.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V8(
    parser_context_t* c, pd_balances_transfer_allow_death_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V8(
    parser_context_t* c, pd_balances_force_transfer_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V8(
    parser_context_t* c, pd_balances_transfer_keep_alive_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V8(
    parser_context_t* c, pd_balances_transfer_all_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V8(
    parser_context_t* c, pd_balances_transfer_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V8(
    parser_context_t* c, pd_session_set_keys_V8_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V8(
    parser_context_t* c, pd_session_purge_keys_V8_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V8(
    parser_context_t* c, pd_utility_batch_V8_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V8(
    parser_context_t* c, pd_utility_batch_all_V8_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V8(
    parser_context_t* c, pd_utility_force_batch_V8_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_polkadotxcm_teleport_assets_V8(
    parser_context_t* c, pd_polkadotxcm_teleport_assets_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_reserve_transfer_assets_V8(
    parser_context_t* c, pd_polkadotxcm_reserve_transfer_assets_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_limited_reserve_transfer_assets_V8(
    parser_context_t* c, pd_polkadotxcm_limited_reserve_transfer_assets_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_limited_teleport_assets_V8(
    parser_context_t* c, pd_polkadotxcm_limited_teleport_assets_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_force_suspension_V8(
    parser_context_t* c, pd_polkadotxcm_force_suspension_V8_t* m)
{
    CHECK_ERROR(_readbool(c, &m->suspended))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xtokens_transfer_V8(
    parser_context_t* c, pd_xtokens_transfer_V8_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readWeightLimit(c, &m->dest_weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xtokens_transfer_multiasset_V8(
    parser_context_t* c, pd_xtokens_transfer_multiasset_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiAsset(c, &m->asset))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readWeightLimit(c, &m->dest_weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xtokens_transfer_with_fee_V8(
    parser_context_t* c, pd_xtokens_transfer_with_fee_V8_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBalance(c, &m->fee))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readWeightLimit(c, &m->dest_weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xtokens_transfer_multiasset_with_fee_V8(
    parser_context_t* c, pd_xtokens_transfer_multiasset_with_fee_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiAsset(c, &m->asset))
    CHECK_ERROR(_readBoxVersionedMultiAsset(c, &m->fee))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readWeightLimit(c, &m->dest_weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_xtokens_transfer_multiassets_V8(
    parser_context_t* c, pd_xtokens_transfer_multiassets_V8_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_item))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readWeightLimit(c, &m->dest_weight_limit))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V8(
    parser_context_t* c, pd_system_remark_V8_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V8(
    parser_context_t* c, pd_system_set_heap_pages_V8_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V8(
    parser_context_t* c, pd_system_set_code_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V8(
    parser_context_t* c, pd_system_set_code_without_checks_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V8(
    parser_context_t* c, pd_system_remark_with_event_V8_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_deprecated_V8(
    parser_context_t* c, pd_balances_set_balance_deprecated_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->old_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V8(
    parser_context_t* c, pd_balances_force_unreserve_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V8(
    parser_context_t* c, pd_balances_upgrade_accounts_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V8(
    parser_context_t* c, pd_balances_force_set_balance_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_companyreserve_spend_V8(
    parser_context_t* c, pd_companyreserve_spend_V8_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_companyreserve_tip_V8(
    parser_context_t* c, pd_companyreserve_tip_V8_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_companyreserve_apply_as_V8(
    parser_context_t* c, pd_companyreserve_apply_as_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_internationalreserve_spend_V8(
    parser_context_t* c, pd_internationalreserve_spend_V8_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_internationalreserve_tip_V8(
    parser_context_t* c, pd_internationalreserve_tip_V8_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_internationalreserve_apply_as_V8(
    parser_context_t* c, pd_internationalreserve_apply_as_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_usareserve_spend_V8(
    parser_context_t* c, pd_usareserve_spend_V8_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_usareserve_tip_V8(
    parser_context_t* c, pd_usareserve_tip_V8_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_usareserve_apply_as_V8(
    parser_context_t* c, pd_usareserve_apply_as_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_V8(
    parser_context_t* c, pd_vesting_claim_V8_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_add_vesting_schedule_V8(
    parser_context_t* c, pd_vesting_add_vesting_schedule_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->dest))
    CHECK_ERROR(_readVestingScheduleOf(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_cancel_all_vesting_schedules_V8(
    parser_context_t* c, pd_vesting_cancel_all_vesting_schedules_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->who))
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->funds_collector))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_renounce_V8(
    parser_context_t* c, pd_vesting_renounce_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_mandate_apply_V8(
    parser_context_t* c, pd_mandate_apply_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V8(
    parser_context_t* c, pd_technicalcommittee_set_members_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId(c, &m->prime))
    CHECK_ERROR(_readMemberCount(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V8(
    parser_context_t* c, pd_technicalcommittee_execute_V8_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V8(
    parser_context_t* c, pd_technicalcommittee_propose_V8_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V8(
    parser_context_t* c, pd_technicalcommittee_vote_V8_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V8(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V8_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V8(
    parser_context_t* c, pd_technicalcommittee_close_V8_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readWeight(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V8(
    parser_context_t* c, pd_technicalmembership_add_member_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V8(
    parser_context_t* c, pd_technicalmembership_remove_member_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V8(
    parser_context_t* c, pd_technicalmembership_swap_member_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->remove))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V8(
    parser_context_t* c, pd_technicalmembership_reset_members_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V8(
    parser_context_t* c, pd_technicalmembership_change_key_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V8(
    parser_context_t* c, pd_technicalmembership_set_prime_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V8(
    parser_context_t* c, pd_technicalmembership_clear_prime_V8_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_invulnerables_V8(
    parser_context_t* c, pd_collatorselection_set_invulnerables_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_desired_candidates_V8(
    parser_context_t* c, pd_collatorselection_set_desired_candidates_V8_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_candidacy_bond_V8(
    parser_context_t* c, pd_collatorselection_set_candidacy_bond_V8_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->bond))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_as_candidate_V8(
    parser_context_t* c, pd_collatorselection_register_as_candidate_V8_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_leave_intent_V8(
    parser_context_t* c, pd_collatorselection_leave_intent_V8_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V8(
    parser_context_t* c, pd_utility_with_weight_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V8(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V8(
    parser_context_t* c, pd_multisig_as_multi_V8_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V8(
    parser_context_t* c, pd_multisig_approve_as_multi_V8_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V8(
    parser_context_t* c, pd_multisig_cancel_as_multi_V8_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_create_V8(
    parser_context_t* c, pd_uniques_create_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_create_V8(
    parser_context_t* c, pd_uniques_force_create_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_destroy_V8(
    parser_context_t* c, pd_uniques_destroy_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readDestroyWitness(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_mint_V8(
    parser_context_t* c, pd_uniques_mint_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_burn_V8(
    parser_context_t* c, pd_uniques_burn_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->check_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_V8(
    parser_context_t* c, pd_uniques_transfer_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_redeposit_V8(
    parser_context_t* c, pd_uniques_redeposit_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readVecItemId(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_V8(
    parser_context_t* c, pd_uniques_freeze_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_V8(
    parser_context_t* c, pd_uniques_thaw_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_collection_V8(
    parser_context_t* c, pd_uniques_freeze_collection_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_collection_V8(
    parser_context_t* c, pd_uniques_thaw_collection_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_ownership_V8(
    parser_context_t* c, pd_uniques_transfer_ownership_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_team_V8(
    parser_context_t* c, pd_uniques_set_team_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_approve_transfer_V8(
    parser_context_t* c, pd_uniques_approve_transfer_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_cancel_approval_V8(
    parser_context_t* c, pd_uniques_cancel_approval_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->maybe_check_delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_item_status_V8(
    parser_context_t* c, pd_uniques_force_item_status_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_attribute_V8(
    parser_context_t* c, pd_uniques_set_attribute_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    CHECK_ERROR(_readBoundedVecu8(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_attribute_V8(
    parser_context_t* c, pd_uniques_clear_attribute_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_metadata_V8(
    parser_context_t* c, pd_uniques_set_metadata_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->data))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_metadata_V8(
    parser_context_t* c, pd_uniques_clear_metadata_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_collection_metadata_V8(
    parser_context_t* c, pd_uniques_set_collection_metadata_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readBoundedVecu8(c, &m->data))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_collection_metadata_V8(
    parser_context_t* c, pd_uniques_clear_collection_metadata_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_accept_ownership_V8(
    parser_context_t* c, pd_uniques_set_accept_ownership_V8_t* m)
{
    CHECK_ERROR(_readOptionCollectionId(c, &m->maybe_collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_collection_max_supply_V8(
    parser_context_t* c, pd_uniques_set_collection_max_supply_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readu32(c, &m->max_supply))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_price_V8(
    parser_context_t* c, pd_uniques_set_price_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionBalanceOf(c, &m->price))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->whitelisted_buyer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_buy_item_V8(
    parser_context_t* c, pd_uniques_buy_item_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readBalanceOf(c, &m->bid_price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_create_with_extra_deposit_limit_V8(
    parser_context_t* c, pd_uniques_create_with_extra_deposit_limit_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readBalanceOf(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_mint_with_extra_deposit_V8(
    parser_context_t* c, pd_uniques_mint_with_extra_deposit_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_update_extra_deposit_limit_V8(
    parser_context_t* c, pd_uniques_update_extra_deposit_limit_V8_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readBalanceOf(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V8(
    parser_context_t* c, pd_preimage_note_preimage_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V8(
    parser_context_t* c, pd_preimage_unnote_preimage_V8_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V8(
    parser_context_t* c, pd_preimage_request_preimage_V8_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V8(
    parser_context_t* c, pd_preimage_unrequest_preimage_V8_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocations_batch_V8(
    parser_context_t* c, pd_allocations_batch_V8_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdBalanceOf(c, &m->batch))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocations_set_curve_starting_block_V8(
    parser_context_t* c, pd_allocations_set_curve_starting_block_V8_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->curve_start))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_add_member_V8(
    parser_context_t* c, pd_allocationsoracles_add_member_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_remove_member_V8(
    parser_context_t* c, pd_allocationsoracles_remove_member_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_swap_member_V8(
    parser_context_t* c, pd_allocationsoracles_swap_member_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->remove))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_reset_members_V8(
    parser_context_t* c, pd_allocationsoracles_reset_members_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_change_key_V8(
    parser_context_t* c, pd_allocationsoracles_change_key_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_set_prime_V8(
    parser_context_t* c, pd_allocationsoracles_set_prime_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_clear_prime_V8(
    parser_context_t* c, pd_allocationsoracles_clear_prime_V8_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_daoreserve_spend_V8(
    parser_context_t* c, pd_daoreserve_spend_V8_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_daoreserve_tip_V8(
    parser_context_t* c, pd_daoreserve_tip_V8_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_daoreserve_apply_as_V8(
    parser_context_t* c, pd_daoreserve_apply_as_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_old_weight_V8(
    parser_context_t* c, pd_contracts_call_old_weight_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_old_weight_V8(
    parser_context_t* c, pd_contracts_instantiate_with_code_old_weight_V8_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_old_weight_V8(
    parser_context_t* c, pd_contracts_instantiate_old_weight_V8_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_upload_code_V8(
    parser_context_t* c, pd_contracts_upload_code_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readDeterminism(c, &m->determinism))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_remove_code_V8(
    parser_context_t* c, pd_contracts_remove_code_V8_t* m)
{
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_set_code_V8(
    parser_context_t* c, pd_contracts_set_code_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V8(
    parser_context_t* c, pd_contracts_call_V8_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_V8(
    parser_context_t* c, pd_contracts_instantiate_with_code_V8_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V8(
    parser_context_t* c, pd_contracts_instantiate_V8_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V8(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V8_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V8(c, &method->nested.balances_transfer_allow_death_V8))
        break;
    case 514: /* module 2 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V8(c, &method->nested.balances_force_transfer_V8))
        break;
    case 515: /* module 2 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V8(c, &method->nested.balances_transfer_keep_alive_V8))
        break;
    case 516: /* module 2 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V8(c, &method->nested.balances_transfer_all_V8))
        break;
    case 519: /* module 2 call 7 */
        CHECK_ERROR(_readMethod_balances_transfer_V8(c, &method->nested.balances_transfer_V8))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V8(c, &method->basic.session_set_keys_V8))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V8(c, &method->basic.session_purge_keys_V8))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V8(c, &method->nested.utility_batch_V8))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V8(c, &method->nested.utility_batch_all_V8))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V8(c, &method->basic.utility_force_batch_V8))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_polkadotxcm_teleport_assets_V8(c, &method->basic.polkadotxcm_teleport_assets_V8))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_polkadotxcm_reserve_transfer_assets_V8(c, &method->basic.polkadotxcm_reserve_transfer_assets_V8))
        break;
    case 8968: /* module 35 call 8 */
        CHECK_ERROR(_readMethod_polkadotxcm_limited_reserve_transfer_assets_V8(c, &method->basic.polkadotxcm_limited_reserve_transfer_assets_V8))
        break;
    case 8969: /* module 35 call 9 */
        CHECK_ERROR(_readMethod_polkadotxcm_limited_teleport_assets_V8(c, &method->basic.polkadotxcm_limited_teleport_assets_V8))
        break;
    case 8970: /* module 35 call 10 */
        CHECK_ERROR(_readMethod_polkadotxcm_force_suspension_V8(c, &method->basic.polkadotxcm_force_suspension_V8))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_xtokens_transfer_V8(c, &method->basic.xtokens_transfer_V8))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_xtokens_transfer_multiasset_V8(c, &method->basic.xtokens_transfer_multiasset_V8))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_xtokens_transfer_with_fee_V8(c, &method->basic.xtokens_transfer_with_fee_V8))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_xtokens_transfer_multiasset_with_fee_V8(c, &method->basic.xtokens_transfer_multiasset_with_fee_V8))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_xtokens_transfer_multiassets_V8(c, &method->basic.xtokens_transfer_multiassets_V8))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V8(c, &method->nested.system_remark_V8))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V8(c, &method->nested.system_set_heap_pages_V8))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V8(c, &method->nested.system_set_code_V8))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V8(c, &method->nested.system_set_code_without_checks_V8))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V8(c, &method->nested.system_remark_with_event_V8))
        break;
    case 513: /* module 2 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_deprecated_V8(c, &method->nested.balances_set_balance_deprecated_V8))
        break;
    case 517: /* module 2 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V8(c, &method->basic.balances_force_unreserve_V8))
        break;
    case 518: /* module 2 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V8(c, &method->basic.balances_upgrade_accounts_V8))
        break;
    case 520: /* module 2 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V8(c, &method->basic.balances_force_set_balance_V8))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_companyreserve_spend_V8(c, &method->basic.companyreserve_spend_V8))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_companyreserve_tip_V8(c, &method->basic.companyreserve_tip_V8))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_companyreserve_apply_as_V8(c, &method->basic.companyreserve_apply_as_V8))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_internationalreserve_spend_V8(c, &method->basic.internationalreserve_spend_V8))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_internationalreserve_tip_V8(c, &method->basic.internationalreserve_tip_V8))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_internationalreserve_apply_as_V8(c, &method->basic.internationalreserve_apply_as_V8))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_usareserve_spend_V8(c, &method->basic.usareserve_spend_V8))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_usareserve_tip_V8(c, &method->basic.usareserve_tip_V8))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_usareserve_apply_as_V8(c, &method->basic.usareserve_apply_as_V8))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_vesting_claim_V8(c, &method->basic.vesting_claim_V8))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_vesting_add_vesting_schedule_V8(c, &method->basic.vesting_add_vesting_schedule_V8))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_vesting_cancel_all_vesting_schedules_V8(c, &method->basic.vesting_cancel_all_vesting_schedules_V8))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_vesting_renounce_V8(c, &method->basic.vesting_renounce_V8))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_mandate_apply_V8(c, &method->nested.mandate_apply_V8))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V8(c, &method->basic.technicalcommittee_set_members_V8))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V8(c, &method->basic.technicalcommittee_execute_V8))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V8(c, &method->basic.technicalcommittee_propose_V8))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V8(c, &method->basic.technicalcommittee_vote_V8))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V8(c, &method->basic.technicalcommittee_disapprove_proposal_V8))
        break;
    case 4102: /* module 16 call 6 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V8(c, &method->basic.technicalcommittee_close_V8))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V8(c, &method->basic.technicalmembership_add_member_V8))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V8(c, &method->basic.technicalmembership_remove_member_V8))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V8(c, &method->basic.technicalmembership_swap_member_V8))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V8(c, &method->basic.technicalmembership_reset_members_V8))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V8(c, &method->basic.technicalmembership_change_key_V8))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V8(c, &method->basic.technicalmembership_set_prime_V8))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V8(c, &method->basic.technicalmembership_clear_prime_V8))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_collatorselection_set_invulnerables_V8(c, &method->basic.collatorselection_set_invulnerables_V8))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_collatorselection_set_desired_candidates_V8(c, &method->basic.collatorselection_set_desired_candidates_V8))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_collatorselection_set_candidacy_bond_V8(c, &method->basic.collatorselection_set_candidacy_bond_V8))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_collatorselection_register_as_candidate_V8(c, &method->basic.collatorselection_register_as_candidate_V8))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_collatorselection_leave_intent_V8(c, &method->basic.collatorselection_leave_intent_V8))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V8(c, &method->basic.utility_with_weight_V8))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V8(c, &method->nested.multisig_as_multi_threshold_1_V8))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V8(c, &method->nested.multisig_as_multi_V8))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V8(c, &method->nested.multisig_approve_as_multi_V8))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V8(c, &method->nested.multisig_cancel_as_multi_V8))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_uniques_create_V8(c, &method->basic.uniques_create_V8))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_uniques_force_create_V8(c, &method->basic.uniques_force_create_V8))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_uniques_destroy_V8(c, &method->basic.uniques_destroy_V8))
        break;
    case 10755: /* module 42 call 3 */
        CHECK_ERROR(_readMethod_uniques_mint_V8(c, &method->basic.uniques_mint_V8))
        break;
    case 10756: /* module 42 call 4 */
        CHECK_ERROR(_readMethod_uniques_burn_V8(c, &method->basic.uniques_burn_V8))
        break;
    case 10757: /* module 42 call 5 */
        CHECK_ERROR(_readMethod_uniques_transfer_V8(c, &method->basic.uniques_transfer_V8))
        break;
    case 10758: /* module 42 call 6 */
        CHECK_ERROR(_readMethod_uniques_redeposit_V8(c, &method->basic.uniques_redeposit_V8))
        break;
    case 10759: /* module 42 call 7 */
        CHECK_ERROR(_readMethod_uniques_freeze_V8(c, &method->basic.uniques_freeze_V8))
        break;
    case 10760: /* module 42 call 8 */
        CHECK_ERROR(_readMethod_uniques_thaw_V8(c, &method->basic.uniques_thaw_V8))
        break;
    case 10761: /* module 42 call 9 */
        CHECK_ERROR(_readMethod_uniques_freeze_collection_V8(c, &method->basic.uniques_freeze_collection_V8))
        break;
    case 10762: /* module 42 call 10 */
        CHECK_ERROR(_readMethod_uniques_thaw_collection_V8(c, &method->basic.uniques_thaw_collection_V8))
        break;
    case 10763: /* module 42 call 11 */
        CHECK_ERROR(_readMethod_uniques_transfer_ownership_V8(c, &method->basic.uniques_transfer_ownership_V8))
        break;
    case 10764: /* module 42 call 12 */
        CHECK_ERROR(_readMethod_uniques_set_team_V8(c, &method->basic.uniques_set_team_V8))
        break;
    case 10765: /* module 42 call 13 */
        CHECK_ERROR(_readMethod_uniques_approve_transfer_V8(c, &method->basic.uniques_approve_transfer_V8))
        break;
    case 10766: /* module 42 call 14 */
        CHECK_ERROR(_readMethod_uniques_cancel_approval_V8(c, &method->basic.uniques_cancel_approval_V8))
        break;
    case 10767: /* module 42 call 15 */
        CHECK_ERROR(_readMethod_uniques_force_item_status_V8(c, &method->basic.uniques_force_item_status_V8))
        break;
    case 10768: /* module 42 call 16 */
        CHECK_ERROR(_readMethod_uniques_set_attribute_V8(c, &method->basic.uniques_set_attribute_V8))
        break;
    case 10769: /* module 42 call 17 */
        CHECK_ERROR(_readMethod_uniques_clear_attribute_V8(c, &method->basic.uniques_clear_attribute_V8))
        break;
    case 10770: /* module 42 call 18 */
        CHECK_ERROR(_readMethod_uniques_set_metadata_V8(c, &method->basic.uniques_set_metadata_V8))
        break;
    case 10771: /* module 42 call 19 */
        CHECK_ERROR(_readMethod_uniques_clear_metadata_V8(c, &method->basic.uniques_clear_metadata_V8))
        break;
    case 10772: /* module 42 call 20 */
        CHECK_ERROR(_readMethod_uniques_set_collection_metadata_V8(c, &method->basic.uniques_set_collection_metadata_V8))
        break;
    case 10773: /* module 42 call 21 */
        CHECK_ERROR(_readMethod_uniques_clear_collection_metadata_V8(c, &method->basic.uniques_clear_collection_metadata_V8))
        break;
    case 10774: /* module 42 call 22 */
        CHECK_ERROR(_readMethod_uniques_set_accept_ownership_V8(c, &method->basic.uniques_set_accept_ownership_V8))
        break;
    case 10775: /* module 42 call 23 */
        CHECK_ERROR(_readMethod_uniques_set_collection_max_supply_V8(c, &method->basic.uniques_set_collection_max_supply_V8))
        break;
    case 10776: /* module 42 call 24 */
        CHECK_ERROR(_readMethod_uniques_set_price_V8(c, &method->basic.uniques_set_price_V8))
        break;
    case 10777: /* module 42 call 25 */
        CHECK_ERROR(_readMethod_uniques_buy_item_V8(c, &method->basic.uniques_buy_item_V8))
        break;
    case 10778: /* module 42 call 26 */
        CHECK_ERROR(_readMethod_uniques_create_with_extra_deposit_limit_V8(c, &method->basic.uniques_create_with_extra_deposit_limit_V8))
        break;
    case 10779: /* module 42 call 27 */
        CHECK_ERROR(_readMethod_uniques_mint_with_extra_deposit_V8(c, &method->basic.uniques_mint_with_extra_deposit_V8))
        break;
    case 10780: /* module 42 call 28 */
        CHECK_ERROR(_readMethod_uniques_update_extra_deposit_limit_V8(c, &method->basic.uniques_update_extra_deposit_limit_V8))
        break;
    case 11008: /* module 43 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V8(c, &method->basic.preimage_note_preimage_V8))
        break;
    case 11009: /* module 43 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V8(c, &method->basic.preimage_unnote_preimage_V8))
        break;
    case 11010: /* module 43 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V8(c, &method->basic.preimage_request_preimage_V8))
        break;
    case 11011: /* module 43 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V8(c, &method->basic.preimage_unrequest_preimage_V8))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_allocations_batch_V8(c, &method->basic.allocations_batch_V8))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_allocations_set_curve_starting_block_V8(c, &method->basic.allocations_set_curve_starting_block_V8))
        break;
    case 13312: /* module 52 call 0 */
        CHECK_ERROR(_readMethod_allocationsoracles_add_member_V8(c, &method->basic.allocationsoracles_add_member_V8))
        break;
    case 13313: /* module 52 call 1 */
        CHECK_ERROR(_readMethod_allocationsoracles_remove_member_V8(c, &method->basic.allocationsoracles_remove_member_V8))
        break;
    case 13314: /* module 52 call 2 */
        CHECK_ERROR(_readMethod_allocationsoracles_swap_member_V8(c, &method->basic.allocationsoracles_swap_member_V8))
        break;
    case 13315: /* module 52 call 3 */
        CHECK_ERROR(_readMethod_allocationsoracles_reset_members_V8(c, &method->basic.allocationsoracles_reset_members_V8))
        break;
    case 13316: /* module 52 call 4 */
        CHECK_ERROR(_readMethod_allocationsoracles_change_key_V8(c, &method->basic.allocationsoracles_change_key_V8))
        break;
    case 13317: /* module 52 call 5 */
        CHECK_ERROR(_readMethod_allocationsoracles_set_prime_V8(c, &method->basic.allocationsoracles_set_prime_V8))
        break;
    case 13318: /* module 52 call 6 */
        CHECK_ERROR(_readMethod_allocationsoracles_clear_prime_V8(c, &method->basic.allocationsoracles_clear_prime_V8))
        break;
    case 15360: /* module 60 call 0 */
        CHECK_ERROR(_readMethod_daoreserve_spend_V8(c, &method->basic.daoreserve_spend_V8))
        break;
    case 15361: /* module 60 call 1 */
        CHECK_ERROR(_readMethod_daoreserve_tip_V8(c, &method->basic.daoreserve_tip_V8))
        break;
    case 15362: /* module 60 call 2 */
        CHECK_ERROR(_readMethod_daoreserve_apply_as_V8(c, &method->basic.daoreserve_apply_as_V8))
        break;
    case 15872: /* module 62 call 0 */
        CHECK_ERROR(_readMethod_contracts_call_old_weight_V8(c, &method->basic.contracts_call_old_weight_V8))
        break;
    case 15873: /* module 62 call 1 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_old_weight_V8(c, &method->basic.contracts_instantiate_with_code_old_weight_V8))
        break;
    case 15874: /* module 62 call 2 */
        CHECK_ERROR(_readMethod_contracts_instantiate_old_weight_V8(c, &method->basic.contracts_instantiate_old_weight_V8))
        break;
    case 15875: /* module 62 call 3 */
        CHECK_ERROR(_readMethod_contracts_upload_code_V8(c, &method->basic.contracts_upload_code_V8))
        break;
    case 15876: /* module 62 call 4 */
        CHECK_ERROR(_readMethod_contracts_remove_code_V8(c, &method->basic.contracts_remove_code_V8))
        break;
    case 15877: /* module 62 call 5 */
        CHECK_ERROR(_readMethod_contracts_set_code_V8(c, &method->basic.contracts_set_code_V8))
        break;
    case 15878: /* module 62 call 6 */
        CHECK_ERROR(_readMethod_contracts_call_V8(c, &method->basic.contracts_call_V8))
        break;
    case 15879: /* module 62 call 7 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_V8(c, &method->basic.contracts_instantiate_with_code_V8))
        break;
    case 15880: /* module 62 call 8 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V8(c, &method->basic.contracts_instantiate_V8))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V8(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 2:
        return STR_MO_BALANCES;
    case 23:
        return STR_MO_SESSION;
    case 40:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 35:
        return STR_MO_POLKADOTXCM;
    case 36:
        return STR_MO_XTOKENS;
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 11:
        return STR_MO_COMPANYRESERVE;
    case 12:
        return STR_MO_INTERNATIONALRESERVE;
    case 13:
        return STR_MO_USARESERVE;
    case 14:
        return STR_MO_VESTING;
    case 15:
        return STR_MO_MANDATE;
    case 16:
        return STR_MO_TECHNICALCOMMITTEE;
    case 17:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 19:
        return STR_MO_COLLATORSELECTION;
    case 41:
        return STR_MO_MULTISIG;
    case 42:
        return STR_MO_UNIQUES;
    case 43:
        return STR_MO_PREIMAGE;
    case 51:
        return STR_MO_ALLOCATIONS;
    case 52:
        return STR_MO_ALLOCATIONSORACLES;
    case 60:
        return STR_MO_DAORESERVE;
    case 62:
        return STR_MO_CONTRACTS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V8(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 514: /* module 2 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 515: /* module 2 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 516: /* module 2 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 519: /* module 2 call 7 */
        return STR_ME_TRANSFER;
    case 5888: /* module 23 call 0 */
        return STR_ME_SET_KEYS;
    case 5889: /* module 23 call 1 */
        return STR_ME_PURGE_KEYS;
    case 10240: /* module 40 call 0 */
        return STR_ME_BATCH;
    case 10242: /* module 40 call 2 */
        return STR_ME_BATCH_ALL;
    case 10244: /* module 40 call 4 */
        return STR_ME_FORCE_BATCH;
    default:
        return _getMethod_Name_V8_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V8_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 8961: /* module 35 call 1 */
        return STR_ME_TELEPORT_ASSETS;
    case 8962: /* module 35 call 2 */
        return STR_ME_RESERVE_TRANSFER_ASSETS;
    case 8968: /* module 35 call 8 */
        return STR_ME_LIMITED_RESERVE_TRANSFER_ASSETS;
    case 8969: /* module 35 call 9 */
        return STR_ME_LIMITED_TELEPORT_ASSETS;
    case 8970: /* module 35 call 10 */
        return STR_ME_FORCE_SUSPENSION;
    case 9216: /* module 36 call 0 */
        return STR_ME_TRANSFER;
    case 9217: /* module 36 call 1 */
        return STR_ME_TRANSFER_MULTIASSET;
    case 9218: /* module 36 call 2 */
        return STR_ME_TRANSFER_WITH_FEE;
    case 9219: /* module 36 call 3 */
        return STR_ME_TRANSFER_MULTIASSET_WITH_FEE;
    case 9221: /* module 36 call 5 */
        return STR_ME_TRANSFER_MULTIASSETS;
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 513: /* module 2 call 1 */
        return STR_ME_SET_BALANCE_DEPRECATED;
    case 517: /* module 2 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 518: /* module 2 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 520: /* module 2 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
    case 2816: /* module 11 call 0 */
        return STR_ME_SPEND;
    case 2817: /* module 11 call 1 */
        return STR_ME_TIP;
    case 2818: /* module 11 call 2 */
        return STR_ME_APPLY_AS;
    case 3072: /* module 12 call 0 */
        return STR_ME_SPEND;
    case 3073: /* module 12 call 1 */
        return STR_ME_TIP;
    case 3074: /* module 12 call 2 */
        return STR_ME_APPLY_AS;
    case 3328: /* module 13 call 0 */
        return STR_ME_SPEND;
    case 3329: /* module 13 call 1 */
        return STR_ME_TIP;
    case 3330: /* module 13 call 2 */
        return STR_ME_APPLY_AS;
    case 3584: /* module 14 call 0 */
        return STR_ME_CLAIM;
    case 3585: /* module 14 call 1 */
        return STR_ME_ADD_VESTING_SCHEDULE;
    case 3586: /* module 14 call 2 */
        return STR_ME_CANCEL_ALL_VESTING_SCHEDULES;
    case 3587: /* module 14 call 3 */
        return STR_ME_RENOUNCE;
    case 3840: /* module 15 call 0 */
        return STR_ME_APPLY;
    case 4096: /* module 16 call 0 */
        return STR_ME_SET_MEMBERS;
    case 4097: /* module 16 call 1 */
        return STR_ME_EXECUTE;
    case 4098: /* module 16 call 2 */
        return STR_ME_PROPOSE;
    case 4099: /* module 16 call 3 */
        return STR_ME_VOTE;
    case 4101: /* module 16 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4102: /* module 16 call 6 */
        return STR_ME_CLOSE;
    case 4352: /* module 17 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4353: /* module 17 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4354: /* module 17 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4355: /* module 17 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4356: /* module 17 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4357: /* module 17 call 5 */
        return STR_ME_SET_PRIME;
    case 4358: /* module 17 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4864: /* module 19 call 0 */
        return STR_ME_SET_INVULNERABLES;
    case 4865: /* module 19 call 1 */
        return STR_ME_SET_DESIRED_CANDIDATES;
    case 4866: /* module 19 call 2 */
        return STR_ME_SET_CANDIDACY_BOND;
    case 4867: /* module 19 call 3 */
        return STR_ME_REGISTER_AS_CANDIDATE;
    case 4868: /* module 19 call 4 */
        return STR_ME_LEAVE_INTENT;
    case 10245: /* module 40 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 10496: /* module 41 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 10497: /* module 41 call 1 */
        return STR_ME_AS_MULTI;
    case 10498: /* module 41 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 10499: /* module 41 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 10752: /* module 42 call 0 */
        return STR_ME_CREATE;
    case 10753: /* module 42 call 1 */
        return STR_ME_FORCE_CREATE;
    case 10754: /* module 42 call 2 */
        return STR_ME_DESTROY;
    case 10755: /* module 42 call 3 */
        return STR_ME_MINT;
    case 10756: /* module 42 call 4 */
        return STR_ME_BURN;
    case 10757: /* module 42 call 5 */
        return STR_ME_TRANSFER;
    case 10758: /* module 42 call 6 */
        return STR_ME_REDEPOSIT;
    case 10759: /* module 42 call 7 */
        return STR_ME_FREEZE;
    case 10760: /* module 42 call 8 */
        return STR_ME_THAW;
    case 10761: /* module 42 call 9 */
        return STR_ME_FREEZE_COLLECTION;
    case 10762: /* module 42 call 10 */
        return STR_ME_THAW_COLLECTION;
    case 10763: /* module 42 call 11 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 10764: /* module 42 call 12 */
        return STR_ME_SET_TEAM;
    case 10765: /* module 42 call 13 */
        return STR_ME_APPROVE_TRANSFER;
    case 10766: /* module 42 call 14 */
        return STR_ME_CANCEL_APPROVAL;
    case 10767: /* module 42 call 15 */
        return STR_ME_FORCE_ITEM_STATUS;
    case 10768: /* module 42 call 16 */
        return STR_ME_SET_ATTRIBUTE;
    case 10769: /* module 42 call 17 */
        return STR_ME_CLEAR_ATTRIBUTE;
    case 10770: /* module 42 call 18 */
        return STR_ME_SET_METADATA;
    case 10771: /* module 42 call 19 */
        return STR_ME_CLEAR_METADATA;
    case 10772: /* module 42 call 20 */
        return STR_ME_SET_COLLECTION_METADATA;
    case 10773: /* module 42 call 21 */
        return STR_ME_CLEAR_COLLECTION_METADATA;
    case 10774: /* module 42 call 22 */
        return STR_ME_SET_ACCEPT_OWNERSHIP;
    case 10775: /* module 42 call 23 */
        return STR_ME_SET_COLLECTION_MAX_SUPPLY;
    case 10776: /* module 42 call 24 */
        return STR_ME_SET_PRICE;
    case 10777: /* module 42 call 25 */
        return STR_ME_BUY_ITEM;
    case 10778: /* module 42 call 26 */
        return STR_ME_CREATE_WITH_EXTRA_DEPOSIT_LIMIT;
    case 10779: /* module 42 call 27 */
        return STR_ME_MINT_WITH_EXTRA_DEPOSIT;
    case 10780: /* module 42 call 28 */
        return STR_ME_UPDATE_EXTRA_DEPOSIT_LIMIT;
    case 11008: /* module 43 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 11009: /* module 43 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 11010: /* module 43 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 11011: /* module 43 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 13056: /* module 51 call 0 */
        return STR_ME_BATCH;
    case 13057: /* module 51 call 1 */
        return STR_ME_SET_CURVE_STARTING_BLOCK;
    case 13312: /* module 52 call 0 */
        return STR_ME_ADD_MEMBER;
    case 13313: /* module 52 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 13314: /* module 52 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 13315: /* module 52 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 13316: /* module 52 call 4 */
        return STR_ME_CHANGE_KEY;
    case 13317: /* module 52 call 5 */
        return STR_ME_SET_PRIME;
    case 13318: /* module 52 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 15360: /* module 60 call 0 */
        return STR_ME_SPEND;
    case 15361: /* module 60 call 1 */
        return STR_ME_TIP;
    case 15362: /* module 60 call 2 */
        return STR_ME_APPLY_AS;
    case 15872: /* module 62 call 0 */
        return STR_ME_CALL_OLD_WEIGHT;
    case 15873: /* module 62 call 1 */
        return STR_ME_INSTANTIATE_WITH_CODE_OLD_WEIGHT;
    case 15874: /* module 62 call 2 */
        return STR_ME_INSTANTIATE_OLD_WEIGHT;
    case 15875: /* module 62 call 3 */
        return STR_ME_UPLOAD_CODE;
    case 15876: /* module 62 call 4 */
        return STR_ME_REMOVE_CODE;
    case 15877: /* module 62 call 5 */
        return STR_ME_SET_CODE;
    case 15878: /* module 62 call 6 */
        return STR_ME_CALL;
    case 15879: /* module 62 call 7 */
        return STR_ME_INSTANTIATE_WITH_CODE;
    case 15880: /* module 62 call 8 */
        return STR_ME_INSTANTIATE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V8(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return 2;
    case 514: /* module 2 call 2 */
        return 3;
    case 515: /* module 2 call 3 */
        return 2;
    case 516: /* module 2 call 4 */
        return 2;
    case 519: /* module 2 call 7 */
        return 2;
    case 5888: /* module 23 call 0 */
        return 2;
    case 5889: /* module 23 call 1 */
        return 0;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10242: /* module 40 call 2 */
        return 1;
    case 10244: /* module 40 call 4 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 8961: /* module 35 call 1 */
        return 4;
    case 8962: /* module 35 call 2 */
        return 4;
    case 8968: /* module 35 call 8 */
        return 5;
    case 8969: /* module 35 call 9 */
        return 5;
    case 8970: /* module 35 call 10 */
        return 1;
    case 9216: /* module 36 call 0 */
        return 4;
    case 9217: /* module 36 call 1 */
        return 3;
    case 9218: /* module 36 call 2 */
        return 5;
    case 9219: /* module 36 call 3 */
        return 4;
    case 9221: /* module 36 call 5 */
        return 4;
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 513: /* module 2 call 1 */
        return 3;
    case 517: /* module 2 call 5 */
        return 2;
    case 518: /* module 2 call 6 */
        return 1;
    case 520: /* module 2 call 8 */
        return 2;
    case 2816: /* module 11 call 0 */
        return 2;
    case 2817: /* module 11 call 1 */
        return 1;
    case 2818: /* module 11 call 2 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 1;
    case 3074: /* module 12 call 2 */
        return 1;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 1;
    case 3330: /* module 13 call 2 */
        return 1;
    case 3584: /* module 14 call 0 */
        return 0;
    case 3585: /* module 14 call 1 */
        return 2;
    case 3586: /* module 14 call 2 */
        return 2;
    case 3587: /* module 14 call 3 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 3;
    case 4097: /* module 16 call 1 */
        return 2;
    case 4098: /* module 16 call 2 */
        return 3;
    case 4099: /* module 16 call 3 */
        return 3;
    case 4101: /* module 16 call 5 */
        return 1;
    case 4102: /* module 16 call 6 */
        return 4;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 2;
    case 4355: /* module 17 call 3 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 1;
    case 4357: /* module 17 call 5 */
        return 1;
    case 4358: /* module 17 call 6 */
        return 0;
    case 4864: /* module 19 call 0 */
        return 1;
    case 4865: /* module 19 call 1 */
        return 1;
    case 4866: /* module 19 call 2 */
        return 1;
    case 4867: /* module 19 call 3 */
        return 0;
    case 4868: /* module 19 call 4 */
        return 0;
    case 10245: /* module 40 call 5 */
        return 2;
    case 10496: /* module 41 call 0 */
        return 2;
    case 10497: /* module 41 call 1 */
        return 5;
    case 10498: /* module 41 call 2 */
        return 5;
    case 10499: /* module 41 call 3 */
        return 4;
    case 10752: /* module 42 call 0 */
        return 2;
    case 10753: /* module 42 call 1 */
        return 3;
    case 10754: /* module 42 call 2 */
        return 2;
    case 10755: /* module 42 call 3 */
        return 3;
    case 10756: /* module 42 call 4 */
        return 3;
    case 10757: /* module 42 call 5 */
        return 3;
    case 10758: /* module 42 call 6 */
        return 2;
    case 10759: /* module 42 call 7 */
        return 2;
    case 10760: /* module 42 call 8 */
        return 2;
    case 10761: /* module 42 call 9 */
        return 1;
    case 10762: /* module 42 call 10 */
        return 1;
    case 10763: /* module 42 call 11 */
        return 2;
    case 10764: /* module 42 call 12 */
        return 4;
    case 10765: /* module 42 call 13 */
        return 3;
    case 10766: /* module 42 call 14 */
        return 3;
    case 10767: /* module 42 call 15 */
        return 7;
    case 10768: /* module 42 call 16 */
        return 4;
    case 10769: /* module 42 call 17 */
        return 3;
    case 10770: /* module 42 call 18 */
        return 4;
    case 10771: /* module 42 call 19 */
        return 2;
    case 10772: /* module 42 call 20 */
        return 3;
    case 10773: /* module 42 call 21 */
        return 1;
    case 10774: /* module 42 call 22 */
        return 1;
    case 10775: /* module 42 call 23 */
        return 2;
    case 10776: /* module 42 call 24 */
        return 4;
    case 10777: /* module 42 call 25 */
        return 3;
    case 10778: /* module 42 call 26 */
        return 3;
    case 10779: /* module 42 call 27 */
        return 4;
    case 10780: /* module 42 call 28 */
        return 2;
    case 11008: /* module 43 call 0 */
        return 1;
    case 11009: /* module 43 call 1 */
        return 1;
    case 11010: /* module 43 call 2 */
        return 1;
    case 11011: /* module 43 call 3 */
        return 1;
    case 13056: /* module 51 call 0 */
        return 1;
    case 13057: /* module 51 call 1 */
        return 1;
    case 13312: /* module 52 call 0 */
        return 1;
    case 13313: /* module 52 call 1 */
        return 1;
    case 13314: /* module 52 call 2 */
        return 2;
    case 13315: /* module 52 call 3 */
        return 1;
    case 13316: /* module 52 call 4 */
        return 1;
    case 13317: /* module 52 call 5 */
        return 1;
    case 13318: /* module 52 call 6 */
        return 0;
    case 15360: /* module 60 call 0 */
        return 2;
    case 15361: /* module 60 call 1 */
        return 1;
    case 15362: /* module 60 call 2 */
        return 1;
    case 15872: /* module 62 call 0 */
        return 5;
    case 15873: /* module 62 call 1 */
        return 6;
    case 15874: /* module 62 call 2 */
        return 6;
    case 15875: /* module 62 call 3 */
        return 3;
    case 15876: /* module 62 call 4 */
        return 1;
    case 15877: /* module 62 call 5 */
        return 2;
    case 15878: /* module 62 call 6 */
        return 5;
    case 15879: /* module 62 call 7 */
        return 6;
    case 15880: /* module 62 call 8 */
        return 6;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V8(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 514: /* module 2 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 515: /* module 2 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 516: /* module 2 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 519: /* module 2 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 8969: /* module 35 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 8970: /* module 35 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_suspended;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_dest_weight_limit;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_dest_weight_limit;
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_fee;
        case 3:
            return STR_IT_dest;
        case 4:
            return STR_IT_dest_weight_limit;
        default:
            return NULL;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset;
        case 1:
            return STR_IT_fee;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_dest_weight_limit;
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_assets;
        case 1:
            return STR_IT_fee_item;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_dest_weight_limit;
        default:
            return NULL;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_old_reserved;
        default:
            return NULL;
        }
    case 517: /* module 2 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 518: /* module 2 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 520: /* module 2 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_funds_collector;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bond;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_admin;
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_free_holding;
        default:
            return NULL;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_witness;
        default:
            return NULL;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 10756: /* module 42 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_check_owner;
        default:
            return NULL;
        }
    case 10757: /* module 42 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 10758: /* module 42 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 10759: /* module 42 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 10760: /* module 42 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 10761: /* module 42 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 10762: /* module 42 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 10763: /* module 42 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 10764: /* module 42 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 10765: /* module 42 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 10766: /* module 42 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_maybe_check_delegate;
        default:
            return NULL;
        }
    case 10767: /* module 42 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_free_holding;
        case 6:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 10768: /* module 42 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_maybe_item;
        case 2:
            return STR_IT_key;
        case 3:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 10769: /* module 42 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_maybe_item;
        case 2:
            return STR_IT_key;
        default:
            return NULL;
        }
    case 10770: /* module 42 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_data;
        case 3:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 10771: /* module 42 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 10772: /* module 42 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_data;
        case 2:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 10773: /* module 42 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 10774: /* module 42 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_collection;
        default:
            return NULL;
        }
    case 10775: /* module 42 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_max_supply;
        default:
            return NULL;
        }
    case 10776: /* module 42 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_price;
        case 3:
            return STR_IT_whitelisted_buyer;
        default:
            return NULL;
        }
    case 10777: /* module 42 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_bid_price;
        default:
            return NULL;
        }
    case 10778: /* module 42 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_admin;
        case 2:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 10779: /* module 42 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_owner;
        case 3:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 10780: /* module 42 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 11009: /* module 43 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 11010: /* module 43 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 11011: /* module 43 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_batch;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_curve_start;
        default:
            return NULL;
        }
    case 13312: /* module 52 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13313: /* module 52 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13314: /* module 52 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 13315: /* module 52 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13317: /* module 52 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13318: /* module 52 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_deposit_limit;
        case 4:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 15873: /* module 62 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 15874: /* module 62 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 15875: /* module 62 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        case 1:
            return STR_IT_storage_deposit_limit;
        case 2:
            return STR_IT_determinism;
        default:
            return NULL;
        }
    case 15876: /* module 62 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 15877: /* module 62 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 15878: /* module 62 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_deposit_limit;
        case 4:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 15879: /* module 62 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 15880: /* module 62 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V8(
    pd_Method_V8_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 514: /* module 2 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V8 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V8.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 515: /* module 2 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 516: /* module 2 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V8 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V8.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 519: /* module 2 call 7 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V8 - keys */;
            return _toStringKeys(
                &m->basic.session_set_keys_V8.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V8 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V8.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V8 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_V8.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V8 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_all_V8.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V8 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V8.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_teleport_assets_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_teleport_assets_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_teleport_assets_V8 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_teleport_assets_V8.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_teleport_assets_V8 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_teleport_assets_V8.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_teleport_assets_V8 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_teleport_assets_V8.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_reserve_transfer_assets_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_reserve_transfer_assets_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_reserve_transfer_assets_V8 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_reserve_transfer_assets_V8.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_reserve_transfer_assets_V8 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_reserve_transfer_assets_V8.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_reserve_transfer_assets_V8 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_reserve_transfer_assets_V8.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_limited_reserve_transfer_assets_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_limited_reserve_transfer_assets_V8 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V8.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_limited_reserve_transfer_assets_V8 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V8.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_limited_reserve_transfer_assets_V8 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V8.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polkadotxcm_limited_reserve_transfer_assets_V8 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V8.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8969: /* module 35 call 9 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_limited_teleport_assets_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_teleport_assets_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_limited_teleport_assets_V8 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_teleport_assets_V8.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_limited_teleport_assets_V8 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_limited_teleport_assets_V8.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_limited_teleport_assets_V8 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_limited_teleport_assets_V8.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polkadotxcm_limited_teleport_assets_V8 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.polkadotxcm_limited_teleport_assets_V8.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8970: /* module 35 call 10 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_force_suspension_V8 - suspended */;
            return _toStringbool(
                &m->basic.polkadotxcm_force_suspension_V8.suspended,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_V8 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.xtokens_transfer_V8.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_V8 - amount */;
            return _toStringBalance(
                &m->basic.xtokens_transfer_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xtokens_transfer_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xtokens_transfer_V8 - dest_weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xtokens_transfer_V8.dest_weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_multiasset_V8 - asset */;
            return _toStringBoxVersionedMultiAsset(
                &m->basic.xtokens_transfer_multiasset_V8.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_multiasset_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xtokens_transfer_multiasset_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_multiasset_V8 - dest_weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xtokens_transfer_multiasset_V8.dest_weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_with_fee_V8 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.xtokens_transfer_with_fee_V8.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_with_fee_V8 - amount */;
            return _toStringBalance(
                &m->basic.xtokens_transfer_with_fee_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_with_fee_V8 - fee */;
            return _toStringBalance(
                &m->basic.xtokens_transfer_with_fee_V8.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xtokens_transfer_with_fee_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xtokens_transfer_with_fee_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* xtokens_transfer_with_fee_V8 - dest_weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xtokens_transfer_with_fee_V8.dest_weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_multiasset_with_fee_V8 - asset */;
            return _toStringBoxVersionedMultiAsset(
                &m->basic.xtokens_transfer_multiasset_with_fee_V8.asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_multiasset_with_fee_V8 - fee */;
            return _toStringBoxVersionedMultiAsset(
                &m->basic.xtokens_transfer_multiasset_with_fee_V8.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_multiasset_with_fee_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xtokens_transfer_multiasset_with_fee_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xtokens_transfer_multiasset_with_fee_V8 - dest_weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xtokens_transfer_multiasset_with_fee_V8.dest_weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_multiassets_V8 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.xtokens_transfer_multiassets_V8.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_multiassets_V8 - fee_item */;
            return _toStringu32(
                &m->basic.xtokens_transfer_multiassets_V8.fee_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_multiassets_V8 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.xtokens_transfer_multiassets_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xtokens_transfer_multiassets_V8 - dest_weight_limit */;
            return _toStringWeightLimit(
                &m->basic.xtokens_transfer_multiassets_V8.dest_weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V8 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V8.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V8 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V8.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V8 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V8 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V8 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V8.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_deprecated_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_deprecated_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_deprecated_V8 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V8.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_deprecated_V8 - old_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V8.old_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 517: /* module 2 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V8 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 518: /* module 2 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V8 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 520: /* module 2 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V8 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V8.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* companyreserve_spend_V8 - to */;
            return _toStringAccountId(
                &m->basic.companyreserve_spend_V8.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* companyreserve_spend_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.companyreserve_spend_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* companyreserve_tip_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.companyreserve_tip_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* companyreserve_apply_as_V8 - call */;
            return _toStringCall(
                &m->basic.companyreserve_apply_as_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* internationalreserve_spend_V8 - to */;
            return _toStringAccountId(
                &m->basic.internationalreserve_spend_V8.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* internationalreserve_spend_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.internationalreserve_spend_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* internationalreserve_tip_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.internationalreserve_tip_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* internationalreserve_apply_as_V8 - call */;
            return _toStringCall(
                &m->basic.internationalreserve_apply_as_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* usareserve_spend_V8 - to */;
            return _toStringAccountId(
                &m->basic.usareserve_spend_V8.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* usareserve_spend_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.usareserve_spend_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* usareserve_tip_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.usareserve_tip_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* usareserve_apply_as_V8 - call */;
            return _toStringCall(
                &m->basic.usareserve_apply_as_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_add_vesting_schedule_V8 - dest */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.vesting_add_vesting_schedule_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_add_vesting_schedule_V8 - schedule */;
            return _toStringVestingScheduleOf(
                &m->basic.vesting_add_vesting_schedule_V8.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_cancel_all_vesting_schedules_V8 - who */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.vesting_cancel_all_vesting_schedules_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_cancel_all_vesting_schedules_V8 - funds_collector */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.vesting_cancel_all_vesting_schedules_V8.funds_collector,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_renounce_V8 - who */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.vesting_renounce_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* mandate_apply_V8 - call */;
            return _toStringCall(
                &m->nested.mandate_apply_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V8 - new_members */;
            return _toStringVecAccountId(
                &m->basic.technicalcommittee_set_members_V8.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V8 - prime */;
            return _toStringOptionAccountId(
                &m->basic.technicalcommittee_set_members_V8.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V8 - old_count */;
            return _toStringMemberCount(
                &m->basic.technicalcommittee_set_members_V8.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V8 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V8.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V8 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V8.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V8 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V8 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V8.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V8 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V8.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V8 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V8.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V8 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V8.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V8 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V8.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V8 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V8.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V8 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V8.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V8 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V8.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V8 - proposal_weight_bound */;
            return _toStringWeight(
                &m->basic.technicalcommittee_close_V8.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V8 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V8.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.technicalmembership_add_member_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.technicalmembership_remove_member_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V8 - remove */;
            return _toStringAccountIdLookupOfT(
                &m->basic.technicalmembership_swap_member_V8.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V8 - add */;
            return _toStringAccountIdLookupOfT(
                &m->basic.technicalmembership_swap_member_V8.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V8 - members */;
            return _toStringVecAccountId(
                &m->basic.technicalmembership_reset_members_V8.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V8 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.technicalmembership_change_key_V8.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.technicalmembership_set_prime_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_invulnerables_V8 - new_ */;
            return _toStringVecAccountId(
                &m->basic.collatorselection_set_invulnerables_V8.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_desired_candidates_V8 - max */;
            return _toStringu32(
                &m->basic.collatorselection_set_desired_candidates_V8.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_candidacy_bond_V8 - bond */;
            return _toStringBalance(
                &m->basic.collatorselection_set_candidacy_bond_V8.bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V8 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V8 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V8.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V8 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V8 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V8 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V8 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V8 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V8.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V8 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V8 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V8.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V8 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V8 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V8 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V8.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V8 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V8.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V8 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V8.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V8 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V8 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V8 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V8.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V8 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V8.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0: /* uniques_create_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_create_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_create_V8 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_create_V8.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0: /* uniques_force_create_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_force_create_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_create_V8 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_create_V8.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_create_V8 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_create_V8.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* uniques_destroy_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_destroy_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_destroy_V8 - witness */;
            return _toStringDestroyWitness(
                &m->basic.uniques_destroy_V8.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        case 0: /* uniques_mint_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_mint_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_mint_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_mint_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_mint_V8 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_mint_V8.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10756: /* module 42 call 4 */
        switch (itemIdx) {
        case 0: /* uniques_burn_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_burn_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_burn_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_burn_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_burn_V8 - check_owner */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.uniques_burn_V8.check_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10757: /* module 42 call 5 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_transfer_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_transfer_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_transfer_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_transfer_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10758: /* module 42 call 6 */
        switch (itemIdx) {
        case 0: /* uniques_redeposit_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_redeposit_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_redeposit_V8 - items */;
            return _toStringVecItemId(
                &m->basic.uniques_redeposit_V8.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10759: /* module 42 call 7 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_freeze_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_freeze_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_freeze_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10760: /* module 42 call 8 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_thaw_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_thaw_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_thaw_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10761: /* module 42 call 9 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_collection_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_freeze_collection_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10762: /* module 42 call 10 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_collection_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_thaw_collection_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10763: /* module 42 call 11 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_ownership_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_transfer_ownership_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_ownership_V8 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_transfer_ownership_V8.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10764: /* module 42 call 12 */
        switch (itemIdx) {
        case 0: /* uniques_set_team_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_team_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_team_V8 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_set_team_V8.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_team_V8 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_set_team_V8.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_team_V8 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_set_team_V8.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10765: /* module 42 call 13 */
        switch (itemIdx) {
        case 0: /* uniques_approve_transfer_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_approve_transfer_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_approve_transfer_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_approve_transfer_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_approve_transfer_V8 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_approve_transfer_V8.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10766: /* module 42 call 14 */
        switch (itemIdx) {
        case 0: /* uniques_cancel_approval_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_cancel_approval_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_cancel_approval_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_cancel_approval_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_cancel_approval_V8 - maybe_check_delegate */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.uniques_cancel_approval_V8.maybe_check_delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10767: /* module 42 call 15 */
        switch (itemIdx) {
        case 0: /* uniques_force_item_status_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_force_item_status_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_item_status_V8 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V8.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_item_status_V8 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V8.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_force_item_status_V8 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V8.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* uniques_force_item_status_V8 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V8.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* uniques_force_item_status_V8 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_item_status_V8.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* uniques_force_item_status_V8 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_force_item_status_V8.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10768: /* module 42 call 16 */
        switch (itemIdx) {
        case 0: /* uniques_set_attribute_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_attribute_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_attribute_V8 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.uniques_set_attribute_V8.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_attribute_V8 - key */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_attribute_V8.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_attribute_V8 - value */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_attribute_V8.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10769: /* module 42 call 17 */
        switch (itemIdx) {
        case 0: /* uniques_clear_attribute_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_clear_attribute_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_attribute_V8 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.uniques_clear_attribute_V8.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_clear_attribute_V8 - key */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_clear_attribute_V8.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10770: /* module 42 call 18 */
        switch (itemIdx) {
        case 0: /* uniques_set_metadata_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_metadata_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_metadata_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_set_metadata_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_metadata_V8 - data */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_metadata_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_metadata_V8 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_set_metadata_V8.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10771: /* module 42 call 19 */
        switch (itemIdx) {
        case 0: /* uniques_clear_metadata_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_clear_metadata_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_metadata_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_clear_metadata_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10772: /* module 42 call 20 */
        switch (itemIdx) {
        case 0: /* uniques_set_collection_metadata_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_collection_metadata_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_collection_metadata_V8 - data */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_collection_metadata_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_collection_metadata_V8 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_set_collection_metadata_V8.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10773: /* module 42 call 21 */
        switch (itemIdx) {
        case 0: /* uniques_clear_collection_metadata_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_clear_collection_metadata_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10774: /* module 42 call 22 */
        switch (itemIdx) {
        case 0: /* uniques_set_accept_ownership_V8 - maybe_collection */;
            return _toStringOptionCollectionId(
                &m->basic.uniques_set_accept_ownership_V8.maybe_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10775: /* module 42 call 23 */
        switch (itemIdx) {
        case 0: /* uniques_set_collection_max_supply_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_collection_max_supply_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_collection_max_supply_V8 - max_supply */;
            return _toStringu32(
                &m->basic.uniques_set_collection_max_supply_V8.max_supply,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10776: /* module 42 call 24 */
        switch (itemIdx) {
        case 0: /* uniques_set_price_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_price_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_price_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_set_price_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_price_V8 - price */;
            return _toStringOptionBalanceOf(
                &m->basic.uniques_set_price_V8.price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_price_V8 - whitelisted_buyer */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.uniques_set_price_V8.whitelisted_buyer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10777: /* module 42 call 25 */
        switch (itemIdx) {
        case 0: /* uniques_buy_item_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_buy_item_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_buy_item_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_buy_item_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_buy_item_V8 - bid_price */;
            return _toStringBalanceOf(
                &m->basic.uniques_buy_item_V8.bid_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10778: /* module 42 call 26 */
        switch (itemIdx) {
        case 0: /* uniques_create_with_extra_deposit_limit_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_create_with_extra_deposit_limit_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_create_with_extra_deposit_limit_V8 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_create_with_extra_deposit_limit_V8.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_create_with_extra_deposit_limit_V8 - limit */;
            return _toStringBalanceOf(
                &m->basic.uniques_create_with_extra_deposit_limit_V8.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10779: /* module 42 call 27 */
        switch (itemIdx) {
        case 0: /* uniques_mint_with_extra_deposit_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_mint_with_extra_deposit_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_mint_with_extra_deposit_V8 - item */;
            return _toStringItemId(
                &m->basic.uniques_mint_with_extra_deposit_V8.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_mint_with_extra_deposit_V8 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_mint_with_extra_deposit_V8.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_mint_with_extra_deposit_V8 - deposit */;
            return _toStringBalanceOf(
                &m->basic.uniques_mint_with_extra_deposit_V8.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10780: /* module 42 call 28 */
        switch (itemIdx) {
        case 0: /* uniques_update_extra_deposit_limit_V8 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_update_extra_deposit_limit_V8.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_update_extra_deposit_limit_V8 - limit */;
            return _toStringBalanceOf(
                &m->basic.uniques_update_extra_deposit_limit_V8.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V8 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V8.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11009: /* module 43 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V8 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V8.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11010: /* module 43 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V8 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V8.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11011: /* module 43 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V8 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V8.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* allocations_batch_V8 - batch */;
            return _toStringVecTupleAccountIdBalanceOf(
                &m->basic.allocations_batch_V8.batch,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* allocations_set_curve_starting_block_V8 - curve_start */;
            return _toStringBlockNumber(
                &m->basic.allocations_set_curve_starting_block_V8.curve_start,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13312: /* module 52 call 0 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_add_member_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.allocationsoracles_add_member_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13313: /* module 52 call 1 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_remove_member_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.allocationsoracles_remove_member_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13314: /* module 52 call 2 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_swap_member_V8 - remove */;
            return _toStringAccountIdLookupOfT(
                &m->basic.allocationsoracles_swap_member_V8.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* allocationsoracles_swap_member_V8 - add */;
            return _toStringAccountIdLookupOfT(
                &m->basic.allocationsoracles_swap_member_V8.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13315: /* module 52 call 3 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_reset_members_V8 - members */;
            return _toStringVecAccountId(
                &m->basic.allocationsoracles_reset_members_V8.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_change_key_V8 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.allocationsoracles_change_key_V8.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13317: /* module 52 call 5 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_set_prime_V8 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.allocationsoracles_set_prime_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13318: /* module 52 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0: /* daoreserve_spend_V8 - to */;
            return _toStringAccountId(
                &m->basic.daoreserve_spend_V8.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* daoreserve_spend_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.daoreserve_spend_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15361: /* module 60 call 1 */
        switch (itemIdx) {
        case 0: /* daoreserve_tip_V8 - amount */;
            return _toStringBalanceOf(
                &m->basic.daoreserve_tip_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15362: /* module 60 call 2 */
        switch (itemIdx) {
        case 0: /* daoreserve_apply_as_V8 - call */;
            return _toStringCall(
                &m->basic.daoreserve_apply_as_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_call_old_weight_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.contracts_call_old_weight_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_old_weight_V8 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_call_old_weight_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_old_weight_V8 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.contracts_call_old_weight_V8.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_old_weight_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_call_old_weight_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_call_old_weight_V8 - data */;
            return _toStringVecu8(
                &m->basic.contracts_call_old_weight_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15873: /* module 62 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_old_weight_V8 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_with_code_old_weight_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_old_weight_V8 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.contracts_instantiate_with_code_old_weight_V8.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_old_weight_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_with_code_old_weight_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_old_weight_V8 - code */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_with_code_old_weight_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_old_weight_V8 - data */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_with_code_old_weight_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_with_code_old_weight_V8 - salt */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_with_code_old_weight_V8.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15874: /* module 62 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_old_weight_V8 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_old_weight_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_old_weight_V8 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.contracts_instantiate_old_weight_V8.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_old_weight_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_old_weight_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_old_weight_V8 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_instantiate_old_weight_V8.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_old_weight_V8 - data */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_old_weight_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_old_weight_V8 - salt */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_old_weight_V8.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15875: /* module 62 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_upload_code_V8 - code */;
            return _toStringVecu8(
                &m->basic.contracts_upload_code_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_upload_code_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_upload_code_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_upload_code_V8 - determinism */;
            return _toStringDeterminism(
                &m->basic.contracts_upload_code_V8.determinism,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15876: /* module 62 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_remove_code_V8 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_remove_code_V8.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15877: /* module 62 call 5 */
        switch (itemIdx) {
        case 0: /* contracts_set_code_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.contracts_set_code_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_set_code_V8 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_set_code_V8.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15878: /* module 62 call 6 */
        switch (itemIdx) {
        case 0: /* contracts_call_V8 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.contracts_call_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V8 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_call_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V8 - gas_limit */;
            return _toStringWeight(
                &m->basic.contracts_call_V8.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_call_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_call_V8 - data */;
            return _toStringVecu8(
                &m->basic.contracts_call_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15879: /* module 62 call 7 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_V8 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_with_code_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_V8 - gas_limit */;
            return _toStringWeight(
                &m->basic.contracts_instantiate_with_code_V8.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_with_code_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_V8 - code */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_with_code_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_V8 - data */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_with_code_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_with_code_V8 - salt */;
            return _toStringVecu8(
                &m->basic.contracts_instantiate_with_code_V8.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15880: /* module 62 call 8 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V8 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V8 - gas_limit */;
            return _toStringWeight(
                &m->basic.contracts_instantiate_V8.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V8 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_V8.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V8 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_instantiate_V8.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V8 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V8.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_V8 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V8.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V8(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V8(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 517: // Balances:Force unreserve
    case 518: // Balances:Upgrade accounts
    case 520: // Balances:Force set balance
    case 2816: // CompanyReserve:Spend
    case 2817: // CompanyReserve:Tip
    case 2818: // CompanyReserve:Apply as
    case 3072: // InternationalReserve:Spend
    case 3073: // InternationalReserve:Tip
    case 3074: // InternationalReserve:Apply as
    case 3328: // UsaReserve:Spend
    case 3329: // UsaReserve:Tip
    case 3330: // UsaReserve:Apply as
    case 3584: // Vesting:Claim
    case 3585: // Vesting:Add vesting schedule
    case 3586: // Vesting:Cancel all vesting schedules
    case 3587: // Vesting:Renounce
    case 4096: // TechnicalCommittee:Set members
    case 4097: // TechnicalCommittee:Execute
    case 4098: // TechnicalCommittee:Propose
    case 4099: // TechnicalCommittee:Vote
    case 4101: // TechnicalCommittee:Disapprove proposal
    case 4102: // TechnicalCommittee:Close
    case 4352: // TechnicalMembership:Add member
    case 4353: // TechnicalMembership:Remove member
    case 4354: // TechnicalMembership:Swap member
    case 4355: // TechnicalMembership:Reset members
    case 4356: // TechnicalMembership:Change key
    case 4357: // TechnicalMembership:Set prime
    case 4358: // TechnicalMembership:Clear prime
    case 4864: // CollatorSelection:Set invulnerables
    case 4865: // CollatorSelection:Set desired candidates
    case 4866: // CollatorSelection:Set candidacy bond
    case 4867: // CollatorSelection:Register as candidate
    case 4868: // CollatorSelection:Leave intent
    case 5888: // Session:Set keys
    case 5889: // Session:Purge keys
    case 8961: // PolkadotXcm:Teleport assets
    case 8962: // PolkadotXcm:Reserve transfer assets
    case 8968: // PolkadotXcm:Limited reserve transfer assets
    case 8969: // PolkadotXcm:Limited teleport assets
    case 8970: // PolkadotXcm:Force suspension
    case 9216: // XTokens:Transfer
    case 9217: // XTokens:Transfer multiasset
    case 9218: // XTokens:Transfer with fee
    case 9219: // XTokens:Transfer multiasset with fee
    case 9221: // XTokens:Transfer multiassets
    case 10244: // Utility:Force batch
    case 10245: // Utility:With weight
    case 10752: // Uniques:Create
    case 10753: // Uniques:Force create
    case 10754: // Uniques:Destroy
    case 10755: // Uniques:Mint
    case 10756: // Uniques:Burn
    case 10757: // Uniques:Transfer
    case 10758: // Uniques:Redeposit
    case 10759: // Uniques:Freeze
    case 10760: // Uniques:Thaw
    case 10761: // Uniques:Freeze collection
    case 10762: // Uniques:Thaw collection
    case 10763: // Uniques:Transfer ownership
    case 10764: // Uniques:Set team
    case 10765: // Uniques:Approve transfer
    case 10766: // Uniques:Cancel approval
    case 10767: // Uniques:Force item status
    case 10768: // Uniques:Set attribute
    case 10769: // Uniques:Clear attribute
    case 10770: // Uniques:Set metadata
    case 10771: // Uniques:Clear metadata
    case 10772: // Uniques:Set collection metadata
    case 10773: // Uniques:Clear collection metadata
    case 10774: // Uniques:Set accept ownership
    case 10775: // Uniques:Set collection max supply
    case 10776: // Uniques:Set price
    case 10777: // Uniques:Buy item
    case 10778: // Uniques:Create with extra deposit limit
    case 10779: // Uniques:Mint with extra deposit
    case 10780: // Uniques:Update extra deposit limit
    case 11008: // Preimage:Note preimage
    case 11009: // Preimage:Unnote preimage
    case 11010: // Preimage:Request preimage
    case 11011: // Preimage:Unrequest preimage
    case 13056: // Allocations:Batch
    case 13057: // Allocations:Set curve starting block
    case 13312: // AllocationsOracles:Add member
    case 13313: // AllocationsOracles:Remove member
    case 13314: // AllocationsOracles:Swap member
    case 13315: // AllocationsOracles:Reset members
    case 13316: // AllocationsOracles:Change key
    case 13317: // AllocationsOracles:Set prime
    case 13318: // AllocationsOracles:Clear prime
    case 15360: // DaoReserve:Spend
    case 15361: // DaoReserve:Tip
    case 15362: // DaoReserve:Apply as
    case 15872: // Contracts:Call old weight
    case 15873: // Contracts:Instantiate with code old weight
    case 15874: // Contracts:Instantiate old weight
    case 15875: // Contracts:Upload code
    case 15876: // Contracts:Remove code
    case 15877: // Contracts:Set code
    case 15878: // Contracts:Call
    case 15879: // Contracts:Instantiate with code
    case 15880: // Contracts:Instantiate
        return false;
    default:
        return true;
    }
}
