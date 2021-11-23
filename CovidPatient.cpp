/*
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp

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

#include "CovidPatient.h"

namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() :Patient(nextCovidTicket){
	   nextCovidTicket++;
   }

   char CovidPatient::type()const{
	   return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   istr.ignore(1000, '\n');
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr)const {
	   if (fileIO()) Patient::csvWrite(ostr);
	   else {
		   ostr << "COVID TEST" << std::endl;
		   Patient::write(ostr) << std::endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr) {
	   if (fileIO()) this->csvRead(istr);
	   else Patient::read(istr);
	   return istr;
   }
}