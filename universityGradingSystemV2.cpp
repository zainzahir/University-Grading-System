#include<iostream>
#include<iomanip>
using namespace std;

char gradeCalculator(int marks);
int main(){
    int choice; //for choice

    int mark; // adding student marks
    string name; // adding student name
    int marks[5]={-1,-1,-1,-1,-1}; //marks of all  students
    int students=0; //check total students
    string student[5] = {"NV","NV","NV","NV","NV"};
    bool flag=false;
    //for password credentials 
    string username = "Administrators", Password = "PF2024"; //predefined
    string askUsername, askPassword; //ask form user
    cout<<"Enter Username : ";
    cin>>askUsername;
    cout<<"Enter Password : ";
    cin>>askPassword;
    if(askUsername == username && askPassword == Password){
    //repeat this menu again and again
    while(!flag){
    cout<<endl;
    cout<<"*****************************************************"<<endl;
    cout<<"              University Grading System              "<<endl;
    cout<<"*****************************************************"<<endl;
    cout<<"    Please Enter the Administration Credential!      "<<endl;
    cout<<"*****************************************************"<<endl;
    cout<<"Username : Administrators"<<endl;
    cout<<"Password : PF2024"<<endl;
    cout<<"*****************************************************"<<endl<<endl;

    cout<<"Choose the option from the menu:"<<endl;
    cout<<"Enter 1 to add a student"<<endl;
    cout<<"Enter 2 to search a student "<<endl;
    cout<<"Enter 3 to delete a student"<<endl;
    cout<<"Enter 4 to update the data of a student"<<endl;
    cout<<"Enter 5 to display number of students in the system"<<endl;
    cout<<"Enter 6 to display list of all students without grade"<<endl;
    cout<<"Enter 7 to display list of all with grade"<<endl;
    cout<<"Enter 0 to close a program"<<endl;
    //input from user to choose option
    cout<<"Enter input:";
    cin>>choice;
    switch(choice){
        case 1:{
            cout<<"\t\tAdd a student"<<endl;
            cout<<"Enter Student Name : ";
            cin>>name;
            cout<<"Enter Student Marks : ";
            cin>>mark;
            bool added = false; //check if added
            for(int i=0; i<5;i++){
                if (student[i] == "NV"){
                    student[i] = name;
                    marks[i] = mark;
                    added = true;
                    cout<<"Student added successfully";
                    break;
                }
            }
            if(!added){
                cout<<"Memory is full, no student can be added.";
            }
            break;
        }
        case 2:{
            cout<<"\t\tSearch Student"<<endl;
            cout<<"Enter the student name:";
            cin>>name;
            cout<<endl;
            bool finded = false;
            for(int i=0; i<5; i++){
                if(student[i] == name){
                    cout<<"Student Name : "<<student[i]<<endl;
                    cout<<"Marks        : "<<marks[i]<<endl;
                    cout<<"Grade        : "<<gradeCalculator(marks[i]);
                    finded = true;
                    break;
                }
            }
            if(!finded){
                cout<<"Not found any student";
            }
            break;
        }
        case 3:{
            cout<<"\t\tDelete Student Record"<<endl;
            cout<<"Enter Student Name : ";
            cin>>name;
            cout<<endl;
            bool deleted = false;
            //searching student if exist and delete student
            for(int i=0; i<5; i++){
                if(student[i] == name){
                    student[i] = "NV";
                    marks[i] = -1;
                    cout<<"Student Record Deleted successfully";
                    deleted = true;
                    break;
                }
            }
            if(!deleted){
                cout<<"Student Record Not Found!";
            }
            break;
        }
        case 4:{
            cout<<"\t\tUpdate Student Record"<<endl;
            cout<<"Enter Student Name      : ";
            cin>>name;
            cout<<endl;
            bool updated = false;
            for(int i=0; i<5; i++){
                if(student[i] == name){
                    cout<<"Student Name        : "<<student[i]<<endl;
                    cout<<"Student Marks       : "<<marks[i]<<endl;
                    cout<<"Enter Student Marks :";
                    cin>>marks[i];
                    updated = true;
                    cout<<"Student Record Updated SUCCESSFULLY!";
                    break;
                }
            }
            if(!updated){
                cout<<"No student is found!";
            }
            break;
        }
        case 5:{
            students = 0;
            for(int i=0; i<5; i++){
                if(student[i] != "NV"){
                    students += 1; //count students
                }
            }
            cout<<"Total Number of Students in System: "<<students;
            break;
        }
        case 6:{
            cout<<"\t\tDisplay Student Record without Grades"<<endl;
            cout<<"*********************************************************************"<<endl;
            cout<<fixed<<left<<setw(20)<<"Student Name"<<setw(5)<<"Marks"<<endl;
            cout<<"*********************************************************************"<<endl;
             for(int i=0; i<5; i++){
                 if(student[i] != "NV"){
                    cout<<left<<fixed<<setw(20);
                    cout<<student[i]<<marks[i]<<endl;
                }
            }
            cout<<"*********************************************************************"<<endl; 
            break;
        }
        case 7:{
             cout<<"\t\tDisplay Student Record with Grades"<<endl;
            cout<<"*********************************************************************"<<endl;
            cout<<left<<fixed<<setw(20)<<"Student Name"<<"Marks"<<setw(20)<<right<<" Grades"<<endl;
            cout<<"*********************************************************************"<<endl;
            for(int i=0; i<5; i++){
                 if(student[i] != "NV"){
                    cout<<left<<fixed<<setw(20);
                    cout<<student[i]<<setw(20)<<marks[i]<<setw(10)<<gradeCalculator(marks[i])<<endl;
                 }
            }
            cout<<"*********************************************************************"<<endl;
            break;
        }
        case 0:{
            cout<<"Thank You"<<endl;
            cout<<"Program closed successfully!"<<endl;
            flag = true;
            break;
        }
        default :
        cout<<"invalid input";
    }
    }
    } //if part ends here
    else 
        cout<<"Invalid Password";
    return 0;
}

char gradeCalculator(int marks){
    char grade;
    if(marks>=85){
            grade = 'A'; 
        }
        else if(marks>=70){
            grade = 'B';
        }
        else if(marks>=55){
            grade = 'C';
        }
        else if(marks>=40){
            grade = 'D';
        }
        else
            grade = 'F';
    return grade;
}