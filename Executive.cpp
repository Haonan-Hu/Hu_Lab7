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

  std::ifstream infile1;
  input="";
  infile1.open(doctorFile);
  if (infile1.is_open())
  {
    int count = 0;
    Doctor *arr;
    while (infile1 >> input)
    {
      size_t one = input.find(",");
      std::string first = input.substr(0, one);
      input.erase(0, first.size() + 1);
      size_t two = input.find(",");
      std::string last = input.substr(0, two);
      input.erase(0, last.size() + 1);
      int num = stoi(input);
      if(num<0 && num>25)
      {
        std::cout<<"unable to creat list!" << '\n';
        throw(std::runtime_error("failed"));
      }
      count++;
      Doctor *temp = new Doctor[count];
      for (int i = 0; i < count - 1; i++)
      {
        temp[i].setDoctorFN(arr[i].getDoctorFN());
        temp[i].setDoctorLN(arr[i].getDoctorLN());
        temp[i].setDoctorUrgency(arr[i].getDoctorUrgency());
      }
      temp[count - 1].setDoctorFN(first);
      temp[count - 1].setDoctorLN(last);
      temp[count - 1].setDoctorUrgency(num);

      if (count > 1)
      {
        delete[] arr;
      }
      arr = temp;
    }
    m_doctor.initalize(arr, count);
    delete[] arr;
    infile.close();
    std::cout << "\e[1mDoctor File reading done, ready for next step:\e[0m\n";
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
  bool flag = true;
  while (flag)
  {
    int choice;
    std::cout << "------------------------------------------ Doctor Assignment System -------------------------------------" << '\n';
    std::cout << "1. New Doctor" << '\n';
    std::cout << "2. Update Patients" << '\n';
    std::cout << "3. Remove Doctor" << '\n';
    std::cout << "4. Next Available Doctor" << '\n';
    std::cout << "5. Check Availability" << '\n';
    std::cout << "6. Total Doctor Count" << '\n';
    std::cout << "7. Available Doctor Count" << '\n';
    std::cout << "8. Available Doctors Report" << '\n';
    std::cout << "9. Busy Doctors List" << '\n';
    std::cout << "10. Go Back to Menu" << '\n';
    std::cout<<"Please choose your option"<< '\n';
    std::cin >> choice;
    if(choice==1)
    {
      std::string first;
      std::string last;
      std::cout<<"Enter doctor details:"<< '\n';
      std::cout << "First name: " ;
      std::cin >> first;
      std::cout << "Last name: ";
      std::cin >> last;
      if (!m_doctor.check_duplicate(first, last))
      {
        try
        {
          m_doctor.insert(first, last, 0);
          std::cout << "A new doctor is added and available." << '\n';
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
    if(choice==2)
    {
      std::string first;
      std::string last;
      int op;
      std::cout<<"Enter the doctor’s details to update the patient count:"<< '\n';
      std::cout << "First name: " ;
      std::cin >> first;
      std::cout << "Last name: ";
      std::cin >> last;
      try
      {
        int x = m_doctor.patient_count(first,last);
        std::cout << "Current patient count:  "<< x << '\n';
        std::cout << "Select 1 to add patients or 0 to reduce patients: ";
        std::cin >> op;
        while(op > 1 || op < 0)
        {
          std::cout << "selection failed try again !";
          std::cout << "Select 1 to add patients or 0 to reduce patients: ";
          std::cin >> op;
        }
        if(op == 0)
        {
          std::cout << "Enter the updated count: "<< '\n';
          std::cin >> op;
          if(op < x)
          {
            m_doctor.change_patient_C(first,last,op);
            std::cout<<"The doctor’s record is updated."<< '\n';
          }
          else
          {
            std::cout<<"Failed, value surpass the original patient count"<< '\n';
          }
        }
        else
        {
          std::cout << "Enter the updated count: "<< '\n';
          std::cin >> op;
          if(op > x)
          {
            m_doctor.change_patient_C(first,last,op);
            std::cout << "The doctor’s record is updated."<< '\n';
          }
          else
          {
            std::cout<<"Failed, value less than the original patient count"<<'\n';
          }
        }
      }
      catch(std::runtime_error& rte)
      {
        std::cout<< rte.what() << '\n';
      }
    }
    if(choice==3)
    {
      try
      {
       m_doctor.remove_d();
       std::cout<<"The doctor with the lowest patient count has been removed."<<'\n';
      }
      catch(std::runtime_error& e)
      {
        std::cout<< e.what() << '\n';
      }
    }
    if(choice==4)
    {
      std::cout<<"Next Doctor available: "<< m_doctor.next_doc() <<'\n';
    }
    if(choice==5)
    {
      std::string first;
      std::string last;

      std::cout << "Enter doctor details to check availability:"<<'\n';
      std::cout << "First name: " ;
      std::cin >> first;
      std::cout << "Last name: ";
      std::cin >> last;
      try
      {
        if(m_doctor.check_avaliable(first,last))
        {
          std::cout<<"This doctor is avaliable"<<'\n';
        }
        else
        {
          std::cout<<"This doctor is not avaliable"<<'\n';
        }
      }
      catch(std::runtime_error& rte)
      {
        std::cout<< rte.what() << '\n';
      }
    }
    if(choice==6)
    {
      std::cout<<"There are " << m_doctor.totaldoc() << " total doctors" << '\n';
    }
    if(choice==7)
    {
      std::cout<<"There are "<<m_doctor.totalavaliable()<<" doctors available"<<'\n';
    }
    if(choice==8)
    {
      m_doctor.avaliable_report();
    }
    if(choice==9)
    {
      m_doctor.busy_report();
    }
    if (choice == 10)
    {
      std::cout << "..................................\n\n";
      flag = false;
    }
  }
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
