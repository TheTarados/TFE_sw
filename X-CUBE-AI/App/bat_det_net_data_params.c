/**
  ******************************************************************************
  * @file    bat_det_net_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Mar  2 16:23:20 2024
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
const ai_u64 s_bat_det_net_weights_array_u64[241] = {
  0xffffffef00000005U, 0xfffffffc00000006U, 0x733783a4ba8df6e2U, 0xa401fc1d2d21f7dU,
  0xfcfe66eb9e819245U, 0x39e157978c17aea4U, 0x30b42a008b37f701U, 0x2ce666d45dac4392U,
  0x24d64bc458797024U, 0x87a6f1e9a61cbdf0U, 0x81e07011cbd316f4U, 0x45cdd4207fb9105cU,
  0x35ee01e7ae7664fdU, 0xe0955f00bd45a219U, 0x1a17d085c2c9d7bcU, 0x74ab2e4cd3a613f7U,
  0x93f2247a790213daU, 0x34799c4a863f8b61U, 0x3293488c68e81cf1U, 0xa7b52b2581b838a6U,
  0xfffffff8ffffffffU, 0x2ffffffedU, 0x5dc31849e9bdd41cU, 0x7742a8485ac8fe2eU,
  0xb1bf56a2673d25abU, 0x899b491802f727U, 0x3aa9f5180dedf60aU, 0x5bc29af1f5f5bbe9U,
  0x964bca343ec3daeaU, 0x5c4bba4f25185c12U, 0x12a8e2afb7fdbcc8U, 0xc731f41a296adeefU,
  0xf7389ffcd0c800a2U, 0x9b0040cee7cd27caU, 0x3e54fdcc39c7c11fU, 0x33c68ca3270a28bcU,
  0xdcf5633faef54827U, 0x9fea6ca5285a231dU, 0xb82a9048e168a325U, 0xe09de1efabc2c49dU,
  0xfd1f158fa1bf2acfU, 0x3cefaaa7fc411cd9U, 0x6f2f52969075ec5U, 0x4cb0ce40b809f859U,
  0xc5b54b66ca3be055U, 0xf8376fa5ebf92f1fU, 0xfbaeecd8e2209903U, 0x273315042c23f4c2U,
  0x4d2f314b3816583fU, 0x656e36e8a5329861U, 0x63edb02a3214135aU, 0xe5683b9ba25aeae5U,
  0x48ca4c2448e90cf1U, 0x17ab6217c6193a4bU, 0x23d5372c540a4f40U, 0x4d26bd5b5bcaa8c3U,
  0xd419bc0159e712c5U, 0xb1000d10ef0cb362U, 0x3ad8b562561e5fb6U, 0x23e04ca0deb41c1bU,
  0xefcffdf4d0b1be1bU, 0xf115c3de42ad5421U, 0x2d8af1e90d169dcdU, 0xfed3a4f02bac44dU,
  0xf90d9bda9fc099b9U, 0x3d14b138c944a39eU, 0xbb02fc840d31c5dU, 0xd8eba657a94cce23U,
  0x64434907b13c4cf5U, 0x1e1f0f0d2702a5c1U, 0x36a447fc5ffeaeeaU, 0xda47d7293c4bf813U,
  0xc96ef72ff129cfefU, 0x6504e4d93825aabbU, 0xc709233ffa5e62f1U, 0x4b4d42f9f30fa8b2U,
  0x9a50161bfe9913fbU, 0xce626a040d1e5ae7U, 0x573b1b44fbb03eb8U, 0x3f4e8fa52f2f0802U,
  0xb450a4bdbdc6a94cU, 0xe6c32e1b5a2bee04U, 0x55594eb8e1edf22fU, 0xd5b701585fcae849U,
  0x58fd031a192eb2d9U, 0xaaf52ca3e19cefaU, 0x3ba7cfdba50adaeeU, 0xc3d534a4fad6ccd8U,
  0x1d323004bd09cc25U, 0x49e36544e740e022U, 0xd9b4092c3f2b9e37U, 0x2f35c261c6eccf01U,
  0x5100deb950a9a6c7U, 0xc1c637642151f8fcU, 0x13bb1cc2369ceaceU, 0x3243af2ad1f34e60U,
  0x39ea40e7b2c10de4U, 0x97d5cf625bc6b736U, 0x440efbbdeae8b904U, 0xeec8b8cb1d061d1fU,
  0xfc11471d30b4e040U, 0x57383acfca2a5994U, 0x22020c231b2251acU, 0x4c4b13a2ffea6cfU,
  0xf6df3b2826c0d259U, 0x1fb43e96e90656baU, 0x9bcac0caeef8cb67U, 0x112d0b053141758U,
  0x29eb0f3ffb9abd07U, 0x34bee29f5352b4c3U, 0x175c065cdd69565aU, 0x40ace7b6af0ca8bcU,
  0xd3e6b39921363e45U, 0xb3c6e7a9640c23b9U, 0xcbeb5c1cebf115cbU, 0xb81dcf3a583c2c25U,
  0xa6a6d5c6bf2ba93aU, 0x35584af225ed660dU, 0x197f7110e5bbfd09U, 0x42b0b02807a04bdcU,
  0x5ce801bc48f20649U, 0xe7213350195f5340U, 0x23ffdc51ed9c42baU, 0xec7a63c85ce300d4U,
  0x4fc4c31f6eda48fdU, 0x6f07baddb767de0fU, 0xe8bae125440eac34U, 0xb2e6dcf999d7f4e2U,
  0xdf56ccb2c107e5e2U, 0x8670f3640fa6019U, 0x9b1435f44ea7026aU, 0xe335deede5ba0b40U,
  0x514ac9274e2d4eecU, 0x8a3703b69940cfd4U, 0x283da6e9ee6d0550U, 0x4dd2d3a6ce27345cU,
  0x615d4f2b53fefae0U, 0xd2e2c16c5335e49eU, 0xb73c03e2b85f49daU, 0x6fb7eddf1c63131cU,
  0xf014ea319e27fba1U, 0xa40e2364a65d983cU, 0x244fbcd4eeabadd3U, 0xd03cda16102acde8U,
  0xbd10e1bf2fa364f1U, 0xe0a30b11e7d32b5aU, 0x184eed1ba336b4e7U, 0x53bb406425d9e35fU,
  0x77dea3dba6fb105cU, 0x2057e0f013fa3b3eU, 0xbcd04e0dd538f0ecU, 0x2e496644d6272170U,
  0xbea9dbf5c0f2419aU, 0xf1b23c41b3544435U, 0x17f839eac61ccbc5U, 0xec2a93b050dfaf98U,
  0x9f22be1d929c8b5fU, 0x51e94612c7ebaca0U, 0x29f0ebdb3032fa98U, 0x3c11b52dff8f3c8U,
  0x1623071e3e42fb21U, 0xbfde9aaa962125f7U, 0xf2e4ccef2b5ccffdU, 0xffebaeab5336ecd6U,
  0x4fb52ddade2d47b4U, 0xc0b3a0b0ac0c5dfU, 0xb0351f2a42bacae5U, 0x456a3458f2e23cc4U,
  0x2fb76fe8b023d9b8U, 0x6c54f03e2cc942dcU, 0xd2acda2cc6c7cbc4U, 0x5364d9d7c5543a43U,
  0xefb00c571dea1104U, 0xb1f9be19f3197b17U, 0x76aefc918e544e4U, 0xb87f2f5751aa6342U,
  0x6945cdc6bfb044c8U, 0x76bf170da20a57ceU, 0x6049650be5692ddaU, 0x2f22464adf0bc70dU,
  0xa82b19ef1e1e515cU, 0x19dafcbb4921b819U, 0xbbcec591a03d3c5U, 0x351ebf611aeb483aU,
  0x2a51d064c43942bfU, 0x331114a429265c6eU, 0xc450ad46f9c74d2aU, 0xa9405169bbd449e2U,
  0xa7a4d75d4dfaf662U, 0xb419b197a907f15eU, 0x5efe33a21cb8a53bU, 0x67dcd5b3c9e065e9U,
  0xdaf4b8eb725ca558U, 0xa0993d9fe65f1caaU, 0x9fd8131725ae385bU, 0x5202440101c6dc47U,
  0x445cb128e9c21141U, 0x18692e98f9d0dc06U, 0x1fe799a401092bbcU, 0xfbfcecc733f6a9e7U,
  0xff5a12c43e279bbeU, 0x30a366eda027ce2aU, 0xb52aa6efc62cacd7U, 0xe8dab2afe78a528fU,
  0xb646c2a5084c2dc5U, 0xd8c5e8b4ee2c581dU, 0x194c0d5423fe3755U, 0xb05ec74f015c54a0U,
  0x73de0b4e425ad43U, 0x52c3ad3b30da1733U, 0x892c0e53cc02422U, 0x309526610c9a55bfU,
  0xb2b5d5fbb8e33bffU, 0x33e8041af470a30fU, 0xd6c7a516eb5d01d5U, 0xb8e44112e3a20153U,
  0xdcf7f3982ec25f1dU, 0x16101bf6f5cc9469U, 0xfffffffc0000000fU, 0xfffffff200000006U,
  0x50000000eU, 0xbfffffff6U, 0xfffffff3fffffff3U, 0x10000000cU,
  0xdfffffffaU, 0xfffffff6fffffff4U, 0xfffffff3fffffff0U, 0xffffffeb0000001fU,
  0xfffffffd00000000U, 0xffffffeb00000014U, 0xffffffee00000017U, 0x700000000U,
  0x9817d4a17f9fbfaaU, 0xaf187dc99bb47557U, 0x65e31410b787ca6aU, 0xfffffff6c59852e1U,
  0x6f81fbf9eb28488cU, 0x5606c781bec9d4ffU, 0x7b67f8d30958224dU, 0xa8a15349403e7081U,
  0x681f751U,
};


ai_handle g_bat_det_net_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_bat_det_net_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

