
#include <cassert>    // Provides assert
using namespace std;
//using namespace std::chrono;
 #include <iostream> 
#include <chrono> 
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
using namespace std::chrono;


int getrand(){
     srand(time(NULL));
    return std::rand()%2;
}

int** new_arr(int size ){
     int **arr;
    arr= new int*[size];

   
    for (int i = 0; i < size; i++) {
arr[i]=new int[size];
    }
  return arr;  
}





int get_neighbors(int **arr, int r, int c , int size){
    int sum=0;
    //GET TOP
    if(r>0){
        if(c<size-1){
        sum=sum+arr[r-1][c+1];  
        }
        if(c>0){
        sum=sum+arr[r-1][c-1];
        }
        sum=sum+arr[r-1][c] ;
       
    }
    //get bottom
    if(r<size-1){
        if(c<size-1){
        sum=sum+arr[r+1][c+1] ;  
        }
        if(c>0){
        sum=sum+arr[r+1][c-1] ;
        }
        sum=sum+arr[r+1][c] ;
       
    }
    //get mid
     if(c<size-1){
        sum=sum+arr[r][c+1];    
        }
        if(c>0){
        sum=sum+arr[r][c-1];
        }
       
    return sum;
}













int** one_turn(int **arr, int r, int c , int size ){
    int sum=get_neighbors(arr,  r,  c ,  size);
int isAlive=arr[r][c];
    if(isAlive==0 && sum==3){
       arr[r][c]=1;
       
    }
    else if(isAlive==1 && (sum==3 || sum==2)){
       
    }
    else{
      arr[r][c]=0;  
    }
    return arr;
}


void print_arr(int **arr, int size){
   
     for(int i=0; i<size; i++){
           
           for(int j=0; j<size; j++){
              cout<<arr[i][j];
           }
           cout<<""<<endl;
           
           
            }
   cout<<""<<endl;
   
   
}

void full_game(int **arr,int size){

for(int i=0; i<size; i++){
           
           for(int j=0; j<size; j++){
             arr=one_turn(arr,i,j,size);
             print_arr(arr,size);
           }
           cout<<""<<endl;
           cout<<""<<endl;
           
            }    
   
   
   
   
}

void full_game2(int **arr,int size){

for(int i=0; i<size; i++){
           
           for(int j=0; j<size; j++){
             arr=one_turn(arr,i,j,size);
            
           }
           //cout<<""<<endl;
          // cout<<""<<endl;
           
            }    
    print_arr(arr,size);
   
   
   
}
int main(){
     
    int size=5;    
    int choice;
        int inputmode = 0;
        int **arr;
        arr=new_arr(size);
         for(int i=0; i<size; i++){
           
           for(int j=0; j<size; j++){
               arr[i][j]=getrand();
           }
         }
       


       
       
       
       
        while(1){
                cout<<"---MAIN MENU---------"<<endl;
                cout<<"0 - Exit Program"<<endl;
                cout<<"1 - New Game"<<endl;
                cout<<"2 - Play game"<<endl;
                cout<<"3 - Full game time"<<endl;
                cout<<"Enter choice >> ";
                cin >> choice;
                if(choice == 0)
                        break;
                else if(choice == 1){
           cout<<"Enter size 0 for 5 and 1 for 10 >> ";
           cin >> choice;
                if(choice == 0){
                        size=5;
                    }
                       
                else if(choice == 1){
                size=10;
                    }
                    arr=new_arr(size);
                for(int i=0; i<size; i++){
           
           for(int j=0; j<size; j++){
               arr[i][j]=getrand();
           }
          // print_arr(arr,size);
           
           
       }    
                }
                else if(choice == 2){
              cout<<"INPUT"<<endl;
                     cout<<""<<endl;
                      cout<<""<<endl;
                    print_arr(arr,size);
            cout<<""<<endl;
               // arr=one_turn(arr,0,0,5);
                 cout<<""<<endl;
                  cout<<""<<endl;
               // print_arr(arr,size);
            cout<<"OUTPUT"<<endl;
            full_game(arr,size);
                }
               
                else if(choice == 3){
                
                    
   
    std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();
   for(int i=0; i<1; i++){
                        // full_game(arr,size);
                        full_game(arr,size);
                         
                     }
    end = std::chrono::system_clock::now();
  
    std::chrono::duration<double> time = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  
    std::cout << " time elapsed: " << time.count() << "s\n";
                    
        ///////////////////////////////////////////////            
                    
                
                     }
                     
      
                    
                else
                        cout<<"Error! Wrong Input"<<endl;
        }
       
}