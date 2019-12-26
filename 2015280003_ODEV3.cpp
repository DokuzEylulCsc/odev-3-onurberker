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
	// dosyayý oluþturup ciftleri yazýyorum
    ofstream create("input.txt");
	
	
	fstream write;
	write.open("input.txt",ios::out);
	int soruSayisi = 10;
	
	// soru sayýsýný yazdým
	write << soruSayisi << endl ;
    
    
    
    char  cevapAnahtari[10];
    // cevap anahtarýný oluþturdum
    ostringstream str;
    for(int i = 0; i < soruSayisi ; i++)
    {
    	
    	int cevap = rand() %4 +65; // 65 -68
    	cevapAnahtari[i] = cevap;
    	
    	str << (char)cevap << ",";
    	
	}
	
	

	  
	   // karakter dizisine ceviriyorum dosyaya yazmak için
		char p[str.str().size()]; 
		int j;
        for (  j = 0; j < sizeof(p)/sizeof(*p); j++)
        p[j] = str.str()[j]; 
        p[j] = '\0';
         
		write << p << endl;
		
	 
	 //ogrencinin cevap anahtarý numaralarý ve sýnav oluþturuyorum.

	int ogrenciPuanlari[15];
	int ogrenciSayisi = 15;
	
    string ogrenciNolari[15]; 
	 vector<int> numaralar;
	for(int i = 0; i < ogrenciSayisi ; i++)
	{
		ostringstream str; //input dosyasý için
	    
		//geçerli öðrenci numarasýný oluþturdum
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
	    //ogrencinin cevabýný oluþturup aldýðý puaný hesaplattým
	    for(int j = 0; j < soruSayisi;j++)
	    {
	      int cevap = rand() %5 +65; // 65 -69
	      if(cevap == 69) // boþ cevap
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
		
		//ogrencinin sýnav notunu ekledim
		ogrenciPuanlari[i] = puan;
		
		// karakter dizisine ceviriyorum
		char p[str.str().size()]; 
        for (  j = 0; j < sizeof(p)/sizeof(*p); j++)
        p[j] = str.str()[j]; 
        p[j] = '\0';
         
         //dosyaya yazýyorum ogrencinin bilgilerini
		write << p << endl;

	}
	
 
	 //ogrenci notlarýna baðlý sýralýyorum 
	bubbleSort(ogrenciPuanlari,ogrenciNolari,15);
	

	
   // dosyayý sýralanmýþ punlarý yazýyorum
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
	
	
	
	//max min range medyan ortlama deðerlerini hesaplatýyorum
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
	// max - min - ort - medyan - açýklýk
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
