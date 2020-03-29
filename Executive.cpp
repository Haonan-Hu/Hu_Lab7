/*
Author: Haonan Hu
File: Executive.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Executive.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <limits>

executive::executive(std::string fileName)
{

}

executive::~executive(){}

void executive::run()
{
  int choice;
  for(;;)
  {
    std::cout << "Please choose one of the following commands: \n";
    std::cout << "1) isFull\n";
    std::cout << "2) Add Movie\n";
    std::cout << "3) Remove movie\n";
    std::cout << "4) Leaf\n";
    std::cout << "5) Print Leaves\n";
    std::cout << "6) Print Tree Height\n";
    std::cout << "7) Preorder\n";
    std::cout << "8) Postorder\n";
    std::cout << "9) Inorder\n";
    std::cout << "10)Levelorder\n";
    std::cout << "11)Exit\n";
    std::cin >> choice;
    std::cout << '\n';
    while(1)
    {
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\n\n";
        std::cout << "..................................\n\n";
        std::cout << "Choose one operation from the options below: \n\n";
        std::cout << "Please choose one of the following commands: \n";
        std::cout << "1) isFull\n";
        std::cout << "2) Add Movie\n";
        std::cout << "3) Remove movie\n";
        std::cout << "4) Leaf\n";
        std::cout << "5) Print Leaves\n";
        std::cout << "6) Print Tree Height\n";
        std::cout << "7) Preorder\n";
        std::cout << "8) Postorder\n";
        std::cout << "9) Inorder\n";
        std::cout << "10)Levelorder\n";
        std::cout << "11)Exit\n";
        std::cin >> choice;
        std::cout << '\n';
      }
      if(!std::cin.fail())
        break;
    }
    if(choice == 1)
    {

    }
    else if(choice == 2)
    {

    }
    else if(choice == 3)
    {

    }
    else if(choice == 4)
    {

    }
    else if(choice == 5)
    {

    }
    else if(choice == 6)
    {

    }
    else if(choice == 7)
    {

    }
    else if(choice == 8)
    {

    }
    else if(choice == 9)
    {

    }
    else if(choice == 10)
    {

    }
    else if(choice == 11)
    {
      std::cout << "Program execution complete!\n";
      break;
    }
    else
    {
      std::cout << " Wrong input!\n\n";
      std::cout << "..................................\n\n";
    }
  }
}
