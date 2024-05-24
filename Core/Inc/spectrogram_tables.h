/*
 * spectrogram_tables.h
 *
 *  Created on: Oct 25, 2023
 *      Author: base_usr
 */

#ifndef INC_SPECTROGRAM_TABLES_H_
#define INC_SPECTROGRAM_TABLES_H_

#include "arm_math.h"

const q15_t hamming_window[512] = {2621, 2622, 2625, 2631, 2639, 2649, 2662, 2677, 2694, 2713, 2735, 2759, 2785, 2813, 2844, 2877, 2912, 2949, 2989, 3030, 3074, 3121, 3169, 3220, 3273,
 3328, 3385, 3444, 3505, 3569, 3635, 3703, 3773, 3845, 3919, 3995, 4074, 4154, 4237, 4321, 4408, 4496, 4587, 4679, 4774, 4870, 4968, 5069, 5171, 5275, 5381, 5489, 5598, 5710, 5823,
  5938, 6055, 6174, 6294, 6416, 6540, 6666, 6793, 6922, 7052, 7184, 7318, 7453, 7590, 7728, 7868, 8009, 8152, 8296, 8442, 8589, 8737, 8887, 9038, 9190, 9344, 9499, 9655, 9813, 9971,
  10131, 10292, 10454, 10617, 10781, 10946, 11112, 11280, 11448, 11617, 11787, 11958, 12130, 12303, 12476, 12650, 12825, 13001, 13178, 13355, 13533, 13711, 13890, 14070, 14250, 14431,
  14612, 14793, 14975, 15158, 15341, 15524, 15708, 15891, 16076, 16260, 16445, 16629, 16814, 16999, 17185, 17370, 17555, 17741, 17926, 18111, 18296, 18482, 18667, 18851, 19036, 19221,
  19405, 19589, 19773, 19956, 20139, 20322, 20504, 20686, 20867, 21048, 21229, 21409, 21588, 21767, 21945, 22122, 22299, 22475, 22651, 22825, 22999, 23172, 23345, 23516, 23686, 23856,
  24025, 24192, 24359, 24525, 24690, 24853, 25016, 25177, 25338, 25497, 25655, 25812, 25967, 26121, 26274, 26426, 26577, 26726, 26873, 27020, 27165, 27308, 27450, 27591, 27730, 27867,
  28003, 28138, 28270, 28402, 28531, 28659, 28786, 28910, 29033, 29155, 29274, 29392, 29508, 29622, 29734, 29845, 29954, 30061, 30166, 30269, 30370, 30469, 30567, 30662, 30756, 30847,
  30937, 31024, 31110, 31193, 31275, 31354, 31431, 31507, 31580, 31651, 31720, 31787, 31851, 31914, 31974, 32033, 32089, 32143, 32194, 32244, 32291, 32336, 32379, 32420, 32458, 32495, 
  32529, 32560, 32590, 32617, 32642, 32665, 32685, 32703, 32719, 32733, 32744, 32754, 32760, 32765, 32767, 32767, 32765, 32760, 32754, 32744, 32733, 32719, 32703, 32685, 32665, 32642, 
  32617, 32590, 32560, 32529, 32495, 32458, 32420, 32379, 32336, 32291, 32244, 32194, 32143, 32089, 32033, 31974, 31914, 31851, 31787, 31720, 31651, 31580, 31507, 31431, 31354, 31275, 
  31193, 31110, 31024, 30937, 30847, 30756, 30662, 30567, 30469, 30370, 30269, 30166, 30061, 29954, 29845, 29734, 29622, 29508, 29392, 29274, 29155, 29033, 28910, 28786, 28659, 28531, 
  28402, 28270, 28138, 28003, 27867, 27730, 27591, 27450, 27308, 27165, 27020, 26873, 26726, 26577, 26426, 26274, 26121, 25967, 25812, 25655, 25497, 25338, 25177, 25016, 24853, 24690, 
  24525, 24359, 24192, 24025, 23856, 23686, 23516, 23345, 23172, 22999, 22825, 22651, 22475, 22299, 22122, 21945, 21767, 21588, 21409, 21229, 21048, 20867, 20686, 20504, 20322, 20139, 
  19956, 19773, 19589, 19405, 19221, 19036, 18851, 18667, 18482, 18296, 18111, 17926, 17741, 17555, 17370, 17185, 16999, 16814, 16629, 16445, 16260, 16076, 15891, 15708, 15524, 15341, 
  15158, 14975, 14793, 14612, 14431, 14250, 14070, 13890, 13711, 13533, 13355, 13178, 13001, 12825, 12650, 12476, 12303, 12130, 11958, 11787, 11617, 11448, 11280, 11112, 10946, 10781, 
  10617, 10454, 10292, 10131, 9971, 9813, 9655, 9499, 9344, 9190, 9038, 8887, 8737, 8589, 8442, 8296, 8152, 8009, 7868, 7728, 7590, 7453, 7318, 7184, 7052, 6922, 6793, 6666, 6540, 6416, 
  6294, 6174, 6055, 5938, 5823, 5710, 5598, 5489, 5381, 5275, 5171, 5069, 4968, 4870, 4774, 4679, 4587, 4496, 4408, 4321, 4237, 4154, 4074, 3995, 3919, 3845, 3773, 3703, 3635, 3569, 
  3505, 3444, 3385, 3328, 3273, 3220, 3169, 3121, 3074, 3030, 2989, 2949, 2912, 2877, 2844, 2813, 2785, 2759, 2735, 2713, 2694, 2677, 2662, 2649, 2639, 2631, 2625, 2622, 2621};

const q15_t l0[4] = {13693, 28364, 23618, 10545};
const q15_t l1[5] = {9149, 22222, 30516, 18868, 7220};
const q15_t l2[6] = {2251, 13899, 25547, 28822, 18444, 8065};
const q15_t l3[7] = {3945, 14323, 24702, 30706, 21459, 12211, 2963};
const q15_t l4[8] = {2061, 11308, 20556, 29804, 27168, 18928, 10688, 2449};
const q15_t l5[8] = {5599, 13839, 22079, 30318, 27608, 20266, 12924, 5582};
const q15_t l6[9] = {5159, 12501, 19843, 27185, 31200, 24658, 18116, 11574, 5032};
const q15_t l7[11] = {1567, 8109, 14651, 21193, 27735, 31423, 25594, 19765, 13936, 8107, 2278};
const q15_t l8[12] = {1344, 7173, 13002, 18831, 24660, 30489, 29604, 24410, 19217, 14023, 8829, 3635};
const q15_t l9[13] = {3163, 8357, 13550, 18744, 23938, 29132, 31379, 26752, 22124, 17496, 12868, 8241, 3613};
const q15_t l10[15] = {1388, 6015, 10643, 15271, 19899, 24526, 29154, 31864, 27740, 23617, 19493, 15370, 11247, 7123, 3000};
const q15_t l11[17] = {903, 5027, 9150, 13274, 17397, 21520, 25644, 29767, 31767, 28093, 24419, 20744, 17070, 13396, 9722, 6048, 2374};
const q15_t l12[19] = {1000, 4674, 8348, 12023, 15697, 19371, 23045, 26719, 30393, 31610, 28336, 25062, 21789, 18515, 15241, 11968, 8694, 5420, 2146};
const q15_t l13[21] = {1157, 4431, 7705, 10978, 14252, 17526, 20799, 24073, 27347, 30621, 31764, 28847, 25930, 23013, 20096, 17179, 14262, 11345, 8428, 5511, 2594};
const q15_t l14[24] = {1003, 3920, 6837, 9754, 12671, 15588, 18505, 21422, 24339, 27256, 30173, 32480, 29881, 27282, 24683, 22084, 19485, 16886, 14287, 11688, 9089, 6490, 3891, 1292};
const q15_t l15[27] = {287, 2886, 5485, 8084, 10683, 13282, 15881, 18480, 21079, 23678, 26277, 28876, 31475, 31603, 29287, 26971, 24656, 22340, 20024, 17708, 15392, 13076, 10761, 8445, 6129, 3813, 1497};        
const q15_t l16[30] = {1164, 3480, 5796, 8111, 10427, 12743, 15059, 17375, 19691, 22006, 24322, 26638, 28954, 31270, 32039, 29975, 27912, 25848, 23785, 21721, 19658, 17595, 15531, 13468, 11404, 9341, 7277, 5214, 3150, 1087};
const q15_t l17[34] = {728, 2792, 4855, 6919, 8982, 11046, 13109, 15172, 17236, 19299, 21363, 23426, 25490, 27553, 29617, 31680, 31898, 30059, 28221, 26382, 24543, 22705, 20866, 19028, 17189, 15351, 13512, 11673, 9835, 7996, 6158, 4319, 2480, 642};
const q15_t l18[38] = {869, 2708, 4546, 6385, 8224, 10062, 11901, 13739, 15578, 17416, 19255, 21094, 22932, 24771, 26609, 28448, 30287, 32125, 31702, 30063, 28425, 26787, 25149, 23510, 21872, 20234, 18596, 16958, 15319, 13681, 12043, 10405, 8766, 7128, 5490, 3852, 2214, 575};
const q15_t l19[42] = {1065, 2704, 4342, 5980, 7618, 9257, 10895, 12533, 14171, 15809, 17448, 19086, 20724, 22362, 24001, 25639, 27277, 28915, 30553, 32192, 31821, 30361, 28902, 27442, 25982, 24522, 23063, 21603, 20143, 18684, 17224, 15764, 14305, 12845, 11385, 9925, 8466, 7006, 5546, 4087, 2627, 1167};
const int8_t l_lens[20] = { 4, 5, 6, 7, 8, 8, 9, 11, 12, 13, 15, 17, 19, 21, 24, 27, 30, 34, 38, 42 };
const uint8_t s_pos[20] = { 18, 20, 22, 25, 28, 32, 36, 40, 45, 51, 57, 64, 72, 81, 91, 102, 115, 129, 145, 163 };
#define MIN_INDEX_MATMUL 18
#define MAX_INDEX_MATMUL (18+163)
//+1 to make it even for optimizations

const q15_t* ls[20] = {l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19};
#endif /* INC_SPECTROGRAM_TABLES_H_ */
