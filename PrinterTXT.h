#ifndef PRINTERTXT_h
#define PRINTERTXT_h
#include "Engine.h"
#include <string>

using namespace std;

class PrinterTXT : public Engine {
  public:
    PrinterTXT(){};
    PrinterTXT(string filename);
    ~PrinterTXT(){};

    virtual void play();
    virtual void print();
  
};

#endif