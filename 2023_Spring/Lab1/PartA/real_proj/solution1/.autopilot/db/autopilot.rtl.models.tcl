set SynModuleInfo {
  {SRCNAME real_matmul_Pipeline_VITIS_LOOP_45_1_VITIS_LOOP_46_2 MODELNAME real_matmul_Pipeline_VITIS_LOOP_45_1_VITIS_LOOP_46_2 RTLNAME real_matmul_real_matmul_Pipeline_VITIS_LOOP_45_1_VITIS_LOOP_46_2
    SUBMODULES {
      {MODELNAME real_matmul_mul_2ns_9ns_10_1_1 RTLNAME real_matmul_mul_2ns_9ns_10_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_mul_8ns_10ns_17_1_1 RTLNAME real_matmul_mul_8ns_10ns_17_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_flow_control_loop_pipe_sequential_init RTLNAME real_matmul_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME real_matmul_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME real_matmul_Pipeline_VITIS_LOOP_56_5 MODELNAME real_matmul_Pipeline_VITIS_LOOP_56_5 RTLNAME real_matmul_real_matmul_Pipeline_VITIS_LOOP_56_5
    SUBMODULES {
      {MODELNAME real_matmul_mac_muladd_16s_16s_16ns_16_4_1 RTLNAME real_matmul_mac_muladd_16s_16s_16ns_16_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME real_matmul_Pipeline_VITIS_LOOP_63_6 MODELNAME real_matmul_Pipeline_VITIS_LOOP_63_6 RTLNAME real_matmul_real_matmul_Pipeline_VITIS_LOOP_63_6
    SUBMODULES {
      {MODELNAME real_matmul_mul_7ns_10ns_16_1_1 RTLNAME real_matmul_mul_7ns_10ns_16_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME real_matmul MODELNAME real_matmul RTLNAME real_matmul IS_TOP 1
    SUBMODULES {
      {MODELNAME real_matmul_mul_2ns_9ns_9_1_1 RTLNAME real_matmul_mul_2ns_9ns_9_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_mac_muladd_6ns_9s_14ns_15_4_1 RTLNAME real_matmul_mac_muladd_6ns_9s_14ns_15_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_MatA_BRAM_RAM_AUTO_1R1W RTLNAME real_matmul_MatA_BRAM_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_mem_m_axi RTLNAME real_matmul_mem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME real_matmul_control_s_axi RTLNAME real_matmul_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
