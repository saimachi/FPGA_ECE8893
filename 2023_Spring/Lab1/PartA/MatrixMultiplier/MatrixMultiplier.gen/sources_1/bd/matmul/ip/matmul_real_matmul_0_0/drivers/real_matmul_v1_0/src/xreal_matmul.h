// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XREAL_MATMUL_H
#define XREAL_MATMUL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xreal_matmul_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
    u64 Control_r_BaseAddress;
} XReal_matmul_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u64 Control_r_BaseAddress;
    u64 IsReady;
} XReal_matmul;

typedef u64 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XReal_matmul_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out64((BaseAddress) + (RegOffset), (u64)(Data))
#define XReal_matmul_ReadReg(BaseAddress, RegOffset) \
    Xil_In64((BaseAddress) + (RegOffset))
#else
#define XReal_matmul_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u64*)((BaseAddress) + (RegOffset)) = (u64)(Data)
#define XReal_matmul_ReadReg(BaseAddress, RegOffset) \
    *(volatile u64*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XReal_matmul_Initialize(XReal_matmul *InstancePtr, u16 DeviceId);
XReal_matmul_Config* XReal_matmul_LookupConfig(u16 DeviceId);
int XReal_matmul_CfgInitialize(XReal_matmul *InstancePtr, XReal_matmul_Config *ConfigPtr);
#else
int XReal_matmul_Initialize(XReal_matmul *InstancePtr, const char* InstanceName);
int XReal_matmul_Release(XReal_matmul *InstancePtr);
#endif

void XReal_matmul_Start(XReal_matmul *InstancePtr);
u64 XReal_matmul_IsDone(XReal_matmul *InstancePtr);
u64 XReal_matmul_IsIdle(XReal_matmul *InstancePtr);
u64 XReal_matmul_IsReady(XReal_matmul *InstancePtr);
void XReal_matmul_EnableAutoRestart(XReal_matmul *InstancePtr);
void XReal_matmul_DisableAutoRestart(XReal_matmul *InstancePtr);

void XReal_matmul_Set_MatA_DRAM(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatC_DRAM(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatC_DRAM(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_0(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_0(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_1(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_1(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_2(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_2(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_3(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_3(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_4(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_4(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_5(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_5(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_6(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_6(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_7(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_7(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_8(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_8(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_9(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_9(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_10(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_10(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_11(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_11(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_12(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_12(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_13(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_13(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_14(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_14(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_15(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_15(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_16(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_16(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_17(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_17(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_18(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_18(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_19(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_19(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_20(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_20(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_21(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_21(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_22(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_22(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_23(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_23(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatA_DRAM_24(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatA_DRAM_24(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_0(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_0(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_1(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_1(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_2(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_2(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_3(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_3(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_4(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_4(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_5(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_5(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_6(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_6(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_7(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_7(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_8(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_8(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_9(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_9(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_10(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_10(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_11(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_11(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_12(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_12(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_13(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_13(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_14(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_14(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_15(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_15(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_16(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_16(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_17(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_17(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_18(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_18(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_19(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_19(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_20(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_20(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_21(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_21(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_22(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_22(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_23(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_23(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_24(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_24(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_25(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_25(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_26(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_26(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_27(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_27(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_28(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_28(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_29(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_29(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_30(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_30(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_31(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_31(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_32(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_32(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_33(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_33(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_34(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_34(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_35(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_35(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_36(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_36(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_37(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_37(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_38(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_38(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_39(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_39(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_40(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_40(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_41(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_41(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_42(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_42(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_43(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_43(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_44(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_44(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_45(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_45(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_46(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_46(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_47(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_47(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_48(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_48(XReal_matmul *InstancePtr);
void XReal_matmul_Set_MatB_DRAM_49(XReal_matmul *InstancePtr, u64 Data);
u64 XReal_matmul_Get_MatB_DRAM_49(XReal_matmul *InstancePtr);

void XReal_matmul_InterruptGlobalEnable(XReal_matmul *InstancePtr);
void XReal_matmul_InterruptGlobalDisable(XReal_matmul *InstancePtr);
void XReal_matmul_InterruptEnable(XReal_matmul *InstancePtr, u64 Mask);
void XReal_matmul_InterruptDisable(XReal_matmul *InstancePtr, u64 Mask);
void XReal_matmul_InterruptClear(XReal_matmul *InstancePtr, u64 Mask);
u64 XReal_matmul_InterruptGetEnabled(XReal_matmul *InstancePtr);
u64 XReal_matmul_InterruptGetStatus(XReal_matmul *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
