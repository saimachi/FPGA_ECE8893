set ModuleHierarchy {[{
"Name" : "real_matmul","ID" : "0","Type" : "sequential",
"SubLoops" : [
	{"Name" : "VITIS_LOOP_27_1","ID" : "1","Type" : "no",
	"SubInsts" : [
	{"Name" : "grp_real_matmul_Pipeline_VITIS_LOOP_45_1_VITIS_LOOP_46_2_fu_210","ID" : "2","Type" : "sequential",
			"SubLoops" : [
			{"Name" : "VITIS_LOOP_45_1_VITIS_LOOP_46_2","ID" : "3","Type" : "pipeline"},]},
	{"Name" : "grp_real_matmul_Pipeline_VITIS_LOOP_63_6_fu_230","ID" : "4","Type" : "sequential",
			"SubLoops" : [
			{"Name" : "VITIS_LOOP_63_6","ID" : "5","Type" : "pipeline"},]},],
	"SubLoops" : [
	{"Name" : "VITIS_LOOP_53_3_VITIS_LOOP_54_4","ID" : "6","Type" : "no",
		"SubInsts" : [
		{"Name" : "grp_real_matmul_Pipeline_VITIS_LOOP_56_5_fu_221","ID" : "7","Type" : "sequential",
				"SubLoops" : [
				{"Name" : "VITIS_LOOP_56_5","ID" : "8","Type" : "pipeline"},]},]},]},]
}]}