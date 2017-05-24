#include <bits/stdc++.h>

using namespace std;

class Person{
protected:
    string Gender;
    int Age;
public:
    string Name;

    Person(string name, string gender, int age): Gender(gender), Name(name), Age(age)
    {
        cout<<"Person"<<Name<<"constructed"<<endl;
    }
    ~Person()
    {
        cout<<"Person"<<Name<<"destructed"<<endl;
    }

    void SetName(string name)
    {
        Name = name;
    }
};

class StudentRecord:virtual public Person{
protected:
    int Score;
public:
    string Number;
    string ClassName;
    static int TotalCount;


    StudentRecord(string name, string gender, int age, string number,
    string classname, int totalcount, int score): Person(name, gender, age),
    Number(number), ClassName(classname), Score(score)
    {
        TotalCount = totalcount;
        cout<<"Student"<<Name<<"constructed"<<endl;
    }
    ~StudentRecord()
    {
        cout<<"Student"<<Name<<"destructed"<<endl;
    }
};

class TeacherRecord:virtual public Person{
public:
    string CollegeName;
    string DepartmentName;
protected:
    int Year;

    TeacherRecord(string name, string gender, int age, string collegename,
                  string departmentname, int year)
                  : Person(name, gender,age),
                  CollegeName(collegename), DepartmentName(departmentname),
                  Year(year)
                  {
                      cout<<"teacher"<<Name<<"constructed"<<endl;
                  }
                  ~TeacherRecord()
                  {
                      cout<<"teacher"<<Name<<"destructed"<<endl;
                  }
};

class TeachingAssistant:public StudentRecord, public TeacherRecord{
public:
    string LectureName;

    string GetLectureName()const {return LectureName;}

    void Show()
    {
        cout<<"Name:"<<Name<<" Gender:"<<Gender<<" Age:"<<Age
        <<" Number:"<<Number<<" ClassName:"<<ClassName<<" TotalCount:"<<TotalCount<<" Score:"
        <<Score<<" CollegeName:"<<CollegeName<<" DepartmentName:"
        <<DepartmentName<<" Year:"<<Year<<" LectureName:"<<LectureName;
    }

    TeachingAssistant(string name, string gender, int age,
                      string number,string classname,int totalcount,int score,
                      string collegename,string departmentname,int year,string lecturename)
                      :Person(name, gender, age),
                       StudentRecord(name,gender,age,number,classname,totalcount,score),
                       TeacherRecord(name,gender,age,collegename,departmentname,year),LectureName(lecturename)
                       {
                           cout<<"teachingassistant"<<Name<<"constructed"<<endl;
                       }
                       ~TeachingAssistant()
                       {
                           cout<<"teachingassistant"<<Name<<"destructed"<<endl;
                       }
};

int StudentRecord::TotalCount = 0;


int main()
{
    TeachingAssistant Print((string)"郑七","男",22,"2010123","软20101",1,89,"信息","软件",1,"数据结构");
    Print.Show();
    Print.SetName("郑八");
    Print.Show();
    return 0;
}
