-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
-- Date        : Sat Feb 10 12:55:19 2024
-- Host        : LAPTOP-QFCR4R7C running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ matmul_real_matmul_0_0_stub.vhdl
-- Design      : matmul_real_matmul_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    s_axi_control_AWADDR : in STD_LOGIC_VECTOR ( 6 downto 0 );
    s_axi_control_AWVALID : in STD_LOGIC;
    s_axi_control_AWREADY : out STD_LOGIC;
    s_axi_control_WDATA : in STD_LOGIC_VECTOR ( 63 downto 0 );
    s_axi_control_WSTRB : in STD_LOGIC_VECTOR ( 7 downto 0 );
    s_axi_control_WVALID : in STD_LOGIC;
    s_axi_control_WREADY : out STD_LOGIC;
    s_axi_control_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_BVALID : out STD_LOGIC;
    s_axi_control_BREADY : in STD_LOGIC;
    s_axi_control_ARADDR : in STD_LOGIC_VECTOR ( 6 downto 0 );
    s_axi_control_ARVALID : in STD_LOGIC;
    s_axi_control_ARREADY : out STD_LOGIC;
    s_axi_control_RDATA : out STD_LOGIC_VECTOR ( 63 downto 0 );
    s_axi_control_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_RVALID : out STD_LOGIC;
    s_axi_control_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC;
    m_axi_MatA_AWID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatA_AWADDR : out STD_LOGIC_VECTOR ( 63 downto 0 );
    m_axi_MatA_AWLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_MatA_AWSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatA_AWBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatA_AWLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatA_AWREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_AWCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_AWPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatA_AWQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_AWVALID : out STD_LOGIC;
    m_axi_MatA_AWREADY : in STD_LOGIC;
    m_axi_MatA_WID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatA_WDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_MatA_WSTRB : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_WLAST : out STD_LOGIC;
    m_axi_MatA_WVALID : out STD_LOGIC;
    m_axi_MatA_WREADY : in STD_LOGIC;
    m_axi_MatA_BID : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatA_BRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatA_BVALID : in STD_LOGIC;
    m_axi_MatA_BREADY : out STD_LOGIC;
    m_axi_MatA_ARID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatA_ARADDR : out STD_LOGIC_VECTOR ( 63 downto 0 );
    m_axi_MatA_ARLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_MatA_ARSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatA_ARBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatA_ARLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatA_ARREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_ARCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_ARPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatA_ARQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatA_ARVALID : out STD_LOGIC;
    m_axi_MatA_ARREADY : in STD_LOGIC;
    m_axi_MatA_RID : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatA_RDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_MatA_RRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatA_RLAST : in STD_LOGIC;
    m_axi_MatA_RVALID : in STD_LOGIC;
    m_axi_MatA_RREADY : out STD_LOGIC;
    m_axi_MatB_AWID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatB_AWADDR : out STD_LOGIC_VECTOR ( 63 downto 0 );
    m_axi_MatB_AWLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_MatB_AWSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatB_AWBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatB_AWLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatB_AWREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_AWCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_AWPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatB_AWQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_AWVALID : out STD_LOGIC;
    m_axi_MatB_AWREADY : in STD_LOGIC;
    m_axi_MatB_WID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatB_WDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_MatB_WSTRB : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_WLAST : out STD_LOGIC;
    m_axi_MatB_WVALID : out STD_LOGIC;
    m_axi_MatB_WREADY : in STD_LOGIC;
    m_axi_MatB_BID : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatB_BRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatB_BVALID : in STD_LOGIC;
    m_axi_MatB_BREADY : out STD_LOGIC;
    m_axi_MatB_ARID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatB_ARADDR : out STD_LOGIC_VECTOR ( 63 downto 0 );
    m_axi_MatB_ARLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_MatB_ARSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatB_ARBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatB_ARLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatB_ARREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_ARCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_ARPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatB_ARQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatB_ARVALID : out STD_LOGIC;
    m_axi_MatB_ARREADY : in STD_LOGIC;
    m_axi_MatB_RID : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatB_RDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_MatB_RRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatB_RLAST : in STD_LOGIC;
    m_axi_MatB_RVALID : in STD_LOGIC;
    m_axi_MatB_RREADY : out STD_LOGIC;
    m_axi_MatC_AWID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatC_AWADDR : out STD_LOGIC_VECTOR ( 63 downto 0 );
    m_axi_MatC_AWLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_MatC_AWSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatC_AWBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatC_AWLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatC_AWREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_AWCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_AWPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatC_AWQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_AWVALID : out STD_LOGIC;
    m_axi_MatC_AWREADY : in STD_LOGIC;
    m_axi_MatC_WID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatC_WDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_MatC_WSTRB : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_WLAST : out STD_LOGIC;
    m_axi_MatC_WVALID : out STD_LOGIC;
    m_axi_MatC_WREADY : in STD_LOGIC;
    m_axi_MatC_BID : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatC_BRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatC_BVALID : in STD_LOGIC;
    m_axi_MatC_BREADY : out STD_LOGIC;
    m_axi_MatC_ARID : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatC_ARADDR : out STD_LOGIC_VECTOR ( 63 downto 0 );
    m_axi_MatC_ARLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_MatC_ARSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatC_ARBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatC_ARLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatC_ARREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_ARCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_ARPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_MatC_ARQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_MatC_ARVALID : out STD_LOGIC;
    m_axi_MatC_ARREADY : in STD_LOGIC;
    m_axi_MatC_RID : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_axi_MatC_RDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_MatC_RRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_MatC_RLAST : in STD_LOGIC;
    m_axi_MatC_RVALID : in STD_LOGIC;
    m_axi_MatC_RREADY : out STD_LOGIC
  );

end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axi_control_AWADDR[6:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[63:0],s_axi_control_WSTRB[7:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[6:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[63:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_clk,ap_rst_n,interrupt,m_axi_MatA_AWID[0:0],m_axi_MatA_AWADDR[63:0],m_axi_MatA_AWLEN[7:0],m_axi_MatA_AWSIZE[2:0],m_axi_MatA_AWBURST[1:0],m_axi_MatA_AWLOCK[1:0],m_axi_MatA_AWREGION[3:0],m_axi_MatA_AWCACHE[3:0],m_axi_MatA_AWPROT[2:0],m_axi_MatA_AWQOS[3:0],m_axi_MatA_AWVALID,m_axi_MatA_AWREADY,m_axi_MatA_WID[0:0],m_axi_MatA_WDATA[31:0],m_axi_MatA_WSTRB[3:0],m_axi_MatA_WLAST,m_axi_MatA_WVALID,m_axi_MatA_WREADY,m_axi_MatA_BID[0:0],m_axi_MatA_BRESP[1:0],m_axi_MatA_BVALID,m_axi_MatA_BREADY,m_axi_MatA_ARID[0:0],m_axi_MatA_ARADDR[63:0],m_axi_MatA_ARLEN[7:0],m_axi_MatA_ARSIZE[2:0],m_axi_MatA_ARBURST[1:0],m_axi_MatA_ARLOCK[1:0],m_axi_MatA_ARREGION[3:0],m_axi_MatA_ARCACHE[3:0],m_axi_MatA_ARPROT[2:0],m_axi_MatA_ARQOS[3:0],m_axi_MatA_ARVALID,m_axi_MatA_ARREADY,m_axi_MatA_RID[0:0],m_axi_MatA_RDATA[31:0],m_axi_MatA_RRESP[1:0],m_axi_MatA_RLAST,m_axi_MatA_RVALID,m_axi_MatA_RREADY,m_axi_MatB_AWID[0:0],m_axi_MatB_AWADDR[63:0],m_axi_MatB_AWLEN[7:0],m_axi_MatB_AWSIZE[2:0],m_axi_MatB_AWBURST[1:0],m_axi_MatB_AWLOCK[1:0],m_axi_MatB_AWREGION[3:0],m_axi_MatB_AWCACHE[3:0],m_axi_MatB_AWPROT[2:0],m_axi_MatB_AWQOS[3:0],m_axi_MatB_AWVALID,m_axi_MatB_AWREADY,m_axi_MatB_WID[0:0],m_axi_MatB_WDATA[31:0],m_axi_MatB_WSTRB[3:0],m_axi_MatB_WLAST,m_axi_MatB_WVALID,m_axi_MatB_WREADY,m_axi_MatB_BID[0:0],m_axi_MatB_BRESP[1:0],m_axi_MatB_BVALID,m_axi_MatB_BREADY,m_axi_MatB_ARID[0:0],m_axi_MatB_ARADDR[63:0],m_axi_MatB_ARLEN[7:0],m_axi_MatB_ARSIZE[2:0],m_axi_MatB_ARBURST[1:0],m_axi_MatB_ARLOCK[1:0],m_axi_MatB_ARREGION[3:0],m_axi_MatB_ARCACHE[3:0],m_axi_MatB_ARPROT[2:0],m_axi_MatB_ARQOS[3:0],m_axi_MatB_ARVALID,m_axi_MatB_ARREADY,m_axi_MatB_RID[0:0],m_axi_MatB_RDATA[31:0],m_axi_MatB_RRESP[1:0],m_axi_MatB_RLAST,m_axi_MatB_RVALID,m_axi_MatB_RREADY,m_axi_MatC_AWID[0:0],m_axi_MatC_AWADDR[63:0],m_axi_MatC_AWLEN[7:0],m_axi_MatC_AWSIZE[2:0],m_axi_MatC_AWBURST[1:0],m_axi_MatC_AWLOCK[1:0],m_axi_MatC_AWREGION[3:0],m_axi_MatC_AWCACHE[3:0],m_axi_MatC_AWPROT[2:0],m_axi_MatC_AWQOS[3:0],m_axi_MatC_AWVALID,m_axi_MatC_AWREADY,m_axi_MatC_WID[0:0],m_axi_MatC_WDATA[31:0],m_axi_MatC_WSTRB[3:0],m_axi_MatC_WLAST,m_axi_MatC_WVALID,m_axi_MatC_WREADY,m_axi_MatC_BID[0:0],m_axi_MatC_BRESP[1:0],m_axi_MatC_BVALID,m_axi_MatC_BREADY,m_axi_MatC_ARID[0:0],m_axi_MatC_ARADDR[63:0],m_axi_MatC_ARLEN[7:0],m_axi_MatC_ARSIZE[2:0],m_axi_MatC_ARBURST[1:0],m_axi_MatC_ARLOCK[1:0],m_axi_MatC_ARREGION[3:0],m_axi_MatC_ARCACHE[3:0],m_axi_MatC_ARPROT[2:0],m_axi_MatC_ARQOS[3:0],m_axi_MatC_ARVALID,m_axi_MatC_ARREADY,m_axi_MatC_RID[0:0],m_axi_MatC_RDATA[31:0],m_axi_MatC_RRESP[1:0],m_axi_MatC_RLAST,m_axi_MatC_RVALID,m_axi_MatC_RREADY";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "real_matmul,Vivado 2023.1";
begin
end;
