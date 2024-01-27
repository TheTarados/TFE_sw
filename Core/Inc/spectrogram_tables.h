/*
 * spectrogram_tables.h
 *
 *  Created on: Oct 25, 2023
 *      Author: base_usr
 */

#ifndef INC_SPECTROGRAM_TABLES_H_
#define INC_SPECTROGRAM_TABLES_H_

#include "arm_math.h"

const q15_t hamming_window[512] = {2621,
2622,
2625,
2631,
2639,
2649,
2662,
2677,
2694,
2713,
2735,
2759,
2785,
2813,
2844,
2877,
2912,
2949,
2989,
3030,
3074,
3121,
3169,
3220,
3272,
3327,
3385,
3444,
3505,
3569,
3635,
3703,
3773,
3845,
3919,
3995,
4074,
4154,
4236,
4321,
4407,
4496,
4587,
4679,
4773,
4870,
4968,
5069,
5171,
5275,
5381,
5489,
5598,
5710,
5823,
5938,
6055,
6174,
6294,
6416,
6540,
6666,
6793,
6922,
7052,
7184,
7318,
7453,
7590,
7728,
7868,
8009,
8152,
8296,
8442,
8589,
8737,
8887,
9038,
9190,
9344,
9499,
9655,
9812,
9971,
10131,
10291,
10453,
10617,
10781,
10946,
11112,
11279,
11448,
11617,
11787,
11958,
12129,
12302,
12476,
12650,
12825,
13001,
13177,
13354,
13532,
13711,
13890,
14069,
14249,
14430,
14611,
14793,
14975,
15157,
15340,
15524,
15707,
15891,
16075,
16260,
16444,
16629,
16814,
16999,
17184,
17369,
17555,
17740,
17925,
18111,
18296,
18481,
18666,
18851,
19036,
19220,
19404,
19588,
19772,
19955,
20138,
20321,
20503,
20685,
20867,
21048,
21228,
21408,
21587,
21766,
21944,
22122,
22299,
22475,
22650,
22825,
22999,
23172,
23344,
23515,
23686,
23855,
24024,
24192,
24358,
24524,
24689,
24853,
25015,
25177,
25337,
25496,
25654,
25811,
25966,
26121,
26274,
26425,
26576,
26725,
26872,
27019,
27164,
27307,
27449,
27590,
27729,
27866,
28002,
28137,
28270,
28401,
28530,
28658,
28785,
28909,
29032,
29154,
29273,
29391,
29507,
29621,
29734,
29844,
29953,
30060,
30165,
30268,
30369,
30469,
30566,
30661,
30755,
30846,
30936,
31023,
31109,
31192,
31274,
31353,
31431,
31506,
31579,
31650,
31719,
31786,
31850,
31913,
31973,
32032,
32088,
32142,
32193,
32243,
32290,
32335,
32378,
32419,
32457,
32494,
32528,
32559,
32589,
32616,
32641,
32664,
32684,
32702,
32718,
32732,
32743,
32753,
32759,
32764,
32766,
32766,
32764,
32759,
32753,
32743,
32732,
32718,
32702,
32684,
32664,
32641,
32616,
32589,
32559,
32528,
32494,
32457,
32419,
32378,
32335,
32290,
32243,
32193,
32142,
32088,
32032,
31973,
31913,
31850,
31786,
31719,
31650,
31579,
31506,
31431,
31353,
31274,
31192,
31109,
31023,
30936,
30846,
30755,
30661,
30566,
30469,
30369,
30268,
30165,
30060,
29953,
29844,
29734,
29621,
29507,
29391,
29273,
29154,
29032,
28909,
28785,
28658,
28530,
28401,
28270,
28137,
28002,
27866,
27729,
27590,
27449,
27307,
27164,
27019,
26872,
26725,
26576,
26425,
26274,
26121,
25966,
25811,
25654,
25496,
25337,
25177,
25015,
24853,
24689,
24524,
24358,
24192,
24024,
23855,
23686,
23515,
23344,
23172,
22999,
22825,
22650,
22475,
22299,
22122,
21944,
21766,
21587,
21408,
21228,
21048,
20867,
20685,
20503,
20321,
20138,
19955,
19772,
19588,
19404,
19220,
19036,
18851,
18666,
18481,
18296,
18111,
17925,
17740,
17555,
17369,
17184,
16999,
16814,
16629,
16444,
16260,
16075,
15891,
15707,
15524,
15340,
15157,
14975,
14793,
14611,
14430,
14249,
14069,
13890,
13711,
13532,
13354,
13177,
13001,
12825,
12650,
12476,
12302,
12129,
11958,
11787,
11617,
11448,
11279,
11112,
10946,
10781,
10617,
10453,
10291,
10131,
9971,
9812,
9655,
9499,
9344,
9190,
9038,
8887,
8737,
8589,
8442,
8296,
8152,
8009,
7868,
7728,
7590,
7453,
7318,
7184,
7052,
6922,
6793,
6666,
6540,
6416,
6294,
6174,
6055,
5938,
5823,
5710,
5598,
5489,
5381,
5275,
5171,
5069,
4968,
4870,
4773,
4679,
4587,
4496,
4407,
4321,
4236,
4154,
4074,
3995,
3919,
3845,
3773,
3703,
3635,
3569,
3505,
3444,
3385,
3327,
3272,
3220,
3169,
3121,
3074,
3030,
2989,
2949,
2912,
2877,
2844,
2813,
2785,
2759,
2735,
2713,
2694,
2677,
2662,
2649,
2639,
2631,
2625,
2622,
2621
};


const q15_t l0[1] = {21856};
const q15_t l1[2] = {10911, 9974};
const q15_t l2[2] = {22793, 132};
const q15_t l3[1] = {32635};
const q15_t l4[1] = {25249};
const q15_t l5[2] = {7518, 19318};
const q15_t l6[2] = {13449, 14986};
const q15_t l7[2] = {17781, 12144};
const q15_t l8[2] = {20623, 10689};
const q15_t l9[2] = {22078, 10524};
const q15_t l10[2] = {22243, 11555};
const q15_t l11[2] = {21212, 13696};
const q15_t l12[2] = {19071, 16863};
const q15_t l13[2] = {15904, 20980};
const q15_t l14[2] = {11787, 25972};
const q15_t l15[3] = {6795, 31769, 5749};
const q15_t l16[3] = {998, 27018, 13238};
const q15_t l17[2] = {19529, 21371};
const q15_t l18[3] = {11396, 30090, 6822};
const q15_t l19[3] = {2677, 25945, 16925};
const q15_t l20[3] = {15842, 27478, 5883};
const q15_t l21[3] = {5289, 26884, 17630};
const q15_t l22[3] = {15137, 29709, 9665};
const q15_t l23[4] = {3058, 23102, 22768, 3458};
const q15_t l24[3] = {9999, 29309, 17495};
const q15_t l25[3] = {15272, 31700, 13777};
const q15_t l26[4] = {1067, 18990, 28773, 11506};
const q15_t l27[4] = {3994, 21261, 27217, 10582};
const q15_t l28[4] = {5550, 22185, 26936, 10909};
const q15_t l29[4] = {5831, 21858, 27837, 12397};
const q15_t l30[5] = {4930, 20370, 29836, 14960, 85};
const q15_t l31[5] = {2931, 17807, 32682, 18519, 4188};
const q15_t l32[4] = {14248, 28579, 22996, 9189};
const q15_t l33[5] = {9771, 23578, 28319, 15018, 1716};
const q15_t l34[5] = {4448, 17749, 31051, 21607, 8792};
const q15_t l35[5] = {11160, 23975, 28892, 16547, 4201};
const q15_t l36[6] = {3875, 16220, 28566, 24921, 13027, 1133};
const q15_t l37[5] = {7846, 19740, 31634, 22400, 10942};
const q15_t l38[5] = {10367, 21825, 32270, 21230, 10191};
const q15_t l39[7] = {497, 11537, 22576, 31950, 21314, 10679, 43};
const q15_t l40[7] = {817, 11453, 22088, 32724, 22563, 12317, 2070};
const q15_t l41[6] = {10204, 20450, 30697, 24891, 15020, 5148};
const q15_t l42[6] = {7876, 17747, 27619, 28217, 18707, 9197};
const q15_t l43[7] = {4550, 14060, 23570, 32466, 23304, 14141, 4979};
const q15_t l44[8] = {301, 9463, 18626, 27788, 28738, 19911, 11084, 2257};
const q15_t l45[8] = {4029, 12856, 21683, 30510, 26438, 17934, 9430, 926};
const q15_t l46[8] = {6329, 14833, 23337, 31841, 25467, 17274, 9082, 889};
const q15_t l47[8] = {7300, 15493, 23685, 31878, 25731, 17838, 9945, 2052};
const q15_t l48[8] = {7036, 14929, 22822, 30715, 27141, 19536, 11932, 4328};
const q15_t l49[9] = {5626, 13231, 20835, 28439, 29612, 22286, 14960, 7634, 308};
const q15_t l50[9] = {3155, 10481, 17807, 25133, 32459, 26006, 18948, 11891, 4833};
const q15_t l51[9] = {6761, 13819, 20876, 27934, 30624, 23824, 17025, 10225, 3425};
const q15_t l52[10] = {2143, 8943, 15742, 22542, 29342, 29517, 22966, 16416, 9865, 3314};
const q15_t l53[10] = {3250, 9801, 16351, 22902, 29453, 29649, 23338, 17027, 10716, 4405};
const q15_t l54[11] = {3118, 9429, 15740, 22051, 28362, 30931, 24851, 18771, 12691, 6611, 530};
const q15_t l55[11] = {1836, 7916, 13996, 20076, 26156, 32237, 27421, 21564, 15706, 9848, 3990};
const q15_t l56[11] = {5346, 11203, 17061, 22919, 28777, 30969, 25326, 19682, 14039, 8395, 2752};
const q15_t l57[12] = {1798, 7441, 13085, 18728, 24372, 30015, 29983, 24546, 19109, 13672, 8235, 2798};
const q15_t l58[12] = {2784, 8221, 13658, 19095, 24532, 29969, 30226, 24988, 19750, 14512, 9274, 4036};
const q15_t l59[13] = {2541, 7779, 13017, 18255, 23493, 28731, 31610, 26564, 21518, 16471, 11425, 6379, 1333};
const q15_t l60[14] = {1157, 6203, 11249, 16296, 21342, 26388, 31434, 29190, 24329, 19467, 14605, 9744, 4882, 20};
const q15_t l61[14] = {3577, 8438, 13300, 18162, 23023, 27885, 32747, 28104, 23420, 18736, 14053, 9369, 4685, 2};
const q15_t l62[14] = {4663, 9347, 14031, 18714, 23398, 28082, 32765, 28257, 23745, 19233, 14720, 10208, 5695, 1183};
const q15_t l63[14] = {4510, 9022, 13534, 18047, 22559, 27072, 31584, 29561, 25213, 20866, 16519, 12172, 7825, 3477};
const int8_t l_lens[64] = { 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 2, 3, 3, 3, 3, 3, 4, 3, 3, 4, 4, 4, 4, 5, 5, 4, 5, 5, 5, 6, 5, 5, 7, 7, 6, 6, 7, 8, 8, 8, 8, 8, 9, 9, 9, 10, 10, 11, 11, 11, 12, 12, 13, 14, 14, 14, 14 };
const uint8_t s_pos[64] = { 18, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 38, 39, 41, 42, 44, 46, 47, 49, 51, 53, 55, 57, 60, 62, 64, 67, 69, 72, 75, 77, 80, 84, 87, 90, 93, 97, 101, 105, 109, 113, 117, 122, 126, 131, 136, 141, 147, 152, 158, 164, 170, 177, 184, 191 };

#define MIN_INDEX_MATMUL 18
#define MAX_INDEX_MATMUL (191+14)

const q15_t* ls[64] = {l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, l33, l34, l35, l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l54, l55, l56, l57, l58, l59, l60, l61, l62, l63};
#endif /* INC_SPECTROGRAM_TABLES_H_ */
