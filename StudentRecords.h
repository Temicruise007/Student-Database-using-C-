#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Generates the registration date of the student

class date {
private:
    int day, month, year;

public:
    date(int d = 0, int m = 0, int y = 0);
    friend istream& operator>>(istream& in, date& dt);
    friend ostream& operator<<(ostream& out, const date& dt);
};

// Base Class Student holds all the vectors for the data structure

class student {
private:
    string student_id, firstname, lastname, program;
    date reg_date;
    vector<string> student_idarray, firstnamearray, lastnamearray, programarray;
    vector<date> reg_datearray;
    int count;
    int menu;

public:
    student(string f = "none", string l = "none", vector<string> stu_idarray = {},
        vector<string> f_a = {}, vector<string> l_a = {}, vector<string> p_a = {},
        int c = 0, vector<date> reg_dtarray = {}, int d = 0, int m = 0, int y = 0, int mu = 0);
    string generate_id(void);        // Generates and returns user id
    void deleterecord(); // deletes a particular record
    int getmenu(void)const;    // returns the menu number
    int getcount(void)const;    // returns the count value
    void upsize(void);                 // increments all the vectors by 1
    void downsize(void);               // decrements all the vectors by 1
    void clrsize(void);                // clear all the vectors
    vector<string> getstudent_idarray()const;
    vector<string> getfirstnamearray()const;
    vector<string> getlastnamearray()const;
    vector<string> getprogramarray()const;
    vector<date> getreg_datearray()const;
    void addstudent_id(string stu_id); // adds student id to the student id vector
    void addfirstname(string f);       // adds firstname to the firstname vector
    void addlastname(string l);        // adds lastname to the lastname vector
    void addprogram(string p);         // adds program to the program array
    void addreg_date(date d);  // adds registration date to the registration date array
    void setmenu(int mu); // Tells the program which menu to go with
    void incrementcount(void); // increments the count by 1
    void resetcount(void);     // sets the count to 0
    void read(istream& in); // reads in student
    void write(ostream& out, int i)const;
};

// Graduate Student Class

class gradStudent :public student {
private:
    string thesis_title, supervisor;
    vector <string> thesis_titlearray, supervisorarray;
public:
    gradStudent(string f = "none", string l = "none", vector<string> stu_idarray = {}, vector<string> f_a = {}, vector<string> l_a = {}, vector<string> p_a = {}, int c = 0, vector<date> reg_dtarray = {}, int d = 0, int m = 0, int y = 0, int mu = '0', string tt = "NA", string s = "NA", vector<string> tt_a = {}, vector<string> s_a = {});
    void deleterecord(void);      // Deletes the thesis title and supervisor record of the student record
    void addthesis_title(string tt);       // adds thesis title to the thesis title vector
    void addsupervisor(string s);        // add supervisor to the supervisor vector
    void downsize(void);     // decrements all the vectors by 1
    void upsize(void);   // increases the array size of thesis title and supervisor
    void clrsize(void);                // clear all the vectors
    void getvectors(istream& in);
    friend istream& operator>>(istream& in, gradStudent& s);
    friend ostream& operator<<(ostream& out, const gradStudent& s);
};


// Declaring the External Functions
void vectoresize(vector <string>& a, vector <string>& b, vector <string>& c, vector <string>& d, vector <date>& e, vector <string>& f, vector <string>& g); // Increments the temp vectors by 1
template <typename T>
int indexsearch(T s, const vector<T> k); // Uses linear search algorithm
void bubblesort(vector <string> a, vector <string> b, vector <string> c, vector <string> d, vector <date> e, vector <string> f, vector <string> g);
#endif // !STUDENTRECORDS_HL
