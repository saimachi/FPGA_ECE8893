set SynModuleInfo {
  {SRCNAME real_matmul_Pipeline_LoadMatAFromDRAMtoBRAM_VITIS_LOOP_49_1 MODELNAME real_matmul_Pipeline_LoadMatAFromDRAMtoBRAM_VITIS_LOOP_49_1 RTLNAME real_matmul_real_matmul_Pipeline_LoadMatAFromDRAMtoBRAM_VITIS_LOOP_49_1
    SUBMODULES {
      {MODELNAME real_matmul_flow_control_loop_pipe_sequential_init RTLNAME real_matmul_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME real_matmul_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME real_matmul_Pipeline_LoadMatBFromDRAMtoBRAM_VITIS_LOOP_56_2 MODELNAME real_matmul_Pipeline_LoadMatBFromDRAMtoBRAM_VITIS_LOOP_56_2 RTLNAME real_matmul_real_matmul_Pipeline_LoadMatBFromDRAMtoBRAM_VITIS_LOOP_56_2
    SUBMODULES {
      {MODELNAME real_matmul_mul_8ns_10ns_17_1_1 RTLNAME real_matmul_mul_8ns_10ns_17_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME PerformMatrixCalculation_Pipeline_PerformBlockMatrixCalculation_VITIS_LOOP_66_1 MODELNAME PerformMatrixCalculation_Pipeline_PerformBlockMatrixCalculation_VITIS_LOOP_66_1 RTLNAME real_matmul_PerformMatrixCalculation_Pipeline_PerformBlockMatrixCalculation_VITIS_LOOP_66_1
    SUBMODULES {
      {MODELNAME real_matmul_mux_4_2_16_1_1 RTLNAME real_matmul_mux_4_2_16_1_1 BINDTYPE op TYPE mux IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_mul_16s_16s_16_1_1 RTLNAME real_matmul_mul_16s_16s_16_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_mac_muladd_16s_16s_16ns_16_4_1 RTLNAME real_matmul_mac_muladd_16s_16s_16ns_16_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME PerformMatrixCalculation MODELNAME PerformMatrixCalculation RTLNAME real_matmul_PerformMatrixCalculation}
  {SRCNAME real_matmul_Pipeline_VITIS_LOOP_78_1 MODELNAME real_matmul_Pipeline_VITIS_LOOP_78_1 RTLNAME real_matmul_real_matmul_Pipeline_VITIS_LOOP_78_1
    SUBMODULES {
      {MODELNAME real_matmul_mul_7ns_10ns_16_1_1 RTLNAME real_matmul_mul_7ns_10ns_16_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME real_matmul MODELNAME real_matmul RTLNAME real_matmul IS_TOP 1
    SUBMODULES {
      {MODELNAME real_matmul_mac_muladd_5ns_9s_13ns_14_4_1 RTLNAME real_matmul_mac_muladd_5ns_9s_13ns_14_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_MatA_BRAM_RAM_AUTO_1R1W RTLNAME real_matmul_MatA_BRAM_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_MatC_BRAM_RAM_AUTO_1R1W RTLNAME real_matmul_MatC_BRAM_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME real_matmul_mem_m_axi RTLNAME real_matmul_mem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME real_matmul_control_s_axi RTLNAME real_matmul_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
