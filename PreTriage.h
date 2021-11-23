/*
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h

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

#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
#include "IOAble.h"
#include "Time.h"
#include "utils.h"
#include "Patient.h"
#include "Menu.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

namespace sdds
{
    const int maxNoOfPatients = 100;
    class PreTriage
    {
        Time
            m_averCovidWait,   // to hold the average wait time for COVID test per patient
            m_averTriageWait;  // to hold the average wait time for Triage per patient
        Patient* m_lineup[maxNoOfPatients]{};  // An array of Patient pointers to hold COVID and Triage Patient lineups dynamically
        char* m_dataFilename = nullptr;   // A character pointer to hold the name of the data file dynamically
        int m_lineupSize = 0;  // Number of Patients in the lineup
        Menu
            m_appMenu,  // Menu object to hold the main menu.
            m_pMenu;  // Menu object to hold the COVID/Triage patient selection.
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run(void);
    };
}


#endif // !SDDS_PRETRIAGE_H_


