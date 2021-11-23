/*
Final Project Milestone 5
Module: utils
Filename: utils.cpp

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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   
   int getInt(const char* prompt){

       int IntNum;
       bool valid = false;
       char newline = 'x';
      
       if (prompt != nullptr)  cout << prompt;
 

       do {
           cin >> IntNum;

           if (cin) {
               cin.get(newline);
               if (newline == '\n')  valid = true;

               else if (newline != '\n') {
                   cin.clear();
                   cin.ignore(2000, '\n');
                   cout << "Enter only an integer, try again: ";
               }
           }
           else {
               cin.clear();
               cin.ignore(2000, '\n');
               cout << "Bad integer value, try again: ";
           }
       } while (!valid);

    return IntNum;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
       
       bool valid = false;
       int IntNum = 0;
       IntNum = getInt(prompt);

       do {
           if (IntNum >= min && IntNum <= max) valid = true;
           else {
               IntNum = 0;
               if (errorMessage != nullptr && showRangeAtError) {
                   cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
                   IntNum = getInt();
               }
               if (errorMessage != nullptr && !showRangeAtError) {
                   cout << errorMessage;
                   IntNum = getInt();
               }
           }
       }while (!valid);

       return IntNum;
   }
   
   char* getcstr(const char* prompt, std::istream& istr, char delimiter){

       char temp[2000] = { '\0' };

       if (prompt != nullptr) cout << prompt;

       istr.get(temp, 2000, delimiter);
       
       char* des = new char[strlen(temp) + 1];
       strcpy(des, temp);
  
       return des;
   }
}