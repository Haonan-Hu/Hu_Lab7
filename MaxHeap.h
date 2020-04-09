#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "Patient.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

class MaxHeap
{
private:
Patient *m_arr;
int m_arrSize;
int m_heapSize;

public:
MaxHeap(); //done
~MaxHeap(); //done
void clear(); //done
void initalize(Patient*entry, int size); //done
void insert(std::string firstName,std::string lastName,int priority); //done
void treat(); //done
void change_urgency(std::string firstName,std::string lastName,int priority); //done
std::string next_patient(); //done
std::string last_patient(); //done
int patient_token(std::string firstName,std::string lastName); //done
int getHeapSize(); //done
void patient_report(); //done
std::string search(std::string firstName,std::string lastName);
bool check_duplicate(std::string firstName,std::string lastName); //done
void heapify(int size,int index); //done
void buildHeap(int size); //done
void downheap(int index); //done

};
#endif
