#include <iostream>
#include "Matrix.h"

using namespace std;

// ***CONSTRUCTORS***
Matrix::Matrix(): columns(0), rows(0){};
Matrix::Matrix(int h, int w) : columns(w), rows(h){
  matrix = new (nothrow) int*[columns];
  for(int i = 0; i < w; i++)
    matrix[i] = new int[h];
  for(int i=0; i<w; i++)
    for(int j=0; j<h; j++){
      matrix[i][j] = false;
    }
};
Matrix::~Matrix(){
  for (int i = 0; i < rows; i++)
      delete[] matrix[i];
  delete[] matrix;
}

//  *** SETTERS ***
void Matrix::setColumns(int col){
  this->columns = col;
}
void Matrix::setRows(int row){
  this->rows = row;
}
void Matrix::initEmptyMatrix(int col, int row){
  this->rows = row;
  this->columns = col;
  matrix = new (nothrow) int*[col];
  for(int i = 0; i < col; i++)
    matrix[i] = new int[row];
};
void Matrix::updateMatrix(int colIndex, int rowIndex, int value){
  matrix[colIndex][rowIndex] = value;
}
void Matrix::overrideMatrix(int** m){
  for(int i=0; i<columns; i++){
    for(int j=0; j<rows; j++){
      updateMatrix(i,j, m[i][j]);
    }
  }
}

// ***GETTERS***
int** Matrix::getMatrix(){
  return matrix;
}
int Matrix::getColumns(){
  return columns;
}
int Matrix::getRows(){
  return rows;
}