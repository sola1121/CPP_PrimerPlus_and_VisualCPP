#include "studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

//public methods
double Student::Average() const{
	if (scores.size()>0)
		return scores.sum()/scores.size();
	else
		return 0;
}

const string & Student::Name() const{
	return name;
}

double & Student::operator[](int i){
	return scores[i];    //use valarray<double>::operator[]()
}

double Student::operator[](int i) const{
	return scores[i];
}

//private methods
ostream & Student::arr_out(ostream & os) const{
	int i;
	int lim=scores.size();    //valarray类的成员方法 size 
	if (lim>0){
		for (i=0; i<lim; i++){
			os<<scores[i]<<"  ";   //这是输出吧 
			if (i%5==4)
				os<<endl;    //这应该是每四个换一行 
		}
		if (i%5!=0)
			os<<endl;
	}
	else
		os<<" empty array ";
	return os;
}

//friends
//use string version of operator>>()
//友元函数形参为所在的类,可以直接调用私有成员
istream & operator>>(istream & is, Student & stu){
	is>>stu.name;
	return is;
}
//use string friend getline(ostream &, const string &)
istream & getline(istream & is, Student & stu){
	getline(is, stu.name);    
	return is;
}

//use string version of operator<<()
ostream & operator<<(ostream & os, const Student & stu){
	os<<"Scores for "<<stu.name<<":\n";
	stu.arr_out(os);   //use privete methods
	return os;
}
