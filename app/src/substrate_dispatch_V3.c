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

#include "substrate_dispatch_V3.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V3(
    parser_context_t* c, pd_balances_transfer_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V3(
    parser_context_t* c, pd_balances_transfer_keep_alive_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V3(
    parser_context_t* c, pd_session_set_keys_V3_t* m)
{
    CHECK_ERROR(_readKeys_V3(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V3(
    parser_context_t* c, pd_session_purge_keys_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V3(
    parser_context_t* c, pd_utility_batch_V3_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V3(
    parser_context_t* c, pd_utility_batch_all_V3_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V3(
    parser_context_t* c, pd_system_fill_block_V3_t* m)
{
    CHECK_ERROR(_readPerbill_V3(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V3(
    parser_context_t* c, pd_system_remark_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V3(
    parser_context_t* c, pd_system_set_heap_pages_V3_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V3(
    parser_context_t* c, pd_system_set_code_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V3(
    parser_context_t* c, pd_system_set_code_without_checks_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V3(
    parser_context_t* c, pd_system_set_changes_trie_config_V3_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V3(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V3(
    parser_context_t* c, pd_system_set_storage_V3_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V3(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V3(
    parser_context_t* c, pd_system_kill_storage_V3_t* m)
{
    CHECK_ERROR(_readVecKey_V3(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V3(
    parser_context_t* c, pd_system_kill_prefix_V3_t* m)
{
    CHECK_ERROR(_readKey_V3(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V3(
    parser_context_t* c, pd_timestamp_set_V3_t* m)
{
    CHECK_ERROR(_readCompactMoment_V3(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V3(
    parser_context_t* c, pd_balances_set_balance_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V3(
    parser_context_t* c, pd_balances_force_transfer_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->source))
    CHECK_ERROR(_readLookupSource_V3(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V3(
    parser_context_t* c, pd_babe_report_equivocation_V3_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V3(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V3_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V3(
    parser_context_t* c, pd_grandpa_report_equivocation_V3_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V3(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V3_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V3(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V3(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V3(
    parser_context_t* c, pd_grandpa_note_stalled_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V3(
    parser_context_t* c, pd_authorship_set_uncles_V3_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V3(
    parser_context_t* c, pd_imonline_heartbeat_V3_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V3(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_add_member_V3(
    parser_context_t* c, pd_validatorsset_add_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_remove_member_V3(
    parser_context_t* c, pd_validatorsset_remove_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_swap_member_V3(
    parser_context_t* c, pd_validatorsset_swap_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->remove))
    CHECK_ERROR(_readAccountId_V3(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_reset_members_V3(
    parser_context_t* c, pd_validatorsset_reset_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_change_key_V3(
    parser_context_t* c, pd_validatorsset_change_key_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_set_prime_V3(
    parser_context_t* c, pd_validatorsset_set_prime_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_validatorsset_clear_prime_V3(
    parser_context_t* c, pd_validatorsset_clear_prime_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V3(
    parser_context_t* c, pd_technicalcommittee_set_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V3(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V3(
    parser_context_t* c, pd_technicalcommittee_execute_V3_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V3(
    parser_context_t* c, pd_technicalcommittee_propose_V3_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V3(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V3(
    parser_context_t* c, pd_technicalcommittee_vote_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V3(
    parser_context_t* c, pd_technicalcommittee_close_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V3(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V3(
    parser_context_t* c, pd_technicalmembership_add_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V3(
    parser_context_t* c, pd_technicalmembership_remove_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V3(
    parser_context_t* c, pd_technicalmembership_swap_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->remove))
    CHECK_ERROR(_readAccountId_V3(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V3(
    parser_context_t* c, pd_technicalmembership_reset_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V3(
    parser_context_t* c, pd_technicalmembership_change_key_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V3(
    parser_context_t* c, pd_technicalmembership_set_prime_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V3(
    parser_context_t* c, pd_technicalmembership_clear_prime_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialcommittee_set_members_V3(
    parser_context_t* c, pd_financialcommittee_set_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V3(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialcommittee_execute_V3(
    parser_context_t* c, pd_financialcommittee_execute_V3_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialcommittee_propose_V3(
    parser_context_t* c, pd_financialcommittee_propose_V3_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V3(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialcommittee_vote_V3(
    parser_context_t* c, pd_financialcommittee_vote_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialcommittee_close_V3(
    parser_context_t* c, pd_financialcommittee_close_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialcommittee_disapprove_proposal_V3(
    parser_context_t* c, pd_financialcommittee_disapprove_proposal_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_add_member_V3(
    parser_context_t* c, pd_financialmembership_add_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_remove_member_V3(
    parser_context_t* c, pd_financialmembership_remove_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_swap_member_V3(
    parser_context_t* c, pd_financialmembership_swap_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->remove))
    CHECK_ERROR(_readAccountId_V3(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_reset_members_V3(
    parser_context_t* c, pd_financialmembership_reset_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_change_key_V3(
    parser_context_t* c, pd_financialmembership_change_key_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_set_prime_V3(
    parser_context_t* c, pd_financialmembership_set_prime_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_financialmembership_clear_prime_V3(
    parser_context_t* c, pd_financialmembership_clear_prime_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootcommittee_set_members_V3(
    parser_context_t* c, pd_rootcommittee_set_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V3(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootcommittee_execute_V3(
    parser_context_t* c, pd_rootcommittee_execute_V3_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootcommittee_propose_V3(
    parser_context_t* c, pd_rootcommittee_propose_V3_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V3(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootcommittee_vote_V3(
    parser_context_t* c, pd_rootcommittee_vote_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootcommittee_close_V3(
    parser_context_t* c, pd_rootcommittee_close_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V3(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootcommittee_disapprove_proposal_V3(
    parser_context_t* c, pd_rootcommittee_disapprove_proposal_V3_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_add_member_V3(
    parser_context_t* c, pd_rootmembership_add_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_remove_member_V3(
    parser_context_t* c, pd_rootmembership_remove_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_swap_member_V3(
    parser_context_t* c, pd_rootmembership_swap_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->remove))
    CHECK_ERROR(_readAccountId_V3(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_reset_members_V3(
    parser_context_t* c, pd_rootmembership_reset_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_change_key_V3(
    parser_context_t* c, pd_rootmembership_change_key_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_set_prime_V3(
    parser_context_t* c, pd_rootmembership_set_prime_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rootmembership_clear_prime_V3(
    parser_context_t* c, pd_rootmembership_clear_prime_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V3(
    parser_context_t* c, pd_scheduler_schedule_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V3(
    parser_context_t* c, pd_scheduler_cancel_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V3(
    parser_context_t* c, pd_scheduler_schedule_named_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V3(
    parser_context_t* c, pd_scheduler_cancel_named_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V3(
    parser_context_t* c, pd_scheduler_schedule_after_V3_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V3(
    parser_context_t* c, pd_scheduler_schedule_named_after_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V3(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V3(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_amendments_propose_V3(
    parser_context_t* c, pd_amendments_propose_V3_t* m)
{
    CHECK_ERROR(_readAmendment_V3(c, &m->amendment))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_amendments_veto_V3(
    parser_context_t* c, pd_amendments_veto_V3_t* m)
{
    CHECK_ERROR(_readu64(c, &m->amendment_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_mandate_apply_V3(
    parser_context_t* c, pd_mandate_apply_V3_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_companyreserve_spend_V3(
    parser_context_t* c, pd_companyreserve_spend_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_companyreserve_tip_V3(
    parser_context_t* c, pd_companyreserve_tip_V3_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_companyreserve_apply_as_V3(
    parser_context_t* c, pd_companyreserve_apply_as_V3_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_internationalreserve_spend_V3(
    parser_context_t* c, pd_internationalreserve_spend_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_internationalreserve_tip_V3(
    parser_context_t* c, pd_internationalreserve_tip_V3_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_internationalreserve_apply_as_V3(
    parser_context_t* c, pd_internationalreserve_apply_as_V3_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_usareserve_spend_V3(
    parser_context_t* c, pd_usareserve_spend_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_usareserve_tip_V3(
    parser_context_t* c, pd_usareserve_tip_V3_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_usareserve_apply_as_V3(
    parser_context_t* c, pd_usareserve_apply_as_V3_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_V3(
    parser_context_t* c, pd_vesting_claim_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_add_vesting_schedule_V3(
    parser_context_t* c, pd_vesting_add_vesting_schedule_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->dest))
    CHECK_ERROR(_readVestingScheduleOf_V3(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_cancel_all_vesting_schedules_V3(
    parser_context_t* c, pd_vesting_cancel_all_vesting_schedules_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->who))
    CHECK_ERROR(_readLookupSource_V3(c, &m->funds_collector))
    CHECK_ERROR(_readbool(c, &m->limit_to_free_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V3(
    parser_context_t* c, pd_utility_as_derivative_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V3(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V3(
    parser_context_t* c, pd_multisig_as_multi_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V3(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V3(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V3(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V3(
    parser_context_t* c, pd_multisig_approve_as_multi_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V3(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V3(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V3(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V3(
    parser_context_t* c, pd_multisig_cancel_as_multi_V3_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V3(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V3(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V3(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_update_schedule_V3(
    parser_context_t* c, pd_contracts_update_schedule_V3_t* m)
{
    CHECK_ERROR(_readSchedule_V3(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V3(
    parser_context_t* c, pd_contracts_call_V3_t* m)
{
    CHECK_ERROR(_readLookupSource_V3(c, &m->dest))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->gas_limit))
    CHECK_ERROR(_readBytes(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_V3(
    parser_context_t* c, pd_contracts_instantiate_with_code_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->endowment))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->gas_limit))
    CHECK_ERROR(_readBytes(c, &m->code))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V3(
    parser_context_t* c, pd_contracts_instantiate_V3_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->endowment))
    CHECK_ERROR(_readCompactWeight_V3(c, &m->gas_limit))
    CHECK_ERROR(_readCodeHash_V3(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_claim_surcharge_V3(
    parser_context_t* c, pd_contracts_claim_surcharge_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->dest))
    CHECK_ERROR(_readOptionAccountId_V3(c, &m->aux_sender))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkitcr_apply_V3(
    parser_context_t* c, pd_pkitcr_apply_V3_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->metadata))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkitcr_counter_V3(
    parser_context_t* c, pd_pkitcr_counter_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->member))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkitcr_vote_V3(
    parser_context_t* c, pd_pkitcr_vote_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->member))
    CHECK_ERROR(_readbool(c, &m->supporting))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkitcr_challenge_V3(
    parser_context_t* c, pd_pkitcr_challenge_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->member))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkirootoftrust_book_slot_V3(
    parser_context_t* c, pd_pkirootoftrust_book_slot_V3_t* m)
{
    CHECK_ERROR(_readCertificateId_V3(c, &m->certificate_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkirootoftrust_renew_slot_V3(
    parser_context_t* c, pd_pkirootoftrust_renew_slot_V3_t* m)
{
    CHECK_ERROR(_readCertificateId_V3(c, &m->certificate_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkirootoftrust_revoke_slot_V3(
    parser_context_t* c, pd_pkirootoftrust_revoke_slot_V3_t* m)
{
    CHECK_ERROR(_readCertificateId_V3(c, &m->certificate_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pkirootoftrust_revoke_child_V3(
    parser_context_t* c, pd_pkirootoftrust_revoke_child_V3_t* m)
{
    CHECK_ERROR(_readCertificateId_V3(c, &m->root))
    CHECK_ERROR(_readCertificateId_V3(c, &m->child))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_emergencyshutdown_toggle_V3(
    parser_context_t* c, pd_emergencyshutdown_toggle_V3_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocations_allocate_V3(
    parser_context_t* c, pd_allocations_allocate_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_add_member_V3(
    parser_context_t* c, pd_allocationsoracles_add_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_remove_member_V3(
    parser_context_t* c, pd_allocationsoracles_remove_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_swap_member_V3(
    parser_context_t* c, pd_allocationsoracles_swap_member_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->remove))
    CHECK_ERROR(_readAccountId_V3(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_reset_members_V3(
    parser_context_t* c, pd_allocationsoracles_reset_members_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId_V3(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_change_key_V3(
    parser_context_t* c, pd_allocationsoracles_change_key_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_set_prime_V3(
    parser_context_t* c, pd_allocationsoracles_set_prime_V3_t* m)
{
    CHECK_ERROR(_readAccountId_V3(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_allocationsoracles_clear_prime_V3(
    parser_context_t* c, pd_allocationsoracles_clear_prime_V3_t* m)
{
    return parser_ok;
}

#endif

parser_error_t _readMethod_V3(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V3_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V3(c, &method->nested.balances_transfer_V3))
        break;
    case 515: /* module 2 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V3(c, &method->nested.balances_transfer_keep_alive_V3))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V3(c, &method->basic.session_set_keys_V3))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V3(c, &method->basic.session_purge_keys_V3))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V3(c, &method->nested.utility_batch_V3))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V3(c, &method->nested.utility_batch_all_V3))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V3(c, &method->nested.system_fill_block_V3))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V3(c, &method->nested.system_remark_V3))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V3(c, &method->nested.system_set_heap_pages_V3))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V3(c, &method->nested.system_set_code_V3))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V3(c, &method->nested.system_set_code_without_checks_V3))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V3(c, &method->nested.system_set_changes_trie_config_V3))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V3(c, &method->nested.system_set_storage_V3))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V3(c, &method->nested.system_kill_storage_V3))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V3(c, &method->nested.system_kill_prefix_V3))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V3(c, &method->basic.timestamp_set_V3))
        break;
    case 513: /* module 2 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V3(c, &method->nested.balances_set_balance_V3))
        break;
    case 514: /* module 2 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V3(c, &method->nested.balances_force_transfer_V3))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V3(c, &method->basic.babe_report_equivocation_V3))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V3(c, &method->basic.babe_report_equivocation_unsigned_V3))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V3(c, &method->basic.grandpa_report_equivocation_V3))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V3(c, &method->basic.grandpa_report_equivocation_unsigned_V3))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V3(c, &method->basic.grandpa_note_stalled_V3))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V3(c, &method->basic.authorship_set_uncles_V3))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V3(c, &method->basic.imonline_heartbeat_V3))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_validatorsset_add_member_V3(c, &method->nested.validatorsset_add_member_V3))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_validatorsset_remove_member_V3(c, &method->nested.validatorsset_remove_member_V3))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_validatorsset_swap_member_V3(c, &method->nested.validatorsset_swap_member_V3))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_validatorsset_reset_members_V3(c, &method->nested.validatorsset_reset_members_V3))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_validatorsset_change_key_V3(c, &method->nested.validatorsset_change_key_V3))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_validatorsset_set_prime_V3(c, &method->nested.validatorsset_set_prime_V3))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_validatorsset_clear_prime_V3(c, &method->nested.validatorsset_clear_prime_V3))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V3(c, &method->nested.technicalcommittee_set_members_V3))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V3(c, &method->nested.technicalcommittee_execute_V3))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V3(c, &method->nested.technicalcommittee_propose_V3))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V3(c, &method->nested.technicalcommittee_vote_V3))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V3(c, &method->nested.technicalcommittee_close_V3))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V3(c, &method->nested.technicalcommittee_disapprove_proposal_V3))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V3(c, &method->nested.technicalmembership_add_member_V3))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V3(c, &method->nested.technicalmembership_remove_member_V3))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V3(c, &method->nested.technicalmembership_swap_member_V3))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V3(c, &method->nested.technicalmembership_reset_members_V3))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V3(c, &method->nested.technicalmembership_change_key_V3))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V3(c, &method->nested.technicalmembership_set_prime_V3))
        break;
    case 4102: /* module 16 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V3(c, &method->nested.technicalmembership_clear_prime_V3))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_financialcommittee_set_members_V3(c, &method->basic.financialcommittee_set_members_V3))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_financialcommittee_execute_V3(c, &method->basic.financialcommittee_execute_V3))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_financialcommittee_propose_V3(c, &method->basic.financialcommittee_propose_V3))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_financialcommittee_vote_V3(c, &method->basic.financialcommittee_vote_V3))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_financialcommittee_close_V3(c, &method->basic.financialcommittee_close_V3))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_financialcommittee_disapprove_proposal_V3(c, &method->basic.financialcommittee_disapprove_proposal_V3))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_financialmembership_add_member_V3(c, &method->nested.financialmembership_add_member_V3))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_financialmembership_remove_member_V3(c, &method->nested.financialmembership_remove_member_V3))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_financialmembership_swap_member_V3(c, &method->nested.financialmembership_swap_member_V3))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_financialmembership_reset_members_V3(c, &method->nested.financialmembership_reset_members_V3))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_financialmembership_change_key_V3(c, &method->nested.financialmembership_change_key_V3))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_financialmembership_set_prime_V3(c, &method->nested.financialmembership_set_prime_V3))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_financialmembership_clear_prime_V3(c, &method->nested.financialmembership_clear_prime_V3))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_rootcommittee_set_members_V3(c, &method->basic.rootcommittee_set_members_V3))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_rootcommittee_execute_V3(c, &method->basic.rootcommittee_execute_V3))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_rootcommittee_propose_V3(c, &method->basic.rootcommittee_propose_V3))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_rootcommittee_vote_V3(c, &method->basic.rootcommittee_vote_V3))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_rootcommittee_close_V3(c, &method->basic.rootcommittee_close_V3))
        break;
    case 4869: /* module 19 call 5 */
        CHECK_ERROR(_readMethod_rootcommittee_disapprove_proposal_V3(c, &method->basic.rootcommittee_disapprove_proposal_V3))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_rootmembership_add_member_V3(c, &method->nested.rootmembership_add_member_V3))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_rootmembership_remove_member_V3(c, &method->nested.rootmembership_remove_member_V3))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_rootmembership_swap_member_V3(c, &method->nested.rootmembership_swap_member_V3))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_rootmembership_reset_members_V3(c, &method->nested.rootmembership_reset_members_V3))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_rootmembership_change_key_V3(c, &method->nested.rootmembership_change_key_V3))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_rootmembership_set_prime_V3(c, &method->nested.rootmembership_set_prime_V3))
        break;
    case 5126: /* module 20 call 6 */
        CHECK_ERROR(_readMethod_rootmembership_clear_prime_V3(c, &method->nested.rootmembership_clear_prime_V3))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V3(c, &method->basic.scheduler_schedule_V3))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V3(c, &method->basic.scheduler_cancel_V3))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V3(c, &method->basic.scheduler_schedule_named_V3))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V3(c, &method->basic.scheduler_cancel_named_V3))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V3(c, &method->basic.scheduler_schedule_after_V3))
        break;
    case 5381: /* module 21 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V3(c, &method->basic.scheduler_schedule_named_after_V3))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_amendments_propose_V3(c, &method->nested.amendments_propose_V3))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_amendments_veto_V3(c, &method->nested.amendments_veto_V3))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_mandate_apply_V3(c, &method->nested.mandate_apply_V3))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_companyreserve_spend_V3(c, &method->nested.companyreserve_spend_V3))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_companyreserve_tip_V3(c, &method->nested.companyreserve_tip_V3))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_companyreserve_apply_as_V3(c, &method->nested.companyreserve_apply_as_V3))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_internationalreserve_spend_V3(c, &method->nested.internationalreserve_spend_V3))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_internationalreserve_tip_V3(c, &method->nested.internationalreserve_tip_V3))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_internationalreserve_apply_as_V3(c, &method->nested.internationalreserve_apply_as_V3))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_usareserve_spend_V3(c, &method->nested.usareserve_spend_V3))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_usareserve_tip_V3(c, &method->nested.usareserve_tip_V3))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_usareserve_apply_as_V3(c, &method->nested.usareserve_apply_as_V3))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_vesting_claim_V3(c, &method->nested.vesting_claim_V3))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_vesting_add_vesting_schedule_V3(c, &method->nested.vesting_add_vesting_schedule_V3))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_vesting_cancel_all_vesting_schedules_V3(c, &method->nested.vesting_cancel_all_vesting_schedules_V3))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V3(c, &method->nested.utility_as_derivative_V3))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V3(c, &method->nested.multisig_as_multi_threshold_1_V3))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V3(c, &method->nested.multisig_as_multi_V3))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V3(c, &method->nested.multisig_approve_as_multi_V3))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V3(c, &method->nested.multisig_cancel_as_multi_V3))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_contracts_update_schedule_V3(c, &method->basic.contracts_update_schedule_V3))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_contracts_call_V3(c, &method->basic.contracts_call_V3))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_V3(c, &method->basic.contracts_instantiate_with_code_V3))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V3(c, &method->basic.contracts_instantiate_V3))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_contracts_claim_surcharge_V3(c, &method->basic.contracts_claim_surcharge_V3))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_pkitcr_apply_V3(c, &method->nested.pkitcr_apply_V3))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_pkitcr_counter_V3(c, &method->nested.pkitcr_counter_V3))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_pkitcr_vote_V3(c, &method->nested.pkitcr_vote_V3))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_pkitcr_challenge_V3(c, &method->nested.pkitcr_challenge_V3))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_pkirootoftrust_book_slot_V3(c, &method->nested.pkirootoftrust_book_slot_V3))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_pkirootoftrust_renew_slot_V3(c, &method->nested.pkirootoftrust_renew_slot_V3))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_pkirootoftrust_revoke_slot_V3(c, &method->nested.pkirootoftrust_revoke_slot_V3))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_pkirootoftrust_revoke_child_V3(c, &method->nested.pkirootoftrust_revoke_child_V3))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_emergencyshutdown_toggle_V3(c, &method->nested.emergencyshutdown_toggle_V3))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_allocations_allocate_V3(c, &method->basic.allocations_allocate_V3))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_allocationsoracles_add_member_V3(c, &method->nested.allocationsoracles_add_member_V3))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_allocationsoracles_remove_member_V3(c, &method->nested.allocationsoracles_remove_member_V3))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_allocationsoracles_swap_member_V3(c, &method->nested.allocationsoracles_swap_member_V3))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_allocationsoracles_reset_members_V3(c, &method->nested.allocationsoracles_reset_members_V3))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_allocationsoracles_change_key_V3(c, &method->nested.allocationsoracles_change_key_V3))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_allocationsoracles_set_prime_V3(c, &method->nested.allocationsoracles_set_prime_V3))
        break;
    case 8966: /* module 35 call 6 */
        CHECK_ERROR(_readMethod_allocationsoracles_clear_prime_V3(c, &method->nested.allocationsoracles_clear_prime_V3))
        break;
#endif
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V3(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 2:
        return STR_MO_BALANCES;
    case 12:
        return STR_MO_SESSION;
    case 28:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 1:
        return STR_MO_TIMESTAMP;
    case 4:
        return STR_MO_RANDOMNESSCOLLECTIVEFLIP;
    case 5:
        return STR_MO_BABE;
    case 6:
        return STR_MO_GRANDPA;
    case 7:
        return STR_MO_AUTHORSHIP;
    case 8:
        return STR_MO_IMONLINE;
    case 9:
        return STR_MO_OFFENCES;
    case 10:
        return STR_MO_VALIDATORSSET;
    case 14:
        return STR_MO_AUTHORITYDISCOVERY;
    case 15:
        return STR_MO_TECHNICALCOMMITTEE;
    case 16:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 17:
        return STR_MO_FINANCIALCOMMITTEE;
    case 18:
        return STR_MO_FINANCIALMEMBERSHIP;
    case 19:
        return STR_MO_ROOTCOMMITTEE;
    case 20:
        return STR_MO_ROOTMEMBERSHIP;
    case 21:
        return STR_MO_SCHEDULER;
    case 22:
        return STR_MO_AMENDMENTS;
    case 23:
        return STR_MO_MANDATE;
    case 24:
        return STR_MO_COMPANYRESERVE;
    case 25:
        return STR_MO_INTERNATIONALRESERVE;
    case 26:
        return STR_MO_USARESERVE;
    case 27:
        return STR_MO_VESTING;
    case 29:
        return STR_MO_MULTISIG;
    case 30:
        return STR_MO_CONTRACTS;
    case 31:
        return STR_MO_PKITCR;
    case 32:
        return STR_MO_PKIROOTOFTRUST;
    case 33:
        return STR_MO_EMERGENCYSHUTDOWN;
    case 34:
        return STR_MO_ALLOCATIONS;
    case 35:
        return STR_MO_ALLOCATIONSORACLES;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V3(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return STR_ME_TRANSFER;
    case 515: /* module 2 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 3072: /* module 12 call 0 */
        return STR_ME_SET_KEYS;
    case 3073: /* module 12 call 1 */
        return STR_ME_PURGE_KEYS;
    case 7168: /* module 28 call 0 */
        return STR_ME_BATCH;
    case 7170: /* module 28 call 2 */
        return STR_ME_BATCH_ALL;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 256: /* module 1 call 0 */
        return STR_ME_SET;
    case 513: /* module 2 call 1 */
        return STR_ME_SET_BALANCE;
    case 514: /* module 2 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1280: /* module 5 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 1281: /* module 5 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 1536: /* module 6 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 1537: /* module 6 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 1538: /* module 6 call 2 */
        return STR_ME_NOTE_STALLED;
    case 1792: /* module 7 call 0 */
        return STR_ME_SET_UNCLES;
    case 2048: /* module 8 call 0 */
        return STR_ME_HEARTBEAT;
    case 2560: /* module 10 call 0 */
        return STR_ME_ADD_MEMBER;
    case 2561: /* module 10 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 2562: /* module 10 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 2563: /* module 10 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 2564: /* module 10 call 4 */
        return STR_ME_CHANGE_KEY;
    case 2565: /* module 10 call 5 */
        return STR_ME_SET_PRIME;
    case 2566: /* module 10 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 3840: /* module 15 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3841: /* module 15 call 1 */
        return STR_ME_EXECUTE;
    case 3842: /* module 15 call 2 */
        return STR_ME_PROPOSE;
    case 3843: /* module 15 call 3 */
        return STR_ME_VOTE;
    case 3844: /* module 15 call 4 */
        return STR_ME_CLOSE;
    case 3845: /* module 15 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4097: /* module 16 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4098: /* module 16 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4099: /* module 16 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4100: /* module 16 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4101: /* module 16 call 5 */
        return STR_ME_SET_PRIME;
    case 4102: /* module 16 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4352: /* module 17 call 0 */
        return STR_ME_SET_MEMBERS;
    case 4353: /* module 17 call 1 */
        return STR_ME_EXECUTE;
    case 4354: /* module 17 call 2 */
        return STR_ME_PROPOSE;
    case 4355: /* module 17 call 3 */
        return STR_ME_VOTE;
    case 4356: /* module 17 call 4 */
        return STR_ME_CLOSE;
    case 4357: /* module 17 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4608: /* module 18 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4609: /* module 18 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4610: /* module 18 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4611: /* module 18 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4612: /* module 18 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4613: /* module 18 call 5 */
        return STR_ME_SET_PRIME;
    case 4614: /* module 18 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4864: /* module 19 call 0 */
        return STR_ME_SET_MEMBERS;
    case 4865: /* module 19 call 1 */
        return STR_ME_EXECUTE;
    case 4866: /* module 19 call 2 */
        return STR_ME_PROPOSE;
    case 4867: /* module 19 call 3 */
        return STR_ME_VOTE;
    case 4868: /* module 19 call 4 */
        return STR_ME_CLOSE;
    case 4869: /* module 19 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 5120: /* module 20 call 0 */
        return STR_ME_ADD_MEMBER;
    case 5121: /* module 20 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 5122: /* module 20 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 5123: /* module 20 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 5124: /* module 20 call 4 */
        return STR_ME_CHANGE_KEY;
    case 5125: /* module 20 call 5 */
        return STR_ME_SET_PRIME;
    case 5126: /* module 20 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 5376: /* module 21 call 0 */
        return STR_ME_SCHEDULE;
    case 5377: /* module 21 call 1 */
        return STR_ME_CANCEL;
    case 5378: /* module 21 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 5379: /* module 21 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 5380: /* module 21 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 5381: /* module 21 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 5632: /* module 22 call 0 */
        return STR_ME_PROPOSE;
    case 5633: /* module 22 call 1 */
        return STR_ME_VETO;
    case 5888: /* module 23 call 0 */
        return STR_ME_APPLY;
    case 6144: /* module 24 call 0 */
        return STR_ME_SPEND;
    case 6145: /* module 24 call 1 */
        return STR_ME_TIP;
    case 6146: /* module 24 call 2 */
        return STR_ME_APPLY_AS;
    case 6400: /* module 25 call 0 */
        return STR_ME_SPEND;
    case 6401: /* module 25 call 1 */
        return STR_ME_TIP;
    case 6402: /* module 25 call 2 */
        return STR_ME_APPLY_AS;
    case 6656: /* module 26 call 0 */
        return STR_ME_SPEND;
    case 6657: /* module 26 call 1 */
        return STR_ME_TIP;
    case 6658: /* module 26 call 2 */
        return STR_ME_APPLY_AS;
    case 6912: /* module 27 call 0 */
        return STR_ME_CLAIM;
    case 6913: /* module 27 call 1 */
        return STR_ME_ADD_VESTING_SCHEDULE;
    case 6914: /* module 27 call 2 */
        return STR_ME_CANCEL_ALL_VESTING_SCHEDULES;
    case 7169: /* module 28 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 7424: /* module 29 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7425: /* module 29 call 1 */
        return STR_ME_AS_MULTI;
    case 7426: /* module 29 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7427: /* module 29 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 7680: /* module 30 call 0 */
        return STR_ME_UPDATE_SCHEDULE;
    case 7681: /* module 30 call 1 */
        return STR_ME_CALL;
    case 7682: /* module 30 call 2 */
        return STR_ME_INSTANTIATE_WITH_CODE;
    case 7683: /* module 30 call 3 */
        return STR_ME_INSTANTIATE;
    case 7684: /* module 30 call 4 */
        return STR_ME_CLAIM_SURCHARGE;
    case 7936: /* module 31 call 0 */
        return STR_ME_APPLY;
    case 7937: /* module 31 call 1 */
        return STR_ME_COUNTER;
    case 7938: /* module 31 call 2 */
        return STR_ME_VOTE;
    case 7939: /* module 31 call 3 */
        return STR_ME_CHALLENGE;
    case 8192: /* module 32 call 0 */
        return STR_ME_BOOK_SLOT;
    case 8193: /* module 32 call 1 */
        return STR_ME_RENEW_SLOT;
    case 8194: /* module 32 call 2 */
        return STR_ME_REVOKE_SLOT;
    case 8195: /* module 32 call 3 */
        return STR_ME_REVOKE_CHILD;
    case 8448: /* module 33 call 0 */
        return STR_ME_TOGGLE;
    case 8704: /* module 34 call 0 */
        return STR_ME_ALLOCATE;
    case 8960: /* module 35 call 0 */
        return STR_ME_ADD_MEMBER;
    case 8961: /* module 35 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 8962: /* module 35 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 8963: /* module 35 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 8964: /* module 35 call 4 */
        return STR_ME_CHANGE_KEY;
    case 8965: /* module 35 call 5 */
        return STR_ME_SET_PRIME;
    case 8966: /* module 35 call 6 */
        return STR_ME_CLEAR_PRIME;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V3(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        return 2;
    case 515: /* module 2 call 3 */
        return 2;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 0;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 256: /* module 1 call 0 */
        return 1;
    case 513: /* module 2 call 1 */
        return 3;
    case 514: /* module 2 call 2 */
        return 3;
    case 1280: /* module 5 call 0 */
        return 2;
    case 1281: /* module 5 call 1 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 2;
    case 1537: /* module 6 call 1 */
        return 2;
    case 1538: /* module 6 call 2 */
        return 2;
    case 1792: /* module 7 call 0 */
        return 1;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2560: /* module 10 call 0 */
        return 1;
    case 2561: /* module 10 call 1 */
        return 1;
    case 2562: /* module 10 call 2 */
        return 2;
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 1;
    case 2565: /* module 10 call 5 */
        return 1;
    case 2566: /* module 10 call 6 */
        return 0;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3841: /* module 15 call 1 */
        return 2;
    case 3842: /* module 15 call 2 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 3;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 1;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 2;
    case 4099: /* module 16 call 3 */
        return 1;
    case 4100: /* module 16 call 4 */
        return 1;
    case 4101: /* module 16 call 5 */
        return 1;
    case 4102: /* module 16 call 6 */
        return 0;
    case 4352: /* module 17 call 0 */
        return 3;
    case 4353: /* module 17 call 1 */
        return 2;
    case 4354: /* module 17 call 2 */
        return 3;
    case 4355: /* module 17 call 3 */
        return 3;
    case 4356: /* module 17 call 4 */
        return 4;
    case 4357: /* module 17 call 5 */
        return 1;
    case 4608: /* module 18 call 0 */
        return 1;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 2;
    case 4611: /* module 18 call 3 */
        return 1;
    case 4612: /* module 18 call 4 */
        return 1;
    case 4613: /* module 18 call 5 */
        return 1;
    case 4614: /* module 18 call 6 */
        return 0;
    case 4864: /* module 19 call 0 */
        return 3;
    case 4865: /* module 19 call 1 */
        return 2;
    case 4866: /* module 19 call 2 */
        return 3;
    case 4867: /* module 19 call 3 */
        return 3;
    case 4868: /* module 19 call 4 */
        return 4;
    case 4869: /* module 19 call 5 */
        return 1;
    case 5120: /* module 20 call 0 */
        return 1;
    case 5121: /* module 20 call 1 */
        return 1;
    case 5122: /* module 20 call 2 */
        return 2;
    case 5123: /* module 20 call 3 */
        return 1;
    case 5124: /* module 20 call 4 */
        return 1;
    case 5125: /* module 20 call 5 */
        return 1;
    case 5126: /* module 20 call 6 */
        return 0;
    case 5376: /* module 21 call 0 */
        return 4;
    case 5377: /* module 21 call 1 */
        return 2;
    case 5378: /* module 21 call 2 */
        return 5;
    case 5379: /* module 21 call 3 */
        return 1;
    case 5380: /* module 21 call 4 */
        return 4;
    case 5381: /* module 21 call 5 */
        return 5;
    case 5632: /* module 22 call 0 */
        return 1;
    case 5633: /* module 22 call 1 */
        return 1;
    case 5888: /* module 23 call 0 */
        return 1;
    case 6144: /* module 24 call 0 */
        return 2;
    case 6145: /* module 24 call 1 */
        return 1;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6400: /* module 25 call 0 */
        return 2;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 1;
    case 6656: /* module 26 call 0 */
        return 2;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 1;
    case 6912: /* module 27 call 0 */
        return 0;
    case 6913: /* module 27 call 1 */
        return 2;
    case 6914: /* module 27 call 2 */
        return 3;
    case 7169: /* module 28 call 1 */
        return 2;
    case 7424: /* module 29 call 0 */
        return 2;
    case 7425: /* module 29 call 1 */
        return 6;
    case 7426: /* module 29 call 2 */
        return 5;
    case 7427: /* module 29 call 3 */
        return 4;
    case 7680: /* module 30 call 0 */
        return 1;
    case 7681: /* module 30 call 1 */
        return 4;
    case 7682: /* module 30 call 2 */
        return 5;
    case 7683: /* module 30 call 3 */
        return 5;
    case 7684: /* module 30 call 4 */
        return 2;
    case 7936: /* module 31 call 0 */
        return 2;
    case 7937: /* module 31 call 1 */
        return 2;
    case 7938: /* module 31 call 2 */
        return 3;
    case 7939: /* module 31 call 3 */
        return 2;
    case 8192: /* module 32 call 0 */
        return 1;
    case 8193: /* module 32 call 1 */
        return 1;
    case 8194: /* module 32 call 2 */
        return 1;
    case 8195: /* module 32 call 3 */
        return 2;
    case 8448: /* module 33 call 0 */
        return 0;
    case 8704: /* module 34 call 0 */
        return 3;
    case 8960: /* module 35 call 0 */
        return 1;
    case 8961: /* module 35 call 1 */
        return 1;
    case 8962: /* module 35 call 2 */
        return 2;
    case 8963: /* module 35 call 3 */
        return 1;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 1;
    case 8966: /* module 35 call 6 */
        return 0;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V3(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 515: /* module 2 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
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
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_changes_trie_config;
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefix;
        case 1:
            return STR_IT__subkeys;
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
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
            return STR_IT_new_reserved;
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
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_uncles;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heartbeat;
        case 1:
            return STR_IT__signature;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
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
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
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
    case 3843: /* module 15 call 3 */
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
    case 3844: /* module 15 call 4 */
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
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
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
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
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
    case 4355: /* module 17 call 3 */
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
    case 4356: /* module 17 call 4 */
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
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
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
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
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
    case 4867: /* module 19 call 3 */
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
    case 4868: /* module 19 call 4 */
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
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5126: /* module 20 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amendment;
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amendment_id;
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_funds_collector;
        case 2:
            return STR_IT_limit_to_free_balance;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
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
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
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
    case 7427: /* module 29 call 3 */
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
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_code;
        case 3:
            return STR_IT_data;
        case 4:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_code_hash;
        case 3:
            return STR_IT_data;
        case 4:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_aux_sender;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_metadata;
        case 1:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member;
        case 1:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member;
        case 1:
            return STR_IT_supporting;
        case 2:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member;
        case 1:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_certificate_id;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_certificate_id;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_certificate_id;
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_root;
        case 1:
            return STR_IT_child;
        default:
            return NULL;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V3(
    pd_Method_V3_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V3 - dest */;
            return _toStringLookupSource_V3(
                &m->nested.balances_transfer_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V3 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 515: /* module 2 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V3 - dest */;
            return _toStringLookupSource_V3(
                &m->nested.balances_transfer_keep_alive_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V3 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V3 - keys */;
            return _toStringKeys_V3(
                &m->basic.session_set_keys_V3.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V3 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V3.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V3 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_V3.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V3 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_all_V3.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V3 - _ratio */;
            return _toStringPerbill_V3(
                &m->nested.system_fill_block_V3._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V3 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V3._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V3 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V3.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V3 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V3.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V3 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V3.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V3 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V3(
                &m->nested.system_set_changes_trie_config_V3.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V3 - items */;
            return _toStringVecKeyValue_V3(
                &m->nested.system_set_storage_V3.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V3 - keys */;
            return _toStringVecKey_V3(
                &m->nested.system_kill_storage_V3.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V3 - prefix */;
            return _toStringKey_V3(
                &m->nested.system_kill_prefix_V3.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V3 - _subkeys */;
            return _toStringu32(
                &m->nested.system_kill_prefix_V3._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V3 - now */;
            return _toStringCompactMoment_V3(
                &m->basic.timestamp_set_V3.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 513: /* module 2 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V3 - who */;
            return _toStringLookupSource_V3(
                &m->nested.balances_set_balance_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V3 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V3.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V3 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V3.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 514: /* module 2 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V3 - source */;
            return _toStringLookupSource_V3(
                &m->nested.balances_force_transfer_V3.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V3 - dest */;
            return _toStringLookupSource_V3(
                &m->nested.balances_force_transfer_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V3 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V3 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V3(
                &m->basic.babe_report_equivocation_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.babe_report_equivocation_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V3 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V3(
                &m->basic.babe_report_equivocation_unsigned_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.babe_report_equivocation_unsigned_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V3 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V3(
                &m->basic.grandpa_report_equivocation_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.grandpa_report_equivocation_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V3 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V3(
                &m->basic.grandpa_report_equivocation_unsigned_V3.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V3 - key_owner_proof */;
            return _toStringKeyOwnerProof_V3(
                &m->basic.grandpa_report_equivocation_unsigned_V3.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V3 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V3.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V3 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V3.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V3 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V3.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V3 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V3.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V3 - _signature */;
            return _toStringSignature_V3(
                &m->basic.imonline_heartbeat_V3._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* validatorsset_add_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.validatorsset_add_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* validatorsset_remove_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.validatorsset_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* validatorsset_swap_member_V3 - remove */;
            return _toStringAccountId_V3(
                &m->nested.validatorsset_swap_member_V3.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* validatorsset_swap_member_V3 - add */;
            return _toStringAccountId_V3(
                &m->nested.validatorsset_swap_member_V3.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* validatorsset_reset_members_V3 - members */;
            return _toStringVecAccountId_V3(
                &m->nested.validatorsset_reset_members_V3.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* validatorsset_change_key_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->nested.validatorsset_change_key_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* validatorsset_set_prime_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.validatorsset_set_prime_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V3 - new_members */;
            return _toStringVecAccountId_V3(
                &m->nested.technicalcommittee_set_members_V3.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V3 - prime */;
            return _toStringOptionAccountId_V3(
                &m->nested.technicalcommittee_set_members_V3.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V3 - old_count */;
            return _toStringMemberCount_V3(
                &m->nested.technicalcommittee_set_members_V3.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V3 - proposal */;
            return _toStringProposal(
                &m->nested.technicalcommittee_execute_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_execute_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V3 - threshold */;
            return _toStringCompactMemberCount_V3(
                &m->nested.technicalcommittee_propose_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V3 - proposal */;
            return _toStringProposal(
                &m->nested.technicalcommittee_propose_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_propose_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V3 - proposal */;
            return _toStringHash(
                &m->nested.technicalcommittee_vote_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->nested.technicalcommittee_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V3 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V3 - proposal_hash */;
            return _toStringHash(
                &m->nested.technicalcommittee_close_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->nested.technicalcommittee_close_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V3 - proposal_weight_bound */;
            return _toStringCompactWeight_V3(
                &m->nested.technicalcommittee_close_V3.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V3 - length_bound */;
            return _toStringCompactu32(
                &m->nested.technicalcommittee_close_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V3 - proposal_hash */;
            return _toStringHash(
                &m->nested.technicalcommittee_disapprove_proposal_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.technicalmembership_add_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.technicalmembership_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V3 - remove */;
            return _toStringAccountId_V3(
                &m->nested.technicalmembership_swap_member_V3.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V3 - add */;
            return _toStringAccountId_V3(
                &m->nested.technicalmembership_swap_member_V3.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V3 - members */;
            return _toStringVecAccountId_V3(
                &m->nested.technicalmembership_reset_members_V3.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->nested.technicalmembership_change_key_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.technicalmembership_set_prime_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* financialcommittee_set_members_V3 - new_members */;
            return _toStringVecAccountId_V3(
                &m->basic.financialcommittee_set_members_V3.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* financialcommittee_set_members_V3 - prime */;
            return _toStringOptionAccountId_V3(
                &m->basic.financialcommittee_set_members_V3.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* financialcommittee_set_members_V3 - old_count */;
            return _toStringMemberCount_V3(
                &m->basic.financialcommittee_set_members_V3.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* financialcommittee_execute_V3 - proposal */;
            return _toStringProposal(
                &m->basic.financialcommittee_execute_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* financialcommittee_execute_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.financialcommittee_execute_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* financialcommittee_propose_V3 - threshold */;
            return _toStringCompactMemberCount_V3(
                &m->basic.financialcommittee_propose_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* financialcommittee_propose_V3 - proposal */;
            return _toStringProposal(
                &m->basic.financialcommittee_propose_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* financialcommittee_propose_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.financialcommittee_propose_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* financialcommittee_vote_V3 - proposal */;
            return _toStringHash(
                &m->basic.financialcommittee_vote_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* financialcommittee_vote_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.financialcommittee_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* financialcommittee_vote_V3 - approve */;
            return _toStringbool(
                &m->basic.financialcommittee_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* financialcommittee_close_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.financialcommittee_close_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* financialcommittee_close_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.financialcommittee_close_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* financialcommittee_close_V3 - proposal_weight_bound */;
            return _toStringCompactWeight_V3(
                &m->basic.financialcommittee_close_V3.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* financialcommittee_close_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.financialcommittee_close_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* financialcommittee_disapprove_proposal_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.financialcommittee_disapprove_proposal_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* financialmembership_add_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.financialmembership_add_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* financialmembership_remove_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.financialmembership_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* financialmembership_swap_member_V3 - remove */;
            return _toStringAccountId_V3(
                &m->nested.financialmembership_swap_member_V3.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* financialmembership_swap_member_V3 - add */;
            return _toStringAccountId_V3(
                &m->nested.financialmembership_swap_member_V3.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* financialmembership_reset_members_V3 - members */;
            return _toStringVecAccountId_V3(
                &m->nested.financialmembership_reset_members_V3.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* financialmembership_change_key_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->nested.financialmembership_change_key_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* financialmembership_set_prime_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.financialmembership_set_prime_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* rootcommittee_set_members_V3 - new_members */;
            return _toStringVecAccountId_V3(
                &m->basic.rootcommittee_set_members_V3.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rootcommittee_set_members_V3 - prime */;
            return _toStringOptionAccountId_V3(
                &m->basic.rootcommittee_set_members_V3.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rootcommittee_set_members_V3 - old_count */;
            return _toStringMemberCount_V3(
                &m->basic.rootcommittee_set_members_V3.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* rootcommittee_execute_V3 - proposal */;
            return _toStringProposal(
                &m->basic.rootcommittee_execute_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rootcommittee_execute_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.rootcommittee_execute_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* rootcommittee_propose_V3 - threshold */;
            return _toStringCompactMemberCount_V3(
                &m->basic.rootcommittee_propose_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rootcommittee_propose_V3 - proposal */;
            return _toStringProposal(
                &m->basic.rootcommittee_propose_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rootcommittee_propose_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.rootcommittee_propose_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* rootcommittee_vote_V3 - proposal */;
            return _toStringHash(
                &m->basic.rootcommittee_vote_V3.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rootcommittee_vote_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.rootcommittee_vote_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rootcommittee_vote_V3 - approve */;
            return _toStringbool(
                &m->basic.rootcommittee_vote_V3.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* rootcommittee_close_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.rootcommittee_close_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rootcommittee_close_V3 - index */;
            return _toStringCompactProposalIndex_V3(
                &m->basic.rootcommittee_close_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rootcommittee_close_V3 - proposal_weight_bound */;
            return _toStringCompactWeight_V3(
                &m->basic.rootcommittee_close_V3.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rootcommittee_close_V3 - length_bound */;
            return _toStringCompactu32(
                &m->basic.rootcommittee_close_V3.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0: /* rootcommittee_disapprove_proposal_V3 - proposal_hash */;
            return _toStringHash(
                &m->basic.rootcommittee_disapprove_proposal_V3.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* rootmembership_add_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.rootmembership_add_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* rootmembership_remove_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.rootmembership_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* rootmembership_swap_member_V3 - remove */;
            return _toStringAccountId_V3(
                &m->nested.rootmembership_swap_member_V3.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rootmembership_swap_member_V3 - add */;
            return _toStringAccountId_V3(
                &m->nested.rootmembership_swap_member_V3.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* rootmembership_reset_members_V3 - members */;
            return _toStringVecAccountId_V3(
                &m->nested.rootmembership_reset_members_V3.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* rootmembership_change_key_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->nested.rootmembership_change_key_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* rootmembership_set_prime_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.rootmembership_set_prime_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5126: /* module 20 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V3 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V3.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V3 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V3 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V3.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V3 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V3 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V3.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V3 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V3.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_named_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_named_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V3 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V3 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V3.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V3 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V3.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_after_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_after_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V3 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V3 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V3.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V3 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V3.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V3 - maybe_periodic */;
            return _toStringOptionPeriod_V3(
                &m->basic.scheduler_schedule_named_after_V3.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V3 - priority */;
            return _toStringPriority_V3(
                &m->basic.scheduler_schedule_named_after_V3.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V3 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* amendments_propose_V3 - amendment */;
            return _toStringAmendment_V3(
                &m->nested.amendments_propose_V3.amendment,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0: /* amendments_veto_V3 - amendment_id */;
            return _toStringu64(
                &m->nested.amendments_veto_V3.amendment_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* mandate_apply_V3 - call */;
            return _toStringCall(
                &m->nested.mandate_apply_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* companyreserve_spend_V3 - to */;
            return _toStringAccountId_V3(
                &m->nested.companyreserve_spend_V3.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* companyreserve_spend_V3 - amount */;
            return _toStringBalanceOf(
                &m->nested.companyreserve_spend_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* companyreserve_tip_V3 - amount */;
            return _toStringBalanceOf(
                &m->nested.companyreserve_tip_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* companyreserve_apply_as_V3 - call */;
            return _toStringCall(
                &m->nested.companyreserve_apply_as_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* internationalreserve_spend_V3 - to */;
            return _toStringAccountId_V3(
                &m->nested.internationalreserve_spend_V3.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* internationalreserve_spend_V3 - amount */;
            return _toStringBalanceOf(
                &m->nested.internationalreserve_spend_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* internationalreserve_tip_V3 - amount */;
            return _toStringBalanceOf(
                &m->nested.internationalreserve_tip_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* internationalreserve_apply_as_V3 - call */;
            return _toStringCall(
                &m->nested.internationalreserve_apply_as_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* usareserve_spend_V3 - to */;
            return _toStringAccountId_V3(
                &m->nested.usareserve_spend_V3.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* usareserve_spend_V3 - amount */;
            return _toStringBalanceOf(
                &m->nested.usareserve_spend_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* usareserve_tip_V3 - amount */;
            return _toStringBalanceOf(
                &m->nested.usareserve_tip_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* usareserve_apply_as_V3 - call */;
            return _toStringCall(
                &m->nested.usareserve_apply_as_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_add_vesting_schedule_V3 - dest */;
            return _toStringLookupSource_V3(
                &m->nested.vesting_add_vesting_schedule_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_add_vesting_schedule_V3 - schedule */;
            return _toStringVestingScheduleOf_V3(
                &m->nested.vesting_add_vesting_schedule_V3.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_cancel_all_vesting_schedules_V3 - who */;
            return _toStringLookupSource_V3(
                &m->nested.vesting_cancel_all_vesting_schedules_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_cancel_all_vesting_schedules_V3 - funds_collector */;
            return _toStringLookupSource_V3(
                &m->nested.vesting_cancel_all_vesting_schedules_V3.funds_collector,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_cancel_all_vesting_schedules_V3 - limit_to_free_balance */;
            return _toStringbool(
                &m->nested.vesting_cancel_all_vesting_schedules_V3.limit_to_free_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V3 - index */;
            return _toStringu16(
                &m->nested.utility_as_derivative_V3.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V3 - call */;
            return _toStringCall(
                &m->nested.utility_as_derivative_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->nested.multisig_as_multi_threshold_1_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V3 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V3 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->nested.multisig_as_multi_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V3 - maybe_timepoint */;
            return _toStringOptionTimepoint_V3(
                &m->nested.multisig_as_multi_V3.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V3 - call */;
            return _toStringOpaqueCall_V3(
                &m->nested.multisig_as_multi_V3.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V3 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V3.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V3 - max_weight */;
            return _toStringWeight_V3(
                &m->nested.multisig_as_multi_V3.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V3 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->nested.multisig_approve_as_multi_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V3 - maybe_timepoint */;
            return _toStringOptionTimepoint_V3(
                &m->nested.multisig_approve_as_multi_V3.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V3 - call_hash */;
            return _toStringu8_array_32_V3(
                &m->nested.multisig_approve_as_multi_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V3 - max_weight */;
            return _toStringWeight_V3(
                &m->nested.multisig_approve_as_multi_V3.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V3 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V3.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V3 - other_signatories */;
            return _toStringVecAccountId_V3(
                &m->nested.multisig_cancel_as_multi_V3.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V3 - timepoint */;
            return _toStringTimepoint_V3(
                &m->nested.multisig_cancel_as_multi_V3.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V3 - call_hash */;
            return _toStringu8_array_32_V3(
                &m->nested.multisig_cancel_as_multi_V3.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_update_schedule_V3 - schedule */;
            return _toStringSchedule_V3(
                &m->basic.contracts_update_schedule_V3.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_call_V3 - dest */;
            return _toStringLookupSource_V3(
                &m->basic.contracts_call_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V3 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_call_V3.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V3 - gas_limit */;
            return _toStringCompactWeight_V3(
                &m->basic.contracts_call_V3.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V3 - data */;
            return _toStringBytes(
                &m->basic.contracts_call_V3.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_V3 - endowment */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_instantiate_with_code_V3.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_V3 - gas_limit */;
            return _toStringCompactWeight_V3(
                &m->basic.contracts_instantiate_with_code_V3.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_V3 - code */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_V3.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_V3 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_V3.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_V3 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_V3.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V3 - endowment */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_instantiate_V3.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V3 - gas_limit */;
            return _toStringCompactWeight_V3(
                &m->basic.contracts_instantiate_V3.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V3 - code_hash */;
            return _toStringCodeHash_V3(
                &m->basic.contracts_instantiate_V3.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V3 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V3.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V3 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V3.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_claim_surcharge_V3 - dest */;
            return _toStringAccountId_V3(
                &m->basic.contracts_claim_surcharge_V3.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_claim_surcharge_V3 - aux_sender */;
            return _toStringOptionAccountId_V3(
                &m->basic.contracts_claim_surcharge_V3.aux_sender,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* pkitcr_apply_V3 - metadata */;
            return _toStringBytes(
                &m->nested.pkitcr_apply_V3.metadata,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pkitcr_apply_V3 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pkitcr_apply_V3.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* pkitcr_counter_V3 - member */;
            return _toStringAccountId_V3(
                &m->nested.pkitcr_counter_V3.member,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pkitcr_counter_V3 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pkitcr_counter_V3.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* pkitcr_vote_V3 - member */;
            return _toStringAccountId_V3(
                &m->nested.pkitcr_vote_V3.member,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pkitcr_vote_V3 - supporting */;
            return _toStringbool(
                &m->nested.pkitcr_vote_V3.supporting,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pkitcr_vote_V3 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pkitcr_vote_V3.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* pkitcr_challenge_V3 - member */;
            return _toStringAccountId_V3(
                &m->nested.pkitcr_challenge_V3.member,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pkitcr_challenge_V3 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pkitcr_challenge_V3.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* pkirootoftrust_book_slot_V3 - certificate_id */;
            return _toStringCertificateId_V3(
                &m->nested.pkirootoftrust_book_slot_V3.certificate_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* pkirootoftrust_renew_slot_V3 - certificate_id */;
            return _toStringCertificateId_V3(
                &m->nested.pkirootoftrust_renew_slot_V3.certificate_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* pkirootoftrust_revoke_slot_V3 - certificate_id */;
            return _toStringCertificateId_V3(
                &m->nested.pkirootoftrust_revoke_slot_V3.certificate_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* pkirootoftrust_revoke_child_V3 - root */;
            return _toStringCertificateId_V3(
                &m->nested.pkirootoftrust_revoke_child_V3.root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pkirootoftrust_revoke_child_V3 - child */;
            return _toStringCertificateId_V3(
                &m->nested.pkirootoftrust_revoke_child_V3.child,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* allocations_allocate_V3 - to */;
            return _toStringAccountId_V3(
                &m->basic.allocations_allocate_V3.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* allocations_allocate_V3 - amount */;
            return _toStringBalanceOf(
                &m->basic.allocations_allocate_V3.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* allocations_allocate_V3 - proof */;
            return _toStringBytes(
                &m->basic.allocations_allocate_V3.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_add_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.allocationsoracles_add_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_remove_member_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.allocationsoracles_remove_member_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_swap_member_V3 - remove */;
            return _toStringAccountId_V3(
                &m->nested.allocationsoracles_swap_member_V3.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* allocationsoracles_swap_member_V3 - add */;
            return _toStringAccountId_V3(
                &m->nested.allocationsoracles_swap_member_V3.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_reset_members_V3 - members */;
            return _toStringVecAccountId_V3(
                &m->nested.allocationsoracles_reset_members_V3.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_change_key_V3 - new_ */;
            return _toStringAccountId_V3(
                &m->nested.allocationsoracles_change_key_V3.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* allocationsoracles_set_prime_V3 - who */;
            return _toStringAccountId_V3(
                &m->nested.allocationsoracles_set_prime_V3.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V3(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V3(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: // Timestamp:Set
    case 1280: // Babe:Report equivocation
    case 1281: // Babe:Report equivocation unsigned
    case 1536: // Grandpa:Report equivocation
    case 1537: // Grandpa:Report equivocation unsigned
    case 1538: // Grandpa:Note stalled
    case 1792: // Authorship:Set uncles
    case 2048: // ImOnline:Heartbeat
    case 3072: // Session:Set keys
    case 3073: // Session:Purge keys
    case 4352: // FinancialCommittee:Set members
    case 4353: // FinancialCommittee:Execute
    case 4354: // FinancialCommittee:Propose
    case 4355: // FinancialCommittee:Vote
    case 4356: // FinancialCommittee:Close
    case 4357: // FinancialCommittee:Disapprove proposal
    case 4864: // RootCommittee:Set members
    case 4865: // RootCommittee:Execute
    case 4866: // RootCommittee:Propose
    case 4867: // RootCommittee:Vote
    case 4868: // RootCommittee:Close
    case 4869: // RootCommittee:Disapprove proposal
    case 5376: // Scheduler:Schedule
    case 5377: // Scheduler:Cancel
    case 5378: // Scheduler:Schedule named
    case 5379: // Scheduler:Cancel named
    case 5380: // Scheduler:Schedule after
    case 5381: // Scheduler:Schedule named after
    case 7680: // Contracts:Update schedule
    case 7681: // Contracts:Call
    case 7682: // Contracts:Instantiate with code
    case 7683: // Contracts:Instantiate
    case 7684: // Contracts:Claim surcharge
    case 8704: // Allocations:Allocate
        return false;
    default:
        return true;
    }
}
