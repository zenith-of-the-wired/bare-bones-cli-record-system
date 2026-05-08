#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

enum ROLE{
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
    int customerRecordNum;
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
    int employeeRecordNum;
    string firstName;
    string lastName;
    string middleInitial;
    string address;
    string phoneNumber;
    ROLE position;
    SEX sex;
};

void RetryAmount()
{
    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(64)<<right<<"Invalid amount! Try again.\n"
        <<"---------------------------------------------------------------------------------------------------------";
}

void RetryStyle()
{
    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(66)<<right<<"Try again. Choice not Found.\n"
        <<"---------------------------------------------------------------------------------------------------------"<<endl;
}

void UpdateConfirmed()
{
    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(63)<<"Customer record updated!\n"
        <<"---------------------------------------------------------------------------------------------------------"<<endl;
}

void RecordSearchFailed()
{
    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(67)<<"Customer record not found!\n"
        <<"---------------------------------------------------------------------------------------------------------"<<endl;
}

void CustomerOriginalCopy(Customer customerInfo[], Customer tempInfo[], int &prevI)
{
    int i;

    for (i = 0; i < prevI; i++)
    {
        tempInfo[i] = customerInfo[i];
    }
}

void AddCustomerInfo(Customer customerInfo[], Customer tempInfo[], int &prevI, int &size, int &paymentStatus)
{
    int i;

    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(60)<<right<<"| Adding Records |"
                    <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
                    <<"\nEnter amount of customers: ";
                cin>>size;
                cin.clear();
                cin.ignore();

                    while (size <= 0)
                    {
                        RetryAmount();
                        cout<<"\nEnter amount of customers: ";
                        cin>>size;
                        cin.clear();
                        cin.ignore();
                    }

                for (i = 0; i < size; i++)
                {
                    customerInfo[i].customerRecordNum =  i + prevI + 1;

                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(59)<<right<<"Customer Record #"<<customerInfo[i].customerRecordNum
                        <<"\nEnter customer's surname: ";
                    getline(cin, customerInfo[i + prevI].lastName);

                    cout<<"Enter customer's first name: ";
                    getline(cin, customerInfo[i + prevI].firstName);

                    cout<<"Enter customer's middle initial: ";
                    getline(cin, customerInfo[i + prevI].middleInitial);

                    cout<<"Enter customer's address (barangy & purok): ";
                    getline(cin, customerInfo[i + prevI].address);
                    
                    cout<<"Enter employee's phone number (format: 09---------): ";
                    getline(cin, customerInfo[i + prevI].phoneNumber);

                    cout<<"Enter customer gallon ownership (quantity): ";
                    cin>>customerInfo[i + prevI].gallonsOwnedQty;
                    cin.clear();
                    cin.ignore();

                        while (customerInfo[i + prevI].gallonsOwnedQty <= 0)
                        {
                            cout<<"---------------------------------------------------------------------------------------------------------\n"
                                <<setw(65)<<right<<"Invalid quantity! Try again."
                                <<"\n---------------------------------------------------------------------------------------------------------"
                                <<"\nEnter how many gallons the customer owns: ";
                            cin>>customerInfo[i + prevI].gallonsOwnedQty;
                            cin.clear();
                            cin.ignore();
                        }

                    cout<<"Enter latest transaction date (m/dd): ";
                    getline(cin, customerInfo[i + prevI].latestTransaction);

                    do
                    {
                        cout<<"Enter payment status of gallons owned (1 - Paid | 2 - Unpaid): ";
                        cin>>paymentStatus;
                        cin.clear();
                        cin.ignore();
                        
                        switch (paymentStatus)
                        {
                            case 1:
                                customerInfo[i + prevI].paymentStatus = PAID;
                                break;
                            case 2:
                                customerInfo[i + prevI].paymentStatus = UNPAID;
                                break;
                            default:
                                RetryStyle();
                                break;
                        }
                    } while (paymentStatus != 1 && paymentStatus != 2);

                    CustomerOriginalCopy(customerInfo, tempInfo, prevI);
                }
                prevI += i;

                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(71)<<right<<"Customer Record(s) Added Successfully!"<<endl;
}

void SortCustDesLastName(Customer customerInfo[], Customer tempInfo[], int &prevI)
{
    int x, y;
    Customer temp;

    CustomerOriginalCopy(customerInfo, tempInfo, prevI);

    for (x = 0; x < prevI - 1; x++)
    {
        for (y = 0; y < prevI - 1 - x; y++)
        {
            if(customerInfo[y].lastName < customerInfo[y + 1].lastName)
            {
                temp = customerInfo[y];
                customerInfo[y] = customerInfo[y + 1];
                customerInfo[y + 1] = temp;
            }
        }
    } 
}

void SortCustAscLastName(Customer customerInfo[], Customer tempInfo[], int &prevI)
{
    int x, y;
    Customer temp;

    CustomerOriginalCopy(customerInfo, tempInfo, prevI);

    for (x = 0; x < prevI - 1; x++)
    {
        for (y = 0; y < prevI - 1 - x; y++)
        {
            if(customerInfo[y].lastName > customerInfo[y + 1].lastName)
            {
                temp = customerInfo[y];
                customerInfo[y] = customerInfo[y + 1];
                customerInfo[y + 1] = temp;
            }
        }
    }
}

void DisplayCusomterInfo(Customer customerInfo[], Customer tempInfo[], int &prevI)
{
    int i, choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(61)<<"| Customer Data |\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(6)<<left<<"#"<<setw(10)<<left<<"Surname"<<setw(16)<<left<<"First Name"<<setw(5)<<left<<"M.I"<<setw(30)<<left<<"Address"<<setw(13)<<left<<"Phone No."<<setw(9)<<left<<"Gallons"<<setw(8)<<left<<"Latest"<<"Status"
            <<"\n-----|--------|--------------------|-----------------------------|-------------|-------|--------|-------|"<<endl;

        for (i = 0; i < prevI; i++)
        {
            cout<<setw(6)<<left<<customerInfo[i].customerRecordNum
                <<setw(10)<<left<<customerInfo[i].lastName
                <<setw(16)<<left<<customerInfo[i].firstName
                <<setw(5)<<left<<customerInfo[i].middleInitial
                <<setw(30)<<left<<customerInfo[i].address
                <<setw(13)<<left<<customerInfo[i].phoneNumber
                <<setw(9)<<left<<customerInfo[i].gallonsOwnedQty
                <<setw(8)<<left<<customerInfo[i].latestTransaction;

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
            <<"\n"<<setw(29)<<right<<"[1] Back"<<setw(32)<<right<<"[2] Sort By Last Name (A-Z)"<<setw(32)<<right<<"[3] Sort By Last Name (Z-A)"
            <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(53)<<right<<"Input: ";
        cin>>choice;
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
        case 1:
            cout<<setw(57)<<right<<"Returning..."<<endl;
            break;
        case 2:
            SortCustAscLastName(customerInfo, tempInfo, prevI);
            break;
        case 3:
            SortCustDesLastName(customerInfo, tempInfo, prevI);
            break;
        default:
            RetryStyle();
            break;
        }
    } while (choice != 1);
}

void CustomerUpdateOption1(Customer customerInfo[], int &prevI)
{
    int i;
    bool found; 
    string search;

    do
    {
        found = false;

        cout<<"Enter customer's Surname/First name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            break;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == customerInfo[i].lastName || search == customerInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Customer #"<<customerInfo[i].customerRecordNum
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
            UpdateConfirmed();
        }
            else
            {
                RecordSearchFailed();
            }
    } while (found == false);
}

void CustomerUpdateOption2(Customer customerInfo[], int &prevI)
{
    int i;
    bool found; 
    string search;

    do
    {
        found = false;

        cout<<"Enter customer's Surname/First name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            break;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == customerInfo[i].lastName || search == customerInfo[i].firstName)
            {   
            found = true;

            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(67)<<"Data you're about to update:\n"
                <<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(57)<<right<<"Customer #"<<customerInfo[i].customerRecordNum
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
            UpdateConfirmed();
        }
            else
            {
                RecordSearchFailed();
            }
    } while (found == false);
}

void CustomerUpdateOption3(Customer customerInfo[], int &prevI, int &paymentStatus)
{
    int i;
    bool found; 
    string search;
    
    do
    {
        found = false;

        cout<<"Enter customer's Surname/First name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            break;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == customerInfo[i].lastName || search == customerInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Customer #"<<customerInfo[i].customerRecordNum;

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
                            RetryStyle();
                            break;
                    }
                } while (paymentStatus != 1 && paymentStatus != 2);
            }
        }

        if (found == true)
        {
            UpdateConfirmed();
        }
            else
            {
                RecordSearchFailed();
            }             
    } while (found == false);
}

void CustomerUpdateParent(Customer customerInfo[], int &prevI, int &paymentStatus)
{
    int choice;

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
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                CustomerUpdateOption1(customerInfo, prevI);
                break;
            case 2:
                CustomerUpdateOption2(customerInfo, prevI);
                break;
            case 3:
                CustomerUpdateOption3(customerInfo, prevI, paymentStatus);
                break;
            case 4:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            default:
                RetryStyle();
                break;  
        }
    } while (choice != 4);
}

void CustomerManagement(Customer customerInfo[], Customer tempInfo[], int &prevI)
{
    int choice, choice2, i, size, paymentStatus;

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
                AddCustomerInfo(customerInfo, tempInfo, prevI, size, paymentStatus);
                break;
            case 2:
                DisplayCusomterInfo(customerInfo, tempInfo, prevI);
                break;
            case 3:
                CustomerUpdateParent(customerInfo, prevI, paymentStatus);
                break;
            case 4:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            default:
                RetryStyle();
                break;
        }
    } while (choice != 4);
}

void ProductManagement()
{

}

void AddEmployeeInfo(Employee employeeInfo[], int &prevI, int &size, int &sex, int &role)
{
    int i, choice;

    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(60)<<right<<"| Adding Records |"
                    <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
                    <<"\nEnter amount of employees: ";
                cin>>size;
                cin.clear();
                cin.ignore();

                    while (size <= 0)
                    {
                        RetryAmount();
                        cout<<"\nEnter amount of employees: ";
                        cin>>size;
                        cin.clear();
                        cin.ignore();
                    }

                for (i = 0; i < size; i++)
                {
                    employeeInfo[i].employeeRecordNum =  i + prevI + 1;
                    
                    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                        <<setw(59)<<right<<"Employee Record #"<<i + prevI + 1
                        <<"\nEnter employee's surname: ";
                    getline(cin, employeeInfo[i + prevI].lastName);

                    cout<<"Enter emloyee's first name: ";
                    getline(cin, employeeInfo[i + prevI].firstName);

                    cout<<"Enter employee's middle initial: ";
                    getline(cin, employeeInfo[i + prevI].middleInitial);

                    cout<<"Enter employee's address (barangy & purok): ";
                    getline(cin, employeeInfo[i + prevI].address);
                    
                    cout<<"Enter employee's phone number (format: 09---------): ";
                    getline(cin, employeeInfo[i + prevI].phoneNumber);

                    do
                    {
                        cout<<"Enter sex of employee (1 - MALE | 2 - FEMALE): ";
                        cin>>sex;
                        cin.clear();
                        cin.ignore();
                        
                        switch (sex)
                        {
                            case 1:
                                employeeInfo[i + prevI].sex = MALE;
                                break;
                            case 2:
                                employeeInfo[i + prevI].sex = FEMALE;
                                break;
                            default:
                                RetryStyle();
                                break;
                        }
                    } while (sex != 1 && sex != 2);

                    do
                    {
                        cout<<"Enter role of employee (1 - DRIVER | 2 - REFILLER): ";
                        cin>>role;
                        cin.clear();
                        cin.ignore();
                        
                        switch (role)
                        {
                            case 1:
                                employeeInfo[i + prevI].position = DRIVER;
                                break;
                            case 2:
                                employeeInfo[i + prevI].position = REFILLER;
                                break;
                            default:
                                RetryStyle();
                                break;
                        }
                    } while (role != 1 && role != 2);
                }

                prevI += i; 

                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(71)<<right<<"Employee Record(s) Added Successfully!"<<endl;
}

void DisplayEmployeeInfo(Employee employeeInfo[], int &prevI)
{
    int i, choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(61)<<"| Employee Data |\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(6)<<left<<"#"
            <<setw(10)<<left<<"Surname"
            <<setw(16)<<left<<"First Name"
            <<setw(5)<<left<<"M.I"
            <<setw(30)<<left<<"Address"
            <<setw(13)<<left<<"Phone No."
            <<setw(13)<<left<<"Sex"
            <<"Role"
            <<"\n-----|--------|--------------------|-----------------------------|-------------|-------|----------------|"<<endl;

        for (i = 0; i < prevI; i++)
        {
            cout<<setw(6)<<left<<i+1
                <<setw(10)<<left<<employeeInfo[i].lastName
                <<setw(16)<<left<<employeeInfo[i].firstName
                <<setw(5)<<left<<employeeInfo[i].middleInitial
                <<setw(30)<<left<<employeeInfo[i].address
                <<setw(13)<<left<<employeeInfo[i].phoneNumber;

        if (employeeInfo[i].sex == MALE)
        {
            cout<<setw(13)<<left<<"MALE";
        }
            else if (employeeInfo[i].sex == FEMALE)
            {
                cout<<setw(13)<<left<<"FEMALE";
            }

        if (employeeInfo[i].position == DRIVER)
        {
            cout<<"DRIVER"<<endl;
        }
            else if (employeeInfo[i].position == REFILLER)
            {
                cout<<"REFILLER"<<endl;
            }
        }

        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
            <<"\n"<<setw(29)<<right<<"[1] Back"<<setw(32)<<right<<"[2] Sort By Last Name (A-Z)"<<setw(32)<<right<<"[3] Sort By Last Name (Z-A)"
            <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(53)<<right<<"Input: ";
        cin>>choice;
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
        case 1:
            cout<<setw(57)<<right<<"Returning..."<<endl;
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            RetryStyle();
            break;
        }
    } while (choice != 1);
}

void EmployeeUpdateOption1(Employee employeeInfo[], int &prevI)
{
    int i;
    bool found;
    string search;

    do
    {
        found = false;

        cout<<"Enter employee's surname/first name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            break;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == employeeInfo[i].lastName || search == employeeInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Customer #"<<employeeInfo[i].employeeRecordNum
                    <<"\n"<<setw(46)<<right<<"Surname: "<<employeeInfo[i].lastName
                    <<"\n"<<setw(49)<<right<<"First Name: "<<employeeInfo[i].firstName
                    <<"\n"<<setw(53)<<right<<"Middle Initial: "<<employeeInfo[i].middleInitial
                    <<"\n"<<setw(46)<<right<<"Address: "<<employeeInfo[i].address
                    <<"\n"<<setw(46)<<right<<"Phone #: "<<employeeInfo[i].phoneNumber
                    <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                cout<<"Enter updated surname: ";
                getline(cin, employeeInfo[i].lastName);

                cout<<"Enter updated first name: ";
                getline(cin, employeeInfo[i].firstName);

                cout<<"Enter updated middle initial: ";
                getline(cin, employeeInfo[i].middleInitial);

                cout<<"Enter updated address: ";
                getline(cin, employeeInfo[i].address);

                cout<<"Enter updated phone number: ";
                getline(cin, employeeInfo[i].phoneNumber);
            }
        }

        if (found == true)
        {
            UpdateConfirmed();
        }
            else
            {
                RecordSearchFailed();
            }
    } while (found == false);
}

void EmployeeUpdateOption2(Employee employeeInfo[], int &prevI, int &sex)
{
    int i;
    bool found; 
    string search;
    
    do
    {
        found = false;

        cout<<"Enter customer's surname/first name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            break;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == employeeInfo[i].lastName || search == employeeInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Employee #"<<employeeInfo[i].employeeRecordNum;

                if (employeeInfo[i].sex == MALE)
                {
                    cout<<"\n"<<setw(64)<<right<<"Sex: MALE"<<endl;
                }
                    else if (employeeInfo[i].sex == FEMALE)
                    {
                        cout<<"\n"<<setw(64)<<right<<"Sex: FEMALE"<<endl;
                    }

                cout<<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                do
                {
                    cout<<"Update customer's sex (1 - MALE | 2 - FEMALE): ";
                    cin>>sex;
                    cin.clear();
                    cin.ignore();

                    switch (sex)
                    {
                        case 1:
                            employeeInfo[i].sex = MALE;
                            break;
                        case 2:
                            employeeInfo[i].sex = FEMALE;
                            break;
                        default:
                            RetryStyle();
                            break;
                    }
                } while (sex != 1 && sex != 2);
            }
        }

        if (found == true)
        {
            UpdateConfirmed();
        }
            else
            {
                RecordSearchFailed();
            }             
    } while (found == false);
}

void EmployeeUpdateOption3(Employee employeeInfo[], int &prevI, int &role)
{
    int i;
    bool found;
    string search;
    
    do
    {
        found = false;

        cout<<"Enter customer's surname/first name to update data (1 - Cancel): ";
        getline(cin, search);
        
        if (search == "1")
        {
            break;
        }

        for (i = 0; i < prevI; i++)
        {   
            if (search == employeeInfo[i].lastName || search == employeeInfo[i].firstName)
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(67)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(57)<<right<<"Employee #"<<employeeInfo[i].employeeRecordNum;

                if (employeeInfo[i].position == DRIVER)
                {
                    cout<<"\n"<<setw(64)<<right<<"Position: DRIVER"<<endl;
                }
                    else if (employeeInfo[i].position == REFILLER)
                    {
                        cout<<"\n"<<setw(64)<<right<<"Position: REFILLER"<<endl;
                    }

                cout<<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                do
                {
                    cout<<"Update employee's position (1 - DRIVER | 2 - REFILLER): ";
                    cin>>role;
                    cin.clear();
                    cin.ignore();

                    switch (role)
                    {
                        case 1:
                            employeeInfo[i].position = DRIVER;
                            break;
                        case 2:
                            employeeInfo[i].position = REFILLER;
                            break;
                        default:
                            RetryStyle();
                            break;
                    }
                } while (role != 1 && role != 2);
            }
        }

        if (found == true)
        {
            UpdateConfirmed();
        }
            else
            {
                RecordSearchFailed();
            }             
    } while (found == false);
}

void EmployeeUpdateParent(Employee emplooyeInfo[], int &prevI, int &sex, int &role)
{
    int choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(65)<<right<<"| Select Field to Update |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(71)<<right<<"[1] Customer Name/Address/Phone #\n"
            <<setw(54)<<right<<"[2] Employee Sex\n"
            <<setw(69)<<right<<"[3] Employee Role/Work Position\n"
            <<setw(45)<<right<<"[4] Back"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(53)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                EmployeeUpdateOption1(emplooyeInfo, prevI);
                break;
            case 2:
                EmployeeUpdateOption2(emplooyeInfo, prevI, sex);
                break;
            case 3:
                EmployeeUpdateOption3(emplooyeInfo, prevI, role);
                break;
            case 4:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            default:
                RetryStyle();
                break;  
        }
    } while (choice != 4);
}

void EmployeeManagement(Employee employeeInfo[], Employee tempInfo[], int &prevI)
{
    int i, choice, size, sex, role;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(62)<<right<<"| Employee Records |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(61)<<right<<"[1] Add Employee Data\n"
            <<setw(65)<<right<<"[2] Display Employee Data\n"
            <<setw(64)<<right<<"[3] Update Employee Data\n"
            <<setw(63)<<right<<"[4] Return to Main Menu\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(53)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";
        
        switch(choice)
        {
            case 1:
                AddEmployeeInfo(employeeInfo, prevI, size, sex, role);
                break;
            case 2:
                DisplayEmployeeInfo(employeeInfo, prevI);
                break;
            case 3:
                EmployeeUpdateParent(employeeInfo, prevI, sex, role);
                break;
            case 4:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            default:
                RetryStyle();
                break;
        }
    } while (choice != 4);
}

void MainMenu(Customer customerInfo[], Product productInfo[], Employee employeeInfo[], Customer custTempInfo[],  Employee empTempInfo[], int &custPrevI, int &prodPrevI, int &empPrevI)
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
                CustomerManagement(customerInfo, custTempInfo, custPrevI);
                break;
            case 3:
                EmployeeManagement(employeeInfo, empTempInfo, empPrevI);
                break;
            case 4:
            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(58)<<"See you again!"
                <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                break;
            default:
                RetryStyle();
                break;
        }

    } while (choice != 4);
}

int main()
{
    Customer customerInformation[50], custTempInfo[50]; // declare all needed struct/variables/arrays here so all of the value/data persists even if functions end,
    Product productInformation[50]; // only does it stop persisting after the program ends.
    Employee employeeInfromation[50], empTempInfo[50]; // array size is 50 maximum per struct, it's just for a case study after all, it makes the program light :D

    int customerPrevI, productPrevI, employeePrevI;

    MainMenu(customerInformation, productInformation, employeeInfromation, custTempInfo, empTempInfo, customerPrevI, productPrevI, employeePrevI);

    return EXIT_SUCCESS;
}