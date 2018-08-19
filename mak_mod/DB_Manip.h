#pragma once
/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  DB_Manip.h:     Header file for the Test-stub which checks	   //
//					various functionalities of the project.		   //
//					Here, related to database manipulations        //
//					Implements class Test-stub for:				   //
//					i. Adding 'string' and 'int' elements into the //
//					   database									   //
//					ii. Deleting any key in the database		   //
//					iii. Deleting Parent-Child relationship		   //
//					iv. Editing the metadata of the elements in    //
//						the database							   //
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
//		1. teststub: A class which is used to test the different functionalities 
//					 (related to database manipulation) of the project.
//			- To update the database with 'string' and 'int' type
//			- To delete a key
//			- To delete a parent-child relationship when a child is deleted
//			- To edit the contents of any instance Of the database
// Required Files :
//		CppProperties.h
//		DBCreate.h
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

using StrData = std::string;
using intData = int;
using Key = NoSqlDB<StrData>::Key;
using Keys = NoSqlDB<StrData>::Keys;
using makeVec = std::vector<StrData>;
using Query = char[];

class teststub
{
public:
	NoSqlDB<StrData> db;
	NoSqlDB<intData> idb;
	NoSqlDB<StrData> strDB();
	NoSqlDB<StrData> intDB();
	NoSqlDB<StrData> strDispChild();
	int intDispChild();
	NoSqlDB<StrData> delKey(Key delete_keys);
	NoSqlDB<StrData> delChildRel(Key key);
	NoSqlDB<StrData> keyedit(Key keys_to_edit);

};
// Populating the string database; Adding string type data into the database
NoSqlDB<StrData> teststub::strDB()
{
	std::cout << "\n***NoSQL Database: WIth String Data***\n";
	
	//first element:
	Element<StrData> elem1;
	elem1.name = "string_elem1";
	elem1.category = "string_cat1";
	elem1.descr = "elem1_description";
	elem1.timedate = "01:01:01;01-30";
	elem1.child_key = { "string_elem4","string_elem5" };
	elem1.data = "elem1_StrData";
	db.save(elem1.name, elem1);			// Saves the element into the database

	//second element
	Element<StrData> elem2;
	elem2.name = "string_elem2";
	elem2.category = "string_cat2";
	elem2.descr = "elem2_description";
	elem2.timedate = "02:02:02;01-30";
	elem2.child_key = { "string_elem5", "string_elem7" };
	elem2.data = "elem2s_StrData";
	db.save(elem2.name, elem2);			// Saves the element into the database

	//third element
	Element<StrData> elem3;
	elem3.name = "string_elem3";
	elem3.category = "string_cat3";
	elem3.descr = "elem3_description";
	elem3.timedate = "03:03:03;01-30";
	elem3.data = "elem3s_StrData";
	db.save(elem3.name, elem3);			// Saves the element into the database

	//fourth element
	Element<StrData> elem4;
	elem4.name = "string_elem4";
	elem4.category = "string_cat4";
	elem4.descr = "elem4_description";
	elem4.timedate = "04:04:04;01-30";
	elem4.data = "elem4s_StrData";
	db.save(elem4.name, elem4);			// Saves the element into the database

	//fifth element
	Element<StrData> elem5;
	elem5.name = "string_elem5";
	elem5.category = "string_cat5";
	elem5.descr = "elem5_description";
	elem5.timedate = "05:05:05;01-30";
	elem5.data = "elem5s_StrData";
	db.save(elem5.name, elem5);			// Saves the element into the database

	//sixth element
	Element<StrData> elem6;
	elem6.name = "string_elem6";
	elem6.category = "string_cat6";
	elem6.descr = "elem6_description";
	elem6.timedate = "06:06:01;01-30";
	elem6.data = "elem6s_StrData";
	db.save(elem6.name, elem6);			// Saves the element into the database

	//seventh element
	Element<StrData> elem7;
	elem7.name = "string_elem7";
	elem7.category = "string_cat7";
	elem7.descr = "elem7_description";
	elem7.timedate = "07:07:07;01-30";
	elem7.data = "elem7s_StrData";
	db.save(elem7.name, elem7);			// Saves the element into the database

	std::cout << " \n\n***The Elements in the Database are:***";
	Keys keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	return db;
}

// To display the child elements of all the elements of the string database
NoSqlDB<StrData> teststub::strDispChild()
{
	Keys keys = db.keys();
	makeVec tempVec1;
	Element<StrData> temp1;
	std::cout << "\n\n***Displaying the child members of String Database elements:***\n";
	for (auto key : keys)
	{
		tempVec1.erase(tempVec1.begin(), tempVec1.end());
		temp1 = db.value(key);
		std::cout << "\nParent key : " << key;
		if (!temp1.child_key.getValue().empty())
		{
			for (int i = 0; i < int(temp1.child_key.getValue().size()); i++)
				tempVec1.push_back(temp1.child_key.getValue()[i]);
			for (auto j : tempVec1)
			{
				std::cout << "\n  " << j << ":";
				std::cout << db.value(j).show();
			}
		}
		else
			std::cout << "\nNo children\n";
	}
	std::cout << "\n\n";
	return db;
}

// Populating the 'int' database; Adding string type data into the database
NoSqlDB<StrData> teststub::intDB()
{
	std::cout << "\n***NoSQL Database: With Int Data***\n";

	//first element:
	Element<intData> ielem1;
	ielem1.name = "int_ielem1";
	ielem1.category = "int_cat1";
	ielem1.descr = "ielem1_description";
	ielem1.timedate = "01:01:01;01-30";
	ielem1.child_key = { "int_ielem4"};
	ielem1.data = 1;
	idb.save(ielem1.name, ielem1);			// Saves the element into the database

	//second element
	Element<intData> ielem2;
	ielem2.name = "int_ielem2";
	ielem2.category = "int_cat2";
	ielem2.descr = "ielem2_description";
	ielem2.timedate = "02:02:02;01-30";
	ielem2.child_key = { "int_ielem5"};
	ielem2.data = 2;
	idb.save(ielem2.name, ielem2);			// Saves the element into the database

	//third element
	Element<intData> ielem3;
	ielem3.name = "int_ielem3";
	ielem3.category = "int_cat3";
	ielem3.descr = "ielem3_description";
	ielem3.timedate = "03:03:03;01-30";
	ielem3.data = 3;
	idb.save(ielem3.name, ielem3);			// Saves the element into the database

	//fourth element
	Element<intData> ielem4;
	ielem4.name = "int_ielem4";
	ielem4.category = "int_cat4";
	ielem4.descr = "ielem4_description";
	ielem4.timedate = "04:04:04;01-30";
	ielem4.data = 4;
	idb.save(ielem4.name, ielem4);			// Saves the element into the database

	//fifth element
	Element<intData> ielem5;
	ielem5.name = "int_ielem5";
	ielem5.category = "int_cat5";
	ielem5.descr = "ielem5_description";
	ielem5.timedate = "05:05:05;01-30";
	ielem5.data = 5;
	idb.save(ielem5.name, ielem5);			// Saves the element into the database

	std::cout << " \n\n***The Elements present in the Database are:***";
	Keys keys = idb.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << idb.value(key).show();
	}
	return db;
}

// To display the child elements of all elements of the int database
int teststub::intDispChild()
{
	Keys keys = idb.keys();
	makeVec tempVec2;
	Element<intData> temp2;
	std::cout << "\n\n***Displaying the child members of Int Database elements:***\n";
	for (auto key : keys)
	{
		tempVec2.erase(tempVec2.begin(), tempVec2.end());
		temp2 = idb.value(key);
		std::cout << "\nParent key : " << key;
		if (!temp2.child_key.getValue().empty())
		{
			for (int i = 0; i < int(temp2.child_key.getValue().size()); i++)
				tempVec2.push_back(temp2.child_key.getValue()[i]);
			for (auto j : tempVec2)
			{
				std::cout << "\n  " << j << ":";
				std::cout << idb.value(j).show();
			}
		}
		else
			std::cout << "\nNo children\n";
	}
	std::cout << "\n\n";
	return 0;
}

// To delete the element from the database for a given key
NoSqlDB<StrData> teststub::delKey(Key delete_keys)
{
	std::cout << "\n\n***Demonstrates deletion of key-value pair from the database for the given key***";
	std::cout << "\n Deleting element with key: " << delete_keys;
	db.delItem(delete_keys);
	std::cout << " \n\n***The Database after deletion of the element is:***";
	Keys keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	return db ;
}

// To remove the parent-child relationship when the deleted element is a child
NoSqlDB<StrData> teststub::delChildRel(Key deleted_key)
{
	bool istrue = true;
	std::cout << "\n\n***Demonstrates Parent-child relationship deletion when the deleted element is a child***";
	std::cout << "\n Deleting element with key: " << deleted_key;
	Keys keys = db.keys();
	makeVec tempVec3;
	Element<StrData> temp3;
	for (auto key : keys)
	{
		temp3 = db.value(key);
		istrue = false;
		if (temp3.child_key.getValue().size() == 1)
		{
			if (temp3.child_key.getValue()[0] == deleted_key)
			{
				temp3.child_key = { "" };
				db.modKey(key, temp3);
			}
		}
		else
		{
			tempVec3.erase(tempVec3.begin(), tempVec3.end());
			for (int i = 0; i < int(temp3.child_key.getValue().size()); i++)
			{
				if (temp3.child_key.getValue()[i] != deleted_key)
				{
					istrue = true;
					tempVec3.push_back(temp3.child_key.getValue()[i]);
				}
			}

			if (istrue == true)
			{
				temp3.child_key = tempVec3;
				db.modKey(key, temp3);
			}
		}
	}
	std::cout << "\n***After deletion***";
	keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	return db;
}

// To modify an element in the database
NoSqlDB<StrData> teststub::keyedit(Key keys_to_edit)
{
	std::cout << "\n***Demonstrates editing an element in the database:***";
	Element<StrData> temp4;
	temp4 = db.value(keys_to_edit);

	temp4.category = "New category value added";

	db.modKey(keys_to_edit, temp4);
	auto keys = db.keys();
	std::cout << "\n***After deletion***";
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	return db ;
}
