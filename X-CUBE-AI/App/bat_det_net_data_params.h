/**
  ******************************************************************************
  * @file    bat_det_net_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Jan 27 22:36:30 2024
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

#ifndef BAT_DET_NET_DATA_PARAMS_H
#define BAT_DET_NET_DATA_PARAMS_H
#pragma once

#include "ai_platform.h"

/*
#define AI_BAT_DET_NET_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_bat_det_net_data_weights_params[1]))
*/

#define AI_BAT_DET_NET_DATA_CONFIG               (NULL)


#define AI_BAT_DET_NET_DATA_ACTIVATIONS_SIZES \
  { 2788, }
#define AI_BAT_DET_NET_DATA_ACTIVATIONS_SIZE     (2788)
#define AI_BAT_DET_NET_DATA_ACTIVATIONS_COUNT    (1)
#define AI_BAT_DET_NET_DATA_ACTIVATION_1_SIZE    (2788)



#define AI_BAT_DET_NET_DATA_WEIGHTS_SIZES \
  { 1924, }
#define AI_BAT_DET_NET_DATA_WEIGHTS_SIZE         (1924)
#define AI_BAT_DET_NET_DATA_WEIGHTS_COUNT        (1)
#define AI_BAT_DET_NET_DATA_WEIGHT_1_SIZE        (1924)



#define AI_BAT_DET_NET_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_bat_det_net_activations_table[1])

extern ai_handle g_bat_det_net_activations_table[1 + 2];



#define AI_BAT_DET_NET_DATA_WEIGHTS_TABLE_GET() \
  (&g_bat_det_net_weights_table[1])

extern ai_handle g_bat_det_net_weights_table[1 + 2];


#endif    /* BAT_DET_NET_DATA_PARAMS_H */
