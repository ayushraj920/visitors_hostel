//C++ OOP PROJECT
//IIITA VISITOR HOSTEL
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//START OF CLASS


class visitor_hostel
{

int room_no;
string name;
string address;
string phone;
map<int,vector<string>> db;
public:

void hostel_menu();		//to dispay the main menu of visitor hostel
void add();			     //to book a room in visitor hostel
void display(); 		//to display the visitor record
void rooms();			 //to display alloted rooms in visitor hostel
void edit();			//to edit the visitor record
int check(int);	 //to check room status
void modify(int);	//to modify the record
void delete_rec(int);	//to delete the record
void bill(int);      //for the bill of a record
};
    //END OF CLASS DEFINITION


void visitor_hostel::hostel_menu()
{

int choice;
while(choice!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t Visitor_Hostel MANAGEMENT ";
cout<<"\n\t\t\t\t      * Hostel MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Visitor Records";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;


if(choice==1)
add();
else if(choice==2)
display();
else if(choice==3)
rooms();
else if(choice==4)
edit();
else
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();

}

}

}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM IN VISITOR HOSTEL


void visitor_hostel::add()
{

  system("cls");
int r,flag;

cout<<"\n Enter visitor Details";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms - 50";
cout<<"\n Single bed Rooms from 1 - 30";
cout<<"\n Double bed Rooms from 31 - 45";
cout<<"\n Meeting  Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

flag=check(r);

if(flag==0)
cout<<"\n Sorry..!!!Room is already booked or room does not exists";
else
{

room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;

db[room_no].push_back({name,address,phone});
cout<<"\n Room is booked...!!!";

}

cout<<"\n Press any key to continue.....!!";

getch();

}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PARTICULAR VISITOR`S RECORD


void visitor_hostel::display()
{

  system("cls");

int r,flag;

cout<<"\n Enter room no. for a particular visitor`s details :- "<<endl;
cin>>r;
cout<<"\n\n Room no: "<<r;
if(db.find(r)!=db.end())
{
cout<<"\n Name: "<<db[r][0];
cout<<"\n Address: "<<db[r][1];
cout<<"\n Phone no: "<<db[r][2];
}
else
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void visitor_hostel::rooms()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";


for(auto it:db)
{
  cout<<it.first<<"->";
  for(auto det:it.second)
  {
    cout<<det<<"    ";
  }
  cout<<endl;
}
cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void visitor_hostel::edit()
{

system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify visitor Record";
cout<<"\n 2.Delete visitor Record";
cout<<"\n 3. Bill Of visitor";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no:";
cin>>r;

if(choice==1)	modify(r);

else if(choice==2)	delete_rec(r);

else if(choice==3) bill(r);

else cout<<"\n Wrong Choice.....!!";

cout<<"\n Press any key to continue....!!!";

getch();
}
//checking for the availability of the room

int visitor_hostel::check(int r)
{

int flag=0;

if(db.find(r)==db.end() || r<=50)
return 0;
else
return 1;

}


//FUNCTION TO MODIFY visitorS RECORD


void visitor_hostel::modify(int r)
{


if(db.find(r)!=db.end())
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
db.erase(r);
db[r].push_back({name,address,phone});
}
else
cout<<"\n Sorry Room no. not found or vacant...!!";

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void visitor_hostel::delete_rec(int r)
{

int flag=0;
if(db.find(r)!=db.end())
{
cout<<"\n Name: "<<db[r][0];
cout<<"\n Address: "<<db[r][1];
cout<<"\n Phone No: "<<db[r][2];
mp.erase(r);
cout<<"\n data deleted succesfully!!";
}
else
cout<<"\n Sorry Room no. not found or vacant...!!";




}


//END OF DELETE FUNCTION


//FUNCTION FOR visitor`S BILL

void visitor_hostel::bill(int r)
{  

    if(db.find(r)==db.end)
  { cout<<"room no. not found";}
  else
  {
      if(r>=1 &&  r<=30)
      cout<<"your bill = 2000";

      else if (r>=35  &&  r<=45)
      cout<<"your bill = 5000" ;

      else
      cout<<"your bill = 7000";
      break;
  }
  getch();

}


//START OF THE MAIN()

int main()
{

visitor_hostel h;

  system("cls");

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* IIITA VISITOR HOSTEL *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

getch();

h.hostel_menu();
return 0;
}

