#include <iostream>

//c library containing useful functions
#include <cstdio>
#include <stdlib.h>


//string handling
#include <string>
#include <string.h>
#include <sstream>

//for file handlings
#include <fstream>

using namespace std;

#define nl endl


//creating a class employee
class Employee
{
        public :
        string name,ssn,age,medical,casual,emergency,experience,department,sdate,edate,days;
        
        //int days;

        Employee()
        {

                casual="12",medical="12",emergency="12",sdate="",edate="",days="";

        }



        void add_user();
        void leave_form();
        void numberofLeaves();
        void list_user();
        void delete_user();

        void exit();

        void approve_leave();

}e;





//function for adding a user in the file
void add_user()
{

        

        cout<<"==================ADDING A USER=================="<<endl;
        cout<<"Enter the unique id of the employee ";
        cin>>e.ssn;
        e.ssn.resize(8);

        cout<<"Enter the name of the employee ";
        cin>>e.name;
        e.name.resize(8);

        cout<<"Enter the age of the employee ";
        cin>>e.age;
        e.name.resize(8);

        cout<<"Enter the experience of the employee ";
        cin>>e.experience;
        e.experience.resize(8);

        cout<<"Enter Your Department ";
        cin>>e.department;
        e.department.resize(8);

        fstream file1,file2,file3;
        file1.open("emp.txt",ios::binary|ios::app);
        file2.open("leaves.txt",ios::binary|ios::app);

       

        if(!file1||!file2)
        {
        system("cls");
		cout<<"\t"<<"Error Occured!"<<endl;
		return;
	    }
	
        e.casual=e.casual+"/20-0",e.medical=e.medical+"/15-0",e.emergency=e.emergency+"/10-0";
        e.casual.resize(10),e.medical.resize(10),e.emergency.resize(10),e.sdate.resize(10),e.edate.resize(10),e.days.resize(5);
       //  file1<<"\t|"<<e.ssn<<"|\t"<<e.name<<"|"<<e.age<<"|"<<"|"<<e.experience<<"|"<<"|"<<e.department<<endl;
       
       file1<<"\t"<<e.ssn<<"|"<<"\t"<<"\t"<<e.name<<"|"<<"\t"<<"\t"<<e.age<<"|\t"<<"\t"<<e.experience<<"|\t"<<"\t"<<"\t"<<e.department<<endl;
       
        file1.close();
          // file2<<e.ssn<<"|"<<e.name<<"|"<<e.casual<<"|"<<e.medical<<"|"<<endl;

       file2<<e.ssn<<"|"<<e.name<<"|"<<e.casual<<"|"<<e.medical<<"|"<<endl;
          //file2<<"\t"<<"\t"<<e.ssn<<"|"<<"\t"<<"\t"<<e.name<<"|"<<e.casual<<"|"<<e.medical<<endl;
	
          //file1<<"\t|"<<e.ssn<<"|\t"<<e.name<<"|"<<e.age<<"|"<<e.sal<<"|"<<e.exp<<"|"<<nl;
	   
	    file2.close();


	cout<<"\t"<<"User added successfully!"<<endl<<endl<<endl;



}

void delete_user(){

	 string id;
    cout << "Enter the employee ID to delete: ";
    cin >> id;
    id.resize(8);

    ifstream file1("emp.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;

    while (getline(file1, line))
    {
        if (line.find(id) != string::npos)
        {
            found = true;
            continue;
        }
        temp << line << endl;
    }

    file1.close();
    temp.close();

    if (found)
    {
        if (remove("emp.txt") == 0)
        {
            if (rename("temp.txt", "emp.txt") != 0)
                cout << "Error occurred while renaming the file!" << endl;
            else
                cout << "User deleted successfully!" << endl;
        }
        else
            cout << "Error occurred while deleting the file!" << endl;
    }
    else
    {
        cout << "Employee not found!" << endl;
        remove("temp.txt");
    }


}
void recover(char *fn1,char *fn2)
{
	remove(fn1);
	rename(fn2,fn1);
}

void apply_leave(){

       
     string id,str;
	int found=1,count=0;
	fstream file1,file2;
	file1.open("leaves.txt",ios::binary|ios::in);
	cout<<nl<<"\t\t"<<"--- A P P L Y  L E A V E ---"<<nl<<nl;
	cout<<"\t\t"<<"    "<<"Enter the Employee ID : ";
	cin>>id;
	cout<<nl;
	id.resize(8);
	if(!file1){
        system("cls");
	  cout<<"\t\t\t\t"<<"Error Occured"<<nl;
		return;
	}
	int index=0;
	while(file1){
		file1.seekg(index, ios::beg);
		getline(file1,str,'|');
		if(str==id){
			found=1;
			break;
		}
		else{
			index+=100;
			str.clear();
			count=count-1;
		}
	}
	file1.close();
	if(found==1)
	{
		
		string sdate,edate;
		int ch,com=7,beg,end,nol,ex=0,lea,tot,days=0,leave,nod;
		float sal,per;
		cout<<"\t\t"<<"    "<<"1. CASUAL LEAVE"<<nl;
		cout<<"\t\t"<<"    "<<"2. MEDICAL LEAVE"<<nl;
		
		cout<<""<<"enter ";
		cin>>ch;
		cout<<"=========================================================";
		cout<<nl;
		if(ch==1){ beg=0,end=3,tot=20,per=.08; }
		else if(ch==2){ beg=1,end=2,tot=15,per=0.05;}
		//else if(ch==3){ beg=2,end=1,tot=10,per=0.03;}
		//else if(ch==4){ beg=3,end=0,tot=40,per=0.15;}
		file1.open("leaves.txt",ios::binary|ios::in);
		file2.open("temp1.txt",ios::binary|ios::app);

        //cout<<"prevcount value"<<count;

		while(!file1){
			getline(file1,str);
			file2<<str<<endl;
           // cout<<"count"<<count;
           // count=count-1;
		}
        //while(count--){
		//	getline(file1,str);
           // cout<<"record from  lesves"<<str;
		//	file2<<str<<endl;
		//}
		for(int i=0;i<2;i++){
			getline(file1,str,'|');
			file2<<str<<"|";
		}
		for(int i=0;i<beg;i++){
			getline(file1,str,'|');
			file2<<str<<"|";
		}
		cout<<"\t\t"<<"    "<<"Enter the number of leaves : ";
		cin>>nol;
		getline(file1,str,'|');
		stringstream buf1(str);
		buf1>>lea;
		leave=lea;
        cout<<"leav value"<<lea;
		if(lea-nol<0)
		days=abs(lea-nol);
		lea=lea-nol;
		if(days!=0)
		lea=0;
		fstream buf2;
		buf2.open("mod.txt",ios::binary|ios::out);
		buf2<<lea<<"/"<<tot<<"-"<<days;
		buf2.close();
		buf2.open("mod.txt",ios::binary|ios::in);
		getline(buf2,str);
		buf2.close();
		remove("mod.txt");
		str.resize(10);
		file2<<str<<"|";
		for(int i=0;i<end;i++){
			getline(file1,str,'|');
			file2<<str<<"|";
		}
	//	getline(file1,str,'|');
		

		
		

		cout<<"\t\t"<<"    "<<"Enter the Start Date(dd/mm/yyyy) : ";
		cin>>sdate;
		cout<<"\t\t"<<"    "<<"Enter the End Date(dd/mm/yyy) : ";
		cin>>edate;
		sdate.resize(10);
		edate.resize(10);
		//file2<<sdate<<"|";
		//file2<<edate<<"|";
		for(int i=0;i<3;i++)
		getline(file1,str,'|');

		stringstream buf5(str);
		buf5>>nod;
		nod=nod+nol;

		ostringstream buf6;
		buf6<<nod;
		str=buf6.str();
		str.resize(5);
		file2<<str<<"|";

		while(file1){
			getline(file1,str);
			file2<<str;
			if(file1)
			file2<<endl;
		}
		file1.close();
		file2.close();
		char fn1[]="leaves.txt",fn2[]="temp1.txt";
		recover(fn1,fn2);
		cout<<"\t\t\t\t"<<"Leave updated!"<<nl<<nl;
	}
	else
		cout<<"\t\t\t\t"<<"User not found!"<<nl<<nl;
}







void display_leaves()
{
     string str;
	fstream file;
	file.open("leaves.txt",ios::binary|ios::in);
	if(!file){
      system("cls");
		cout<<"Error Occured"<<endl;
		return;
	}
	cout<<endl<<"Employee ID\t"<<"Name\t\t"<<"CL(12)\t\t"<<"ML(12)\t\t"<<"Start Date"<<"\t"<<"\t"<<"\t"<<"\t"<<"End Date"<<"\t"<<"\t"<<"\t"<<"\t"<<"No.ofLeaves"<<endl<<endl;
	while(file){
		getline(file,str,'|');
		cout<<str<<"\t"<<"\t";
	}
	cout<<endl<<endl;
	
	file.close();

}

void list_user()
{

      string str;
        fstream file;
        file.open("emp.txt",ios::binary|ios::in);
        if(!file){

                system("cls");
                cout<<"\t"<<"Error Ocurred"<<endl;
                return ;
        }
        cout<<"\n"<<"\tEmployee ID"<<"\t\t"<<"Name"<<"\t\t"<<"Age"<<"\t\t"<<"Experience"<<"\t"<<"\t"<<"\t"<<"Department"<<endl<<endl;
        while(file)
        {
                getline(file,str,'|');
                cout<<str<<"\t";
        }
        file.close();
        
        int t=80;
        cout<<endl;
        while(t--)
         cout<<"-";
        cout<<endl<<endl;

        file.close();



}



void exit()
{

    cout<<"Thankyou!";
}


void exit_prompt(){
        int out;
        cout<<"Enter 1 if you want to exit"<<endl;
        cin>>out;
        
        
}

void approve_leave() {
   
    {
    cout << "Below are the details of the leaves:" << endl;
    // Display leaves from the leaves.txt file
    ifstream leavesFile("leaves.txt");
    if (!leavesFile) {
        cout << "Error occurred while opening the file." << endl;
        return;
    }

    string leaveDetails;
    while (getline(leavesFile, leaveDetails)) {
        cout << leaveDetails << endl;
    }

    leavesFile.close();

    // Prompt for approval
    cout << "Enter 'yes' or 'no' to approve leaves: ";
    string approval;
    cin >> approval;

    // Write approval status to a file
    ofstream approvalFile("approval.txt", ios::app);
    if (!approvalFile) {
        cout << "Error occurred while opening the file." << endl;
        return;
    }

    approvalFile << approval << endl;
    approvalFile.close();

    cout << "Leaves approved successfully!" << endl;
}

}


int main()
{

do {
   
   int a,b;
   
    cout<<endl<<"============================================================="<<endl;
    cout<<"----------L E A V E  M A N A G E M E N T  S Y S T E M -------"<<endl;
    cout<<"============================================================="<<endl<<endl;
    cout<<"\t \t"<<"--- M A I N  M E N U ---"<<endl<<endl;


    cout<<"Choose an Option"<<endl;

    cout<<"ENTER 1 FOR EMPLOYEE PORTAL"<<endl;
    cout<<"ENTER 2 FOR MANAGER PORTAL"<<endl<<endl;
	cout<<"ENTER 0 TO EXIT "<<endl;
    cin>>a;
	cout<<endl<<endl;

	if (a==0){

		exit(0);
		break;
	}

    if(a==1)

    {

    
    cout<<"ENTER 1 FOR ADDING A USER"<<endl;
    cout<<"ENTER 2 FOR APPLYING A LEAVE"<<endl;
    cout<<"ENTER 3 FOR CHECKING LEAVE DETAILS"<<endl;
    cout<<"ENTER 4 FOR DISPLAYING THE DETAILS OF USER"<<endl;

    cout<<"Enter 5 for EXIT"<<endl;

    
    int ch;
    cin>>ch;
	

    switch(ch)

    {
		

        case 1: add_user();
                break;
        case 2: apply_leave();
                break;
        case 3: display_leaves();
                break;
        case 4: list_user();
                break;
        //case 5: delete_user();
        //        break;
        case 5: exit(0);
                break;
		

        default:cout<<"Error please try again!"<<endl;
    }


    }

    else
    {
        cout<<endl<<"============================================================="<<endl;
        cout<<"----------L E A V E  M A N A G E M E N T  S Y S T E M -------"<<endl;
        cout<<"============================================================="<<endl<<endl;
        cout<<"\t \t"<<"--- M A I N  M E N U ---"<<endl<<endl;

        cout<<"Enter 1 for approving leaves"<<endl;
        cout<<"Enter 2 for deleting a user"<<endl;

        cin>>b;
        cout<<endl;
        if(b==1)
        approve_leave();
        else
        delete_user();
    }

}while(1);
    
	
	return 0;
	
}
