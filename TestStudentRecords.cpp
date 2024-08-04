#include "StudentRecords.h"

int main(void) {
	ofstream outfile("StudentRecords.txt", ios::app);
	ifstream infile("StudentRecords.txt", ios::app);

	int n = 0, num;
	gradStudent stu;

	cout << "REGISTRATION MANAGER" << endl;
	cout << "Choose an option from menu 1 to 7" << endl;
	cout << "1) Register a new student" << endl;
	cout << "2) Edit a student's record" << endl;
	cout << "3) Delete a student's record" << endl;
	cout << "4) Display a student's record" << endl;
	cout << "5) Display all the student records" << endl;
	cout << "6) Empty Database" << endl;
	cout << "7) Number of students registered" << endl;
  

	while (1)
	{
		cout << endl;
		cout << "Menu number(Enter 0 to quit): ";
		cin >> num;
		if (num == 1) {
			// Register student
			stu.setmenu(num); // sets menu to num
			stu.resetcount(); //set count to 0
			cin >> stu; // reads into the gradstudent
			outfile << stu; // print the gradstudent to the file
			stu.resetcount(); // set count to 0
		}
		else if (num == 2) {
			// edit Student
			stu.setmenu(num); // sets menu to num
			infile >> stu; // reads for the file to stu
			ofstream outfile2("StudentRecords.txt"); // Opens StudentRecord as a new file
			outfile2 << stu; // print the gradstudent to the file
			outfile2.close(); // terminates the file
			stu.resetcount(); // set the count to 0
		}
		else if (num == 3) {
			// delete Student
			stu.setmenu(num); // sets menu to num
			infile >> stu; // reads for the file to stu
			stu.deleterecord(); // delete the required record
			ofstream outfile1("StudentRecords.txt");
			outfile1 << stu; // print the gradstudent to the file
			outfile1.close(); // terminates the file
			stu.resetcount(); // set the count to 0
		}
		else if (num == 4) {
			// display Student
			stu.setmenu(num); // sets menu to num
			infile >> stu; // reads for the file to stu
			cout << stu; // print out on the console the required student
			stu.resetcount(); // set the count to 0
		}
		else if (num == 5) {
			// display all Students
			stu.setmenu(num); // sets menu to num
			infile >> stu; // reads for the file to stu
			cout << stu; // print all the student recors to the screen
			stu.resetcount(); // set the count to 0
			stu.clrsize();
		}
		else if (num == 6) {
			// empty Students
			stu.setmenu(num);
			ofstream outfile1("StudentRecords.txt"); // Creates a new file for writing
			cin >> stu;
			outfile1.close(); // terminates the file
			stu.clrsize();
		}
		else if (num == 7) {
			// count Students
			stu.setmenu(num); // sets menu to num
			infile >> stu; // reads for the file to stu
			cout << stu; // print out the number of student
			stu.resetcount(); // set the count to 0
		}
		else if (num == 0) {
			break;
		}
		else
		{
			cout << num << " is not part of the menu" << endl;
		}
	}

	infile.close(); // close the reading file
	outfile.close(); // close the writing file
	return 0;
}