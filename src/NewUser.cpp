#include "NewUser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

NewUser::NewUser(string u, string p, string n, string s, int dob, int h){
    username = u;
    password = p;
    name = n;
    surname = s;
    DOB = dob;
    handicap = h;
}

NewUser::NewUser(){
    //ctor
}
NewUser::~NewUser(){/*dtor*/}

void NewUser::userMenu(){
    int userchoice2 = 0;
    cout<<"=================================Main Menu================================="<<endl<<"Do you want to >>"<<endl<<"1.Create a New score card"<<endl<<
    "2.Print Scorecards"<<endl<<"3.View Profile"<<endl<<"4.Logout and retrun to menu" <<endl<<"5.Exit & Close" << endl;
    cin>>userchoice2;
    while(userchoice2 < 0 || userchoice2 > 5){//check if the input for userchoice2 is a correct value
        system("CLS");
        cout<<"-----------PLEASE ENTER A VALID NUMBER -----------"<<endl<<endl<<"Do you want to >>"<<endl<<"1.Create a New score card"<<endl<<
    "2.Print Scorecards"<<endl<<"3.View Profile"<<endl<<"4.Logout and retrun to menu" <<endl<<"5.Exit & Close" << endl;
        cin>>userchoice2;
    }
    system("CLS");
    if (userchoice2 == 1){
        cout<<"*******************Creating new score card******************* "<<endl;
        writeScorecard();
    }
    if (userchoice2 == 2){
        cout<<"Printing Data Stored "<<endl;
        readScorecard();
    }
    if (userchoice2 == 3){
        readProfile(); /// Prints out the text file
        //one.readHandicap();
    }
    if (userchoice2 == 4){
        system("CLS");
        Menu();///goes back to main menu
    }
    if (userchoice2 == 5){///leave the program

        system("CLS");
        cout << "Goodbye, see you soon. " << endl;
        abort();
    }
}
void NewUser::login(){
    system("CLS"); // clears console
    cout << endl << "*******************LOGIN*******************" << endl << endl; //display login screen
    string filename; //variable used for the file name
    string un,pw; //variables used to select line from text file
    un = 1; //variable to point at line 1 in txt document
    pw = 2; //variable to point at line 2 in txt document
    ifstream file; //input to file
    cout << "Please enter your username: " << endl; // get username
    cin >> userNameAttempt; //input username
    filename = userNameAttempt + ".txt"; //define file name by username
    file.open(filename);// opens file
    getline(file, un); // get username from the first line (un)
    getline(file, pw); // get password from the second line (pw)
    file.close(); // close file
    if(userNameAttempt==un){ // check username in file matches entered username
        cout << "Password: "; // display "Password"
        cin >> passWordAttempt; // input password
        if(passWordAttempt== pw){ // check if password is correct
            system("CLS");
            exit3 = 0;
            cout << "Login Successufl!" << endl;
            userMenu();
        }
        else if (passWordAttempt != pw) // check password doesn't matcj
        {
            while (passWordAttempt != pw) // repeat till password matches
            {
                cout << "Wrong password! Try again. \npassword: " << endl; //print out wrong password
                cin >> passWordAttempt; //input password
            }
        }
    }
    else if (userNameAttempt!=un) // goes back to login if the username is not found.
    {
        cout << "No username found" << endl << "Please enter a valid username." << endl; //prints out no username
        login(); // returns to begin to attempt login again.
    }
}
void NewUser::Menu(){//user interface menu
    string userchoice1 ="0";
    cout << "*******************Welcome to the Golf Club System*******************" << endl;
    cout<<"Do you want to: "<<endl<<" >>>1.Login"<<endl<<" >>>2.Admin"<<endl;
    cin>>userchoice1;
    while (userchoice1 != "1" && userchoice1 !="2"){
        system("CLS");
        cout<<"-----------PLEASE ENTER A VALID NUMBER -----------"<<endl<<"Do you want to: "<<endl<<" >>>1.Login"<<endl<<" >>>2.Admin"<<endl;
        userchoice1 = "0";
        cin>>userchoice1;
    }
    if (userchoice1 == "1"){
        //#login
        login();
    }
    if (userchoice1 == "2"){
        //#sign up
        loginAdmin();
    }
}
void NewUser::adminOptions(){
    cout << "Would you like to \n1.Create a new user.\n2.View user details & scorecards.\n3.Remove existing user.\n4.Logout and return to main menu.\n5.Exit." << endl; //asks what the admin would like to do
    string adminChoice = "0"; // sets default choice to 0
    cin >> adminChoice; // input for admin choice
    while (adminChoice != "1" && adminChoice !="2" && adminChoice !="3"&& adminChoice !="4" && adminChoice !="5") //runs till a number between 1 & 3 is selected
    {
        system("CLS"); // clears console
        cout<<"-----------PLEASE ENTER A VALID NUMBER -----------"<<endl<<"Would you like to \n1.Create a new user.\n2.View user details & scorecards.\n3.Remove existing user.\n4.Logout and return to main menu.\n5.Exit."<<endl; //asks for valid input
        adminChoice = "0"; // sets default choice to 0
        cin>>adminChoice; // input for admin choice
        system("CLS"); // clear console
    }
    if (adminChoice == "1") // if "Create new user is selected"
    {
        getDetails(); // runs get details to obtain new login details
        system("CLS"); // clears console
        cout << "**************User Created Successfully**************" << endl << endl;
        adminOptions(); // returns to admin options
    }
    else if (adminChoice == "2") // if "View user is selected"
    {
        userNameAttempt = usernameAdmin; // sets the usernameAttempt to Admin which later enters a private loop
        system("CLS"); // clears console
        readProfile(); // reads user profile
        readScorecard(); // reads user scorecard
        adminOptions(); // returns to admin options
    }
    else if (adminChoice == "3")
    {
        system("CLS");
        removeUser();
        cout << "**************User Removed Successfully**************" << endl << endl;
        adminOptions();
    }
    else if (adminChoice == "4")
    {
        userNameAttempt = "";
        passWordAttempt = "";
        system("CLS");
        Menu();
    }
    else if (adminChoice == "5")
    {
        exit3 = 1;
        system("CLS");
        cout << "Goodbye, see you soon. " << endl;
    }
}
void NewUser::removeUser(){
    cout << endl << "*******************User Removal*******************" << endl << endl;
    cout << "Please enter the username of the player you would like to delete:" << endl;
    cin >> username;
    string filename;
    filename = (username + ".txt");
    remove(filename.c_str());

}
void NewUser::loginAdmin(){
    system("CLS"); // clears console
    cout << endl << "*******************ADMIN LOGIN*******************" << endl << endl; // prints out screen for Admin Login
    cout << "Password: "; // prints out password
    cin >> passWordAttempt; // input password
        if (passWordAttempt != passwordAdmin) // password doesn't match
        {
            while (passWordAttempt != passwordAdmin) // runs till password is correct
                {
                cout << "Wrong password! Try again. \npassword: " << endl; // prints wrong password
                cin >> passWordAttempt; // input password
                }
        }
        if (passWordAttempt == passwordAdmin) // if password matches
        {
            system("CLS"); // clear system
            userNameAttempt = usernameAdmin; // sets usernameAttempt to Admin
            cout << "*******************Welcome Admin*******************\n" << endl; // prints out welcome screen
            adminOptions(); // goes to admin options
        }
}
void NewUser::getDetails(){
    system("CLS"); // clears console
    int exit = 0; // sets exit variable to 0
    while (exit < 1) // run while exit is not 1
    {
        cout << endl << "*******************REGISTRATION*******************" << endl; // prints out registration screen
        cout << endl << "Username: "; // prints out username
        cin >> username; // input username
        string un = "1"; //variable used to go to line 1 in text file
        string filename; // variable used for the file name
        ifstream file; //input
        filename = username + ".txt"; // sets the file name to the username
        file.open(filename);// opens file
        if (file.fail()) // if file successfully creates exits while loop and asks for password
        {
            exit = 1;
        }
        else if (!file.fail()) // if file name is not created successfully
        {
            system("CLS"); // clears console
                cout << "***********************ERROR********************** \nUsername already used, Please input a new username! \n" << endl; // prints out error & asks for a username
                exit = 0; // repeats this while loop to get a new username
        }
    }
    cout << "Password: "; // prints password
    cin >> password; // gets password
    cout << "Name: "; // prints name
    cin >> name; // gets name
    cout << "Surname: "; // prints surname
    cin >> surname; // gets surname
    cout << "DOB, numbers only Day,Month,Year: "; // prints DOB
    cin >> DOB; // gets DOB
    cout << "Handicap level: "; // prints handicap level
    cin >> handicap; // gets handicap
    while (handicap < 0 || handicap > 54){ // while the handicap is not within the expected range repeats till valid
        cout << "Please enter a valid handicap level :"; // prints handicap level
        cin >> handicap; // gets handicap
    }
    writeProfile(); // goes to writeProfile which stores the data in a text file
}
void NewUser::writeProfile(){
    string filename; //variable for filename
    ifstream fsIn; //input
    ofstream fsOut; // output
    fstream both; // both input & output
    filename = username + ".txt"; // makes the filename the username
    fsOut.open(filename); //opens file
    if (!fsOut){  //checks to see if a file is opened
        cout << "Cannot open file to write profile.\n"; // prints can't open file
    }
    else{ // confirms file is opened
        fsOut<< username  << endl << password << endl << name  << endl << surname << endl << DOB << endl << handicap <<endl;//writes the above to the file
    }
    fsOut.close(); // closes file
}
void NewUser::readProfile(){
    string filename; // variable for filename
    string un,pw,n,s,d,h; // strings used for location of file
    un = 1; // points username to line 1
    pw = 2; // points password to line 2
    n = 3; // points name to line 3
    s = 4; // points surname to line 4
    d = 5; // points DOB to line 5
    h = 6; // points handicap to line 6
    ifstream file; //input
    if (userNameAttempt == usernameAdmin) // checks the username is the same as Admin
    {
        cout << "Please enter the username of the profile you want to view" << endl; // asks for admin to enter profile to view
        cin >> userNameAttempt; // gets username of player
    }
    filename = userNameAttempt + ".txt"; // makes the username the filename
    file.open(filename);// opens file
    if (file.fail()) // if file can't open
    {
       cout << "File failed to open." << endl; // prints failed to open
    }
    else // if file can open
    {
        getline(file, un); // gets username from text file
        getline(file, pw); // gets password from text file
        getline(file, n); // gets name from text file
        getline(file, s); // gets surname from text file
        getline(file, d); // gets DOB from text file
        getline(file, h); // gets handicap from text file
        cout << "Username: "<< un  << endl << "Name: "<< n  << endl << "Surname: "<< s << endl<< "DOB: " << d << endl<< "Handicap: " << h <<endl; // prints out details from text file
    }
    file.close(); // closes file
}
void NewUser::writeScorecard(){
    string date; // variable for date
    string filename; // variable for filename
    ifstream fsIn; //input
    ofstream fsOut; // output
    fstream both; // both input & output
    cout << "Please input todays date: "; // prints out request for the date
    cin >> date; // input date
    filename = userNameAttempt + date + ".txt"; // makes the filename username and date
    fsOut.open(filename); // opens file
    if (fsOut.fail()){  //checks to see if a file is opened
        cout << "Cannot open file .\n"; // prints out cant open file
    }
    else // run if file is open
    {
        for (int i = 0; i < 18; i++ ) // run for 18 times for the amount of holes
        {
            cout << "Please enter the strokes on hole " << (i+1) << endl; // prints enter strokes
            cin >> holes[i]; // gets entry for hole
            fsOut << holes[i] << endl; // stores strokes for hole in text file
        }
        system("CLS");
        cout << "Successfully Stored game!" << endl; // print out success!
    }
    fsOut.close(); // close file
}
void NewUser::readScorecard(){
    string filename; // variable for filename
    ifstream fsIn; // input stream
    ofstream fsOut; // output stream
    fstream both; // both
    string date; // variable for date
    string line; // variable for the line at which will be opened
    int lineNum = 1; // set default line to 1
    cout << "Please enter the date of the game\nDate: "; // print out
    cin >> date; // get date
    filename = userNameAttempt+ date + ".txt"; // set filename to username and date
    fsIn.open(filename);// opens file
    string exit3 = "1"; // variable used to exit loop
    while (!fsIn)  // checks to see if a file is opened
    {
        if (exit3 == "0") // if exit is set as 0 return to admin options
        {
            system("CLS"); // clear console
            return;
            adminOptions(); // return to Admin options

        }
        else
        {
            system("CLS"); // clear console
            cout << "***********************ERROR!***********************\nCannot open file.\nPlease enter the date of the game or type 0 to return:"; // print out error
            cin >> date; // get date
            exit3  =date; // set date as exit3 to check if 0 was inputed
            filename = userNameAttempt+ date + ".txt"; // set filename as username and date
            fsIn.open(filename); // opens file
        }
    }
    string line_data = "0"; // set variable to 0 to start at line 0
    while(lineNum < 19)  // while the file hasn't reached the end
    {
        getline(fsIn, line_data); //fetch line from data.txt and put it in a string
        cout << "Strokes in hole " << lineNum << " are " << line_data << endl; // print out strokes in hole
        int dataHole = stoi(line_data); // change value of string line_data to int datahole
        holes[lineNum-1] = dataHole;
        lineNum  = lineNum + 1;
        line_data = line_data +"1";
    }
    fsIn.close();
    for (int x=0;x != 1; x++){//ensure program loops only once
        //free strokes proportional to the handicap
        if (handicap == 0 ) //execute if handicap == 0
        {
                for (int i=0; i <= 17; i++)
                {
                    free_strokes[i] = 0; /// set all free strokes to make sure that there will be no unexpected integers in the array
                }
        }
        else if  (handicap <= 18 && handicap >0){ //execute if handicap <= 18 && handicap >0
            for (int i = 0; i <= 17; i++){
                if (hole_dif[i] == 1 || hole_dif[i] <= handicap )
                {
                    free_strokes[i] = 1; ///set free strokes in the array to 1 (based on the handicap)
                }
            }
        }
        else if  (handicap > 18 && handicap <=35){//execute if handicap > 18 && handicap <=35
            for (int i = 0; i <= 17; i++){
                free_strokes[i] = 1; ///set all free strokes to 1
            }
            int freeleft = handicap-18; // use the remaining free strokes to add 1 to the hardest holes
            if (freeleft > 0){
                for (int i = 0; i <= 17; i++){
                    if (hole_dif[i] == 1 || hole_dif[i] <= freeleft)
                    {
                        free_strokes[i] += 1; ///set free strokes in the array to +1 (based on the handicap)
                    }
                }
            }
        }
    else if  (handicap > 35 && handicap <=54){//execute if handicap > 35 && handicap <=54
        for (int i = 0; i <= 17; i++){
            free_strokes[i] = 2; ///set all free strokes to 2
        }
        int freeleft = handicap-36;// use the remaining free strokes to add 1 to the hardest holes
        if (freeleft > 0){
            for (int i = 0; i <= 17; i++){
                if (hole_dif[i] == 1 || hole_dif[i] <= freeleft)
                {
                    free_strokes[i] += 1; ///set free strokes in the array to +1 (based on the handicap)
                }
            }
        }
    }
    //calculating array for net strokes
    for (int i=0; i <= 17; i++){
        net_strokes[i] = holes[i] - free_strokes[i];}
    //calculating score to par
    for (int i=0;i<=17;i++){
        scoretopar[i] = (net_strokes[i]) - par[i];
    }
    //calculating points based on the tables given in the breif
    for(int i=0;i<=17;i++){
        if (scoretopar[i] >= 2){
            points[i] = 0;
        }
        if (scoretopar[i] == 1){
            points[i] = 1;
        }
        if (scoretopar[i] == 0){
            points[i] = 2;
        }
        if (scoretopar[i] == -1){
            points[i] = 3;
        }
        if (scoretopar[i] == -2){
            points[i] = 4;
        }
        if (scoretopar[i] == -3){
            points[i] = 5;
        }
        if (scoretopar[i] == -4){
            points[i] = 6;
        }
        if (scoretopar[i] == -5){
            points[i] = 7;
        }
        if (scoretopar[i] == -6){
            points[i] = 8;
        }
        if (scoretopar[i] == -7){
            points[i] = 9;
        }
    }
    //printing out score cards (using the (-) simbol to create a table like structure)
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Holes  / ";
    for(int i = 0 ; i <=17 ; i++){
        cout<< hole_num[i]<<" / ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Par    / ";
    for(int i = 0 ; i <=17 ; i++){
        cout<< par[i]<<" / ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"In-    / ";
    for(int i = 0 ; i <=17 ; i++){
        cout<< hole_dif[i]<<" / ";
    }
    cout<<endl;
    cout<<"dex    / "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Free   /";
    for(int i = 0 ; i <=17 ; i++){
        cout<< free_strokes[i]<<" / ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Net    /";
    for(int i = 0 ; i <=17 ; i++){
        cout<< net_strokes[i]<<" / ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Free   /";
    for(int i = 0 ; i <=17 ; i++){
        cout<< free_strokes[i]<<" / ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Points /";
    int totalPoints = 0;
    for(int i = 0 ; i <=17 ; i++){
        cout<< points[i]<<" / ";
        totalPoints = totalPoints + points[i];
    }
    cout<<"\nTotal points:" << totalPoints << endl;
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
}
}
