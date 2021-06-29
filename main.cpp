#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

struct Food
{
    string name;
    float sum;
    bool IsMember;
    string MenuFood[10] = {"Nasi Goreng CTC","Lamb Chop","Banjo", "Chicken Chop", "Fries Chicken", "Fries", "Oblong", "Nugget","Coleslaw", "Mashed Potato"};
};
Food info;

struct receipt
{
    float PricePerFood[10];
    int quantity[10];
    float discountedprice;
};
receipt price;

void OrderFood();
void CheckMemberID();
void CalculationForMember();
void Calculation();
void PrintReceipt();
int Exit();


int main()
{
    cout << setw(70) << "Welcome To Crispy Technician Chicken (CTC)" << endl;
    cout << "\nPlease Enter Your Name:";
    getline(cin, info.name);
    cout << "Hello " << info.name << endl;
    int selection;

    cout << "\nPress 1 To Order Food or Press 2 To Exit Order" << endl;
    cin >> selection;

    switch (selection)
    {
        case 1: cout << "\nOrder Food" << endl;
        OrderFood();
        break;
        case 2: cout << "\nThank You For Visiting Our Restaurant" << endl;
        return 0;
        break;
        default:
        Exit();
    }
}

void OrderFood()
{
    float ArrayPrice[11] = {7.00,25.00,4.00,10.00,4.00,7.50,3.50,11.00,3.00,2.50,3.50};
    int number;
    float sum = 0;
    int quantity;
    bool loop = 1;
    int HaveMemberID;


    while (loop)
    {
    cout << "\nMenu Crispy Technician Chicken:\n " << endl;
    //cout << Food().MenuFood[0] << ArrayPrice[0] << endl;
    cout << "1. Nasi Goreng CTC: RM" << ArrayPrice[1] << endl;
    cout << "2. Lamb Chop: RM" << ArrayPrice[1] << endl;
    cout << "3. Benjo: RM" << ArrayPrice[2] << endl;
    cout << "4. Chicken Chop: RM" << ArrayPrice[3] << endl;
    cout << "5. Fried Chicken: RM" << ArrayPrice[4] << endl;
    cout << "6. Fries: RM" << ArrayPrice[5] << endl;
    cout << "7. Oblong: RM" << ArrayPrice[6] << endl;
    cout << "8. Nugget: RM" << ArrayPrice[7] << endl;
    cout << "9. Coleslaw: RM" << ArrayPrice[8] << endl;
    cout << "10. Mashed Potato: RM" << ArrayPrice[9] << endl;
    cout << "\n" << endl;

    cout << "Enter The Number Of The Menu You Want To Buy :)" << endl;
    cin >> number;



    switch (number)
    {
        case 1: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[0] * quantity;
                price.PricePerFood[0] += ArrayPrice[0] * quantity;
                price.quantity[0] += quantity;
                break;
        case 2: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[1] * quantity;
                price.PricePerFood[1] += ArrayPrice[1] * quantity;
                price.quantity[1] += quantity;
                break;
        case 3: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[2] * quantity;
                price.PricePerFood[2] += ArrayPrice[2] * quantity;
                price.quantity[2] += quantity;
                break;
        case 4: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[3] * quantity;
                price.PricePerFood[3] += ArrayPrice[3] * quantity;
                price.quantity[3] += quantity;
                break;
        case 5: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[4] * quantity;
                price.PricePerFood[4] += ArrayPrice[4] * quantity;
                price.quantity[4] += quantity;
                break;
        case 6: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[5] * quantity;
                price.PricePerFood[5] += ArrayPrice[5] * quantity;
                price.quantity[5] += quantity;
                break;
        case 7: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[6] * quantity;
                price.PricePerFood[6] += ArrayPrice[6] * quantity;
                price.quantity[6] += quantity;
                break;
        case 8: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[7] * quantity;
                price.PricePerFood[7] += ArrayPrice[7] * quantity;
                price.quantity[7] += quantity;
                break;
        case 9: cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[8] * quantity;
                price.PricePerFood[8] += ArrayPrice[8] * quantity;
                price.quantity[8] += quantity;
                break;
        case 10:cout << "Quantities?:";
                cin >> quantity;
                info.sum += ArrayPrice[9] * quantity;
                price.PricePerFood[9] += ArrayPrice[9] * quantity;
                price.quantity[9] += quantity;
                break;
        default: cout << "Unidentified Number" << endl;
                 loop == 1;
    }
    cout << "\nDo You Wish To Buy More Food? Press 1 To Buy More Food or 0 To End Your Order :)" << endl;
    cin >> loop;
    }
    cout << "\nTotal: RM" << info.sum << endl;

    cout << "\nDo You Have A Member ID? Press 1 If You Have, Press 0 If You Do Not have." << endl;
    cin >> HaveMemberID;

    if (HaveMemberID == 1)
        CheckMemberID();
    else if (HaveMemberID == 0)
        Calculation();
   else
        Exit();
}


void CheckMemberID()
{
    int MemberIDInput;
    int IDFileCheck[10];
    bool confirmation;
    ifstream ReadMemberIDFile;
    ReadMemberIDFile.open("id.dat");

    cout << "Enter Your Member ID: ";
    cin >> MemberIDInput;


    if (!ReadMemberIDFile)
    {
        cout << "Could Not Access id.dat" << endl;
    }

    while (!ReadMemberIDFile.eof())
    {
        for (int i = 0; i < 10; i++)
            ReadMemberIDFile >> IDFileCheck[i];
    }

    ReadMemberIDFile.close();

    for (int i = 0; i < 10; i++)
        if (MemberIDInput == IDFileCheck[i])
            confirmation = 1;

    if (confirmation == true)
    {
        info.IsMember = true;
        CalculationForMember();
    }
    else
    {
        cout << "Invalid" << endl;
        Calculation();
    }


}

void CalculationForMember()
{
    cout << "\nThank You For Applying Our Member ID." << endl;
    cout << "25% Off From Your Total Price Is Now Active." << endl;
    PrintReceipt();
}


void Calculation()
{
    PrintReceipt();
}

void PrintReceipt()
{
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);

    fstream StoreReceipt;
    StoreReceipt.open("receipt.dat", ios::app);
    cout << "\nCRISPY TECHNICIAN CHICKEN (CTC) OFFICIAL RECEIPT" << endl;
    cout << "15300 TAMAN SETIA" << endl;
    cout << "This Receipt Belong To " << info.name << endl;
    cout << "\nYour Total Price Is: RM" << info.sum << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "\t" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900;
    cout << "\t\t" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;
    cout << "-----------------------------------------------" << endl;
    //cout << "Menu" << setw(10)  << "Price" << setw(10) <<"Quantity" << endl;


    StoreReceipt << "\nCRISPY TECHNICIAN CHICKEN (CTC) OFFICIAL RECEIPT" << endl;
    StoreReceipt << "15300 TAMAN SETIA" << endl;
    StoreReceipt << "This Receipt Belong to " << info.name << endl;
    StoreReceipt << "-----------------------------------------------" << endl;
    StoreReceipt << "\t" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900;
    StoreReceipt << "\t\t" << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;
    StoreReceipt << "-----------------------------------------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (price.PricePerFood[i] > 0)
            {
                cout << Food().MenuFood[i] << " RM" << price.PricePerFood[i] << " Quantities: " << price.quantity[i] << endl;
                StoreReceipt << Food().MenuFood[i] << " RM" << price.PricePerFood[i] << " Quantities: " << price.quantity[i] << endl;
            }
    }
    if (info.IsMember == true)
    {
        float discountedprice;
        discountedprice = info.sum - (info.sum * 0.25);
        cout << "\nTotal: RM " << info.sum << endl;
        cout << "\nTotal After Discount: RM" << discountedprice << endl;
    }
    else
    {
        cout << "\nTotal: RM " << info.sum << endl;
    }

    cout << "Please Go To Counter B6 To Pay Your Food. Have A Good Day!" << endl;

}


int Exit()
{
    return 0;
}
