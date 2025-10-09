#include <iostream>
#include <string>
using namespace std;
class Company {
protected:
string company_name;
string location;
public:
Company(string cname, string loc)
{
company_name=cname;
location=loc;
}
void displayCompany() {
cout << "Company Name: " << company_name << endl;
cout << "Location: " << location << endl;
}
};
class Team : protected Company {
protected:
 string team_name;
 string project;
public:
Team(string cname, string loc, string tname, string proj): Company(cname,
loc)
 {
 team_name=tname;
project=proj;
}
void displayTeam() {
 cout << "Team Name: " << team_name << endl;
  cout << "Project: " << project << endl;
 }
};
class Developer : public Team {
private:
 string developer_name;
 string programming_language;
public:
Developer(string cname, string loc, string tname, string proj, string dname,
string lang)
 : Team(cname, loc, tname, proj)
 {
 developer_name=dname;
 programming_language=lang;
}
void displayDeveloper() {
 displayCompany(); // Call base class display function
 displayTeam(); // Call intermediate class display function
 cout << "Developer Name: " << developer_name << endl;
 cout << "Programming Language: " << programming_language << endl;
 }
};
int main() {

 Developer obj("Tech Solutions", "New York", "AI Team", "AI Chatbot",
"Alice", "C++");
 obj.displayDeveloper();
//  Team ob1("Tech Solutions", "New York", "AI Team", "AI Chatbot");
//  ob1.displayCompany();
 return 0;
}
