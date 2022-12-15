#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;
struct entry
{
	string fname;
	string lname;
	int age;
	int bikeno;
	long long int cnic;
};
struct wapis
{
	string name;
	int bikenow;
};
bool check(string,int);
void menu();
void opt(int);
void opt(int);
void bike(entry);//to open entry file of bikes 
void returnbikes(string name);//to open returning file of bike
void detail(string);//to fetch details
const int size=3;
string username[size]={"ali","iko","ham"};
int password[size]={12,14,15};
string usrname;
int pass;
bool a;
int main()
{
	do{
	cout<<"\t\t\t\t ASALAM O ALIKUM "<<endl;	
	cout<<"\t\t\t      WELCOME TO RENT SERVICES "<<endl;
	cout<<"\n\t\t\t      ENTER USERNAME: "<<endl;
	getline(cin,usrname);
	cout<<"ENTER PASSWORD"<<endl;
	cin>>pass;
	a=check(usrname,pass);
	if(a==true)
	{
		cout<<"LOGIN SUCCESSFUL."<<endl;
		menu();	
	}
	else if(a==false)
	{
		system("CLS");
		cout<<"LOGIN FAILED"<<endl;
	}
}while(a==false);
	}
	bool check(string usrname,int pass)
	{
		bool x=true;
		for(int i=0;i<size;i++)
		{
			if(username[i]==usrname&&password[i]==pass)
			{
				return x=true;
			}
			else
			{
				 x=false;
			}
			
		}
		return x;
	}
void menu()
{	
	int option;
	do{
	cout<<"\t\t\t      WELCOME MR."<<usrname<<endl;
	cout<<"\t\t\t      1.RENT PR DI!"<<endl;
	cout<<"\t\t\t      2.WAPIS LI!"<<endl;
	cout<<"\t\t\t      3.DETAILS!"<<endl;
	cout<<"\t\t\t      4.LOGOUT!"<<endl;
    cin>>option;
    system("CLS");
    opt(option);
      }
    while(option<4 && option>0);
}
void opt(int option)
{
	switch(option)
	{
		case 1 :
			{
				entry a;
			   system("CLS");
			   cout<<"ENTER FIRST NAME: "<<endl;
			   cin>>a.fname;
			   cout<<"ENTER LAST NAME: "<<endl;
			   cin>>a.lname;
			   cout<<"ENTER AGE: "<<endl;
			   cin>>a.age;
			   cout<<"ENTER CNIC: "<<endl;
			   cin>>a.cnic;
			   cout<<"ENTER BIKE NO: "<<endl;
			   cin>>a.bikeno; 
			   cout<<endl;
			   cout<<"FIRST NAME: "<<a.fname<<endl;
			   cout<<"LAST NAME: "<<a.lname<<endl;
			   cout<<"AGE: "<<a.age<<endl;
			   cout<<"CNIC: "<<a.cnic<<endl;
  			   cout<<"BIKE NO: "<<a.bikeno<<endl;
               // FOR WRITING IN FILE.
               	bike(a);
			     break;
	         }
			case 2:
				{
					wapis b;
               system("CLS");
			   cout<<"ENTER NAME: ";
               cin.ignore();
               getline(cin,b.name);
               // FOR WRITING IN FILE.
               returnbikes(b.name);
			  break;
	         }
				
			case 3:
					{
						  string det;
	  	       string name;
			   cout<<"DETAILS OF PERSON: ";
			   cin>>det;
			   detail(det);
			  break;
	         
					}
			case 4 :
			{
				cout<<"LOGGING OUT"<<endl;
				break;
			}	
			default :
			{
				cout<<"INVALID ENTRY"<<endl;
			}
	}
}
void bike(entry a)
{
	time_t now;
               struct tm nowlocal;
               now=time(NULL);
               nowlocal=*localtime(&now);
               string n = a.fname+".txt";
	ofstream myfile3(n);
	if(myfile3.is_open())
	{
			   myfile3<<"\n";
			   myfile3<<a.fname<<"\t";
			   myfile3<<a.lname<<"\t";
			   myfile3<<a.age<<"\t";
			   myfile3<<a.cnic<<"\t";
  			   myfile3<<a.bikeno<<"\t";
  			   myfile3<<nowlocal.tm_mday;
			   myfile3<<"-"<<nowlocal.tm_mon+1;
			   myfile3<<"-"<<nowlocal.tm_year+1900;
  			   myfile3<<" "<<nowlocal.tm_hour<<"H";
			   myfile3<<"-"<<nowlocal.tm_min<<"M";
			   myfile3<<"\t RENTED.";
		}
		else
		cout<<"FILE NOT OPENED";
			   myfile3.close();
}

void returnbikes(string name)
{
	time_t now;
               struct tm nowlocal;
               now=time(NULL);
               nowlocal=*localtime(&now);
               string n = name+".txt";
	ofstream myfile3(n, ios :: app);
	if(myfile3.is_open())
	{
			   myfile3<<"\n";
			   myfile3<<"RETURNED AT(TIME): ";
  			   myfile3<<nowlocal.tm_mday;
			   myfile3<<"-"<<nowlocal.tm_mon+1;
			   myfile3<<"-"<<nowlocal.tm_year+1900;
  			   myfile3<<" "<<nowlocal.tm_hour<<"H";
			   myfile3<<"-"<<nowlocal.tm_min<<"M";
			   myfile3.close();
		}
		else
		cout<<"FILE NOT OPENED";
}	


void detail(string name)
{
    string n = name+".txt";
	ifstream myfile(n);
	if(myfile.is_open())
	{
	          string fname,lname;
	          int age;
	          long long int cnic;
	          int bikeno;
	          int day,month,year;
			  myfile>>fname;
			  myfile>>lname;
			  myfile>>age;
			  myfile>>cnic;
			  myfile>>bikeno;	
			  myfile>>day;
			  myfile>>month;
			  myfile>>year;
			  
			  cout<<"FIRST NAME: "<<fname<<endl;
			  cout<<"LAST NAME: "<<lname<<endl;
			  cout<<"AGE: "<<age<<endl;
			  cout<<"CNIC: "<<cnic<<endl;
			  cout<<"BIKE NO: "<<bikeno<<endl;
			  cout<<"DATE: "<<day<<"-"<<month<<"-"<<year<<endl;
			  myfile.close();
	}
		else
		cout<<"FILE NOT OPENED";
}
	
