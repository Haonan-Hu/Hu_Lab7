#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
  m_arrSize = 100;
  m_heapSize = 0;
  m_arr = new Patient[m_arrSize];
}

MaxHeap::~MaxHeap()
{
  clear();
}

void MaxHeap::clear()
{
  delete[] m_arr;
  m_arr = nullptr;
} // clear the m_array

void MaxHeap::initalize(Patient *entry, int size)
{
  for (int i = 0; i < size; i++)
  {
    m_arr[i].setPatientFN(entry[i].getPatientFN());
    m_arr[i].setPatientLN(entry[i].getPatientLN());
    m_arr[i].setPatientUrgency(entry[i].getPatientUrgency());
    m_heapSize++;
  }
  buildHeap(m_heapSize);
}

void MaxHeap::buildHeap(int size)
{
  int index = floor((size / 3) - 1);
  for (int i = index; i >= 0; i--)
  {
      heapify(size, i);
  }
}

void MaxHeap::heapify(int size, int index)
{
  int temp = index;
  int l_child = 3 * index + 1;
  int m_child = 3 * index + 2;
  int r_child = 3 * index + 3;

  if (r_child < size && m_arr[r_child].getPatientUrgency() > m_arr[temp].getPatientUrgency())
  {
    temp = r_child;
  }
  if (m_child < size && m_arr[m_child].getPatientUrgency() > m_arr[temp].getPatientUrgency())
  {
    temp = m_child;
  }

  if (l_child < size && m_arr[l_child].getPatientUrgency() > m_arr[temp].getPatientUrgency())
  {
    temp = l_child;
  }
  if (temp != index)
  {
    std::string first = m_arr[temp].getPatientFN();
    std::string last = m_arr[temp].getPatientLN();
    int num = m_arr[temp].getPatientUrgency();
    m_arr[temp].setPatientFN(m_arr[index].getPatientFN());
    m_arr[temp].setPatientLN(m_arr[index].getPatientLN());
    m_arr[temp].setPatientUrgency(m_arr[index].getPatientUrgency());
    m_arr[index].setPatientFN(first);
    m_arr[index].setPatientLN(last);
    m_arr[index].setPatientUrgency(num);

    heapify(size, temp);
  }
}

void MaxHeap::downheap(int index)
{
  int temp = index;
  int l_child = 3 * index + 1;
  int m_child = 3 * index + 2;
  int r_child = 3 * index + 3;
  if (r_child < m_heapSize && m_arr[r_child].getPatientUrgency() > m_arr[temp].getPatientUrgency())
  {
    temp = r_child;
  }

  if (m_child < m_heapSize && m_arr[m_child].getPatientUrgency() > m_arr[temp].getPatientUrgency())
  {
    temp = m_child;
  }

  if (l_child < m_heapSize && m_arr[l_child].getPatientUrgency() > m_arr[temp].getPatientUrgency())
  {
    temp = l_child;
  }
  if (temp != index)
  {
    std::string first = m_arr[temp].getPatientFN();
    std::string last = m_arr[temp].getPatientLN();
    int num = m_arr[temp].getPatientUrgency();
    m_arr[temp].setPatientFN(m_arr[index].getPatientFN());
    m_arr[temp].setPatientLN(m_arr[index].getPatientLN());
    m_arr[temp].setPatientUrgency(m_arr[index].getPatientUrgency());
    m_arr[index].setPatientFN(first);
    m_arr[index].setPatientLN(last);
    m_arr[index].setPatientUrgency(num);

    downheap(temp);
  }
}

void MaxHeap::insert(std::string firstName, std::string lastName, int priority)
{
  int x = m_heapSize + 1;
  if (m_arrSize < x)
  {
    throw(std::runtime_error("failed to insert, surpass the large size"));
  }
  else
  {
    m_arr[m_heapSize].setPatientFN(firstName);
    m_arr[m_heapSize].setPatientLN(lastName);
    m_arr[m_heapSize].setPatientUrgency(priority);
    m_heapSize++;
    buildHeap(m_heapSize);
  }
}

bool MaxHeap::check_duplicate(std::string firstName, std::string lastName)
{
  bool flag = false;
  for (int i = 0; i < m_heapSize; i++)
  {
    if (m_arr[i].getPatientFN() == firstName && m_arr[i].getPatientLN() == lastName)
    {
      flag = true;
    }
  }
  return flag;
}

void MaxHeap::treat()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("empty patients in heap"));
  }
  else
  {
    m_arr[0].setPatientFN(m_arr[m_heapSize - 1].getPatientFN());
    m_arr[0].setPatientLN(m_arr[m_heapSize - 1].getPatientLN());
    m_arr[0].setPatientUrgency(m_arr[m_heapSize - 1].getPatientUrgency());
    m_arr[m_heapSize - 1].setPatientFN("");
    m_arr[m_heapSize - 1].setPatientLN("");
    m_arr[m_heapSize - 1].setPatientUrgency(0);
    m_heapSize--;
    downheap(0);
  }
}

void MaxHeap::change_urgency(std::string firstName,std::string lastName,int priority)
{
  bool flag = false;
  int index;
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("heap is empty"));
  }
  else
  {
    for (int i = 0; i < m_heapSize; i++)
    {
      if (m_arr[i].getPatientFN() == firstName && m_arr[i].getPatientLN() == lastName)
      {
        flag = true;
        index = i;
      }
    }
  }
  if (!flag)
  {
    throw(std::runtime_error("patient not found!"));
  }
  else
  {
    m_arr[index].setPatientFN(m_arr[m_heapSize - 1].getPatientFN());
    m_arr[index].setPatientLN(m_arr[m_heapSize - 1].getPatientLN());
    m_arr[index].setPatientUrgency(m_arr[m_heapSize - 1].getPatientUrgency());
    m_arr[m_heapSize - 1].setPatientFN("");
    m_arr[m_heapSize - 1].setPatientLN("");
    m_arr[m_heapSize - 1].setPatientUrgency(0);
    m_heapSize--;
    insert(firstName, lastName, priority);
  }
}

std::string MaxHeap::next_patient()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("heap is empty"));
  }
  std::string output = m_arr[0].getPatientFN() + ", ";
  output = output + m_arr[0].getPatientLN() + ", ";
  output = output + std::to_string(m_arr[0].getPatientUrgency());
  return output;
}

std::string MaxHeap::last_patient()
{
  int lower = m_arr[0].getPatientUrgency();
  int index = 0;
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("heap is empty"));
  }
  for (int i = 0; i < m_heapSize; i++)
  {
      if (m_arr[i].getPatientUrgency() < lower)
      {
        lower = m_arr[i].getPatientUrgency();
        index = i;
      }
  }
  std::string output = m_arr[index].getPatientFN() + ", ";
  output = output + m_arr[index].getPatientLN() + ", ";
  output = output + std::to_string(m_arr[index].getPatientUrgency());
  return output;
}

int MaxHeap::patient_token(std::string firstName,std::string lastName)
{
  bool flag = false;
  int out = -1;
  for (int i = 0; i < m_heapSize; i++)
  {
    if (m_arr[i].getPatientFN() == firstName && m_arr[i].getPatientLN() == lastName)
    {
      flag = true;
      out = i;
      break;
    }
  }
  if (!flag)
  {
    throw(std::runtime_error("patient not found!"));
  }
  return out + 1;
}

int MaxHeap::getHeapSize()
{
  return m_heapSize;
}

void MaxHeap::patient_report()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("heap is empty"));
  }
  else
  {
    for (int i = 0; i < m_heapSize; i++)
    {
      std::string output = "";
      output = m_arr[i].getPatientLN() + ", ";
      output = output + m_arr[i].getPatientFN() + ", ";
      output = output + std::to_string(m_arr[i].getPatientUrgency());
      std::cout << output << '\n';
    }
  }
}

std::string MaxHeap::search(std::string firstName,std::string lastName)
{
  bool flag = false;
  std::string output = "";
  for (int i = 0; i < m_heapSize; i++)
  {
    if (m_arr[i].getPatientFN() == firstName && m_arr[i].getPatientLN() == lastName)
    {
      output = m_arr[i].getPatientFN() + ", ";
      output = output + m_arr[i].getPatientLN() + ", ";
      output = output + std::to_string(m_arr[i].getPatientUrgency());
      flag = true;
      break;
    }
  }
  if (!flag)
  {
    throw(std::runtime_error("patient not found!"));
  }
  return output;
}
