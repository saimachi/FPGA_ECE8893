///////////////////////////////////////////////////////////////////////////////
// Author:      <>
// Course:      ECE8893 - Parallel Programming for FPGAs
// Filename:    real_matmul.cpp
// Description: Perform matrix multiplication with real values
//
// Note:        You are free to modify this code to optimize your design.
///////////////////////////////////////////////////////////////////////////////

#include "real.h"

#define BLOCK_SIZE 2

void block_matmul(real_t[M][N], real_t[N][K], int, real_t[M][K]);

void real_matmul( 
    real_t MatA_DRAM[M][N], 
    real_t MatB_DRAM[N][K], 
    real_t MatC_DRAM[M][K])
{
#pragma HLS interface m_axi depth=1 port=MatA_DRAM offset=slave bundle=mem
#pragma HLS interface m_axi depth=1 port=MatB_DRAM offset=slave bundle=mem
#pragma HLS interface m_axi depth=1 port=MatC_DRAM offset=slave bundle=mem

#pragma HLS interface s_axilite port=return

    for (int counter = 0; counter < (M / BLOCK_SIZE) * (K / BLOCK_SIZE); counter++) {
    	block_matmul(MatA_DRAM, MatB_DRAM, counter, MatC_DRAM);
    }
}

void block_matmul(
		real_t MatA_DRAM[M][N],
		real_t MatB_DRAM[N][K],
		int counter,
		real_t MatC_DRAM[M][K]
) {
	real_t MatA_BRAM[BLOCK_SIZE][N];
	real_t MatB_BRAM[N][BLOCK_SIZE];
	real_t MatC_BRAM[BLOCK_SIZE][BLOCK_SIZE] = {};

	int i, j, k;

	// Load values from DRAM into BRAM
	for (i = 0; i < BLOCK_SIZE; i++) {
		for (j = 0; j < N; j++) {
			MatA_BRAM[i][j] = MatA_DRAM[BLOCK_SIZE * (counter / (K / BLOCK_SIZE)) + i][j];
			MatB_BRAM[j][i] = MatB_DRAM[j][i + BLOCK_SIZE * (counter % (K / BLOCK_SIZE))];
		}
	}

	// Calculation Loop
	for (i = 0; i < BLOCK_SIZE; i++) {
		for (j = 0; j < BLOCK_SIZE; j++) {
			MatC_BRAM[i][j] = 0;
			for (k = 0; k < N; k++) {
				MatC_BRAM[i][j] += MatA_BRAM[i][k] * MatB_BRAM[k][j];
			}
		}
	}

	// Write values from BRAM back to DRAM
	for (i = 0; i < BLOCK_SIZE; i++) {
		for (j = 0; j < BLOCK_SIZE; j++) {
			// printf("(%d, %d)\n", BLOCK_SIZE * (counter / (K / BLOCK_SIZE)) + i, j + BLOCK_SIZE * (counter % (K / BLOCK_SIZE)));
			MatC_DRAM[BLOCK_SIZE * (counter / (K / BLOCK_SIZE)) + i][j + BLOCK_SIZE * (counter % (K / BLOCK_SIZE))] = MatC_BRAM[i][j];
		}
	}
}
