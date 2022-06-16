
#include <cassert>    // Provides assert

using namespace std;
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<cmath>
#include<iomanip>
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class    
#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream> // Provides
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class    





int insertionSort(int arr[], int n)
{
    int c=0;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        c++;
        }
        arr[j + 1] = key;
        
    }
return c;
}
















int* new_arr(int size,queue<int> q ){
     int * arr;
    arr= new int[size];
	
   
    
	for (int x = 0; x < size; x++) {
		 arr[x]=q.front();
     q.pop( );
    }
  
  return arr;  
}




void showq(queue<int> gq) 
{ 
    int size=0;
    if(gq.empty()){
        
        
       return; 
    }
    cout << "new Partition "; 
    //cout << "_______________ "; 
    cout << '\n'; 
     
    queue<int> g = gq; 
    while (!g.empty()) { 
        cout << "| " << g.front() << " |"; 
        cout << '\n'; 
        g.pop(); 
        size++;
    } 
   // cout << '\n'; 
    cout <<"size of bucket " << size <<'\n'; 
    cout << '\n'; 
} 


int getrand(){
       srand((unsigned int)time(NULL));
    return rand()%100;
}

int getrand2(){
      
    return rand()%rand()%100;
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
    
queue<int> sortQ(queue<int> *arr, int size){
  int count=0;
    int i=0;
int a=0;
int b=a+1;;
    queue<int> Q;
    
    while(i<=size){
       


      
      while(b<size){
   // cout << " Value1  " << arr[a].front()<<" Qindex " << a << endl;
      //    cout << " Value2  " << arr[b].front()<<" Qindex " << b<< endl;
     //  cout << "  " << endl;
  //      cout << "  " << endl;
   

    
    if( arr[a].front() > arr[b].front() && !arr[b].empty() && !arr[a].empty()){
           
            a=b;
          b=b+1;
          
      }
       else{
           
          b++; 
           
       } 
        
        
        
        
        count++;
        
      }  
    if(!arr[a].empty())
    Q.push(arr[a].front());
   // cout << " Q  " << arr[a].front()<<" Qindex " << a << endl;
    arr[a].pop();
    a=0;
    b=a+1;
    i++;
    
    }
     cout << " count  " << count << endl;
    return Q;
    
}    
    
    
    
    
    


queue<int> bucket_sort(int size,int *arr ){
      printarr(arr,size);
      cout << "__________________________"<< endl;
    queue<int> *q= new queue<int>[size];
    queue<int> Q;
    int v;
    int size2;
    int *arr2;
    int qcount=0;
    int a=0;
    int inter=0;
	bool first=true;
    int swap=0;
    int j=0;
     
 if(size==2){
     Q.push(arr[0]);
     Q.push(arr[1]);
     return Q;
     
 }
       
     
    while(a<size){
        
         a++;
           if(arr[j]>arr[a] ){
              size2=a-j;
               v=j+1;
              // cout <<"a-j " <<size2<<endl;
               qcount++;
               arr2 = new int[size2-1];
               
               for(int z=0; z<size2-1; z++){
                    
             arr2[z]=arr[v];
           //       cout <<arr2[z] << endl; 
                v++;


                }
                q[qcount].push(arr[j]);
                
            inter=insertionSort(arr2,size2-1)+inter;
             //q[qcount]=bucket_sort(size2,arr2 );
             
               
               for(int i=0; i<size2-1; i++){
           //         cout <<arr2[i] << endl;
             q[qcount].push(arr2[i]);

                

                }
          showq(q[qcount]);
              j=a;
        
           }
       
       
        if(a == size-1 ){
            
            
            size2=a-j;
               v=j;
             
               qcount++;
               arr2 = new int[size2+1];
               
               for(int z=0; z<size2; z++){
                    
             arr2[z]=arr[v];
          
                v++;


                }
               arr2[size2]=arr[size-1];
               
              inter=insertionSort(arr2,size2+1)+inter;
              // bucket_sort(size2,arr2 );
             //  q[qcount]=bucket_sort(size2,arr2 );
               
               for(int i=0; i<size2+1; i++){
          
             q[qcount].push(arr2[i]);

                }
             
           //  q[qcount].push(arr[size-1]);
       
            j=a;
            showq(q[qcount]);
            break; 
            // q[qcount].push(arr[j]);
         //   j=j+1;
           
        }
   
   
   }
      
      
      
      
      

   
int p=0;
      
    while(p<size){
//cout << "-------------------------"<< endl;         
// sortQueue(q[p]);
//showq(q[p]);
//cout << "__________________________"<< endl;       
          p++;
      }  
cout << "__________________________"<< endl; 
Q=sortQ(q,size);

showq(Q);




cout << " Max # of swaps for all buckets  " <<inter<< endl;
cout << " size  " <<size<< endl;



    
  return Q;  
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
    
    
   
     //printarr(arr,size);
cout << "-------------------------"<< endl;
 //  cout << " swap  "<<swap<< endl;
    
   
  return arr;  
}





int main()
{
    int size=getrand();
    
    //size=10;
   bucket_sort(size,Get_arr(size)); 
    
    
    


 return (EXIT_SUCCESS);
}