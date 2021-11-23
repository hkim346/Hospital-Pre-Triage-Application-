/*
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/12  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#include "IOAble.h"

namespace sdds{

    std::ostream& operator<<(std::ostream& ostr, const IOAble& i) {
        return i.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& i) {
        return i.read(istr);
    }
}