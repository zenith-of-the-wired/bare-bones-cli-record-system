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
    double priceToPay;
    PAYMENT_STATUS paymentStatus;
};

struct Product{
    int tankStorage;
    int year;
    int day;
    MONTHS month;
    int sales;
    int distributedGallonQty;
    int iceBagBatchQty;
    int bottledWaterBatchQty;
    string gallonType;
    string iceBagType;
    string bottledWaterType;
};

struct Employee{
    string fullName;
    string address;
    int phoneNumber;
    POSITION position;
    SEX sex;
};

void MainMenu(); // so that other functions can also call MainMenu, because they are defined before it.

void PeopleInfo()
{

}

void CustomerInfo()
{

}

void CustomerUpdates()
{

}

void PaymentStatus()
{

}

void GallonOwnership()
{

}

void LatestTransactionDate()
{

}

void CustomerManagement()
{
    int choice;

    do
    {
        cout<<"-----=====---===   Customer Records   ===---=====-----"
            <<"\n"<<setw(21)<<"[1] Customers"<<setw(26)<<"[3] Gallon Ownership"
            <<"\n"<<setw(26)<<"[2] Payment Status"<<setw(28)<<"[4] Latest Transaction Date"
            <<"\n"<<setw(40)<<"[5] Return to Main Menu"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----";
        cout<<"\nInput: ";
        cin>>choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                return CustomerInfo();
                break;
            case 2:
                return PaymentStatus();
                break;
            case 3:
                return GallonOwnership();
                break;
            case 4:
                return LatestTransactionDate();
                break;
            case 5:
                return MainMenu();
                break;
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
        }

    } while (choice != 5);
}

void ProductUpdates()
{

}

void MaintenanceRecord()
{

}

void DistributedGallons()
{

}

void TotalPriceUnpaid()
{
    double totalPriceUnpaid;
}

void BottledWaterStorage()
{
    
}

void IceBagStorage()
{
    
}

void ProductManagement()
{
    int choice;

    do
    {
        cout<<"-----=====---===   Product Management  ===---=====-----"
            <<"\n"<<setw(27)<<"[1] Maintenance Record"<<setw(26)<<"[4] Water Bottle Storage"
            <<"\n"<<setw(28)<<"[2] Distributed Gallons"<<setw(20)<<"[5] Ice Bag Storage"
            <<"\n"<<setw(27)<<"[3] Total Price Unpaid"<<setw(25)<<"[6] Return to Main Menu"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----";
        cout<<"\nInput: ";
        cin>>choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                MaintenanceRecord();
                break;
            case 2:
                DistributedGallons();
                break;
            case 3: 
                TotalPriceUnpaid();
                break;
            case 4: 
                BottledWaterStorage();
                break;
            case 5: 
                IceBagStorage;
                break;
            case 6:
                MainMenu();
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
                break;
        }

    } while (choice != 6);
}

void EmployeeUpdates()
{

}

void EmployeeInfo()
{

}

void BusinessInfo()
{

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
        cin.ignore();

        switch(choice)
        {
            case 1:
                return EmployeeInfo();
                break;
            case 2:
                return BusinessInfo();
                break;
            case 3:
                return MainMenu();
                break;
            default:
                cout<<"-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                cout<<setw(41)<<"Try again! Choice not found."<<endl;
                break;
        }

    } while (choice != 3);
}

void MainMenu()
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
        cin.ignore();

        switch(choice)
        {
            case 1:
                return ProductManagement();
                break;
            case 2:
                return CustomerManagement();
                break;
            case 3:
                return EmployeeManagement();
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
    MainMenu();
}