///////////////////////////////////////////////////////////////////////////////
// Author:      <>
// Course:      ECE8893 - Parallel Programming for FPGAs
// Filename:    real_matmul.cpp
// Description: Perform matrix multiplication with real values
//
// Note:        You are free to modify this code to optimize your design.
///////////////////////////////////////////////////////////////////////////////

#include "real.h"
#include <string.h>

#define BLOCK_SIZE 4

void LoadMatricesFromDRAMToBRAM(real_t MatA_BRAM[BLOCK_SIZE][N], real_t MatA_DRAM[M][N], real_t MatB_BRAM[N][BLOCK_SIZE], real_t MatB_DRAM[N][K], int counter);
void PerformMatrixCalculation(real_t MatA_BRAM[BLOCK_SIZE][N], real_t MatB_BRAM[N][BLOCK_SIZE], real_t MatC_BRAM[BLOCK_SIZE][BLOCK_SIZE]);
void LoadMatricesFromBRAMToDRAM(real_t MatC_BRAM[BLOCK_SIZE][BLOCK_SIZE], real_t MatC_DRAM[M][K], int counter);

void real_matmul( 
    real_t MatA_DRAM[M][N], 
    real_t MatB_DRAM[N][K], 
    real_t MatC_DRAM[M][K])
{
    #pragma HLS interface m_axi depth=1 port=MatA_DRAM offset=slave bundle=MatA
    #pragma HLS interface m_axi depth=1 port=MatB_DRAM offset=slave bundle=MatB
    #pragma HLS interface m_axi depth=1 port=MatC_DRAM offset=slave bundle=MatC

    #pragma HLS interface s_axilite port=return

    CallBlockMatmul: for (int counter = 0; counter < (M / BLOCK_SIZE) * (K / BLOCK_SIZE); counter++) {
        #pragma HLS dataflow

        real_t MatA_BRAM[BLOCK_SIZE][N];
        real_t MatB_BRAM[N][BLOCK_SIZE];
        real_t MatC_BRAM[BLOCK_SIZE][BLOCK_SIZE];
        // Partition A along dimension 1 and B along dimension 2
        // Partition A Factor: M/BLOCK_SIZE
        // Partition B Factor: K/BLOCK_SIZE
        #pragma HLS array_partition variable=MatA_BRAM block factor=25 dim=1
        #pragma HLS array_partition variable=MatB_BRAM block factor=50 dim=2
        LoadMatricesFromDRAMToBRAM(MatA_BRAM, MatA_DRAM, MatB_BRAM, MatB_DRAM, counter);
        PerformMatrixCalculation(MatA_BRAM, MatB_BRAM, MatC_BRAM);
        LoadMatricesFromBRAMToDRAM(MatC_BRAM, MatC_DRAM, counter);
    }
}

void LoadMatricesFromDRAMToBRAM(real_t MatA_BRAM[BLOCK_SIZE][N], real_t MatA_DRAM[M][N], real_t MatB_BRAM[N][BLOCK_SIZE], real_t MatB_DRAM[N][K], int counter) {
    int i, j, k;

    // Load values from DRAM real_to BRAM
    LoadMatAFromDRAMtoBRAMOuter: for (i = 0; i < BLOCK_SIZE; i++) {
        LoadMatAFromDRAMtoBRAMInner: for (j = 0; j < N; j++) {
            #pragma HLS PIPELINE II=1
            MatA_BRAM[i][j] = MatA_DRAM[BLOCK_SIZE * (counter / (K / BLOCK_SIZE)) + i][j];
        }
    }

    LoadMatBFromDRAMtoBRAMOuter: for (i = 0; i < BLOCK_SIZE; i++) {
        LoadMatBFromDRAMtoBRAMInner: for (j = 0; j < N; j++) {
            #pragma HLS PIPELINE II=1
            MatB_BRAM[j][i] = MatB_DRAM[j][i + BLOCK_SIZE * (counter % (K / BLOCK_SIZE))];
        }
    }
}

void PerformMatrixCalculation(real_t MatA_BRAM[BLOCK_SIZE][N], real_t MatB_BRAM[N][BLOCK_SIZE], real_t MatC_BRAM[BLOCK_SIZE][BLOCK_SIZE]) {
    // Calculation Loop
    PerformBlockMatrixCalculationOuter: for (int i = 0; i < BLOCK_SIZE; i++) {
        PerformBlockMatrixCalculationInner: for (int j = 0; j < BLOCK_SIZE; j++) {
            MatC_BRAM[i][j] = 0;
            #pragma HLS PIPELINE II=1
            PerformBlockMatrixCalculationElementWise: for (int k = 0; k < N; k++) {
                MatC_BRAM[i][j] += MatA_BRAM[i][k] * MatB_BRAM[k][j];
            }
        }
    }
}

void LoadMatricesFromBRAMToDRAM(real_t MatC_BRAM[BLOCK_SIZE][BLOCK_SIZE], real_t MatC_DRAM[M][K], int counter) {
    LoadArraysFromBRAMtoDRAMOuter: for (int i = 0; i < BLOCK_SIZE; i++) {
        LoadArraysFromBRAMtoDRAMInner: for (int j = 0; j < BLOCK_SIZE; j++) {
            #pragma HLS PIPELINE II=1
            MatC_DRAM[BLOCK_SIZE * (counter / (K / BLOCK_SIZE)) + i][j + BLOCK_SIZE * (counter % (K / BLOCK_SIZE))] = MatC_BRAM[i][j];
        }
    }
}
