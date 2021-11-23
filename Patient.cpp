/*
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/17  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Patient.h"

namespace sdds
{
	Patient::Patient(int ticketNumber, bool fileIO) {
		p_ticket = Ticket(ticketNumber);
		p_fileIO = fileIO;
		p_name = nullptr;
		p_OHIP_num = 0;
	}
	Patient::~Patient() {
		delete[] p_name;
		p_name = nullptr;
	}

	bool Patient::fileIO() const {
		return p_fileIO;
	}

	void Patient::fileIO(bool fileIO) {
		p_fileIO = fileIO;
	}

	bool Patient::operator==(const char& C)const {
		bool same = false;
		if (C == this->type()) same = true;
		return same;
	}
	bool Patient::operator==(const Patient& p) const {
		bool same = false;
		if (this->type() == p.type()) same = true;
		return same;
	}
	void Patient::setArrivalTime() {
		p_ticket.resetTime();
	}

	Patient::operator Time()const {
		return Time(this->p_ticket);
	}

	int Patient::number()const {
		return p_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const {
		ostr << this->type() << "," << p_name << "," << p_OHIP_num << ",";
		return p_ticket.csvWrite(ostr);
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		char name[100] = { '\0' };
		istr.get(name, 99, ',');
		istr.ignore();

		if (name[0] != '\0') {
			delete[] p_name;
			p_name = nullptr;
			p_name = new char[strlen(name) + 1];
			strcpy(p_name, name);
			istr >> p_OHIP_num;
			istr.ignore();
			p_ticket.csvRead(istr);
		}

		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const {
		p_ticket.write(ostr) << std::endl;

		printf("%.25s", p_name);
		ostr << ", OHIP: " << p_OHIP_num;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr) {
		char name[100] = { '\0' };
		bool valid = false;
		std::cout << "Name: ";
		istr.get(name, 99, '\n');
		istr.ignore();

		delete[] p_name;
		p_name = nullptr;
		p_name = new char[strlen(name) + 1];
		strcpy(p_name, name);
		std::cout << "OHIP: ";

		do {
			p_OHIP_num = 0;
			p_OHIP_num = getInt();

			if (p_OHIP_num < 100000000 || p_OHIP_num > 999999999) {
				std::cout << "Invalid OHIP Number, [100000000 <= value <= 999999999]: ";
			}
			else valid = true;
		} while (!valid);
		return istr;
	}
}