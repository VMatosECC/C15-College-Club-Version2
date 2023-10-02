#pragma once
#include "MyHeader.h"

class Person
{
private:
	string id;
	string name;

public:
	//Getter-Setters
	string getID() { return id; }
	string getName() { return name; }
	void setID(string value) { id = value; }
	void setName(string value) { name = titleCaps(value); }

	//constructor(s)
	Person(string id = "n.a", string name = "n.a")
	{
		setID(id);
		setName(name);
	}

	//user-defined methods
	string toString(string msg = "");
	string titleCaps(string str);

	//Destructor
	~Person()
	{
		cout << "+++ Person  Destuctor called - "
			<< this->toString() << endl;
	}
};
//Implementation section ///////////////////////////////////
string Person::toString(string msg) {
	ostringstream sout;
	sout << msg
		<< this
		<< " Person [id:" << id
		<< ", Name:" << name
		<< "]";
	return sout.str();
}

//Make sure names are stored in Proper-Cap format 
//(Capital letter followed by lower case letters)
string Person::titleCaps(string str) {
	if (str.size() == 0) return "";

	string result = "";
	result += toupper(str.at(0));

	for (int i = 1; i < str.size(); i++)
	{
		if (str.at(i) == ' ' && str.at(i - 1) == ' ') continue;
		if (str.at(i - 1) == ' ')
			result += toupper(str.at(i));
		else
			result += tolower(str.at(i));
	}
	return result;

}


