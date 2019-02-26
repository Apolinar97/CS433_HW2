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
//Sudoku Solution that will be used for testing puposed.
int SudokuSolution[ROW][COL] = {
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
  int row;
  int column;

} parameters;


int main() {
  
  return 0;
}
