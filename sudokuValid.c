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

// row and column that will be checked, put into a struct.
typedef struct {
  int _row;
  int _col;
} parameters;

void* rowValid(void* workingParam);
void* colValid(void* workingParam);
void* valid3x3(void* workingParam);

int main() {
  //Parameters for col and row//
  parameters* p0 = (parameters*) malloc(sizeof(parameters));
  p0->_row = 0;
  p0->_col = 0;

  //Threads section begin//
  pthread_t tRows;
  pthread_t tCols;
  
  //end threads section//

  //Return values
  void* rows;
  void* cols;
  //end return values section // 

  //Initialize thread
  pthread_create(&tRows,NULL,rowValid,(void *) p0);
  pthread_create(&tCols,NULL,colValid,(void *) p0);
  

  //Wait for threads//
  pthread_join(tRows,&rows);
  pthread_join(tCols,&cols);
  
  return 0;
}

void* rowValid(void* workingParam) { 
  parameters* data = (parameters*) workingParam;
  int startRow = data->_row;
  int startCol = data->_col;
  int tableValue;
  
  printf("Initial values of row and col: %d:%d \n", startRow, startCol);
  
  for(int i = startRow; i<9; i++) {
    
    int checker[10] = {0};//array to check for duplicates.
    
    
    for(int j = startCol; j<9; j++)
      {
	tableValue = Sudoku[i][j];
	
	if(checker[tableValue] != 0)
	  {
	    printf("Invalid row.\n");
	    return (void*) 0;
	  }
	else {
	  checker[tableValue] = 1;
	  printf("Value of table.\n %d",tableValue);
	}
      }
    
  }
  printf("Valid row!");
  
  return (void*) 1;
  
}//end of rowValid(...); 

void* colValid(void* workingParam) {
  parameters* data = (parameters*) workingParam;
  int startRow = data->_row;
  int startCol = data->_col;
  int tableValue;
  for(int i=startCol; i<9;i++) {
    int checker[10] = {0};

    for(int j=startRow; j<9; j++) {
      tableValue = Sudoku[j][i];

      if(checker[tableValue] !=0) { //duplicate has apperead. 
	return (void *) 0;
      }

      else {
	printf("tableValue: %d\n ", tableValue);
	checker[tableValue] = 1;
      }
      
    }//end of inner for
    
  }//end outter for.

  return (void*) 1;
  
 
}//end of colValid.

void* valid3x3(void* workingParam) {
  parameters* data = (parameters*) workingParam;
  int startRow = data->_row;
  int startCol = data->_col;
  int checker[9] = {0};
  int tempNum;
  for(int i = startRow; startRow<startRow+3; i++)
    {
      for(int z = startCol; startCol=startCol+3; z++)
	{
	  tempNum = Sudoku[startRow][startCol];
	  if(checker[tempNum] != 0)
	    {
	      return (void* ) 0;
	    }
	  else
	    {
	      checker[tempNum]=1;
	    }
	}//end innner for.
      
    }//end of outter for.
  
  return (void*) 1;
}

  /*
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
	   success = 0;
	 }
	}
    }
  */


