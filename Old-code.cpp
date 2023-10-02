//// C15-Person-Student-Graduate-Faculty-Club-PART7.cpp 
//
//#include "MyHeader.h"
//#include "Person.h"
//#include "Student.h"
//#include "Graduate.h"
//#include "GraduateMI.h" //Multiple-Inheritance - NOT TOO GOOD! 
//#include "GraduatePtr.h"
//#include "Faculty.h"
//#include "Faculty2.h"
//#include "Club.h"
//#include "ClubSmart.h"
//#include <memory>
//
////----------------------------------------------------------------------------
//void experiment01();	// Test inheritance-Hierarchy and Aggregation
//void experiment02();	// Test Multiple Inheritance
//void experiment03();	// Faculty class is-a Person and has Students (advisees)
//void experiment04();	// Faculty class is-a Person and has Students (advisees)
//// Graduate students point to the Faculty
//void experiment05();	// Faculty class is-a Person and has a vector of pointers 
//// to Students (advisees). Graduate students point to the Faculty
//void experiment05B();
//
//void experiment06();	// Testing the Club class - Using RAW Pointers
//
//void experiment07();	// Testing the Club clas - Using SMART Pointers
//
////----------------------------------------------------------------------------
//int main()
//{
//	//Testing Single-Inheritance and Aggregation
//	//experiment01();
//
//	// Using Multiple Inheritance (not recommended!!!)
//	//experiment02();  //Test Multiple Inheritance
//
//	//Test the Faculty class
//	//experiment03();
//
//	// Faculty class is-a Person and has Students (advisees)
//	// Graduate students point to the Faculty
//	//experiment04();
//
//	//Faculty2 is a better implementation. It has pointers to students (advisees)
//	//experiment05();   //advisees are in the STACK (cannot be deleted)
//	//experiment05B();	//advisees are in the HEAP (must be deleted)
//
//	//Testing the Club class - Total data ownership (NO SHARED POINTER-BASED DATA)
//	//experiment06(); 
//
//	//Testing the Club class - Shared data ownership - Smart pointers
//	experiment07();
//
//	cout << "\nAll done!\n";
//
//
//}
////--------------------------------------------------------------------------------
//void experiment01()
//{
//	//A common Person
//	Person p1("Mr.", "Dobby");
//	cout << p1.toString("p1 ") << endl;
//
//	//intentional misspelling of Student student name
//	Student s1("Mr.", "HaRrY  POTTer", "Wizardry", 4.0);
//	cout << s1.toString(" s1 ") << endl;
//
//	//A Graduate Student (advisor is an aggregation)
//	Graduate g1("Mr.", "Elastic", "Chemistry", 3.95, "Invisible Glue", "Dr.", "No");
//	cout << endl << g1.toString() << endl;
//
//	//How an existing Person (such as Dobby) becomes a Student?
//	Student gp1(&p1, "Magical Spells", 3.99);  //The param &p is used to create a copy!
//	cout << gp1.toString() << endl;
//	//change Person's p1 name
//	p1.setSalutation("Master");
//	cout << p1.toString() << endl;
//	//Did the change to p1 affect gp1?  // NO!
//	cout << gp1.toString() << endl;
//}
//
//
//
//void experiment02()
//{
//	GraduateMI g2("Mrs.", "Diana Prince", "Aerospace Eng", 3.99,
//		"Molecular Transmutation",
//		"Dr.", "Strange");
//	cout << endl << g2.toString() << endl;
//
//	g2.setAdvName("Seuss");
//
//	cout << endl << g2.toString() << endl;
//	cout << endl << "Adv name: " << g2.getAdvisor()->toString() << endl;
//
//}
//
//void experiment03()
//{
//	// Faculty class is-a Person and has Students (advisees)
//	Faculty f1("Dr", "Xavier", "MBA346");
//	//Creating students
//	Student  s1("Mr.", "HaRrY  POTTer", "Wizardry", 4.0);
//	Graduate g1("Mrs.", "Diana Prince", "Aerospace Eng", 3.99,
//		"Aerodynamic Archery", f1.getSalutation(), f1.getName());
//
//	f1.addStudent(s1);
//	f1.addStudent(g1);
//	cout << f1.toString() << endl;
//
//	cout << " s1 " << s1.toString() << endl;
//	cout << " g1 " << g1.toString() << endl;
//
//}
////-----------------------------------------------------------------------------------------
//void experiment04() 	// Faculty class is-a Person and has Students (advisees)
//// Graduate students point to the Faculty
//{
//	// Faculty class is-a Person and has Students (advisees)
//	Faculty f1("Dr", "Xavier", "MBA346");
//
//	//Creating students
//	Student  s1("Mr.", "HaRrY  POTTer", "Wizardry", 4.0);
//	cout << " s1 " << s1.toString() << endl;
//
//	Graduate g1("Mr.", "Elastic", "Chemistry", 3.95, "Invisible Glue", "Dr.", "Xavier");
//	cout << " g1 " << g1.toString() << endl;
//
//	Graduate g2("Mrs.", "Diana Prince", "Aerospace Eng", 3.99,
//		"Aerodynamic Archery", f1.getSalutation(), f1.getName());
//	cout << " g2 " << g2.toString() << endl;
//
//	GraduatePtr g3("Mr.", "Peter Parker", "Comp. Sc", 3.95, "Complex Webs", &f1);
//	cout << " g3 " << g3.toString() << endl;
//
//	cout << "\nTesting the Faculty class\n";
//	f1.addStudent(s1);
//	f1.addStudent(g1);
//	f1.addStudent(g2);
//	f1.addStudent(g3);
//
//	cout << " f1 " << f1.toString() << endl;
//
//}
//
////--------------------------------------------------------------------------------
//void experiment05() 	// Faculty class is-a Person and has Students (advisees)
//// Graduate students point to the Faculty
//// All advisees are in the STACK 
//{
//	// Faculty class is-a Person and has Students (advisees)
//	Faculty2 f1("Dr", "Xavier", "MBA346");
//
//	//Creating students
//	Student  s1("Mr.", "HaRrY  POTTer", "Wizardry", 4.0);
//	cout << " s1 " << s1.toString() << endl;
//
//
//
//	Graduate g1("Mr.", "Reed Richards", "Chemistry", 3.95, "Invisible Glue", "Dr.", "Xavier");
//	cout << " g1 " << g1.toString() << endl;
//
//	Graduate g2("Mrs.", "Diana Prince", "Aerospace Eng", 3.99,
//		"Aerodynamic Archery", f1.getSalutation(), f1.getName());
//	cout << " g2 " << g2.toString() << endl;
//
//	GraduatePtr g3("Mr.", "Peter Parker", "Comp. Sc", 3.95, "Complex Webs", &f1);
//	cout << " g3 " << g3.toString() << endl;
//
//	cout << "\nTesting the Faculty class\n";
//
//	f1.addStudent(&s1);			//all this objects are in the stack!
//	f1.addStudent(&g1);
//	f1.addStudent(&g2);
//	f1.addStudent(&g3);
//
//	cout << " f1 " << f1.toString() << endl;
//	g1.setName("Mr. Fantastic");
//	g2.setName("Wonder Woman");
//	g3.setName("Spiderman");
//	cout << " f1 " << f1.toString() << endl;
//}
//
////--------------------------------------------------------------------------------
//void experiment05B() 	// Faculty class is-a Person and has Students (advisees)
//// Graduate students point to the Faculty
//// Faculty and ALL advisees are in the HEAP
//{
//	cout << "\nexperiment05B begins\n";
//	// Faculty class is-a Person and has Students (advisees)
//	Faculty2* f1 = new Faculty2("Dr", "Xavier", "MBA346");
//
//	//Creating students
//	Student* s1 = new Student("Mr.", "HaRrY  POTTer", "Wizardry", 4.0);
//	cout << " s1 " << s1->toString() << endl;
//
//
//
//	Graduate* g1 = new Graduate("Mr.", "Reed Richards", "Chemistry", 3.95, "Invisible Glue", "Dr.", "Xavier");
//	cout << " g1 " << g1->toString() << endl;
//
//	Graduate* g2 = new Graduate("Mrs.", "Diana Prince", "Aerospace Eng", 3.99,
//		"Aerodynamic Archery", f1->getSalutation(), f1->getName());
//	cout << " g2 " << g2->toString() << endl;
//
//	GraduatePtr* g3 = new GraduatePtr("Mr.", "Peter Parker", "Comp. Sc", 3.95, "Complex Webs", f1);
//	cout << " g3 " << g3->toString() << endl;
//
//	cout << "\nTesting the Faculty class\n";
//
//	f1->addStudent(s1);
//	f1->addStudent(g1);
//	f1->addStudent(g2);
//	f1->addStudent(g3);
//
//	cout << " f1 " << f1->toString() << endl;
//	g1->setName("Mr. Fantastic");
//	g2->setName("Wonder Woman");
//	g3->setName("Spiderman");
//	cout << " f1 " << f1->toString() << endl;
//
//	//Housekeeping - 
//	cout << "\nexperiment05B is over - Faculty2 destructor SHOULD delete all\n";
//	delete f1;
//
//	{
//		Faculty2* f2 = new Faculty2("Mr.", "T");
//		f2->addStudent(new Student("Mrs", "Robinson"));
//		cout << " f2 " << f2->toString() << endl;
//		delete f2;
//	}
//	cout << "Leaving the block. f2 is out of scope\n";
//}
//
////---------------------------------------------------------------------------
//void experiment06()
//{
//	//Experiment. Show you delete heap objects whose addresses are held
//	//            in a vector<> when the app is over?  YES!
//	//-----------------------------------------------------------------------
//	Student* p1 = new Student("Mrs.", "One");
//	Student* p2 = new Student("Mr.", "Two");
//	Student* p3 = new Student("Ms.", "Three");
//
//	Student* p4 = new Student("Mrs.", "Four");
//	Student* p5 = new Student("Mr.", "Five");
//	Student* p6 = new Student("Ms.", "Six");
//
//
//	vector<Student*> v1{ p1, p2, p3 };
//	for (Student* p : v1) cout << p->toString() << endl;
//
//	//Clearing a vector holding pointers doesn't delete the pointed objects!
//	//v1.clear();   //pointer list is erased - however...
//
//	//cout << " After clear - vector's size is " << v1.size() << endl;
//	//cout << "ALIVE p1 " << p1->toString(" p1 ") << endl;
//	//cout << "ALIVE p2 " << p2->toString(" p2 ") << endl;
//	//cout << "ALIVE p3 " << p3->toString(" p3 ") << endl;
//
//	//Reload v1 with p1, p2, and p3.
//	//v1.push_back(p1); v1.push_back(p2); v1.push_back(p3);
//
//	//Housekeeping - one-by-one the list of unwanted objects is removed
//	cout << "\nDeleting...\n";
//	while (!v1.empty()) {
//		Student* pLast = v1[v1.size() - 1];
//		v1.pop_back();
//		delete pLast;
//	}
//	//at this point v1 is empty and pointed objects are deleted (for real!)
//
//	//create vector v2
//	cout << "\nThis is v2\n";
//	vector<Student*> v2{ p4,p5,p6 };
//	for (Student* p : v2) cout << p->toString() << endl;
//
//	//copy from v2 into v1
//	for (Student* ps : v2)
//	{
//		Student* newPtr = new Student();
//		*newPtr = *ps;
//		v1.push_back(newPtr);
//	}
//
//	//Show that v2 and v1 have different lists of pointers (although same info)
//	cout << "\nThis is v1\n";
//	for (Student* p : v1) cout << p->toString() << endl;
//
//	//Testing the Club class
//	Club c0(new string("Poetry"),
//		vector<Student*>
//	{
//		new Student("Mrs.", "Maya Angelou"),
//			new Student("Mr.", "Allan Poe"),
//			new Student("Mr.", "Robert Frost"),
//			new Student("Sor", "Juana Ines de la Cruz"),
//	});
//	cout << "\n\nThis is Club c0\n";
//	cout << c0.toString(" c0 ") << endl;
//
//	cout << "\n\nThis is Club c1\n";
//	Club c1(new string("Photography"), vector<Student*> { p1, p2, p3 });
//	cout << c1.toString(" c1 ") << endl;
//
//	//Testing copy-constructor and operator=
//	Club c2(c1);
//	cout << "\n\nThis is Club c2\n";
//	cout << c2.toString(" c2 ") << endl;
//
//	//Rename the clone to "Chess" club
//	c2.setClubNamePtr(new string("Chess"));
//	//add new member to the chess club
//	c2.addNewMemberPtr(new Student("Mr.", "G. Kasparov"));
//
//	//add new member to the photography club
//	c1.addNewMemberPtr(new Student("Mr.", "Kodak", "Graphic Arts", 4.0));
//
//	//Show Photography and Chess club members
//	cout << "\n\nThis is Club c1 (Photography)\n";
//	cout << c1.toString(" c1 ") << endl;
//	cout << "\n\nThis is Club c2 (Chess)\n";
//	cout << c2.toString(" c2 ") << endl;
//
//
//	//Testing operator<<
//	cout << "\noverloaded<< c1 \n" << c1 << endl;
//
//	//Testing findClubMemberPtr function
//	cout << "\nTesting findClubMemberPtr\n";
//	Student* memAddress = c1.findClubMemberPtr("Mr.", "Kodak");
//	cout << " Loc. Mr. Kodak is: " << memAddress << endl;
//
//}
//
//
////---------------------------------------------------------------------------
//void experiment07()
//{
//	//-----------------------------------------------------------------------
//	// Using SMART POINTERS
//	//-----------------------------------------------------------------------
//
//	// Raw pointers
//	Student* p1 = new Student("Mrs.", "One");
//	Student* p2 = new Student("Mr.", "Two");
//	Student* p3 = new Student("Ms.", "Three");
//
//	//Smart pointers
//	shared_ptr<Student> p4(new Student("Mrs.", "Four"));
//	shared_ptr<Student> p5(new Student("Mr.", "Five"));
//	shared_ptr<Student> p6(new Student("Ms.", "Six"));
//
//
//	//Show vector<RAW PTRS>	
//	vector<Student*> v1{ p1, p2, p3 };
//	for (Student* p : v1) cout << p->toString(" RAW\t") << endl;
//
//	//----------------------------------------------------------------------
//	//Clearing a vector holding pointers doesn't delete the pointed objects!
//	v1.clear();   //pointer list is erased - however...
//	cout << " After v1.clear() - vector's size is " << v1.size() << " However, " << endl;
//	cout << "ALIVE p1 " << p1->toString(" p1 ") << endl;
//	cout << "ALIVE p2 " << p2->toString(" p2 ") << endl;
//	cout << "ALIVE p3 " << p3->toString(" p3 ") << endl;
//
//
//
//	//Re-store zombies p1, p2, and p3 in v1
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//	for (Student* p : v1) cout << p->toString(" v1 again\t") << endl;
//	//Delete all Students referenced by v1 - at the end, clear v1
//	while (!v1.empty())
//	{
//		cout << " Deleting p from vector ...\n";
//		Student* p = v1.back();
//		v1.pop_back();
//		delete p;
//	}
//	cout << "Clearing v1...\n";
//	v1.clear();
//
//	//Show vector holding SMART PTRS
//	vector< shared_ptr<Student> > v2{ p4, p5, p6 };
//	for (shared_ptr< Student> p : v2)
//	{
//		cout << p->toString(" SMART\t") << endl;
//		cout << " SMART  TYPE: " << typeid(p).name() << endl;
//	}
//
//	//Create two raw pointer - wrap them with a smart pointer
//	Student* p7 = new Student("Mr", "Seven");
//	Student* p8 = new Student("Mr", "Eight");
//
//	//Upcasting raw p7 and p8 to the smart-pointer category
//	shared_ptr<Student> sp7(p7);
//	cout << "\n SMART \t" << sp7->toString(" sp7 ") << endl;
//
//	shared_ptr<Student> sp8 = (shared_ptr<Student>) p8;
//	cout << "\n SMART \t" << sp8->toString(" sp8 ") << endl;
//
//	cout << " Vector vsmart created with shared_ptrs \n";
//	vector<shared_ptr<Student>> vsmart{ sp7, sp8 };
//	cout << " Vector vsmart is asked to clear() \n";
//	vsmart.clear();
//	cout << " Immediately after vsmart.clear()\n";
//	cout << " Showing sp7 which was part of vsmart (now empty!)\n";
//	cout << " ALIVE " << sp7->toString(" sp7 ") << endl;
//
//	//---------------------------------------------------------------------
//	// Can a raw pointer be (downcasted) initialized with a smart pointer?
//	// NO - we cannot downcast a smart pointer to become a raw pointer.
//	//Student* rawptr1(sp7);							//error
//	//Student* rawptr2 = (Student*) (sp7);			//error
//	//Student* rawptr3 = (shared_ptr<Student>)(sp7);	//error
//
//
//
//	//Testing the ClubSmart class
//	ClubSmart c1(make_shared<string>("Poetry"),
//		vector<shared_ptr<Student>>
//	{
//		make_shared<Student>("Mrs.", "Maya Angelou"),
//			make_shared<Student>("Mr.", "Allan Poe"),
//			make_shared<Student>("Mr.", "Robert Frost"),
//			make_shared<Student>("Sor", "Juana Ines de la Cruz"),
//	});
//
//	cout << "\n\nThis is ClubSmart c1\n";
//	cout << c1.toString(" c1 ") << endl;
//
//	//Testing copy-constructor and operator=
//	ClubSmart c2(c1);
//	cout << "\n\nThis is Club c2\n";
//	cout << c2.toString(" c2 ") << endl;
//
//	//Rename the clone to "Chess" club
//	c2.setClubNamePtr(make_shared<string>("Chess"));
//	//add new member to the chess club
//	c2.addNewMemberPtr(make_shared<Student>("Mr.", "G. Kasparov"));
//
//	cout << "\n\nThis is Club c2 (Chess)\n";
//	cout << c2.toString(" c2 ") << endl;
//
//
//	//Testing operator<<
//	cout << "\noverloaded<< c1 \n" << c1 << endl;
//
//	//Testing retrieval using findClubMemberPtr function
//	cout << "\nTesting findClubMemberPtr\n";
//	shared_ptr<Student> memAddress = c2.findClubMemberPtr("Mr.", "G. Kasparov");
//	cout << *c2.getClubNamePtr()
//		<< " Location of Mr. G. Kasparov is: " << memAddress << endl;
//
//}