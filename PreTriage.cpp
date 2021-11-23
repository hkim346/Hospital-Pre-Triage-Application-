/*
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp

Student Name: Hyunjung Kim
Student ID: 150360196
Class: OOP244NAA

Version 1.0
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/28  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstring>
#include "PreTriage.h"


using namespace std;
namespace sdds
{

	PreTriage::PreTriage(const char* dataFilename) :m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {

		delete[] m_dataFilename;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
		if (m_lineupSize == 0) {
			m_averCovidWait = 15;
			m_averTriageWait = 5;
		}
	}

	PreTriage::~PreTriage() {

		ofstream fout(m_dataFilename);
		if (fout.is_open()) {
			fout << m_averCovidWait;
			fout.put(',');
			fout << m_averTriageWait << endl;

			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;

			cout << "Saving m_lineup..." << endl;
			for (int i = 0; i < m_lineupSize; i++) {
				m_lineup[i]->csvWrite(fout) << endl;
				cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(cout) << endl;
				
			}
		}
		fout.close();
		
		for (int i = 0; i < maxNoOfPatients; i++) {
			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}

		delete[] m_dataFilename;
		cout << "done!" << endl;
	}

	void PreTriage::run(void) {
		int selection = -1;

		while (selection != 0) {
			m_appMenu >> selection;
			switch (selection)
			{
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			case 0:
				break;
			}
		}
	}

	void PreTriage::reg() {

		int selection = 0;

		if (m_lineupSize == maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {

			m_pMenu >> selection;
			if (selection == 1 || selection == 2) {

				if (selection == 1) m_lineup[m_lineupSize] = new CovidPatient();
				if (selection == 2) m_lineup[m_lineupSize] = new TriagePatient();

				m_lineup[m_lineupSize]->setArrivalTime();
				m_lineup[m_lineupSize]->fileIO(false);
				cout << "Please enter patient information: " << endl;
				cin >> *m_lineup[m_lineupSize];
				cout << endl << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;

			}
		}
	}

	void PreTriage::admit() {
		int selection = 0;
		int index = -1;

		m_pMenu >> selection;
		switch (selection)
		{
		case 1:
			index = indexOfFirstInLine('C');
			break;
		case 2:
			index = indexOfFirstInLine('T');
			break;
		case 0:
			break;
		}

		if (index >= 0) {
			cout << endl << "******************************************" << endl;
			m_lineup[index]->fileIO(false);
			cout << "Calling for " << *m_lineup[index] << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const {
		unsigned int p_num = 0;
		for (int i = 0; i < m_lineupSize; i++) {
			if (p.type() == m_lineup[i]->type()) p_num++;
		}
		return (p.type() == 'C') ? m_averCovidWait * p_num : m_averTriageWait * p_num;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time CT, PTT, AWT;
		unsigned int PTN;

		CT.setToNow();  //Current Time
		PTT = Time(p);  //Patient's Ticket Time
		PTN = p.number();  // Patient's Ticket Number

		if (p.type() == 'C') {
			AWT = unsigned(m_averCovidWait);  // Average Wait Time (Covid)
			m_averCovidWait = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		}
		else {
			AWT = unsigned(m_averTriageWait);  // Average Wait Time (Triage)
			m_averTriageWait = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		}
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		bool found = false;
		int index = -1;
		int i = 0;
		while (!found && i < m_lineupSize) {

			if (m_lineup[i]->type() == type) {
				found = true;
				index = i;
			}
			else i++;
		}
		return index;
	}

	void PreTriage::load() {
		int i = 0;
		char type = 'X';
		Patient* p = nullptr;

		cout << "Loading data..." << endl;
		ifstream fin(m_dataFilename);

		if (fin.is_open()) {
			fin >> m_averCovidWait;
			fin.ignore(); // ignore the comman
			fin >> m_averTriageWait;
			fin.ignore(); // ignore the newline

			while (i < maxNoOfPatients && fin.get(type)) {

				fin.get(); // ignore a comma;

				if (type == 'C') {
					p = new CovidPatient();
				}
				else if (type == 'T') {
					p = new TriagePatient();
				}
				if (p != nullptr) {
					p->fileIO(true);
					fin >> *p;
					p->fileIO(false);
					m_lineup[i] = p;
					m_lineupSize++;
					p = nullptr;
					i++;
				}
			}
		}
		fin.close();

		if (m_lineupSize == maxNoOfPatients) {
			cout << "Warning: number of records exceeded 100" << endl;
			cout << maxNoOfPatients << " Records imported..." << endl << endl;
		}
		else if (m_lineupSize < maxNoOfPatients && m_lineupSize != 0) cout << m_lineupSize << " Records imported..." << endl << endl;
		else cout << "No data or bad data file!" << endl << endl;
	}

}
