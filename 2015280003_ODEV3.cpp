#include<iostream>
#include<time.h>
#include<fstream>
#include <sstream>
#include <vector> 
#include <string.h> 
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],string nolar[], int len);
main()
{
    
      srand(time(NULL));
	// dosyay� olu�turup ciftleri yaz�yorum
    ofstream create("input.txt");
	
	
	fstream write;
	write.open("input.txt",ios::out);
	int soruSayisi = 10;
	
	// soru say�s�n� yazd�m
	write << soruSayisi << endl ;
    
    
    
    char  cevapAnahtari[10];
    // cevap anahtar�n� olu�turdum
    ostringstream str;
    for(int i = 0; i < soruSayisi ; i++)
    {
    	
    	int cevap = rand() %4 +65; // 65 -68
    	cevapAnahtari[i] = cevap;
    	
    	str << (char)cevap << ",";
    	
	}
	
	

	  
	   // karakter dizisine ceviriyorum dosyaya yazmak i�in
		char p[str.str().size()]; 
		int j;
        for (  j = 0; j < sizeof(p)/sizeof(*p); j++)
        p[j] = str.str()[j]; 
        p[j] = '\0';
         
		write << p << endl;
		
	 
	 //ogrencinin cevap anahtar� numaralar� ve s�nav olu�turuyorum.

	int ogrenciPuanlari[15];
	int ogrenciSayisi = 15;
	
    string ogrenciNolari[15]; 
	 vector<int> numaralar;
	for(int i = 0; i < ogrenciSayisi ; i++)
	{
		ostringstream str; //input dosyas� i�in
	    
		//ge�erli ��renci numaras�n� olu�turdum
		str << "N00000";
	
		while(true)
		{
			
		
		int ogrenciNo = rand() % 100 +1 ;
		if(!std::count(numaralar.begin(), numaralar.end(), ogrenciNo))
		{
			numaralar.push_back(ogrenciNo);
			str<<ogrenciNo<<",";
		    ogrenciNolari[i] = "N00000" +to_string(ogrenciNo);
		   
			break;
			
		}
		
	    }
	    
	    
	    int puan = 0;
	    //ogrencinin cevab�n� olu�turup ald��� puan� hesaplatt�m
	    for(int j = 0; j < soruSayisi;j++)
	    {
	      int cevap = rand() %5 +65; // 65 -69
	      if(cevap == 69) // bo� cevap
	      {
	      	str << ",";
		  }
    	  else str << (char)cevap << ",";
    	  
    	  if(cevapAnahtari[j] == (char)cevap)
    	  {
    	  	puan +=4;
		  }
		 else{
		 	
		 	if(cevap != 69)
		 	puan-=1;
		 }
		  
    	  /* if(i == 0)
		  cout << cevapAnahtari[j] << "  =  " << (char)cevap <<"  PUAN : " << puan<< endl; */
		}
		
		if(puan  < 0) puan = 0;
		
		//ogrencinin s�nav notunu ekledim
		ogrenciPuanlari[i] = puan;
		
		// karakter dizisine ceviriyorum
		char p[str.str().size()]; 
        for (  j = 0; j < sizeof(p)/sizeof(*p); j++)
        p[j] = str.str()[j]; 
        p[j] = '\0';
         
         //dosyaya yaz�yorum ogrencinin bilgilerini
		write << p << endl;

	}
	
 
	 //ogrenci notlar�na ba�l� s�ral�yorum 
	bubbleSort(ogrenciPuanlari,ogrenciNolari,15);
	

	
   // dosyay� s�ralanm�� punlar� yaz�yorum
    ofstream createOut("output.txt");
	
	
	fstream writeOut;
	writeOut.open("output.txt",ios::out);
	
	for(int i = 0; i < 15 ;i++)
	{
	    ostringstream str;
		
		str <<ogrenciNolari[i] << "," << ogrenciPuanlari[i] << endl;
		
		// karakter dizisine ceviriyorum
		char p[str.str().size()]; 
        for (  j = 0; j < sizeof(p)/sizeof(*p); j++)
        p[j] = str.str()[j]; 
        p[j] = '\0';
        writeOut << p ;
	}
	
	
	
	//max min range medyan ortlama de�erlerini hesaplat�yorum
	int min = INT_MAX;
	int max = INT_MIN;
	double sum = 0.0;
	
	for(int i = 0; i < 15 ; i++)
	{
		if(min > ogrenciPuanlari[i] )
		min = ogrenciPuanlari[i];
		
		if(max < ogrenciPuanlari[i] )
		max = ogrenciPuanlari[i];
		
		sum += ogrenciPuanlari[i];
		
	}
	
	ostringstream str2;
	// max - min - ort - medyan - a��kl�k
	str2 << max << "," << min << "," << (sum / 15.0) << ","  << ogrenciPuanlari[7] << "," << (max - min) ;
	
	
		// karakter dizisine ceviriyorum
		 p[str2.str().size()]; 
        for (  j = 0; j < sizeof(p)/sizeof(*p); j++)
        p[j] = str2.str()[j]; 
        p[j] = '\0';
        writeOut << p << endl;
	
	

	
}

void bubbleSort(int arr[] , string nolar[], int len )
{
	int temp;
	string s;
	for(int i = 0 ; i < len - 1 ;i ++)
	{
		for(int j = 0; j < len - 1 - i;j++)
		{
			if(arr[j+1] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
		        	swap (nolar[j],nolar[j+1]);

			}
		}
	}
	
}
