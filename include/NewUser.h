#ifndef NEWUSER_H
#define NEWUSER_H
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class NewUser{
    public:
        NewUser();
        virtual ~NewUser();
        NewUser(string, string, string , string, int, int);
        int exit3 = 0;
        string userNameAttempt;
        string passWordAttempt;
        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }
        void getDetails();
        void writeProfile();
        void readProfile();
        void writeScorecard();
        void readScorecard();
        void login();
        void calcHandicap();
        void loginAdmin();
        void adminOptions();
        void removeUser();
        void Menu();
        void userMenu();
        string Getusername() { return username; }
        void Setusername(string val) { username = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getsurname() { return surname; }
        void Setsurname(string val) { surname = val; }
        string GetDOB() { return DOB; }
        void SetDOB(string val) { DOB = val; }
        int Gethandicap() { return handicap; }
        void Sethandicap(int val) { handicap = val; }
        string username;
    protected:
    private:
        const string usernameAdmin = "Admin";
        const string passwordAdmin = "Admin";
        string password;
        //cout<<"Do you want to >>"<<endl<<"1.Create a New score card"<<endl<<"2.Print Scorecards"<<endl<<"3.View Profile"<<endl<<"4.Logout and retrun to menu" <<endl<<"5.Exit & Close" << endl;
        string name;
        string surname;
        string DOB;
        int handicap;
        int strokes[18];
        const int hole_num[18] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        const int hole_dif[18] = {16,4,8,2,18,14,10,6,12,11,15,5,13,1,17,7,3,9};
        int par[18] = {4,5,3,4,4,5,3,5,3,5,3,4,4,4,4,5,4,3};
        int holes[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int free_strokes[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int net_strokes[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int scoretopar[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int points [18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};
#endif // NEWUSER_H
