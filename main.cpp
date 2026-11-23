#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
struct Student
{
   string name;
   string surname;
   string facultyNumber;
   
};
vector<Student> students;


void showMenu()
{
    cout << "================================" << endl;
    cout << "     STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "================================" << endl;

    cout << "1. Add Student" << endl;
    cout << "2. Show All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Delete Student" << endl;
    cout << "5. Exit" << endl;
}

void addStudent()
{
    Student student;
    cout<<"Enter first name:";
    cin>>student.name;
    cout<<"Enter surname:";
    cin>>student.surname;
    cout<<"Enter faculty number:";
    cin>>student.facultyNumber;
    students.push_back(student);
    ofstream file("students.txt",ios::app);
    
    file<<student.name<<endl;
    file<<student.surname<<endl;
    file<<student.facultyNumber<<endl;
    cout << "Name: " << student.name << endl;
    cout << "Surname: "<< student.surname << endl;
    cout << "Faculty Number: "<< student.facultyNumber << endl;
}
void loadStudents()
{
    ifstream file("students.txt");
    Student student;
    while (file >> student.name
        >> student.surname
        >> student.facultyNumber)
    {
        students.push_back(student);
    }

}
void saveStudents()
{
    ofstream file("students.txt");
    for(int i=0;i<students.size();i++)
    {
      file<<students[i].name<<endl;
      file<<students[i].surname<<endl;
      file<<students[i].facultyNumber<<endl;
    }
}
void showAllStudents()
{
    if(students.empty())
    {
       cout<<"Empty list!";
       return;
    }
    for(int i=0;i<students.size();i++)
    {
       cout<< "Name: "<<students[i].name<<endl;
       cout<< "Surname: "<<students[i].surname<<endl;
       cout<<"Faculty Number: "<<students[i].facultyNumber<<endl;
    }
}
void searchStudent()
{
    string searchNumber;
    cout<<"Enter faculty number: ";
    cin>>searchNumber;
    bool found=false;
    for(int i=0;i<students.size();i++)
    {
        if(searchNumber==students[i].facultyNumber)
        {
            found=true;
            cout<< "Name: "<<students[i].name<<endl;
            cout<< "Surname: "<<students[i].surname<<endl;
            cout<<"Faculty Number: "<<students[i].facultyNumber<<endl;
            return;
        }
    }
    if(found==false)
    {
        cout<<"Student not found!" << endl;
    }
}
void saveStudents();
void deleteStudent()
{
    string deleteNumber;
    cout<<"Enter faculty number to delete: ";
    cin>>deleteNumber;
    bool foundd=false;
    for(int i=0;i<students.size();i++)
    {
        
        if(deleteNumber==students[i].facultyNumber)
        {
            foundd=true;
            students.erase(students.begin() + i);
            saveStudents();
            cout<<"Student deleted successfully!"<<endl;
            return;
        }
    }
    if(foundd==false)
    {
        cout << "Student not found!" << endl;
    }
}
int main()
{
    int choice;
    loadStudents();
    while(true)
    {
    showMenu();
    cout << "Choose an option: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
        addStudent(); break;
        case 2:
        showAllStudents();break;
        case 3:
        searchStudent();break;
        case 4:
        deleteStudent();break;
        case 5:
        cout<<"Goodbye!";exit(0);
        default: 
        cout<<"Invalid option!"; break;
    }
    }
    cout << endl;
    return 0;
}