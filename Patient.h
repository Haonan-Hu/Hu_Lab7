#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
public:
  Patient(){
    p_firstName = "";
    p_lastName = "";
    p_urgency = 0;
  }
  Patient(std::string firstName, std::string lastName, int urgency){
    p_firstName = firstName;
    p_lastName = lastName;
    p_urgency = urgency;
  }

  void setPatientFN(std::string firstName)
  {
    p_firstName = firstName;
  }
  std::string getPatientFN()const{
    return p_firstName;
  }

  void setPatientLN(std::string lastName)
  {
    p_lastName = lastName;
  }
  std::string getPatientLN()const{
    return p_lastName;
  }

  void setPatientUrgency(int urgency)
  {
    p_urgency = urgency;
  }
  int getPatientUrgency()const{
    return p_urgency;
  }

  bool operator<(const Patient& rhs){
    return (this->p_urgency < rhs.p_urgency);
  }
  bool operator>(const Patient& rhs){
    return (this->p_urgency > rhs.p_urgency);
  }
  bool operator==(const Patient& rhs){
    return (this->p_urgency == rhs.p_urgency);
  }

private:
  std::string p_firstName;
  std::string p_lastName;
  int p_urgency;
};
#endif
