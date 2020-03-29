#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "Patient.h"
#include <iostream>

class MaxHeap
{
public:
  MaxHeap();
  ~MaxHeap();
  void NewPatient(std::string firstName, std::string lastName, int urgency); //Add new patient to he system
  void TreatPatient(); // Remove a patient from the records
  void ChangeUrgency(); // change urgency level
  void NextPatient(); //Print next patient to be treated
  void LastPatient(); //print last patient to be treated
  void PatientToken(); //Find position of patient in the queue
  int PatientCount()const; //get heap size
  void PatientsReport(); // print all patients info
  int GetArrSize() const; //get arr size
  void clear(); // clear the array


private:
  Patient* m_arr;
  int m_arrSize;
  int m_heapSize;


  void resize(); //resize the array if needed
  void heapifying();
  void upHeap(int curIndex);
  void downHeap(int curIndex);
};
#endif
