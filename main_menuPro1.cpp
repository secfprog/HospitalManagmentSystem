#include<iostream>
using namespace std;

struct MenuInterface
{
    void mainMenu()
    {
        int input;

        cout<<"\n\n\t\tWELCOME TO HOSPITAL MANAGENT SYSTEM\n\n\n";
        cout<<"\t\tPress\n\n";
        cout<<"\t\t1. Login\n";
        cout<<"\t\t2. Sign Up\n";
        cout<<"\t\t3. Quit\n";

        cout<<"\n\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            loginMenu();
        }
        else if(input==2)
        {
            signUpMenu();
        }
    }

    void loginMenu()
    {
        int input;

        cout<<"\n\n\t\t-----------Login AS-----------\n\n";

        cout<<"\t\t1. Service Administrator\n";
        cout<<"\t\t2. Doctor\n";
        cout<<"\t\t3. Patient\n";
        cout<<"\t\tPress 0 to Return\n";

        cout<<"\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            SA_Login();
            SA_subMenu();
        }
        else if(input==2)
        {
            LoginDetails("Doctor's");
        }
        else if(input==3)
        {
            LoginDetails("Patient's");
        }
        else if(input==0)
        {
            mainMenu();
        }
    }

    void signUpMenu()
    {
        int input;

        cout<<"\t\t-----------Sign Up AS-----------\n";

        cout<<"\t\t1. Patient\n";
        cout<<"\t\tTo Return Press 0\n";

        cout<<"\n\n\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            signUpDetails();
        }
    }

    void LoginDetails(string role)
    {
        string hospitalID, password;
        int input;

        cout<<"\t\t-----------"<<role<<" Login Page-----------\n";

        cout<<"\n\t\t Hospital ID: ";
        cin>>hospitalID;

        cout<<"\n\t\t Password: ";
        cin>>password;
    }

    void signUpDetails()
    {
        string fName, lName, address, password;
        int tellNumber;
        char gender;

        cout<<"\n\n\t\t-----------Patient Sign Up Page-----------\n";

        cout<<"\n\t\tEnter First Name: ";
        cin>>fName;

        cout<<"\n\t\tEnter Last Name: ";
        cin>>lName;

        cout<<"\n\t\tEnter Current Address: ";
        cin>>address;

        cout<<"\n\t\tEnter Telephone Number: ";
        cin>>tellNumber;

        cout<<"\n\t\tEnter Gender(M/F): ";
        cin>>gender;

        cout<<"\n\t\tEnter a Password: ";
        cin>>password;
    }

    void SA_Login()
    {
        string userName, password;

        cout<<"\n\t\tEnter UserName: ";
        cin>>userName;

        cout<<"\n\t\tEnter Password: ";
        cin>>password;
    }

    void SA_subMenu()
    {
        int input;

        cout<<"\n\n\t\t-----------Service Administrator-----------\n\n";
        cout<<"\t\tPress\n";

        cout<<"\n\t\t1. To Manage the DataBase";
        cout<<"\n\t\t2. To Manage the Pricing";
        cout<<"\n\t\t3. To Reset\n";

        cout<<"\n\n\t\tInput : ";
        cin>>input;

        if(input==1)
        {
            manageDatabase();
        }
        else if(input==2)
        {
            managePricing();
        }
        else if(input==3)
        {
            reset();
        }

        if(input==0)
        {
            mainMenu();
        }
    }

    void manageDatabase()
    {
        int input;

        cout<<"\n\n\t\t-----------Manage Database-----------\n\n";
        cout<<"\t\tPress\n";

        cout<<"\n\t\t1. To print Doctor's Information";
        cout<<"\n\t\t2. To print Patient's Information";
        cout<<"\n\t\t3. To Write a Query";
        cout<<"\n\t\tPress 0 To Return";

        cout<<"\n\n\t\tInput: ";
        cin>>input;

        if(input==0)
        {
            SA_subMenu();
        }
    }

    void managePricing()
    {
        int input;
        cout<<"\n\n\t\t-----------Manage Pricing-----------\n";
        cout<<"\n\t\tEnter\n";
        cout<<"\n\t\t1. To Update cost per day: ";
        cout<<"\n\t\tTo Return Press 0\n";

        cout<<"\n\n\t\tInput: ";
        cin>>input;

        if(input==0)
        {
            SA_subMenu();
        }
    }

    void reset()
    {
         int input;

         cout<<"\n\n\t\t-----------To Reset Information-----------\n";
         cout<<"\n\tPress\n";

         cout<<"\n\t\t1. To Reset Whole Information";
         cout<<"\n\t\t2. To Reset Specific Role\n";

         cout<<"\n\t\t To Return Press 0";
         cout<<"\n\t\t Input: ";
         cin>>input;

         if(input==0)
         {
             SA_subMenu();
         }
    }

};

int main()
{
    MenuInterface interface;
    interface.mainMenu();
    return 0;
}



