/*
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/12  Preliminary release
2021/7/17  Remove namespace std, and parameter name
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

namespace sdds{
	class IOAble{
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() {};
	};

	std::ostream& operator<<(std::ostream& ostr, const IOAble& i);
	std::istream& operator>>(std::istream& istr, IOAble& i);
}

#endif // !SDDS_IOABLE_H

