/*
Author: Haonan Hu
File: main.cpp
Date:2/24/2020
Brief:File is main file
*/

#include "Executive.h"
#include <stdexcept>
#include <string>
#include <iostream>

int main(int argc, char*argv[ ])
{
  if(argc < 3)
  {
    std::cout << "Wrong number of parameters\n";
  }
  else
  {
    executive exec(argv[1],argv[2]);
    exec.run();
  }
  return 0;
}
