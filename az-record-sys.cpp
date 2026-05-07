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
    int phoneNumber;
    int gallonsOwnedQty;
    int lastDayBought;
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
    int choice, i, size;

    do
    {
        cout<<"-----=====---===   Customer Records   ===---=====-----"
            <<"\n"<<setw(26)<<"[1] Add Customers"<<setw(26)<<"[2] Display Customer Data"
            <<"\n"<<setw(26)<<"[3] Update Customer Data"<<setw(40)<<"[4] Return to Main Menu"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----";
        cout<<"\nInput: ";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice)
        {
            case 1:
                cout<<"-----=====---===-=  Adding Records  =-===---=====-----"
                    <<"\nEnter amount of customers: ";
                cin>>size;
                cin.clear();
                cin.ignore();

                while (size <= 0) // simple input error handling
                {
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----"
                        <<"\n"<<setw(39)<<"Invalid amount! Try again."
                        <<"\nEnter amount of customers: ";
                    cin>>size;
                    cin.clear();
                    cin.ignore();
                }

                for (i = 0; i < size; i++)
                {
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----"
                        <<"\n"<<setw(34)<<"Customer Record #"<<i + prevI + 1
                        <<"\nEnter customer's full name: ";
                    getline(cin, tempInfo[i].fullName);

                    cout<<"Enter customer's address: ";
                    cin>>tempInfo[i].address;
                    
                    cout<<"Enter customer's phone number: ";
                    cin>>tempInfo[i].phoneNumber;
                    
                    cout<<"Enter how many gallons the customer owns: ";
                    cin>>tempInfo[i].gallonsOwnedQty;
                    cin.ignore();

                    customerInfo[i + prevI].fullName = tempInfo[i].fullName;
                    customerInfo[i + prevI].address = tempInfo[i].address;
                    customerInfo[i + prevI].phoneNumber = tempInfo[i].phoneNumber;
                    customerInfo[i + prevI].gallonsOwnedQty = tempInfo[i].gallonsOwnedQty;
                }
                prevI += i;

                break;
            case 2:
                do
                {
                    cout<<"-----=====---===   Customer Records   ===---=====-----"
                    <<"\n"<<setw(5)<<"#"<<setw(20)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Phone No."<<endl;
                    for (i = 0; i < prevI; i++)
                    {
                        cout<<i+1<<setw(5)
                            <<customerInfo[i].fullName<<setw(30)
                            <<customerInfo[i].address<<setw(30)
                            <<customerInfo[i].phoneNumber<<setw(30)
                            <<customerInfo[i].gallonsOwnedQty<<endl;
                    }
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----"
                        <<"\n[1] Back"
                        <<"\nInput: ";
                    cin>>choice;
                    cin.ignore();

                } while (choice != 1);
                break;
            case 3:
                
                break;
            case 4:
                break;
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
        }
    } while (choice != 4);
}

void ProductManagement()
{
    int choice;

    do
    {
        cout<<"-----=====---===   Product Management  ===---=====-----"
            <<"\n"<<setw(27)<<"[0] Empty for "<<"\n[1] Now"<<endl;
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
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
                break;
        }

    } while (choice != 6);
}

void EmployeeManagement()
{
    int choice;

    do
    {
        cout<<"-----=====---===   Employee Records   ===---=====-----"
            <<"\n"<<setw(30)<<"[1] Employees"
            <<"\n"<<setw(35)<<"[2] About Business"
            <<"\n"<<setw(40)<<"[3] Return to Main Menu"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----";
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
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
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
        cout<<"-----=====  AquaZeb Water Refilling Station  =====-----"
            <<"\n"<<setw(37)<<"[1] Product Management"
            <<"\n"<<setw(35)<<"[2] Customer Records"
            <<"\n"<<setw(35)<<"[3] Employee Records"
            <<"\n"<<setw(31)<<"[4] Exit Program"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----";
        cout<<"\nInput: ";
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
            cout<<"-----=====-----=====-----=====-----=====-----=====-----"
                <<"\n"<<setw(35)<<"See you again!"
                <<"\n-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                break;
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
        }

    } while (choice != 4);
}

int main()
{
    Customer customerInformation[50]; // declare all struct/variables/arrays here so all of the value/data persists even if functions end, only does it stop persisting after the program ends.
    Product productInformation[50];
    Employee employeeInfromation[50];

    int customerPrevI, productPrevI, employeePrevI;

    MainMenu(customerInformation, productInformation, employeeInfromation, customerPrevI, productPrevI, employeePrevI);

    return EXIT_SUCCESS;
}