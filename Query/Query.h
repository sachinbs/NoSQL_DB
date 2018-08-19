#pragma once
/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  Query.h:        Header file for the Test-stub which checks	   //
//					various functionalities of the project.		   //
//					Here, related to Queries.					   //
//					Implements class Test-stub for:				   //
//					i. Querying on keys							   //
//					ii. Querying on category					   //
//					iii. Querying on description				   //
//					iv. Querying on data					       //
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
//					   (queries related) of the project.
//			- To provide querying capabilities to the database. 
//				* Queries to keys
//				* Queries to category
//				* Queries to description
//				* Queries to data
// Required Files :
//		CppProperties.h
//		DBCreate.h
//		DB_Manip.h
// Build Process :
//		devenv Sachin_Project1.sln/ Rebuild debug
// Maintenance Information:
//		Version 1: 02/07/2017

#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <regex>
#include "../CppProperties/CppProperties.h"
#include "../Project_files/NoSqlDb/DBCreate.h"
#include "../mak_mod/DB_Manip.h"

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
using makevector = std::vector<StrData>;
using Query = char[];

// Class teststub2
class teststub2
{
public:
	Element<StrData> tempq1;
	int keyQuery(NoSqlDB<StrData> &db, Key in_key);						// Method to perform queries on keys
	int teststub2::categQuery(NoSqlDB<StrData> &db, Category cat);		// Method to perform queries on category
	int teststub2::descrQuery(NoSqlDB<StrData> &db, Category cat);		// Method to perform queries on description
	int teststub2::dataQuery(NoSqlDB<StrData> &db, Category cat);		// Method to perform queries on data
	int teststub2::qName(NoSqlDB<StrData> db);
	int teststub2::qCateg(NoSqlDB<StrData> db);
	int teststub2::qData(NoSqlDB<StrData> db);
};

// Method to perform queries on keys
int teststub2::keyQuery(NoSqlDB<StrData> &db, Key in_key)
{
	Keys keys = db.keys();
	std::cout << "\nQuerying based on key";
	std::cout << "\nReturning the element based on the request. " << "Queried key: " << in_key;
	for (Key key : keys)
	{
		tempq1 = db.value(key);
		if (key == in_key)
		{
			std::cout << "\n" << db.value(in_key).show();
		}
	}
	return 0;
}

// Method to perform queries on category
int teststub2::categQuery(NoSqlDB<StrData> &db, Category cat)
{
	Element<StrData> tempq2;
	Keys keys = db.keys();
	std::cout << "\nQuerying based on Category";
	std::cout << "\nReturning the element based on the request. " << "Queried category: " << cat;
	for (Key key : keys)
	{
		tempq2 = db.value(key);
		if (cat.compare(tempq2.category.getValue()) == 0)
		{
			std::cout << db.value(key).show();
		}
	}
	return 0;
}

// Method to perform queries on description
int teststub2::descrQuery(NoSqlDB<StrData> &db, Category cat)
{
	Element<StrData> tempq3;
	Keys keys = db.keys();
	std::cout << "\nQuerying based on Text Description";
	std::cout << "\nReturning the element based on the request. " << "Queried description: " << cat;
	for (Key key : keys)
	{
		tempq3 = db.value(key);
		if (cat.compare(tempq3.descr.getValue()) == 0)
		{
			std::cout << db.value(key).show();
		}
	}
	return 0;
}

// Method to perform queries on data
int teststub2::dataQuery(NoSqlDB<StrData> &db, Category cat)
{
	Element<StrData> tempq4;
	Keys keys = db.keys();
	std::cout << "\nQuerying based on String Data";
	std::cout << "\nReturning the element based on the request. " << "Queried data: " << cat;
	for (Key key : keys)
	{
		tempq4 = db.value(key);
		if (cat.compare(tempq4.data.getValue()) == 0)
		{
			std::cout << db.value(key).show();
		}
	}
	return 0;
}

// To perform queries on the database using 'regex'
int teststub2::qName(NoSqlDB<StrData> db)
{
	std::cout << "\nRegex on keys\n";
	StrData spot("[1-9]*");
	std::regex exp(spot);
	StrData valstr;
	Element<StrData> tempq5;
	std::smatch result;
	Keys keys = db.keys();
	for (Key key : keys) {
		tempq5 = db.value(key);
		if (std::regex_search(key, result, exp))
			std::cout << db.value(key).show();
	}return 0;
}

// To perform queries on the database using 'regex'
int teststub2::qCateg(NoSqlDB<StrData> db)
{
	std::cout << "\nRegex on category\n";
	StrData spot("o.*");
	StrData elem;
	std::regex exp(spot);
	Element<StrData> tempq6;
	std::smatch result;
	Keys keys = db.keys();
	for (Key key : keys) {
		tempq6 = db.value(key);
		elem = tempq6.category.getValue();
		if (std::regex_search(elem, result, exp))
			std::cout << db.value(key).show();
	}return 0;
}

// To perform queries on the database using 'regex'
int teststub2::qData(NoSqlDB<StrData> db)
{
	std::cout << "\nRegex on data\n";
	StrData spot("d.*");
	StrData elem;
	std::regex exp(spot);
	Element<StrData> tempq7;
	std::smatch result;
	Keys keys = db.keys();
	for (Key key : keys) {
		tempq7 = db.value(key);
		elem = tempq7.data.getValue();
		if (std::regex_search(elem, result, exp))
			std::cout << db.value(key).show();
	}return 0;
}