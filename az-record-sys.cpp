#include <iostream>
#include <cstdlib>

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

struct Product{
    int tankStorage;
    int year;
    int day;
    MONTHS month;
    int distributedGallons;
    double totalPriceUnpaid;
    int waterBottleBatchQty;
    int sales;
};

struct Customer{
    string fullName;
    string address;
    int phoneNumber;
    int gallonsOwnedQty;
    int day;
    double priceToPay;
    PAYMENT_STATUS paymentStatus;
};

struct Employee{
    string fullName;
    string address;
    int phoneNumber;
    POSITION position;
    SEX sex;
};

void MainMenu();

void ProductManagement()
{

}

void AddProductInfo()
{

}

void CustomerManagement()
{

}

void AddCustomerInfo()
{

}

void EmployeeManagement()
{

}

void AddEmployeeInfo()
{

}

void MainMenu()
{
    
}

int main()
{
    
}