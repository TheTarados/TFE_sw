/**
  ******************************************************************************
  * @file    bat_det_net_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Dec 16 13:35:16 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
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
const ai_u64 s_bat_det_net_weights_array_u64[241] = {
  0x1f1011e01f07000bU, 0xeac6d80cd6fd07faU, 0xee25f8160421ddfaU, 0x2b1d1211f3041303U,
  0x9e2fa15fe122321U, 0xf0e6111af2dcfceeU, 0xe3ebd604d1e9f8e4U, 0x320241019ec23e9U,
  0x171ff60a181d0af6U, 0xc408f5efefeaeb2fU, 0x3103c14fcf3e308U, 0xdde7f92912f2f2fbU,
  0x309dd02f9e23622U, 0xd310c4ecedd906f3U, 0xfbcfdb051ff6e4d5U, 0x2e2503ec00f7c6d2U,
  0x292bb5d1fd33ffe6U, 0x360f021229f0f105U, 0x5cd49f023cf4f724U, 0x1ec4d5d31ed8ce16U,
  0x9cff2c01fa5c7c6U, 0x1df5eafe2cf3f8f1U, 0xbfce0da1406181aU, 0xdf280a12edf2e607U,
  0xf027f7f5dee82dfaU, 0xec18f327141f06e4U, 0x16060b12fcde0f18U, 0x111e0330122d04f7U,
  0xa3ff18ff85f51efbU, 0x18fcdcdafde334e7U, 0x4dbe2faee2af519U, 0x34320afd3424eafbU,
  0xff27df0d0225e6d4U, 0xf206f312f3f6fdf6U, 0xf4eb16d2ee26fa21U, 0xe2dc21d9c5fb05c8U,
  0x2efed522f9f614acU, 0x16ff37ec2f081115U, 0xaadde2d620fed5deU, 0x1345e207c804fd18U,
  0x81803020831cfe9U, 0x4a13fad52f0206e5U, 0xebe412f7910e11c5U, 0x1d072e190fea0de5U,
  0xcd1aef153af217e3U, 0xc1e8c009e5ee17e0U, 0x480eda2ce726ebefU, 0xdbf5a6e02718caf5U,
  0x41f2e4b70d1cd7d8U, 0x30ad40b1e17a62cU, 0x26f6e2f1e5edfce0U, 0xdfd10dd71201102fU,
  0x242621210a130de2U, 0xd61912da0cfe060eU, 0x1be10ef3f111dd01U, 0x191fed08e818ff01U,
  0x115311fef1d1727U, 0xc5f32c3efb11110bU, 0xf0e81026cfd21b10U, 0xf9f2deedcde4f60bU,
  0xf00dc2a4eff3ded0U, 0x1ecd7f5fa0304e7U, 0x2c2ce3e931012410U, 0x1ef12427e813fbe9U,
  0x7f7140f20f3fdedU, 0xd4eef30806f6de16U, 0xea1a06f0ecf925fdU, 0x1cf0001bd215131fU,
  0xd02c08071cf31808U, 0x1618ed2df2081703U, 0x31cf91ef524201bU, 0xf701e3200fe60006U,
  0x1e0bfc1514fffde6U, 0x1406ffe9f7e2f516U, 0xa0dfe1e31f0e22fU, 0x242bfa111cdeebd6U,
  0x1902e4f7332f1a23U, 0x2e81ae51111ff17U, 0x8f3f11b221ffd0eU, 0x13ee13e3ce311d06U,
  0xd017f506e0cdcf0fU, 0x16f8351a2c0b1a05U, 0xd8ea0f08f210f015U, 0xe722f0fff4f2231fU,
  0xcc0c061823e2bbU, 0xf315faf2f8bac809U, 0x202529f5371f1d14U, 0x8fdf21e10afb1de3U,
  0x1f11f1f3bac50304U, 0xb06dbdcfff90d09U, 0x3bfe25f92528f611U, 0x13fe09100c1a2d20U,
  0x9f7022012e92c0dU, 0xf30fe3aadbd5f8eeU, 0xc3f1d125fb0107bdU, 0x1e31c1a92c051fe1U,
  0x15ed1f09ef13e8e4U, 0x2eb1cf513ceedd9U, 0xfefe0f0a22162504U, 0xc6cbfad1e7f3101bU,
  0xf52c0111e411b9b8U, 0x1ee333f4f218221cU, 0x8e7ff22dd1a13f1U, 0x23040a11e906dcf4U,
  0xf7d4f40c29ff08e6U, 0xf8080801051f1920U, 0xee1f23fcf922fae6U, 0x12f7031b032209e6U,
  0xed091717d2ea1903U, 0xec0709260afde919U, 0xdf00ce1f5dbfb11U, 0xfa1313f41b14f6edU,
  0xe1be9cef209f5e1U, 0xb3e9e1f508fd1aceU, 0xc0f4e10fabead0fcU, 0xb804f8fee207f7f0U,
  0xe4fe1909cffc0f13U, 0xe3180ef8cd0be0fdU, 0x113b0bba201c16e7U, 0x13272cbbeb10c8d3U,
  0x1333e5e4db110bd1U, 0xfecf2017e51fd709U, 0xe0e5e2fcd6d9e247U, 0x1c020f0323e10d17U,
  0x15f7fc1ecb05fef5U, 0xe7dd04ebb9f23deeU, 0x14edeae8050aec23U, 0xc1e61bf818fa071bU,
  0x190f0826bcf9eae0U, 0x2408050b242f2b38U, 0xfbf2170892e2fc0fU, 0x280e2512cc0a231cU,
  0xbf0d0817d3171f11U, 0xd5e6f41b0cff07d5U, 0xbf2c0cff21ebead4U, 0xf0fccd281600fae2U,
  0x918e4d9c5ee12fcU, 0xa003beca2efd151eU, 0x2d202a1c0620f706U, 0xd525000222e9f6f1U,
  0x4090c13f4fcf2f0U, 0x8d13bafef10bf5faU, 0xc11da8e0a4fba9c3U, 0xb710bb01b909d6eeU,
  0x225f416e402d405U, 0x225c0fe34f404f8U, 0x36f5ecb43426ede0U, 0x2ded02cae0081802U,
  0xeb1ee80b051c0427U, 0x2a1916f5eb172b10U, 0x2beb0f234502b5f8U, 0x141cf3daf9eff117U,
  0xdfc05f8f11b0a0dU, 0xe2df20ec1700eeecU, 0xef0c040811150a15U, 0xe0daf1fefd0be4ecU,
  0x2b2201daf41e0dd1U, 0xe21414f7021d1613U, 0x1713e5210ee9ddf8U, 0x7f316e9f405ee1aU,
  0x212304031a250118U, 0xebfb0a0bfa15140dU, 0xebe5082cc3080a2dU, 0xd7d6fdf5d30eef03U,
  0xeaf10a0fde16150eU, 0xf4f812ffece046f3U, 0xde0712ceff13fedeU, 0xe7120dfdeae7e3e7U,
  0xdef0f2bd9eafb11U, 0x81e3c2f6d3d41fedU, 0x4d17210ba8dad70fU, 0xe824dbfaf6103423U,
  0xe3eb051d232a0dfcU, 0x1d1e0adbf3f0ebcdU, 0xf1e42e15ebfe15fbU, 0x1a06e7da091cf1fbU,
  0xf3e4d61de209f515U, 0x3211ce1decdc6f8U, 0xfd35f3ee0ed6030cU, 0xbd11fd1b32f60805U,
  0xa0bf50ceeea1be0U, 0xc610f315dde41df8U, 0x301cef06dd06f7e0U, 0x37fe22171c060bf0U,
  0x1df20305f8f60d14U, 0xeb19be2cd9d5dde3U, 0x1f12438361f1117U, 0xcb10dfdf00ef02f0U,
  0xd8fdccd3feefbdddU, 0xbe090fc302c3d7d0U, 0x10200408f2f1fd05U, 0xa9cebe043d081e2aU,
  0xfffb0fe10ddac6ffU, 0x22eff3fe281822cfU, 0x1fcdd5d704fbeae2U, 0xe2e0100013d107e3U,
  0xffffffe8ffffffcdU, 0x3300000003U, 0x24fffffff2U, 0xffffffdf0000003aU,
  0x3200000030U, 0xffffffd30000003cU, 0x2900000022U, 0xffffffd0ffffffd3U,
  0x130000003dU, 0xfffffff5ffffffaeU, 0xffffffde00000068U, 0x520000002eU,
  0xffffffcdffffffdeU, 0xffffffee00000014U, 0x1d5f5222d3b93132U, 0x1d20c33e14f8f5d5U,
  0xb9e00881212ee599U, 0xffffffd9ae3d2d36U, 0x651551ea503588faU, 0xe581173d032b2a7fU,
  0xb7f17e4c157adb8U, 0xe8d2e817e35ae5b8U, 0xffffffcf08b3c87fU, 0x1ffffffffU,
  0x14e716b00000002eU, 0x5e3efd2524fbff0bU, 0x2c0c2f05b80534f1U, 0x1200fd40ddcb0381U,
  0x129af4e61ad538fcU, 0xb925ca077f2ab3d6U, 0x52bdf1049db42697U, 0xd2d4d9ec037a063bU,
  0x2ea0138cca0e2f0U, 0xf6b681f3f4ec6af7U, 0xea0f2bd8f30ac9feU, 0x3df8f8e44815410bU,
  0x5a17b9b65bafbdc6U, 0x137df748207117afU, 0x1525f4d51effba1cU, 0xfabe8a070dd9ebeaU,
  0x686ac80c2a07bbfbU, 0xbad7d5f5c1ac81e9U, 0xffffffe31e1b1be5U, 0x6fffffffc5U,
  0x11U,
};


ai_handle g_bat_det_net_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_bat_det_net_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

