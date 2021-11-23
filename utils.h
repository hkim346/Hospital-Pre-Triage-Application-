/*
Final Project Milestone 5
Module: utils
Filename: utils.h

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


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files which include: "utils.h"
         
   int getTime(); // returns the time of day in minutes
  
   int getInt(
       const char* prompt = nullptr   // User entry prompt
   );
   
   int getInt(
       int min,   // minimum acceptable value
       int max,   // maximum acceptable value
       const char* prompt = nullptr,  // User entry prompt
       const char* errorMessage = nullptr, // Invalid value error message
       bool showRangeAtError = true    // display the range if invalud value entered 
   );

   char* getcstr(
       const char* prompt = nullptr,   // User entry prompt
       std::istream& istr = std::cin,  // the Stream to read from
       char delimiter = '\n'    // Delimiter to mark the end of data
   );
   
   template <typename type>
   void removeDynamicElement(type* array[], int index, int& size) {
       delete array[index];
       for (int j = index; j < size; j++) {
           array[j] = array[j + 1];
       }
       size--;
   }
}
#endif // !SDDS_UTILS_H_

