

#include "MyHeader.h"
#include "Person.h"
#include "Student.h"
#include "Club.h"
using namespace std;

void experiment01();

int main()
{
	experiment01();
    cout << "Hello World!\n";
}


//---------------------------------------------------------------------------
void experiment01()
{
	//Experiment. Show you delete heap objects whose addresses are held
	//            in a vector<> when the app is over?  YES!
	//-----------------------------------------------------------------------
	// We do NOT want to delete these objects until the app is over
	// they do not belong to us. We'll work with clones of these objects.
	Student* p1 = new Student("S0111", "Mr. One", "Sociology", 3.1);
	Student* p2 = new Student("S0222", "Ms. Two", "Mathematics", 3.2);
	Student* p3 = new Student("S0333", "Mr. Three", "Computer Sc.", 3.3);

	Student* p4 = new Student("S0444", "Mrs. Four", "Music", 3.4);
	Student* p5 = new Student("S0555", "Mr. Five", "Music", 3.5);
	Student* p6 = new Student("S0666", "Ms. Six", "Education", 3.6);
	//-----------------------------------------------------------------------

	cout << "Step1 - put students one, two, three in vector v1\n";
	vector<Student*> v1{ p1, p2, p3 };
	for (Student* p : v1) cout << p->toString() << endl;

	//Clearing a vector holding pointers doesn't delete the pointed objects!
	v1.clear();   //pointer list is erased - however...

	cout << "Step2 - After clearing v1 - vector's size is " << v1.size() << endl;
	cout << "ALIVE p1 " << p1->toString(" p1 ") << endl;
	cout << "ALIVE p2 " << p2->toString(" p2 ") << endl;
	cout << "ALIVE p3 " << p3->toString(" p3 ") << endl;

	//Reload v1 with p1, p2, and p3.
	v1.push_back(p1); v1.push_back(p2); v1.push_back(p3);

	////Housekeeping - one-by-one the list of unwanted objects is removed
	//cout << "\nDeleting...\n";
	//while (!v1.empty()) {
	//	Student* pLast = v1[v1.size() - 1];
	//	v1.pop_back();
	//	delete pLast;
	//}
	////at this point v1 is empty and pointed objects are deleted (for real!)

	//create vector v2
	cout << "\nStep 3 - Holds four, five, and six\n";
	vector<Student*> v2{ p4, p5, p6 };
	for (Student* p : v2) cout << p->toString() << endl;

	cout << "Step4 - v2 has been cleared and reloaded with independent v1 clones\n";
	//clear v2, copy v1 into v2
	v2.clear();
	for (Student* ps : v1)
	{
		//Independent cloning of each object (it preserves the original p1, p2, p3)
		Student* newPtr = new Student();
		*newPtr = *ps;
		v2.push_back(newPtr);
	}

	//Show that v2 and v1 have different lists of pointers (although same info)
	cout << "\nThis is v1\n";
	for (Student* p : v1) cout << p->toString() << endl;

	cout << "\nThis is v2\n";
	for (Student* p : v2) cout << p->toString() << endl;

	//Testing the Club class - Create a Poetry club
	cout << "Step5 - This is the Poetry club (new people that we do not own)\n";

	//Making new People (not owned by the club!)
	Student* p7 = new Student("S0777", "Maya Angelou");
	Student* p8 = new Student("S0888", "Allan Poe");
	Student* p9 = new Student("S0999", "Robert Frost");
	Student* p10 = new Student("S1110", "Sor Juana");

	Club c0(new string("Poetry"), vector<Student*> {p7, p8, p9, p10});
	cout << "\n\nThis is Club c0: " << *(c0.getClubNamePtr()) << endl;
	cout << c0.toString(" c0 ") << endl;

	// Create a Photography club
	Club c1(new string("Photography"), vector<Student*> { p1, p2, p3 });
	cout << "\n\nThis is Club c1: " << *(c1.getClubNamePtr()) << endl;
	cout << c1.toString(" c1 ") << endl;

	Student* spy1 = c1.getVectorStudentPtr()[0];

	//Testing copy-constructor and operator=

	Club c2(c1);
	cout << "\n\nStep6 - Cloning club c1 into c2 - This is the new Club c2\n";
	cout << c2.toString(" c2 ") << endl;

	cout << "SPY node old c1 " << spy1->toString(" spy1 ") << endl;

	//Rename the clone C2 to "Chess" club
	c2.setClubNamePtr(new string("Chess"));
	//add new member to the chess club
	c2.addNewMemberPtr(new Student("S1222", "Kasparov"));
	cout << "\n\nStep7 - This is the new chess Club c2\n";
	cout << c2.toString(" c2 ") << endl;

	//Test again the copy-constructor and operator=
	c2 = c0;
	//add new member to the photography club
	c1.addNewMemberPtr(new Student("S1333", "Mr. Kodak", "Graphic Arts", 4.0));

	cout << "\n\nStep8 - Cloning club c0 into c2 - This is the new Club c2\n";
	cout << c2.toString(" c2 ") << endl;




	////Testing operator<<
	//cout << "\noverloaded<< c1 \n" << c1 << endl;

	////Testing findClubMemberPtr function
	//cout << "\nTesting findClubMemberPtr\n";
	//Student* memAddress = c1.findClubMemberPtr("Mr.", "Kodak");
	//cout << " Loc. Mr. Kodak is: " << memAddress << endl;

}

