#include<bits/stdc++.h>

using namespace std;

class CPeople {
  protected:
  string _name;
  char _gender;
  int _age;
  public:
  CPeople(string name, char gender,int age):_name(name), _gender(gender), _age(age){}
  void say () {
    cout << "People:" << endl;
    cout << "Name: " << _name <<endl;
    cout << "Sex: " << _gender <<endl;
    cout << "Age: " << _age << endl << endl;
  }   
};
class CStudent: virtual public CPeople{
  public:
  string _stuid;
  double _grade;
  CStudent(string stuid, double grade, string name, char gender, int age):_stuid(stuid), _grade(grade),CPeople(name, gender, age){}
  void say (){
    cout <<"Student:" <<endl;
    cout <<"Name: " << _name  <<endl;
    cout <<"Sex: " << _gender <<endl;
    cout << "Age: " << _age <<endl;
    cout << "No.: " << _stuid <<endl;
    cout << "Score: " << _grade <<endl;
    cout << endl;
  }
};
class CTeacher : virtual public CPeople{
  public:
  string _postition, _department;
  CTeacher(string position,string department,string name, char gender,int age):_postition(position),_department(department), CPeople(name, gender, age){}
  void say () {
    cout << "Teacher:" << endl;
    cout << "Name: " <<_name << endl;
    cout << "Sex: " << _gender << endl;
    cout << "Age: " << _age << endl;
    cout << "Position: " << _postition << endl;
    cout << "Department: " << _department << endl;
    cout << endl;
  }
};
class CGradOnWork:public CStudent, public CTeacher {
  string _researchDir,_tutor;
  public:   
  CGradOnWork(string researchDir, string tutor, string name, char gender, int age, string stuid, double grade, string position,string department):_researchDir(researchDir), _tutor(tutor), CStudent(stuid, grade, name, gender, age), CPeople(name, gender, age), CTeacher(position, department, name, gender, age){}
  void say () {
    cout << "GradOnWork:" << endl;
    cout << "Name: " <<_name << endl;
    cout << "Sex: " << _gender << endl;
    cout << "Age: " << _age << endl;
    cout << "No.: " << _stuid <<endl;
    cout << "Score: " << _grade <<endl;
    cout << "Position: " << _postition << endl;
    cout << "Department: " << _department << endl;
    cout << "Direction: " << _researchDir << endl;
    cout << "Tutor: " << _tutor << endl;
  }
};


int main () {
  string name ; char gender ; int age;
  string stuid; double grade;
  string position, department;
  string researchDir, tutor;
  cin >> name >> gender >> age >> stuid >> grade >> position >> department >> researchDir >> tutor;
  CPeople(name, gender, age).say();
  CStudent(stuid, grade, name, gender, age).say();
  CTeacher(position, department, name, gender, age).say();
  CGradOnWork(researchDir, tutor, name, gender, age, stuid, grade, position,department).say();
}
