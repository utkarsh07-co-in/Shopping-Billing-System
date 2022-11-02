#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};
void shopping :: menu()
{
    int choice;
    string email;
    string password;

    cout<<"*********************************************"<<endl;
    cout<<"*                                           *"<<endl;
    cout<<"*           SUPER MARKET MAIN MENU          *"<<endl;
    cout<<"*                                           *"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<endl;
    start:
    cout<<"*****| 1) Administrator.   |*****"<<endl; 
    cout<<"*****| 2) Buyer.           |*****"<<endl; 
    cout<<"*****| 3) Exit.            |*****"<<endl; 
    cout<<endl;
    cout<<"PLEASE SELECT ANY OF THESE !!! "<<endl;
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
        {
            cout<<"Enter E-mail id : "<<endl;
            cin>>email;
            cout<<"Enter password : "<<endl;
            cin>>password;
            if(email=="av9514843@gmail.com" && password=="Aakash2003")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid E-mail/Password"<<endl;
            }
            break;
        }
        case 2:
        {
            buyer();
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            cout<<"You Entered invalid option!!!"<<endl;
            cout<<"Enter option(1,2,or 3)"<<endl;
            cout<<"*****************************************"<<endl;
        }
        goto start;
    }
}
void shopping :: administrator()
{
    A:
    int choice;
    cout<<"**************** ADMINISTRATOR ****************"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"*****| 1) Add the product.               |*****"<<endl; 
    cout<<"*****| 2) Modify the product.            |*****"<<endl; 
    cout<<"*****| 3) Delete the product.            |*****"<<endl;  
    cout<<"*****| 3) Back to main menu.             |*****"<<endl;  
    cout<<endl;
    cout<<"PLEASE SELECT ANY OF THESE !!! "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"INVALID CHOICE!!!"<<endl;
        }
        goto A;
    }
}
void shopping:: buyer()
{
    b:
    int choice;
    cout<<"*********** BUYER ***********"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"*****| 1) Buy Product.   |*****"<<endl; 
    cout<<"*****| 2) Go back.       |*****"<<endl; 
    cout<<endl;
    cout<<"Enter your choice."<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
            menu();
            break;
        }
        default:
        {
            cout<<"INVALID CHOICE!!!"<<endl;
            goto b;
        }
    } 
}
void shopping :: add()
{
    fstream data;
    int c;
    int flag=0;
    float p;
    float d;
    string n;
    f:
    cout<<"ADD NEW PRODUCTS"<<endl;
    cout<<"Product Code of the product : "<<endl;
    cin>>pcode;
    cout<<"Nmae of the product : "<<endl;
    cin>>pname;
    cout<<"Price of the product : "<<endl;
    cin>>price;
    cout<<"discount on  product : "<<endl;
    cin>>dis;

    data.open("Product.txt",ios::in);  //opening file in reading mode.
    if(!data)
    {
        data.open("Product.txt",ios::app|ios::out); //opening flile in append and writing mode.
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();  //closing the file.
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                flag++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(flag==1)
        {
            goto f;
        }
        else
        {
            data.open("Product.txt",ios::app|ios::out); //opening flile in append and writing mode.
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            data.close();  //closing the file.
        }
    }
    cout<<endl<<"        RECORD INSERTED!!!    ";
}
void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int flag=0;
    int c;
    float p;
    float d;
    string n;
    e:
    cout<<" MODIFY THE PRODUCT "<<endl;
    cout<<"Product Code : "<<endl;
    cin>>pkey;
    data.open("Product.txt", ios :: in);
    if(!data)
    {
        cout<<endl<<"File doesn't exist!"<<endl;
    }
    else
    {
        data1.open("Product1.txt", ios :: app| ios :: out);
        // now for iteration purpose
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"Product new code : "<<endl;
                cin>>c;
                cout<<"Name of product : "<<endl;
                cin>>n;
                cout<<"Price of the product : "<<endl;
                cin>>p;
                cout<<"Dicount on product : "<<endl;
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                flag++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
        }
        data.close();
        data1.close();

        remove("Product.txt");
        rename("Product1.txt","Product.txt");
        if(flag==1)
        {
            cout<<"Record Inserted"<<endl;
        }
        else
        {
            cout<<"Invalid Product Key"<<endl;
            goto e;
        }
    }
}
void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int flag=0;
    cout<<" MODIFY THE PRODUCT "<<endl;
    cout<<"Product Code : "<<endl;
    cin>>pkey;
    data.open("Product.txt",ios::in);
    if(!data)
    {
        cout<<endl<<"File doesn't exist !"<<endl;
    }
    else
    {
        data1.open("Product1.txt", ios::app|ios :: out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"Data removed successfully";
                flag++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("Product.txt");
        rename("Product1.txt","Product.txt");

        if(flag==0)
        {
            cout<<"Record not found"<<endl;
        }
    }
}
void shopping :: list()
{
    fstream data;
    data.open("Product1.txt",ios::in);
    cout<<"*********************"<<endl;
    cout<<"ProNo  Name  Price"<<endl;
    cout<<"*********************"<<endl;
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<" "<<pname<<" "<<price<<endl;
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping :: receipt()
{
    fstream data;
    int arrc[150];
    int arrq[150];
    char choice;
    int c=0;
    float amount =0;
    float dis =0;
    float total =0;
    m:
    cout<<endl<<"       Reciept       "<<endl;
    data.open("Product.txt",ios::in);  //opening file in reading mode.
    if(!data)
    {
        cout<<endl<<"Empty database"<<endl;
    }
    else{
        data.close();
        list();
        cout<<"*************************************"<<endl;
        cout<<"                                     "<<endl;
        cout<<"****** Please place the order *******"<<endl;
        cout<<"                                     "<<endl;
        cout<<"*************************************"<<endl;
        do
        {
            cout<<"Enter the Product Code : "<<endl;
            cin>>arrc[c];
            cout<<"Enter the Product Quantity : "<<endl;
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"Duplicate product key Please try again !!!"<<endl;
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to buy another product? if yes then press y else no"<<endl;
            cin>>choice;

        }
        while(choice=='y');
        cout<<endl<<"************************************* Reciept ************************************"<<endl;
              cout<<"Product No  Product Name  Product Quantity  Price  Amount  Amount Whith Discount"<<endl;
        for(int i=0;i<c;i++)
        {
            data.open("Product.txt",ios::in);  //opening file in reading mode.
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    float discount=(amount*dis/100);
                    total=total+dis;
                cout<<pcode<<"        "<<pname<<"       "<<arrq[i]<<"        "<<price<<"       "<<amount<<"      "<<dis<<endl;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }data.close();
    }
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"Total => "<<total;
}
int main()
{
    shopping obj;
    obj.menu();
}