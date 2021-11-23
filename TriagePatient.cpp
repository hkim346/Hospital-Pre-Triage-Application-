/*
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/24  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "TriagePatient.h"

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient():Patient(nextTriageTicket){
	   m_sysptoms = nullptr;
	   nextTriageTicket++;
   }

   TriagePatient::~TriagePatient(){
	   delete[] m_sysptoms;
   }

   char TriagePatient::type() const{
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const{
	   Patient::csvWrite(ostr) << "," << m_sysptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr){
	   string temp;
	   Patient::csvRead(istr);
	   istr.get();  //extracts a single character comma

	   //read sysptoms
	   getline(istr, temp, '\n');
	   istr.clear();
	   delete[] m_sysptoms;
	   m_sysptoms = new char[strlen(temp.c_str()) + 1];
	   strcpy(m_sysptoms, temp.c_str());
	   
	   //set 'nextTriageTicket' gloval variable
	   nextTriageTicket = Patient::number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const{
	   if (fileIO()) csvWrite(ostr);
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr) << endl;
		   ostr << "Symptoms: " << m_sysptoms << endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr){
	   string temp;

	   if (fileIO())  csvRead(istr);
	   else {
		   Patient::read(istr);

		   //read sysptoms
		   cout << "Symptoms: ";   
		   getline(istr, temp, '\n');
		   istr.clear();
		   delete[] m_sysptoms;
		   m_sysptoms = new char[strlen(temp.c_str()) + 1];
		   strcpy(m_sysptoms, temp.c_str());
	   }

	   return istr;
   }

}