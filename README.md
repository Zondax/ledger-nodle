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
# Nodle 5.16.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Fill block              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Perbill`ratio<br/>               |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`remark<br/>                |

## Timestamp

| Name | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments            |
| ---- | ------ | ------------------ | ------------------ | ------- | -------------------- |
| Set  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu64`now<br/> |

## Balances

| Name                | Nano S             | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                  |
| ------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/> |
| Force transfer      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                                                                           |
| -------------------- | ------ | --------- | --------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| Schedule             |        |           |           |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`BoxCallOrHashOfT`call<br/>                |
| Cancel               |        |           |           |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                               |
| Schedule named       |        |           |           |         | `Vecu8`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`BoxCallOrHashOfT`call<br/>  |
| Cancel named         |        |           |           |         | `Vecu8`id<br/>                                                                                                                                      |
| Schedule after       |        |           |           |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`BoxCallOrHashOfT`call<br/>               |
| Schedule named after |        |           |           |         | `Vecu8`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`BoxCallOrHashOfT`call<br/> |

## CompanyReserve

| Name     | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                |
| -------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------- |
| Spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`to<br/>`BalanceOf`amount<br/> |
| Tip      |        | :heavy_check_mark: | :heavy_check_mark: |         | `BalanceOf`amount<br/>                   |
| Apply as |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>                          |

## InternationalReserve

| Name     | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                |
| -------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------- |
| Spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`to<br/>`BalanceOf`amount<br/> |
| Tip      |        | :heavy_check_mark: | :heavy_check_mark: |         | `BalanceOf`amount<br/>                   |
| Apply as |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>                          |

## UsaReserve

| Name     | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                |
| -------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------- |
| Spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`to<br/>`BalanceOf`amount<br/> |
| Tip      |        | :heavy_check_mark: | :heavy_check_mark: |         | `BalanceOf`amount<br/>                   |
| Apply as |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>                          |

## Vesting

| Name                         | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                            |
| ---------------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------ |
| Claim                        |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                      |
| Add vesting schedule         |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`dest<br/>`VestingScheduleOf`schedule<br/>                |
| Cancel all vesting schedules |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`who<br/>`LookupasStaticLookupSource`funds_collector<br/> |
| Renounce                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `LookupasStaticLookupSource`who<br/>                                                 |

## Mandate

| Name  | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments       |
| ----- | ------ | ------------------ | ------------------ | ------------------ | --------------- |
| Apply |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Call`call<br/> |

## TechnicalCommittee

| Name                | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close               |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>                                                                                          |

## TechnicalMembership

| Name          | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                   |
| ------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------- |
| Add member    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Remove member |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Swap member   |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`remove<br/>`AccountIdLookupOfT`add<br/> |
| Reset members |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`members<br/>                                  |
| Change key    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>                              |
| Set prime     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Clear prime   |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                             |

## CollatorSelection

| Name                   | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                |
| ---------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------ |
| Set invulnerables      |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new\_<br/> |
| Set desired candidates |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`max<br/>            |
| Set candidacy bond     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`bond<br/>       |
| Register as candidate  |        | :heavy_check_mark: | :heavy_check_mark: |         |                          |
| Leave intent           |        | :heavy_check_mark: | :heavy_check_mark: |         |                          |

## Authorship

| Name       | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                  |
| ---------- | ------ | --------- | --------- | ------- | -------------------------- |
| Set uncles |        |           |           |         | `VecHeader`new_uncles<br/> |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X          | Nesting | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------- | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                  |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                        |
| ------------------------ | ------ | --------- | --------- | ------- | -------------------------------- |
| Set validation data      |        |           |           |         | `ParachainInherentData`data<br/> |
| Sudo send upward message |        |           |           |         | `UpwardMessage`message<br/>      |
| Authorize upgrade        |        |           |           |         | `Hash`code_hash<br/>             |
| Enact authorized upgrade |        |           |           |         | `Vecu8`code<br/>                 |

## ParachainInfo

| Name | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments |
| ---- | ------ | --------- | --------- | ------- | --------- |

## CumulusXcm

| Name | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments |
| ---- | ------ | --------- | --------- | ------- | --------- |

## DmpQueue

| Name               | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                            |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------- |
| Service overweight |        | :heavy_check_mark: | :heavy_check_mark: |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |                    | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |                    | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `VecCall`calls<br/>                             |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                                                                                     |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                                           |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`OpaqueCall`call<br/>`bool`store_call<br/>`Weight`max_weight<br/> |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/>                       |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                                          |

## Uniques

| Name                      | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                                                                                                           |
| ------------------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`admin<br/>                                                                                                                                         |
| Force create              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>`bool`free_holding<br/>                                                                                                                  |
| Destroy                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`DestroyWitness`witness<br/>                                                                                                                                           |
| Mint                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                        |
| Burn                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionAccountIdLookupOfT`check_owner<br/>                                                                                                            |
| Transfer                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`dest<br/>                                                                                                                         |
| Redeposit                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`VecItemId`items<br/>                                                                                                                                                  |
| Freeze                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                      |
| Thaw                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                      |
| Freeze collection         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                       |
| Thaw collection           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                       |
| Transfer ownership        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                         |
| Set team                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                          |
| Approve transfer          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                     |
| Cancel approval           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionAccountIdLookupOfT`maybe_check_delegate<br/>                                                                                                   |
| Force item status         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`bool`free_holding<br/>`bool`is_frozen<br/> |
| Set attribute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionItemId`maybe_item<br/>`BoundedVecu8`key<br/>`BoundedVecu8`value<br/>                                                                                            |
| Clear attribute           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionItemId`maybe_item<br/>`BoundedVecu8`key<br/>                                                                                                                    |
| Set metadata              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`BoundedVecu8`data<br/>`bool`is_frozen<br/>                                                                                                           |
| Clear metadata            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                      |
| Set collection metadata   |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`BoundedVecu8`data<br/>`bool`is_frozen<br/>                                                                                                                            |
| Clear collection metadata |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                       |
| Set accept ownership      |        | :heavy_check_mark: | :heavy_check_mark: |         | `OptionCollectionId`maybe_collection<br/>                                                                                                                                                           |
| Set collection max supply |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`u32`max_supply<br/>                                                                                                                                                   |
| Set price                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionItemPrice`price<br/>`OptionAccountIdLookupOfT`whitelisted_buyer<br/>                                                                           |
| Buy item                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`ItemPrice`bid_price<br/>                                                                                                                             |

## Preimage

| Name               | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments         |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ----------------- |
| Note preimage      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`bytes<br/> |
| Unnote preimage    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Request preimage   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Unrequest preimage |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |

## Allocations

| Name                     | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                              |
| ------------------------ | ------ | ------------------ | ------------------ | ------- | -------------------------------------- |
| Batch                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecTupleAccountIdBalanceOf`batch<br/> |
| Set curve starting block |        | :heavy_check_mark: | :heavy_check_mark: |         | `BlockNumber`curve_start<br/>          |

## AllocationsOracles

| Name          | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                   |
| ------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------- |
| Add member    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Remove member |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Swap member   |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`remove<br/>`AccountIdLookupOfT`add<br/> |
| Reset members |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`members<br/>                                  |
| Change key    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>                              |
| Set prime     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Clear prime   |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                             |

## DaoReserve

| Name     | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                |
| -------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------- |
| Spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`to<br/>`BalanceOf`amount<br/> |
| Tip      |        | :heavy_check_mark: | :heavy_check_mark: |         | `BalanceOf`amount<br/>                   |
| Apply as |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>                          |

## Contracts

| Name                  | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                                                                       |
| --------------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Call                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>            |
| Instantiate with code |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>         |
| Instantiate           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/> |
| Upload code           |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`code<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>                                                                                              |
| Remove code           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CodeHash`code_hash<br/>                                                                                                                                        |
| Set code              |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CodeHash`code_hash<br/>                                                                                                           |
