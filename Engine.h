#ifndef ENGINE_H
#define ENGINE_H
#include "Matrix.h"

class Engine {
  protected:
    Matrix* matrix;  
    Matrix* tmp_matrix;  
  public:
    Engine(){};
    virtual ~Engine(){};
    Engine(Matrix* m, Matrix* tmp);
    void cloneMatrix(Matrix* destination_matrix, Matrix* input_matrix);
    int countNeighbors(int col, int row);
    void scanMatrix();

    virtual void play()=0;
    virtual void print()=0;

};

#endif