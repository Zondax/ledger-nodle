# Nodle  3.52.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` _remark <br/> | 
|set_heap_pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|set_code |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_code_without_checks |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :heavy_check_mark: |   | `Compact<Moment>` now <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    |   |   | `AccountIndex` index <br/> | 
|transfer |    |   |   | `AccountId` new <br/>`AccountIndex` index <br/> | 
|free |    |   |   | `AccountIndex` index <br/> | 
|force_transfer |    |   |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|freeze |    |   |   | `AccountIndex` index <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|set_balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_keep_alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 

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
|note_stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

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
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :heavy_check_mark:  |   |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys | :heavy_check_mark:  | :heavy_check_mark: |   |  | 

## Historical

Empty

## AuthorityDiscovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal_hash <br/> | 

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## FinancialCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    | :heavy_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## FinancialMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## RootCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> | 
|execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|propose |    | :heavy_check_mark: |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> | 
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> | 
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> | 
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 

## RootMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: | :heavy_check_mark: |  | 

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
|veto |    | :heavy_check_mark: |   | `u64` amendment_id <br/> | 

## Mandate

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|apply |    | :heavy_check_mark: |   | `Call` call <br/> | 

## CompanyReserve

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> | 
|tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> | 
|apply_as |    | :heavy_check_mark: |   | `Call` call <br/> | 

## InternationalReserve

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> | 
|tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> | 
|apply_as |    | :heavy_check_mark: |   | `Call` call <br/> | 

## UsaReserve

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> | 
|tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> | 
|apply_as |    | :heavy_check_mark: |   | `Call` call <br/> | 

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: |   |  | 
|add_vesting_schedule |    |   |   | `LookupSource` dest <br/>`VestingScheduleOf` schedule <br/> | 
|cancel_all_vesting_schedules |    | :heavy_check_mark: |   | `LookupSource` who <br/>`LookupSource` funds_collector <br/>`bool` limit_to_free_balance <br/> | 

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    |   |   | `AccountId` account <br/> | 
|set_identity |    |   |   | `IdentityInfo` info <br/> | 
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> | 
|clear_identity |    |   |   |  | 
|request_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> | 
|cancel_request |    |   |   | `RegistrarIndex` reg_index <br/> | 
|set_fee |    |   |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> | 
|set_account_id |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> | 
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> | 
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> | 
|kill_identity |    |   |   | `LookupSource` target <br/> | 
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> | 
|remove_sub |    |   |   | `LookupSource` sub <br/> | 
|quit_sub |    |   |   |  | 

## Recovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> | 
|set_recovered |    |   |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|create_recovery |    |   |   | `Vec<AccountId>` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> | 
|initiate_recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|vouch_recovery |    |   |   | `AccountId` lost <br/>`AccountId` rescuer <br/> | 
|claim_recovery |    |   |   | `AccountId` account <br/> | 
|close_recovery |    |   |   | `AccountId` rescuer <br/> | 
|remove_recovery |    |   |   |  | 
|cancel_recovered |    |   |   | `AccountId` account <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|batch_all | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|proxy |    |   |   | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 
|add_proxy |    |   |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxy |    |   |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxies |    |   |   |  | 
|anonymous |    |   |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|kill_anonymous |    |   |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> | 
|announce |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|remove_announcement |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|reject_announcement |    |   |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> | 
|proxy_announced |    |   |   | `AccountId` delegate <br/>`AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> | 
|as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|approve_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> | 
|cancel_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## Contracts

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|update_schedule |    |   |   | `Schedule` schedule <br/> | 
|call |    | :heavy_check_mark: |   | `LookupSource` dest <br/>`Compact<BalanceOf>` value <br/>`Compact<Weight>` gas_limit <br/>`Bytes` data <br/> | 
|instantiate_with_code |    | :heavy_check_mark: |   | `Compact<BalanceOf>` endowment <br/>`Compact<Weight>` gas_limit <br/>`Bytes` code <br/>`Bytes` data <br/>`Bytes` salt <br/> | 
|instantiate |    |   |   | `Compact<BalanceOf>` endowment <br/>`Compact<Weight>` gas_limit <br/>`CodeHash` code_hash <br/>`Bytes` data <br/>`Bytes` salt <br/> | 
|claim_surcharge |    | :heavy_check_mark: |   | `AccountId` dest <br/>`Option<AccountId>` aux_sender <br/> | 

## PkiTcr

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|apply |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` metadata <br/>`BalanceOf` deposit <br/> | 
|counter |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` member <br/>`BalanceOf` deposit <br/> | 
|vote |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` member <br/>`bool` supporting <br/>`BalanceOf` deposit <br/> | 
|challenge |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` member <br/>`BalanceOf` deposit <br/> | 

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
|toggle |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## Allocations

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|allocate |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/>`Bytes` proof <br/> | 

## AllocationsOracles

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` remove <br/>`AccountId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` members <br/> | 
|change_key |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/> | 
|set_prime |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` who <br/> | 
|clear_prime |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## Poa

Empty

