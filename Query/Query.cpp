/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  Query.cpp:													   //
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
//		Package to test the querying capabilites.
// Required Files :
//		CppProperties.h
//		DBCreate.h
//		DB_Manip.h
//		query.h
// Build Process :
//		devenv Sachin_Project1.sln/ Rebuild debug
// Maintenance Information:
//		Version 1: 02/06/2017

//#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../CppProperties/CppProperties.h"
#include "../Project_files/NoSqlDb/DBCreate.h"
#include "../mak_mod/DB_Manip.h"
#include "../Query/query.h"

using StrData = std::string;
using intData = int;
using Key = NoSqlDB<StrData>::Key;
using Keys = NoSqlDB<StrData>::Keys;
using makevector = std::vector<StrData>;
using Query = char[];

int main()
{
	return 0;
}