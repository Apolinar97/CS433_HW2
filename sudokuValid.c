/*********************************************
Written by: Apolinar Camacho and Alan Mendez
Instructor: Leticia Rabor
Init Date: 2/25/2019
Due Date: 2/28/2019

************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ROW 9
#define COL 9
#define SIZE_VALID_ARRAY 11

//Sudoku Solution that will be used for testing puposed.
int Sudoku[ROW][COL] = {
  {6,2,4,5,3,9,1,8,7},
  {5,1,9,7,2,8,6,3,4},
  {8,3,7,6,1,4,2,9,5},
  {1,4,3,8,6,5,7,2,9},
  {9,5,8,2,4,7,3,6,1},
  {7,6,2,3,9,1,4,5,8},
  {3,7,1,9,5,6,8,4,2},
  {4,9,6,1,8,2,5,7,3},
  {2,8,5,4,7,3,9,1,6}
};
int validArray[SIZE_VALID_ARRAY] = {0,0,0,0,0,0,0,0,0,0,0};
int validArray2[9] = {1,2,3,4,5,6,7,8,9};

// row and column that will be checked, put into a struct.
typedef struct {
  int _row;
  int _col;
} parameters;

void* rowValid(void* workingParam);
void* colValid(void* workingParam);

int main() {
  
  return 0;
}

void* rowValid(void* workingParam) { 
  parameters *currentParam = workingParam;
  int row = currentParam->_row;
  int col = currentParam->_col;
  int tempArray[9] = {1,2,3,4,5,6,7,8,9};
  int success = 0; 
  
  for(int colum=0; colum<9; colum++)
    {
      for(int row_=0; row_<9; row_++) 
	{
       for(int i=0; i<9; i++)
	 {   
	   if(Sudoku[colum][row] == tempArray[i] && Sudoku[colum][row_] > 0 &&
	      Sudoku[colum][row_] < 10)
	     {
	       success ++;
	     }
	   else
	     {
	       
	     }
	 }
       if(success == 1)
	 {
	   int tempArray[9] = {1,2,3,4,5,6,7,8,9};
	   sucess = 0;
	 }
	}
    }
}



void* colValid(void* workingParam) {
  ;
}

