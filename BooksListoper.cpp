#include "Booksoper.cpp"
#include<fstream>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
class BooksList{
int count;
public:
Books *book;
	BooksList(){
	this->count = 0;
	book=new Books[count];	
	} 
	bool addBook(const char *catagory,const char *title,const char *author,const char *publisher,const char *edition,const char* call_no,int rack_no,int acc_id){
	book=new Books[count];
	book->set(catagory,title,author,publisher,edition,call_no,rack_no,acc_id);
		return true;
	return false;
      }
	void set(const char *catagory,const char *title,const char *author,const char *publisher,const char *edition,const char* call_no,int rack_no,int acc_id){
		book=new Books[count];
	book->set(catagory,title,author,publisher,edition,call_no,rack_no,acc_id);
	}
	void add(const char *catagory,const char *title,const char *author,const char *publisher,const char *edition,const char* call_no,int rack_no,int acc_id){
	fstream in;
	in.open("Library.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		addBook(catagory,title,author,publisher,edition,call_no,rack_no,acc_id);
		in.seekp(0,ios::end);
		in.write((char*)(this->book),sizeof(Books));	
	}
	in.close();
	} 
	void searchnthrecord(int n){
		fstream in;
	in.open("Library.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		n--;
		in.seekg(sizeof(Books)*n);
		in.read((char*)(this->book),sizeof(Books));	
	}
	in.close();
	}
	void modifyrecord(int n,const char *catagory,const char *title,const char *author,const char *publisher,const char *edition,const char* call_no,int rack_no,int acc_id){
	fstream in;
	in.open("Library.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		n--;
		in.seekp(sizeof(Books)*n);
		book->set(catagory,title,author,publisher,edition,call_no,rack_no,acc_id);
		in.write((char*)(this->book),sizeof(Books));
	}
	in.close();
	}
	void deleteRecord(int n){
	fstream in;
	in.open("Library.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		in.seekg(0,ios::end);
		count=in.tellg()/sizeof(Books);
		in.seekg(0);
		book=new Books[count];
		in.read((char*)(this->book),sizeof(Books)*count);
		if(n>count){
			if(count==0)  {cout<<"Sorry no record in the file\n";}
			else	     { cout<<"Sorry,file has less than n records\n";}
		}
		n--;
		in.close();
		remove("Library.bin");
		ofstream out("Library.bin",ios::binary);
		out.write((char*)book,sizeof(Books)*n);
		out.write((char*)&book[n+1],sizeof(Books)*(count-n-1));
		out.close();
		delete[]book;
		in.open("Library.bin",ios::binary|ios::in|ios::out);
	}
	}

	~BooksList(){
	delete[]book;
	}
	
	friend istream&operator>>(istream&, BooksList&);
	friend ostream&operator<<(ostream&,const BooksList&);
};
istream&operator>>(istream &in, BooksList &list){
	in.seekg(0,ios::end);
	list.count=in.tellg()/sizeof(Books);
	in.seekg(0);
	list.book = new Books[list.count];
	in.read((char*)list.book,sizeof(Books)*list.count);
	return in;
	
}
ostream&operator<<(ostream &out,const BooksList &List){
	out << " Sr     Catagory     Title       Author       Publisher   Edition     CallNo     RackNo    Acc_ID\n";
	out << "---------------------------------------------------------------------------------------------------\n";
	for (int i=0;i<List.count;i++)
		out << setw(2) <<i+1<<'\t'<<List.book[i];
	out<<'\n';
	return out;
}










































































