# Ledger Nodle App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-nodle/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-nodle/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Nodle app (https://www.nodle.com/) for Ledger Nano S and X.

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
# Nodle  5.15.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## CompanyReserve

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> |
|Tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> |
|Apply as |    | :heavy_check_mark: |   | `Call` call <br/> |

## InternationalReserve

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> |
|Tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> |
|Apply as |    | :heavy_check_mark: |   | `Call` call <br/> |

## UsaReserve

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> |
|Tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> |
|Apply as |    | :heavy_check_mark: |   | `Call` call <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   |  |
|Add vesting schedule |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`VestingScheduleOf` schedule <br/> |
|Cancel all vesting schedules |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`LookupasStaticLookupSource` funds_collector <br/> |
|Renounce |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/> |

## Mandate

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Apply |    | :heavy_check_mark: | :heavy_check_mark: | `Call` call <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    | :heavy_check_mark: |   | `Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    | :heavy_check_mark: |   | `Compactu32` threshold <br/>`Proposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## ValidatorsSet

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## Poa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation data |    |   |   | `ParachainInherentData` data <br/> |
|Sudo send upward message |    |   |   | `UpwardMessage` message <br/> |
|Authorize upgrade |    |   |   | `Hash` code_hash <br/> |
|Enact authorized upgrade |    |   |   | `Vecu8` code <br/> |

## ParachainInfo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## CumulusXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|

## DmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    | :heavy_check_mark: |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |
|Force batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Uniques

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` admin <br/> |
|Force create |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` owner <br/>`bool` free_holding <br/> |
|Try increment id |    | :heavy_check_mark: |   |  |
|Destroy |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`DestroyWitness` witness <br/> |
|Mint |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`LookupasStaticLookupSource` owner <br/> |
|Burn |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`OptionLookupasStaticLookupSource` check_owner <br/> |
|Transfer |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`LookupasStaticLookupSource` dest <br/> |
|Redeposit |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`VecItemId` items <br/> |
|Freeze |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/> |
|Thaw |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/> |
|Freeze collection |    | :heavy_check_mark: |   | `CollectionId` collection <br/> |
|Thaw collection |    | :heavy_check_mark: |   | `CollectionId` collection <br/> |
|Transfer ownership |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Approve transfer |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`LookupasStaticLookupSource` delegate <br/> |
|Cancel approval |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`OptionLookupasStaticLookupSource` maybe_check_delegate <br/> |
|Force item status |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`bool` free_holding <br/>`bool` is_frozen <br/> |
|Set attribute |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`OptionItemId` maybe_item <br/>`BoundedVecu8` key <br/>`BoundedVecu8` value <br/> |
|Clear attribute |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`OptionItemId` maybe_item <br/>`BoundedVecu8` key <br/> |
|Set metadata |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`BoundedVecu8` data <br/>`bool` is_frozen <br/> |
|Clear metadata |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/> |
|Set collection metadata |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`BoundedVecu8` data <br/>`bool` is_frozen <br/> |
|Clear collection metadata |    | :heavy_check_mark: |   | `CollectionId` collection <br/> |
|Set accept ownership |    | :heavy_check_mark: |   | `OptionCollectionId` maybe_collection <br/> |
|Set collection max supply |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`u32` max_supply <br/> |
|Set price |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`OptionItemPrice` price <br/>`OptionLookupasStaticLookupSource` whitelisted_buyer <br/> |
|Buy item |    | :heavy_check_mark: |   | `CollectionId` collection <br/>`ItemId` item <br/>`ItemPrice` bid_price <br/> |

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    | :heavy_check_mark: |   | `Vecu8` bytes <br/> |
|Unnote preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Request preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Unrequest preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |

## Allocations

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch |    | :heavy_check_mark: |   | `VecTupleAccountIdBalanceOf` batch <br/> |
|Set curve starting block |    | :heavy_check_mark: |   | `BlockNumber` curve_start <br/> |

## AllocationsOracles

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## DaoReserve

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Spend |    | :heavy_check_mark: |   | `AccountId` to <br/>`BalanceOf` amount <br/> |
|Tip |    | :heavy_check_mark: |   | `BalanceOf` amount <br/> |
|Apply as |    | :heavy_check_mark: |   | `Call` call <br/> |

