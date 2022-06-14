#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
class Books{

public:
	char catagory[20];
	char title[50];
	char author[30];
	char publisher[30];
	char edition[15];
	char call_no[10];
	int rack_no;
	int acc_id;
	/*Books(){ }
	Books(const char *catagory,const char *title,const char *author,const char *publisher,const char *edition,const char* call_no,int rack_no,int acc_id){
	set(catagory,title,author,publisher,edition,call_no,rack_no,acc_id);
	}*/
	void set(const char *catagory,const char *title,const char *author,const char *publisher,const char *edition,const char* call_no,int rack_no,int acc_id){
	strcpy(this->catagory,catagory);
	strcpy(this->title,title);
	strcpy(this->author,author);
	strcpy(this->publisher,publisher);
	strcpy(this->edition,edition);
	strcpy(this->call_no,call_no);
	this->rack_no=rack_no;
	this->acc_id=acc_id;
}
const char* getT()const{
		return title;
}
	friend istream& operator >> (istream&, Books&);
	friend ostream& operator << (ostream&,const Books&);
};
istream& operator >> (istream &in, Books &b){
	in.read(b.catagory,18);
        in.read(b.title,48);
	in.read(b.author,28);
	in.read(b.publisher,28);
	in.read(b.edition,14);
	in.read(b.call_no,9);
        in>>b.rack_no>>b.acc_id;
	return in;
}
ostream& operator << (ostream &out,const Books &b){
	out << setw(12) << left << b.catagory ;
	out << setw(12) << left << b.title ;
	out << setw(15) << left << b.author;
	out << setw(12) << left << b.publisher;
	out <<  setw(8) << left << b.edition ;
	out << setw(10) << left << b.call_no;
	out <<  setw(9) << right << b.rack_no ;
	out <<  setw(10)<< right << b.acc_id << '\n';
	return out;
}
