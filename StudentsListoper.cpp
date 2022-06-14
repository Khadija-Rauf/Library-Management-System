#include "Studentsoper.cpp"
//#include "Booksoper.cpp"
#include<fstream>
#include<iomanip>
class StudentsList{
int count;
public:
Students *student;//strong aggregation
	StudentsList(){
	this->count = 0;
	student=new Students[count];	
	}
	bool addStudent(const char *f_name,const char *l_name,const char *id,int age){
	student=new Students[count];
	student->set(f_name,l_name, id, age);
		return true;
	return false;
	}
	void set(const char *f_name,const char *l_name,const char *id,int age){
	student=new Students[count];
	student->set(f_name,l_name, id, age);
	}
	void add(const char *f_name,const char *l_name,const char *id,int age){
	fstream in;
	in.open("Students.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		addStudent(f_name,l_name, id, age);
		in.seekp(0,ios::end);
		in.write((char*)(this->student),sizeof(Students));	
	}
	in.close();
	}
	void searchnthrecord(int n){
	fstream in;
	in.open("Students.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		n--;
		in.seekg(sizeof(Students)*n);
		in.read((char*)(this->student),sizeof(Students));	
	}
	in.close();
	}
	void modifyrecord(int n,const char *f_name,const char *l_name,const char *id,int age){
	fstream in;
	in.open("Students.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		n--;
		in.seekp(sizeof(Students)*n);
		student->set(f_name,l_name, id, age);
		in.write((char*)(this->student),sizeof(Students));
	}
	in.close();
	}
	void deleteRecord(int n){
	fstream in;
	in.open("Students.bin",ios::in|ios::out|ios::binary);
	if(!in)
	cout<<"\nFile not found";
	else{
		in.seekg(0,ios::end);
		count=in.tellg()/sizeof(Students);
		in.seekg(0);
		student=new Students[count];
		in.read((char*)(this->student),sizeof(Students)*count);
		if(n>count){
			if(count==0)  {cout<<"Sorry no record in the file\n";}
			else	     { cout<<"Sorry,file has less than n records\n";}
		}
		n--;
		in.close();
		remove("Students.bin");
		ofstream out("Students.bin",ios::binary);
		out.write((char*)student,sizeof(Students)*n);
		out.write((char*)&student[n+1],sizeof(Students)*(count-n-1));
		out.close();
		delete[]student;
		in.open("Students.bin",ios::binary|ios::in|ios::out);
	}
	}
	
	~StudentsList(){
	delete[]student;
	}
	friend istream&operator>>(istream&, StudentsList&);
	friend ostream&operator<<(ostream&,const StudentsList&);
};
istream&operator>>(istream &in, StudentsList &list){
	in.seekg(0,ios::end);
	list.count=in.tellg()/sizeof(Students);
	in.seekg(0);
	list.student = new Students[list.count];
	in.read((char*)list.student,sizeof(Students)*list.count);
	return in;
	
}
ostream&operator<<(ostream &out,const StudentsList &List){
	out << "Sr   First Name     Last Name        ID             Age\n"  ;
    out << "-------------------------------------------------------\n";
	for (int i=0;i<List.count;i++)
		out  << setw(2)<<i+1<<'\t'<<List.student[i];
	return out;
}


