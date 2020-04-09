#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "Doctor.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

class MinHeap
{
private:
Doctor *m_arr;
int m_arrSize;
int m_heapSize;

public:
MinHeap();
~MinHeap();
void clear();
void initalize(Doctor *entry,int size);
void insert(std::string firstName,std::string lastName,int priority);
void heapify(int size,int index);
void remove_d();
bool search(std::string firstName,std::string lastName);
int patient_count(std::string firstName,std::string lastName);
bool check_duplicate(std::string firstName,std::string lastName);
bool check_avaliable(std::string firstName,std::string lastName);
void change_patient_C(std::string firstName,std::string lastName,int priority);
int totaldoc();
int totalavaliable();
void avaliable_report();
void busy_report();
std::string next_doc();
void buildheap(int size);
void downheap(int partents);
void pritall();
};
#endif
