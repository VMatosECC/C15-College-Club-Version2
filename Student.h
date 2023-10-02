#pragma once
#include "MyHeader.h"
#include "Person.h"

class Student : public Person
{
private:
	//Data members
	string major;
	double gpa;

public:
	//Accessors-Mutators
	string getMajor() { return major; }
	double getGpa()   { return gpa; }
	void   setMajor(string majorValue) { major = majorValue; }
	void   setGpa(double gpaValue)     { gpa = gpaValue; }

	//constructors
	Student(string idValue = "n.a",
		string nameValue = "n.a",
		string majorValue = "n.a",
		double gpaValue = 0.0)
		: Person(idValue, nameValue)
	{
		setGpa(gpaValue);
		setMajor(majorValue);
	}

	//constructor 
	Student(Person* p, string majorValue = "n.a", double gpaValue = 0.0)
		: Person(p->getID(), p->getName())
	{
		setMajor(majorValue);
		setGpa(gpaValue);

	}

	//Destructor
	~Student()
	{
		cout << "+++ Student Destuctor called\n";
	}

	//programmer-defined method
	string toString(string msg = "");

};

// Implementation Section ///////////////////////////////////////////
string Student::toString(string msg) {
	ostringstream sout;
	sout << msg
		<< this
		<< " Student[ ID:" << getID()
		<<  ", Name:" << setw(12) << left << getName()
		<< ", Major: " << setw(12) << left << getMajor()
		<< ", Gpa:" << getGpa() << " ]";

	return sout.str();
}

