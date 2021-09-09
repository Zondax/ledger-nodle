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
  '0200006be843a6cc46e14661e612b9520f2b5c11020c5c994a9bb9bcca4a93579cb05400d50304003500000003000000a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23'

export const txOther =
  '0f03a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23ce83070000d50304003500000003000000a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23a3d114c2b8d0627c1aa9b134eafcf7d05ca561fdc19fb388bb9457f81809fb23'
