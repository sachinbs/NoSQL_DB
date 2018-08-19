#pragma once
//////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							  	//
//					To create a non-SQL key/value database using	//
//					C++												//
//  DBCreate.h:		Header file to create a NoSQL Database			//
//																	//
//  ## Using Prof. Jim Fawcett's "NoSqlDb.h" as the reference ##	//
//  ## for few database operation functions and augmenting it ##	//
//	## with other functions to add/delete/modify the database ##	//
//																	//
//	Version:		1.0												//
//  Date:			02/07/2017										//
//  Language:       Visual C++, Version 11.							//
//  Platform:       Visual Studio Community Edition					//
//					HP ENVY, Windows 10								//
//  Application:    CSE687 - Object Oriented Design					//
//  Author:         Sachin Basavani Shivashankara					//
//	SUID:			267871645										//
//                  (315)751-5895, sbasavan@syr.edu					//
//////////////////////////////////////////////////////////////////////
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

#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../../CppProperties/CppProperties.h"

// Element class which represents the data record
template<typename Data>
class Element
{
private:
	using Name = std::string;

public:

	using Category = std::string;
	using Timedate = std::string;
	using Descr = std::string;
	using Strdata = std::string;
	using ChildVec = std::vector<Strdata>;

	Property<Name> name;			// metadata
	Property<Category> category;	// metadata
	Property<Descr> descr;			// metadata
	Property<Timedate> timedate;	// metadata
	Property<ChildVec> child_key;   // metadata
	Property<Data> data;			// data


	std::string show();
};

// Function method to display the member variables of Element class
template<typename Data>
std::string Element<Data>::show()
{
	std::ostringstream out;
	out.setf(std::ios::adjustfield, std::ios::left);
	out << "\n    " << std::setw(8) << "name" << " : " << name;
	out << "\n    " << std::setw(8) << "category" << " : " << category;
	out << "\n    " << std::setw(8) << "Text Description" << " : " << descr;
	out << "\n    " << std::setw(8) << "timeDate" << " : " << timedate;
	for (int i = 0; i < int(child_key.getValue().size()); i++)
		out << "\n    " << std::setw(8) << "child_keys : " << child_key.getValue()[i];
	out << "\n    " << std::setw(8) << "Data_stored : " << data;
	out << "\n";
	return out.str();
}

// NoSqlDB class which populates the database. Utilizes 'unordered_map' library.
template<typename Data>
class NoSqlDB : Element<Data>
{
public:
	using Key = std::string;
	using Keys = std::vector<Key>;

	Keys keys();
	bool save(Key key, Element<Data> elem);
	Element<Data> value(Key key);
	Element<Data> delItem(Key key);
	Element<Data> modKey(Key key, Element<Data> elem);
	size_t count();
private:
	using Item = std::pair<Key, Element<Data>>;
	std::unordered_map<Key, Element<Data>> store;
};

// To delete an element for the given key from the database
template<typename Data>
Element<Data> NoSqlDB<Data>::delItem(Key key)
{
	if (store.find(key) != store.end())
		store.erase(key);
	std::cout << "\n***The Key  is successfully deleted from the Database***";
	return Element<Data>();
}

// TO modify the contents of the database for the given key
template<typename Data>
Element<Data> NoSqlDB<Data>::modKey(Key key, Element<Data> elem)
{
	store[key] = elem;
	return Element<Data>();
}

// To create a database of the keys of the elements in the database
template<typename Data>
typename NoSqlDB<Data>::Keys NoSqlDB<Data>::keys()
{
	Keys keys;
	for (Item item : store)
	{
		keys.push_back(item.first);
	}
	return keys;
}

// To save the key-value pair in the database
template<typename Data>
bool NoSqlDB<Data>::save(Key key, Element<Data> elem)
{
	if (store.find(key) != store.end())
		return false;
	store[key] = elem;
	return true;
}

// To retrieve the value of the database for a given key
template<typename Data>
Element<Data> NoSqlDB<Data>::value(Key key)
{
	if (store.find(key) != store.end())
		return store[key];
	return Element<Data>();
}

// To get the total number of elements in the database
template<typename Data>
size_t NoSqlDB<Data>::count()
{
	return store.size();
}