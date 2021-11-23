/*
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.h

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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds{

	class CovidPatient : public Patient {

	public:
		CovidPatient();
		virtual char type()const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_COVIDPATIENT_H_



