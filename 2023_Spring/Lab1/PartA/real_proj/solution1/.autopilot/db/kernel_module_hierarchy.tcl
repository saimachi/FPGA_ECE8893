set ModuleHierarchy {[{
"Name" : "real_matmul","ID" : "0","Type" : "sequential",
"SubLoops" : [
	{"Name" : "CallBlockMatmul","ID" : "1","Type" : "no",
	"SubInsts" : [
	{"Name" : "grp_real_matmul_Pipeline_LoadMatAFromDRAMtoBRAM_VITIS_LOOP_49_1_fu_179","ID" : "2","Type" : "sequential",
			"SubLoops" : [
			{"Name" : "LoadMatAFromDRAMtoBRAM_VITIS_LOOP_49_1","ID" : "3","Type" : "pipeline"},]},
	{"Name" : "grp_real_matmul_Pipeline_LoadMatBFromDRAMtoBRAM_VITIS_LOOP_56_2_fu_190","ID" : "4","Type" : "sequential",
			"SubLoops" : [
			{"Name" : "LoadMatBFromDRAMtoBRAM_VITIS_LOOP_56_2","ID" : "5","Type" : "pipeline"},]},
	{"Name" : "grp_PerformMatrixCalculation_fu_202","ID" : "6","Type" : "sequential",
			"SubInsts" : [
			{"Name" : "grp_PerformMatrixCalculation_Pipeline_PerformBlockMatrixCalculation_VITIS_LOOP_66_1_fu_11192","ID" : "7","Type" : "sequential",
				"SubLoops" : [
				{"Name" : "PerformBlockMatrixCalculation_VITIS_LOOP_66_1","ID" : "8","Type" : "pipeline"},]},]},
	{"Name" : "grp_real_matmul_Pipeline_VITIS_LOOP_78_1_fu_215","ID" : "9","Type" : "sequential",
			"SubLoops" : [
			{"Name" : "LoadArraysFromBRAMtoDRAM_VITIS_LOOP_78_1","ID" : "10","Type" : "pipeline"},]},]},]
}]}