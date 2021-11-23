/*
Final Project Milestone 5
Module: Patient
Filename: Patient.h

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/17  Preliminary release
2021/7/24  line 48-51: Update member functions as Virtual functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "Ticket.h"
#include "Time.h"
#include "IOAble.h"
#include "utils.h"

namespace sdds{
	class Patient : public IOAble {
		char* p_name;  // to hold the name of the patient in a Cstring dynamically.
		int p_OHIP_num;  //to hold the OHIP insurance number (exactly 9 digits) of the patient.
		Ticket p_ticket; //to hold the ticket of the patient for the lineup.
		bool p_fileIO; // true if reading from a file, false if reading from console.

	public:
		Patient(int ticketNumber = 0, bool fileIO = false);
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool fileIO);
		bool operator==(const char& C)const;
		bool operator==(const Patient& p)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;

		virtual std::ostream& csvWrite(std::ostream& ostr) const;
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
	};
}



#endif // !SDDS_PATIENT_H_
