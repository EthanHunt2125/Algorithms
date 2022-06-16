#include <stdio.h>
#include <time.h>       /* time */
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;
#include <stdio.h>
#include<cmath>
#include<iomanip>
#include <bits/stdc++.h>
#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream> // Provides cout and cin
#include <stdlib.h>     /* srand, rand */


 int  myMax(int* a, int size) {
       int max = a[0];
       for(int i=1; i < size; i++)
          if ( a[i] > max)
                max = a[i];

    return max; 
  }

int  myMin(int* a, int size) {
       int min = a[0];
       for(int i=1; i < size; i++)
          if ( a[i] < min)
                min = a[i];

    return min; 
  }

 double myAvg(int* a, int size) {
     int n = size;
     double sum = 0;
     for (int i=0; i < n; i++)
         sum += a[i];

     double average = sum /n;
     return average; 
    }

int* myCopy(int *a, int size) {
          int n = size;
          int * b = new int[n];
          for(int i=0; i < n; i++)
             b[i] = a[i];

      return b; 
    }

void reverse(int *arr, int x){
    
    if(x==0){
        
        
        cout << arr[x] << " "; 
        
        
      return;
    }
    
    else{
        
     cout << arr[x] << " ";   
        x--;
        return reverse(arr,x);
    }
    cout << endl;
    
}






int* Get_arr(int size ){
      srand((unsigned int)time(NULL));
    int * arr;
    arr= new int[size];
	
     
   
    
	for (int x = 0; x < size; x++) {
		 arr[x]=rand()%100;;
    
    }
    
    
    
    
  return arr;  
}


int* myReverse(int* a, int size) {
       int n = size;
       for (int i = 0; i < n/2; i++) {
          int temp = a[i];
          a[i] = a[n- i-1];
          a[n - i - 1] = temp;  

      }

   }


void printNumbers(int *arr, int size){
      for(int i=0; i < size; i++){
          cout << arr[i] << " ";  
      }
        cout << endl;
       }

 bool isPrime(long num) {
       if ( num < 2) return false;
       for (long i = 2; i * i <= num; i++)
              if ( num % i == 0) return false;
       return true;
 
    }

  void printPrimeNumbers(int* a, int size){
      for (int i=0; i < size; i++){
         if (isPrime(a[i])){
           cout << a[i] << " ";   
         }
            
    } 
   cout << endl;
  }




int main()
{


int size=rand()%100;
    int* numbers = Get_arr(size);
        int highest;
        int lowest;
        double avg;
        highest =  myMax(numbers,size);
        avg = myAvg(numbers,size);
 
    cout<<"The highest number "<< highest<<endl; 
       cout<< "The average of the numbers: " << avg <<endl;
 
        int* outNumbers = myCopy(numbers,size);

        cout<<"The oroginal array"<<endl;
        printNumbers(outNumbers,size);

        myReverse(outNumbers,size);

        cout<<"The reverse array"<<endl;
        printNumbers(outNumbers,size);
         
       cout<<"These are the prime numbers in the array"<<endl;
        printPrimeNumbers(outNumbers,size);
    
    
    
    
    
    
    
    
    
    
    
    

return 0;	
}
