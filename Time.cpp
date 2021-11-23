/* 
Final Project Milestone 5
Module: Time
Filename: Time.cpp

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/6  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

	Time& Time::setToNow(){
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min){
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const{
		unsigned int hh = 0;
		unsigned int mm = 0;

		hh = m_min / 60;
		mm = m_min % 60;
		
		ostr.fill('0');
		ostr.width(2);
		ostr << hh;
		

		ostr << ":";
		ostr.width(2);
		ostr << mm;

		ostr.fill(' ');
		return ostr;
	}

	std::istream& Time::read(std::istream& istr){
		int temp_hh = 0;
		int temp_mm = 0;
		char del = '\0';

		istr >> temp_hh;
		if (temp_hh < 0) istr.setstate(ios::failbit);

		istr >> del;
		if (del != ':') istr.setstate(ios::failbit);

		istr >> temp_mm;
		if (temp_mm < 0) istr.setstate(ios::failbit);
		
		this->m_min = temp_hh * 60 + temp_mm;
		return istr;
	}

	Time& Time::operator-=(const Time& D){
		
		if (this->m_min > D.m_min) this->m_min = this->m_min - D.m_min;

		else if (this->m_min < D.m_min) this->m_min = this->m_min - D.m_min + (1440 * (int)((D.m_min / 1440) + 1));

		return *this;
	}

	Time Time::operator-(const Time& D) const{
		Time temp;

		if (this->m_min > D.m_min) temp.m_min = this->m_min - D.m_min;

		else if (this->m_min < D.m_min) temp.m_min = this->m_min - D.m_min + (1440 * (int)((D.m_min / 1440) + 1));

		return temp;
	}

	Time& Time::operator+=(const Time& D){
		this->m_min = this->m_min + D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const{
		Time temp;
		temp.m_min = this->m_min + D.m_min;
		return temp;
	}

	Time& Time::operator=(unsigned int val){
		this->m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val){
		this->m_min = this->m_min * val;
		return *this;
	}

	Time& Time::operator/=(unsigned int val){
		this->m_min = this->m_min / val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const{
		Time temp(this->m_min * val);
		return temp;
	}

	Time Time::operator/(unsigned int val) const{
		Time temp(this->m_min / val);
		return temp;
	}

	Time::operator int() const{
		return (int)m_min;
	}

	Time::operator unsigned int() const{
		return (unsigned) m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D){
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D){
		D.read(istr);
		return istr;
	}
}
