// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of AMD and is protected under U.S. and international copyright
// and other intellectual property laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// AMD, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) AMD shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or AMD had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// AMD products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of AMD products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:hls:real_matmul:1.0
// IP Revision: 2113421924

`timescale 1ns/1ps

(* IP_DEFINITION_SOURCE = "HLS" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module matmul_real_matmul_0_0 (
  s_axi_control_AWADDR,
  s_axi_control_AWVALID,
  s_axi_control_AWREADY,
  s_axi_control_WDATA,
  s_axi_control_WSTRB,
  s_axi_control_WVALID,
  s_axi_control_WREADY,
  s_axi_control_BRESP,
  s_axi_control_BVALID,
  s_axi_control_BREADY,
  s_axi_control_ARADDR,
  s_axi_control_ARVALID,
  s_axi_control_ARREADY,
  s_axi_control_RDATA,
  s_axi_control_RRESP,
  s_axi_control_RVALID,
  s_axi_control_RREADY,
  ap_clk,
  ap_rst_n,
  interrupt,
  m_axi_MatA_AWID,
  m_axi_MatA_AWADDR,
  m_axi_MatA_AWLEN,
  m_axi_MatA_AWSIZE,
  m_axi_MatA_AWBURST,
  m_axi_MatA_AWLOCK,
  m_axi_MatA_AWREGION,
  m_axi_MatA_AWCACHE,
  m_axi_MatA_AWPROT,
  m_axi_MatA_AWQOS,
  m_axi_MatA_AWVALID,
  m_axi_MatA_AWREADY,
  m_axi_MatA_WID,
  m_axi_MatA_WDATA,
  m_axi_MatA_WSTRB,
  m_axi_MatA_WLAST,
  m_axi_MatA_WVALID,
  m_axi_MatA_WREADY,
  m_axi_MatA_BID,
  m_axi_MatA_BRESP,
  m_axi_MatA_BVALID,
  m_axi_MatA_BREADY,
  m_axi_MatA_ARID,
  m_axi_MatA_ARADDR,
  m_axi_MatA_ARLEN,
  m_axi_MatA_ARSIZE,
  m_axi_MatA_ARBURST,
  m_axi_MatA_ARLOCK,
  m_axi_MatA_ARREGION,
  m_axi_MatA_ARCACHE,
  m_axi_MatA_ARPROT,
  m_axi_MatA_ARQOS,
  m_axi_MatA_ARVALID,
  m_axi_MatA_ARREADY,
  m_axi_MatA_RID,
  m_axi_MatA_RDATA,
  m_axi_MatA_RRESP,
  m_axi_MatA_RLAST,
  m_axi_MatA_RVALID,
  m_axi_MatA_RREADY,
  m_axi_MatB_AWID,
  m_axi_MatB_AWADDR,
  m_axi_MatB_AWLEN,
  m_axi_MatB_AWSIZE,
  m_axi_MatB_AWBURST,
  m_axi_MatB_AWLOCK,
  m_axi_MatB_AWREGION,
  m_axi_MatB_AWCACHE,
  m_axi_MatB_AWPROT,
  m_axi_MatB_AWQOS,
  m_axi_MatB_AWVALID,
  m_axi_MatB_AWREADY,
  m_axi_MatB_WID,
  m_axi_MatB_WDATA,
  m_axi_MatB_WSTRB,
  m_axi_MatB_WLAST,
  m_axi_MatB_WVALID,
  m_axi_MatB_WREADY,
  m_axi_MatB_BID,
  m_axi_MatB_BRESP,
  m_axi_MatB_BVALID,
  m_axi_MatB_BREADY,
  m_axi_MatB_ARID,
  m_axi_MatB_ARADDR,
  m_axi_MatB_ARLEN,
  m_axi_MatB_ARSIZE,
  m_axi_MatB_ARBURST,
  m_axi_MatB_ARLOCK,
  m_axi_MatB_ARREGION,
  m_axi_MatB_ARCACHE,
  m_axi_MatB_ARPROT,
  m_axi_MatB_ARQOS,
  m_axi_MatB_ARVALID,
  m_axi_MatB_ARREADY,
  m_axi_MatB_RID,
  m_axi_MatB_RDATA,
  m_axi_MatB_RRESP,
  m_axi_MatB_RLAST,
  m_axi_MatB_RVALID,
  m_axi_MatB_RREADY,
  m_axi_MatC_AWID,
  m_axi_MatC_AWADDR,
  m_axi_MatC_AWLEN,
  m_axi_MatC_AWSIZE,
  m_axi_MatC_AWBURST,
  m_axi_MatC_AWLOCK,
  m_axi_MatC_AWREGION,
  m_axi_MatC_AWCACHE,
  m_axi_MatC_AWPROT,
  m_axi_MatC_AWQOS,
  m_axi_MatC_AWVALID,
  m_axi_MatC_AWREADY,
  m_axi_MatC_WID,
  m_axi_MatC_WDATA,
  m_axi_MatC_WSTRB,
  m_axi_MatC_WLAST,
  m_axi_MatC_WVALID,
  m_axi_MatC_WREADY,
  m_axi_MatC_BID,
  m_axi_MatC_BRESP,
  m_axi_MatC_BVALID,
  m_axi_MatC_BREADY,
  m_axi_MatC_ARID,
  m_axi_MatC_ARADDR,
  m_axi_MatC_ARLEN,
  m_axi_MatC_ARSIZE,
  m_axi_MatC_ARBURST,
  m_axi_MatC_ARLOCK,
  m_axi_MatC_ARREGION,
  m_axi_MatC_ARCACHE,
  m_axi_MatC_ARPROT,
  m_axi_MatC_ARQOS,
  m_axi_MatC_ARVALID,
  m_axi_MatC_ARREADY,
  m_axi_MatC_RID,
  m_axi_MatC_RDATA,
  m_axi_MatC_RRESP,
  m_axi_MatC_RLAST,
  m_axi_MatC_RVALID,
  m_axi_MatC_RREADY
);

(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control AWADDR" *)
input wire [6 : 0] s_axi_control_AWADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control AWVALID" *)
input wire s_axi_control_AWVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control AWREADY" *)
output wire s_axi_control_AWREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control WDATA" *)
input wire [63 : 0] s_axi_control_WDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control WSTRB" *)
input wire [7 : 0] s_axi_control_WSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control WVALID" *)
input wire s_axi_control_WVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control WREADY" *)
output wire s_axi_control_WREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control BRESP" *)
output wire [1 : 0] s_axi_control_BRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control BVALID" *)
output wire s_axi_control_BVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control BREADY" *)
input wire s_axi_control_BREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control ARADDR" *)
input wire [6 : 0] s_axi_control_ARADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control ARVALID" *)
input wire s_axi_control_ARVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control ARREADY" *)
output wire s_axi_control_ARREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control RDATA" *)
output wire [63 : 0] s_axi_control_RDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control RRESP" *)
output wire [1 : 0] s_axi_control_RRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control RVALID" *)
output wire s_axi_control_RVALID;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME s_axi_control, ADDR_WIDTH 7, DATA_WIDTH 64, PROTOCOL AXI4LITE, READ_WRITE_MODE READ_WRITE, FREQ_HZ 50000000, ID_WIDTH 0, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 0, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.0, CLK_DOMAIN matmul_processing_system7_0_0_FCLK_CLK0, NUM_READ_THRE\
ADS 4, NUM_WRITE_THREADS 4, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_control RREADY" *)
input wire s_axi_control_RREADY;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ap_clk, ASSOCIATED_BUSIF s_axi_control:m_axi_MatA:m_axi_MatB:m_axi_MatC, ASSOCIATED_RESET ap_rst_n, FREQ_HZ 50000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN matmul_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 ap_clk CLK" *)
input wire ap_clk;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ap_rst_n, POLARITY ACTIVE_LOW, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 ap_rst_n RST" *)
input wire ap_rst_n;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME interrupt, SENSITIVITY LEVEL_HIGH, PortWidth 1" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:interrupt:1.0 interrupt INTERRUPT" *)
output wire interrupt;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWID" *)
output wire [0 : 0] m_axi_MatA_AWID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWADDR" *)
output wire [63 : 0] m_axi_MatA_AWADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWLEN" *)
output wire [7 : 0] m_axi_MatA_AWLEN;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWSIZE" *)
output wire [2 : 0] m_axi_MatA_AWSIZE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWBURST" *)
output wire [1 : 0] m_axi_MatA_AWBURST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWLOCK" *)
output wire [1 : 0] m_axi_MatA_AWLOCK;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWREGION" *)
output wire [3 : 0] m_axi_MatA_AWREGION;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWCACHE" *)
output wire [3 : 0] m_axi_MatA_AWCACHE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWPROT" *)
output wire [2 : 0] m_axi_MatA_AWPROT;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWQOS" *)
output wire [3 : 0] m_axi_MatA_AWQOS;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWVALID" *)
output wire m_axi_MatA_AWVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA AWREADY" *)
input wire m_axi_MatA_AWREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA WID" *)
output wire [0 : 0] m_axi_MatA_WID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA WDATA" *)
output wire [31 : 0] m_axi_MatA_WDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA WSTRB" *)
output wire [3 : 0] m_axi_MatA_WSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA WLAST" *)
output wire m_axi_MatA_WLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA WVALID" *)
output wire m_axi_MatA_WVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA WREADY" *)
input wire m_axi_MatA_WREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA BID" *)
input wire [0 : 0] m_axi_MatA_BID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA BRESP" *)
input wire [1 : 0] m_axi_MatA_BRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA BVALID" *)
input wire m_axi_MatA_BVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA BREADY" *)
output wire m_axi_MatA_BREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARID" *)
output wire [0 : 0] m_axi_MatA_ARID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARADDR" *)
output wire [63 : 0] m_axi_MatA_ARADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARLEN" *)
output wire [7 : 0] m_axi_MatA_ARLEN;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARSIZE" *)
output wire [2 : 0] m_axi_MatA_ARSIZE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARBURST" *)
output wire [1 : 0] m_axi_MatA_ARBURST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARLOCK" *)
output wire [1 : 0] m_axi_MatA_ARLOCK;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARREGION" *)
output wire [3 : 0] m_axi_MatA_ARREGION;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARCACHE" *)
output wire [3 : 0] m_axi_MatA_ARCACHE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARPROT" *)
output wire [2 : 0] m_axi_MatA_ARPROT;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARQOS" *)
output wire [3 : 0] m_axi_MatA_ARQOS;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARVALID" *)
output wire m_axi_MatA_ARVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA ARREADY" *)
input wire m_axi_MatA_ARREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA RID" *)
input wire [0 : 0] m_axi_MatA_RID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA RDATA" *)
input wire [31 : 0] m_axi_MatA_RDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA RRESP" *)
input wire [1 : 0] m_axi_MatA_RRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA RLAST" *)
input wire m_axi_MatA_RLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA RVALID" *)
input wire m_axi_MatA_RVALID;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME m_axi_MatA, NUM_READ_OUTSTANDING 16, NUM_WRITE_OUTSTANDING 16, MAX_READ_BURST_LENGTH 16, MAX_WRITE_BURST_LENGTH 16, MAX_BURST_LENGTH 256, PROTOCOL AXI4, READ_WRITE_MODE READ_ONLY, HAS_BURST 0, SUPPORTS_NARROW_BURST 0, DATA_WIDTH 32, FREQ_HZ 50000000, ID_WIDTH 1, ADDR_WIDTH 64, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 1, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, PHASE 0.0, CLK_DOMAIN matm\
ul_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatA RREADY" *)
output wire m_axi_MatA_RREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWID" *)
output wire [0 : 0] m_axi_MatB_AWID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWADDR" *)
output wire [63 : 0] m_axi_MatB_AWADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWLEN" *)
output wire [7 : 0] m_axi_MatB_AWLEN;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWSIZE" *)
output wire [2 : 0] m_axi_MatB_AWSIZE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWBURST" *)
output wire [1 : 0] m_axi_MatB_AWBURST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWLOCK" *)
output wire [1 : 0] m_axi_MatB_AWLOCK;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWREGION" *)
output wire [3 : 0] m_axi_MatB_AWREGION;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWCACHE" *)
output wire [3 : 0] m_axi_MatB_AWCACHE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWPROT" *)
output wire [2 : 0] m_axi_MatB_AWPROT;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWQOS" *)
output wire [3 : 0] m_axi_MatB_AWQOS;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWVALID" *)
output wire m_axi_MatB_AWVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB AWREADY" *)
input wire m_axi_MatB_AWREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB WID" *)
output wire [0 : 0] m_axi_MatB_WID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB WDATA" *)
output wire [31 : 0] m_axi_MatB_WDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB WSTRB" *)
output wire [3 : 0] m_axi_MatB_WSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB WLAST" *)
output wire m_axi_MatB_WLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB WVALID" *)
output wire m_axi_MatB_WVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB WREADY" *)
input wire m_axi_MatB_WREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB BID" *)
input wire [0 : 0] m_axi_MatB_BID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB BRESP" *)
input wire [1 : 0] m_axi_MatB_BRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB BVALID" *)
input wire m_axi_MatB_BVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB BREADY" *)
output wire m_axi_MatB_BREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARID" *)
output wire [0 : 0] m_axi_MatB_ARID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARADDR" *)
output wire [63 : 0] m_axi_MatB_ARADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARLEN" *)
output wire [7 : 0] m_axi_MatB_ARLEN;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARSIZE" *)
output wire [2 : 0] m_axi_MatB_ARSIZE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARBURST" *)
output wire [1 : 0] m_axi_MatB_ARBURST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARLOCK" *)
output wire [1 : 0] m_axi_MatB_ARLOCK;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARREGION" *)
output wire [3 : 0] m_axi_MatB_ARREGION;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARCACHE" *)
output wire [3 : 0] m_axi_MatB_ARCACHE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARPROT" *)
output wire [2 : 0] m_axi_MatB_ARPROT;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARQOS" *)
output wire [3 : 0] m_axi_MatB_ARQOS;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARVALID" *)
output wire m_axi_MatB_ARVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB ARREADY" *)
input wire m_axi_MatB_ARREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB RID" *)
input wire [0 : 0] m_axi_MatB_RID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB RDATA" *)
input wire [31 : 0] m_axi_MatB_RDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB RRESP" *)
input wire [1 : 0] m_axi_MatB_RRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB RLAST" *)
input wire m_axi_MatB_RLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB RVALID" *)
input wire m_axi_MatB_RVALID;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME m_axi_MatB, NUM_READ_OUTSTANDING 16, NUM_WRITE_OUTSTANDING 16, MAX_READ_BURST_LENGTH 16, MAX_WRITE_BURST_LENGTH 16, MAX_BURST_LENGTH 256, PROTOCOL AXI4, READ_WRITE_MODE READ_ONLY, HAS_BURST 0, SUPPORTS_NARROW_BURST 0, DATA_WIDTH 32, FREQ_HZ 50000000, ID_WIDTH 1, ADDR_WIDTH 64, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 1, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, PHASE 0.0, CLK_DOMAIN matm\
ul_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatB RREADY" *)
output wire m_axi_MatB_RREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWID" *)
output wire [0 : 0] m_axi_MatC_AWID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWADDR" *)
output wire [63 : 0] m_axi_MatC_AWADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWLEN" *)
output wire [7 : 0] m_axi_MatC_AWLEN;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWSIZE" *)
output wire [2 : 0] m_axi_MatC_AWSIZE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWBURST" *)
output wire [1 : 0] m_axi_MatC_AWBURST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWLOCK" *)
output wire [1 : 0] m_axi_MatC_AWLOCK;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWREGION" *)
output wire [3 : 0] m_axi_MatC_AWREGION;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWCACHE" *)
output wire [3 : 0] m_axi_MatC_AWCACHE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWPROT" *)
output wire [2 : 0] m_axi_MatC_AWPROT;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWQOS" *)
output wire [3 : 0] m_axi_MatC_AWQOS;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWVALID" *)
output wire m_axi_MatC_AWVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC AWREADY" *)
input wire m_axi_MatC_AWREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC WID" *)
output wire [0 : 0] m_axi_MatC_WID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC WDATA" *)
output wire [31 : 0] m_axi_MatC_WDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC WSTRB" *)
output wire [3 : 0] m_axi_MatC_WSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC WLAST" *)
output wire m_axi_MatC_WLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC WVALID" *)
output wire m_axi_MatC_WVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC WREADY" *)
input wire m_axi_MatC_WREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC BID" *)
input wire [0 : 0] m_axi_MatC_BID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC BRESP" *)
input wire [1 : 0] m_axi_MatC_BRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC BVALID" *)
input wire m_axi_MatC_BVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC BREADY" *)
output wire m_axi_MatC_BREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARID" *)
output wire [0 : 0] m_axi_MatC_ARID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARADDR" *)
output wire [63 : 0] m_axi_MatC_ARADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARLEN" *)
output wire [7 : 0] m_axi_MatC_ARLEN;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARSIZE" *)
output wire [2 : 0] m_axi_MatC_ARSIZE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARBURST" *)
output wire [1 : 0] m_axi_MatC_ARBURST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARLOCK" *)
output wire [1 : 0] m_axi_MatC_ARLOCK;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARREGION" *)
output wire [3 : 0] m_axi_MatC_ARREGION;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARCACHE" *)
output wire [3 : 0] m_axi_MatC_ARCACHE;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARPROT" *)
output wire [2 : 0] m_axi_MatC_ARPROT;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARQOS" *)
output wire [3 : 0] m_axi_MatC_ARQOS;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARVALID" *)
output wire m_axi_MatC_ARVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC ARREADY" *)
input wire m_axi_MatC_ARREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC RID" *)
input wire [0 : 0] m_axi_MatC_RID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC RDATA" *)
input wire [31 : 0] m_axi_MatC_RDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC RRESP" *)
input wire [1 : 0] m_axi_MatC_RRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC RLAST" *)
input wire m_axi_MatC_RLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC RVALID" *)
input wire m_axi_MatC_RVALID;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME m_axi_MatC, NUM_READ_OUTSTANDING 16, NUM_WRITE_OUTSTANDING 16, MAX_READ_BURST_LENGTH 16, MAX_WRITE_BURST_LENGTH 16, MAX_BURST_LENGTH 256, PROTOCOL AXI4, READ_WRITE_MODE WRITE_ONLY, HAS_BURST 0, SUPPORTS_NARROW_BURST 0, DATA_WIDTH 32, FREQ_HZ 50000000, ID_WIDTH 1, ADDR_WIDTH 64, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 1, HAS_REGION 1, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, PHASE 0.0, CLK_DOMAIN mat\
mul_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi_MatC RREADY" *)
output wire m_axi_MatC_RREADY;

(* SDX_KERNEL = "true" *)
(* SDX_KERNEL_TYPE = "hls" *)
(* SDX_KERNEL_SIM_INST = "" *)
  real_matmul #(
    .C_S_AXI_CONTROL_ADDR_WIDTH(7),
    .C_S_AXI_CONTROL_DATA_WIDTH(64),
    .C_M_AXI_MATA_ID_WIDTH(1),
    .C_M_AXI_MATA_ADDR_WIDTH(64),
    .C_M_AXI_MATA_DATA_WIDTH(32),
    .C_M_AXI_MATA_AWUSER_WIDTH(1),
    .C_M_AXI_MATA_ARUSER_WIDTH(1),
    .C_M_AXI_MATA_WUSER_WIDTH(1),
    .C_M_AXI_MATA_RUSER_WIDTH(1),
    .C_M_AXI_MATA_BUSER_WIDTH(1),
    .C_M_AXI_MATA_USER_VALUE(32'H00000000),
    .C_M_AXI_MATA_PROT_VALUE(3'B000),
    .C_M_AXI_MATA_CACHE_VALUE(4'B0011),
    .C_M_AXI_MATB_ID_WIDTH(1),
    .C_M_AXI_MATB_ADDR_WIDTH(64),
    .C_M_AXI_MATB_DATA_WIDTH(32),
    .C_M_AXI_MATB_AWUSER_WIDTH(1),
    .C_M_AXI_MATB_ARUSER_WIDTH(1),
    .C_M_AXI_MATB_WUSER_WIDTH(1),
    .C_M_AXI_MATB_RUSER_WIDTH(1),
    .C_M_AXI_MATB_BUSER_WIDTH(1),
    .C_M_AXI_MATB_USER_VALUE(32'H00000000),
    .C_M_AXI_MATB_PROT_VALUE(3'B000),
    .C_M_AXI_MATB_CACHE_VALUE(4'B0011),
    .C_M_AXI_MATC_ID_WIDTH(1),
    .C_M_AXI_MATC_ADDR_WIDTH(64),
    .C_M_AXI_MATC_DATA_WIDTH(32),
    .C_M_AXI_MATC_AWUSER_WIDTH(1),
    .C_M_AXI_MATC_ARUSER_WIDTH(1),
    .C_M_AXI_MATC_WUSER_WIDTH(1),
    .C_M_AXI_MATC_RUSER_WIDTH(1),
    .C_M_AXI_MATC_BUSER_WIDTH(1),
    .C_M_AXI_MATC_USER_VALUE(32'H00000000),
    .C_M_AXI_MATC_PROT_VALUE(3'B000),
    .C_M_AXI_MATC_CACHE_VALUE(4'B0011)
  ) inst (
    .s_axi_control_AWADDR(s_axi_control_AWADDR),
    .s_axi_control_AWVALID(s_axi_control_AWVALID),
    .s_axi_control_AWREADY(s_axi_control_AWREADY),
    .s_axi_control_WDATA(s_axi_control_WDATA),
    .s_axi_control_WSTRB(s_axi_control_WSTRB),
    .s_axi_control_WVALID(s_axi_control_WVALID),
    .s_axi_control_WREADY(s_axi_control_WREADY),
    .s_axi_control_BRESP(s_axi_control_BRESP),
    .s_axi_control_BVALID(s_axi_control_BVALID),
    .s_axi_control_BREADY(s_axi_control_BREADY),
    .s_axi_control_ARADDR(s_axi_control_ARADDR),
    .s_axi_control_ARVALID(s_axi_control_ARVALID),
    .s_axi_control_ARREADY(s_axi_control_ARREADY),
    .s_axi_control_RDATA(s_axi_control_RDATA),
    .s_axi_control_RRESP(s_axi_control_RRESP),
    .s_axi_control_RVALID(s_axi_control_RVALID),
    .s_axi_control_RREADY(s_axi_control_RREADY),
    .ap_clk(ap_clk),
    .ap_rst_n(ap_rst_n),
    .interrupt(interrupt),
    .m_axi_MatA_AWID(m_axi_MatA_AWID),
    .m_axi_MatA_AWADDR(m_axi_MatA_AWADDR),
    .m_axi_MatA_AWLEN(m_axi_MatA_AWLEN),
    .m_axi_MatA_AWSIZE(m_axi_MatA_AWSIZE),
    .m_axi_MatA_AWBURST(m_axi_MatA_AWBURST),
    .m_axi_MatA_AWLOCK(m_axi_MatA_AWLOCK),
    .m_axi_MatA_AWREGION(m_axi_MatA_AWREGION),
    .m_axi_MatA_AWCACHE(m_axi_MatA_AWCACHE),
    .m_axi_MatA_AWPROT(m_axi_MatA_AWPROT),
    .m_axi_MatA_AWQOS(m_axi_MatA_AWQOS),
    .m_axi_MatA_AWUSER(),
    .m_axi_MatA_AWVALID(m_axi_MatA_AWVALID),
    .m_axi_MatA_AWREADY(m_axi_MatA_AWREADY),
    .m_axi_MatA_WID(m_axi_MatA_WID),
    .m_axi_MatA_WDATA(m_axi_MatA_WDATA),
    .m_axi_MatA_WSTRB(m_axi_MatA_WSTRB),
    .m_axi_MatA_WLAST(m_axi_MatA_WLAST),
    .m_axi_MatA_WUSER(),
    .m_axi_MatA_WVALID(m_axi_MatA_WVALID),
    .m_axi_MatA_WREADY(m_axi_MatA_WREADY),
    .m_axi_MatA_BID(m_axi_MatA_BID),
    .m_axi_MatA_BRESP(m_axi_MatA_BRESP),
    .m_axi_MatA_BUSER(1'B0),
    .m_axi_MatA_BVALID(m_axi_MatA_BVALID),
    .m_axi_MatA_BREADY(m_axi_MatA_BREADY),
    .m_axi_MatA_ARID(m_axi_MatA_ARID),
    .m_axi_MatA_ARADDR(m_axi_MatA_ARADDR),
    .m_axi_MatA_ARLEN(m_axi_MatA_ARLEN),
    .m_axi_MatA_ARSIZE(m_axi_MatA_ARSIZE),
    .m_axi_MatA_ARBURST(m_axi_MatA_ARBURST),
    .m_axi_MatA_ARLOCK(m_axi_MatA_ARLOCK),
    .m_axi_MatA_ARREGION(m_axi_MatA_ARREGION),
    .m_axi_MatA_ARCACHE(m_axi_MatA_ARCACHE),
    .m_axi_MatA_ARPROT(m_axi_MatA_ARPROT),
    .m_axi_MatA_ARQOS(m_axi_MatA_ARQOS),
    .m_axi_MatA_ARUSER(),
    .m_axi_MatA_ARVALID(m_axi_MatA_ARVALID),
    .m_axi_MatA_ARREADY(m_axi_MatA_ARREADY),
    .m_axi_MatA_RID(m_axi_MatA_RID),
    .m_axi_MatA_RDATA(m_axi_MatA_RDATA),
    .m_axi_MatA_RRESP(m_axi_MatA_RRESP),
    .m_axi_MatA_RLAST(m_axi_MatA_RLAST),
    .m_axi_MatA_RUSER(1'B0),
    .m_axi_MatA_RVALID(m_axi_MatA_RVALID),
    .m_axi_MatA_RREADY(m_axi_MatA_RREADY),
    .m_axi_MatB_AWID(m_axi_MatB_AWID),
    .m_axi_MatB_AWADDR(m_axi_MatB_AWADDR),
    .m_axi_MatB_AWLEN(m_axi_MatB_AWLEN),
    .m_axi_MatB_AWSIZE(m_axi_MatB_AWSIZE),
    .m_axi_MatB_AWBURST(m_axi_MatB_AWBURST),
    .m_axi_MatB_AWLOCK(m_axi_MatB_AWLOCK),
    .m_axi_MatB_AWREGION(m_axi_MatB_AWREGION),
    .m_axi_MatB_AWCACHE(m_axi_MatB_AWCACHE),
    .m_axi_MatB_AWPROT(m_axi_MatB_AWPROT),
    .m_axi_MatB_AWQOS(m_axi_MatB_AWQOS),
    .m_axi_MatB_AWUSER(),
    .m_axi_MatB_AWVALID(m_axi_MatB_AWVALID),
    .m_axi_MatB_AWREADY(m_axi_MatB_AWREADY),
    .m_axi_MatB_WID(m_axi_MatB_WID),
    .m_axi_MatB_WDATA(m_axi_MatB_WDATA),
    .m_axi_MatB_WSTRB(m_axi_MatB_WSTRB),
    .m_axi_MatB_WLAST(m_axi_MatB_WLAST),
    .m_axi_MatB_WUSER(),
    .m_axi_MatB_WVALID(m_axi_MatB_WVALID),
    .m_axi_MatB_WREADY(m_axi_MatB_WREADY),
    .m_axi_MatB_BID(m_axi_MatB_BID),
    .m_axi_MatB_BRESP(m_axi_MatB_BRESP),
    .m_axi_MatB_BUSER(1'B0),
    .m_axi_MatB_BVALID(m_axi_MatB_BVALID),
    .m_axi_MatB_BREADY(m_axi_MatB_BREADY),
    .m_axi_MatB_ARID(m_axi_MatB_ARID),
    .m_axi_MatB_ARADDR(m_axi_MatB_ARADDR),
    .m_axi_MatB_ARLEN(m_axi_MatB_ARLEN),
    .m_axi_MatB_ARSIZE(m_axi_MatB_ARSIZE),
    .m_axi_MatB_ARBURST(m_axi_MatB_ARBURST),
    .m_axi_MatB_ARLOCK(m_axi_MatB_ARLOCK),
    .m_axi_MatB_ARREGION(m_axi_MatB_ARREGION),
    .m_axi_MatB_ARCACHE(m_axi_MatB_ARCACHE),
    .m_axi_MatB_ARPROT(m_axi_MatB_ARPROT),
    .m_axi_MatB_ARQOS(m_axi_MatB_ARQOS),
    .m_axi_MatB_ARUSER(),
    .m_axi_MatB_ARVALID(m_axi_MatB_ARVALID),
    .m_axi_MatB_ARREADY(m_axi_MatB_ARREADY),
    .m_axi_MatB_RID(m_axi_MatB_RID),
    .m_axi_MatB_RDATA(m_axi_MatB_RDATA),
    .m_axi_MatB_RRESP(m_axi_MatB_RRESP),
    .m_axi_MatB_RLAST(m_axi_MatB_RLAST),
    .m_axi_MatB_RUSER(1'B0),
    .m_axi_MatB_RVALID(m_axi_MatB_RVALID),
    .m_axi_MatB_RREADY(m_axi_MatB_RREADY),
    .m_axi_MatC_AWID(m_axi_MatC_AWID),
    .m_axi_MatC_AWADDR(m_axi_MatC_AWADDR),
    .m_axi_MatC_AWLEN(m_axi_MatC_AWLEN),
    .m_axi_MatC_AWSIZE(m_axi_MatC_AWSIZE),
    .m_axi_MatC_AWBURST(m_axi_MatC_AWBURST),
    .m_axi_MatC_AWLOCK(m_axi_MatC_AWLOCK),
    .m_axi_MatC_AWREGION(m_axi_MatC_AWREGION),
    .m_axi_MatC_AWCACHE(m_axi_MatC_AWCACHE),
    .m_axi_MatC_AWPROT(m_axi_MatC_AWPROT),
    .m_axi_MatC_AWQOS(m_axi_MatC_AWQOS),
    .m_axi_MatC_AWUSER(),
    .m_axi_MatC_AWVALID(m_axi_MatC_AWVALID),
    .m_axi_MatC_AWREADY(m_axi_MatC_AWREADY),
    .m_axi_MatC_WID(m_axi_MatC_WID),
    .m_axi_MatC_WDATA(m_axi_MatC_WDATA),
    .m_axi_MatC_WSTRB(m_axi_MatC_WSTRB),
    .m_axi_MatC_WLAST(m_axi_MatC_WLAST),
    .m_axi_MatC_WUSER(),
    .m_axi_MatC_WVALID(m_axi_MatC_WVALID),
    .m_axi_MatC_WREADY(m_axi_MatC_WREADY),
    .m_axi_MatC_BID(m_axi_MatC_BID),
    .m_axi_MatC_BRESP(m_axi_MatC_BRESP),
    .m_axi_MatC_BUSER(1'B0),
    .m_axi_MatC_BVALID(m_axi_MatC_BVALID),
    .m_axi_MatC_BREADY(m_axi_MatC_BREADY),
    .m_axi_MatC_ARID(m_axi_MatC_ARID),
    .m_axi_MatC_ARADDR(m_axi_MatC_ARADDR),
    .m_axi_MatC_ARLEN(m_axi_MatC_ARLEN),
    .m_axi_MatC_ARSIZE(m_axi_MatC_ARSIZE),
    .m_axi_MatC_ARBURST(m_axi_MatC_ARBURST),
    .m_axi_MatC_ARLOCK(m_axi_MatC_ARLOCK),
    .m_axi_MatC_ARREGION(m_axi_MatC_ARREGION),
    .m_axi_MatC_ARCACHE(m_axi_MatC_ARCACHE),
    .m_axi_MatC_ARPROT(m_axi_MatC_ARPROT),
    .m_axi_MatC_ARQOS(m_axi_MatC_ARQOS),
    .m_axi_MatC_ARUSER(),
    .m_axi_MatC_ARVALID(m_axi_MatC_ARVALID),
    .m_axi_MatC_ARREADY(m_axi_MatC_ARREADY),
    .m_axi_MatC_RID(m_axi_MatC_RID),
    .m_axi_MatC_RDATA(m_axi_MatC_RDATA),
    .m_axi_MatC_RRESP(m_axi_MatC_RRESP),
    .m_axi_MatC_RLAST(m_axi_MatC_RLAST),
    .m_axi_MatC_RUSER(1'B0),
    .m_axi_MatC_RVALID(m_axi_MatC_RVALID),
    .m_axi_MatC_RREADY(m_axi_MatC_RREADY)
  );
endmodule
