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

  parameters* _1st3x3 = (parameters*) malloc(sizeof(parameters));
  _1st3x3->_row = 0;
  _1st3x3->_col = 0;

  parameters* _2nd3x3 = (parameters*) malloc(sizeof(parameters));
  _2nd3x3->_row = 0;
  _2nd3x3->_col = 3;

  parameters* _3d3x3 = (parameters*) malloc(sizeof(parameters));
  _3d3x3->_row=0;
  _3d3x3->_col = 6;

  parameters* _4th3x3 = (parameters*) malloc(sizeof(parameters));
  _4th3x3->_row = 3;
  _4th3x3->_col= 0;

  parameters* _5th3x3 = (parameters*) malloc(sizeof(parameters));
  _5th3x3->_row = 3;
  _5th3x3->_col = 3;

  parameters* _6th3x3 = (parameters*) malloc(sizeof(parameters));
  _6th3x3->_row = 3;
  _6th3x3->_col = 6;

  parameters* _7th3x3 = (parameters*) malloc(sizeof(parameters));
  _7th3x3->_row = 6;
  _7th3x3->_col = 0;

  parameters* _8th3x3 = (parameters*) malloc(sizeof(parameters));
  _8th3x3->_row = 6;
  _8th3x3->_col = 3;

  parameters* _9th3x3 = (parameters*) malloc(sizeof(parameters));
  _9th3x3->_row = 6;
  _9th3x3->_col = 6;   
  //end of parameters init.
  


  //Threads section begin//
  pthread_t tRows;
  pthread_t tCols;
  pthread_t unit1;
  pthread_t unit2;
  pthread_t unit3;
  pthread_t unit4;
  pthread_t unit5;
  pthread_t unit6;
  pthread_t unit7;
  pthread_t unit8;
  pthread_t unit9;
  
  //end threads section//

  //Return values
  
  void* return0;
  void* return1;
  void* return2;
  void* return3;
  void* return4;
  void* return5;
  void* return6;
  void* return7;
  void* return8;
  void* return9;
  void* return10;
  void* return11;

  //end return values section // 

  //Initialize thread
  pthread_create(&tRows,NULL,rowValid,(void *) p0);
  pthread_create(&tCols,NULL,colValid,(void *) p0);
  
  pthread_create(&unit1,NULL,valid3x3,(void *) _1st3x3);
  pthread_create(&unit2,NULL,valid3x3,(void *) _2nd3x3);
  pthread_create(&unit3,NULL,valid3x3,(void *) _3d3x3);   
  pthread_create(&unit4,NULL,valid3x3,(void *) _4th3x3);
  pthread_create(&unit5,NULL,valid3x3,(void *) _5th3x3);
  pthread_create(&unit6,NULL,valid3x3,(void *) _6th3x3);
  pthread_create(&unit7,NULL,valid3x3,(void *) _7th3x3);
  pthread_create(&unit8,NULL,valid3x3,(void *) _8th3x3);
  pthread_create(&unit9,NULL,valid3x3,(void *) _9th3x3);
 
  //Wait for threads//
  pthread_join(tRows,&return0);
  pthread_join(tCols,&return1);
  pthread_join(unit1,&return2);
  
  pthread_join(unit2,&return3);
  pthread_join(unit3,&return4);
  
 
  pthread_join(unit4,&return5);
  pthread_join(unit5,&return6);
  pthread_join(unit6,&return7);
  pthread_join(unit7,&return8);
  pthread_join(unit8,&return9);
  pthread_join(unit9,&return10);
  
  
  if( (long) return0 == 1 && (long) return1 == 1 && (long) return2 == 1 && (long) return3 == 1 &&
      (long) return4 == 1 && (long) return5 == 1 && (long) return6 == 1 && (long) return7 == 1 &&
      (long) return8 == 1 && (long) return9 == 1 && (long) return10 == 1)  {

    printf("Valid Sudoku board! \n");
  }
  else
    {
      printf("Invalid Sudoku board\n");
    }
 
  
  return 0;
}
//Written by Apolinar Camacho
void* rowValid(void* workingParam) { 
  parameters* data = (parameters*) workingParam;
  int startRow = data->_row;
  int startCol = data->_col;
  int tableValue;
  
  
  for(int i = startRow; i<9; i++) {
    
    int checker[10] = {0};//array to check for duplicates.
    
    
    for(int j = startCol; j<9; j++)
      {
	tableValue = Sudoku[i][j];
	
	if(checker[tableValue] != 0)
	  {
	    // printf("Invalid row.\n");
	    return (void*)  0;
	  }
	else {
	  checker[tableValue] = 1;
	  //printf("Value of table.\n %d",tableValue);
	}
      }
    
  }
  //printf("Valid row!");
  
  return (void*)  1;
  
}//end of rowValid(...); 
//Written by Apolinar Camacho
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
	return (void*)  0;
      }

      else {
	//printf("tableValue: %d\n ", tableValue);
	checker[tableValue] = 1;
      }
      
    }//end of inner for
    
  }//end outter for.

  return (void*) 1;
  
 
}//end of colValid.
//Written by: Alan Mendez.

void* valid3x3(void* workingParam) {
  parameters* data = (parameters*) workingParam;
  int startRow = data->_row;
  int startCol = data->_col;
  int checker[10] = {0};
  int tempNum;
  
  for(int i = startRow; i<startRow+3; i++)
    {
      for(int z = startCol; z<startCol+3; z++)
	{	  
	  tempNum = Sudoku[i][z];
	  // printf("tempNum: %d\n",tempNum);
	  if(checker[tempNum] != 0)
	    {
	      printf("Error!....\n");
	      return (void*) 0;
	    }
	  else
	    {
	      checker[tempNum]=1;
	      // printf("Okay! 3x3!\n");
	    }
	}//end innner for.
      
    }//end of outter for.
  
  return (void*)  1;
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


