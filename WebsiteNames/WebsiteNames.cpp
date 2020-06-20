// WebsiteNames.cpp : Defines the entry point for the console application.
//
#include "Record.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

void saveRecords(const std::vector<Record> &abook, const char* filename)
{
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oar(ofs);
	oar << abook;
}

void restoreRecords(std::vector<Record> &abook, const char* filename)
{
	std::ifstream ifs(filename);
	boost::archive::text_iarchive iar(ifs);
	iar >> abook;
}

int numRecords = 0;
void printRecords(std::vector<Record> db);

int main()
{
	std::vector<Record>abook;
	
	Record rec;
	rec.setIndex(++numRecords);
	abook.push_back(rec);

	rec.setIndex(++numRecords);
	rec.setUsername("John");
	rec.setPassword("J111");
	rec.setWebsite("www.ibm.com");
	rec.setComment("Comment for John");
	abook.push_back(rec);

	rec.setIndex(++numRecords);
	rec.setUsername("Robert");
	rec.setPassword("R222");
	rec.setWebsite("www.yahoo.com");
	rec.setComment("Comment for Robert");
	abook.push_back(rec);

	rec.setIndex(++numRecords);
	rec.setUsername("Someone");
	rec.setPassword("S333");
	rec.setWebsite("google.com");
	rec.setComment("Comment for Someone");
	abook.push_back(rec);

	cout << "size of abook=" << abook.size() << "\n";
	abook.resize(numRecords);

	std::cout << "-------- abook1 ----------\n";
	printRecords(abook);
	saveRecords(abook, "myAddressBook.txt");

	std::cout << "-------- abook2 ----------\n";
	std::vector<Record> abook2;
	restoreRecords(abook2, "myAddressBookOLD.txt");
	printRecords(abook2);

    return 0;
}

void printRecords(std::vector<Record> aBook)
{
	int i = 0;
	std::vector<Record>::iterator it;
	for (auto it = aBook.begin(); it<aBook.end(); it++)
	{
		i++;
		std::cout << "[" << i << "]:";
		std::cout << " index="    << it->getIndex();
		std::cout << " website="  << it->getWebsite();
		std::cout << " username=" << it->getUsername();
		std::cout << " password=" << it->getPassword();
		std::cout << "\n";
	}
}
