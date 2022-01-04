import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
]

export const txBasic =
  '020000616a09c926c427dbead087edcdccc56ae2c297bcf9c1d9d68c87be7d53ee628800d5039101003700000003000000a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23'

export const txOther =
  '0f03a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb2325c100d5038d248ed73e0d3700000003000000a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23'
