/**
  ******************************************************************************
  * @file    bat_det_net_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Apr 30 10:47:56 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "bat_det_net_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_bat_det_net_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_bat_det_net_weights_array_u64[191] = {
  0x2d00000027U, 0x1c00000004U, 0x18ffffffe9U, 0x500000004U,
  0xbce91b06191643faU, 0x17d60c55b1e02b17U, 0x150823de2d02f8daU, 0x35e2299b1347d4e1U,
  0x7f3a374d17f42644U, 0x54245829e70c530dU, 0xd00258e9bc3c4828U, 0x53dcfed66b08c7e1U,
  0x11ec73e3403bd7dbU, 0xc949146368280e1dU, 0x174e78de06797f46U, 0x29ff49322a325f3bU,
  0xfdc659fedad25731U, 0x250d17f7af4b196aU, 0xc40851af3dc9201eU, 0xbb12e322a1dcfbacU,
  0x52c4b1b059d6b551U, 0x9d11be0c9f12955U, 0xd9c00bc1f6a28fa6U, 0x5f8d330d2cd1a1fbU,
  0xa819c9c63240e109U, 0x44a4eb9431027221U, 0xe496eed19e4c3305U, 0x444215aabeee80dU,
  0x924023564cc44523U, 0x422cf9b6be4452c5U, 0x8216135aae81a918U, 0xaff9e2e2bdd8b13fU,
  0x58be2c29e212cf56U, 0x37bfbf8881fbc715U, 0x4c57b47b18aefe10U, 0xbae8233d062ae66bU,
  0x341ef4fe2e373d47U, 0x1e7751124f1cb51aU, 0xa6c578f3f048c55eU, 0xf773c65da8b81fafU,
  0xd6761dc61bb702e3U, 0x169f0f3d100b26bbU, 0xe40a125ece07e5cdU, 0x1cac1ad6ef90e523U,
  0x362c67aa6bbe230aU, 0x79494b603d392ab4U, 0x519ca4260aff2e81U, 0xf83f63fe26ee0194U,
  0x5a6eef067bdcd333U, 0xf4d1d2aea3170eaaU, 0x1603392f39fc9be4U, 0x69c9e1525b4b532U,
  0x34bbffabec1ae4c2U, 0xd838982e03e94a02U, 0xbda737adb5e80b59U, 0x55b2c1e8d51f01b9U,
  0xe3dc01dedc365c18U, 0x483e60dbd97f537cU, 0xcb1be3d5012abeb3U, 0xdf0bfd4db505b042U,
  0xd5ce1acae81d07adU, 0xf67a57ff383b0ebcU, 0xcdf50d1ea6f13cc1U, 0xe60810d94e19d8deU,
  0x12410d7fd92f3cfdU, 0xf0b15a66f7a30b1aU, 0x26b74acfde3705b9U, 0x52daefd9e6fd030cU,
  0x7f2c512510122501U, 0x10a5d1cb40e5f059U, 0xeef74138e6163ee3U, 0x4c11089e41b6ec12U,
  0xbcc4b6a4391cf5c4U, 0x1b912a412f0690afU, 0x8d024817ea233bc9U, 0xc3dffc28bc1f49aeU,
  0x3cffffffc8U, 0xffffffe8fffffff2U, 0x9fffffffcU, 0x5bfffffffbU,
  0xf81bf4fad71b6343U, 0xff4cdcd900e522f8U, 0xb7e7d5a1a9b7078cU, 0xbbb6143cd30e1da7U,
  0x17b5ebb32218f9fcU, 0xaa3d22bbb6ddf2a2U, 0xc0cdb706284d4032U, 0xd213183aceeb261eU,
  0xb02ad2f53dbc1af6U, 0x618b6d4c62b13d9U, 0xb0dfb7d200e7aae3U, 0x1210c400e92ec8cbU,
  0xfa4a26e2e2be1cebU, 0x210c121cc131fcc7U, 0x2fdeea3535b7f1feU, 0x3f2db0df052909e1U,
  0xbca208cd1dbb31eaU, 0x50a6fe4c36091813U, 0x1f2d4208200bb73fU, 0xbcef414af6f9b2d8U,
  0xf81dfebe0cc5eac3U, 0xad54523ea0d2ef9U, 0xb5c3cc07d714c947U, 0x4ee41b39ef0be7e3U,
  0xaadc07ea2444d0e2U, 0x37e6d3daf644b632U, 0xee2bdf513be0e73eU, 0xdcb20ea26f94a27U,
  0x4dfeb509363ec912U, 0x254cbf88ef3fcafbU, 0xe9cff71125b7621cU, 0x6768a5efda4e3a16U,
  0xa146c0a1b3cf20e9U, 0xf14952463aff4becU, 0x3cfecacf1a2ef2e4U, 0xc6e4c6a73f28af2dU,
  0x8e8ee34ee17c81aU, 0x7e1024bcb29f824U, 0x4800e1b7314421f2U, 0x256cb3b2c2dba09U,
  0x1c0131bb2e3de1e5U, 0xc85210214df1f43eU, 0x90cfab3160c4914U, 0x4136e61cc224beeaU,
  0xcf07a332b0dda98cU, 0xaddec93f1bf5baaeU, 0xc1434a33014de0d7U, 0x233eb4e135b84c32U,
  0x19db46d1b4d20809U, 0xb5fd1f4839b429c3U, 0x1c223ff302efec29U, 0xa0ae94d50cbeb01U,
  0x351de74ba6ece21eU, 0xf43ed547b5f04f34U, 0xdc0352426c90fd1U, 0xedd92e44b4f22f46U,
  0xf3a7143fcbeb4906U, 0x3426ff3cb1be612aU, 0xfb4d811ff24ee618U, 0x193df6b3f9e2d38eU,
  0x24200b094e441926U, 0xd21f4c2d0b19b41fU, 0xf634c031d71cd714U, 0x371b3fc7de0dd135U,
  0xe5471b311abf263fU, 0xdcc4362feb30e127U, 0xb2c72e33d8d20607U, 0x9173e0fbb3fef3aU,
  0xdb2d06c2c7fbd60eU, 0x83d3515b7f9b21aU, 0xbef7d5f40a19ddbeU, 0xebbb0836150ab2b5U,
  0x14b4082034e83dddU, 0x344daf05e240170aU, 0xf35014b0c348e5cfU, 0x18f3b82ad4e2c2bdU,
  0xd129f4f6c8b5ffdcU, 0xc6cc1dded43d32ffU, 0xf40d3ff72ef025d8U, 0xf5fedc0fcf29db2cU,
  0xf252080ce50f3c0aU, 0xbc360eb8210bd0f5U, 0x29d1d3e53d35ffb8U, 0x40d337b1d402fb3aU,
  0xfffffff600000013U, 0xfffffff80000000bU, 0xfffffff800000000U, 0xfffffff7fffffffeU,
  0x14fffffff6U, 0x1900000018U, 0xfffffff800000000U, 0xfffffff500000015U,
  0xcfffffffdU, 0x10fffffff9U, 0xfffffff3fffffff8U, 0xfffffffdfffffff6U,
  0xfffffffd00000012U, 0xfffffffefffffffeU, 0xe23510f10f520c0U, 0xc9dda7b6e5e1d3d7U,
  0xe44efd2881591159U, 0xfffffff53efc2e93U, 0xf9563b9b42891922U, 0x50be4cc739f6817fU,
  0x507fb0d63d073327U, 0x47197f5d51569d56U, 0x35c710abec49c95aU, 0x7f832c12e9498197U,
  0x4668d3d73da37e93U, 0x6d65c42f3811d77U, 0x649c2b7f6ea0b8efU,
};


ai_handle g_bat_det_net_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_bat_det_net_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

