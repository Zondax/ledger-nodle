# Ledger Nodle App
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![CircleCI](https://circleci.com/gh/Zondax/ledger-nodle.svg?style=shield)](https://circleci.com/gh/Zondax/ledger-nodle)

-------------------

![zondax](docs/zondax.jpg)

_Please visit our website at [zondax.ch](zondax.ch)_

------------------
This project contains the Nodle app (https://nodle.network/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# Nodle  3.52.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :white_check_mark: | :white_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :white_check_mark: | :white_check_mark: | `Bytes` _remark <br/> | 
|set_heap_pages |    | :white_check_mark: | :white_check_mark: | `u64` pages <br/> | 
|set_code |    | :white_check_mark: | :white_check_mark: | `Bytes` code <br/> | 
|set_code_without_checks |    | :white_check_mark: | :white_check_mark: | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :white_check_mark: |   | `Compact<Moment>` now <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :white_check_mark: |   | `AccountIndex` index <br/> | 
|transfer |    | :white_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/> | 
|free |    | :white_check_mark: |   | `AccountIndex` index <br/> | 
|force_transfer |    | :white_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|freeze |    | :white_check_mark: |   | `AccountIndex` index <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|set_balance |    | :white_check_mark: | :white_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer |    | :white_check_mark: | :white_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_keep_alive | :white_check_mark:  | :white_check_mark: | :white_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 

## TransactionPayment

Empty

## RandomnessCollectiveFlip

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Babe

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 

## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|note_stalled |    | :white_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> | 

## ImOnline

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> | 

## Offences

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## ValidatorsSet

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :white_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :white_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :white_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :white_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :white_check_mark: |   |  | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :white_check_mark:  |   |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys | :white_check_mark:  | :white_check_mark: |   |  | 

## Historical

Empty

## AuthorityDiscovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :white_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :white_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/> | 

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :white_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :white_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :white_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :white_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :white_check_mark: |   |  | 

## FinancialCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :white_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    | :white_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    | :white_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :white_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/> | 

## FinancialMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :white_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :white_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :white_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :white_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :white_check_mark: |   |  | 

## RootCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :white_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    | :white_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    | :white_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :white_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :white_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :white_check_mark: |   | `Hash` proposal_hash <br/> | 

## RootMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :white_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :white_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :white_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :white_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :white_check_mark: |   |  | 

## Scheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|schedule |    |   |   | `BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> | 
|schedule_named |    |   |   | `Bytes` id <br/>`BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel_named |    |   |   | `Bytes` id <br/> | 
|schedule_after |    |   |   | `BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|schedule_named_after |    |   |   | `Bytes` id <br/>`BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 

## Amendments

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|propose |    |   |   | `Amendment` amendment <br/> | 
|veto |    | :white_check_mark: |   | `u64` amendment_id <br/> | 

## Mandate

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|apply |    | :white_check_mark: |   | `Call` call <br/> | 

## CompanyReserve

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|spend |    | :white_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> | 
|tip |    | :white_check_mark: |   | `BalanceOf` amount <br/> | 
|apply_as |    | :white_check_mark: |   | `Call` call <br/> | 

## InternationalReserve

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|spend |    | :white_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> | 
|tip |    | :white_check_mark: |   | `BalanceOf` amount <br/> | 
|apply_as |    | :white_check_mark: |   | `Call` call <br/> | 

## UsaReserve

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|spend |    | :white_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> | 
|tip |    | :white_check_mark: |   | `BalanceOf` amount <br/> | 
|apply_as |    | :white_check_mark: |   | `Call` call <br/> | 

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :white_check_mark: |   |  | 
|add_vesting_schedule |    |   |   | `LookupSource` dest <br/>`VestingScheduleOf` schedule <br/> | 
|cancel_all_vesting_schedules |    | :white_check_mark: |   | `LookupSource` who <br/>`LookupSource` funds_collector <br/>`bool` limit_to_free_balance <br/> | 

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    | :white_check_mark: |   | `AccountId` account <br/> | 
|set_identity |    |   |   | `IdentityInfo` info <br/> | 
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> | 
|clear_identity |    | :white_check_mark: |   |  | 
|request_judgement |    | :white_check_mark: |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> | 
|cancel_request |    | :white_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|set_fee |    | :white_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> | 
|set_account_id |    | :white_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> | 
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> | 
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> | 
|kill_identity |    | :white_check_mark: |   | `LookupSource` target <br/> | 
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|remove_sub |    | :white_check_mark: |   | `LookupSource` sub <br/> | 
|quit_sub |    | :white_check_mark: |   |  | 

## Recovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> | 
|set_recovered |    | :white_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|create_recovery |    |   |   | `Vec<AccountId>` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> | 
|initiate_recovery |    | :white_check_mark: |   | `AccountId` account <br/> | 
|vouch_recovery |    | :white_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|claim_recovery |    | :white_check_mark: |   | `AccountId` account <br/> | 
|close_recovery |    | :white_check_mark: |   | `AccountId` rescuer <br/> | 
|remove_recovery |    | :white_check_mark: |   |  | 
|cancel_recovered |    | :white_check_mark: |   | `AccountId` account <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :white_check_mark:  | :white_check_mark: |   | `Vec<Call>` calls <br/> | 
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|batch_all | :white_check_mark:  | :white_check_mark: |   | `Vec<Call>` calls <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|proxy |    | :white_check_mark: | :white_check_mark: | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 
|add_proxy |    | :white_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxy |    | :white_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxies |    | :white_check_mark: |   |  | 
|anonymous |    | :white_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|kill_anonymous |    | :white_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> | 
|announce |    | :white_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|remove_announcement |    | :white_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|reject_announcement |    | :white_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> | 
|proxy_announced |    | :white_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    | :white_check_mark: | :white_check_mark: | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> | 
|as_multi |    | :white_check_mark: | :white_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|approve_as_multi |    | :white_check_mark: | :white_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> | 
|cancel_as_multi |    | :white_check_mark: | :white_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## Contracts

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|update_schedule |    |   |   | `Schedule` schedule <br/> | 
|call |    | :white_check_mark: |   | `LookupSource` dest <br/>`Compact<BalanceOf>` value <br/>`Compact<Weight>` gas_limit <br/>`Bytes` data <br/> | 
|instantiate_with_code |    | :white_check_mark: |   | `Compact<BalanceOf>` endowment <br/>`Compact<Weight>` gas_limit <br/>`Bytes` code <br/>`Bytes` data <br/>`Bytes` salt <br/> | 
|instantiate |    |   |   | `Compact<BalanceOf>` endowment <br/>`Compact<Weight>` gas_limit <br/>`CodeHash` code_hash <br/>`Bytes` data <br/>`Bytes` salt <br/> | 
|claim_surcharge |    | :white_check_mark: |   | `AccountId` dest <br/>`Option<AccountId>` aux_sender <br/> | 

## PkiTcr

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|apply |    | :white_check_mark: |   | `Bytes` metadata <br/>`BalanceOf` deposit <br/> | 
|counter |    | :white_check_mark: |   | `AccountId` member <br/>`BalanceOf` deposit <br/> | 
|vote |    | :white_check_mark: |   | `AccountId` member <br/>`bool` supporting <br/>`BalanceOf` deposit <br/> | 
|challenge |    | :white_check_mark: |   | `AccountId` member <br/>`BalanceOf` deposit <br/> | 

## PkiRootOfTrust

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|book_slot |    |   |   | `CertificateId` certificate_id <br/> | 
|renew_slot |    |   |   | `CertificateId` certificate_id <br/> | 
|revoke_slot |    |   |   | `CertificateId` certificate_id <br/> | 
|revoke_child |    |   |   | `CertificateId` root <br/>`CertificateId` child <br/> | 

## EmergencyShutdown

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|toggle |    | :white_check_mark: |   |  | 

## Allocations

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|allocate |    | :white_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/>`Bytes` proof <br/> | 

## AllocationsOracles

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|remove_member |    | :white_check_mark: |   | `AccountId` who <br/> | 
|swap_member |    | :white_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :white_check_mark: |   | `Vec<AccountId>` members <br/> | 
|change_key |    | :white_check_mark: |   | `AccountId` new <br/> | 
|set_prime |    | :white_check_mark: |   | `AccountId` who <br/> | 
|clear_prime |    | :white_check_mark: |   |  | 

## Poa

Empty

