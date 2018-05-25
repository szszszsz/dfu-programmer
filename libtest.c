//
// Created by sz on 25.02.18.
//

#include "src/lib_implementation.h"

int main(int argc, char** argv){

  if (argc !=2){
    return 1;
  }
  switch (argv[1][0]){
    case 'l': launch(); break;
    case 'e': erase(); break;
    case 'f': flash(); break;
    default: break;
  }
  return 0;
}