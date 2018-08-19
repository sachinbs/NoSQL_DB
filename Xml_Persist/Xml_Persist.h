#pragma once
/////////////////////////////////////////////////////////////////////
//	Project#1:		Key/Value Database							   //
//					To create a non-SQL key/value database using   //
//					C++											   //
//  Xml_Persist.h:  Header file for the Test-stub which checks	   //
//					various functionalities of the project.		   //
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
#include <string>
#include <string>
#include <vector>
#include <fstream>
#include "../XmlDocument/XmlDocument/XmlDocument.h"
#include "../XmlDocument/XmlElement/XmlElement.h"
#include "../Convert/Convert.h"
#include "../CppProperties/CppProperties.h"
#include "../StrHelper.h"
#include "../mak_mod/DB_Manip.h"
#include "../Project_files/NoSqlDb/DBCreate.h"

using StrData = std::string;
using intData = int;
using Key = NoSqlDB<StrData>::Key;
using Keys = NoSqlDB<StrData>::Keys;
using makeVec = std::vector<StrData>;
using Query = char[];
using namespace XmlProcessing;
using sPtr = std::shared_ptr<AbstractXmlElement>;

// Class teststub3
class teststub3
{
public:
	void toXml(NoSqlDB<StrData> &db);
	void fromxml(NoSqlDB<StrData> &db, std::string fileName);
};

// Method function to persist the contents of the database to an XML file
void teststub3::toXml(NoSqlDB<StrData> &db)
{
	Keys keys = db.keys();
	sPtr pRoot = makeTaggedElement("root");
	XmlDocument doc(XmlProcessing::makeDocElement(pRoot));
	Element<StrData> tempX1;
	std::vector<std::string> vect;
	std::cout << "\n\nCreating an XML file (XML_op.txt)\n\n";
	for (Key key : keys)
	{
		vect.erase(vect.begin(), vect.end());
		tempX1 = db.value(key);
		std::string name = tempX1.name.getValue();
		std::string category = tempX1.category.getValue();
		std::string textdesc = tempX1.descr.getValue();
		std::string timedate = tempX1.timedate.getValue();
		std::string datastore = tempX1.data.getValue();
		for (int i = 0; i < int(tempX1.child_key.getValue().size()); i++)
			vect.push_back(tempX1.child_key.getValue()[i]);
		sPtr child1 = makeTaggedElement(key);

		sPtr child1Name = makeTaggedElement("name");
		child1->addChild(child1Name);
		child1Name->addChild(makeTextElement(name));

		sPtr child1Category = makeTaggedElement("category");
		child1->addChild(child1Category);
		child1Category->addChild(makeTextElement(category));

		sPtr child1Description = makeTaggedElement("textDescription");
		child1->addChild(child1Description);
		child1Description->addChild(makeTextElement(textdesc));

		sPtr child1Timedate = makeTaggedElement("timeDate");
		child1->addChild(child1Timedate);
		child1Timedate->addChild(makeTextElement(timedate));

		sPtr child1Data = makeTaggedElement("dataStore");
		child1->addChild(child1Data);
		child1Data->addChild(makeTextElement(datastore));
		for (auto j : vect)
		{
			sPtr child1Rel = makeTaggedElement("child");
			child1->addChild(child1Rel);
			child1Rel->addChild(makeTextElement(j));
		}
		pRoot->addChild(child1);
	}
	std::ofstream outputFile("XML_op.xml");
	outputFile << doc.toString();
	std::cout << "\n  Database persisted to the XML: \n\n";
	std::cout << doc.toString();
}

// Method function to populate the database using the XML file as an input
void teststub3::fromxml(NoSqlDB<StrData> &db, std::string fileName)
{
	XmlDocument doc2(fileName, XmlDocument::file);
	sPtr root = doc2.xmlRoot();
	//Element<StrData> tempX2;
	for (sPtr entry : root->children())
	{
		
		Key key = entry->tag();
		Element<StrData> tempX2;
		//std::cout << "\nkey :";
		//tempX2 = db.value(key);

		for (sPtr field : entry->children())
		{
			if (field->tag() == "name")
				tempX2.name = trim(field->children()[0]->value());
			else if (field->tag() == "category")
				tempX2.category = trim(field->children()[0]->value());
			else if (field->tag() == "textDescription")
				tempX2.descr = trim(field->children()[0]->value());
			else if (field->tag() == "timeDate")
				tempX2.timedate = trim(field->children()[0]->value());
			else if (field->tag() == "dataStore")
				tempX2.data = trim(field->children()[0]->value());
			else if (field->tag() == "child")
				for (int i = 0; i < int(tempX2.child_key.getValue().size()); i++)
					tempX2.child_key.getValue()[i] = (trim(field->children()[i]->value()));
		}
		db.save(key, tempX2);
	}

	std::cout << "\n  Populated the NoSqlDB<string> database from xml.txt:";
	std::cout << "\n ------------------------------------------\n";

	for (Key key : db.keys())
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
}