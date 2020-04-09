/*
Author: Haonan Hu
File: Executive.h
Date:2/24/2020
Brief:File is header file
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "MaxHeap.h"
#include "MinHeap.h"
#include <fstream>

class executive
{
public:
  executive(std::string doctorFile, std::string patientFile);
  ~executive();
  /**
  * @pre none
  * @post run the user controled panel
  */
  void run();
  void doctor();
  void patient();
private:
  MaxHeap m_patient;
  MinHeap m_doctor;
};
#endif
