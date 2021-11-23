/*
Final Project Milestone 5
Module: Ticket
Filename: Ticket.h

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/17  Preliminary release (Professor provided)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"

namespace sdds
{
    class Ticket :public IOAble
    {
        Time m_time;
        int m_number;
    public:
        Ticket(int number = 0);
        operator Time()const;
        int number()const;
        void resetTime();
        std::ostream& csvWrite(std::ostream& ostr)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}
#endif // !SDDS_TICKET_H_