#include<fstream>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include "BooksListoper.cpp"
#include "StudentsListoper.cpp"
#include "Assign.cpp"
using namespace std;
void assign(int n,int m);
int main(){          
	#define QUIT 12              
	char c[20],t[50],a[30],p[30],e[15],n[10],no[50]; //for books
	int  choice,co,r,d;
	BooksList b;
	char f[20],l[50],id[30]; //for students
	int age,number;
	StudentsList s;
	Assign A;
	int st_number,book_number;
	int press;
		cout << "\n\tProgram is handling both Books and Students records\n\n";
	do{     
		cout << "\t\t1.	Show all Books\n";
		cout << "\t\t2.	Add new Book\n";
		cout << "\t\t3.	Show nth Book\n";
		cout << "\t\t4.	Modify nth Book\n";
		cout << "\t\t5.	Delete nth Book\n";
		cout << "\t\t6.	Show all Students\n";
		cout << "\t\t7.	Add new Students\n";
		cout << "\t\t8.	Show nth Students\n";
		cout << "\t\t9.	Modify nth Students\n";
		cout << "\t\t10.     Delete nth Students\n";
		cout << "\t\t11.	To assign nth book to kth Student\n";
		cout << "\t\t12.     Quit\n\n";
		cout<<"Enter your choice:  ";	
		cin >> choice;

		switch (choice){
			case 1:{
				ifstream file("Library.bin",ios::binary);
				file>>b;
                                cout<<b;
				file.close();
			 break;
			 }
			case 2:
				cout<<"Enter catagory of book: ";
				cin>>c;
				cout<<"Enter title of book: ";
				cin>>t;
				cout<<"Enter author of book: ";
				cin>>a;
				cout<<"Enter publisher of book: ";
				cin>>p;
				cout<<"Enter edition of book: ";
				cin>>e;
				cout<<"Enter call_no of book: ";
				cin>>n;
				cout<<"Enter rack_no of book: ";
				cin>>r;
				cout<<"Enter acc_id of book: ";
				cin>>d; 
				b.add(c,t,a,p,e,n,r,d);
		        break;
			case 3:
				cout<<"Enter record number: ";
				cin>>co;
				b.searchnthrecord(co);
				cout<<*b.book; //Indirection operator
			break;
			case 4:
				cout<<"Enter record number: ";
				cin>>co;
				cout<<"Enter catagory of book: ";
				cin>>c;
				cout<<"Enter title of book: ";
				cin>>t;
				cout<<"Enter author of book: ";
				cin>>a;
				cout<<"Enter publisher of book: ";
				cin>>p;
				cout<<"Enter edition of book: ";
				cin>>e;
				cout<<"Enter call_no of book: ";
				cin>>n;
				cout<<"Enter rack_no of book: ";
				cin>>r;
				cout<<"Enter acc_id of book: ";
				cin>>d;
				b.modifyrecord(co,c,t,a,p,e,n,r,d); 
			
			break;
			case 5:
				cout<<"Enter Book no: ";
				cin>>co;
				if(co==0){	cout<<"Please enter number greater than '0'\n\n"; break;}
				else b.deleteRecord(co);
			break;
			case 6:{
				ifstream file("Students.bin",ios::binary);
				file>>s;
                                cout<<s;
				file.close();
			break;
				}				
			case 7:
				cout<<"Enter first name of student: ";
				cin>>f;
				cout<<"Enter last name of student: ";
				cin>>l;
				cout<<"Enter ID of student: ";
				cin>>id;
				cout<<"Enter age of student: ";
				cin>>age; 
				s.add(f,l,id,age);
		        break;
			case 8:
				cout<<"Enter record number: ";
				cin>>number;
				s.searchnthrecord(number);
				cout<<*s.student;
			break;
			case 9: 
				cout<<"Enter record number: ";
				cin>>number;
				cout<<"Enter first name of student: ";
				cin>>f;
				cout<<"Enter last name of student: ";
				cin>>l;
				cout<<"Enter ID of student: ";
				cin>>id;
				cout<<"Enter age of student: ";
				cin>>age; 
				s.modifyrecord(number,f,l,id,age);
			break;
			case 10:
				p:
				cout<<"Enter Record no:";
				cin>>number;
				if(number==0){	cout<<"Please enter number greater than '0'\n\n"; goto p;}
				else	 s.deleteRecord(number);
			break;
			case 11:
				cout<<"Enter Student number in list: ";
				cin>>st_number;
				cout<<"Enter Book number in list: ";
				cin>>book_number;
				cout<<'\n';
				A.Write(st_number,book_number);
				A.file();
			break;
	}
		}while(choice!=QUIT);
		cout<<"\n\t\tThanks for using the program *_*\n";
		return 0;
	}


