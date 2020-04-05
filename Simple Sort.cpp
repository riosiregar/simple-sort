#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;
int data[100],data2[100]; //memuat array sampai dengan 100
int n, start, stop;// variable n untuk inputan manual

void tukar(int a, int b) //fungsi menukar untuk dipanggil kedalam pilihan exchange_sort
{
	int t;
	t = data [b];
	data[b] = data [a];
	data[a] = t;
}

timespec diff(timespec start, timespec end)
{
    timespec temp;
    if ((end.tv_nsec - start.tv_nsec) < 0)
		{
        	temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        	temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    	} else 
		{
        	temp.tv_sec = end.tv_sec - start.tv_sec;
        	temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    	}
    return temp;
}

void bubble_sort()
{
	for(int i=1;i<n;i++) //mengulang variable n sebagai jumlah batasan yg input oleh pengguna
	{
		for(int j=n-1;j>=i;j--)// mengulang dengan cara mengambil -1 dengan jumlah inputan lalu diproses membandingkannya dan ditukar
		{
			if(data[j]<data[j-1]) tukar(j,j-1);// proses tukar menukar untuk diurutkan dari nilai terkecil hingga terbesar
		}
	}
	cout<<"bubble sort selesai!"<<endl;// tampilan layar untuk hasil proses bubble sort
	{
	timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);
    sleep(1);
    clock_gettime(CLOCK_REALTIME, &stop);
 
    timespec duration = diff(start, stop);
    printf("lama proses sorting adalah %d.%09d s\n", duration.tv_sec, duration.tv_nsec);
	}
}
void selection_sort()
{
	int pos,i,j;
		for(i=0;i<n-1;i++) //mengulang variable n sebagai jumlah batasan yg input oleh pengguna
		{
			pos = i;
			for (j=i+1;j<n;j++)
			{
				if(data[j]<data[pos]) pos=j;// proses tukar menukar untuk diurutkan dari nilai terkecil hingga terbesar
			}
			if (pos !=i) tukar(pos,i);
		}
		cout<<"selection sort selesai"<<endl;//tampilan layar untuk hasil proses selection sort
		{
			timespec start, stop;
    		clock_gettime(CLOCK_REALTIME, &start);
    		sleep(1);
    		clock_gettime(CLOCK_REALTIME, &stop);
 
    		timespec duration = diff(start, stop);
    		printf("lama proses sorting adalah %d.%09d s\n", duration.tv_sec, duration.tv_nsec);
		}
}

void insertion_sort()
{
	int temp,i,j;
	for(i=1;i<n;i++) //mengulang variable n sebagai jumlah batasan yg input oleh pengguna
	{
		temp= data[i];
		j = i-1;
		while(data[j]>temp && j>=0)// proses tukar menukar untuk diurutkan dari nilai terkecil hingga terbesar
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=temp;
	}
	cout<<"insertion sort selesai!"<<endl;// tampilan layar untuk hasil proses insertion sort
	{
		timespec start, stop;
    	clock_gettime(CLOCK_REALTIME, &start);
    	sleep(1);
    	clock_gettime(CLOCK_REALTIME, &stop);
 
    	timespec duration = diff(start, stop);
    	printf("lama proses sorting adalah %d.%09d s\n", duration.tv_sec, duration.tv_nsec);
	}
}
void Input()
{
	cout<<"Masukan Jumlah data = ";cin>>n; //memasukan jumlah data kedalam variable n
	for(int i=0;i<n;i++)//mengulang dari jumlah data inputan variable n
	{
		cout<<"masukan data ke-"<<(i+1)<<" = "; cin>>data[i];//memasukan data dari jumlah data yg input
		data2[i]=data[i];
	}
}

void Tampil()//menampilkan kembali data yg telah diinput menggunakan variable n
{
	cout<<"Data : "<<endl;// tampilan layar Data
	for(int i=0;i<n;i++)//mengulang dari jumlah data inputan variable n
	{
		cout<<data[i]<<" ";//tampilan layar untuk hasil memunculkan data
	}
	cout<<endl;// fungsi enter satu baris kebawah
}


int main()
{
	int pil;// variable pill digunakan untuk pilihan case
	system("cls");// perintah membersihkan layar
	do// menggunakan perulangan do while
	{
		system("cls");// perintah membersihkan layar
		system("title program sorting");
		cout<<"menu sorting"<<endl;// menampilkan tulisan menu sorting ke layar
		cout<<"*****************************"<<endl;
		cout<<"1. Masukkan Code barang"<<endl;// menampilkan tulisan 1. input data sebagai tanda case 1 adalah fungsi Input
		cout<<"2. Sorting Menggunakan Bubble Sort"<<endl;// menampilkan tulisan 2. bubble sort sebagai tanda case 2 adalah fungsi bubble_sort
		cout<<"3. Sorting Menggunakan Selection sort"<<endl;// menampilkan tulisan 4. selection sort sebagai tanda case 3 adalah fungsi selection_sort
		cout<<"4. Sorting Menggunakan Insertion sort"<<endl;// menampilkan tulisan 5. insertion sort sebagai tanda case 4 adalah fungsi insertion_sort
		cout<<"5. Tampilkan Code barang yang telah tersorting"<<endl;
		cout<<"6. exit"<<endl;// menampilkan tulisan 6. exit sebagai perintah keluar jika selesai
		cout<<" pilihan anda = ";cin>>pil;// memasukan pilihan yang ingin disorting
		switch(pil)
		{
			case 1:Input(); break;//untuk memanggil fungsi input yang berada di case 1
			case 2:bubble_sort(); break; //untuk memanggil fungsi bubble_sort yg berada di case 2
			case 3:selection_sort(); break;//untuk memanggil fungsi selectio_sort yg berada di case 3
			case 4:insertion_sort(); break;//untuk memanggil fungsi insertion_sort yg berada di case 4
			cout<<"Pengurutan Selesai selesai!"<<endl;//tampilan layar hasil Quck Sort
			break;
			case 5:Tampil(); break;//untuk memanggil fungsi Tampil yg berada di case 5
		}
		
		getch();//perintah tampil layar
		}
		
		while(pil!=9);// batas perulangan sampe dengan case 9
}
