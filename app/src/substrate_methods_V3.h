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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V3 0
#define PD_CALL_TIMESTAMP_V3 1
#define PD_CALL_INDICES_V3 2
#define PD_CALL_BALANCES_V3 3
#define PD_CALL_RANDOMNESSCOLLECTIVEFLIP_V3 5
#define PD_CALL_BABE_V3 6
#define PD_CALL_GRANDPA_V3 7
#define PD_CALL_AUTHORSHIP_V3 8
#define PD_CALL_IMONLINE_V3 9
#define PD_CALL_OFFENCES_V3 10
#define PD_CALL_VALIDATORSSET_V3 11
#define PD_CALL_SESSION_V3 12
#define PD_CALL_AUTHORITYDISCOVERY_V3 14
#define PD_CALL_TECHNICALCOMMITTEE_V3 15
#define PD_CALL_TECHNICALMEMBERSHIP_V3 16
#define PD_CALL_FINANCIALCOMMITTEE_V3 17
#define PD_CALL_FINANCIALMEMBERSHIP_V3 18
#define PD_CALL_ROOTCOMMITTEE_V3 19
#define PD_CALL_ROOTMEMBERSHIP_V3 20
#define PD_CALL_SCHEDULER_V3 21
#define PD_CALL_AMENDMENTS_V3 22
#define PD_CALL_MANDATE_V3 23
#define PD_CALL_COMPANYRESERVE_V3 24
#define PD_CALL_INTERNATIONALRESERVE_V3 25
#define PD_CALL_USARESERVE_V3 26
#define PD_CALL_VESTING_V3 27
#define PD_CALL_IDENTITY_V3 28
#define PD_CALL_RECOVERY_V3 29
#define PD_CALL_UTILITY_V3 30
#define PD_CALL_PROXY_V3 31
#define PD_CALL_MULTISIG_V3 32
#define PD_CALL_CONTRACTS_V3 33
#define PD_CALL_PKITCR_V3 34
#define PD_CALL_PKIROOTOFTRUST_V3 35
#define PD_CALL_EMERGENCYSHUTDOWN_V3 36
#define PD_CALL_ALLOCATIONS_V3 37
#define PD_CALL_ALLOCATIONSORACLES_V3 38

#define PD_CALL_SESSION_SET_KEYS_V3 0
typedef struct {
    pd_Keys_V3_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V3_t;

#define PD_CALL_SESSION_PURGE_KEYS_V3 1
typedef struct {
} pd_session_purge_keys_V3_t;

#define PD_CALL_UTILITY_BATCH_V3 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V3_t;

#define PD_CALL_UTILITY_BATCH_ALL_V3 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V3_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_TIMESTAMP_SET_V3 0
typedef struct {
    pd_CompactMoment_V3_t now;
} pd_timestamp_set_V3_t;

#define PD_CALL_INDICES_CLAIM_V3 0
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_claim_V3_t;

#define PD_CALL_INDICES_TRANSFER_V3 1
typedef struct {
    pd_AccountId_V3_t new_;
    pd_AccountIndex_V3_t index;
} pd_indices_transfer_V3_t;

#define PD_CALL_INDICES_FREE_V3 2
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_free_V3_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V3 3
typedef struct {
    pd_AccountId_V3_t new_;
    pd_AccountIndex_V3_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V3_t;

#define PD_CALL_INDICES_FREEZE_V3 4
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_freeze_V3_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V3 0
typedef struct {
    pd_BabeEquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_babe_report_equivocation_V3_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V3 1
typedef struct {
    pd_BabeEquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V3_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V3 0
typedef struct {
    pd_GrandpaEquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_grandpa_report_equivocation_V3_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V3 1
typedef struct {
    pd_GrandpaEquivocationProof_V3_t equivocation_proof;
    pd_KeyOwnerProof_V3_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V3_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V3 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V3_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V3 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V3_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V3 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V3_t _signature;
} pd_imonline_heartbeat_V3_t;

#define PD_CALL_VALIDATORSSET_ADD_MEMBER_V3 0
typedef struct {
    pd_AccountId_V3_t who;
} pd_validatorsset_add_member_V3_t;

#define PD_CALL_VALIDATORSSET_REMOVE_MEMBER_V3 1
typedef struct {
    pd_AccountId_V3_t who;
} pd_validatorsset_remove_member_V3_t;

#define PD_CALL_VALIDATORSSET_SWAP_MEMBER_V3 2
typedef struct {
    pd_AccountId_V3_t remove;
    pd_AccountId_V3_t add;
} pd_validatorsset_swap_member_V3_t;

#define PD_CALL_VALIDATORSSET_RESET_MEMBERS_V3 3
typedef struct {
    pd_VecAccountId_V3_t members;
} pd_validatorsset_reset_members_V3_t;

#define PD_CALL_VALIDATORSSET_CHANGE_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t new_;
} pd_validatorsset_change_key_V3_t;

#define PD_CALL_VALIDATORSSET_SET_PRIME_V3 5
typedef struct {
    pd_AccountId_V3_t who;
} pd_validatorsset_set_prime_V3_t;

#define PD_CALL_VALIDATORSSET_CLEAR_PRIME_V3 6
typedef struct {
} pd_validatorsset_clear_prime_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V3 0
typedef struct {
    pd_VecAccountId_V3_t new_members;
    pd_OptionAccountId_V3_t prime;
    pd_MemberCount_V3_t old_count;
} pd_technicalcommittee_set_members_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V3 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V3 2
typedef struct {
    pd_CompactMemberCount_V3_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V3 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V3 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V3_t index;
    pd_CompactWeight_V3_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V3 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V3 0
typedef struct {
    pd_AccountId_V3_t who;
} pd_technicalmembership_add_member_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V3 1
typedef struct {
    pd_AccountId_V3_t who;
} pd_technicalmembership_remove_member_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V3 2
typedef struct {
    pd_AccountId_V3_t remove;
    pd_AccountId_V3_t add;
} pd_technicalmembership_swap_member_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V3 3
typedef struct {
    pd_VecAccountId_V3_t members;
} pd_technicalmembership_reset_members_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t new_;
} pd_technicalmembership_change_key_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V3 5
typedef struct {
    pd_AccountId_V3_t who;
} pd_technicalmembership_set_prime_V3_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V3 6
typedef struct {
} pd_technicalmembership_clear_prime_V3_t;

#define PD_CALL_FINANCIALCOMMITTEE_SET_MEMBERS_V3 0
typedef struct {
    pd_VecAccountId_V3_t new_members;
    pd_OptionAccountId_V3_t prime;
    pd_MemberCount_V3_t old_count;
} pd_financialcommittee_set_members_V3_t;

#define PD_CALL_FINANCIALCOMMITTEE_EXECUTE_V3 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_financialcommittee_execute_V3_t;

#define PD_CALL_FINANCIALCOMMITTEE_PROPOSE_V3 2
typedef struct {
    pd_CompactMemberCount_V3_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_financialcommittee_propose_V3_t;

#define PD_CALL_FINANCIALCOMMITTEE_VOTE_V3 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_financialcommittee_vote_V3_t;

#define PD_CALL_FINANCIALCOMMITTEE_CLOSE_V3 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V3_t index;
    pd_CompactWeight_V3_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_financialcommittee_close_V3_t;

#define PD_CALL_FINANCIALCOMMITTEE_DISAPPROVE_PROPOSAL_V3 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_financialcommittee_disapprove_proposal_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_ADD_MEMBER_V3 0
typedef struct {
    pd_AccountId_V3_t who;
} pd_financialmembership_add_member_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_REMOVE_MEMBER_V3 1
typedef struct {
    pd_AccountId_V3_t who;
} pd_financialmembership_remove_member_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_SWAP_MEMBER_V3 2
typedef struct {
    pd_AccountId_V3_t remove;
    pd_AccountId_V3_t add;
} pd_financialmembership_swap_member_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_RESET_MEMBERS_V3 3
typedef struct {
    pd_VecAccountId_V3_t members;
} pd_financialmembership_reset_members_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_CHANGE_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t new_;
} pd_financialmembership_change_key_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_SET_PRIME_V3 5
typedef struct {
    pd_AccountId_V3_t who;
} pd_financialmembership_set_prime_V3_t;

#define PD_CALL_FINANCIALMEMBERSHIP_CLEAR_PRIME_V3 6
typedef struct {
} pd_financialmembership_clear_prime_V3_t;

#define PD_CALL_ROOTCOMMITTEE_SET_MEMBERS_V3 0
typedef struct {
    pd_VecAccountId_V3_t new_members;
    pd_OptionAccountId_V3_t prime;
    pd_MemberCount_V3_t old_count;
} pd_rootcommittee_set_members_V3_t;

#define PD_CALL_ROOTCOMMITTEE_EXECUTE_V3 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_rootcommittee_execute_V3_t;

#define PD_CALL_ROOTCOMMITTEE_PROPOSE_V3 2
typedef struct {
    pd_CompactMemberCount_V3_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_rootcommittee_propose_V3_t;

#define PD_CALL_ROOTCOMMITTEE_VOTE_V3 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_rootcommittee_vote_V3_t;

#define PD_CALL_ROOTCOMMITTEE_CLOSE_V3 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V3_t index;
    pd_CompactWeight_V3_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_rootcommittee_close_V3_t;

#define PD_CALL_ROOTCOMMITTEE_DISAPPROVE_PROPOSAL_V3 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_rootcommittee_disapprove_proposal_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_ADD_MEMBER_V3 0
typedef struct {
    pd_AccountId_V3_t who;
} pd_rootmembership_add_member_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_REMOVE_MEMBER_V3 1
typedef struct {
    pd_AccountId_V3_t who;
} pd_rootmembership_remove_member_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_SWAP_MEMBER_V3 2
typedef struct {
    pd_AccountId_V3_t remove;
    pd_AccountId_V3_t add;
} pd_rootmembership_swap_member_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_RESET_MEMBERS_V3 3
typedef struct {
    pd_VecAccountId_V3_t members;
} pd_rootmembership_reset_members_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_CHANGE_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t new_;
} pd_rootmembership_change_key_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_SET_PRIME_V3 5
typedef struct {
    pd_AccountId_V3_t who;
} pd_rootmembership_set_prime_V3_t;

#define PD_CALL_ROOTMEMBERSHIP_CLEAR_PRIME_V3 6
typedef struct {
} pd_rootmembership_clear_prime_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V3 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V3_t;

#define PD_CALL_SCHEDULER_CANCEL_V3 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V3 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V3_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V3 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V3 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V3_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V3 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V3_t maybe_periodic;
    pd_Priority_V3_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V3_t;

#define PD_CALL_AMENDMENTS_PROPOSE_V3 0
typedef struct {
    pd_Amendment_V3_t amendment;
} pd_amendments_propose_V3_t;

#define PD_CALL_AMENDMENTS_VETO_V3 1
typedef struct {
    pd_u64_t amendment_id;
} pd_amendments_veto_V3_t;

#define PD_CALL_MANDATE_APPLY_V3 0
typedef struct {
    pd_Call_t call;
} pd_mandate_apply_V3_t;

#define PD_CALL_COMPANYRESERVE_SPEND_V3 0
typedef struct {
    pd_AccountId_V3_t to;
    pd_BalanceOf_t amount;
} pd_companyreserve_spend_V3_t;

#define PD_CALL_COMPANYRESERVE_TIP_V3 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_companyreserve_tip_V3_t;

#define PD_CALL_COMPANYRESERVE_APPLY_AS_V3 2
typedef struct {
    pd_Call_t call;
} pd_companyreserve_apply_as_V3_t;

#define PD_CALL_INTERNATIONALRESERVE_SPEND_V3 0
typedef struct {
    pd_AccountId_V3_t to;
    pd_BalanceOf_t amount;
} pd_internationalreserve_spend_V3_t;

#define PD_CALL_INTERNATIONALRESERVE_TIP_V3 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_internationalreserve_tip_V3_t;

#define PD_CALL_INTERNATIONALRESERVE_APPLY_AS_V3 2
typedef struct {
    pd_Call_t call;
} pd_internationalreserve_apply_as_V3_t;

#define PD_CALL_USARESERVE_SPEND_V3 0
typedef struct {
    pd_AccountId_V3_t to;
    pd_BalanceOf_t amount;
} pd_usareserve_spend_V3_t;

#define PD_CALL_USARESERVE_TIP_V3 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_usareserve_tip_V3_t;

#define PD_CALL_USARESERVE_APPLY_AS_V3 2
typedef struct {
    pd_Call_t call;
} pd_usareserve_apply_as_V3_t;

#define PD_CALL_VESTING_CLAIM_V3 0
typedef struct {
} pd_vesting_claim_V3_t;

#define PD_CALL_VESTING_ADD_VESTING_SCHEDULE_V3 1
typedef struct {
    pd_LookupSource_V3_t dest;
    pd_VestingScheduleOf_V3_t schedule;
} pd_vesting_add_vesting_schedule_V3_t;

#define PD_CALL_VESTING_CANCEL_ALL_VESTING_SCHEDULES_V3 2
typedef struct {
    pd_LookupSource_V3_t who;
    pd_LookupSource_V3_t funds_collector;
    pd_bool_t limit_to_free_balance;
} pd_vesting_cancel_all_vesting_schedules_V3_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V3 0
typedef struct {
    pd_AccountId_V3_t account;
} pd_identity_add_registrar_V3_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V3 1
typedef struct {
    pd_IdentityInfo_V3_t info;
} pd_identity_set_identity_V3_t;

#define PD_CALL_IDENTITY_SET_SUBS_V3 2
typedef struct {
    pd_VecTupleAccountIdData_V3_t subs;
} pd_identity_set_subs_V3_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V3 3
typedef struct {
} pd_identity_clear_identity_V3_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V3 4
typedef struct {
    pd_CompactRegistrarIndex_V3_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V3_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V3 5
typedef struct {
    pd_RegistrarIndex_V3_t reg_index;
} pd_identity_cancel_request_V3_t;

#define PD_CALL_IDENTITY_SET_FEE_V3 6
typedef struct {
    pd_CompactRegistrarIndex_V3_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V3_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V3 7
typedef struct {
    pd_CompactRegistrarIndex_V3_t index;
    pd_AccountId_V3_t new_;
} pd_identity_set_account_id_V3_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V3 8
typedef struct {
    pd_CompactRegistrarIndex_V3_t index;
    pd_IdentityFields_V3_t fields;
} pd_identity_set_fields_V3_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V3 9
typedef struct {
    pd_CompactRegistrarIndex_V3_t reg_index;
    pd_LookupSource_V3_t target;
    pd_IdentityJudgement_V3_t judgement;
} pd_identity_provide_judgement_V3_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V3 10
typedef struct {
    pd_LookupSource_V3_t target;
} pd_identity_kill_identity_V3_t;

#define PD_CALL_IDENTITY_ADD_SUB_V3 11
typedef struct {
    pd_LookupSource_V3_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V3_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V3 12
typedef struct {
    pd_LookupSource_V3_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V3_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V3 13
typedef struct {
    pd_LookupSource_V3_t sub;
} pd_identity_remove_sub_V3_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V3 14
typedef struct {
} pd_identity_quit_sub_V3_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V3 0
typedef struct {
    pd_AccountId_V3_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_V3_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V3 1
typedef struct {
    pd_AccountId_V3_t lost;
    pd_AccountId_V3_t rescuer;
} pd_recovery_set_recovered_V3_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V3 2
typedef struct {
    pd_VecAccountId_V3_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V3_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V3 3
typedef struct {
    pd_AccountId_V3_t account;
} pd_recovery_initiate_recovery_V3_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V3 4
typedef struct {
    pd_AccountId_V3_t lost;
    pd_AccountId_V3_t rescuer;
} pd_recovery_vouch_recovery_V3_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V3 5
typedef struct {
    pd_AccountId_V3_t account;
} pd_recovery_claim_recovery_V3_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V3 6
typedef struct {
    pd_AccountId_V3_t rescuer;
} pd_recovery_close_recovery_V3_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V3 7
typedef struct {
} pd_recovery_remove_recovery_V3_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V3 8
typedef struct {
    pd_AccountId_V3_t account;
} pd_recovery_cancel_recovered_V3_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V3 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V3_t;

#define PD_CALL_PROXY_ADD_PROXY_V3 1
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V3_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V3 2
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V3_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V3 3
typedef struct {
} pd_proxy_remove_proxies_V3_t;

#define PD_CALL_PROXY_ANONYMOUS_V3 4
typedef struct {
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V3_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V3 5
typedef struct {
    pd_AccountId_V3_t spawner;
    pd_ProxyType_V3_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V3_t;

#define PD_CALL_PROXY_ANNOUNCE_V3 6
typedef struct {
    pd_AccountId_V3_t real;
    pd_CallHashOf_V3_t call_hash;
} pd_proxy_announce_V3_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V3 7
typedef struct {
    pd_AccountId_V3_t real;
    pd_CallHashOf_V3_t call_hash;
} pd_proxy_remove_announcement_V3_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V3 8
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_CallHashOf_V3_t call_hash;
} pd_proxy_reject_announcement_V3_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V3 9
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_AccountId_V3_t real;
    pd_OptionProxyType_V3_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V3_t;

#define PD_CALL_CONTRACTS_UPDATE_SCHEDULE_V3 0
typedef struct {
    pd_Schedule_V3_t schedule;
} pd_contracts_update_schedule_V3_t;

#define PD_CALL_CONTRACTS_CALL_V3 1
typedef struct {
    pd_LookupSource_V3_t dest;
    pd_CompactBalanceOf_t value;
    pd_CompactWeight_V3_t gas_limit;
    pd_Bytes_t data;
} pd_contracts_call_V3_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V3 2
typedef struct {
    pd_CompactBalanceOf_t endowment;
    pd_CompactWeight_V3_t gas_limit;
    pd_Bytes_t code;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_with_code_V3_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V3 3
typedef struct {
    pd_CompactBalanceOf_t endowment;
    pd_CompactWeight_V3_t gas_limit;
    pd_CodeHash_V3_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V3_t;

#define PD_CALL_CONTRACTS_CLAIM_SURCHARGE_V3 4
typedef struct {
    pd_AccountId_V3_t dest;
    pd_OptionAccountId_V3_t aux_sender;
} pd_contracts_claim_surcharge_V3_t;

#define PD_CALL_PKITCR_APPLY_V3 0
typedef struct {
    pd_Bytes_t metadata;
    pd_BalanceOf_t deposit;
} pd_pkitcr_apply_V3_t;

#define PD_CALL_PKITCR_COUNTER_V3 1
typedef struct {
    pd_AccountId_V3_t member;
    pd_BalanceOf_t deposit;
} pd_pkitcr_counter_V3_t;

#define PD_CALL_PKITCR_VOTE_V3 2
typedef struct {
    pd_AccountId_V3_t member;
    pd_bool_t supporting;
    pd_BalanceOf_t deposit;
} pd_pkitcr_vote_V3_t;

#define PD_CALL_PKITCR_CHALLENGE_V3 3
typedef struct {
    pd_AccountId_V3_t member;
    pd_BalanceOf_t deposit;
} pd_pkitcr_challenge_V3_t;

#define PD_CALL_PKIROOTOFTRUST_BOOK_SLOT_V3 0
typedef struct {
    pd_CertificateId_V3_t certificate_id;
} pd_pkirootoftrust_book_slot_V3_t;

#define PD_CALL_PKIROOTOFTRUST_RENEW_SLOT_V3 1
typedef struct {
    pd_CertificateId_V3_t certificate_id;
} pd_pkirootoftrust_renew_slot_V3_t;

#define PD_CALL_PKIROOTOFTRUST_REVOKE_SLOT_V3 2
typedef struct {
    pd_CertificateId_V3_t certificate_id;
} pd_pkirootoftrust_revoke_slot_V3_t;

#define PD_CALL_PKIROOTOFTRUST_REVOKE_CHILD_V3 3
typedef struct {
    pd_CertificateId_V3_t root;
    pd_CertificateId_V3_t child;
} pd_pkirootoftrust_revoke_child_V3_t;

#define PD_CALL_EMERGENCYSHUTDOWN_TOGGLE_V3 0
typedef struct {
} pd_emergencyshutdown_toggle_V3_t;

#define PD_CALL_ALLOCATIONS_ALLOCATE_V3 0
typedef struct {
    pd_AccountId_V3_t to;
    pd_BalanceOf_t amount;
    pd_Bytes_t proof;
} pd_allocations_allocate_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_ADD_MEMBER_V3 0
typedef struct {
    pd_AccountId_V3_t who;
} pd_allocationsoracles_add_member_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_REMOVE_MEMBER_V3 1
typedef struct {
    pd_AccountId_V3_t who;
} pd_allocationsoracles_remove_member_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_SWAP_MEMBER_V3 2
typedef struct {
    pd_AccountId_V3_t remove;
    pd_AccountId_V3_t add;
} pd_allocationsoracles_swap_member_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_RESET_MEMBERS_V3 3
typedef struct {
    pd_VecAccountId_V3_t members;
} pd_allocationsoracles_reset_members_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_CHANGE_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t new_;
} pd_allocationsoracles_change_key_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_SET_PRIME_V3 5
typedef struct {
    pd_AccountId_V3_t who;
} pd_allocationsoracles_set_prime_V3_t;

#define PD_CALL_ALLOCATIONSORACLES_CLEAR_PRIME_V3 6
typedef struct {
} pd_allocationsoracles_clear_prime_V3_t;

#endif

typedef union {
    pd_session_set_keys_V3_t session_set_keys_V3;
    pd_session_purge_keys_V3_t session_purge_keys_V3;
    pd_utility_batch_V3_t utility_batch_V3;
    pd_utility_batch_all_V3_t utility_batch_all_V3;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V3_t timestamp_set_V3;
    pd_indices_claim_V3_t indices_claim_V3;
    pd_indices_transfer_V3_t indices_transfer_V3;
    pd_indices_free_V3_t indices_free_V3;
    pd_indices_force_transfer_V3_t indices_force_transfer_V3;
    pd_indices_freeze_V3_t indices_freeze_V3;
    pd_babe_report_equivocation_V3_t babe_report_equivocation_V3;
    pd_babe_report_equivocation_unsigned_V3_t babe_report_equivocation_unsigned_V3;
    pd_grandpa_report_equivocation_V3_t grandpa_report_equivocation_V3;
    pd_grandpa_report_equivocation_unsigned_V3_t grandpa_report_equivocation_unsigned_V3;
    pd_grandpa_note_stalled_V3_t grandpa_note_stalled_V3;
    pd_authorship_set_uncles_V3_t authorship_set_uncles_V3;
    pd_imonline_heartbeat_V3_t imonline_heartbeat_V3;
    pd_validatorsset_add_member_V3_t validatorsset_add_member_V3;
    pd_validatorsset_remove_member_V3_t validatorsset_remove_member_V3;
    pd_validatorsset_swap_member_V3_t validatorsset_swap_member_V3;
    pd_validatorsset_reset_members_V3_t validatorsset_reset_members_V3;
    pd_validatorsset_change_key_V3_t validatorsset_change_key_V3;
    pd_validatorsset_set_prime_V3_t validatorsset_set_prime_V3;
    pd_validatorsset_clear_prime_V3_t validatorsset_clear_prime_V3;
    pd_technicalcommittee_set_members_V3_t technicalcommittee_set_members_V3;
    pd_technicalcommittee_execute_V3_t technicalcommittee_execute_V3;
    pd_technicalcommittee_propose_V3_t technicalcommittee_propose_V3;
    pd_technicalcommittee_vote_V3_t technicalcommittee_vote_V3;
    pd_technicalcommittee_close_V3_t technicalcommittee_close_V3;
    pd_technicalcommittee_disapprove_proposal_V3_t technicalcommittee_disapprove_proposal_V3;
    pd_technicalmembership_add_member_V3_t technicalmembership_add_member_V3;
    pd_technicalmembership_remove_member_V3_t technicalmembership_remove_member_V3;
    pd_technicalmembership_swap_member_V3_t technicalmembership_swap_member_V3;
    pd_technicalmembership_reset_members_V3_t technicalmembership_reset_members_V3;
    pd_technicalmembership_change_key_V3_t technicalmembership_change_key_V3;
    pd_technicalmembership_set_prime_V3_t technicalmembership_set_prime_V3;
    pd_technicalmembership_clear_prime_V3_t technicalmembership_clear_prime_V3;
    pd_financialcommittee_set_members_V3_t financialcommittee_set_members_V3;
    pd_financialcommittee_execute_V3_t financialcommittee_execute_V3;
    pd_financialcommittee_propose_V3_t financialcommittee_propose_V3;
    pd_financialcommittee_vote_V3_t financialcommittee_vote_V3;
    pd_financialcommittee_close_V3_t financialcommittee_close_V3;
    pd_financialcommittee_disapprove_proposal_V3_t financialcommittee_disapprove_proposal_V3;
    pd_financialmembership_add_member_V3_t financialmembership_add_member_V3;
    pd_financialmembership_remove_member_V3_t financialmembership_remove_member_V3;
    pd_financialmembership_swap_member_V3_t financialmembership_swap_member_V3;
    pd_financialmembership_reset_members_V3_t financialmembership_reset_members_V3;
    pd_financialmembership_change_key_V3_t financialmembership_change_key_V3;
    pd_financialmembership_set_prime_V3_t financialmembership_set_prime_V3;
    pd_financialmembership_clear_prime_V3_t financialmembership_clear_prime_V3;
    pd_rootcommittee_set_members_V3_t rootcommittee_set_members_V3;
    pd_rootcommittee_execute_V3_t rootcommittee_execute_V3;
    pd_rootcommittee_propose_V3_t rootcommittee_propose_V3;
    pd_rootcommittee_vote_V3_t rootcommittee_vote_V3;
    pd_rootcommittee_close_V3_t rootcommittee_close_V3;
    pd_rootcommittee_disapprove_proposal_V3_t rootcommittee_disapprove_proposal_V3;
    pd_rootmembership_add_member_V3_t rootmembership_add_member_V3;
    pd_rootmembership_remove_member_V3_t rootmembership_remove_member_V3;
    pd_rootmembership_swap_member_V3_t rootmembership_swap_member_V3;
    pd_rootmembership_reset_members_V3_t rootmembership_reset_members_V3;
    pd_rootmembership_change_key_V3_t rootmembership_change_key_V3;
    pd_rootmembership_set_prime_V3_t rootmembership_set_prime_V3;
    pd_rootmembership_clear_prime_V3_t rootmembership_clear_prime_V3;
    pd_scheduler_schedule_V3_t scheduler_schedule_V3;
    pd_scheduler_cancel_V3_t scheduler_cancel_V3;
    pd_scheduler_schedule_named_V3_t scheduler_schedule_named_V3;
    pd_scheduler_cancel_named_V3_t scheduler_cancel_named_V3;
    pd_scheduler_schedule_after_V3_t scheduler_schedule_after_V3;
    pd_scheduler_schedule_named_after_V3_t scheduler_schedule_named_after_V3;
    pd_amendments_propose_V3_t amendments_propose_V3;
    pd_amendments_veto_V3_t amendments_veto_V3;
    pd_mandate_apply_V3_t mandate_apply_V3;
    pd_companyreserve_spend_V3_t companyreserve_spend_V3;
    pd_companyreserve_tip_V3_t companyreserve_tip_V3;
    pd_companyreserve_apply_as_V3_t companyreserve_apply_as_V3;
    pd_internationalreserve_spend_V3_t internationalreserve_spend_V3;
    pd_internationalreserve_tip_V3_t internationalreserve_tip_V3;
    pd_internationalreserve_apply_as_V3_t internationalreserve_apply_as_V3;
    pd_usareserve_spend_V3_t usareserve_spend_V3;
    pd_usareserve_tip_V3_t usareserve_tip_V3;
    pd_usareserve_apply_as_V3_t usareserve_apply_as_V3;
    pd_vesting_claim_V3_t vesting_claim_V3;
    pd_vesting_add_vesting_schedule_V3_t vesting_add_vesting_schedule_V3;
    pd_vesting_cancel_all_vesting_schedules_V3_t vesting_cancel_all_vesting_schedules_V3;
    pd_identity_add_registrar_V3_t identity_add_registrar_V3;
    pd_identity_set_identity_V3_t identity_set_identity_V3;
    pd_identity_set_subs_V3_t identity_set_subs_V3;
    pd_identity_clear_identity_V3_t identity_clear_identity_V3;
    pd_identity_request_judgement_V3_t identity_request_judgement_V3;
    pd_identity_cancel_request_V3_t identity_cancel_request_V3;
    pd_identity_set_fee_V3_t identity_set_fee_V3;
    pd_identity_set_account_id_V3_t identity_set_account_id_V3;
    pd_identity_set_fields_V3_t identity_set_fields_V3;
    pd_identity_provide_judgement_V3_t identity_provide_judgement_V3;
    pd_identity_kill_identity_V3_t identity_kill_identity_V3;
    pd_identity_add_sub_V3_t identity_add_sub_V3;
    pd_identity_rename_sub_V3_t identity_rename_sub_V3;
    pd_identity_remove_sub_V3_t identity_remove_sub_V3;
    pd_identity_quit_sub_V3_t identity_quit_sub_V3;
    pd_recovery_as_recovered_V3_t recovery_as_recovered_V3;
    pd_recovery_set_recovered_V3_t recovery_set_recovered_V3;
    pd_recovery_create_recovery_V3_t recovery_create_recovery_V3;
    pd_recovery_initiate_recovery_V3_t recovery_initiate_recovery_V3;
    pd_recovery_vouch_recovery_V3_t recovery_vouch_recovery_V3;
    pd_recovery_claim_recovery_V3_t recovery_claim_recovery_V3;
    pd_recovery_close_recovery_V3_t recovery_close_recovery_V3;
    pd_recovery_remove_recovery_V3_t recovery_remove_recovery_V3;
    pd_recovery_cancel_recovered_V3_t recovery_cancel_recovered_V3;
    pd_utility_as_derivative_V3_t utility_as_derivative_V3;
    pd_proxy_add_proxy_V3_t proxy_add_proxy_V3;
    pd_proxy_remove_proxy_V3_t proxy_remove_proxy_V3;
    pd_proxy_remove_proxies_V3_t proxy_remove_proxies_V3;
    pd_proxy_anonymous_V3_t proxy_anonymous_V3;
    pd_proxy_kill_anonymous_V3_t proxy_kill_anonymous_V3;
    pd_proxy_announce_V3_t proxy_announce_V3;
    pd_proxy_remove_announcement_V3_t proxy_remove_announcement_V3;
    pd_proxy_reject_announcement_V3_t proxy_reject_announcement_V3;
    pd_proxy_proxy_announced_V3_t proxy_proxy_announced_V3;
    pd_contracts_update_schedule_V3_t contracts_update_schedule_V3;
    pd_contracts_call_V3_t contracts_call_V3;
    pd_contracts_instantiate_with_code_V3_t contracts_instantiate_with_code_V3;
    pd_contracts_instantiate_V3_t contracts_instantiate_V3;
    pd_contracts_claim_surcharge_V3_t contracts_claim_surcharge_V3;
    pd_pkitcr_apply_V3_t pkitcr_apply_V3;
    pd_pkitcr_counter_V3_t pkitcr_counter_V3;
    pd_pkitcr_vote_V3_t pkitcr_vote_V3;
    pd_pkitcr_challenge_V3_t pkitcr_challenge_V3;
    pd_pkirootoftrust_book_slot_V3_t pkirootoftrust_book_slot_V3;
    pd_pkirootoftrust_renew_slot_V3_t pkirootoftrust_renew_slot_V3;
    pd_pkirootoftrust_revoke_slot_V3_t pkirootoftrust_revoke_slot_V3;
    pd_pkirootoftrust_revoke_child_V3_t pkirootoftrust_revoke_child_V3;
    pd_emergencyshutdown_toggle_V3_t emergencyshutdown_toggle_V3;
    pd_allocations_allocate_V3_t allocations_allocate_V3;
    pd_allocationsoracles_add_member_V3_t allocationsoracles_add_member_V3;
    pd_allocationsoracles_remove_member_V3_t allocationsoracles_remove_member_V3;
    pd_allocationsoracles_swap_member_V3_t allocationsoracles_swap_member_V3;
    pd_allocationsoracles_reset_members_V3_t allocationsoracles_reset_members_V3;
    pd_allocationsoracles_change_key_V3_t allocationsoracles_change_key_V3;
    pd_allocationsoracles_set_prime_V3_t allocationsoracles_set_prime_V3;
    pd_allocationsoracles_clear_prime_V3_t allocationsoracles_clear_prime_V3;
#endif
} pd_MethodBasic_V3_t;

#define PD_CALL_BALANCES_TRANSFER_V3 0
typedef struct {
    pd_LookupSource_V3_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V3_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V3 3
typedef struct {
    pd_LookupSource_V3_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V3_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V3 0
typedef struct {
    pd_Perbill_V3_t _ratio;
} pd_system_fill_block_V3_t;

#define PD_CALL_SYSTEM_REMARK_V3 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V3_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V3 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_V3 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V3 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V3_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V3 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V3_t changes_trie_config;
} pd_system_set_changes_trie_config_V3_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V3 6
typedef struct {
    pd_VecKeyValue_V3_t items;
} pd_system_set_storage_V3_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V3 7
typedef struct {
    pd_VecKey_V3_t keys;
} pd_system_kill_storage_V3_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V3 8
typedef struct {
    pd_Key_V3_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V3_t;

#define PD_CALL_BALANCES_SET_BALANCE_V3 1
typedef struct {
    pd_LookupSource_V3_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V3_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V3 2
typedef struct {
    pd_LookupSource_V3_t source;
    pd_LookupSource_V3_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V3_t;

#define PD_CALL_PROXY_PROXY_V3 0
typedef struct {
    pd_AccountId_V3_t real;
    pd_OptionProxyType_V3_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V3_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V3 0
typedef struct {
    pd_VecAccountId_V3_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V3_t;

#define PD_CALL_MULTISIG_AS_MULTI_V3 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_OptionTimepoint_V3_t maybe_timepoint;
    pd_OpaqueCall_V3_t call;
    pd_bool_t store_call;
    pd_Weight_V3_t max_weight;
} pd_multisig_as_multi_V3_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V3 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_OptionTimepoint_V3_t maybe_timepoint;
    pd_u8_array_32_V3_t call_hash;
    pd_Weight_V3_t max_weight;
} pd_multisig_approve_as_multi_V3_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V3 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_Timepoint_V3_t timepoint;
    pd_u8_array_32_V3_t call_hash;
} pd_multisig_cancel_as_multi_V3_t;

#endif

typedef union {
    pd_balances_transfer_V3_t balances_transfer_V3;
    pd_balances_transfer_keep_alive_V3_t balances_transfer_keep_alive_V3;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V3_t system_fill_block_V3;
    pd_system_remark_V3_t system_remark_V3;
    pd_system_set_heap_pages_V3_t system_set_heap_pages_V3;
    pd_system_set_code_V3_t system_set_code_V3;
    pd_system_set_code_without_checks_V3_t system_set_code_without_checks_V3;
    pd_system_set_changes_trie_config_V3_t system_set_changes_trie_config_V3;
    pd_system_set_storage_V3_t system_set_storage_V3;
    pd_system_kill_storage_V3_t system_kill_storage_V3;
    pd_system_kill_prefix_V3_t system_kill_prefix_V3;
    pd_balances_set_balance_V3_t balances_set_balance_V3;
    pd_balances_force_transfer_V3_t balances_force_transfer_V3;
    pd_proxy_proxy_V3_t proxy_proxy_V3;
    pd_multisig_as_multi_threshold_1_V3_t multisig_as_multi_threshold_1_V3;
    pd_multisig_as_multi_V3_t multisig_as_multi_V3;
    pd_multisig_approve_as_multi_V3_t multisig_approve_as_multi_V3;
    pd_multisig_cancel_as_multi_V3_t multisig_cancel_as_multi_V3;
#endif
} pd_MethodNested_V3_t;

typedef union {
    pd_MethodBasic_V3_t basic;
    pd_MethodNested_V3_t nested;
} pd_Method_V3_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
