/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  Xml_Persist.cpp Test-stub for Xml persist					   //
//					To test various functionalities of the project //
//					Here, related to XML file persistence.		   //
//					Implements class Test-stub for:				   //
//					i. Persisiting the contents of the database	   //
//					   to an XML file							   //
//					ii. Populating the database using the XML file //
//						as an input								   //
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
// Classes:
//		1. teststub2: A class which is used to test the different functionalities 
//					   (XML persistence related) of the project.
//					  i. Persists (writes) the contents of the database to an XML file
//					  ii. Uses an XML file as an input to populate the database with elements
// Required Files :
//		CppProperties.h
//		DB_Manip.h
//		DBCreate.h
// Build Process :
//		devenv Sachin_Project1.sln/ Rebuild debug
// Maintenance Information:
//		Version 1: 02/07/2017

#include <iostream>
#include <vector>
#include <fstream>
#include "../XmlDocument/XmlDocument/XmlDocument.h"
#include "../XmlDocument/XmlElement/XmlElement.h"
#include "../Convert/Convert.h"
#include "../CppProperties/CppProperties.h"
#include "../StrHelper.h"
#include "../Project_files/NoSqlDb/DBCreate.h"
#include "../mak_mod/DB_Manip.h"
#include "../Query/Query.h"
#include "../Xml_Persist/Xml_Persist.h"

using StrData = std::string;
using intData = int;
using Key = NoSqlDB<StrData>::Key;
using Keys = NoSqlDB<StrData>::Keys;
using makeVec = std::vector<StrData>;
using Query = char[];
using namespace XmlProcessing;
using sPtr = std::shared_ptr<AbstractXmlElement>;

int main()
{
	NoSqlDB<StrData> db;
	teststub3 test;
	test.toXml(db);
	test.fromxml(db, "test.xml");
	test.fromxml(db, "Package_structure.xml");
}