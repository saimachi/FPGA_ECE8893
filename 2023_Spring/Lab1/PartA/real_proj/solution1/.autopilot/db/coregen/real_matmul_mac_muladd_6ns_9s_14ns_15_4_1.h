// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __real_matmul_mac_muladd_6ns_9s_14ns_15_4_1__HH__
#define __real_matmul_mac_muladd_6ns_9s_14ns_15_4_1__HH__
#include "real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1.h"

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int din2_WIDTH,
    int dout_WIDTH>
SC_MODULE(real_matmul_mac_muladd_6ns_9s_14ns_15_4_1) {
    sc_core::sc_in_clk clk;
    sc_core::sc_in<sc_dt::sc_logic> reset;
    sc_core::sc_in<sc_dt::sc_logic> ce;
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_in< sc_dt::sc_lv<din2_WIDTH> >   din2;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1 real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U;

    SC_CTOR(real_matmul_mac_muladd_6ns_9s_14ns_15_4_1):  real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U ("real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U") {
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.clk(clk);
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.rst(reset);
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.ce(ce);
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.in0(din0);
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.in1(din1);
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.in2(din2);
        real_matmul_mac_muladd_6ns_9s_14ns_15_4_1_DSP48_1_U.dout(dout);

    }

};

#endif //
