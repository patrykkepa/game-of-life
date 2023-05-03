#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
  protected:
    int ** matrix;
    int columns;
    int rows;
  public:
    Matrix();
    Matrix(int, int);
    ~Matrix();
    Matrix& operator=(const Matrix& m);
    Matrix(const Matrix& m);

    void initEmptyMatrix(int rows, int cols);
    void setColumns(int col);
    void setRows(int row);

    int getColumns();
    int getRows();
    int** getMatrix();

    void updateMatrix(int rowIndex, int colIndex, int value);
    void overrideMatrix(int ** m);
  
};

#endif