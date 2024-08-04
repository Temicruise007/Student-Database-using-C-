#include "StudentRecords.h"



//*****************Implementing date*************************
date::date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

istream& operator>>(istream& in, date& dt) {
	char discard;
	in >> dt.day >> discard >> dt.month >> discard >> dt.year;
	return in;
}

ostream& operator<<(ostream& out, const date& dt) {
	out << to_string(dt.day) + "/" + to_string(dt.month) + "/" + to_string(dt.year);
	return out;
}


//*************** Implementing Students******************

student::student(string f, string l, vector <string> stu_idarray, vector <string> f_a, vector <string> l_a, vector <string> p_a, int c, vector <date> reg_dtarray, int d, int m, int y, int mu)
	:reg_date(d, m, y) {
	student_idarray = stu_idarray;
	firstnamearray = f_a;
	lastnamearray = l_a;
	programarray = p_a;
	count = c;
	reg_datearray = reg_dtarray;
	menu = mu;
}

string student::generate_id() {   // Function to generate Student ID
	int val;
	string str, str1, str2, userid;
	str1 = tolower(firstname[0]);
	str2 = tolower(lastname[0]);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 6; ++i) {
		val = rand() % 10; // generates a random number from 0 to 9
		str.append(to_string(val));
	}
	userid = str1 + str2 + str;
	return userid;
}

void student::deleterecord(void) {    // Function to delete a student's record;
	if (student_idarray.size() == count) {
		cout << "Student does not exist" << endl;
	}
	else
	{
		int j;
		for (j = count; j < student_idarray.size() - 1; j++)
		{
			student_idarray[j] = student_idarray[j + 1];
			firstnamearray[j] = firstnamearray[j + 1];
			lastnamearray[j] = lastnamearray[j + 1];
			programarray[j] = programarray[j + 1];
			reg_datearray[j] = reg_datearray[j + 1];
		}
		downsize();
	}
}

int student::getmenu(void)const {  // returns the menu
	return menu;
}

int student::getcount(void)const {    // returns the count value
	return count;
}

void student::upsize(void) {    // increments all the vectors by 1
	student_idarray.resize(student_idarray.size() + 1);
	firstnamearray.resize(firstnamearray.size() + 1);
	lastnamearray.resize(lastnamearray.size() + 1);
	programarray.resize(programarray.size() + 1);
	reg_datearray.resize(reg_datearray.size() + 1);
}

void student::downsize(void) {     // decrements all the vectors by 1
	student_idarray.resize(student_idarray.size() - 1);
	firstnamearray.resize(firstnamearray.size() - 1);
	lastnamearray.resize(lastnamearray.size() - 1);
	programarray.resize(programarray.size() - 1);
	reg_datearray.resize(reg_datearray.size() - 1);
}

void student::clrsize(void) {      // clear all the vectors
	student_idarray.resize(0);
	firstnamearray.resize(0);
	lastnamearray.resize(0);
	programarray.resize(0);
	reg_datearray.resize(0);
}

vector<string> student::getstudent_idarray()const {
	return student_idarray;
}

vector<string> student::getfirstnamearray()const {
	return firstnamearray;
}

vector<string> student::getlastnamearray()const {
	return lastnamearray;
}

vector<string> student::getprogramarray()const {
	return programarray;
}

vector<date> student::getreg_datearray()const {
	return reg_datearray;
}


void student::addstudent_id(string stu_id) {     // adds student id to the student id vector
	student_idarray[count] = stu_id;
}

void student::addfirstname(string f) {      // adds firstname to the firstname vector
	string back = "", joined, front;
	for (int i = 1; i < f.size(); i++) {
		back = back + f[i];
	}
	front = toupper(f[0]);
	joined = front + back;
	firstnamearray[count] = joined;
}

void student::addlastname(string l) {       // adds lastname to the lastname vector
	string back = "", joined, front;
	for (int i = 1; i < l.size(); i++) {
		back = back + l[i];
	}
	front = toupper(l[0]);
	joined = front + back;
	lastnamearray[count] = joined;
}

void student::addprogram(string p) {        // adds program to the program array
	string back = "", joined, front;
	for (int i = 1; i < p.size(); i++) {
		back = back + p[i];
	}
	front = toupper(p[0]);
	joined = front + back;
	programarray[count] = joined;
}

void student::addreg_date(date d) {       // adds registration date to the registration date array
	reg_datearray[count] = d;
}

void student::incrementcount(void) {    // increments the count by 1
	count++;
}

void student::resetcount(void) {        // sets the count to 0
	count = 0;
}

void student::setmenu(int mu) {         // Tells the program which menu to go with
	menu = mu;
}


void student::read(istream& in) {
	if (menu == 1) {   // Add New Student
		upsize();
		cout << "Enter Firstname: ";
		in >> firstname;
		firstnamearray[count] = firstname;
		cout << "Enter Lastname: ";
		in >> lastname;
		lastnamearray[count] = lastname;
		cout << "Enter Engineering Program: ";
		in >> program;
		programarray[count] = program;
		cout << "Registration Date(dd/mm/yyyy): ";
		in >> reg_date;
		reg_datearray[count] = reg_date;
		cout << endl;
		student_id = generate_id();
		cout << "Your student ID is " << student_id << endl << endl;
		student_idarray[count] = student_id;
	}
	else if (menu == 2) {   // Edit a student's record
		string stu_id, n_p;
		char dt_check;
		date n_regdt;
		int i;
		cout << "Enter Student ID: ";
		cin >> stu_id;
		i = indexsearch(stu_id, student_idarray);
		count = i;
		if (count == student_idarray.size()) {
			cout << "Student does not exist" << endl;
		}
		else
		{
			cout << endl;
			cout << "Editing Record of " << firstnamearray[count] << " " << lastnamearray[count] << endl;
			cout << "NOTE: For the field(s) you DON'T want to change, put '-' OTHERWISE, Enter the new value for the field" << endl;
			cout << "Enter New Program: ";
			cin >> n_p;
			if (n_p == "-") {}
			else
			{
				programarray[count] = n_p;
			}
			while (1)
			{
				cout << "Do you want to change the registration date (Y/N): ";
				cin >> dt_check;
				if (dt_check == 'N' || dt_check == 'n') {
					break;
				}
				else if (dt_check == 'Y' || dt_check == 'y')
				{
					cout << "Enter New Registration Date: ";
					cin >> n_regdt;
					reg_datearray[count] = n_regdt;
					break;
				}
				else
				{
					cout << "invalid entry Your input should be (Y/N)" << endl;
				}
			}
		}
	}
	else if (menu == 3) {
		string stu_id;
		int i;
		cout << "Enter Student ID: ";
		cin >> stu_id;
		i = indexsearch(stu_id, student_idarray);
		count = i;
		if (count == student_idarray.size()) {
		
		}
		else
		{
			cout << "Deleting record of " << firstnamearray[count] << " " << lastnamearray[count] << endl;
		}
	}
	else if (menu == 4) {
		string stu_id;
		int i;
		cout << "Enter Student ID: ";
		cin >> stu_id;
		i = indexsearch(stu_id, student_idarray);
		count = i;
	}
	else if (menu == 5) {}
	else if (menu == 6) {}
	else if (menu == 7) {}
}

void student::write(ostream& out, int i)const {
	if (menu == 1) {
		string space = "        ";
		out.width(20); out << left << student_id;
		out.width(20); out << left << firstname;
		out.width(20); out << left << lastname;
		out.width(20); out << left << program;
		out.width(20); out << left << reg_date;
	}
	else if (menu == 2) {
		out.width(20); out << left << student_idarray[i];
		out.width(20); out << left << firstnamearray[i];
		out.width(20); out << left << lastnamearray[i];
		out.width(20); out << left << programarray[i];
		out.width(20); out << left << reg_datearray[i];
	}
	else if (menu == 3) {
		out.width(20); out << left << student_idarray[i];
		out.width(20); out << left << firstnamearray[i];
		out.width(20); out << left << lastnamearray[i];
		out.width(20); out << left << programarray[i];
		out.width(20); out << left << reg_datearray[i];
	}
	else if (menu == 4) {
		out.width(20); out << left << student_idarray[i];
		out.width(20); out << left << firstnamearray[i];
		out.width(20); out << left << lastnamearray[i];
		out.width(20); out << left << programarray[i];
		out.width(20); out << left << reg_datearray[i];
	}
	else if (menu == 5) {
		out.width(20); out << left << student_idarray[i];
		out.width(20); out << left << firstnamearray[i];
		out.width(20); out << left << lastnamearray[i];
		out.width(20); out << left << programarray[i];
		out.width(20); out << left << reg_datearray[i];
	}
	else if (menu == 6) {

	}
	else if (menu == 7) {
		if (i == 0) {
			out << "THERE ARE NO REGISTERED STUDENT!!!";
		}
		else
		{
			out << "There are currently " << i << " registered students" << endl;
		}
	}
}

//*****************Implementing graduateStudent************************

gradStudent::gradStudent(string f, string l, vector<string> stu_idarray, vector<string> f_a, vector<string> l_a, vector<string> p_a, int c, vector<date> reg_dtarray, int d, int m, int y, int mu, string tt, string s, vector<string> tt_a, vector<string> s_a)
	:student(f, l, stu_idarray, f_a, l_a, p_a, c, reg_dtarray, d, m, y, mu)
{
	thesis_title = tt;
	supervisor = s;
	thesis_titlearray = tt_a;
	supervisorarray = s_a;
}

void gradStudent::addthesis_title(string tt) {       // adds thesis title to the thesis title vector
	string back = "", joined, front;
	for (int i = 1; i < tt.size(); i++) {
		back = back + tt[i];
	}
	front = toupper(tt[0]);
	joined = front + back;
	thesis_titlearray[getcount()] = joined;
}

void gradStudent::addsupervisor(string s) {        // add supervisor to the supervisor vector
	string back = "", joined, front;
	for (int i = 1; i < s.size(); i++) {
		back = back + s[i];
	}
	front = toupper(s[0]);
	joined = front + back;
	supervisorarray[getcount()] = joined;
}

void gradStudent::deleterecord(void) {
	student::deleterecord();
	if (thesis_titlearray.size() == getcount()) {

	}
	else
	{
		int j;
		for (j = student::getcount(); j < thesis_titlearray.size() - 1; j++)
		{
			thesis_titlearray[j] = thesis_titlearray[j + 1];
			supervisorarray[j] = supervisorarray[j + 1];
		}
		downsize();
	}
}

void gradStudent::downsize(void) {
	thesis_titlearray.resize(thesis_titlearray.size() - 1);
	supervisorarray.resize(supervisorarray.size() - 1);
}

void gradStudent::upsize(void) {
	student::upsize();
	thesis_titlearray.resize(thesis_titlearray.size() + 1);
	supervisorarray.resize(supervisorarray.size() + 1);
}

void gradStudent::clrsize(void) {
	student::clrsize();
	thesis_titlearray.resize(0);
	supervisorarray.resize(0);
}

void gradStudent::getvectors(istream& in) {
	vector <string> a, b, c, d, f, g;
	vector <date> e;
	vectoresize(a, b, c, d, e, f, g);
	int n = 0;
	resetcount();
	clrsize();
	while (in >> a[n] >> b[n] >> c[n] >> d[n] >> e[n] >> f[n] >> g[n]) {
		vectoresize(a, b, c, d, e, f, g);
		upsize();
		addstudent_id(a[n]);
		addfirstname(b[n]);
		addlastname(c[n]);
		addprogram(d[n]);
		addreg_date(e[n]);
		addthesis_title(f[n]);
		addsupervisor(g[n]);
		incrementcount();
		n++;
	}
}

istream& operator>>(istream& in, gradStudent& s) {
	if (s.getmenu() == 1) {     // Add New Student
		s.read(in);
		s.upsize();
		cout << "NOTE: For the field(s) not available, put '-' OTHERWISE, Enter the value for the field" << endl;
		cout << "Enter Supervisor's name: ";
		in >> s.supervisor;
		s.supervisorarray[s.getcount()] = s.supervisor;
		cout << "Enter Thesis Title: ";
		in >> s.thesis_title;
		s.thesis_titlearray[s.getcount()] = s.thesis_title;
	}
	else if (s.getmenu() == 2) {      // Edit a student's record
		in.clear();
		in.seekg(0);
		s.getvectors(in);
		s.read(in);
		if (s.thesis_titlearray.size() == s.getcount()) {

		}
		else
		{
			string n_s, n_tt;
			cout << "Enter New Supervisor: ";
			cin >> n_s;
			if (n_s == "-") {}
			else
			{
				s.supervisorarray[s.getcount()] = n_s;
			}
			cout << "Enter New Thesis Title: ";
			cin >> n_tt;
			if (n_tt == "-") {}
			else
			{
				s.thesis_titlearray[s.getcount()] = n_tt;
			}
		}
	}
	else if (s.getmenu() == 3) {
		in.clear();
		in.seekg(0);
		s.getvectors(in);
		s.read(in);
	}
	else if (s.getmenu() == 4) {
		in.clear();
		in.seekg(0);
		s.getvectors(in);
		s.read(in);
	}
	else if (s.getmenu() == 5) {
		in.clear();
		in.seekg(0);
		s.getvectors(in);
	}
	else if (s.getmenu() == 6) {
		s.clrsize();
	}
	else if (s.getmenu() == 7) {
		in.clear();
		in.seekg(0);
		s.getvectors(in);

	}
	return in;
}


ostream& operator<<(ostream& out, const gradStudent& s) {
	if (s.getmenu() == 1) {
		s.write(out, 0);
		if (s.thesis_titlearray[s.getcount()] == "-") {
			out.width(20); out << left << "NA";
		}
		else
		{
			out.width(20); out << left << s.thesis_titlearray[s.getcount()];
		}
		if (s.supervisorarray[s.getcount()] == "-") {
			out.width(20); out << left << "NA" << endl;
		}
		else
		{
			out.width(20); out << left << s.supervisorarray[s.getcount()] << endl;
		}
	}
	else if (s.getmenu() == 2) {
		if (s.thesis_titlearray.size() == s.getcount()) {}
		else {
			for (int i = 0; i < s.thesis_titlearray.size(); i++) {
				s.write(out, i);
				out.width(20); out << left << s.thesis_titlearray[i];
				out.width(20); out << left << s.supervisorarray[i] << endl;
			}
		}

		out << endl;

	}
	else if (s.getmenu() == 3) {
		if (s.thesis_titlearray.size() == (s.getcount() - 1)) {}
		else {
			for (int i = 0; i < s.thesis_titlearray.size(); i++) {
				s.write(out, i);
				out.width(20); out << left << s.thesis_titlearray[i];
				out.width(20); out << left << s.supervisorarray[i] << endl;
			}
		}

		out << endl;
	}
	else if (s.getmenu() == 4) {
		out << endl;
		out.width(20); out << left << "STUDENT ID";
		out.width(20); out << left << "FIRSTNAME";
		out.width(20); out << left << "LASTNAME";
		out.width(20); out << left << "PROGRAM";
		out.width(20); out << left << "REGISTRATION DATE";
		out.width(20); out << left << "THESIS TITTLE";
		out.width(20); out << left << "SUPERVISOR" << endl;
		if (s.thesis_titlearray.size() == s.getcount()) {
			out << "Student does not exist" << endl;
		}
		else
		{
			s.write(out, s.getcount());
			out.width(20); out << left << s.thesis_titlearray[s.getcount()];
			out.width(20); out << left << s.supervisorarray[s.getcount()] << endl;
			out << endl << endl << endl << endl;
			if (s.supervisorarray[s.getcount()] == "NA") {
				cout << "This is an Undergraduate Student's Record" << endl;
			}
			else
			{
				cout << "This is a Graduate Student's Record" << endl;
			}
		}
	}
	else if (s.getmenu() == 5) {
		char ans;
		out << endl;
		out.width(20); out << left << "STUDENT ID";
		out.width(20); out << left << "FIRSTNAME";
		out.width(20); out << left << "LASTNAME";
		out.width(20); out << left << "PROGRAM";
		out.width(20); out << left << "REGISTRATION DATE";
		out.width(20); out << left << "THESIS TITTLE";
		out.width(20); out << left << "SUPERVISOR" << endl;
		for (int i = 0; i < s.thesis_titlearray.size(); i++)
		{
			s.write(out, i);
			out.width(20); out << left << s.thesis_titlearray[i];
			out.width(20); out << left << s.supervisorarray[i] << endl;
		}
		cout << endl << endl << endl;
		while (true)
		{
			cout << "Do you want the Sorted Student Record? (Y/N): ";
			cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				bubblesort(s.getstudent_idarray(), s.getfirstnamearray(), s.getlastnamearray(), s.getprogramarray(), s.getreg_datearray(), s.thesis_titlearray, s.supervisorarray);
				break;
			}
			else if (ans == 'n' || ans == 'N') {
				break;
			}
			else
			{

			}
		}
	}
	else if (s.getmenu() == 6) {} 			// empty Students
	else if (s.getmenu() == 7) {			// count Students
		out << endl;
		s.write(out, s.getcount());
	}
	return out;
}


// ***************External Functions*****************


void vectoresize(vector <string>& a, vector <string>& b, vector <string>& c, vector <string>& d, vector <date>& e, vector <string>& f, vector <string>& g) {
	a.resize(a.size() + 1);
	b.resize(b.size() + 1);
	c.resize(c.size() + 1);
	d.resize(d.size() + 1);
	e.resize(e.size() + 1);
	f.resize(f.size() + 1);
	g.resize(g.size() + 1);
}

template <typename T>
int indexsearch(T s, const vector<T> k) {
	int i = 0;
	for (i = 0; i < k.size(); ++i) {
		if (k[i] == s) {
			break;
		}
	}
	return i;
}


void bubblesort(vector <string> a, vector <string> b, vector <string> c, vector <string> d, vector <date> e, vector <string> f, vector <string> g) {
	string temp_a, temp_b, temp_c, temp_d, temp_f, temp_g;
	date temp_e;
	if (c.size() == 0) {
		cout << "Student Records Empty!!" << endl;
	}
	else if(c.size() == 1) {
		cout << endl;
		cout.width(20); cout << left << "STUDENT ID";
		cout.width(20); cout << left << "FIRSTNAME";
		cout.width(20); cout << left << "LASTNAME";
		cout.width(20); cout << left << "PROGRAM";
		cout.width(20); cout << left << "REGISTRATION DATE";
		cout.width(20); cout << left << "THESIS TITTLE";
		cout.width(20); cout << left << "SUPERVISOR" << endl;
		cout.width(20); cout << left << a[0];
		cout.width(20); cout << left << b[0];
		cout.width(20); cout << left << c[0];
		cout.width(20); cout << left << d[0];
		cout.width(20); cout << left << e[0];
		cout.width(20); cout << left << f[0];
		cout.width(20); cout << left << g[0] << endl;

	}
	else if(c.size() >= 1)
	{

		for (int i = 0; i < c.size(); i++) {

			for (int j = 0; j < c.size() - i - 1; j++) {

				if (c[j] > c[j + 1]) {
					temp_c = c[j];
					c[j] = c[j + 1];
					c[j + 1] = temp_c;

					temp_a = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp_a;

					temp_b = b[j];
					b[j] = b[j + 1];
					b[j + 1] = temp_b;

					temp_d = d[j];
					d[j] = d[j + 1];
					d[j + 1] = temp_d;

					temp_e = e[j];
					e[j] = e[j + 1];
					e[j + 1] = temp_e;

					temp_f = f[j];
					f[j] = f[j + 1];
					f[j + 1] = temp_f;

					temp_g = g[j];
					g[j] = g[j + 1];
					g[j + 1] = temp_g;
				}
			}
		}

		cout << endl;
		cout.width(20); cout << left << "STUDENT ID";
		cout.width(20); cout << left << "FIRSTNAME";
		cout.width(20); cout << left << "LASTNAME";
		cout.width(20); cout << left << "PROGRAM";
		cout.width(20); cout << left << "REGISTRATION DATE";
		cout.width(20); cout << left << "THESIS TITTLE";
		cout.width(20); cout << left << "SUPERVISOR" << endl;
		for (int k = 0; k < c.size(); k++)
		{
			cout.width(20); cout << left << a[k];
			cout.width(20); cout << left << b[k];
			cout.width(20); cout << left << c[k];
			cout.width(20); cout << left << d[k];
			cout.width(20); cout << left << e[k];
			cout.width(20); cout << left << f[k];
			cout.width(20); cout << left << g[k] << endl;
		}
	}
}
