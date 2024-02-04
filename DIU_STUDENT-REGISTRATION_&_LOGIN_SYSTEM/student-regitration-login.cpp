#include<bits/stdc++.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{

    int c;
    cout<<"\t\t\t                Dhaka International University (DIU)            \n\n";
    cout<<"\t\t\t                   Student Registration & Login                 \n\n";
    cout<<"\t\t\t________________________________Menu____________________________\n\n\n\n";
    cout<<"\t\t\t| Press 1 to LOGIN                                              |"<<endl;
    cout<<"\t\t\t| Press 2 to REGISTER                                           |"<<endl;
    cout<<"\t\t\t| Press 3 to Reset Password                                     |"<<endl;
    cout<<"\t\t\t| Press 4 to Exit                                               |"<<endl;
    cout<<"\n";
    cout<<"\t\t\t  Please Enter your choice: ";
    cin>>c;
    cout<<endl;

    switch (c)
    {

        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout<<"\t\t\t Thank you for using DIU SIMS! "<<endl;

        default:
        system("cls");
            cout<<"\t\t\t Please select from the given above\n"<<endl;
            main();

    }
}

void login()
{
    int count;
    string email,password,ID,pass;
    system("cls");
    cout<<"\t\t\t Please enter the Email and Password below "<<endl;
    cout<<"\t\t\t Email   : ";
    cin>>email;
    cout<<"\t\t\t Password: ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>ID>>pass)
    {
        if(ID==email && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count=1)
        {
            cout<<email<<" Your LOGIN is successful. Thanks for logging in!\n";
            main();
        }
    else
        {
            cout<<"\n LOGIN ERROR \n Please check your Email & Password";
            main();
        }
}

void registration()
{
    string regEmail, regPassword, regID, regPass;
    system("cls");
    cout<<"\t\t\t Enter the Email   : ";
    cin>>regEmail;
    cout<<"\t\t\t Enter the Password: ";
    cin>>regPass;

    ofstream f1("records.txt", ios::app);
    f1<<regEmail<<' '<<regPassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is Successfull! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password?\n";
    cout<<"Press 1 to search your ID by email"<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice: ";
    cin>>option;
    switch(option)
    {

    case 1:
        {
            int count = 0;
            string sEmail,sID,spass;
            cout<<"\n\t\t\t Enter the email which your remembered: ";
            cin>>sEmail;

            ifstream f2("records.txt");
            while(f2>>sID>>spass)
            {
                if(sID==sEmail)
                {
                    count = 1;
                }
            }
            f2.close();

            if(count==1)
            {
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your Password is: "<<spass;
                main();
            }
            else
                {
                    cout<<"\n\t Sorry! Your account is not found!\n";
                    main();
                }
                break;
        }

    case 2:
        {
            main();
        }
    default:
        cout<<"\t\t\t Wrong Choice! Please try again "<<endl;
        forgot();


    }

}



