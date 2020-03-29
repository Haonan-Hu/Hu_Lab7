#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
  m_arrSize = 2;
  m_heapSize = 0;
  m_arr = new Patient[2];
}

MaxHeap::~MaxHeap()
{
  clear();
}

void MaxHeap::NewPatient(Patient patient)
{
  if(m_arrSize == m_heapSize)
  {
    resize();
  }
  m_heapSize++;
  m_arr[m_heapSize - 1] = patient;
} //Add new patient to he system

void MaxHeap::TreatPatient()
{

} // Remove a patient from the records

void MaxHeap::ChangeUrgency()
{

} // change urgency level

void MaxHeap::NextPatient()
{

} //Print next patient to be treated

void MaxHeap::LastPatient()
{

} //print last patient to be treated

void MaxHeap::PatientToken()
{

} //Find position of patient in the queue

int MaxHeap::PatientCount()const
{
  return m_heapSize;
}//get heap size

void MaxHeap::PatientsReport()
{

} // print all patients info

int MaxHeap::GetArrSize() const
{
  return m_arrSize;
} //get arr size

void MaxHeap::clear()
{
  delete[] m_arr;
  m_arr = nullptr;
} // clear the array

void MaxHeap::resize()
{
  int newSize = m_arrSize * 2;
  Patient* temp = new Patient[newSize];
  for(int i = 0; i < newSize; i++)
  {
    temp[i] = m_arr[i];
  }
  m_arrSize = newSize;
  delete[] m_arr;
  m_arr = temp;
} //resize the array if needed

void MaxHeap::heapifying()
{
  for(int i = m_arrSize -1 ; i >= 0; i--)
  {
    upHeap(i);
  }
}

void MaxHeap::upHeap(int curIndex)
{
  if(curIndex > 0)
  {
    int parent = (curIndex - 1) / 3;
    if(parent < m_heapSize && curIndex < m_heapSize)
    {
      if(m_arr[parent] > m_arr[curIndex])
      {
        std::swap(m_arr[parent], m_arr[curIndex]);
        upHeap(parent);
      }
    }
  }
}

void MaxHeap::downHeap(int curIndex)
{
  // int leftChild = (3 * curIndex) + 1;
  // int middleChild = (3 * curIndex) + 2;
  // int rightChild = (3 * curIndex) + 3;
}
