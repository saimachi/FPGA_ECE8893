// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xreal_matmul.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XReal_matmul_CfgInitialize(XReal_matmul *InstancePtr, XReal_matmul_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->Control_r_BaseAddress = ConfigPtr->Control_r_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XReal_matmul_Start(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u64 XReal_matmul_IsDone(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u64 XReal_matmul_IsIdle(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u64 XReal_matmul_IsReady(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XReal_matmul_EnableAutoRestart(XReal_matmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XReal_matmul_DisableAutoRestart(XReal_matmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_AP_CTRL, 0);
}

void XReal_matmul_Set_MatA_DRAM(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_MATA_DRAM_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_MATA_DRAM_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_MATB_DRAM_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_MATB_DRAM_DATA);
    return Data;
}

void XReal_matmul_Set_MatC_DRAM(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATC_DRAM_DATA, Data);
}

u64 XReal_matmul_Get_MatC_DRAM(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATC_DRAM_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_0(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_0_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_0(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_0_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_1(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_1_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_1(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_1_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_2(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_2_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_2(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_2_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_3(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_3_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_3(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_3_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_4(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_4_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_4(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_4_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_5(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_5_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_5(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_5_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_6(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_6_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_6(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_6_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_7(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_7_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_7(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_7_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_8(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_8_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_8(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_8_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_9(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_9_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_9(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_9_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_10(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_10_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_10(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_10_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_11(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_11_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_11(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_11_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_12(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_12_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_12(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_12_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_13(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_13_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_13(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_13_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_14(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_14_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_14(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_14_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_15(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_15_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_15(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_15_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_16(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_16_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_16(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_16_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_17(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_17_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_17(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_17_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_18(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_18_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_18(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_18_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_19(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_19_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_19(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_19_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_20(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_20_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_20(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_20_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_21(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_21_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_21(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_21_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_22(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_22_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_22(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_22_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_23(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_23_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_23(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_23_DATA);
    return Data;
}

void XReal_matmul_Set_MatA_DRAM_24(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_24_DATA, Data);
}

u64 XReal_matmul_Get_MatA_DRAM_24(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATA_DRAM_24_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_0(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_0_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_0(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_0_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_1(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_1_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_1(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_1_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_2(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_2_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_2(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_2_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_3(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_3_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_3(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_3_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_4(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_4_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_4(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_4_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_5(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_5_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_5(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_5_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_6(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_6_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_6(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_6_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_7(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_7_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_7(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_7_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_8(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_8_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_8(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_8_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_9(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_9_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_9(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_9_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_10(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_10_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_10(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_10_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_11(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_11_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_11(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_11_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_12(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_12_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_12(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_12_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_13(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_13_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_13(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_13_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_14(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_14_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_14(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_14_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_15(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_15_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_15(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_15_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_16(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_16_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_16(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_16_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_17(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_17_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_17(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_17_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_18(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_18_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_18(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_18_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_19(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_19_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_19(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_19_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_20(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_20_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_20(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_20_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_21(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_21_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_21(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_21_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_22(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_22_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_22(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_22_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_23(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_23_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_23(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_23_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_24(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_24_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_24(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_24_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_25(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_25_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_25(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_25_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_26(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_26_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_26(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_26_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_27(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_27_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_27(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_27_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_28(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_28_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_28(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_28_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_29(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_29_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_29(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_29_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_30(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_30_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_30(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_30_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_31(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_31_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_31(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_31_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_32(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_32_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_32(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_32_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_33(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_33_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_33(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_33_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_34(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_34_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_34(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_34_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_35(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_35_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_35(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_35_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_36(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_36_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_36(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_36_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_37(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_37_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_37(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_37_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_38(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_38_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_38(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_38_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_39(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_39_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_39(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_39_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_40(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_40_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_40(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_40_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_41(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_41_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_41(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_41_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_42(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_42_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_42(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_42_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_43(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_43_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_43(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_43_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_44(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_44_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_44(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_44_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_45(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_45_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_45(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_45_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_46(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_46_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_46(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_46_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_47(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_47_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_47(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_47_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_48(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_48_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_48(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_48_DATA);
    return Data;
}

void XReal_matmul_Set_MatB_DRAM_49(XReal_matmul *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_49_DATA, Data);
}

u64 XReal_matmul_Get_MatB_DRAM_49(XReal_matmul *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XReal_matmul_ReadReg(InstancePtr->Control_r_BaseAddress, XREAL_MATMUL_CONTROL_R_ADDR_MATB_DRAM_49_DATA);
    return Data;
}

void XReal_matmul_InterruptGlobalEnable(XReal_matmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_GIE, 1);
}

void XReal_matmul_InterruptGlobalDisable(XReal_matmul *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_GIE, 0);
}

void XReal_matmul_InterruptEnable(XReal_matmul *InstancePtr, u64 Mask) {
    u64 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_IER);
    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_IER, Register | Mask);
}

void XReal_matmul_InterruptDisable(XReal_matmul *InstancePtr, u64 Mask) {
    u64 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_IER);
    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_IER, Register & (~Mask));
}

void XReal_matmul_InterruptClear(XReal_matmul *InstancePtr, u64 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XReal_matmul_WriteReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_ISR, Mask);
}

u64 XReal_matmul_InterruptGetEnabled(XReal_matmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_IER);
}

u64 XReal_matmul_InterruptGetStatus(XReal_matmul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XReal_matmul_ReadReg(InstancePtr->Control_BaseAddress, XREAL_MATMUL_CONTROL_ADDR_ISR);
}

