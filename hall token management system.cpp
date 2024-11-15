#include<iostream>
#include<fstream>
#include<conio.h>
#include<time.h>
#include<string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
class enter;
class meal;
 void logout();
string new_user_id;
string User_ID;
vector<string>vt{"MONDAY","TUESDAY","WEDNESDAY","THURSDAY", "FRIDAY","SATURDAY", "SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY", "FRIDAY","SATURDAY", "SUNDAY"};
vector<string>vtt{"BREAKFAST","LUNCH","DINNER"};
pair<string,string>P[7]=
{
    {"RICE + FRIED + CHICKEN MEAT + DAL               30","RICE + FRIED + BIG FISH + DAL                   30"},
    {"RICE + FRIED + SMALL FISH +  DAL                30","RICE + FRIED + VEGETABLE + FRIED + DAL          30"},
    {"RICE + FRIED + BEEF + DAL                       30","RICE + FRIED + EGG + DAL                        30"},
    {"RICE + FRIED + BIG FISH + DAL                   30","RICE + FRIED + CHICKEN MEAT + DAL               30"},
    {"RICE + FRIED + CHICKEN MEAT +  DAL              30","RICE + FRIED + SMALL FISH + DAL                 30"},
    {"RICE + FRIED + GOLDEN CHICKEN MEAT + DAL        30","RICE + FRIED + VEGETABLE + FRIED + DAL          30"},
    {"RICE + FRIED + BEEF(KHASHI) + DAL               30","RICE + FRIED + EGG + DAL                        30"}
};
pair<int,string>p[14][3];
int ar[10];
void time()
{
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char dateStr[50];
    strftime(dateStr, sizeof(dateStr), "%A, %B %d, %Y", localTime);
    cout<<endl;
    cout<<"                                            MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY                                "<<dateStr<<endl;
    cout<<"                                                          Santosh, Tangail."<<endl<<endl;
     cout<<"                                                 Hall Food Token Management System"<<endl;
      cout<<"                                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;

   // cout<<"WELCOME"<<"                                                                                                                   "<<dateStr<<endl<<endl;
}
void storeData(const string& filename, const map<string, string>& data)
{
    ofstream file(filename,ios ::app);

    if (file.is_open())
    {
        for (const auto& pair : data)
        {
            file << pair.first << ": " << pair.second << "\n";
        }
        file.close();
    }
}
map<string, string> readData(const string& filename,string strn)
{
    map<string, string> data;
    ifstream file(filename, ios::app);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t colonPos = line.find(':');
            if (colonPos != string::npos)
            {
                string key = line.substr(0, colonPos);
                string value = line.substr(colonPos + 1);
                if(key==strn)
                    data[key] = value;
            }
        }
        file.close();
    }
    return data;
}

void storeMapData(const string& filename, map<string,vector<string>>& data)
{
    ofstream file(filename,ios::app);

    if (file.is_open())
    {
        for (const auto& pair : data)
        {
            file << pair.first << ": ";
            for (const string& value : pair.second)
            {
                file << value << " ";
            }
            file << "\n";
        }
        file.close();
    }
}
map<string,vector<string>> readMapData(const string& filename,string profile)
{
    map<string, vector<string>> data;
    profile =profile+":";
    ifstream file(filename);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            string key;
            iss >> key;
            if(key==profile)
            {
                string value;
                while (iss >> value)
                {
                    data[key].push_back(value);
                }
            }
        }
        file.close();
    }
    return data;
}
void profile(string user_name)
{
    map<string,vector<string>>mp;
    vector<string>vt;
    string nameF;
    string nameL;
    string id;
    string dept;
    string phon_num;
    string session;
    cout<<"ENTER YOUR FIRST NAME : ";
    getline(cin,nameF);
    cout<<"ENTER YOUR LAST NAME : ";
    getline(cin,nameL);
    cout<<"ENTER YOUR ID : ";
    getline(cin,id);
    cout<<"ENTER YOUR DEPARTMENT : ";
    getline(cin,dept);
    cout<<"ENTER YOUR SESSION : ";
    getline(cin,session);
    cout<<"ENTER YOUR PHONE NUMBER : ";
    getline(cin,phon_num);
    cout<<endl;
    string name=nameF+"_";
    name=name+nameL;
    vt.push_back(name);
    vt.push_back(id);
    vt.push_back(dept);
    vt.push_back(session);
    vt.push_back(phon_num);
    mp[user_name]=vt;
    storeMapData("map.txt",mp);
     system("cls"); time(); cout<<endl;
}
int sum=0;
class meal
{
public:

    int point;
    void current_date()
    {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        char dateStr[50];
        strftime(dateStr, sizeof(dateStr), "%A, %B %d, %Y", localTime);
        cout<<"DAY                                         MEAL                               TAKA"<<endl;
        DAY(localTime->tm_wday);
    }
    void DAY(int D)
    {

        cout<<""<<vt[D%7]<<endl<<endl;
        cout<<"         1)BREAKFAST                 BREAD + FRIED EGG                          20"<<"            "<<endl;
        cout<<"         2) LUNCH"<<"               "<<P[D%7].first<<"            "<<endl;
        cout<<"         3) DINNER"<<"              "<<P[D%7].second<<"            "<<endl;
        cout<<""<<vt[(D+1)%7]<<endl<<endl;
        cout<<"         4)BREAKFAST                BREAD + FRIED EGG                           20"<<"            "<<endl;
        cout<<"         5) LUNCH"<<"               "<<P[(D+1)%7].first<<"            "<<endl;
        cout<<"         6) DINNER"<<"              "<<P[(D+1)%7].second<<"            "<<endl;
        cout<<""<<vt[(D+2)%7]<<endl<<endl;
        cout<<"         7)BREAKFAST                 BREAD + FRIED EGG                          20"<<"            "<<endl;
        cout<<"         8) LUNCH"<<"               "<<P[(D+2)%7].first<<"            "<<endl;
        cout<<"         9) DINNER"<<"              "<<P[(D+2)%7].second<<"            "<<endl<<endl;
         cout<<"Choose Any Option........."<<endl;
        string point;
        while(1)
        {
            point =getch();
            if(point>="1" &&point<="9"|| point[0] ==13)
            {
                cout<<point<<' ';
                if(point[0]==13)
                    break;
                char ch[1];
                ch[0]=point[0];
                int top=ch[0]-'0';
                if(top%3==0)
                {
                    p[D+top/3-1][2].first++;
                }
                else
                {
                    p[D+top/3][top%3-1].first++;
                }
                total(top);
            }
        }
        system("cls"); time(); cout<<endl;
       // cout<<"                                                                                                                       TOTOA = "<<sum<<endl;
        SHOW();
    }
    int total(int x)
    {
        if(x%3==1)
        {
            sum=sum+20;
        }
        else sum=sum+30;
    }
    void SHOW()
    {
        pair<string,int>pr[2001];
        int k=0;
        string str;
        for(int i=0; i<14; i++)
        {
            for(int j=0; j<3; j++)
            {
                {
                    if(p[i][j].first!=0)
                    {
                       // cout<<vt[i]<<' '<<vtt[j]<<' '<<p[i][j].first<<endl;
                        string st=vt[i];
                        st+="_";
                        st+=vtt[j];
                        pr[k].first=st;
                        pr[k].second=p[i][j].first;
                        k++;
                        str+=vt[i];
                        str+="_";
                        str+=vtt[j];
                        str+="_";
                        str+=to_string(p[i][j].first);
                        str+="-";
                    }
                }
            }
        }
        str+="$";
        str+=to_string(sum);
        map<string,string>MP;
        MP[new_user_id]=str;
        string file = "mp.txt";
        storeData(file, MP);
        int t;
        cout<<"1. SHOW YOUR PROFILE"<<endl;
        cout<<"2. LOGOUT"<<endl;
        cout<<"3. EXIT"<<endl;
        cin>>t; system("cls"); time(); cout<<endl;
        if(t==2)
          logout();
          else if(t==1)sh_profile();
          else exit(0);

    }
    void logout();
    void sh_profile();


};
class enter:public meal
{
public:
    string Password = "";
    string User_ID;
    fstream projectfile_userid;
    fstream projectfile_passward;
    void fileopen()
    {
        projectfile_userid.open("projectfileuser.txt",fstream::in|fstream::app);
        projectfile_passward.open("projectfilepassward.txt",fstream::in|fstream::app);
    }
    void fileclose()
    {
        projectfile_passward.close();
        projectfile_userid.close();
    }
    void  registration()
    {
        fileopen();
        string new_password;
        cout<<"ENTER YOUR USER_ID : ";
        cin>>new_user_id;
        string check_user_id;
        while(projectfile_userid>>check_user_id)
        {
            if(check_user_id==new_user_id)
            {    system("cls"); time(); cout<<endl<<endl;
                cout<<"USER_ID IS NOT VALID"<<endl;
                cout<<"TRY AGAIN"<<endl;
                projectfile_userid.close();
                projectfile_passward.close();
                registration();
                return;
            }
        }
        projectfile_userid.close();
        projectfile_passward.close();
        projectfile_userid.open("projectfileuser.txt",fstream::in|fstream::app);
        projectfile_passward.open("projectfilepassward.txt",fstream::in|fstream::app);
        projectfile_userid<<endl;
        projectfile_userid<<new_user_id;
        cout<<"ENTER YOUR PASSWORD : ";
        char ch;
        while ((ch = getch()) != '\r')
        {
            new_password += ch;
            cout << '*';
        }
        new_password+=new_user_id;
        projectfile_passward<<endl;
        projectfile_passward<<new_password;
        fileclose();
        cout<<endl;
        getchar();
        profile(new_user_id);
        cout<<"YOU HAVE SUCCESSFULLY COMPLETED YOUR REGISTRATION."<<endl;
        option();
    }
    void login()
    {
        fileopen();
        cout<<"ENTER YOUR USER_ID : ";

        cin>>User_ID;
        new_user_id =User_ID;
        cout<<"ENTER YOUR PASSWORD : ";
        string Password = "";
        char ch;
        while ((ch = getch()) != '\r')
        {
            Password += ch;
            cout << '*';
        }
        check(Password);
    }
    void check(string Password)
    {
        string user;
        string password;
        int f=0;
        while(projectfile_userid>>user)
        {
            if(user==User_ID)
            {
                f++;
                Password+=User_ID;
                while(projectfile_passward>>password)
                {
                    if(password==Password)
                    {
                        f++; system("cls"); time(); cout<<endl;
                        cout<<"\nYOU ARE LOGED IN"<<endl;
                        fileclose();
                        break;
                    }
                }
                if(f==2)break;
            }
        }
        if(f<2)
        {
            system("cls"); time(); cout<<endl;
            cout<<"\nWRONG USER_ID OR PASSWORD"<<endl;
            cout<<"PLEASE TRY AGAIN"<<endl;
            fileclose();
            option();
        }

        int point;
        cout<<"1. SHOW FOOD MENU"<<endl;
        cout<<"2. SHOW YOUR PROFILE"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"Choose Any Option........."<<endl;
        cin>>point;
        system("cls"); time(); cout<<endl;
        if(point==1) current_date();
        else if(point==2) show_profile();
        else exit(0);
    }
         void show_profile();
    void option();

};
void meal::sh_profile()
{
    enter obj;
    obj.show_profile();
}
void enter::show_profile()
{
    {
        User_ID =new_user_id;
        map<string,vector<string>> mpp = readMapData("map.txt",User_ID);
        for(auto x:mpp)
        {
            vector<string>k;
            k=x.second;
            string s=k[0];
            cout<<"YOUR INFORMATION"<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='_') s[i]=' ';
                else s[i]=s[i];
            }
            cout<<"NAME       : "<<s<<endl;
            cout<<"ID         : "<<k[1]<<endl;
            cout<<"DEPARTMENT : "<<k[2]<<endl;
            cout<<"SESSION    : "<<k[3]<<endl;
            cout<<"NUMBER     : "<<k[4]<<endl;
        }
        cout<<endl<<endl;
        cout<<"YOUR FOOD PURCHASED INFORMATION"<<endl;
         cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        map<string, string> readdata = readData("mp.txt",User_ID);
        if(readdata.size()==0) cout<<"    EMPTY"<<endl;
        else
        for(auto x:readdata)
        {
            string ax=x.second;

            for(int i=1; i<ax.size(); i++)
            {
                if(ax[i]=='_') cout<<" ";
                else if(ax[i]=='-') cout<<endl;
                else if(ax[i]=='$')
                {
                    cout<<"TOTAL              ";
                    for(int j=i+1;j<ax.size();j++) cout<<ax[j];
                    cout<<" TAKA"<<endl;
                    break;
                }
                else  cout<<ax[i];
            }
        }
        cout<<endl;
        cout<<"1. SHOW FOOD MENU"<<endl;
        cout<<"2. LOGOUT"<<endl;
        cout<<"3. EXIT"<<endl; int t;
        cout<<"Choose Any Option........."<<endl;
        cin>>t; system("cls"); time(); cout<<endl;
        if(t==2)
          logout();
          else if(t==3) exit(0);
          else current_date();
    }
}
 void meal::logout()
    {
        enter obj;
        obj.option();
cout<<endl;
    }
void enter::option()
    {
        cout<<"1. LOGIN"<<endl;
        cout<<"2. REGISTRATION"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"Choose Any Option........."<<endl;
        int point;
        {
            cin>>point;
             system("cls"); time(); cout<<endl;
            switch(point)
            {
            case 1:
            {
                login();
                break;
            }
            case 2:
            {
                registration();
                break;
            }
            case 3:
                {
                     exit(0);
                }
            default:
            {
                cout<<"PLEASE SELECT OPTION 1 OR 2 OR 3"<<endl;
                option();
            }

            }
        }
    }

int main()
{
    time();
    enter object;
    object.option();
    // meal object;
    //  object.current_date();
//  object.day
  
}
