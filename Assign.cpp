#include<fstream>
#include<string.h>
#include<string>
#include<iostream>
#include<stdio.h>
#include "BooksListoper.cpp"
#include "StudentsListoper.cpp"
using namespace std;
class Assign{
Books B;
fstream book;
Students S;
fstream st;
fstream ass;
char id[30];
char T[50];
int count;
int count1;
public:
Assign(){
	ass.open("Assign.bin",ios::in|ios::out|ios::binary);
	book.open("Library.bin",ios::in|ios::out|ios::binary);
	st.open("Students.bin",ios::in|ios::out|ios::binary);
	st.seekg(0,ios::end);
	count=st.tellg()/sizeof(Students);
	cout<<count;
	book.seekg(0,ios::end);
	count1=book.tellg()/sizeof(Books);
	cout<<count1;
	st.seekg(0);
	book.seekg(0);
	while(st.read((char*)&S,sizeof(S))){
	setI(S.getid());
	setTi("Nill");  
	ass.write((char*)id,sizeof(char)*50);
	ass.write((char*)T,sizeof(char)*50); 
}
st.seekg(0);
}
void setI(const char *id){
strcpy(this->id,id);
}
void setTi(const char *T){
strcpy(this->T,T);
}
~Assign(){
ass.close();
}
const char* file(){
	ass.seekg(0);
	while(true){
	ass.read((char*)id,sizeof(char)*count);
	ass.read((char*)T,sizeof(char)*count1);
        if (ass.eof()) break;
        cout<<id<<'\t'<<T<<'\n';
	}
}
void Write(int m,int n){
	ass.seekg(0);
	m=m*2;
	n--;
	m--;
	//ass.read((char*)id,sizeof(char)*50);
	book.seekg(sizeof(Books)*n);
	book.read((char*)&B,sizeof(Books));
	ass.seekp(sizeof(T)*m);
	setTi(B.getT());
	ass.write((char*)&T,sizeof(T)); 
	}
	friend ostream& operator << (ostream&,const Assign&);
}; 
ostream& operator << (ostream &out,const Assign &a){
	out << setw(12) << left << a.id ;
	out << setw(12) << left << a.T << '\n';
	return out;
}
int main(){
Assign A;
A.file();
A.Write(1,3);
return 0;
}
