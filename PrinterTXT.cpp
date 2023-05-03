#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include "PrinterTXT.h"

using namespace std;

// PrinterTXT::PrinterTXT(int col, int row) : Engine(new Matrix(col, row), new Matrix(col, row)){};

PrinterTXT::PrinterTXT(string filename): Engine(new Matrix(), new Matrix()){
  ifstream plik;
  plik.open(filename);
  if(plik.is_open()){
    string dimension;
    string initBoard;
    string initBoardLine;
    int lineNumber = 0;
    int col, row;

    // wczytaj rozmiary
    while(!plik.eof() && lineNumber == 0){
        getline(plik, dimension);
        row = stoi(dimension);
        lineNumber++;
    }
    while(!plik.eof() && lineNumber == 1){
        getline(plik, dimension);
        col = stoi(dimension);
        lineNumber++;
    }
    while(!plik.eof() && lineNumber > 1 && (lineNumber < row +2)){
      getline(plik, initBoardLine);
      initBoard += initBoardLine;
    }
    //zainicjuj pustą macierz
    matrix->initEmptyMatrix(col, row);
    tmp_matrix->initEmptyMatrix(col, row);

    // wypełnij na podstawie pliku
    int index = 0;
    for(int w=0; w<col; w++){
      for(int h=0; h<row; h++){
        char value = initBoard[index++];
        matrix->updateMatrix(w,h,value-'0');
      }
    }
    cloneMatrix(tmp_matrix, matrix);

  } else {
    cout << "Blad otwarcia pliku" << endl;
    exit(0);
  }
};


void PrinterTXT::print() {
  for(int i=0; i<matrix->getColumns(); i++){
    cout << endl;
    for(int j=0; j<matrix->getRows(); j++){
      if(matrix->getMatrix()[i][j] != 0){
        
        cout << "#";
      }
      else {
        cout << " ";
      }
    }
  }
  cout << endl;
};

void PrinterTXT::play(){
  while(1)
      {
        system("cls");
        print();
        scanMatrix();

        using namespace std::this_thread;
        using namespace std::chrono;
        sleep_until(system_clock::now() + milliseconds(900));


        if( kbhit() ){ 
            if( 'c' == getch() ){
                break;
            }
        }
      }

}