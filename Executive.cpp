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

executive::executive(std::string doctorFile, std::string patientFile)
{
  std::ifstream infile;
  std::string input;
  infile.open(patientFile);
  if (infile.is_open())
  {
      int count = 0;
      Patient *arr;
      while (infile >> input)
      {
          size_t one = input.find(",");
          std::string first = input.substr(0, one);
          input.erase(0, first.size() + 1);
          size_t two = input.find(",");
          std::string last = input.substr(0, two);
          input.erase(0, last.size() + 1);
          int priority = stoi(input);
          count++;
          Patient *temp = new Patient[count];
          for (int i = 0; i < count - 1; i++)
          {
              temp[i].setPatientFN(arr[i].getPatientFN());
              temp[i].setPatientLN(arr[i].getPatientLN());
              temp[i].setPatientUrgency(arr[i].getPatientUrgency());
          }
          temp[count - 1].setPatientFN(first);
          temp[count - 1].setPatientLN(last);
          temp[count - 1].setPatientUrgency(priority);
          // std::std::cout << first << ' ' << last << ' ' << priority << '\n';
          if (count > 1)
          {
              delete[] arr;
          }
          arr = temp;
      }
      m_patient.initalize(arr, count);
      delete[] arr;
      infile.close();
      std::cout << "\e[1mPatient File reading done, ready for next step:\e[0m\n";
      std::cout << "..................................\n\n";
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){}

void executive::run()
{
  bool flag = true;
  while (flag)
  {
    int choice;
    std::cout << "-------------Hospital Patient & Doctor Management System-----------" << '\n';
    std::cout << "1. Patient Management" << '\n';
    std::cout << "2. Doctor Assignment" << '\n';
    std::cout << "3. Exit" << '\n';
    std::cin >> choice;
    if (choice == 1)
    {
      patient();
    }
    if (choice == 2)
    {
      doctor();
    }
    if (choice == 3)
    {
      std::cout << "Program execution complete!\n";
      std::cout << "..................................\n\n";
      flag = false;
    }
  }
}

void executive::doctor()
{

}

void executive::patient()
{
  bool flag = true;
  while (flag)
  {
    int choice;
    std::cout << "---------------- Patient Management System ----------------------" << '\n';
    std::cout << "1. New Patient" << '\n';   //finished
    std::cout << "2. Treat Patient" << '\n'; //finished
    std::cout << "3. Change Urgency" << '\n';
    std::cout << "4. Next Patient" << '\n'; //finished
    std::cout << "5. Last Patient" << '\n';
    std::cout << "6. Patient Token" << '\n';
    std::cout << "7. Patient Count" << '\n'; //finished
    std::cout << "8. Patient Report" << '\n';
    std::cout << "9. Go Back to Menu" << '\n'; //finished
    std::cout << '\n';
    std::cout << "Please choose your option:" << '\n';
    std::cin >> choice;
    if (choice == 1)
    {
        std::string first;
        std::string last;
        int num;
        std::cout << "Enter Patient’s First name:" << '\n';
        std::cin >> first;
        std::cout << "Enter Patient’s Last name:" << '\n';
        std::cin >> last;
        std::cout << "Enter Patient’s Urgency:" << '\n';
        std::cin >> num;
        if (!m_patient.check_duplicate(first, last))
        {
          try
          {
            m_patient.insert(first, last, num);
            std::cout << "New Patient record added" << '\n';
          }
          catch (std::runtime_error &rte)
          {
            std::cout << rte.what() << '\n';
          }
        }
        else
        {
          std::cout << "Duplicate detected, add patient failed" << '\n';
        }
    }
    if (choice == 2)
    {
      try
      {
        std::string p = m_patient.next_patient();
        m_patient.treat();
        std::cout << "High priority patient successfully treated. Below are the details:" << '\n';
        std::cout << p << '\n';
      }
      catch (std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
      }
    }
    if (choice == 3)
    {
      std::string first;
      std::string last;
      int num;
      std::cout << "Enter the patient details to change the urgency:" << '\n';
      std::cout << "First name: ";
      std::cin >> first;
      std::cout << "Last name: ";
      std::cin >> last;
      try
      {
        std::cout << "Current details of this patient are: " << m_patient.search(first, last) << '\n';
        std::cout << "Enter new urgency level: ";
        std::cin >> num;
        m_patient.change_urgency(first, last, num);
        std::cout << "The patient record is updated." << '\n';
      }
      catch (const std::exception &rte)
      {
        std::cerr << rte.what() << '\n';
      }
    }
    if (choice == 4)
    {
      std::cout << "Next patient: " << m_patient.next_patient() << '\n';
    }
    if (choice == 5)
    {
      std::cout << "Last patient details: " << m_patient.last_patient() << '\n';
    }
    if (choice == 6)
    {
      std::string first;
      std::string last;
      std::cout << "Enter details of patient:" << '\n';
      std::cout << "First name:" ;
      std::cin >> first;
      std::cout << "Last name:" ;
      std::cin >> last;

      try
      {
        int token = m_patient.patient_token(first, last);
        std::cout << "Patient token: " << token << '\n';
      }
      catch (std::runtime_error &e)
      {
        std::cout << e.what() << '\n';
      }
    }
    if (choice == 7)
    {
      std::cout << "Current patient count is: " << m_patient.getHeapSize() << '\n';
    }
    if (choice == 8)
    {
      std::cout << "Current Patients report:" << '\n';
      try
      {
        m_patient.patient_report();
      }
      catch (std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
      }
    }
    if (choice == 9)
    {
      std::cout << "..................................\n\n";
      flag = false;
    }
  }
}
