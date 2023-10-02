#pragma once
#include "Student.h"

class Club
{
private:
	// TODO - Add a president and an advisor
	// Student* president;
	// Faculty* advisor;
	// --------------------------------------------
	string* clubNamePtr;
	vector<Student*> vs;

public:
	//Mutators
	void setClubNamePtr(string* clubNameValue)
	{
		if (clubNamePtr != nullptr) delete clubNamePtr;
		clubNamePtr = new string();
		*clubNamePtr = *clubNameValue;
	}
	void setVectorStudentPtr(vector<Student*> vsValue)
	{
		// Remove any Student referenced by vs
		// this is fine because we own the objects in the vector
		while (!vs.empty())
		{
			Student* sp = vs.back();
			delete sp;
			vs.pop_back();
		}
		//copy incoming club members' data into fresh containers
		//observe, we OWN the student objects in the club list!
		for (Student* sp : vsValue)
		{
			Student* ptr = new Student(*sp);
			vs.push_back(new Student(*sp));
		}
	}

	//Accessors
	string* getClubNamePtr()  const { return clubNamePtr; }
	vector<Student*> getVectorStudentPtr() const { return vs; }

	//Constructors
	Club(string* clubNamePtrValue = nullptr, vector<Student*> vsValue = {})
	{
		setClubNamePtr(clubNamePtrValue);
		setVectorStudentPtr(vsValue);
	}
	//
	~Club()
	{
		cout << "\nClub destructor called ++++++++++++++++++++\n";
		//get rid of the heap-box holding the club name
		delete clubNamePtr;
		//If the current club has members on the heap these objects must deleted
		while (!vs.empty()) {
			Student* pLast = vs.back();
			vs.pop_back();
			delete pLast;
		}
	}

	//User-defined methods
	void operator= (const Club& otherClub)
	{
		cout << " Operator= called\n";
		delete clubNamePtr;
		clubNamePtr = new string;
		*clubNamePtr = *otherClub.clubNamePtr;

		// We have ownership of the student objects listed as club members; 
		// thoose are independent clones. We must delete them.
		while (!vs.empty()) {
			Student* pLast = vs[vs.size() - 1];
			vs.pop_back();
			delete pLast;
		}

		//Copy new club members in the current vector
		for (Student* ps : otherClub.vs)
		{
			//Independent clones
			Student* newPtr = new Student();
			*newPtr = *ps;
			vs.push_back(newPtr);
		}


	}

	//Custom made Club class Copy-Constructor (avoid bit-by-bit cloning)
	Club(const Club& otherClub)
	{
		cout << " Club Custom-Copy-Constructor called\n";
		//here we call the overloaded operator=
		*this = otherClub;
	}

	//stringify the current Club object
	string toString(string msg = "") const
	{
		ostringstream sout;
		sout << msg << this << " Club [ NamePtr: " << getClubNamePtr()
			<< ", Name: " << *(getClubNamePtr())
			<< "\n\tMembers:\n";

		for (Student* p : vs)
			sout << "\t" << p->toString() << endl;

		sout << "\t]";
		return sout.str();

	}

	//add a pointer to the vector holding club member's references
	void addNewMemberPtr(Student* ptrValue)
	{
		//Independent clone - we own it!
		Student* s = new Student();
		*s = *ptrValue;
		vs.push_back(s);
	}

	//Look for a club member. If found return its pointer (or nullptr otherwise)
	Student* findClubMemberPtr(string salutValue, string nameValue)
	{
		Student* ptr = nullptr;
		for (Student* ptr : vs)
		{
			if (ptr->getID() == salutValue && ptr->getName() == nameValue)
				return ptr;
		}
		return ptr;
	}

	//overload the << operator to show current club
	friend ostream& operator << (ostream& sout, const Club& theClub)
	{
		sout << theClub.toString();
		return sout;
	}
};

