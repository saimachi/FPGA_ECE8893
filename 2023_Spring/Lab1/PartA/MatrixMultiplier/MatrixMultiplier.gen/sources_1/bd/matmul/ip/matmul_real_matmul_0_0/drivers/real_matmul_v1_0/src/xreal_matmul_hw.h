// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x08 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x10 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x18 : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x20 : Data signal of MatA_DRAM
//        bit 63~0 - MatA_DRAM[63:0] (Read/Write)
// 0x28 : reserved
// 0x30 : Data signal of MatB_DRAM
//        bit 63~0 - MatB_DRAM[63:0] (Read/Write)
// 0x38 : reserved
// 0x40 : Data signal of MatC_DRAM
//        bit 63~0 - MatC_DRAM[63:0] (Read/Write)
// 0x48 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XREAL_MATMUL_CONTROL_ADDR_AP_CTRL        0x00
#define XREAL_MATMUL_CONTROL_ADDR_GIE            0x08
#define XREAL_MATMUL_CONTROL_ADDR_IER            0x10
#define XREAL_MATMUL_CONTROL_ADDR_ISR            0x18
#define XREAL_MATMUL_CONTROL_ADDR_MATA_DRAM_DATA 0x20
#define XREAL_MATMUL_CONTROL_BITS_MATA_DRAM_DATA 64
#define XREAL_MATMUL_CONTROL_ADDR_MATB_DRAM_DATA 0x30
#define XREAL_MATMUL_CONTROL_BITS_MATB_DRAM_DATA 64
#define XREAL_MATMUL_CONTROL_ADDR_MATC_DRAM_DATA 0x40
#define XREAL_MATMUL_CONTROL_BITS_MATC_DRAM_DATA 64

// control_r
// 0x000 : reserved
// 0x008 : reserved
// 0x010 : reserved
// 0x018 : reserved
// 0x020 : Data signal of MatA_DRAM_0
//         bit 63~0 - MatA_DRAM_0[63:0] (Read/Write)
// 0x028 : reserved
// 0x030 : Data signal of MatA_DRAM_1
//         bit 63~0 - MatA_DRAM_1[63:0] (Read/Write)
// 0x038 : reserved
// 0x040 : Data signal of MatA_DRAM_2
//         bit 63~0 - MatA_DRAM_2[63:0] (Read/Write)
// 0x048 : reserved
// 0x050 : Data signal of MatA_DRAM_3
//         bit 63~0 - MatA_DRAM_3[63:0] (Read/Write)
// 0x058 : reserved
// 0x060 : Data signal of MatA_DRAM_4
//         bit 63~0 - MatA_DRAM_4[63:0] (Read/Write)
// 0x068 : reserved
// 0x070 : Data signal of MatA_DRAM_5
//         bit 63~0 - MatA_DRAM_5[63:0] (Read/Write)
// 0x078 : reserved
// 0x080 : Data signal of MatA_DRAM_6
//         bit 63~0 - MatA_DRAM_6[63:0] (Read/Write)
// 0x088 : reserved
// 0x090 : Data signal of MatA_DRAM_7
//         bit 63~0 - MatA_DRAM_7[63:0] (Read/Write)
// 0x098 : reserved
// 0x0a0 : Data signal of MatA_DRAM_8
//         bit 63~0 - MatA_DRAM_8[63:0] (Read/Write)
// 0x0a8 : reserved
// 0x0b0 : Data signal of MatA_DRAM_9
//         bit 63~0 - MatA_DRAM_9[63:0] (Read/Write)
// 0x0b8 : reserved
// 0x0c0 : Data signal of MatA_DRAM_10
//         bit 63~0 - MatA_DRAM_10[63:0] (Read/Write)
// 0x0c8 : reserved
// 0x0d0 : Data signal of MatA_DRAM_11
//         bit 63~0 - MatA_DRAM_11[63:0] (Read/Write)
// 0x0d8 : reserved
// 0x0e0 : Data signal of MatA_DRAM_12
//         bit 63~0 - MatA_DRAM_12[63:0] (Read/Write)
// 0x0e8 : reserved
// 0x0f0 : Data signal of MatA_DRAM_13
//         bit 63~0 - MatA_DRAM_13[63:0] (Read/Write)
// 0x0f8 : reserved
// 0x100 : Data signal of MatA_DRAM_14
//         bit 63~0 - MatA_DRAM_14[63:0] (Read/Write)
// 0x108 : reserved
// 0x110 : Data signal of MatA_DRAM_15
//         bit 63~0 - MatA_DRAM_15[63:0] (Read/Write)
// 0x118 : reserved
// 0x120 : Data signal of MatA_DRAM_16
//         bit 63~0 - MatA_DRAM_16[63:0] (Read/Write)
// 0x128 : reserved
// 0x130 : Data signal of MatA_DRAM_17
//         bit 63~0 - MatA_DRAM_17[63:0] (Read/Write)
// 0x138 : reserved
// 0x140 : Data signal of MatA_DRAM_18
//         bit 63~0 - MatA_DRAM_18[63:0] (Read/Write)
// 0x148 : reserved
// 0x150 : Data signal of MatA_DRAM_19
//         bit 63~0 - MatA_DRAM_19[63:0] (Read/Write)
// 0x158 : reserved
// 0x160 : Data signal of MatA_DRAM_20
//         bit 63~0 - MatA_DRAM_20[63:0] (Read/Write)
// 0x168 : reserved
// 0x170 : Data signal of MatA_DRAM_21
//         bit 63~0 - MatA_DRAM_21[63:0] (Read/Write)
// 0x178 : reserved
// 0x180 : Data signal of MatA_DRAM_22
//         bit 63~0 - MatA_DRAM_22[63:0] (Read/Write)
// 0x188 : reserved
// 0x190 : Data signal of MatA_DRAM_23
//         bit 63~0 - MatA_DRAM_23[63:0] (Read/Write)
// 0x198 : reserved
// 0x1a0 : Data signal of MatA_DRAM_24
//         bit 63~0 - MatA_DRAM_24[63:0] (Read/Write)
// 0x1a8 : reserved
// 0x1b0 : Data signal of MatB_DRAM_0
//         bit 63~0 - MatB_DRAM_0[63:0] (Read/Write)
// 0x1b8 : reserved
// 0x1c0 : Data signal of MatB_DRAM_1
//         bit 63~0 - MatB_DRAM_1[63:0] (Read/Write)
// 0x1c8 : reserved
// 0x1d0 : Data signal of MatB_DRAM_2
//         bit 63~0 - MatB_DRAM_2[63:0] (Read/Write)
// 0x1d8 : reserved
// 0x1e0 : Data signal of MatB_DRAM_3
//         bit 63~0 - MatB_DRAM_3[63:0] (Read/Write)
// 0x1e8 : reserved
// 0x1f0 : Data signal of MatB_DRAM_4
//         bit 63~0 - MatB_DRAM_4[63:0] (Read/Write)
// 0x1f8 : reserved
// 0x200 : Data signal of MatB_DRAM_5
//         bit 63~0 - MatB_DRAM_5[63:0] (Read/Write)
// 0x208 : reserved
// 0x210 : Data signal of MatB_DRAM_6
//         bit 63~0 - MatB_DRAM_6[63:0] (Read/Write)
// 0x218 : reserved
// 0x220 : Data signal of MatB_DRAM_7
//         bit 63~0 - MatB_DRAM_7[63:0] (Read/Write)
// 0x228 : reserved
// 0x230 : Data signal of MatB_DRAM_8
//         bit 63~0 - MatB_DRAM_8[63:0] (Read/Write)
// 0x238 : reserved
// 0x240 : Data signal of MatB_DRAM_9
//         bit 63~0 - MatB_DRAM_9[63:0] (Read/Write)
// 0x248 : reserved
// 0x250 : Data signal of MatB_DRAM_10
//         bit 63~0 - MatB_DRAM_10[63:0] (Read/Write)
// 0x258 : reserved
// 0x260 : Data signal of MatB_DRAM_11
//         bit 63~0 - MatB_DRAM_11[63:0] (Read/Write)
// 0x268 : reserved
// 0x270 : Data signal of MatB_DRAM_12
//         bit 63~0 - MatB_DRAM_12[63:0] (Read/Write)
// 0x278 : reserved
// 0x280 : Data signal of MatB_DRAM_13
//         bit 63~0 - MatB_DRAM_13[63:0] (Read/Write)
// 0x288 : reserved
// 0x290 : Data signal of MatB_DRAM_14
//         bit 63~0 - MatB_DRAM_14[63:0] (Read/Write)
// 0x298 : reserved
// 0x2a0 : Data signal of MatB_DRAM_15
//         bit 63~0 - MatB_DRAM_15[63:0] (Read/Write)
// 0x2a8 : reserved
// 0x2b0 : Data signal of MatB_DRAM_16
//         bit 63~0 - MatB_DRAM_16[63:0] (Read/Write)
// 0x2b8 : reserved
// 0x2c0 : Data signal of MatB_DRAM_17
//         bit 63~0 - MatB_DRAM_17[63:0] (Read/Write)
// 0x2c8 : reserved
// 0x2d0 : Data signal of MatB_DRAM_18
//         bit 63~0 - MatB_DRAM_18[63:0] (Read/Write)
// 0x2d8 : reserved
// 0x2e0 : Data signal of MatB_DRAM_19
//         bit 63~0 - MatB_DRAM_19[63:0] (Read/Write)
// 0x2e8 : reserved
// 0x2f0 : Data signal of MatB_DRAM_20
//         bit 63~0 - MatB_DRAM_20[63:0] (Read/Write)
// 0x2f8 : reserved
// 0x300 : Data signal of MatB_DRAM_21
//         bit 63~0 - MatB_DRAM_21[63:0] (Read/Write)
// 0x308 : reserved
// 0x310 : Data signal of MatB_DRAM_22
//         bit 63~0 - MatB_DRAM_22[63:0] (Read/Write)
// 0x318 : reserved
// 0x320 : Data signal of MatB_DRAM_23
//         bit 63~0 - MatB_DRAM_23[63:0] (Read/Write)
// 0x328 : reserved
// 0x330 : Data signal of MatB_DRAM_24
//         bit 63~0 - MatB_DRAM_24[63:0] (Read/Write)
// 0x338 : reserved
// 0x340 : Data signal of MatB_DRAM_25
//         bit 63~0 - MatB_DRAM_25[63:0] (Read/Write)
// 0x348 : reserved
// 0x350 : Data signal of MatB_DRAM_26
//         bit 63~0 - MatB_DRAM_26[63:0] (Read/Write)
// 0x358 : reserved
// 0x360 : Data signal of MatB_DRAM_27
//         bit 63~0 - MatB_DRAM_27[63:0] (Read/Write)
// 0x368 : reserved
// 0x370 : Data signal of MatB_DRAM_28
//         bit 63~0 - MatB_DRAM_28[63:0] (Read/Write)
// 0x378 : reserved
// 0x380 : Data signal of MatB_DRAM_29
//         bit 63~0 - MatB_DRAM_29[63:0] (Read/Write)
// 0x388 : reserved
// 0x390 : Data signal of MatB_DRAM_30
//         bit 63~0 - MatB_DRAM_30[63:0] (Read/Write)
// 0x398 : reserved
// 0x3a0 : Data signal of MatB_DRAM_31
//         bit 63~0 - MatB_DRAM_31[63:0] (Read/Write)
// 0x3a8 : reserved
// 0x3b0 : Data signal of MatB_DRAM_32
//         bit 63~0 - MatB_DRAM_32[63:0] (Read/Write)
// 0x3b8 : reserved
// 0x3c0 : Data signal of MatB_DRAM_33
//         bit 63~0 - MatB_DRAM_33[63:0] (Read/Write)
// 0x3c8 : reserved
// 0x3d0 : Data signal of MatB_DRAM_34
//         bit 63~0 - MatB_DRAM_34[63:0] (Read/Write)
// 0x3d8 : reserved
// 0x3e0 : Data signal of MatB_DRAM_35
//         bit 63~0 - MatB_DRAM_35[63:0] (Read/Write)
// 0x3e8 : reserved
// 0x3f0 : Data signal of MatB_DRAM_36
//         bit 63~0 - MatB_DRAM_36[63:0] (Read/Write)
// 0x3f8 : reserved
// 0x400 : Data signal of MatB_DRAM_37
//         bit 63~0 - MatB_DRAM_37[63:0] (Read/Write)
// 0x408 : reserved
// 0x410 : Data signal of MatB_DRAM_38
//         bit 63~0 - MatB_DRAM_38[63:0] (Read/Write)
// 0x418 : reserved
// 0x420 : Data signal of MatB_DRAM_39
//         bit 63~0 - MatB_DRAM_39[63:0] (Read/Write)
// 0x428 : reserved
// 0x430 : Data signal of MatB_DRAM_40
//         bit 63~0 - MatB_DRAM_40[63:0] (Read/Write)
// 0x438 : reserved
// 0x440 : Data signal of MatB_DRAM_41
//         bit 63~0 - MatB_DRAM_41[63:0] (Read/Write)
// 0x448 : reserved
// 0x450 : Data signal of MatB_DRAM_42
//         bit 63~0 - MatB_DRAM_42[63:0] (Read/Write)
// 0x458 : reserved
// 0x460 : Data signal of MatB_DRAM_43
//         bit 63~0 - MatB_DRAM_43[63:0] (Read/Write)
// 0x468 : reserved
// 0x470 : Data signal of MatB_DRAM_44
//         bit 63~0 - MatB_DRAM_44[63:0] (Read/Write)
// 0x478 : reserved
// 0x480 : Data signal of MatB_DRAM_45
//         bit 63~0 - MatB_DRAM_45[63:0] (Read/Write)
// 0x488 : reserved
// 0x490 : Data signal of MatB_DRAM_46
//         bit 63~0 - MatB_DRAM_46[63:0] (Read/Write)
// 0x498 : reserved
// 0x4a0 : Data signal of MatB_DRAM_47
//         bit 63~0 - MatB_DRAM_47[63:0] (Read/Write)
// 0x4a8 : reserved
// 0x4b0 : Data signal of MatB_DRAM_48
//         bit 63~0 - MatB_DRAM_48[63:0] (Read/Write)
// 0x4b8 : reserved
// 0x4c0 : Data signal of MatB_DRAM_49
//         bit 63~0 - MatB_DRAM_49[63:0] (Read/Write)
// 0x4c8 : reserved
// 0x4d0 : Data signal of MatC_DRAM
//         bit 63~0 - MatC_DRAM[63:0] (Read/Write)
// 0x4d8 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_0_DATA  0x020
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_0_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_1_DATA  0x030
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_1_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_2_DATA  0x040
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_2_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_3_DATA  0x050
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_3_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_4_DATA  0x060
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_4_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_5_DATA  0x070
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_5_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_6_DATA  0x080
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_6_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_7_DATA  0x090
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_7_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_8_DATA  0x0a0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_8_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_9_DATA  0x0b0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_9_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_10_DATA 0x0c0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_10_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_11_DATA 0x0d0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_11_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_12_DATA 0x0e0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_12_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_13_DATA 0x0f0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_13_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_14_DATA 0x100
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_14_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_15_DATA 0x110
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_15_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_16_DATA 0x120
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_16_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_17_DATA 0x130
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_17_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_18_DATA 0x140
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_18_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_19_DATA 0x150
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_19_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_20_DATA 0x160
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_20_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_21_DATA 0x170
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_21_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_22_DATA 0x180
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_22_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_23_DATA 0x190
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_23_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_24_DATA 0x1a0
#define XREAL_MATMUL_CONTROL_R_BITS_MATA_DRAM_24_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_0_DATA  0x1b0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_0_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_1_DATA  0x1c0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_1_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_2_DATA  0x1d0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_2_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_3_DATA  0x1e0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_3_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_4_DATA  0x1f0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_4_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_5_DATA  0x200
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_5_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_6_DATA  0x210
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_6_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_7_DATA  0x220
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_7_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_8_DATA  0x230
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_8_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_9_DATA  0x240
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_9_DATA  64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_10_DATA 0x250
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_10_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_11_DATA 0x260
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_11_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_12_DATA 0x270
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_12_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_13_DATA 0x280
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_13_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_14_DATA 0x290
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_14_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_15_DATA 0x2a0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_15_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_16_DATA 0x2b0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_16_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_17_DATA 0x2c0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_17_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_18_DATA 0x2d0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_18_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_19_DATA 0x2e0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_19_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_20_DATA 0x2f0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_20_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_21_DATA 0x300
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_21_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_22_DATA 0x310
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_22_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_23_DATA 0x320
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_23_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_24_DATA 0x330
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_24_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_25_DATA 0x340
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_25_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_26_DATA 0x350
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_26_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_27_DATA 0x360
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_27_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_28_DATA 0x370
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_28_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_29_DATA 0x380
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_29_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_30_DATA 0x390
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_30_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_31_DATA 0x3a0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_31_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_32_DATA 0x3b0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_32_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_33_DATA 0x3c0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_33_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_34_DATA 0x3d0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_34_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_35_DATA 0x3e0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_35_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_36_DATA 0x3f0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_36_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_37_DATA 0x400
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_37_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_38_DATA 0x410
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_38_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_39_DATA 0x420
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_39_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_40_DATA 0x430
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_40_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_41_DATA 0x440
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_41_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_42_DATA 0x450
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_42_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_43_DATA 0x460
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_43_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_44_DATA 0x470
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_44_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_45_DATA 0x480
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_45_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_46_DATA 0x490
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_46_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_47_DATA 0x4a0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_47_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_48_DATA 0x4b0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_48_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_49_DATA 0x4c0
#define XREAL_MATMUL_CONTROL_R_BITS_MATB_DRAM_49_DATA 64
#define XREAL_MATMUL_CONTROL_R_ADDR_MATC_DRAM_DATA    0x4d0
#define XREAL_MATMUL_CONTROL_R_BITS_MATC_DRAM_DATA    64

