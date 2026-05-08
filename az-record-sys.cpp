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
    string firstName;
    string lastName;
    string middleInitial;
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

void CustomerUpdateOption1(Customer customerInfo[], int &prevI, bool &found, string &search)
{
    int i;

    do
    {
        found = false;

        cout<<"Enter customer's Surname/First name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            found = true;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == customerInfo[i].lastName || search == customerInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Customer #"<<i+1
                    <<"\n"<<setw(46)<<right<<"Surname: "<<customerInfo[i].lastName
                    <<"\n"<<setw(49)<<right<<"First Name: "<<customerInfo[i].firstName
                    <<"\n"<<setw(53)<<right<<"Middle Initial: "<<customerInfo[i].middleInitial
                    <<"\n"<<setw(46)<<right<<"Address: "<<customerInfo[i].address
                    <<"\n"<<setw(46)<<right<<"Phone #: "<<customerInfo[i].phoneNumber
                    <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                cout<<"Enter updated surname: ";
                getline(cin, customerInfo[i].lastName);

                cout<<"Enter updated first name: ";
                getline(cin, customerInfo[i].firstName);

                cout<<"Enter updated middle initial: ";
                getline(cin, customerInfo[i].middleInitial);

                cout<<"Enter updated address: ";
                getline(cin, customerInfo[i].address);

                cout<<"Enter updated phone number: ";
                getline(cin, customerInfo[i].phoneNumber);
            }
        }

        if (found == true)
        {
            cout<<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(63)<<"Customer record updated!"<<endl;
        }
            else
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(67)<<"Customer record not found!"<<endl;
            }
        
    } while (found == false);
}

void CustomerUpdateOption2(Customer customerInfo[], int &prevI, bool &found, string &search)
{
    int i;

    do
    {
        found = false;

        cout<<"Enter customer's Surname/First name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            found = true;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == customerInfo[i].lastName || search == customerInfo[i].firstName)
            {   
            found = true;

            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(67)<<"Data you're about to update:\n"
                <<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(57)<<right<<"Customer #"<<i+1
                <<"\n"<<setw(57)<<right<<"Gallons Owned: "<<customerInfo[i].gallonsOwnedQty
                <<"\n"<<setw(62)<<right<<"Latest Transaction: "<<customerInfo[i].latestTransaction
                <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

            cout<<"Update gallon ownership: ";
            cin>>customerInfo[i].gallonsOwnedQty;
            cin.clear();
            cin.ignore();

            while (customerInfo[i].gallonsOwnedQty <= 0)
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(65)<<right<<"Invalid quantity! Try again.\n"
                    <<"---------------------------------------------------------------------------------------------------------"<<endl;
                
                cout<<"Update gallon ownership: ";
                cin>>customerInfo[i].gallonsOwnedQty;
                cin.clear();
                cin.ignore();
            }

                cout<<"Update customer's  latest transaction (m/dd): ";
                getline(cin, customerInfo[i].latestTransaction);
            }
        }

        if (found == true)
        {
            cout<<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(63)<<"Customer record updated!"<<endl;
        }
            else
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(67)<<"Customer record not found!"<<endl;
            }
        
    } while (found == false);
}

void CustomerUpdateOption3(Customer customerInfo[], int &prevI, int &paymentStatus, bool &found, string &search)
{
    int i;
    
    do
    {
        found = false;

        cout<<"Enter customer's Surname/First name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            found = true;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == customerInfo[i].lastName || search == customerInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Customer #"<<i+1;

                if (customerInfo[i].paymentStatus == PAID)
                {
                    cout<<"\n"<<setw(64)<<right<<"Payment Status: PAID"<<endl;
                }
                    else if (customerInfo[i].paymentStatus == UNPAID)
                    {
                        cout<<"\n"<<setw(64)<<right<<"Payment Status: UNPAID"<<endl;
                    }

                cout<<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                do
                {
                    cout<<"Update customer's payment status (1 - PAID | 2 - UNPAID): ";
                    cin>>paymentStatus;
                    cin.clear();
                    cin.ignore();

                    switch (paymentStatus)
                    {
                        case 1:
                            customerInfo[i].paymentStatus = PAID;
                            break;
                        case 2:
                            customerInfo[i].paymentStatus = UNPAID;
                            break;
                        default:
                            cout<<"---------------------------------------------------------------------------------------------------------\n"
                            <<setw(66)<<right<<"Try again. Choice not Found."
                            <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
                    }
                } while (paymentStatus != 1 && paymentStatus != 2);
                }
        }

        if (found == true)
        {
            cout<<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(63)<<"Customer record updated!"<<endl;
        }
            else
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(67)<<"Customer record not found!"<<endl;
            }
                                
    } while (found == false);
}

void CustomerManagement(Customer customerInfo[], int &prevI)
{
    Customer tempInfo[25];
    int choice, choice2, i, size, paymentStatus;
    string search;
    bool validation, found;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(62)<<right<<"| Customer Records |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(58)<<right<<"[1] Add Customers\n"
            <<setw(66)<<right<<"[2] Display Customer Data\n"
            <<setw(65)<<right<<"[3] Update Customer Data\n"
            <<setw(63)<<right<<"[4] Return to Main Menu"<<endl;
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
                        <<"\nEnter customer's surname: ";
                    getline(cin, tempInfo[i].lastName);

                    cout<<"Enter customer's first name: ";
                    getline(cin, tempInfo[i].firstName);

                    cout<<"Enter customer's middle initial: ";
                    getline(cin, tempInfo[i].middleInitial);

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

                    cout<<"Enter latest transaction date (m/dd): ";
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
                    
                    customerInfo[i + prevI].lastName = tempInfo[i].lastName;
                    customerInfo[i + prevI].firstName = tempInfo[i].firstName; 
                    customerInfo[i + prevI].middleInitial = tempInfo[i].middleInitial;
                    customerInfo[i + prevI].address = tempInfo[i].address;
                    customerInfo[i + prevI].phoneNumber = tempInfo[i].phoneNumber;
                    customerInfo[i + prevI].gallonsOwnedQty = tempInfo[i].gallonsOwnedQty;
                    customerInfo[i + prevI].latestTransaction = tempInfo[i].latestTransaction;
                    customerInfo[i + prevI].paymentStatus = tempInfo[i].paymentStatus;
                }
                prevI += i; 
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(71)<<right<<"Customer Record(s) Added Successfully!"<<endl;
                break;
            case 2:
                do
                {
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(61)<<"| Customer Data |\n"
                        <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(6)<<left<<"#"
                        <<setw(10)<<left<<"Surname"
                        <<setw(16)<<left<<"First Name"
                        <<setw(5)<<left<<"M.I"
                        <<setw(30)<<left<<"Address"
                        <<setw(13)<<left<<"Phone No."
                        <<setw(10)<<left<<"Gallons"
                        <<setw(9)<<left<<"Latest"
                        <<"Status"
                        <<"\n-----|--------|--------------------|-----------------------------|-------------|-------|--------|-------|"<<endl;
                    for (i = 0; i < prevI; i++)
                    {
                        cout<<setw(6)<<left<<i+1
                            <<setw(10)<<left<<customerInfo[i].lastName
                            <<setw(16)<<left<<customerInfo[i].firstName
                            <<setw(5)<<left<<customerInfo[i].middleInitial
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
                        <<"\n<< [1] Back\n"
                        <<setw(53)<<right<<"Input: ";
                    cin>>choice2;
                    cin.ignore();

                } while (choice2 != 1);
                break;
            case 3:
                do
                {
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(65)<<right<<"| Select Field to Update |"
                        <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(71)<<right<<"[1] Customer Name/Address/Phone #\n"
                        <<setw(79)<<right<<"[2] Gallon Ownership & Latest Transaction\n"
                        <<setw(56)<<right<<"[3] Payment Status\n"
                        <<setw(45)<<right<<"[4] Back"<<endl;
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(53)<<right<<"Input: ";
                    cin>>choice2;
                    cin.clear();
                    cin.ignore();
                    cout<<"---------------------------------------------------------------------------------------------------------\n";

                    switch (choice2)
                    {
                        case 1:
                            CustomerUpdateOption1(customerInfo, prevI, found, search);
                            break;
                        case 2:
                            CustomerUpdateOption2(customerInfo, prevI, found, search);
                            break;
                        case 3:
                            CustomerUpdateOption3(customerInfo, prevI, paymentStatus, found, search);
                            break;
                        case 4:
                            cout<<setw(57)<<right<<"Returning..."<<endl;
                            break;
                        default:
                            cout<<"---------------------------------------------------------------------------------------------------------\n"
                                <<setw(66)<<right<<"Try again. Choice not Found."<<endl;
                            break;  
                    }
                } while (choice2 != 4);
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
            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(58)<<"See you again!"
                <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;
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