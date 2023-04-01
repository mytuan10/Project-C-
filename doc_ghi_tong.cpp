#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int n, m;

void WriteFile()
{
    FILE *fp;
    fp = fopen("test.txt", "wt");

    cout <<"\nNhap n va m : "; cin >> n >> m;
    fprintf(fp,"%d %d", n, m );                         // LUU Y  NEU DE %d%d GAN NHAU SE RA KET QUA 38 VAY LA LOI
    // luu y khoang cach %d%d
    fclose(fp);

}

void ReadFile()
{
    FILE *fp;
    fp = fopen("test.txt", "rt");

    fscanf(fp, "%d%d", &n, &m);

    int sum = n + m;
    cout <<"\nTong = " << sum;

    fclose(fp);  
}

int main()
{
    WriteFile();
    ReadFile();

    return 0;
}