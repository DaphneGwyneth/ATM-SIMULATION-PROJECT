/*
   BSCS - 2CD
   ATM SIMULATION PROJECT

   CAMODOC, DAPHNE GWYNETH A.
   AMILANO, MARK LYNDON
                              */


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;


class bank
{
    private:
        char PIN[7];
        float balance;
        string AccNumber,AccName,AccBirthday,AccContactNumber,pin;

    public:
        void gotoxy(int x,int y);
        void MainMenu();
        void bank_management();
        void atm_management();
        void NewAcc();
        void ExistingAcc();
        void Deposit();
        void Withdraw();
        void FundTransfer();
        void ChangePin();
        void insertcard();
        void removecard();
        void pincode();
        void user_balance();
        void withdraw_atm();
        void AccDetail();

};






void bank::MainMenu()
{
    p:
        system("cls");
        int choice;
        char ch;
        string pin,email;
        gotoxy(40,5);cout<<"********** Control Panel **********";
        gotoxy(40,6);cout<<"*                                 *";
        gotoxy(40,7);cout<<"*       1. Bank Management        *";
        gotoxy(40,8);cout<<"*       2. ATM Management         *";
        gotoxy(40,9);cout<<"*       3. Exit                   *";
        gotoxy(40,10);cout<<"*                                 *";
        gotoxy(40,11);cout<<"***********************************";
        gotoxy(40,12);cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                bank_management();
                break;
            case 2:
                atm_management();
                break;
            case 3:
                removecard();
                exit(0);
            default:
                gotoxy(40,5);cout<<" Invalid value... Please Try Again";
            }
            getch();
            goto p;
}









void bank::bank_management()
{
    p:
    system("cls");
    int choice;
    gotoxy(40,5);cout<<"********** Bank Management System **********";
    gotoxy(40,6);cout<<"*                                          *";
    gotoxy(40,7);cout<<"*           1. Add New Account             *";
    gotoxy(40,8);cout<<"*           2. Existing Account            *";
    gotoxy(40,9);cout<<"*           3. Deposit                     *";
    gotoxy(40,10);cout<<"*           4. Withdraw                    *";
    gotoxy(40,11);cout<<"*           5. Fund Transfer               *";
    gotoxy(40,12);cout<<"*           6. Change PIN code             *";
    gotoxy(40,13);cout<<"*           7. Go back                     *";
    gotoxy(40,14);cout<<"*                                          *";
    gotoxy(40,15);cout<<"********************************************";
    gotoxy(40,16);cout<<"Enter Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
               NewAcc();
               break;
        case 2:
               ExistingAcc();
               break;
        case 3:
               Deposit();
               break;
        case 4:
               Withdraw();
               break;
        case 5:
               FundTransfer();
               break;
        case 6:
               ChangePin();
               break;
        case 7:
               MainMenu();
        default:
            cout<<" Invalid value... Please Try Again";

    }
    getch();
    goto p;
}









void bank::atm_management()
{
    p:
    system("cls");
    int choice;
    gotoxy(40,5);cout<<"********** ATM Management System ***********";
    gotoxy(40,6);cout<<"*                                          *";
    gotoxy(40,7);cout<<"*           1. Check Balance               *";
    gotoxy(40,8);cout<<"*           2. Account Details             *";
    gotoxy(40,9);cout<<"*           3. Go Back                     *";
    gotoxy(40,10);cout<<"*                                          *";
    gotoxy(40,11);cout<<"********************************************";
    gotoxy(40,12);cout<<" Enter Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
               user_balance();
               break;
        case 2:
               AccDetail();
               break;
        case 3:
               MainMenu();
        default:
            gotoxy(40,15);cout<<"\n\n Invalid value... Please Try Again";

    }
    getch();
    goto p;
}










void bank::NewAcc()
{
    p:
    system("cls");
    fstream file;
    int p;
    float b;
    string aNum,aName,aBday,aCN;
    gotoxy(40,3);cout<<" Add New Account";
    gotoxy(35,5);cout<<" Account Number: ";
    cin>>AccNumber;
    gotoxy(35,7);cout<<" Name: ";
    cin>>AccName;
    gotoxy(35,9);cout<<" Account Birthday: ";
    cin>>AccBirthday;
    gotoxy(35,11);cout<<" Account Contact Number: ";
    cin>>AccContactNumber;

    gotoxy(35,13);cout<<" Pin Code (6 digit): ";
    cin>>pin;

    gotoxy(35,15);cout<<" Current Balance: ";
    cin>>balance;

    file.open("bank.txt", ios::in);
    if(!file)
    {
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
        file.close();
    }
    else
    {
        file>>aNum>>aName>>aBday>>aCN>>p>>b;
        while(!file.eof())
        {
            if(aNum == AccNumber)
            {
                gotoxy(40,5);cout<<" Account Number Already Exist...";
                getch();
                goto p;
            }
            file>>aNum>>aName>>aBday>>aCN>>p>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
        file.close();
    }
    gotoxy(35,20);cout<<"New User Account Created Successfully... ";
}









void bank::ExistingAcc()
{
    system("cls");
    fstream file;
    string t_AccNumber;
    int found=0;
    gotoxy(40,3);cout<<" Existing Account";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error";
    }
    else
    {
        gotoxy(35,5);cout<<" Account Number: ";
        cin>>t_AccNumber;
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(t_AccNumber == AccNumber)
            {
                system("cls");
                gotoxy(35,5);cout<<" Account Number Already Exist...";
                gotoxy(35,7);cout<<" Account Number: "<<AccNumber<<"   Account Name: "<<AccName;
                found++;
            }
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        }
        file.close();
        if(found == 0)
        cout<<"\n\n\t\t Account Number Can't Find...";
    }


}









void bank::Deposit()
{
    fstream file,file1;
    string t_AccNumber;
    float dep;
    int found=0;
    system("cls");
    gotoxy(40,3);cout<<" Deposit Amount Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error...";
    }
    else
    {
        gotoxy(35,5);cout<<" Account Number: ";
        cin>>t_AccNumber;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(t_AccNumber == AccNumber)
            {
                gotoxy(35,7);cout<<" Amount For Deposit: ";
                cin>>dep;
                balance += dep;
                file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
                found++;
                gotoxy(35,9);cout<<"Your Amount "<<dep<<" Sucessfully Deposit!";
            }
            else
            {
                 file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
            }
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0)
        cout<<"\n\n\t\t Account Number Can't Find...";
    }

}







void bank::Withdraw()
{
    fstream file,file1;
    string t_AccNumber,t_pin;
    float with;
    char ch;
    int found=0;
    system("cls");
    gotoxy(40,3);cout<<" Withdraw Amount Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error...";
    }
    else
    {
        gotoxy(35,5);cout<<" Account Number: ";
        cin>>t_AccNumber;
        gotoxy(35,7);cout<<" Enter Pin Code (6 digit): ";
        for(int i=1; i<=6; i++)
        {
            ch = getch();
            t_pin += ch;
            cout<<"*";
        }
        file1.open("bank1.txt",ios::app|ios::out);
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(t_AccNumber == AccNumber && t_pin == pin)
            {
                gotoxy(35,9);cout<<" Amount For Withdraw: ";
                cin>>with;
                if(with <= balance)
                {
                balance -=with;
                file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
                found++;
                gotoxy(35,15);cout<<" Your Amount "<<with<<" Sucessfully Withdraw!";
                gotoxy(35,16);cout<<" Your Current Balance is "<<balance;
                }
                else
                {
                    file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
                    gotoxy(35,19);cout<<" Your Current Balance"<<balance<<"is less...";
                }
                found++;
            }
            else
            {
                 file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
            }
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0)
        cout<<"\n\n\t\t Account Number Can't Find...";
    }

}







void bank::FundTransfer()
{
    fstream file,file1;
    system("cls");
    string s_AccNumber,r_AccNumber;
    int found=0;
    float amount;
    gotoxy(40,3);cout<<" Payment Transfer Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error...";
    }
    else
    {
        gotoxy(35,5);cout<<" Sender Account Number for Transaction: ";
        cin>>s_AccNumber;
        gotoxy(35,7);cout<<" Receiver Account Number for Transaction: ";
        cin>>r_AccNumber;
        gotoxy(35,9);cout<<" Enter Transaction Amount: ";
        cin>>amount;
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(s_AccNumber == AccNumber && amount >= balance)
            found++;
            else if(r_AccNumber == AccNumber)
            found++;

            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        }
        file.close();
        if(found == 2)
        {
            file.open("bank.txt",ios::in);
            file1.open("bank1.txt",ios::app|ios::out);
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
            while(!file.eof())
            {
                if(s_AccNumber == AccNumber)
                {
                    balance -= amount;
                    file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
                }
                else if(r_AccNumber == AccNumber)
                {
                    balance += amount;
                    file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
                }
                else
                {
                    file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";
                }

                file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            gotoxy(40,15);cout<<" Transaction Successfully!";
            gotoxy(35,16);cout<<" Sender "<<s_AccNumber<<" successfully sends an amount of "<<amount;
        }
        else
        {
            gotoxy(35,19);cout<<" Both Transaction Account Number's & Balance Invalid...";
        }
    }

}








void bank::ChangePin()
{
    system("cls");
    fstream file,file1;
    string t_AccNumber,t_pin,pi;
    char ch;
    int found=0;
    gotoxy(40,3);cout<<" Change Pin Code";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error...";
    }
    else
    {
        gotoxy(35,5);cout<<" Account Number: ";
        cin>>t_AccNumber;
        gotoxy(35,7);cout<<" Enter Pin Code (6 digit): ";
        for(int i=1; i<=6; i++)
        {
            ch = getch();
            t_pin += ch;
            cout<<"*";
        }
        file1.open("bank1.txt",ios::app|ios::out);
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(t_AccNumber == AccNumber && t_pin == pin)
            {
                gotoxy(35,9);cout<<" Change Pin Code To(6 digit): ";
                cin>>pi;
                file1<<" "<<AccNumber<<" "<<pi<<"\n";
                gotoxy(35,19);cout<<" Change Pin Code Successfully!";
                gotoxy(35,20);cout<<" Your New Pin Code is "<<pi;
                found++;
            }
            else
            {
                file1<<" "<<AccNumber<<" "<<AccName<<" "<<AccBirthday<<" "<<AccContactNumber<<" "<<pin<<" "<<balance<<"\n";

            }
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;

        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0)
        cout<<"\n\n\t\t Account Number Can't Found...";
    }


}









void bank::user_balance()
{
    system("cls");
    fstream file;
    int found=0;
    string t_AccNumber,t_pin;
    char ch;
    gotoxy(40,3);cout<<" Check Balance";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error...";
    }
    else
    {
        gotoxy(35,5);cout<<" Account Number: ";
        cin>>t_AccNumber;
        gotoxy(35,7);cout<<" Enter Pin Code (6 digit): ";
        for(int i=1; i<=6; i++)
        {
            ch = getch();
            t_pin += ch;
            cout<<"*";
        }
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(t_AccNumber == AccNumber && t_pin == pin)
            {
                gotoxy(35,9);cout<<" Your Current Balance is: "<<balance;
                found++;
            }
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        }
        file.close();
        if(found == 0)
        cout<<"\n\n\t\t Account Number and Pin Code Invalid...";

    }

}







void bank::AccDetail()
{
    fstream file;
    string t_AccNumber,t_pin;
    char ch;
    int found=0;
    system("cls");
    gotoxy(40,3);cout<<" Account Details Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        gotoxy(40,4);cout<<" File Opening Error...";
    }
    else
    {
        gotoxy(35,5);cout<<" Account Number: ";
        cin>>t_AccNumber;
        gotoxy(35,7);cout<<" Enter Pin Code (6 digit): ";
        for(int i=1; i<=6; i++)
        {
            ch = getch();
            t_pin += ch;
            cout<<"*";
        }
        file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        while(!file.eof())
        {
            if(t_AccNumber == AccNumber && t_pin == pin)
            {
                system("cls");
                gotoxy(40,5);cout<<" Account Details";
                gotoxy(35,7);cout<<" Account Number: "<<AccNumber;
                gotoxy(35,8);cout<<" Name: "<<AccName;
                gotoxy(35,9);cout<<" Birthday: "<<AccBirthday;
                gotoxy(35,10);cout<<" Contact Number: "<<AccContactNumber;
                gotoxy(35,11);cout<<" Pin Code: "<<pin;
                gotoxy(35,12);cout<<" Current Balance: "<<balance;
                found++;
            }
            file>>AccNumber>>AccName>>AccBirthday>>AccContactNumber>>pin>>balance;
        }
        file.close();
        if(found == 0)
        cout<<"\n\n\t\t Account Number Can't Find...";
    }
}








void bank::insertcard()
{
    system("COLOR 06");
    FILE *fp;
    do{
    system("cls");
    gotoxy(45,8);printf("Please insert card...");
    fp=fopen("d:\mypin.txt","r");
    }
    while(fp==NULL);
    fclose(fp);
    system("cls");
     static CONSOLE_FONT_INFOEX  fontex;
     fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     GetCurrentConsoleFontEx(hOut, 0, &fontex);
     fontex.FontWeight = 700;
     fontex.dwFontSize.X = 36;
     fontex.dwFontSize.Y = 36;
     SetCurrentConsoleFontEx(hOut, NULL, &fontex);
     gotoxy(35,8);printf("WELCOME TO");
     gotoxy(36,9);printf("OUR BANK\n\n\n\n\n\n\n\n\n\n\n\n\n");
     system("pause");
     system("cls");
    gotoxy(40,10);printf("Thank you. Please enter PIN : ");
    pincode();
}





void bank::pincode()
{
    int i;
    for (i = 0;i<6;i++)
    {
    PIN[i]=getch();
    putchar('*');
    }
    PIN[i]='\0';
}









void bank::removecard()
{
    system("COLOR 06");
    FILE *fp;
    do{ system("cls");
        gotoxy(45,8);printf("Please remove card...");
        fp=fopen("d:mypin.txt","r");
        }
    while(fp!=NULL);
    fclose(fp);
    system("cls");
    gotoxy(40,10);printf("Thank you for banking with us!\n\n\n\n");
    //pincode();
}







main()
{
    system("COLOR 06");
    char PIN[7];
    bank obj;
   obj.insertcard();
    obj.MainMenu();
    obj.removecard();

}





void bank::gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}








