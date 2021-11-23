/*
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/13  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds
{
	void Menu::display() const {
		cout << m_text << endl << "0- Exit" << endl;
	}

	Menu::Menu() {
		m_text = nullptr;
		m_noOfSel = 0;
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		m_text = nullptr;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
		return Selection;
	}

	Menu::Menu(const Menu& M) {
		m_noOfSel = M.m_noOfSel;
		if (M.m_text != nullptr) {
			m_text = new char[strlen(M.m_text) + 1];
			strcpy(m_text, M.m_text);
		}
		else {
			m_text = nullptr;
		}
	}
}