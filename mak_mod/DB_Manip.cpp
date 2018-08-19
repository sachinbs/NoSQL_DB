/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  DB_Manip.cpp:   Test-stub to check various functionalities of  //
//					the project									   //
//	Version:		1.0											   //
//  Date:			02/07/2017									   //
//  Language:       Visual C++, Version 11.						   //
//  Platform:       Visual Studio Community Edition				   //
//					HP ENVY, Windows 10				               //
//  Application:    CSE687 - Object Oriented Design                //
//  Author:         Sachin Basavani Shivashankara				   //
//	SUID:			267871645									   //
//                  (315)751-5895, sbasavan@syr.edu				   //
/////////////////////////////////////////////////////////////////////
// Manual Information:
//		Test-stub package to test various functionalities of the project.
// Required Files :
//		CppProperties.h
//		DBCreate.h
//		DB_Manip.h
// Build Process :
//		devenv Sachin_Project1.sln/ Rebuild debug	
// Maintenance Information:
//		Version 1: 02/06/2017

#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../CppProperties/CppProperties.h"
#include "../Project_files/NoSqlDb/DBCreate.h"
#include "../mak_mod/DB_Manip.h"

using StrData = std::string;
using intData = int;
using Key = NoSqlDB<StrData>::Key;
using Keys = NoSqlDB<StrData>::Keys;
using makeVec = std::vector<StrData>;
using Query = char[];

int main()
{
	// Main Test-stub function
	teststub test1;
	test1.strDB();			//Adding elements to string Database
	test1.strDispChild();	//displaying the children of the string Database elements
	test1.intDB();			//Adding elements to interger Database
	test1.intDispChild();	//displaying the children of the integer Database elements
	return 0;
}
