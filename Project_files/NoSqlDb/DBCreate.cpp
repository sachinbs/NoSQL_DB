/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  DBCreate.cpp:   Test-stub to check various functionalities of  //
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
// Classes:
//		1. Element: A template class used to create objects which represents the data record (key, metadata and the generic data)
//			** Metadata **
//				## String type ##
//					-Name (Also the key)
//					-Category
//					-Descr
//					-Timedate
//				## Vector of string type ##
//					-ChildrenVec
//			** Data **
//				## Template type ##
//					-Data
//		2. NoSqlDB: A template class to push the key, value pair into the database using 'unordered_map' library
//			** Methods used **
//				## save(key, value) ##
//					-To save the key-value pair into the database
//				## value(key) ##
//					-To retrieve the value (object which holds the metadata and data) for the 'key' from the database
//				## delItem(key) ##
//					-To delete the 'key'-value pair from the database
//				## count() ##
//					-To get the count of the number of elements in the database
//				## modKey(key, value) ##
//					-To push the key value pair into the database after the data is modified
// Required Files :
//		CppProperties.h
// Build Process :
//		devenv Sachin_Project1.sln/ Rebuild debug	
// Maintenance Information:
//		Version 1: 02/06/2017

#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <unordered_map>
#include "../../XmlDocument/XmlDocument/XmlDocument.h"
#include "../../XmlDocument/XmlElement/XmlElement.h"
#include "../../Convert/Convert.h"
#include "../../CppProperties/CppProperties.h"
#include "../../StrHelper.h"
#include "../../mak_mod/DB_Manip.h"
#include "../../Query/Query.h"
#include "../../Xml_Persist/Xml_Persist.h"
#include "DBCreate.h"

using name = std::string;
using Category = std::string;
using TimeDate = std::string;
using TextDesc = std::string;
using qdata = std::string;
using Strdata = std::string;
using child_vec = std::vector<Strdata>;
using StrData = std::string;
using intData = int;
using Key = NoSqlDB<StrData>::Key;
using Keys = NoSqlDB<StrData>::Keys;
using makeVec = std::vector<StrData>;
using Query = char[];

int main()
{
	NoSqlDB<StrData> db, db1;

	std::cout << "\n" << "************DB Related Start*************" << "\n";
	// Database Manipulation related
	teststub test1;
	db = test1.strDB();						 //Adding elements to string Database
	test1.intDB();						     //Adding elements to interger Database
	db = test1.strDispChild();				 //Displaying the children of the string Database elements
	test1.intDispChild();				     //Displaying the children of the integer Database elements
	/////////////////////////////
	Key delete_keys = "string_elem4";	     //Deletion of a key from the Database
	db = test1.delKey(delete_keys);			     
	Key deletion_key = delete_keys;		     //Delete the parent child relationship
	db = test1.delChildRel(deletion_key);
	/////////////////////////////
	Key keys_to_edit = "string_elem5";	     //Editing an element in the Database
	db = test1.keyedit(keys_to_edit);
	std::cout << "\n" << "************DB Related End*************" << "\n";

	// Query related
	std::cout << "\n" << "************Query Related Start*************" << "\n";
	teststub2 test2;
	Key in_key = "string_elem3";			
	test2.keyQuery(db, in_key);				// Querying of keys
	Category cat = "string_cat6";
	test2.categQuery(db, cat);				// Querying of category
	TextDesc dscr = "elem7_description";
	test2.descrQuery(db, dscr);				// Querying of description
	qdata data = "elem1_StrData";
	test2.dataQuery(db, data);				// Querying of data

	test2.qCateg(db);						// Querying of category (using 'regex')
	test2.qName(db);						// Querying of name (using 'regex')
	test2.qData(db);						// Querying of data (using 'regex')
	std::cout << "\n" << "************Query Related End*************" << "\n";

	// XML persistence related
	std::cout << "\n" << "************XML Related Start*************" << "\n";
	teststub3 test3;
	test3.toXml(db);									//Persisting to an XML file
	test3.fromxml(db, "test.xml");						//Persisting from an XML file
	test3.fromxml(db, "Package_structure.xml");
	std::cout << "\n" << "************XML Related End*************" << "\n";
	
	std::cout << "\n";
	return 0;
}