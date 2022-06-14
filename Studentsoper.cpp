#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
class Students{
public:
	char f_name[20];
	char l_name[20];
	char id[14];
	int age;

	void set(const char *f_name,const char *l_name,const char *id,int age){
	strcpy(this->f_name,f_name);
	strcpy(this->l_name,l_name);
	strcpy(this->id,id);
        this->age=age;
}
	const char* getT()const{
		return f_name;
	}
	const char* getid()const{
		return id;
	}
	Students operator = (Books b){
	id[14]=b.title[50];
	//cout<<"\nStudent"<<"\t\t"<<"Book"<<'\n';
	//cout<<id<<'\t'<<b.title<<"\n\n";
	}
	
	friend istream& operator >> (istream&, Students&);
	friend ostream& operator << (ostream&,const Students&);
};
istream& operator >> (istream &in, Students &s){
	in.read(s.f_name,18);
        in.read(s.id,10);
	in.read(s.l_name,18);
	in>>s.age;
	return in;
}
ostream& operator << (ostream &out,const Students &s){
	out << setw(12) << left << s.f_name ;
	out << setw(12) << left << s.l_name ;
	out << setw(12) <<right << s.id  ;
	out << setw(9) <<right <<s.age<<'\n';
	return out;
}


