#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <algorithm> // need this to use rotate()

using namespace std;

void TryMap();
void TryVector();
void TestRotateVector();

int LearnMain() {

	TestRotateVector();

	return 0;
}

void TryMap() {
	map<int, string> Employees;

	Employees[101] = "John Thomas";
	Employees[103] = "Jack Jones";
	Employees[105] = "Jane Doe";

	cout << "Maximum size: " << Employees.max_size() << endl << endl;

	cout << Employees[101] << " " << Employees[103] << endl;
	cout << "Size: " << Employees.size() << endl;

	cout << endl << "Natural Order:" << endl;
	for (map<int, string>::iterator x = Employees.begin(); x != Employees.end(); x++) {
		cout << (*x).first << " | " << (*x).second << endl;
	}
	cout << endl << "Reverse Order:" << endl;
	for (map<int, string>::reverse_iterator x = Employees.rbegin(); x != Employees.rend(); x++) {
		cout << (*x).first << " | " << (*x).second << endl;
	}
}

void TryVector() {
	vector<string> skills;
	vector<string> old_skills = { "C", "Delphi", "Unix", "Windows", "VB", "SQL", "MySQL", "MongoDB" };

	// skills.push_back("Test"); // test to see if the vector skills is empty.

	if (skills.empty()) { // boolean - check if vector is empty.
		skills.push_back("HTML");
		skills.push_back("CSS");
		skills.push_back("JavaScript");
	}

	for (vector<string>::iterator x = skills.begin(); x != skills.end(); x++)
		cout << *x << ", ";
	cout << endl;

	// add new element to skills
	skills.push_back("Node.js");

	// remove the last element and reduces the vector size by one.
	skills.pop_back();

	// now test swap function
	skills.swap(old_skills);
	skills.insert(skills.end(), old_skills.begin(), old_skills.end());

	skills.erase(skills.begin() + 2); // will take out "Unix"

	// using insert function
	skills.insert(skills.begin() + 1, "AutoCAD");
	skills.push_back("Node.js");

	for (int i = 0; i < (signed)skills.size(); i++)
		cout << skills.at(i) << ", ";
	cout << endl << "New skill added: " << skills.back() << endl;
	cout << endl << "First skill added: " << skills.front() << endl;

	cout << "Size: " << skills.size() << " Capacity: " << skills.capacity() <<
		" Maximum Capacity: " << skills.max_size() << endl;

	// using resize function
	skills.resize(skills.size() + 1, "Inkscape");
	skills.resize(5);
	skills.clear();

	for (int i = 0; i < (signed)skills.size(); i++)
		cout << skills.at(i) << ", ";
	cout << endl;
	cout << "Size: " << skills.size() << endl;
}

void TestRotateVector() {
	vector<int> arrLeft = { 1,2,3,4,5,6,7 };
	vector<int> arrRight = { 1,2,3,4,5,6,7 };

	// this one is rotate left
	int rotLeft = 3;
	rotate(arrLeft.begin(), arrLeft.begin() + rotLeft, arrLeft.end());

	cout << "Rotate Left " << rotLeft << " times." << endl;
	for (int i = 0; i < (signed)arrLeft.size(); i++)
		cout << arrLeft.at(i) << ", ";
	cout << endl;

	// this one is rotate right using rbegin() and rend()
	int rotRight = 3;
	cout << "Rotate Right " << rotRight << " times." << endl;
	rotate(arrRight.rbegin(), arrRight.rbegin() + rotRight, arrRight.rend());

	for (int i = 0; i < (signed)arrRight.size(); i++)
		cout << arrRight.at(i) << ", ";
	cout << endl;
}