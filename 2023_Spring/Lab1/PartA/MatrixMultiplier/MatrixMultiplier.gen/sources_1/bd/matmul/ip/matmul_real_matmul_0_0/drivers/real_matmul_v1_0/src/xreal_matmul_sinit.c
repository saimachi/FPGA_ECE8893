// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xreal_matmul.h"

extern XReal_matmul_Config XReal_matmul_ConfigTable[];

XReal_matmul_Config *XReal_matmul_LookupConfig(u16 DeviceId) {
	XReal_matmul_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XREAL_MATMUL_NUM_INSTANCES; Index++) {
		if (XReal_matmul_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XReal_matmul_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XReal_matmul_Initialize(XReal_matmul *InstancePtr, u16 DeviceId) {
	XReal_matmul_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XReal_matmul_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XReal_matmul_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

