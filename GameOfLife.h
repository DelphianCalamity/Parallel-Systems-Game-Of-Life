#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "mpi.h"

#define XDIMENSION	10						//We demand that the grid is square in order to simplify the problem, so only its one dimension needs to be defined
#define GENERATIONS 1	                	//number of generations
#define MAXWORKER   50                  	//maximum number of worker tasks
#define MINWORKER   1                  		//minimum number of worker tasks
#define BEGIN       1
#define TAG       	2
#define DONE        4
#define MASTER      0
#define ALIVE		't'
#define DEAD 		'f'

typedef struct {
	int north;
	int south;
	int west;
	int east;
	int northeast;
	int northwest;
	int southeast;
	int southwest;
} Neighborhood;


typedef struct {
	char *north;
	char *south;
	char *west;
	char *east;
	char northeast;
	char northwest;
	char southeast;
	char southwest;
} ReceiveBuffer;

void prtdat();
void nextGenerationInsideCells(char *fromGrid, char *toGrid, int x);
void nextGenerationOutsideCells(char *fromGrid, char *toGrid, int x);
void validateInput(int numOfworkers);
void getRestNeighbors(MPI_Comm cartesianComm, int *myCoords, int sqrtWorkers, Neighborhood *neighbors);

#endif
