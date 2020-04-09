#include "MinHeap.h"

MinHeap::MinHeap()
{
  m_arrSize = 100;
  m_heapSize = 0;
  m_arr = new Doctor[m_arrSize];
}

MinHeap::~MinHeap()
{
  clear();
}

void MinHeap::clear()
{
  delete[] m_arr;
  m_arr = nullptr;
} // clear the m_m_array

void MinHeap::initalize(Doctor *entry, int size)
{
  for (int i = 0; i < size; i++)
  {
    m_arr[i].setDoctorFN(entry[i].getDoctorFN());
    m_arr[i].setDoctorLN(entry[i].getDoctorLN());
    m_arr[i].setDoctorUrgency(entry[i].getDoctorUrgency());
    m_heapSize++;
  }
  buildheap(m_heapSize);
}
void MinHeap::remove_d()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("failed to treat, empty patients in heap"));
  }
  else
  {
    m_arr[0].setDoctorFN(m_arr[m_heapSize - 1].getDoctorFN());
    m_arr[0].setDoctorLN(m_arr[m_heapSize - 1].getDoctorLN());
    m_arr[0].setDoctorUrgency(m_arr[m_heapSize - 1].getDoctorUrgency());
    m_arr[m_heapSize - 1].setDoctorFN("");
    m_arr[m_heapSize - 1].setDoctorLN("");
    m_arr[m_heapSize - 1].setDoctorUrgency(0);
    m_heapSize--;
    downheap(0);
  }
}
void MinHeap::insert(std::string first, std::string last, int num)
{
  int x = m_heapSize + 1;
  if (m_arrSize < x)
  {
    throw(std::runtime_error("failed to insert, surpass the large size"));
  }
  else
  {
    m_arr[m_heapSize].setDoctorFN(first);
    m_arr[m_heapSize].setDoctorLN(last);
    m_arr[m_heapSize].setDoctorUrgency(num);
    m_heapSize++;
    buildheap(m_heapSize);
  }
}
void MinHeap::heapify(int size, int index)
{
  int partent = index;
  int one_c = 3 * index + 1;
  int two_c = 3 * index + 2;
  int three_c = 3 * index + 3;

  if (three_c < size && m_arr[three_c].getDoctorUrgency() < m_arr[partent].getDoctorUrgency())
  {
    partent = three_c;
  }
  if (two_c < size && m_arr[two_c].getDoctorUrgency() < m_arr[partent].getDoctorUrgency())
  {
    partent = two_c;
  }

  if (one_c < size && m_arr[one_c].getDoctorUrgency() < m_arr[partent].getDoctorUrgency())
  {
    partent = one_c;
  }
  if (partent != index)
  {
    std::string first = m_arr[partent].getDoctorFN();
    std::string last = m_arr[partent].getDoctorLN();
    int num = m_arr[partent].getDoctorUrgency();
    m_arr[partent].setDoctorFN(m_arr[index].getDoctorFN());
    m_arr[partent].setDoctorLN(m_arr[index].getDoctorLN());
    m_arr[partent].setDoctorUrgency(m_arr[index].getDoctorUrgency());
    m_arr[index].setDoctorFN(first);
    m_arr[index].setDoctorLN(last);
    m_arr[index].setDoctorUrgency(num);

    heapify(size, partent);
  }
}
void MinHeap::buildheap(int size)
{
  int index = floor((size / 3));
  for (int i = index; i >= 0; i--)
  {
    heapify(size, i);
  }
}
std::string MinHeap::next_doc()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("faild,heap is empty"));
  }
  std::string output = m_arr[0].getDoctorFN() + ", ";
  output = output + m_arr[0].getDoctorLN() + ", ";

  return output;
}
bool MinHeap::check_duplicate(std::string first, std::string last)
{
  bool flag = false;
  for (int i = 0; i < m_heapSize; i++)
  {
    if (m_arr[i].getDoctorFN() == first && m_arr[i].getDoctorLN() == last)
    {
      flag = true;
    }
  }
  return flag;
}
void MinHeap::downheap(int index)
{
  int partent = index;
  int one_c = 3 * index + 1;
  int two_c = 3 * index + 2;
  int three_c = 3 * index + 3;
  if (three_c < m_heapSize && m_arr[three_c].getDoctorUrgency() < m_arr[partent].getDoctorUrgency())
  {
    partent = three_c;
  }

  if (two_c < m_heapSize && m_arr[two_c].getDoctorUrgency() < m_arr[partent].getDoctorUrgency())
  {
    partent = two_c;
  }

  if (one_c < m_heapSize && m_arr[one_c].getDoctorUrgency() < m_arr[partent].getDoctorUrgency())
  {
    partent = one_c;
  }
  if (partent != index)
  {
    std::string first = m_arr[partent].getDoctorFN();
    std::string last = m_arr[partent].getDoctorLN();
    int num = m_arr[partent].getDoctorUrgency();
    m_arr[partent].setDoctorFN(m_arr[index].getDoctorFN());
    m_arr[partent].setDoctorLN(m_arr[index].getDoctorLN());
    m_arr[partent].setDoctorUrgency(m_arr[index].getDoctorUrgency());
    m_arr[index].setDoctorFN(first);
    m_arr[index].setDoctorLN(last);
    m_arr[index].setDoctorUrgency(num);

    downheap(partent);
  }
}
void MinHeap::pritall()
{
  std::cout << "heap_size" << m_heapSize << '\n';
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("faild,heap is empty"));
  }
  else
  {
    for (int i = 0; i < m_heapSize; i++)
    {
      std::string output = "";
      output = m_arr[i].getDoctorLN() + ", ";
      output = output + m_arr[i].getDoctorFN() + ", ";
      output = output + std::to_string(m_arr[i].getDoctorUrgency());
      std::cout << output << '\n';
    }
  }
}
bool MinHeap::check_avaliable(std::string first, std::string last)
{
  bool flag = false;
  bool flag2 = false;
  if (m_heapSize == 0)
  {
      throw(std::runtime_error("faild,heap is empty"));
  }
  else
  {
    for (int i = 0; i < m_heapSize; i++)
    {
      std::string output = "";
      if (m_arr[i].getDoctorFN() == first && m_arr[i].getDoctorLN() == last)
      {
        flag2 = true;
        if (m_arr[i].getDoctorUrgency() < 22)
        {
          flag = true;
        }
      }
    }
    if (!flag2)
    {
      throw(std::runtime_error("MinHeap record not found!"));
    }
  }
  return flag;
}
int MinHeap::totaldoc()
{
  return m_heapSize;
}
int MinHeap::totalavaliable()
{
  int out = 0;
  for (int i = 0; i < m_heapSize; i++)
  {
    std::string output = "";

    if (m_arr[i].getDoctorUrgency() < 22)
    {
      out++;
    }
  }
  return out;
}
void MinHeap::avaliable_report()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("faild,heap is empty"));
  }
  else
  {
    for (int i = 0; i < m_heapSize; i++)
    {
      std::string output = "";
      if (m_arr[i].getDoctorUrgency() < 22)
      {
        output = m_arr[i].getDoctorFN() + ", ";
        output = output + m_arr[i].getDoctorLN() + ", ";
        output = output + std::to_string(m_arr[i].getDoctorUrgency());
        std::cout << output << '\n';
      }
    }
  }
}
void MinHeap::busy_report()
{
  if (m_heapSize == 0)
  {
    throw(std::runtime_error("faild,heap is empty"));
  }
  else
  {
    for (int i = 0; i < m_heapSize; i++)
    {
      std::string output = "";
      if (m_arr[i].getDoctorUrgency() >= 22)
      {
        output = m_arr[i].getDoctorFN() + ", ";
        output = output + m_arr[i].getDoctorLN() + ", ";
        output = output + std::to_string(m_arr[i].getDoctorUrgency());
        std::cout << output << '\n';
      }
    }
  }
}
bool MinHeap::search(std::string first, std::string last)
{
  bool flag = false;
  for (int i = 0; i < m_heapSize; i++)
  {
    if (m_arr[i].getDoctorFN() == first && m_arr[i].getDoctorLN() == last)
    {
      flag = true;
    }
  }
  if (!flag)
  {
    throw(std::runtime_error("MinHeap record not found!"));
  }
  return flag;
}
int MinHeap::patient_count(std::string first, std::string last)
{
  bool flag = false;
  int output = 0;
  for (int i = 0; i < m_heapSize; i++)
  {
    if (m_arr[i].getDoctorFN() == first && m_arr[i].getDoctorLN() == last)
    {
      output = m_arr[i].getDoctorUrgency();
      flag = true;
      break;
    }
  }
  if (!flag)
  {
    throw(std::runtime_error("MinHeap record not found!"));
  }
  return output;
}
void MinHeap::change_patient_C(std::string first, std::string last, int num)
{
  if (search(first, last))
  {
    int index;
    for (int i = 0; i < m_heapSize; i++)
    {
      if (m_arr[i].getDoctorFN() == first && m_arr[i].getDoctorLN() == last)
      {
        index = i;
      }
    }
    m_arr[index].setDoctorFN(m_arr[m_heapSize - 1].getDoctorFN());
    m_arr[index].setDoctorLN(m_arr[m_heapSize - 1].getDoctorLN());
    m_arr[index].setDoctorUrgency(m_arr[m_heapSize - 1].getDoctorUrgency());
    m_arr[m_heapSize - 1].setDoctorFN("");
    m_arr[m_heapSize - 1].setDoctorLN("");
    m_arr[m_heapSize - 1].setDoctorUrgency(0);
    m_heapSize--;
    insert(first, last, num);
  }
}
