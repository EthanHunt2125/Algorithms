
#include <cassert>    // Provides assert

using namespace std;
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<cmath>
#include<iomanip>

#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream> // Provides

int getrand(){
       srand((unsigned int)time(NULL));
    return rand()%100;
}

int getrand2(){
      
    return rand()%rand()%1000;
}

int* Get_arr(int size ){
      srand((unsigned int)time(NULL));
    int * arr;
    arr= new int[size];
	
   
    
	for (int x = 0; x < size; x++) {
		 arr[x]=getrand2();
    
    }
    
    
    
    
  return arr;  
}

void printarr(int* table, int size){
    
    for(int i=0; i<size ;i++){
   
    cout << " Value  " <<table[i]<< endl;
    
    
}
    
    
}

int* sort_arr(int size,int *arr ){
     
    int inter=0;
	bool first=true;
    int swap=0;
    int j=0;
       for(int a=0; a<size/2; a++){
       
        for(int i=0; i<size; i++){
      first=true;
     //  cout << "-------------------------"<< endl;
      
     // cout << i << " Intial Value  " <<arr[i]<< endl;
     // cout << "   "<< endl;
      
	   j=i;
    for (int x = i+1; x < size; x++) {
		  
       // cout <<"arrayi " <<x << " Value  " <<arr[x]<< endl;
      
        if(arr[i]>arr[x] && first==true){
          swap++;
        //  cout << "   "<< endl;
        // cout<<"swap# "<< swap <<" i "<< i << " swap value@  " <<arr[x]<< " Intial Value  " <<arr[i]<<endl;
            inter=arr[x];
            arr[x]=arr[i];
            arr[i]=inter;
            first=false;
      /*  while(x!=j+1){
                swap++;
                inter=arr[x];
            arr[x]=arr[x-1];
            arr[x-1]=inter;
                x--;
            }
        */
        
        
        j++;
        while(arr[j]>arr[x] && j<x){
                swap++;
                inter=arr[x];
            arr[x]=arr[j];
            arr[j]=inter;
                j++;
            }
        
        
        
        
        }
    
    }
   
    }
   
   
   }
    
   printarr(arr,size);
    cout << "-------------------------"<< endl;
    cout << " swap  "<<swap<< endl;
  return arr;  
}

int* sort_arr2(int size,int *arr ){
     
    int inter=0;
	bool first=true;
    int swap=0;
    int j=0;
    int b=0;
   
    
       for(int a=0; a<size/2; a++){
        for(int i=0; i<size; i++){
      first=true;
     //  cout << "-------------------------"<< endl;
      
     // cout << i << " Intial Value  " <<arr[i]<< endl;
     // cout << "   "<< endl;
      
	  
    for (int x = i+1; x < size; x++) {
		  
       // cout <<"arrayi " <<x << " Value  " <<arr[x]<< endl;
      b=x;
        // swap++;
        if(arr[i]>arr[x] && first==true){
        swap++;
        
            inter=arr[x];
            arr[x]=arr[i];
            arr[i]=inter;
          /*  while(x!=j+1){
                swap++;
                inter=arr[x];
            arr[x]=arr[x-1];
            arr[x-1]=inter;
                x--;
            }
       
        x=b;
       
        */      
        
            swap++;
                inter=arr[x];
            arr[x]=arr[i+1];
            arr[i+1]=inter;
               
         first=false;
  
        
        
        }
    
    }
        }
    }
    
    
   
     printarr(arr,size);
cout << "-------------------------"<< endl;
   cout << " swap  "<<swap<< endl;
    
   
  return arr;  
}





int main()
{
    srand((unsigned int)time(NULL));
    int size=25;
    size=getrand();
    
    int* table=Get_arr(size);
 int* table2=Get_arr(size);
      cout << " size " <<size <<endl;
cout << "_________________________"<< endl;
//   printarr(table,size);
 cout << "_________________________"<< endl;
table2=sort_arr2(size,table2);
 cout << "_________________________"<< endl;
 //  printarr(table,size);
    cout << "_________________________"<< endl;
table=sort_arr(size,table);
    cout << "_________________________"<< endl;
 

  //  cout << "_________________________"<< endl;
//printarr(table,size);
 
   // cout << "_________________________"<< endl;
    
  //  table=sort_arr(size,table);


  //  printarr(table,size);



 return (EXIT_SUCCESS);
}