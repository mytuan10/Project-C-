
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


#define fio     "Products.txt"
#define fbin    "Products.dat"          // là một phần mở rộng đại diện của các tập tin mang dữ liệu thô(raw data)

using namespace std;

typedef struct Products
{
    char ID[50];
    char nameID[50];
    int quantity;
    float cost;

}product;

void Input      (product prd[], int n);            
void WriteBin   (product prd[], int n);
void Write      (product prd[], int n);
void Sort_Cost  (product prd[], int n);
void ReadBin    (product prd[], int *n);
void Output     (product prd[], int n);
void Search_ID  (product prd[], int n, char ID[]);
void Search_Name(product prd[], int n, char nameID[]);
void Search     (product prd[], int n);


int main()
{
    product prd[50];
    FILE *fp = fopen(fio, "r");
    int n, i, select;

    do{
        //system("clr");
        printf("\nProduct: \n--------------------------\n");
        printf("1: Input\n2: Read and Sort by cost\n3: Search\n4: Exit\n");
        scanf("%d",&select);
        switch (select)
        {
            case 1:
                cout << "\n1: Input\n";
                Input (prd, n);
                Write (prd, n);
                break;

            case 2:
                cout <<"\n2: Read and Sort by cost\n" ;
                Input (prd, n);
                WriteBin (prd, n);
                Output (prd, n);
                Sort_Cost (prd, n);
                Write (prd, n);

                printf ("After sort:\n--------------------------\n");
                ReadBin (prd, &n);
                Output (prd, n);

                break;
            case 3:
                cout <<"\n3: Search\n";
                Search(prd, n);
            
                break;
        
            case 4:
                cout <<"\n4: Search\n";
                return 0;
                break;
        
            default:
                cout << "\nError select!";
                break;
        }
    }
    while (select != 4);
       
    return 0;
}

void Input (product prd[], int n)
{
    int i; 
    char s[50];
    // cout <<"\nEnter the number of products";   scanf("%d",&n);
    // gets(s);
    // cout <<"\n";

    printf("\nEnter the number of products: ");
    scanf("%d", &n);
    gets(s);
    cout << "\n";

    for(i = 0 ; i < (n) ; i++)
    {
        cout << "\nEnter the ID of the product" << i + 1 << ": ";
        gets(prd[i].ID);
        cout << "\nEnter the nameID of the product" << i + 1 << ": ";
        gets(prd[i].nameID);
        cout << "\nEnter the quantity of the product" << i + 1 << ": ";
        cin >> prd[i].quantity ;
        cout << "\nEnter the cost of the product" << i + 1 << ": ";
        cin >> prd[i].cost ;
        gets(s);
    }

}

void WriteBin (product prd[], int n)
{
    FILE *fp = fopen(fio, "wb");
    if(fp == NULL)
    {
        cout <<"\nError load file";
    }
    else{
        fwrite(prd, sizeof(product), n,fp);

    }
    fclose(fp);
}

void Write (product prd[], int n )
{
    FILE *fp = fopen(fio, "wb");
    if(fp == NULL)
    {
        cout <<"\nError load file";
    }
    else{
        fprintf(fp, "\n%-10s %-15s %-10s %-10s\n", "ID", "nameID", "quantity", "cost");
    }
    for(int i = 0 ; i < n ;i ++)
    {
        fprintf(fp, "\n%-10s %-15s %d  %.2f\n", prd[i].ID, prd[i].nameID, prd[i].quantity, prd[i].cost);

    }
    fclose(fp);

    WriteBin(prd, n);
    cout << "\n Input and read success to file\n";

}

// sap xep giam dan thi i phai lon j
void Sort_Cost (product prd[], int n)
{
    for(int i = 0; i < n-1; i ++)
    {
        for(int j = i + 1; j < n ; j++)
        {
            if( prd[i].cost < prd[j].cost )
            {
                product tmp = prd[j];
                prd[j] = prd[i];
                prd[i] = tmp;
            }
        }
    }

}

void ReadBin (product prd[], int *n)
{
    FILE *fp = fopen(fbin, "rb");
    
    fseek(fp, 0, SEEK_END);
    (*n) = (ftell(fp)+1)/sizeof(product);           // tra ve vi tri file hien tai

    fseek(fp, 0, SEEK_SET);
    fread(prd, sizeof(product), *n, fp);

    fclose(fp);
}

void Output (product prd[], int n)
{
    cout << "\n%-10s %-10s %-15s %-10s %-10s\n", "Order", "ID", "nameID", "quantity", "cost" ;
    for(int i = 0 ; i < n ;i ++)
    {
        cout << "\n%-10d %-10s %-15s %d  %.2f\n", i+1, prd[i].ID, prd[i].nameID, prd[i].quantity, prd[i].cost;
    }

}

void Search_ID (product prd[], int n, char ID[])
{
    int check = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(strcmp(ID, prd[i].ID) == 0)
        {
            check = 1;
            cout << "\n%-10s %-10s %-15s %-10s %-10s\n", "Order", "ID", "nameID", "quantity", "cost" ;
            cout << "\n%-10d %-10s %-15s %d  %.2f\n", i+1, prd[i].ID, prd[i].nameID, prd[i].quantity, prd[i].cost ;
        
            break;
        }
        if( check == 0 && i == n-1)
        {
            cout <<"\nNot fount product have ID is " << ID;

        }
    }
}

void Search_Name (product prd[], int n, char nameID[])
{
    int check = 0;
    for(int i = 0; i < n ; i++)
    {
        if(strcmp(nameID, prd[i].nameID) == 0)
        {
            check = 1;
            cout << "\n%-10s %-10s %-15s %-10s %-10s\n", "Order", "ID", "nameID", "quantity", "cost" ;
            cout << "\n%-10d %-10s %-15s %d  %.2f\n", i+1, prd[i].ID, prd[i].nameID, prd[i].quantity, prd[i].cost ;
        
            break;
        }
        if( check == 0 && i == n-1)
        {
            cout <<"\nNot fount product have ID is " << nameID;

        }

    }
}

void Search (product prd[], int n)
{
    int select;
    char s[50];
    do
    {
        cout <<"\n\t1: ID\n\t2: NameID \n\t3: Exit search\n\t4: Enter type\n";
        cin >> select;
        gets(s);
        switch (select)
        {
            case 1:
                cout <<"\nEnter ID: ";
                char ID[50];
                gets(ID);
                Search_ID(prd, n, ID);
                break;

            case 2:
                cout <<"\nEnter nameID want search: ";
                char nameID[50];
                gets(ID);
                Search_Name(prd, n, nameID);
                break;

            case 3:
                return ;

            default:
                cout << "\nError select! ";
                break;

        }
    } while (select != 3);
    
}
