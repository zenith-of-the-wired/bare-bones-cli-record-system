#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

enum POSITION{
    DRIVER,
    REFILLER
};

enum SEX{
    MALE,
    FEMALE
};

enum MONTHS{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

enum PAYMENT_STATUS{
    PAID,
    UNPAID
};

struct Customer{
    string fullName;
    string address;
    string phoneNumber;
    int gallonsOwnedQty;
    string latestTransaction;
    PAYMENT_STATUS paymentStatus;
};

struct Product{
    int tankStorage;
    int year;
    int day;
    int sales;
    int distributedGallonQty;
    int iceBagBatchQty;
    int bottledWaterBatchQty;
    string gallonType;
    string iceBagType;
    string bottledWaterType;
    MONTHS month;
};

struct Employee{
    string fullName;
    string address;
    int phoneNumber;
    POSITION position;
    SEX sex;
};

void MainMenu(Customer customerInfo[], Product productInfo[], Employee employeeInfo, int &custPrevI, int &prodPrevI, int &empPrevI); // so that other functions can also call MainMenu, because they are defined before it.

void CustomerManagement(Customer customerInfo[], int &prevI)
{
    Customer tempInfo[25];
    int choice, i, size, paymentStatus;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(62)<<right<<"| Customer Records |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(59)<<right<<"[1] Add Customers\n"
            <<setw(67)<<right<<"[2] Display Customer Data\n"
            <<setw(66)<<right<<"[3] Update Customer Data\n"
            <<setw(64)<<right<<"[4] Return to Main Menu"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(53)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice)
        {
            case 1:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(60)<<right<<"| Adding Records |"
                    <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
                    <<"\nEnter amount of customers: ";
                cin>>size;
                cin.clear();
                cin.ignore();

                    while (size <= 0) // simple input error handling, used thoughout parts of the code.
                    {
                        cout<<"---------------------------------------------------------------------------------------------------------\n"
                            <<setw(64)<<right<<"Invalid amount! Try again."
                            <<"\nEnter amount of customers: ";
                        cin>>size;
                        cin.clear();
                        cin.ignore();
                    }

                for (i = 0; i < size; i++)
                {
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(59)<<right<<"Customer Record #"<<i + prevI + 1
                        <<"\nEnter customer's full name: ";
                    getline(cin, tempInfo[i].fullName);

                    cout<<"Enter customer's address (brngy & purok): ";
                    getline(cin, tempInfo[i].address);
                    
                    cout<<"Enter customer's phone number (example: 09123456789): ";
                    getline(cin, tempInfo[i].phoneNumber);

                    cout<<"Enter customer gallon ownership (quantity): ";
                    cin>>tempInfo[i].gallonsOwnedQty;
                    cin.clear();
                    cin.ignore();

                        while (tempInfo[i].gallonsOwnedQty <= 0)
                        {
                            cout<<"---------------------------------------------------------------------------------------------------------\n"
                                <<setw(65)<<right<<"Invalid quantity! Try again."
                                <<"\n---------------------------------------------------------------------------------------------------------"
                                <<"\nEnter how many gallons the customer owns: ";
                            cin>>tempInfo[i].gallonsOwnedQty;
                            cin.clear();
                            cin.ignore();
                        }

                    cout<<"Enter latest transaction date (month/day | 8/16): ";
                    getline(cin, tempInfo[i].latestTransaction);

                    do
                    {
                        cout<<"Enter payment status of gallons owned (1 - Paid | 2 - Unpaid): ";
                        cin>>paymentStatus;
                        cin.clear();
                        cin.ignore();
                        
                        switch (paymentStatus)
                        {
                            case 1:
                                tempInfo[i].paymentStatus = PAID;
                                break;
                            case 2:
                                tempInfo[i].paymentStatus = UNPAID;
                                break;
                            default:
                                cout<<"---------------------------------------------------------------------------------------------------------\n"
                                <<setw(66)<<right<<"Try again. Choice not Found."
                                <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
                        }
                    } while (paymentStatus != 1 && paymentStatus != 2);
                    

                    // a self maintaining algorithm that prevents old array values (data of users) from getting overwritten
                    customerInfo[i + prevI].fullName = tempInfo[i].fullName; 
                    customerInfo[i + prevI].address = tempInfo[i].address;
                    customerInfo[i + prevI].phoneNumber = tempInfo[i].phoneNumber;
                    customerInfo[i + prevI].gallonsOwnedQty = tempInfo[i].gallonsOwnedQty;
                    customerInfo[i + prevI].latestTransaction = tempInfo[i].latestTransaction;
                    customerInfo[i + prevI].paymentStatus = tempInfo[i].paymentStatus;
                }
                prevI += i; 

                break;
            case 2:
                do
                {
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(61)<<"| Customer Data |\n"
                        <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(6)<<left<<"#"
                        <<setw(30)<<left<<"Full Name"
                        <<setw(30)<<left<<"Address"
                        <<setw(13)<<left<<"Phone No."
                        <<setw(10)<<left<<"Gallons"
                        <<setw(9)<<left<<"Latest"
                        <<"Status"
                        <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
                    for (i = 0; i < prevI; i++)
                    {
                        cout<<setw(6)<<left<<i+1
                            <<setw(30)<<left<<customerInfo[i].fullName
                            <<setw(30)<<left<<customerInfo[i].address
                            <<setw(13)<<left<<customerInfo[i].phoneNumber
                            <<setw(10)<<left<<customerInfo[i].gallonsOwnedQty
                            <<setw(9)<<left<<customerInfo[i].latestTransaction;

                        if (customerInfo[i].paymentStatus == PAID)
                        {
                            cout<<"PAID"<<endl;
                        }
                            else if (customerInfo[i].paymentStatus == UNPAID)
                            {
                                cout<<"UNPAID"<<endl;
                            }
                    }
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
                        <<"\n[1] Back\n"
                        <<setw(53)<<right<<"Input: ";
                    cin>>choice;
                    cin.ignore();

                } while (choice != 1);
                break;
            case 3:
                
                break;
            case 4:
                break;
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<right<<"Try again! Choice not found."<<endl;
        }
    } while (choice != 4);
}

void ProductManagement()
{
    int choice;

    do
    {
        cout<<"-----=====---===   Product Management  ===---=====-----\n"
            <<setw(27)<<"[0] Empty for "<<"\n[1] Now"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----";
        cout<<"\nInput: ";
        cin>>choice;
        cin.ignore();

        switch(choice)
        {
            case 1:

                break;
            case 2:

            default:
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(41)<<"Try again! Choice not found."<<endl;
                break;
        }

    } while (choice != 6);
}

void EmployeeManagement()
{
    int choice;

    do
    {
        cout<<"-----=====-----=====-----=====---===   Employee Records   ===---=====-----=====-----=====-----"
            <<"\n"<<setw(30)<<"[1] Employees"
            <<"\n"<<setw(35)<<"[2] Update Employee Data"
            <<"\n"<<setw(40)<<"[3] Return to Main Menu"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----";
        cout<<"\nInput: ";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:
                
                break;
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
                break;
        }

    } while (choice != 3);
}

void MainMenu(Customer customerInfo[], Product productInfo[], Employee employeeInfo[], int &custPrevI, int &prodPrevI, int &empPrevI)
{
    int choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(71)<<right<<"| AquaZeb Water Refilling Station |\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(64)<<right<<"[1] Product Management\n"
            <<setw(62)<<right<<"[2] Customer Records\n"
            <<setw(62)<<right<<"[3] Employee Records\n"
            <<setw(57)<<right<<"[4] Exit Program"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(53)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice)
        {
            case 1:
                ProductManagement();
                break;
            case 2:
                CustomerManagement(customerInfo, custPrevI);
                break;
            case 3:
                EmployeeManagement();
                break;
            case 4:
            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(35)<<"See you again!"
                <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                break;
            default:
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(66)<<right<<"Try again. Choice not Found."<<endl;
        }

    } while (choice != 4);
}

int main()
{
    Customer customerInformation[50]; // declare all needed struct/variables/arrays here so all of the value/data persists even if functions end,
    Product productInformation[50]; // only does it stop persisting after the program ends.
    Employee employeeInfromation[50];

    int customerPrevI, productPrevI, employeePrevI;

    MainMenu(customerInformation, productInformation, employeeInfromation, customerPrevI, productPrevI, employeePrevI);

    return EXIT_SUCCESS;
}