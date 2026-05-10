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
    PAYMENT_STATUS paymentStatus;
};

struct Sales{
    int week[4];
};

struct Product{
    int tankStorage[50];
    int latestYear[50];
    int upcomingYear[50];
    int latestDay[50];
    int upcomingDay[50];
    int distributedGallonQty;
    int unpaidGallons;
    int paidGallons;
    MONTHS latestMonth[50];
    MONTHS upcomingMonth[50];
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

void UpdateConfirmed(string &target)
{
    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(49)<<target<<" record updated!\n"
        <<"---------------------------------------------------------------------------------------------------------"<<endl;
}

void RecordSearchFailed(string &target)
{
    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(47)<<target<<" record not found!\n"
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

void AddCustomerInfo(Customer customerInfo[], Customer tempInfo[], Product &productInfo, int &prevI, int &paymentStatus)
{
    int i, size;

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
        customerInfo[i + prevI].customerRecordNum =  i + prevI + 1;

        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(59)<<right<<"Customer Record #"<<customerInfo[i].customerRecordNum + prevI
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
                    productInfo.paidGallons += customerInfo[i + prevI].gallonsOwnedQty;
                    break;
                case 2:
                    customerInfo[i + prevI].paymentStatus = UNPAID;
                    productInfo.unpaidGallons += customerInfo[i + prevI].gallonsOwnedQty;
                    break;
                default:
                    RetryStyle();
                    break;
            }
        } while (paymentStatus != 1 && paymentStatus != 2);

        CustomerOriginalCopy(customerInfo, tempInfo, prevI);
        productInfo.distributedGallonQty = productInfo.paidGallons + productInfo.unpaidGallons;
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

void DisplayCustomerInfo(Customer customerInfo[], Customer tempInfo[], int &prevI)
{
    int i, choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(61)<<"| Customer Data |\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(6)<<left<<"#"<<setw(10)<<left<<"Surname"<<setw(16)<<left<<"First Name"<<setw(5)<<left<<"M.I"<<setw(30)<<left<<"Address"<<setw(13)<<left<<"Phone No."<<setw(9)<<left<<"Gallons"<<setw(8)<<left<<"Latest"<<"Status"
            <<"\n-----|--------|--------------------|-----------------------------|-------------|-------|----------------|"<<endl;

        for (i = 0; i < prevI; i++)
        {
            cout<<setw(6)<<left<<customerInfo[i].customerRecordNum
                <<setw(10)<<left<<customerInfo[i].lastName
                <<setw(16)<<left<<customerInfo[i].firstName
                <<setw(5)<<left<<customerInfo[i].middleInitial
                <<setw(30)<<left<<customerInfo[i].address
                <<setw(13)<<left<<customerInfo[i].phoneNumber
                <<setw(9)<<left<<customerInfo[i].gallonsOwnedQty;

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
        cout<<setw(50)<<right<<"Input: ";
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

void CustomerUpdateOption1(Customer customerInfo[], int &prevI, string &target)
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
            UpdateConfirmed(target);
        }
            else
            {
                RecordSearchFailed(target);
            }
    } while (found == false);
}

void CustomerUpdateOption2(Customer customerInfo[], Product &productInfo, int &prevI, string &target)
{
    int i, oldValue, update;
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
                    <<"\n"<<setw(60)<<right<<"Gallons Owned: "<<customerInfo[i].gallonsOwnedQty
                    <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                oldValue = customerInfo[i].gallonsOwnedQty;
                
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

                update = customerInfo[i].gallonsOwnedQty - oldValue;

                if(customerInfo[i].paymentStatus == PAID)
                {
                    productInfo.paidGallons += update;
                }
                    else if(customerInfo[i].paymentStatus == UNPAID)
                    {
                        productInfo.unpaidGallons += update;
                    }
                    
                productInfo.distributedGallonQty = productInfo.paidGallons + productInfo.unpaidGallons;
            }
        }

        if (found == true)
        {
            UpdateConfirmed(target);
        }
            else
            {
                RecordSearchFailed(target);
            }
    } while (found == false);
}

void CustomerUpdateOption3(Customer customerInfo[], Product &productInfo, int &prevI, int &paymentStatus, string &target)
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
                            productInfo.paidGallons += customerInfo[i].gallonsOwnedQty;
                            productInfo.unpaidGallons -= customerInfo[i].gallonsOwnedQty;
                            break;
                        case 2:
                            customerInfo[i].paymentStatus = UNPAID;
                            productInfo.unpaidGallons += customerInfo[i].gallonsOwnedQty;
                            productInfo.paidGallons -= customerInfo[i].gallonsOwnedQty;
                            break;
                        default:
                            RetryStyle();
                            break;
                    }
                } while (paymentStatus != 1 && paymentStatus != 2);

                productInfo.distributedGallonQty = productInfo.paidGallons + productInfo.unpaidGallons;
            }
        }

        if (found == true)
        {
            UpdateConfirmed(target);
        }
            else
            {
                RecordSearchFailed(target);
            }             
    } while (found == false);
}

void CustomerUpdateParent(Customer customerInfo[], Product &productInfo, int &prevI, int &paymentStatus)
{
    int choice;
    string target = "Customer";

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(65)<<right<<"| Select Field to Update |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(71)<<right<<"[1] Customer Name/Address/Phone #\n"
            <<setw(58)<<right<<"[2] Gallon Ownership\n"
            <<setw(56)<<right<<"[3] Payment Status\n"
            <<setw(45)<<right<<"[4] Back"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                CustomerUpdateOption1(customerInfo, prevI, target);
                break;
            case 2:
                CustomerUpdateOption2(customerInfo, productInfo, prevI, target);
                break;
            case 3:
                CustomerUpdateOption3(customerInfo, productInfo, prevI, paymentStatus, target);
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

void CustomerManagement(Customer customerInfo[], Customer tempInfo[], Product &productInfo, int &prevI)
{
    int choice, i, paymentStatus;

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
            <<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice)
        {
            case 1:
                AddCustomerInfo(customerInfo, tempInfo, productInfo, prevI, paymentStatus);
                break;
            case 2:
                DisplayCustomerInfo(customerInfo, tempInfo, prevI);
                break;
            case 3:
                CustomerUpdateParent(customerInfo, productInfo, prevI, paymentStatus);
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

void UpdateSales(Product &productInfo, Sales salesInfo[], int &monthlySales, int &totalSales, int PRICE)
{
    int x, y, choice, week, month;
    bool valid = false;
    string months[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};


    cout<<"Which week do you want to update? (1 - 4): ";
    cin>>week;
    cin.clear();
    cin.ignore();

    while (week < 1 || week > 4)
    {
        RetryStyle();   

        cout<<"Which week do you want to update? (1 - 4): ";
        cin>>week;
        cin.clear();
        cin.ignore();
    }

    cout<<"Which month is this week part of? (1 - 12): ";
    cin>>month;
    cin.clear();
    cin.ignore();

    while (month < 1 || month > 12)
    {
        RetryStyle();

        cout<<"Which month is this week part of? (1 - 12): ";
        cin>>month;
        cin.clear();
        cin.ignore();
    }

    cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
    <<setw(62)<<"Data you're about to update:\n"
    <<"---------------------------------------------------------------------------------------------------------\n"
    <<setw(42)<<right<<"Month: "<<months[month - 1]<<setw(8)<<right<<"Week #"<<week<<"\n"
    <<setw(49)<<right<<"Sales: "<<salesInfo[month - 1].week[week - 1]
    <<"\n---------------------------------------------------------------------------------------------------------"<<endl;

    cout<<"Enter updated sales: ";
    cin>>salesInfo[month - 1].week[week - 1];
    cin.clear();
    cin.ignore();

    if (salesInfo[month - 1].week[week - 1] < 0)
    {
        cout<<"---------------------------------------------------------------------------------------------------------\n"
            <<setw(60)<<right<<"Record update failed!\n"
            <<"---------------------------------------------------------------------------------------------------------"<<endl;

        cout<<"Enter updated sales: ";
        cin>>salesInfo[month - 1].week[week - 1];
        cin.clear();
        cin.ignore();
    }

    valid = true;

    if (valid == true)
    {
        cout<<"---------------------------------------------------------------------------------------------------------\n"
            <<setw(56)<<right<<"Record updated!\n"
            <<"---------------------------------------------------------------------------------------------------------"<<endl;
    }
}

void DisplaySales(Product &productInfo, Sales salesInfo[])
{
    int x, y, choice, monthlySales, totalSales;
    int const PRICE = 30;

    do
    {
        totalSales = 0;

        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(59)<<"| Sales Information |\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(30)<<right<<"Month"<<setw(13)<<right<<"Week #1"<<setw(12)<<right<<"Week #2"<<setw(10)<<right<<"Week #3"<<setw(12)<<right<<"Week #4\n"
            <<"---------------------------------------------------------------------------------------------------------"<<endl;
        
            // had to write every month and week manually, using loops would actually take so much more effort compared to doing this. week 0 is week 1 and so forth, saleInfo 0 is january and so forth.
            cout<<setw(25)<<right<<" "<<setw(11)<<left<<"JANUARY"<<setw(11)<<left<<salesInfo[0].week[0]<<setw(11)<<left<<salesInfo[0].week[1]<<setw(11)<<left<<salesInfo[0].week[2]<<setw(11)<<left<<salesInfo[0].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"FEBRUARY"<<setw(11)<<left<<salesInfo[1].week[0]<<setw(11)<<left<<salesInfo[1].week[1]<<setw(11)<<left<<salesInfo[1].week[2]<<setw(11)<<left<<salesInfo[1].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"MARCH"<<setw(11)<<left<<salesInfo[2].week[0]<<setw(11)<<left<<salesInfo[2].week[1]<<setw(11)<<left<<salesInfo[2].week[2]<<setw(11)<<left<<salesInfo[2].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"APRIL"<<setw(11)<<left<<salesInfo[3].week[0]<<setw(11)<<left<<salesInfo[3].week[1]<<setw(11)<<left<<salesInfo[3].week[2]<<setw(11)<<left<<salesInfo[3].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"MAY"<<setw(11)<<left<<salesInfo[4].week[0]<<setw(11)<<left<<salesInfo[4].week[1]<<setw(11)<<left<<salesInfo[4].week[2]<<setw(11)<<left<<salesInfo[4].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"JUNE"<<setw(11)<<left<<salesInfo[5].week[0]<<setw(11)<<left<<salesInfo[5].week[1]<<setw(11)<<left<<salesInfo[5].week[2]<<setw(11)<<left<<salesInfo[5].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"JULY"<<setw(11)<<left<<salesInfo[6].week[0]<<setw(11)<<left<<salesInfo[6].week[1]<<setw(11)<<left<<salesInfo[6].week[2]<<setw(11)<<left<<salesInfo[6].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"AUGUST"<<setw(11)<<left<<salesInfo[7].week[0]<<setw(11)<<left<<salesInfo[7].week[1]<<setw(11)<<left<<salesInfo[7].week[2]<<setw(11)<<left<<salesInfo[7].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"SEPTEMBER"<<setw(11)<<left<<salesInfo[8].week[0]<<setw(11)<<left<<salesInfo[8].week[1]<<setw(11)<<left<<salesInfo[8].week[2]<<setw(11)<<left<<salesInfo[8].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"OCTOBER"<<setw(11)<<left<<salesInfo[9].week[0]<<setw(11)<<left<<salesInfo[9].week[1]<<setw(11)<<left<<salesInfo[9].week[2]<<setw(11)<<left<<salesInfo[9].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"NOVEMBER"<<setw(11)<<left<<salesInfo[10].week[0]<<setw(11)<<left<<salesInfo[10].week[1]<<setw(11)<<left<<salesInfo[10].week[2]<<setw(11)<<left<<salesInfo[10].week[3]<<"\n"
                <<setw(25)<<right<<" "<<setw(11)<<left<<"DECEMBER"<<setw(11)<<left<<salesInfo[11].week[0]<<setw(11)<<left<<salesInfo[11].week[1]<<setw(11)<<left<<salesInfo[11].week[2]<<setw(11)<<left<<salesInfo[11].week[3]<<endl;

        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;

        for (x = 0; x < 12; x++)
        {
            for (y = 0; y < 4; y++)
            {
                // both formulas for bonus pts, sub total is monthlySales and grand total is totalSales.
                monthlySales = salesInfo[x].week[y] * PRICE; 
                totalSales += monthlySales;
            }
        }

        cout<<setw(11)<<right<<"TOTAL SALES THIS YEAR: ₱"<<totalSales<<endl;

        cout<<"---------------------------------------------------------------------------------------------------------"
            <<setw(11)<<right<<"\nCURRENT PRICE PER GALLON : ₱"<<PRICE
            <<"\nNOTE: NUMBERS ABOVE ARE HOW MANY GALLONS SOLD PER WEEK. NOT ACTUAL PESOS PRICE."
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
            <<"\n"<<setw(43)<<right<<"[1] Back"<<setw(24)<<right<<"[2] Add/Update Sales"
            <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            case 2:
                UpdateSales(productInfo, salesInfo, monthlySales, totalSales, PRICE);
                break;
            default:
                RetryStyle();
                break;
        }
    } while (choice != 1);
}

void AddWaterTank(Product &productInfo, int &prevI)
{
    int i, latestMonth, upcomingMonth;

        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(63)<<right<<"| Adding Water Tank Data |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n";

        for (i = 0; i < 1; i++)
        {
            productInfo.tankStorage[i + prevI] = i + prevI + 1;

            cout<<"Tank #"<<productInfo.tankStorage[i] + prevI
                <<"\nLast Maintenance Date"<<endl;

            do
            {
                cout<<"Enter Month (1-12 : 1 for Jan, 12 for Dec...): ";
                cin>>latestMonth;
                cin.ignore();

                switch (latestMonth)
                {
                    case 1:
                        productInfo.latestMonth[i + prevI] = JANUARY;
                        break;
                    case 2:
                        productInfo.latestMonth[i + prevI] = FEBRUARY;
                        break;
                    case 3:
                        productInfo.latestMonth[i + prevI] = MARCH;
                        break;
                    case 4:
                        productInfo.latestMonth[i + prevI] = APRIL;
                        break;
                    case 5:
                        productInfo.latestMonth[i + prevI] = MAY;
                        break;
                    case 6:
                        productInfo.latestMonth[i + prevI] = JUNE;
                        break;
                    case 7:
                        productInfo.latestMonth[i + prevI] = JULY;
                        break;
                    case 8:
                        productInfo.latestMonth[i + prevI] = AUGUST;
                        break;
                    case 9:
                        productInfo.latestMonth[i + prevI] = SEPTEMBER;
                        break;
                    case 10:
                        productInfo.latestMonth[i + prevI] = OCTOBER;
                        break;
                    case 11:
                        productInfo.latestMonth[i + prevI] = NOVEMBER;
                        break;
                    case 12:
                        productInfo.latestMonth[i + prevI] = DECEMBER;
                        break;
                    default:
                        RetryStyle();
                        break;
                }
            } while (latestMonth != 1 && latestMonth != 2 && latestMonth != 3 && latestMonth != 4 && latestMonth != 5 && latestMonth != 6 && latestMonth != 7 && latestMonth != 8 && latestMonth != 9 && latestMonth != 10 && latestMonth != 11 && latestMonth != 12);
            
            cout<<"Enter Day (1-31): ";
            cin>>productInfo.latestDay[i + prevI];

            while (productInfo.latestDay[i] <= 0 || productInfo.latestDay[i] > 31)
                {
                    cout<<"---------------------------------------------------------------------------------------------------------\n"
                        <<setw(63)<<right<<"Invalid Day! Try again.\n"
                        <<"---------------------------------------------------------------------------------------------------------\n";
                    
                    cout<<"Enter Day (1-31): ";
                    cin>>productInfo.latestDay[i];
                }

            cout<<"Enter Year: ";
            cin>>productInfo.latestYear[i + prevI];

            while (productInfo.latestYear[i + prevI] < 2000 || productInfo.latestYear[i + prevI] > 9999)
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(64)<<right<<"Invalid Year! Try again.\n"
                    <<"---------------------------------------------------------------------------------------------------------\n";
                
                cout<<"Enter Year: ";
                cin>>productInfo.latestYear[i + prevI];
            }

            cout<<"\nUpcoming Maintenance Date"<<endl;

            do
            {
                cout<<"Enter Month (1-12 : 1 for Jan, 12 for Dec...): ";
                cin>>upcomingMonth;
                cin.ignore();

                switch (upcomingMonth)
                {
                    case 1:
                        productInfo.upcomingMonth[i + prevI] = JANUARY;
                        break;
                    case 2:
                        productInfo.upcomingMonth[i + prevI] = FEBRUARY;
                        break;
                    case 3:
                        productInfo.upcomingMonth[i + prevI] = MARCH;
                        break;
                    case 4:
                        productInfo.upcomingMonth[i + prevI] = APRIL;
                        break;
                    case 5:
                        productInfo.upcomingMonth[i + prevI] = MAY;
                        break;
                    case 6:
                        productInfo.upcomingMonth[i + prevI] = JUNE;
                        break;
                    case 7:
                        productInfo.upcomingMonth[i + prevI] = JULY;
                        break;
                    case 8:
                        productInfo.upcomingMonth[i + prevI] = AUGUST;
                        break;
                    case 9:
                        productInfo.upcomingMonth[i + prevI] = SEPTEMBER;
                        break;
                    case 10:
                        productInfo.upcomingMonth[i + prevI] = OCTOBER;
                        break;
                    case 11:
                        productInfo.upcomingMonth[i + prevI] = NOVEMBER;
                        break;
                    case 12:
                        productInfo.upcomingMonth[i + prevI] = DECEMBER;
                        break;
                    default:
                        RetryStyle();
                        break;
                }
            } while (upcomingMonth != 1 && upcomingMonth != 2 && upcomingMonth != 3 && upcomingMonth != 4 && upcomingMonth != 5 && upcomingMonth != 6 && upcomingMonth != 7 && upcomingMonth != 8 && upcomingMonth != 9 && upcomingMonth != 10 && upcomingMonth != 11 && upcomingMonth != 12);
            
            cout<<"Enter Day (1-31): ";
            cin>>productInfo.upcomingDay[i + prevI];

            while (productInfo.upcomingDay[i] <= 0 || productInfo.upcomingDay[i] > 31)
                {
                    cout<<"---------------------------------------------------------------------------------------------------------\n"
                        <<setw(63)<<right<<"Invalid Day! Try again.\n"
                        <<"---------------------------------------------------------------------------------------------------------\n";
                    
                    cout<<"Enter Day (1-31): ";
                    cin>>productInfo.upcomingDay[i];
                }

            cout<<"Enter Year: ";
            cin>>productInfo.upcomingYear[i + prevI];

            while (productInfo.upcomingYear[i + prevI] < 2000 || productInfo.upcomingYear[i + prevI] > 9999)
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(64)<<right<<"Invalid Year! Try again.\n"
                    <<"---------------------------------------------------------------------------------------------------------\n";
                
                cout<<"Enter Year: ";
                cin>>productInfo.upcomingYear[i + prevI];
            }
        }

        prevI += i;
}

void LatestMonthDisplay(Product &productInfo, int &i)
{
    if (productInfo.latestMonth[i] == JANUARY)
    {
        cout<<setw(6)<<right<<" "<<setw(10)<<left<<"JANUARY";
    }
        else if (productInfo.latestMonth[i] == FEBRUARY)
        {
            cout<<setw(6)<<right<<" "<<setw(10)<<left<<"FEBRUARY";
        }
            else if (productInfo.latestMonth[i] == MARCH)
            {
                cout<<setw(6)<<right<<" "<<setw(10)<<left<<"MARCH";
            }
                else if (productInfo.latestMonth[i] == APRIL)
                {
                    cout<<setw(6)<<right<<" "<<setw(10)<<left<<"APRIL";
                }
                    else if (productInfo.latestMonth[i] == MAY)
                    {
                        cout<<setw(6)<<right<<" "<<setw(10)<<left<<"MAY";
                    }
                        else if (productInfo.latestMonth[i] == JUNE)
                        {
                            cout<<setw(6)<<right<<" "<<setw(10)<<left<<"JUNE";
                        }
                            else if (productInfo.latestMonth[i] == JULY)
                            {
                                cout<<setw(6)<<right<<" "<<setw(10)<<left<<"JULY";
                            }
                                else if (productInfo.latestMonth[i] == AUGUST)
                                {
                                    cout<<setw(6)<<right<<" "<<setw(10)<<left<<"AUGUST";
                                }
                                    else if (productInfo.latestMonth[i] == SEPTEMBER)
                                    {
                                        cout<<setw(6)<<right<<" "<<setw(10)<<left<<"SEPTEMBER";
                                    }
                                        else if (productInfo.latestMonth[i] == OCTOBER)
                                        {
                                            cout<<setw(6)<<right<<" "<<setw(10)<<left<<"OCTOBER";
                                        }
                                            else if (productInfo.latestMonth[i] == NOVEMBER)
                                            {
                                                cout<<setw(6)<<right<<" "<<setw(10)<<left<<"NOVEMBER";
                                            }
                                                else if (productInfo.latestMonth[i] == DECEMBER)
                                                {
                                                    cout<<setw(6)<<right<<" "<<setw(10)<<left<<"DECEMBER";
                                                }
}

void UpcomingMonthDisplay(Product &productInfo, int &i)
{
    if (productInfo.upcomingMonth[i] == JANUARY)
    {
        cout<<setw(7)<<right<<" "<<setw(10)<<left<<"JANUARY";
    }
        else if (productInfo.upcomingMonth[i] == FEBRUARY)
        {
            cout<<setw(7)<<right<<" "<<setw(10)<<left<<"FEBRUARY";
        }
            else if (productInfo.upcomingMonth[i] == MARCH)
            {
                cout<<setw(7)<<right<<" "<<setw(10)<<left<<"MARCH";
            }
                else if (productInfo.upcomingMonth[i] == APRIL)
                {
                    cout<<setw(7)<<right<<" "<<setw(10)<<left<<"APRIL";
                }
                    else if (productInfo.upcomingMonth[i] == MAY)
                    {
                        cout<<setw(7)<<right<<" "<<setw(10)<<left<<"MAY";
                    }
                        else if (productInfo.upcomingMonth[i] == JUNE)
                        {
                            cout<<setw(7)<<right<<" "<<setw(10)<<left<<"JUNE";
                        }
                            else if (productInfo.upcomingMonth[i] == JULY)
                            {
                                cout<<setw(7)<<right<<" "<<setw(10)<<left<<"JULY";
                            }
                                else if (productInfo.upcomingMonth[i] == AUGUST)
                                {
                                    cout<<setw(7)<<right<<" "<<setw(10)<<left<<"AUGUST";
                                }
                                    else if (productInfo.upcomingMonth[i] == SEPTEMBER)
                                    {
                                        cout<<setw(7)<<right<<" "<<setw(10)<<left<<"SEPTEMBER";
                                    }
                                        else if (productInfo.upcomingMonth[i] == OCTOBER)
                                        {
                                            cout<<setw(7)<<right<<" "<<setw(10)<<left<<"OCTOBER";
                                        }
                                            else if (productInfo.upcomingMonth[i] == NOVEMBER)
                                            {
                                                cout<<setw(7)<<right<<" "<<setw(10)<<left<<"NOVEMBER";
                                            }
                                                else if (productInfo.upcomingMonth[i] == DECEMBER)
                                                {
                                                    cout<<setw(7)<<right<<" "<<setw(10)<<left<<"DECEMBER";
                                                }
}
    
void UpdateMaintenanceData(Product &productInfo, int &prevI, int &i)
{
    bool found;
    int search, upcomingMonth;
    
    do
    {
        found = false;

        cout<<"Enter tank number to update data: ";
        cin>>search;
        cin.ignore();

        for (i = 0; i < prevI; i++)
        {   
            if (search == productInfo.tankStorage[i])
            {   
                found = true;
                cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                    <<setw(62)<<"Data you're about to update:\n"
                    <<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(48)<<right<<"Tank #"<<productInfo.tankStorage[i]<<"\n"
                    <<setw(45)<<right<<"Last Maintenance Date"<<setw(29)<<right<<"Upcoming Maintenance Date\n"
                    <<setw(18)<<right<<" ";

                    LatestMonthDisplay(productInfo, i);
                    cout<<setw(3)<<left<<productInfo.latestDay[i]<<setw(4)<<left<<productInfo.latestYear[i];

                    UpcomingMonthDisplay(productInfo, i);
                    cout<<setw(3)<<left<<productInfo.upcomingDay[i]<<productInfo.upcomingYear[i];

                cout<<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;

                productInfo.latestMonth[i] = productInfo.upcomingMonth[i];
                productInfo.latestDay[i] = productInfo.upcomingDay[i];
                productInfo.latestYear[i] = productInfo.upcomingYear[i]; 

                cout<<"Update Upcoming Maintenance Date"<<endl;

                do
                {
                    cout<<"Enter Month (1-12 : 1 for Jan, 12 for Dec...): ";
                    cin>>upcomingMonth;
                    cin.ignore();

                    switch (upcomingMonth)
                    {
                        case 1:
                            productInfo.upcomingMonth[i] = JANUARY;
                            break;
                        case 2:
                            productInfo.upcomingMonth[i] = FEBRUARY;
                            break;
                        case 3:
                            productInfo.upcomingMonth[i] = MARCH;
                            break;
                        case 4:
                            productInfo.upcomingMonth[i] = APRIL;
                            break;
                        case 5:
                            productInfo.upcomingMonth[i] = MAY;
                            break;
                        case 6:
                            productInfo.upcomingMonth[i] = JUNE;
                            break;
                        case 7:
                            productInfo.upcomingMonth[i] = JULY;
                            break;
                        case 8:
                            productInfo.upcomingMonth[i] = AUGUST;
                            break;
                        case 9:
                            productInfo.upcomingMonth[i] = SEPTEMBER;
                            break;
                        case 10:
                            productInfo.upcomingMonth[i] = OCTOBER;
                            break;
                        case 11:
                            productInfo.upcomingMonth[i] = NOVEMBER;
                            break;
                        case 12:
                            productInfo.upcomingMonth[i] = DECEMBER;
                            break;
                        default:
                            RetryStyle();
                            break;
                    }
                } while (upcomingMonth != 1 && upcomingMonth != 2 && upcomingMonth != 3 && upcomingMonth != 4 && upcomingMonth != 5 && upcomingMonth != 6 && upcomingMonth != 7 && upcomingMonth != 8 && upcomingMonth != 9 && upcomingMonth != 10 && upcomingMonth != 11 && upcomingMonth != 12);
                
                cout<<"Enter Day (1-31): ";
                cin>>productInfo.upcomingDay[i];

                while (productInfo.upcomingDay[i] <= 0 || productInfo.upcomingDay[i] > 31)
                {
                    cout<<"---------------------------------------------------------------------------------------------------------\n"
                        <<setw(63)<<right<<"Invalid Day! Try again.\n"
                        <<"---------------------------------------------------------------------------------------------------------\n";
                    
                    cout<<"Enter Day (1-31): ";
                    cin>>productInfo.upcomingDay[i];
                }

                cout<<"Enter Year: ";
                cin>>productInfo.upcomingYear[i];

                while (productInfo.upcomingYear[i] < 2000 || productInfo.upcomingYear[i] > 9999)
                {
                    cout<<"---------------------------------------------------------------------------------------------------------\n"
                        <<setw(64)<<right<<"Invalid Year! Try again.\n"
                        <<"---------------------------------------------------------------------------------------------------------\n";
                    
                    cout<<"Enter Year: ";
                    cin>>productInfo.upcomingYear[i];
                }
            }
        }

        if (found == true)
        {
            cout<<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(59)<<right<<"Tank record updated!\n"
                <<"---------------------------------------------------------------------------------------------------------"<<endl;
        }
            else
            {
                cout<<"---------------------------------------------------------------------------------------------------------\n"
                    <<setw(61)<<"Tank record not found!\n"
                    <<"---------------------------------------------------------------------------------------------------------"<<endl;

                break;
            }             
    } while (found == false);
}

void WaterTankMaintenanceData(Product &productInfo, int &prevI)
{
    int i, choice;

    do 
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(62)<<right<<"| Water Tank(s) Information |"
                <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(28)<<right<<"Tank #"<<setw(25)<<right<<"Last Maintenance Date"<<setw(29)<<right<<"Upcoming Maintenance Date\n"
                <<"---------------------------------------------------------------------------------------------------------\n";

                for(i = 0; i < prevI; i++)
                {
                    cout<<setw(26)<<right<<productInfo.tankStorage[i];
                    
                    LatestMonthDisplay(productInfo, i);
                    cout<<setw(3)<<left<<productInfo.latestDay[i]<<setw(4)<<left<<productInfo.latestYear[i];

                    UpcomingMonthDisplay(productInfo, i);
                    cout<<setw(3)<<left<<productInfo.upcomingDay[i]<<productInfo.upcomingYear[i];

                    cout<<endl;
                }
                
            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(29)<<right<<"[1] Back"<<setw(22)<<right<<"[2] Add Water Tank"<<setw(31)<<right<<"[3] Update Maintenance Date\n"
                <<"---------------------------------------------------------------------------------------------------------\n"
                <<setw(50)<<right<<"Input: ";
            cin>>choice;
            cin.ignore();
            cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            case 2:
                AddWaterTank(productInfo, prevI);
                break;
            case 3:
                UpdateMaintenanceData(productInfo, prevI, i);
                break;
            default:
                RetryStyle();
                break;
        }
    } while (choice != 1);
}

void DisplayGallonRecords(Product &productInfo)
{
    int i, choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(62)<<"| Gallons Information |\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"<<endl;
        
            cout<<setw(48)<<right<<"Unpaid Gallons: "<<setw(26)<<right<<productInfo.unpaidGallons<<endl;
    
            cout<<setw(46)<<right<<"Paid Gallons: "<<setw(28)<<right<<productInfo.paidGallons<<endl;
        
            cout<<setw(73)<<right<<"Total Gallons Distributed to Customers:  "<<productInfo.distributedGallonQty<<endl;
        
        cout<<"\n---------------------------------------------------------------------------------------------------------"
            <<"\nFor more information, check customer records."
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"
            <<"\n[1] Back"
            <<"\n---------------------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            default:
                RetryStyle();
                break;
        }
    } while (choice != 1);
}

void ProductManagement(Product &productInfo, Sales salesInfo[], int &prevI)
{
    int choice;

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(62)<<right<<"| Inventory Management |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(64)<<right<<"[1] Water Tank Maintenance\n"
            <<setw(56)<<right<<"[2] Gallon Records\n"
            <<setw(55)<<right<<"[3] Sales Records\n"
            <<setw(61)<<right<<"[4] Return to Main Menu\n"
            <<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch(choice)
        {
            case 1:
                WaterTankMaintenanceData(productInfo, prevI);
                break;
            case 2:
                DisplayGallonRecords(productInfo);
                break;
            case 3:
                DisplaySales(productInfo, salesInfo);
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

void EmployeeOriginalCopy(Employee employeeInfo[], Employee tempInfo[], int &prevI)
{
    int i;

    for (i = 0; i < prevI; i++)
    {
        tempInfo[i] = employeeInfo[i];
    }
}

void AddEmployeeInfo(Employee employeeInfo[], Employee tempInfo[], int &prevI, int &sex, int &role)
{
    int i, choice, size;

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
            employeeInfo[i + prevI].employeeRecordNum =  i + prevI + 1;
              
            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(59)<<right<<"Employee Record #"<<employeeInfo[i].employeeRecordNum + prevI
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

        EmployeeOriginalCopy(employeeInfo, tempInfo, prevI);
    }

    prevI += i; 

    cout<<"---------------------------------------------------------------------------------------------------------\n"
        <<setw(71)<<right<<"Employee Record(s) Added Successfully!"<<endl;
}

void SortEmpDesLastName(Employee employeeInfo[], Employee tempInfo[], int &prevI)
{
    int x, y;
    Employee temp;

    EmployeeOriginalCopy(employeeInfo, tempInfo, prevI);

    for (x = 0; x < prevI - 1; x++)
    {
        for (y = 0; y < prevI - 1 - x; y++)
        {
            if(employeeInfo[y].lastName < employeeInfo[y + 1].lastName)
            {
                temp = employeeInfo[y];
                employeeInfo[y] = employeeInfo[y + 1];
                employeeInfo[y + 1] = temp;
            }
        }
    } 
}

void SortEmpAscLastName(Employee employeeInfo[], Employee tempInfo[], int &prevI)
{
    int x, y;
    Employee temp;

    EmployeeOriginalCopy(employeeInfo, tempInfo, prevI);

    for (x = 0; x < prevI - 1; x++)
    {
        for (y = 0; y < prevI - 1 - x; y++)
        {
            if(employeeInfo[y].lastName > employeeInfo[y + 1].lastName)
            {
                temp = employeeInfo[y];
                employeeInfo[y] = employeeInfo[y + 1];
                employeeInfo[y + 1] = temp;
            }
        }
    } 
}

void DisplayEmployeeInfo(Employee employeeInfo[], Employee tempInfo[], int &prevI)
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
            cout<<setw(6)<<left<<employeeInfo[i].employeeRecordNum
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
        cout<<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                cout<<setw(57)<<right<<"Returning..."<<endl;
                break;
            case 2:
                SortEmpAscLastName(employeeInfo, tempInfo, prevI);
                break;
            case 3:
                SortEmpDesLastName(employeeInfo, tempInfo, prevI);
                break;
            default:
                RetryStyle();
                break;
        }
    } while (choice != 1);
}

void EmployeeUpdateOption1(Employee employeeInfo[], int &prevI, string &target)
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
                    <<setw(57)<<right<<"Employee #"<<employeeInfo[i].employeeRecordNum
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
            UpdateConfirmed(target);
        }
            else
            {
                RecordSearchFailed(target);
            }
    } while (found == false);
}

void EmployeeUpdateOption2(Employee employeeInfo[], int &prevI, int &sex, string &target)
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
            UpdateConfirmed(target);
        }
            else
            {
                RecordSearchFailed(target);
            }             
    } while (found == false);
}

void EmployeeUpdateOption3(Employee employeeInfo[], int &prevI, int &role, string &target)
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
                    <<setw(55)<<right<<"Employee #"<<employeeInfo[i].employeeRecordNum;

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
            UpdateConfirmed(target);
        }
            else
            {
                RecordSearchFailed(target);
            }             
    } while (found == false);
}

void EmployeeUpdateParent(Employee emplooyeInfo[], int &prevI, int &sex, int &role)
{
    int choice;
    string target = "Employee";

    do
    {
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(65)<<right<<"| Select Field to Update |"
            <<"\n-----=====-----=====-----=====-----=====-----=====-----=   ====-----=====-----=====-----=====-----=====-----\n"
            <<setw(71)<<right<<"[1] Employee Name/Address/Phone #\n"
            <<setw(54)<<right<<"[2] Employee Sex\n"
            <<setw(69)<<right<<"[3] Employee Role/Work Position\n"
            <<setw(45)<<right<<"[4] Back"<<endl;
        cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
            <<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch (choice)
        {
            case 1:
                EmployeeUpdateOption1(emplooyeInfo, prevI, target);
                break;
            case 2:
                EmployeeUpdateOption2(emplooyeInfo, prevI, sex, target);
                break;
            case 3:
                EmployeeUpdateOption3(emplooyeInfo, prevI, role, target);
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
    int i, choice, sex, role;

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
            <<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch(choice)
        {
            case 1:
                AddEmployeeInfo(employeeInfo, tempInfo, prevI, sex, role);
                break;
            case 2:
                DisplayEmployeeInfo(employeeInfo, tempInfo, prevI);
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

void MainMenu(Customer customerInfo[], Product &productInfo, Sales salesInfo[], Employee employeeInfo[], Customer custTempInfo[],  Employee empTempInfo[], int &custPrevI, int &prodPrevI, int &empPrevI)
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
            <<setw(50)<<right<<"Input: ";
        cin>>choice;
        cin.clear();
        cin.ignore();

        switch(choice)
        {
            case 1:
                ProductManagement(productInfo, salesInfo, prodPrevI);
                break;
            case 2:
                CustomerManagement(customerInfo, custTempInfo, productInfo, custPrevI);
                break;
            case 3:
                EmployeeManagement(employeeInfo, empTempInfo, empPrevI);
                break;
            case 4:
            cout<<"-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----\n"
                <<setw(55)<<"See you again!"
                <<"\n-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----=====-----"<<endl;
                return;
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
    Product productInformation; // only does it stop persisting after the program ends.
    Sales salesInformation[50]; // array size is 50 maximum per struct/members, 
    Employee employeeInfromation[50], empTempInfo[50]; // it's just for a case study after all, it makes the program light :D

    int customerPrevI, prodPrevI, employeePrevI;

    MainMenu(customerInformation, productInformation, salesInformation, employeeInfromation, custTempInfo, empTempInfo, customerPrevI, prodPrevI, employeePrevI);

    return EXIT_SUCCESS;
}