#include <iostream>
#include "Engine.h"

using namespace std;

Engine::Engine(Matrix* matrix, Matrix* tmp) : matrix(matrix), tmp_matrix(tmp){};

void Engine::cloneMatrix(Matrix* destination_matrix, Matrix* input_matrix){
  destination_matrix->setColumns(input_matrix->getColumns());
  destination_matrix->setRows(input_matrix->getRows());
  destination_matrix->overrideMatrix(input_matrix->getMatrix());
}

int Engine::countNeighbors(int colIndex, int rowIndex){
  int neighborsAmount = 0;
  (colIndex-1 >= 0 && matrix->getMatrix()[colIndex-1][rowIndex] == 1) ? neighborsAmount++ : neighborsAmount;
  (colIndex-1 >= 0 && rowIndex-1 >= 0 && matrix->getMatrix()[colIndex-1][rowIndex-1] == 1 ) ? neighborsAmount++ : neighborsAmount;
  (rowIndex-1 >= 0 && matrix->getMatrix()[colIndex][rowIndex-1] == 1 ) ? neighborsAmount++ : neighborsAmount;
  (colIndex+1 < matrix->getColumns() && rowIndex-1 >= 0 && matrix->getMatrix()[colIndex+1][rowIndex-1] == 1) ? neighborsAmount++ : neighborsAmount;
  (colIndex+1 < matrix->getColumns() && matrix->getMatrix()[colIndex+1][rowIndex] == 1) ? neighborsAmount++ : neighborsAmount;
  (colIndex+1 < matrix->getColumns() && rowIndex+1 < matrix->getRows()-1 && matrix->getMatrix()[colIndex+1][rowIndex+1] == 1) ? neighborsAmount++ : neighborsAmount;
  (rowIndex+1 < matrix->getRows() && matrix->getMatrix()[colIndex][rowIndex+1] == 1) ? neighborsAmount++ : neighborsAmount;
  (colIndex-1 >= 0 && rowIndex+1 < matrix->getRows() && matrix->getMatrix()[colIndex-1][rowIndex+1] == 1)  ? neighborsAmount++ : neighborsAmount;

  return neighborsAmount;
}

void Engine::scanMatrix(){
  for(int i=0; i<matrix->getColumns(); i++){
    for(int j=0; j<matrix->getRows(); j++){
      int neighborsAmount = 0;
      neighborsAmount = countNeighbors(i,j);
      (neighborsAmount == 0) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 1) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 2 && matrix->getMatrix()[i][j] == 0) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 2 && matrix->getMatrix()[i][j] == 1) ? tmp_matrix->updateMatrix(i,j,1) : void();
      (neighborsAmount == 3) ? tmp_matrix->updateMatrix(i,j,1) : void();
      (neighborsAmount == 4) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 5) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 6) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 7) ? tmp_matrix->updateMatrix(i,j,0) : void();
      (neighborsAmount == 8) ? tmp_matrix->updateMatrix(i,j,0) : void();
    }
  }
  cloneMatrix(matrix, tmp_matrix);
}

