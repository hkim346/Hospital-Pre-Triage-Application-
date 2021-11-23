/*
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h

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

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {

	class TriagePatient : public Patient{
		char* m_sysptoms;    //to a dynamically allocated Cstring holding the list of the symptoms of the TriagePatient.
			
	public :
		TriagePatient();
		~TriagePatient();
		virtual char type()const;
		virtual std::ostream& csvWrite(std::ostream& ostr) const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


