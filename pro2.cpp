#include<iostream>
#include<conio.h>
#include<string.h>
#include<ctime>
#include<fstream>
using namespace std;
struct date1
{
    int dd,mm,yy;
};
struct stu_struct
{
    int roll,hindi,english,maths,science,total,mfees,clss;
    char name[25],father_name[25],mother_name[25],address[25],phone[10];
    float avg;
    date1 dob,doj,dof;
};
struct tea_struct
{
    int code,salary,Clss1,Clss2;
    char Name[25],Father_name[25],Phone[10],Address[25],sub1[10],sub2[10];
    date1 dob,doj;
};
string one[]={""," One  "," Two  "," Three  "," Four  "," Five  "," Six  "," Seven  "," Eight  "," Nine  "," Ten  "," Eleven  "," Twelve  "," Thirteen  "," Fourteen  "," Fifteen  "," Sixteen  "," Seventeen  "," Eighteen  "," Nineteen  "};
string ten[]={"",""," Twenty  "," Thirty  "," Forty  "," Fifty  "," Sixty  "," Seventy  "," Eighty  "," Ninety  "};
//**************************************************************** */
string num_to_words(int,string);
string convert(long);
void menu_ad(int);
void date_due();
void admin_menu();
void student_menu();
void teacher_menu();
void main_menu();
void welcome_window();
void newts(int);
void deletet(int);
void find(int);
void update(int);
void date_bday();
//******************************** */
int unique(int c,int a,int b=0)
{
    if(c==0)
    {
        
    ifstream fout("student.dat",ios::binary|ios::in);
    stu_struct x;
    while(fout.read((char*)&x,sizeof(x)))
    {
        if(a==x.roll&&b==x.clss)
        return 0;
    }
     fout.close();
    return 1;
    }
    else if(c==1)
    {
      ifstream gin("teacher.dat",ios::binary|ios::in);
        tea_struct y;
       while(gin.read((char*)&y,sizeof(y)))
       {
        if(a==y.code)
        return 0;
       }
       gin.close();
       return 1;
    }
}
//****************************************** */
int update_menu(int);
void display_doj_fail(int);
void display_sub_pass(int);
void display_class(int);
void display_all(int);
void display_menu(int);

//*************************************************** */
void welcome_window()
{
    char id[25],pass[25];
    int d=0;
    cout<<" "<<" "<<" "<<" "<<"Kendriya Vidhayala School"<<" "<<" "<<" "<<" "<<endl;
    cout<<" "<<" "<<"Air Force Hindon Station ,Mohan Nagar,Ghaziabad"<<" "<<" "<<endl;
    while(d<3)
    {
        cout<<"Enter id:"<<endl;
        gets(id);
        cout<<"Enter password:";
        gets(pass);
        if(((strcmp(id,"1001")==0)&&(strcmp(pass,"1111")==0))||((strcmp(id,"1002")==0)&&(strcmp(pass,"2222")==0))||((strcmp(id,"1003")==0)&&(strcmp(pass,"3333")==0)))
        {
            cout<<"Login completed"<<endl;
            date_bday();
        }
        else
        cout<<"Wrong id and password"<<endl<<"Please enter correct id and password"<<endl;
        
        d++;
    }
}
void main_menu()
{
fflush(stdout);
    system("CLS");
    int e;
    cout<<"Press 1 for Admin"<<endl;
    cout<<"Press 2 for Student"<<endl;
    cout<<"Press 3 for Teacher"<<endl;
    cin>>e;
    if(e==1)
    date_due();
    else if(e==2)
    student_menu();
    else if(e==3)
    teacher_menu();
    else
    exit(0);
}
string num_to_words(int n,string s)
{
    string str="";
    if(n>19)
    str+=ten[n/10]+one[n%10];
    else
    str+=one[n];
    
    if(n)
    str+=s;
    return str;
}
string convert(long n)
{
    string result="";
    result+=num_to_words((n/10000000),"Crore");
    result+=num_to_words((n/100000)%100,"Lakh");
    result+=num_to_words((n/1000)%100,"Thousand");
    result+=num_to_words((n/100)%10,"Hundred");
   if(n>100 && n%100)
   result+="and";
   
   result+=num_to_words(n%100,"");
   return result;
}
void date_due()
{  
    time_t now=time(0);
    tm*ltm=localtime(&now);
    int dd=ltm->tm_mday;
    int mm=ltm->tm_mon;
    int yy=1900+ltm->tm_year;
    int a,s;
    long total;
    ifstream fout("student.dat",ios::binary|ios::in);
    stu_struct x;
    s=0;
    cout<<"roll no"<<" "<<"name"<<" "<<"monthly fees"<<endl;
    while(fout.read((char*)&x,sizeof(x)))
    {
        if((x.dof.dd!=dd)&&(x.dof.mm!=mm)&&(x.dof.yy!=yy))
        { 
            s=s+x.mfees;
        cout<<x.roll<<" "<<x.name<<" "<<x.clss<<" "<<x.mfees<<" "<<endl;
        }
    }
    total=s;
    cout<<"total"<<"="<<s<<endl;
    cout<<"total in words:"<<convert(total)<<endl;
    fout.close();
    cout<<"enter 1 for admin"<<endl;
    getch();    
    admin_menu();
}
void date_bday()
{ fflush(stdout);
    time_t now=time(0);
    tm* ltm=localtime(&now);
    int dd=ltm->tm_mday;
    int mm=ltm->tm_mon;
    int yy=1900+ltm->tm_year;
    int a;
    ifstream fout("teacher.dat",ios::binary|ios::in);
    tea_struct y;
    while(fout.read((char*)&y,sizeof(y)))
    {
        if((y.dob.dd==dd)&&(y.dob.mm==mm+1))
        cout<<"HAPPY  BIRTHDAY :)"<<" "<<y.Name<<" "<<"TO YOUUU :)"<<endl;
    }
    fout.close();
    cout<<"Press any key to conti..................."<<endl;
    getch();
    main_menu();  
}
void student_menu()
{ fflush(stdout);
    char a[25];
    int b,t,c,d,e,f;
    cout<<"Enter roll no:"<<endl;
    cin>>b;
    cout<<"Enter name:"<<endl;
    cin.ignore();
    gets(a);
    cout<<"Enter class:"<<endl;
    cin>>c;
    fstream fin ("student.dat",ios::binary|ios::in|ios::out);
    stu_struct x;
    while(fin.read((char*)&x,sizeof(x)))
    {
        if((strcmp(x.name,a)==0)&&(x.roll==b)&&(x.clss==c))
        {
            cout<<"Login completed"<<endl;
            f=fin.tellg();
          cout<<"Press 1 for display"<<endl;
          cout<<"Press 2 for change"<<endl;
          cin>>d;
          if(d==1)
          {
             cout<<x.roll<<" "<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<" "<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<" "<<x.phone<<" "<<x.name<<" "<<x.clss<<" "<<x.father_name<<" "<<x.mother_name<<" "<<x.address<<" "<<x.hindi<<" "<<x.english<<" "<<x.science<<" "<<x.maths<<" "<<endl;
               fin.close();
               cout<<"Press 1 for back"<<endl;
               getch();
               main_menu();
          }
          else if(d==2)
          {
            cout<<"Press 3 for phone"<<endl;
            cout<<"Press 4 for address"<<endl;
            cin>>e;
            if(e==3)
            {
                cin.ignore();
               gets(x.phone);
               fin.seekp(f-sizeof(x),ios::beg);
               fin.write((char*)&x,sizeof(x));
               fin.close();
               cout<<"Press 1 for back"<<endl;
               getch();
               main_menu();
            }
            else if(e==4)
            {
             cin.ignore();
               gets(x.address);
               fin.seekp(f-sizeof(x),ios::beg);
               fin.write((char*)&x,sizeof(x));
               fin.close();
               cout<<"Press 1 for back"<<endl;
               getch();
               main_menu();
            }
          }
        }
        else
        {
         cout<<"no record found"<<endl;
         fin.close();
         cout<<"Press digit for back"<<endl;
         getch();
         main_menu();
        }
    }
}
void teacher_menu()
{
    fflush(stdout);
    char a[25];
    int b,d,e,n,f;
    cout<<"Enter code:"<<endl;
    cin>>b;
    cout<<"Enter name:"<<endl;
    cin.ignore();
    gets(a);
    fstream fin ("teacher.dat",ios::binary|ios::in|ios::out);
    tea_struct y;
    while(fin.read((char*)&y,sizeof(y)))
    {
        if((strcmp(y.Name,a)==0)&&(y.code==b))
        {
            cout<<"Login completed"<<endl;
            f=fin.tellg();
          cout<<"Press 1 for display"<<endl;
          cout<<"Press 2 for change"<<endl;
          cout<<"Press 3 for student"<<endl;
          cin>>d;
          if(d==1)
           {
            cout<<y.code<<" "<<y.dob.dd<<"/"<<y.dob.mm<<"/"<<y.dob.yy<<" "<<y.doj.dd<<"/"<<y.doj.mm<<"/"<<y.doj.yy<<" "<<y.Phone<<" "<<y.Name<<" "<<y.Clss1<<" "<<y.Clss2<<" "<<y.Father_name<<" "<<y.Address<<" "<<y.salary<<" "<<y.sub1<<" "<<y.sub2<<endl;
               fin.close();
               cout<<"Press 1 for back"<<endl;
               getch();
               main_menu();
          }
          else if(d==2)
          {
            cout<<"Press 4 for phone"<<endl;
            cout<<"Press 5 for address"<<endl;
            cin>>e;
            if(e==4)
            {
                cin.ignore();
               gets(y.Phone);
               fin.seekp(f-sizeof(y),ios::beg);
               fin.write((char*)&y,sizeof(y));
               fin.close();
               cout<<"Press 1 for back"<<endl;
               getch();
               main_menu();
            }
            else if(e==5)
            {
             cin.ignore();
               gets(y.Address);
               fin.seekp(f-sizeof(y),ios::beg);
               fin.write((char*)&y,sizeof(y));
               fin.close();
               cout<<"Press 1 for back"<<endl;
               getch();
               main_menu();
            }
        }
        else if(d==3)
        { fin.close();
            char a[25];
         int b,t,n,c,d,e,f;
         cout<<"Enter roll no:"<<endl;
         cin>>b;
         cout<<"Enter name:"<<endl;
         cin.ignore();
         gets(a);
         cout<<"Enter class:"<<endl;
         cin>>c;
         fstream fin ("student.dat",ios::binary|ios::in|ios::out);
         stu_struct x;
         while(fin.read((char*)&x,sizeof(x)))
         {
                 if((strcmp(x.name,a)==0)&&(x.roll==b)&&(x.clss==c))
                   {  
                        cout<<"Login completed"<<endl;
                         f=fin.tellg();
                         cout<<"Press 1 for display"<<endl;
                          cout<<"Press 2 for change"<<endl;
                          cin>>d;
                         if(d==1)
                         {
                             cout<<x.roll<<" "<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<" "<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<" "<<x.phone<<" "<<x.name<<" "<<x.clss<<" "<<x.father_name<<" "<<x.mother_name<<" "<<x.address<<" "<<x.hindi<<" "<<x.english<<" "<<x.science<<" "<<x.maths<<" "<<endl;
                              fin.close();
                               cout<<"Press 1 for back"<<endl;
                              getch();
                              main_menu();
                         }
              
                         else if(d==2)
                         { int v;
                               cout<<"Press 1 for hindi"<<endl;
                              cout<<"Press 2 for english"<<endl;
                             cout<<"Press 3 for maths"<<endl;
                             cout<<"Press 4 for science"<<endl;
                              cin>>v;
                             if(v==1)
                             cin>>x.hindi;
                             else if(v==2)
                             cin>>x.english;
                             else if(v==3)
                              cin>>x.science;
                             else if(v==4)
                             cin>>x.maths;
                             fin.seekp(f-sizeof(x),ios::beg);
                              fin.write((char*)&x,sizeof(x));
                             fin.close();
                              cout<<"Press 1 for back"<<endl;
                             getch();
                             main_menu();
                         }
        
                }
                else
                {
                cout<<"no record found"<<endl;
                fin.close();
                cout<<"enter digit for back"<<endl;
                getch();
                main_menu();
                }
            }
        }
    }
    else{
       cout<<"no record found"<<endl; 
           fin.close();
           cout<<"enter digit for back"<<endl;
                getch();
                main_menu(); }     
   }
}
void admin_menu()
{ 
    system("CLS");
    int a;
    cout<<"Press 1 for Student"<<endl;
    cout<<"Press 2 for Teacher"<<endl;
    cout<<"Press any key for back"<<endl;
    cin>>a;
    if(a==1)
    menu_ad(0);
    else if (a==2)
    menu_ad(1);
    else
    main_menu();   
}

void menu_ad(int a)
{ system("CLS");
    int n;
    if(a==0)
    {
        int c;
    cout<<"Press 1 for New"<<endl;
    cout<<"Press 2 for Update"<<endl;
    cout<<"Press 3 for Delete"<<endl;
    cout<<"Press 4 for Display"<<endl;
    cout<<"Press 5 for Find"<<endl;
    cout<<"Press any key for back"<<endl;
    cin>>c;
    if(c==1)
    newts(0);
    else if(c==2)
    update(0);
    else if(c==3)
     deletet(0);
     else if(c==4)
     display_menu(0);
     else if(c==5)
      find(0);
      else
      admin_menu();
    }
    else if (a==1)
    {
   int c;
    cout<<"Press 1 for New"<<endl;
    cout<<"Press 2 for Update"<<endl;
    cout<<"Press 3 for Delete"<<endl;
    cout<<"Press 4 for Display"<<endl;
    cout<<"Press 5 for Find"<<endl;
    cout<<"Press any key for back"<<endl;
    cin>>c;
    if(c==1)
    newts(1);
    else if(c==2)
    update(1);
    else if(c==3)
    deletet(1);
    else if(c==4)
    display_menu(1);
    else if(c==5)
    find(1);
    else 
    admin_menu();
   }

}


void newts(int a)
{   fflush(stdin);
    int b;
    if(a==0)
    {
        fstream fin("student.dat",ios::app|ios::binary|ios::in);
        stu_struct x;
        int a,v1,v2;
        if(!fin)
        {
            cout<<"error";
            exit(0);
        }
        
        while(1)
        {
        cout<<"Enter roll number:"<<endl;
        cin>>v1;
        cout<<"Enter class:"<<endl;
        cin>>v2;
        if (unique(0,v1,v2)==0)
        {
            cout<<"This roll number is already exist"<<"Please enter unique roll number"<<endl;
        }
        else
        break;
        } 
        x.roll=v1;
        x.clss=v2;
        cout<<"Enter name:"<<endl;
        cin.ignore();
        gets(x.name);
        cout<<"Enter father name:"<<endl;
        gets(x.father_name);
        cout<<"Enter mother name:"<<endl;
        gets(x.mother_name);
        cout<<"Enter address:"<<endl;
        gets(x.address);
        cout<<"Enter phone number:"<<endl;
        gets(x.phone);
        cout<<"Enter dob:"<<endl;
        cin>>x.dob.dd>>x.dob.mm>>x.dob.yy;
        cout<<"Enter doj"<<endl;
        cin>>x.doj.dd>>x.doj.mm>>x.doj.yy;
        cout<<"Enter hindi english maths science marks"<<endl;
        cin>>x.hindi>>x.english>>x.maths>>x.science;
        x.total= x.english + x.hindi + x.maths + x.science;
        x.avg = x.total/4;
        fin.seekp(0,ios::end);
        fin.write((char*)&x,sizeof(x));
        fin.close();

    }
    else if(a==1)
    {
    fstream gout("teacher.dat",ios::app|ios::binary|ios::in);
    tea_struct y;
    int t,b;
    if(!gout)
    {
        cout<<"error";
        exit(0);
    }
    while(1)
    {
    cout<<"Enter code:"<<endl;
    cin>>t;
    if (unique(1,t)==0)
    {
        cout<<"This code is already exist"<<"Please enter unique code"<<endl;
    }
    else
    break;
    }
    y.code=t;
    cout<<"Enter name:"<<endl;
    cin.ignore();
    gets(y.Name);
    cout<<"Enter salary:"<<endl;
    cin>>y.salary;
    cout<<"Enter subject:"<<endl;
    cin.ignore();
    gets(y.sub1);
    cout<<"Enter another subject:"<<endl;
    cin.ignore();
    gets(y.sub2);
    cout<<"Enter class:"<<endl;
    cin>>y.Clss1;
    cout<<"Enter another class:"<<endl;
    cin>>y.Clss2;
    cout<<"Enter father name:"<<endl;
    cin.ignore();
    gets(y.Father_name);
    cout<<"Enter phone number:"<<endl;
    cin.ignore();
    gets(y.Phone);
    cout<<"Enter dob:"<<endl;
    cin>>y.dob.dd>>y.dob.mm>>y.dob.yy;
    cout<<"Enter doj"<<endl;
    cin>>y.doj.dd>>y.doj.mm>>y.doj.yy;
    cout<<"Enter address:"<<endl;
    cin.ignore();
    gets(y.Address);
    gout.seekp(0,ios::end);
    gout.write((char*)&y,sizeof(y));
    gout.close();
   }
   cout<<"Enter 1 for back"<<endl;
   getch();
   admin_menu();
}


void find(int c)
{  int d;
     if(c==0)
    { int a,b,t;
        cout<<"Enter roll no"<<endl;
        cin>>a;
        cout<<"Enter class"<<endl;
        cin>>b;
    ifstream fin("student.dat",ios::binary|ios::in);
    stu_struct x;
    t=0;
    while(fin.read((char*)&x,sizeof(x)))
    {
        if((x.roll==a)&&(x.clss==b))
        { 
            cout<<"Found"<<endl;
         cout<<x.roll<<" "<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<" "<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<" "<<x.phone<<" "<<x.name<<" "<<x.clss<<" "<<x.father_name<<" "<<x.mother_name<<" "<<x.address<<" "<<x.hindi<<" "<<x.english<<" "<<x.science<<" "<<x.maths<<" "<<endl;
        t=1;
        break;
        }
    }
    fin.close();
    if(t==0)
    cout<<"not found"<<endl;
    
   }
   else if(c==1)
   { int t,a;
    cout<<"Enter code"<<endl;
    cin>>a;
    ifstream gin("teacher.dat",ios::binary|ios::in);
    tea_struct y;
    t=0;
    while(gin.read((char*)&y,sizeof(y)))
    {
        if(y.code==a)
        {
         cout<<y.code<<" "<<y.dob.dd<<"/"<<y.dob.mm<<"/"<<y.dob.yy<<" "<<y.doj.dd<<"/"<<y.doj.mm<<"/"<<y.doj.yy<<" "<<y.Phone<<" "<<y.Name<<" "<<y.Clss1<<" "<<y.Clss2<<" "<<y.Father_name<<" "<<y.Address<<" "<<y.salary<<" "<<y.sub1<<" "<<y.sub2<<endl;
         t=1;
        }
    }
    gin.close();
   if(t==0)
    cout<<"not found"<<endl;
  }
     cout<<"Enter 1 for back for student"<<endl;
     cout<<"Enter 2 for back for teacher"<<endl;
    cin>>d;
    if(d==1)
    menu_ad(0);
    else if(d==2)
    menu_ad(1);
    else
    exit(0);
}

int update_menu(int b)
{ system("CLS");
   if(b==0)
   {
    int a;
    cout<<"Enter 1 for English"<<endl;
    cout<<"Enter 2 for Hindi"<<endl;
    cout<<"Enter 3 for Maths"<<endl;
    cout<<"Enter 4 for Science"<<endl;
    cout<<"Enter 5 for Father name"<<endl;
    cout<<"Enter 6 for Mother name"<<endl;
    cout<<"Enter 7 for DOB"<<endl;
    cout<<"Enter 8 for DOJ"<<endl;
    cout<<"Enter 9 for Phone"<<endl;
    cout<<"Enter 10 for Address"<<endl;
    cout<<"Enter 11 for Class"<<endl;
    cout<<"Enter 12 for Monthly fees"<<endl;
    cout<<"Enter 13 for DOF"<<endl;
   cin>>a;
    return a;
   }
   else if (b==1)
   {
    int a;
    cout<<"Enter 1 for subject 1"<<endl;
    cout<<"Enter 2 for subject 2"<<endl;
    cout<<"Enter 3 for Father name"<<endl;
    cout<<"Enter 4 for salary"<<endl;
    cout<<"Enter 5 for DOB"<<endl;
    cout<<"Enter 6 for DOJ"<<endl;
    cout<<"Enter 7 for Phone"<<endl;
    cout<<"Enter 8 for Address"<<endl;
    cout<<"Enter 9 for Class 1"<<endl;
    cout<<"Enter 10 for Class 2"<<endl;
   cin>>a;
    return a;
   }
}  
void update(int n)
{ int d;
    if(n==0)
    {
        fstream fin("student.dat",ios::binary|ios::in|ios::out);
    stu_struct x;
    int e,a,b,f,c;
    cout<<"enter roll number:"<<endl;
    cin>>a;
    cout<<"enter class:"<<endl;
    cin>>b;
    
    while(fin.read((char*)&x,sizeof(x)))
    {
        if (x.roll==a&&x.clss==b)
        {
            f=update_menu(0);
            e= fin.tellg();
            if(f==1)
            cin>>x.english;
            else if(f==2)
            cin>>x.hindi;
            else if(f==11)
            cin>>x.clss;
            else if(f==9){
            cin.ignore();
            gets(x.phone);}
            else if(f==7)
            cin>>x.dob.dd>>x.dob.mm>>x.dob.yy;
            else if(f==8)
            cin>>x.doj.dd>>x.doj.mm>>x.doj.yy;
            else if(f==4)
            cin>>x.science;
            else if (f==3)
            cin>>x.maths;
            else if (f==10){
            cin.ignore();
            gets(x.address);}
            else if(f==5){
            cin.ignore();
            gets(x.father_name);}
            else if(f==12)
            cin>>x.mfees;
            else if(f==13)
            cin>>x.dof.dd>>x.dof.mm>>x.dof.yy;
            else if(f==6){
                cin.ignore();
            gets(x.mother_name);}
            fin.seekp(e-sizeof(x),ios::beg);
            fin.write((char*)&x,sizeof(x));
        }
    }
    fin.close();
    }
    else if(n==1)
    {
    fstream gin("teacher.dat",ios::binary|ios::in|ios::out);
    tea_struct y;
    int e,a,f;
    cout<<"enter code:"<<endl;
    cin>>a;
    while(gin.read((char*)&y,sizeof(y)))
    {
        if (y.code==a)
        {
            f=update_menu(1);
            e= gin.tellg();
            if(f==9)
            cin>>y.Clss1;
            else if(f==10)
            cin>>y.Clss2;
            else if(f==7)
            {
            cin.ignore();
            gets(y.Phone);}
            else if(f==5)
            cin>>y.dob.dd>>y.dob.mm>>y.dob.yy;
            else if(f==6)
            cin>>y.doj.dd>>y.doj.mm>>y.doj.yy;
            else if(f==4)
            cin>>y.salary;
            else if (f==1){
                cout<<"enter subject"<<endl;
                cin.ignore();
                gets(y.sub1);
            }
            else if (f==2){
                cout<<"enter subject"<<endl;
                cin.ignore();
                gets(y.sub2);
            }
            else if (f==8){
            cin.ignore();
            gets(y.Address);}
            else if(f==3){
            cin.ignore();
            gets(y.Father_name);}
            gin.seekp(e-sizeof(y),ios::beg);
            gin.write((char*)&y,sizeof(y));
        }
    }
    gin.close();
   }
    cout<<"Enter any key for back"<<endl;
     getch();
     admin_menu();
     
}

void deletet(int c)
{ int n;
    if(c==0)
    {
        ifstream fin("student.dat",ios::binary|ios::in);
      ofstream fout("dd.dat",ios::binary|ios::out);
    stu_struct x;
    int a,b,t,c;
    cout<<"Enter roll no"<<endl;
    cin>>a;
    cout<<"Enter class"<<endl;
    cin>>b;
    t=0;
    while(fin.read((char*)&x,sizeof(x)))
    {
        if((x.roll!=a)&&(x.clss!=b))
        {
            fout.write((char*)&x,sizeof(x));
        }
        else
        {
            t=1;
        }
    }
    fin.close();
    fout.close();
    if(t==1)
    cout<<"record deleted"<<endl;
    else
    cout<<"record not found"<<endl;
    remove("student.dat");
    rename("dd.dat","student.dat");
    }
    else if(c==1)
    {
    ifstream gin("teacher.dat",ios::binary|ios::in);
    ofstream gout("ddt.dat",ios::binary|ios::out);
    tea_struct y;
    int t,a;
    cout<<"Enter code"<<endl;
    cin>>a;
    t=0;
    
    while(gin.read((char*)&y,sizeof(y)))
    {
        if(y.code!=a)
        {
            gout.write((char*)&y,sizeof(y));
        }
        else
        {
            t=1;
        }
    } 
     gout.close();
     gin.close();
    if(t==1)
    cout<<"record deleted"<<endl;
    else
    cout<<"record not found"<<endl;
    remove("teacher.dat");
    rename("ddt.dat","teacher.dat");
    }
    cout<<"Enter 1 for back for student"<<endl;
    cout<<"Enter 2 for back for teacher"<<endl;
    cin>>n;
    if(n==1)
    display_menu(0);
    else if(n==2)
    display_menu(1);
    else
    exit(0);
     
}

void display_menu(int n)
{ fflush(stdout);
    system("CLS");
    if(n==0)
    {
        int a,b;
    cout<<"Press 1 for all"<<endl;
    cout<<"Press 2 for class"<<endl;
    cout<<"Press 3 for pass students"<<endl;
    cout<<"Press 4 for fail students"<<endl;
    cout<<"Press 5 for back"<<endl;
    cin>>a;
    if (a==1)
    display_all(0);
    else if(a==2)
    display_class(0);
    else if (a==3)
    display_sub_pass(0);
    else if (a==4)
    display_doj_fail(0);
    else
    menu_ad(0);
 }
    else if(n==1)
    {
    int a,b;
    char s[10];
    cout<<"Press 1 for all"<<endl;
    cout<<"Press 2 for class"<<endl;
    cout<<"Press 3 for doj"<<endl;
    cout<<"Press 4 for subject"<<endl;
    cout<<"Press 5 for back"<<endl;
    cin>>a;
    if (a==1)
    display_all(1);
    else if (a==2)
    display_class(1);
    else if (a==3)
    display_doj_fail(1);
    else if (a==4)
    display_sub_pass(1);
    else
    menu_ad(1);
    }

}
void display_all(int n)
{ fflush(stdout);
     system("CLS");
     if(n==0)
     {
        ifstream fin("student.dat",ios::binary|ios::in);
      stu_struct x;
      int a;
      cout<<"================================================================================================================================================="<<endl;
      cout<<"roll no"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class"<<"\t"<<"father name"<<"\t"<<"mother name"<<"\t"<<"address"<<"\t"<<"hindi"<<"\t"<<"english"<<"\t"<<"science"<<"\t"<<"maths"<<"\t"<<"total"<<"\t"<<"average"<<endl;
      cout<<"================================================================================================================================================="<<endl;
      while(fin.read((char*)&x,sizeof(x)))
      {
       cout<<x.roll<<"\t"<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<"\t"<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<"\t"<<x.phone<<"\t"<<x.name<<"\t"<<x.clss<<"\t"<<x.father_name<<"\t"<<x.mother_name<<"\t"<<x.address<<"\t"<<x.hindi<<"\t"<<x.english<<"\t"<<x.science<<"\t"<<x.maths<<"\t"<<x.total<<"\t"<<x.avg<<endl;
      }
      fin.close();
      cout<<"Enter 1 for back........."<<endl;
      getch();
      display_menu(0);
     }
     else if(n==1)
     {
     ifstream gin("teacher.dat",ios::binary|ios::in);
     tea_struct y;
     if(!gin)
     {
        cout<<"error";
        exit(0);
     }
     int a;
     cout<<"================================================================================================================================================="<<endl;
     cout<<"code"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class1"<<"\t"<<"class2"<<"\t"<<"father name"<<"\t"<<"address"<<"\t"<<"salary"<<"\t"<<"subject1"<<"\t"<<"subject2"<<endl;
     cout<<"================================================================================================================================================="<<endl;
     while(gin.read((char*)&y,sizeof(y)))
     {
      cout<<y.code<<" "<<y.dob.dd<<"/"<<y.dob.mm<<"/"<<y.dob.yy<<" "<<y.doj.dd<<"/"<<y.doj.mm<<"/"<<y.doj.yy<<" "<<y.Phone<<" "<<y.Name<<" "<<y.Clss1<<" "<<y.Clss2<<" "<<y.Father_name<<" "<<y.Address<<" "<<y.salary<<" "<<y.sub1<<" "<<y.sub2<<endl;
     }
     gin.close();
     
    cout<<"Enter 1 for back"<<endl;
    getch();
    display_menu(1);
    }
}
void display_doj_fail(int n)
{   fflush(stdout);
    system("CLS");
    if(n==0)
    {
        ifstream fin("student.dat",ios::binary|ios::in);
    stu_struct x;  
    int a; 
    cout<<"================================================================================================================================================="<<endl;
    cout<<"roll no"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class"<<"\t"<<"father name"<<"\t"<<"mother name"<<"\t"<<"address"<<"\t"<<"hindi"<<"\t"<<"english"<<"\t"<<"science"<<"\t"<<"maths"<<"\t"<<"total"<<"\t"<<"average"<<endl;
    cout<<"================================================================================================================================================="<<endl;
     while(fin.read((char*)&x,sizeof(x)))
    {
        if(x.avg<50)
        {
         cout<<x.roll<<" "<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<" "<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<" "<<x.phone<<" "<<x.name<<" "<<x.clss<<" "<<x.father_name<<" "<<x.mother_name<<" "<<x.address<<" "<<x.hindi<<" "<<x.english<<" "<<x.science<<" "<<x.maths<<" "<<x.total<<" "<<x.avg<<endl;

        }
    }
    fin.close();
    cout<<"Enter 1 for back"<<endl;
    getch();
    display_menu(0);
    }
    else if(n==1)
    {
    ifstream fin("teacher.dat",ios::binary|ios::in);
    tea_struct y;
    int a;
    date1 dok;
    cout<<"Enter the doj to find"<<endl;
    cin>>dok.dd>>dok.mm>>dok.yy;
    while(fin.read((char*)&y,sizeof(y)))
    {
        if((y.doj.dd==dok.dd)&&(y.doj.mm==dok.mm)&&(y.doj.yy==dok.yy))
        {
            cout<<y.code<<" "<<y.dob.dd<<"/"<<y.dob.mm<<"/"<<y.dob.yy<<" "<<y.doj.dd<<"/"<<y.doj.mm<<"/"<<y.doj.yy<<" "<<y.Phone<<" "<<y.Name<<" "<<y.Clss1<<" "<<y.Clss2<<" "<<y.Father_name<<" "<<y.Address<<" "<<y.salary<<" "<<y.sub1<<" "<<y.sub2<<endl;
        }
    }
    fin.close();
   cout<<"press any digit for back"<<endl;
   getch();
   display_menu(1);
   }
}
void display_class(int n)
{ fflush(stdout);
    system("CLS");
    int a,b;
    char c[25];
    cout<<"Enter class"<<endl;
    cin>>b;
    if(n==0)
    {
     strcpy(c,"student.dat");
      cout<<"================================================================================================================================================="<<endl;
      cout<<"roll no"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class"<<"\t"<<"father name"<<"\t"<<"mother name"<<"\t"<<"address"<<"\t"<<"hindi"<<"\t"<<"english"<<"\t"<<"science"<<"\t"<<"maths"<<"\t"<<"total"<<"\t"<<"average"<<endl;
      cout<<"================================================================================================================================================="<<endl;
    }
    else
    {
        strcpy(c,"teacher.dat");
          cout<<"================================================================================================================================================="<<endl;
          cout<<"code"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class1"<<"\t"<<"class2"<<"\t"<<"father name"<<"\t"<<"address"<<"\t"<<"salary"<<"\t"<<"subject1"<<"\t"<<"subject2"<<endl;
          cout<<"================================================================================================================================================="<<endl;
    }
    ifstream fin(c,ios::binary|ios::in);
     if(n==0)
    {
         stu_struct x;
          while(fin.read((char*)&x,sizeof(x)))
       {
        if(x.clss==b)
        {
         cout<<x.roll<<"\t "<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<"\t"<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<"\t"<<x.phone<<"\t"<<x.name<<"\t"<<x.clss<<"\t"<<x.father_name<<"\t"<<x.mother_name<<"\t"<<x.address<<"\t"<<x.hindi<<"\t"<<x.english<<"\t"<<x.science<<"\t"<<x.maths<<"\t"<<x.total<<"\t"<<x.avg<<endl;
        }
       } 
       fin.close();
       cout<<"Enter a digit for back"<<endl;
       getch();
       display_menu(0);
    }
    else
    {
         tea_struct y;
               while(fin.read((char*)&y,sizeof(y)))
                {      
                     if((y.Clss2==b)||(y.Clss1==b))
                   {
                    cout<<y.code<<" "<<y.dob.dd<<"/"<<y.dob.mm<<"/"<<y.dob.yy<<" "<<y.doj.dd<<"/"<<y.doj.mm<<"/"<<y.doj.yy<<" "<<y.Phone<<" "<<y.Name<<" "<<y.Clss1<<" "<<y.Clss2<<" "<<y.Father_name<<" "<<y.Address<<" "<<y.salary<<" "<<y.sub1<<" "<<y.sub2<<endl;
                    }
                }
                 fin.close();
                 cout<<"Enter a digit for back"<<endl;
                 getch();
                 display_menu(1);
     }
}
void display_sub_pass(int n)
{ fflush(stdout);
    system("CLS");
    int a;
    char c[25];
    if(n==0)
    {
     strcpy(c,"student.dat");
      cout<<"================================================================================================================================================="<<endl;
      cout<<"roll no"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class"<<"\t"<<"father name"<<"\t"<<"mother name"<<"\t"<<"address"<<"\t"<<"hindi"<<"\t"<<"english"<<"\t"<<"science"<<"\t"<<"maths"<<"\t"<<"total"<<"\t"<<"average"<<endl;
      cout<<"================================================================================================================================================="<<endl;
    }
    else
    {
        strcpy(c,"teacher.dat");
          cout<<"================================================================================================================================================="<<endl;
          cout<<"code"<<"\t"<<"DOB"<<"\t"<<"DOJ"<<"\t"<<"phone no."<<"\t"<<"name"<<"\t"<<"class1"<<"\t"<<"class2"<<"\t"<<"father name"<<"\t"<<"address"<<"\t"<<"salary"<<"\t"<<"subject1"<<"\t"<<"subject2"<<endl;
          cout<<"================================================================================================================================================="<<endl;
    }
    ifstream fin(c,ios::binary|ios::in);
    if(n==0)
    {
    stu_struct x;
     while(fin.read((char*)&x,sizeof(x)))
    {
        if(x.avg>=50)
        {
         cout<<x.roll<<" "<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy<<" "<<x.doj.dd<<"/"<<x.doj.mm<<"/"<<x.doj.yy<<" "<<x.phone<<" "<<x.name<<" "<<x.clss<<" "<<x.father_name<<" "<<x.mother_name<<" "<<x.address<<" "<<x.hindi<<" "<<x.english<<" "<<x.science<<" "<<x.maths<<" "<<x.total<<" "<<x.avg<<endl;
        }
    }
    fin.close();
    cout<<"Enter 1 for back"<<endl;
    getch();
    display_menu(0);
    }
    else
    {
      tea_struct y;
      fflush(stdin);
      cout<<"Enter subject"<<endl;
      char b[25];
      gets(b);
    while(fin.read((char*)&y,sizeof(y)))
    {//cout<<b<<endl;
     if(strcmp(y.sub1,b)==0||strcmp(y.sub2,b)==0)
     { //cout<<y.code;
       cout<<y.code<<" "<<y.dob.dd<<"/"<<y.dob.mm<<"/"<<y.dob.yy<<" "<<y.doj.dd<<"/"<<y.doj.mm<<"/"<<y.doj.yy<<" "<<y.Phone<<" "<<y.Name<<" "<<y.Clss1<<" "<<y.Clss2<<" "<<y.Father_name<<" "<<y.Address<<" "<<y.salary<<" "<<y.sub1<<" "<<y.sub2<<endl;
     }
    }
    fin.close();
    cout<<"Enter 1 for back"<<endl;
    getch();
    display_menu(1);
    }
}

main()
{
  // long total;
   //cout<<"enter amount"<<endl;
  // cin>>total;
 // cout<<convert(total)<<endl;
  welcome_window();
  //update_menu(1);
  //display_class(1);
  //display_sub_pass(1);
  //date_due();
 return 0;

}