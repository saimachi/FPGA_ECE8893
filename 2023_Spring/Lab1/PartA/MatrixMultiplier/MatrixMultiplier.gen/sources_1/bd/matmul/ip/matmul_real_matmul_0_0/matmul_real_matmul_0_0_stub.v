// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
// Date        : Sat Feb 10 12:55:31 2024
// Host        : LAPTOP-QFCR4R7C running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Personal/FPGA/FPGA_ECE8893/2023_Spring/Lab1/PartA/MatrixMultiplier/MatrixMultiplier.gen/sources_1/bd/matmul/ip/matmul_real_matmul_0_0/matmul_real_matmul_0_0_stub.v
// Design      : matmul_real_matmul_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "real_matmul,Vivado 2023.1" *)
module matmul_real_matmul_0_0(s_axi_control_AWADDR, 
  s_axi_control_AWVALID, s_axi_control_AWREADY, s_axi_control_WDATA, s_axi_control_WSTRB, 
  s_axi_control_WVALID, s_axi_control_WREADY, s_axi_control_BRESP, s_axi_control_BVALID, 
  s_axi_control_BREADY, s_axi_control_ARADDR, s_axi_control_ARVALID, 
  s_axi_control_ARREADY, s_axi_control_RDATA, s_axi_control_RRESP, s_axi_control_RVALID, 
  s_axi_control_RREADY, ap_clk, ap_rst_n, interrupt, m_axi_MatA_AWID, m_axi_MatA_AWADDR, 
  m_axi_MatA_AWLEN, m_axi_MatA_AWSIZE, m_axi_MatA_AWBURST, m_axi_MatA_AWLOCK, 
  m_axi_MatA_AWREGION, m_axi_MatA_AWCACHE, m_axi_MatA_AWPROT, m_axi_MatA_AWQOS, 
  m_axi_MatA_AWVALID, m_axi_MatA_AWREADY, m_axi_MatA_WID, m_axi_MatA_WDATA, 
  m_axi_MatA_WSTRB, m_axi_MatA_WLAST, m_axi_MatA_WVALID, m_axi_MatA_WREADY, m_axi_MatA_BID, 
  m_axi_MatA_BRESP, m_axi_MatA_BVALID, m_axi_MatA_BREADY, m_axi_MatA_ARID, 
  m_axi_MatA_ARADDR, m_axi_MatA_ARLEN, m_axi_MatA_ARSIZE, m_axi_MatA_ARBURST, 
  m_axi_MatA_ARLOCK, m_axi_MatA_ARREGION, m_axi_MatA_ARCACHE, m_axi_MatA_ARPROT, 
  m_axi_MatA_ARQOS, m_axi_MatA_ARVALID, m_axi_MatA_ARREADY, m_axi_MatA_RID, 
  m_axi_MatA_RDATA, m_axi_MatA_RRESP, m_axi_MatA_RLAST, m_axi_MatA_RVALID, 
  m_axi_MatA_RREADY, m_axi_MatB_AWID, m_axi_MatB_AWADDR, m_axi_MatB_AWLEN, 
  m_axi_MatB_AWSIZE, m_axi_MatB_AWBURST, m_axi_MatB_AWLOCK, m_axi_MatB_AWREGION, 
  m_axi_MatB_AWCACHE, m_axi_MatB_AWPROT, m_axi_MatB_AWQOS, m_axi_MatB_AWVALID, 
  m_axi_MatB_AWREADY, m_axi_MatB_WID, m_axi_MatB_WDATA, m_axi_MatB_WSTRB, m_axi_MatB_WLAST, 
  m_axi_MatB_WVALID, m_axi_MatB_WREADY, m_axi_MatB_BID, m_axi_MatB_BRESP, 
  m_axi_MatB_BVALID, m_axi_MatB_BREADY, m_axi_MatB_ARID, m_axi_MatB_ARADDR, 
  m_axi_MatB_ARLEN, m_axi_MatB_ARSIZE, m_axi_MatB_ARBURST, m_axi_MatB_ARLOCK, 
  m_axi_MatB_ARREGION, m_axi_MatB_ARCACHE, m_axi_MatB_ARPROT, m_axi_MatB_ARQOS, 
  m_axi_MatB_ARVALID, m_axi_MatB_ARREADY, m_axi_MatB_RID, m_axi_MatB_RDATA, 
  m_axi_MatB_RRESP, m_axi_MatB_RLAST, m_axi_MatB_RVALID, m_axi_MatB_RREADY, 
  m_axi_MatC_AWID, m_axi_MatC_AWADDR, m_axi_MatC_AWLEN, m_axi_MatC_AWSIZE, 
  m_axi_MatC_AWBURST, m_axi_MatC_AWLOCK, m_axi_MatC_AWREGION, m_axi_MatC_AWCACHE, 
  m_axi_MatC_AWPROT, m_axi_MatC_AWQOS, m_axi_MatC_AWVALID, m_axi_MatC_AWREADY, 
  m_axi_MatC_WID, m_axi_MatC_WDATA, m_axi_MatC_WSTRB, m_axi_MatC_WLAST, m_axi_MatC_WVALID, 
  m_axi_MatC_WREADY, m_axi_MatC_BID, m_axi_MatC_BRESP, m_axi_MatC_BVALID, 
  m_axi_MatC_BREADY, m_axi_MatC_ARID, m_axi_MatC_ARADDR, m_axi_MatC_ARLEN, 
  m_axi_MatC_ARSIZE, m_axi_MatC_ARBURST, m_axi_MatC_ARLOCK, m_axi_MatC_ARREGION, 
  m_axi_MatC_ARCACHE, m_axi_MatC_ARPROT, m_axi_MatC_ARQOS, m_axi_MatC_ARVALID, 
  m_axi_MatC_ARREADY, m_axi_MatC_RID, m_axi_MatC_RDATA, m_axi_MatC_RRESP, m_axi_MatC_RLAST, 
  m_axi_MatC_RVALID, m_axi_MatC_RREADY)
/* synthesis syn_black_box black_box_pad_pin="s_axi_control_AWADDR[6:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[63:0],s_axi_control_WSTRB[7:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[6:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[63:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_rst_n,interrupt,m_axi_MatA_AWID[0:0],m_axi_MatA_AWADDR[63:0],m_axi_MatA_AWLEN[7:0],m_axi_MatA_AWSIZE[2:0],m_axi_MatA_AWBURST[1:0],m_axi_MatA_AWLOCK[1:0],m_axi_MatA_AWREGION[3:0],m_axi_MatA_AWCACHE[3:0],m_axi_MatA_AWPROT[2:0],m_axi_MatA_AWQOS[3:0],m_axi_MatA_AWVALID,m_axi_MatA_AWREADY,m_axi_MatA_WID[0:0],m_axi_MatA_WDATA[31:0],m_axi_MatA_WSTRB[3:0],m_axi_MatA_WLAST,m_axi_MatA_WVALID,m_axi_MatA_WREADY,m_axi_MatA_BID[0:0],m_axi_MatA_BRESP[1:0],m_axi_MatA_BVALID,m_axi_MatA_BREADY,m_axi_MatA_ARID[0:0],m_axi_MatA_ARADDR[63:0],m_axi_MatA_ARLEN[7:0],m_axi_MatA_ARSIZE[2:0],m_axi_MatA_ARBURST[1:0],m_axi_MatA_ARLOCK[1:0],m_axi_MatA_ARREGION[3:0],m_axi_MatA_ARCACHE[3:0],m_axi_MatA_ARPROT[2:0],m_axi_MatA_ARQOS[3:0],m_axi_MatA_ARVALID,m_axi_MatA_ARREADY,m_axi_MatA_RID[0:0],m_axi_MatA_RDATA[31:0],m_axi_MatA_RRESP[1:0],m_axi_MatA_RLAST,m_axi_MatA_RVALID,m_axi_MatA_RREADY,m_axi_MatB_AWID[0:0],m_axi_MatB_AWADDR[63:0],m_axi_MatB_AWLEN[7:0],m_axi_MatB_AWSIZE[2:0],m_axi_MatB_AWBURST[1:0],m_axi_MatB_AWLOCK[1:0],m_axi_MatB_AWREGION[3:0],m_axi_MatB_AWCACHE[3:0],m_axi_MatB_AWPROT[2:0],m_axi_MatB_AWQOS[3:0],m_axi_MatB_AWVALID,m_axi_MatB_AWREADY,m_axi_MatB_WID[0:0],m_axi_MatB_WDATA[31:0],m_axi_MatB_WSTRB[3:0],m_axi_MatB_WLAST,m_axi_MatB_WVALID,m_axi_MatB_WREADY,m_axi_MatB_BID[0:0],m_axi_MatB_BRESP[1:0],m_axi_MatB_BVALID,m_axi_MatB_BREADY,m_axi_MatB_ARID[0:0],m_axi_MatB_ARADDR[63:0],m_axi_MatB_ARLEN[7:0],m_axi_MatB_ARSIZE[2:0],m_axi_MatB_ARBURST[1:0],m_axi_MatB_ARLOCK[1:0],m_axi_MatB_ARREGION[3:0],m_axi_MatB_ARCACHE[3:0],m_axi_MatB_ARPROT[2:0],m_axi_MatB_ARQOS[3:0],m_axi_MatB_ARVALID,m_axi_MatB_ARREADY,m_axi_MatB_RID[0:0],m_axi_MatB_RDATA[31:0],m_axi_MatB_RRESP[1:0],m_axi_MatB_RLAST,m_axi_MatB_RVALID,m_axi_MatB_RREADY,m_axi_MatC_AWID[0:0],m_axi_MatC_AWADDR[63:0],m_axi_MatC_AWLEN[7:0],m_axi_MatC_AWSIZE[2:0],m_axi_MatC_AWBURST[1:0],m_axi_MatC_AWLOCK[1:0],m_axi_MatC_AWREGION[3:0],m_axi_MatC_AWCACHE[3:0],m_axi_MatC_AWPROT[2:0],m_axi_MatC_AWQOS[3:0],m_axi_MatC_AWVALID,m_axi_MatC_AWREADY,m_axi_MatC_WID[0:0],m_axi_MatC_WDATA[31:0],m_axi_MatC_WSTRB[3:0],m_axi_MatC_WLAST,m_axi_MatC_WVALID,m_axi_MatC_WREADY,m_axi_MatC_BID[0:0],m_axi_MatC_BRESP[1:0],m_axi_MatC_BVALID,m_axi_MatC_BREADY,m_axi_MatC_ARID[0:0],m_axi_MatC_ARADDR[63:0],m_axi_MatC_ARLEN[7:0],m_axi_MatC_ARSIZE[2:0],m_axi_MatC_ARBURST[1:0],m_axi_MatC_ARLOCK[1:0],m_axi_MatC_ARREGION[3:0],m_axi_MatC_ARCACHE[3:0],m_axi_MatC_ARPROT[2:0],m_axi_MatC_ARQOS[3:0],m_axi_MatC_ARVALID,m_axi_MatC_ARREADY,m_axi_MatC_RID[0:0],m_axi_MatC_RDATA[31:0],m_axi_MatC_RRESP[1:0],m_axi_MatC_RLAST,m_axi_MatC_RVALID,m_axi_MatC_RREADY" */
/* synthesis syn_force_seq_prim="ap_clk" */;
  input [6:0]s_axi_control_AWADDR;
  input s_axi_control_AWVALID;
  output s_axi_control_AWREADY;
  input [63:0]s_axi_control_WDATA;
  input [7:0]s_axi_control_WSTRB;
  input s_axi_control_WVALID;
  output s_axi_control_WREADY;
  output [1:0]s_axi_control_BRESP;
  output s_axi_control_BVALID;
  input s_axi_control_BREADY;
  input [6:0]s_axi_control_ARADDR;
  input s_axi_control_ARVALID;
  output s_axi_control_ARREADY;
  output [63:0]s_axi_control_RDATA;
  output [1:0]s_axi_control_RRESP;
  output s_axi_control_RVALID;
  input s_axi_control_RREADY;
  input ap_clk /* synthesis syn_isclock = 1 */;
  input ap_rst_n;
  output interrupt;
  output [0:0]m_axi_MatA_AWID;
  output [63:0]m_axi_MatA_AWADDR;
  output [7:0]m_axi_MatA_AWLEN;
  output [2:0]m_axi_MatA_AWSIZE;
  output [1:0]m_axi_MatA_AWBURST;
  output [1:0]m_axi_MatA_AWLOCK;
  output [3:0]m_axi_MatA_AWREGION;
  output [3:0]m_axi_MatA_AWCACHE;
  output [2:0]m_axi_MatA_AWPROT;
  output [3:0]m_axi_MatA_AWQOS;
  output m_axi_MatA_AWVALID;
  input m_axi_MatA_AWREADY;
  output [0:0]m_axi_MatA_WID;
  output [31:0]m_axi_MatA_WDATA;
  output [3:0]m_axi_MatA_WSTRB;
  output m_axi_MatA_WLAST;
  output m_axi_MatA_WVALID;
  input m_axi_MatA_WREADY;
  input [0:0]m_axi_MatA_BID;
  input [1:0]m_axi_MatA_BRESP;
  input m_axi_MatA_BVALID;
  output m_axi_MatA_BREADY;
  output [0:0]m_axi_MatA_ARID;
  output [63:0]m_axi_MatA_ARADDR;
  output [7:0]m_axi_MatA_ARLEN;
  output [2:0]m_axi_MatA_ARSIZE;
  output [1:0]m_axi_MatA_ARBURST;
  output [1:0]m_axi_MatA_ARLOCK;
  output [3:0]m_axi_MatA_ARREGION;
  output [3:0]m_axi_MatA_ARCACHE;
  output [2:0]m_axi_MatA_ARPROT;
  output [3:0]m_axi_MatA_ARQOS;
  output m_axi_MatA_ARVALID;
  input m_axi_MatA_ARREADY;
  input [0:0]m_axi_MatA_RID;
  input [31:0]m_axi_MatA_RDATA;
  input [1:0]m_axi_MatA_RRESP;
  input m_axi_MatA_RLAST;
  input m_axi_MatA_RVALID;
  output m_axi_MatA_RREADY;
  output [0:0]m_axi_MatB_AWID;
  output [63:0]m_axi_MatB_AWADDR;
  output [7:0]m_axi_MatB_AWLEN;
  output [2:0]m_axi_MatB_AWSIZE;
  output [1:0]m_axi_MatB_AWBURST;
  output [1:0]m_axi_MatB_AWLOCK;
  output [3:0]m_axi_MatB_AWREGION;
  output [3:0]m_axi_MatB_AWCACHE;
  output [2:0]m_axi_MatB_AWPROT;
  output [3:0]m_axi_MatB_AWQOS;
  output m_axi_MatB_AWVALID;
  input m_axi_MatB_AWREADY;
  output [0:0]m_axi_MatB_WID;
  output [31:0]m_axi_MatB_WDATA;
  output [3:0]m_axi_MatB_WSTRB;
  output m_axi_MatB_WLAST;
  output m_axi_MatB_WVALID;
  input m_axi_MatB_WREADY;
  input [0:0]m_axi_MatB_BID;
  input [1:0]m_axi_MatB_BRESP;
  input m_axi_MatB_BVALID;
  output m_axi_MatB_BREADY;
  output [0:0]m_axi_MatB_ARID;
  output [63:0]m_axi_MatB_ARADDR;
  output [7:0]m_axi_MatB_ARLEN;
  output [2:0]m_axi_MatB_ARSIZE;
  output [1:0]m_axi_MatB_ARBURST;
  output [1:0]m_axi_MatB_ARLOCK;
  output [3:0]m_axi_MatB_ARREGION;
  output [3:0]m_axi_MatB_ARCACHE;
  output [2:0]m_axi_MatB_ARPROT;
  output [3:0]m_axi_MatB_ARQOS;
  output m_axi_MatB_ARVALID;
  input m_axi_MatB_ARREADY;
  input [0:0]m_axi_MatB_RID;
  input [31:0]m_axi_MatB_RDATA;
  input [1:0]m_axi_MatB_RRESP;
  input m_axi_MatB_RLAST;
  input m_axi_MatB_RVALID;
  output m_axi_MatB_RREADY;
  output [0:0]m_axi_MatC_AWID;
  output [63:0]m_axi_MatC_AWADDR;
  output [7:0]m_axi_MatC_AWLEN;
  output [2:0]m_axi_MatC_AWSIZE;
  output [1:0]m_axi_MatC_AWBURST;
  output [1:0]m_axi_MatC_AWLOCK;
  output [3:0]m_axi_MatC_AWREGION;
  output [3:0]m_axi_MatC_AWCACHE;
  output [2:0]m_axi_MatC_AWPROT;
  output [3:0]m_axi_MatC_AWQOS;
  output m_axi_MatC_AWVALID;
  input m_axi_MatC_AWREADY;
  output [0:0]m_axi_MatC_WID;
  output [31:0]m_axi_MatC_WDATA;
  output [3:0]m_axi_MatC_WSTRB;
  output m_axi_MatC_WLAST;
  output m_axi_MatC_WVALID;
  input m_axi_MatC_WREADY;
  input [0:0]m_axi_MatC_BID;
  input [1:0]m_axi_MatC_BRESP;
  input m_axi_MatC_BVALID;
  output m_axi_MatC_BREADY;
  output [0:0]m_axi_MatC_ARID;
  output [63:0]m_axi_MatC_ARADDR;
  output [7:0]m_axi_MatC_ARLEN;
  output [2:0]m_axi_MatC_ARSIZE;
  output [1:0]m_axi_MatC_ARBURST;
  output [1:0]m_axi_MatC_ARLOCK;
  output [3:0]m_axi_MatC_ARREGION;
  output [3:0]m_axi_MatC_ARCACHE;
  output [2:0]m_axi_MatC_ARPROT;
  output [3:0]m_axi_MatC_ARQOS;
  output m_axi_MatC_ARVALID;
  input m_axi_MatC_ARREADY;
  input [0:0]m_axi_MatC_RID;
  input [31:0]m_axi_MatC_RDATA;
  input [1:0]m_axi_MatC_RRESP;
  input m_axi_MatC_RLAST;
  input m_axi_MatC_RVALID;
  output m_axi_MatC_RREADY;
endmodule
