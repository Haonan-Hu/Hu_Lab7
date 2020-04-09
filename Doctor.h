#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor
{
public:
  Doctor(){
    d_firstName = "";
    d_lastName = "";
    d_urgency = 0;
  }
  Doctor(std::string firstName, std::string lastName, int urgency){
    d_firstName = firstName;
    d_lastName = lastName;
    d_urgency = urgency;
  }

  void setDoctorFN(std::string firstName)
  {
    d_firstName = firstName;
  }
  std::string getDoctorFN()const{
    return d_firstName;
  }

  void setDoctorLN(std::string lastName)
  {
    d_lastName = lastName;
  }
  std::string getDoctorLN()const{
    return d_lastName;
  }

  void setDoctorUrgency(int urgency)
  {
    d_urgency = urgency;
  }
  int getDoctorUrgency()const{
    return d_urgency;
  }

  bool operator<(const Doctor& rhs){
    return (this->d_urgency < rhs.d_urgency);
  }
  bool operator>(const Doctor& rhs){
    return (this->d_urgency > rhs.d_urgency);
  }
  bool operator==(const Doctor& rhs){
    return (this->d_urgency == rhs.d_urgency);
  }

  private:
  std::string d_firstName;
  std::string d_lastName;
  int d_urgency;
};
#endif
