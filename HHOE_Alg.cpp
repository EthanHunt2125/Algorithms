#include <stdio.h>
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








int gethashKey(int key){
    
    return key%50;
}


int gethashKey2(int key, int value, int size){
      
    return (key*value)%size;
}


char* get_plain_text(int size,char* key_table, int table_size){
  char* text = new char[size];  
    for(int i=0; i<size; i++){
        
        text[i]=key_table[rand()%table_size];
        
    }
    
    
    return text;
}

void print_int(int* text, int size){
   
   for(int i=0; i<size; i++){
   
   cout<<""<<text[i] <<" ";
}   
    cout<<""<< endl; 
    
    
    
}

void print_char(char* text, int size){
    
   for(int i=0; i<size; i++){
   
   cout<<text[i];
}   
    cout<<""<< endl; 
    
    
    
}



int getrand(){
      
    return rand()%50;
}


int sumprobe(int sum, int probe){
    
    
    
    return sum+probe;
}





int* digitsplit2(int* A, int a, int* B, int b , int Da, int Db){
 
  int c=a+b;
   
    int* C= new int[c];
   for(int i=0; i<c ;i++){
            C[i]=0;
            
        }
    int j=0; int z=0; int n=1; int Ac=0; int Bc=0;  //Da=2; // Db=3;
   
    for(int i=0; i<c; i=i){
       
        Ac=0;
        Bc=0;
       
        if(n%2==1){
     //     cout<<"char"<<endl;
        while(Ac<Da){
        //cout<<A[j]<<endl;    
       
        C[i]=A[j];
       
       //  cout<<i <<": " <<A[j]<<"  "  <<endl;
          i++;  
          j++;
          Ac++;
             
          }  
         
         
         
          }

 
          else{
           
        //    cout<<"mod"<<endl;  
        while(Bc<Db){
         
        C[i]=B[z];
         //  cout<<i <<": " <<B[z]<<"  " <<endl;
          i++;
          z++;
          Bc++;
             
             
                       }    
            }  
       
          n++;  
        }
       
       
       
   
       
       
       
       
       
       
   
    
    return C;
    
    
}
int* get_values2(int* shift_text,int vp, int size, int ogsize){
    
     int* new_text= new int[vp*ogsize];
    
    for(int i=0; i<size ;i++){
            new_text[i]=0;
            
        }
    int j=0; int z=(vp*ogsize); int n=1; int Ac=0; int Bc=0;  //Da=2; // Db=3;
   
    for(int i=0; i<vp*ogsize; i=i){
       
        Ac=0;
        Bc=0;
       
        if(n%2==1){
     //     cout<<"char"<<endl;
        while(Ac<vp){
        //cout<<A[j]<<endl;    
       
        new_text[i]=shift_text[j];
       
       //  cout<<i <<": " <<A[j]<<"  "  <<endl;
          i++;  
          j++;
          Ac++;
             
          }  
         
         
         
          }
    }
    
     return new_text; 
    
}

int* Shift_Text(int* en_text, int vp, int keyp, int size, int ogsize){
    
    int* new_text= new int[size];
    
    for(int i=0; i<size ;i++){
            new_text[i]=0;
            
        }
    int j=0; int z=(vp*ogsize); int n=1; int Ac=0; int Bc=0;  //Da=2; // Db=3;
   
    for(int i=0; i<size; i=i){
       
        Ac=0;
        Bc=0;
       
        if(n%2==1){
     //     cout<<"char"<<endl;
        while(Ac<vp){
        //cout<<A[j]<<endl;    
       
        new_text[i]=en_text[j];
       
       //  cout<<i <<": " <<A[j]<<"  "  <<endl;
          i++;  
          j++;
          Ac++;
             
          }  
         
         
         
          }

 
          else{
           
        //    cout<<"mod"<<endl;  
        while(Bc<keyp){
         
        new_text[z+i]=en_text[j];
         //  cout<<i <<": " <<B[z]<<"  " <<endl;
          i++;
          j++;
          Bc++;
             
             
                       }    
            }  
       
          n++;  
        }
       
       
       
   
       
    
    
    
    
  return new_text;  
    
    
    
}

int* digitsplit(int* Values, int digitnum, int size){
   

    
 int value=0;
 int* digits=new int[size*digitnum];
 
    int value_new=value;
    int decmial_power=1;
    int count=0;
    for(int k=0; k<size*digitnum; k=k){
     value=Values[count];
     value_new=value;
  
    for(int i=0; i<digitnum; i++){
        
        value=value_new;
        //power of ten
        
        for(int j=digitnum-i; j>1; j--){
        decmial_power=decmial_power*10;
           
        }
       
        value_new=value%decmial_power;
         
        digits[k]=(value-value_new)/decmial_power;
       // cout<<value<<" " <<value_new << " "<< k <<"  " <<digits[k] <<endl;
        decmial_power=1;
        k++;
    }
    //digits[k]=value;
   count++;
    }

   /* for(int i=0; i<digitnum*size; i++){
        
     cout<< " "<< digits[i];   
        
    }
    cout<<endl;
    */
    
    return digits;
    
    
    
    
}


int* encrypt_hash_with_size(int* keys, int* plain_text, int size, int keyp, int vp){
    int size_in_char=(vp+(keyp+vp-1))*size;
    int hashkey=0;
    int* value=new int[size];
    int* mod_order=new int[size];
    int* encrypted_text=new int[size_in_char];
    int count=0;
        for(int i=0; i<size ;i++){
            value[i]=0;
            
        }
        
        
        for(int i=0; i<size ;i++){
            
            hashkey = gethashKey2(keys[i],plain_text[i],size);
        mod_order[i]=hashkey*keys[i];
       
    while(value[hashkey]>0){
           
            
            hashkey++;
           
            if(hashkey>=size){
                hashkey=0;
            }
        }
       
        value[hashkey]=plain_text[i];
        }
 
    
   value= digitsplit(value,vp,size);
   mod_order=digitsplit(mod_order,(keyp+vp-1),size);
    
    
    
    encrypted_text=digitsplit2(value,vp*size,mod_order,(keyp+vp-1)*size,vp,(keyp+vp-1));
    
    return encrypted_text;  
}


int* digitscombine(int* digits, int digitnum, int size){
   

   
 int value=0;
 int* Values=new int[size/digitnum];
 
    int value_new=value;
    int decmial_power=1;
    int count=0;
    for(int k=0; k<size/digitnum; k++){
     Values[k]=0;
   
    }
   
   
    for(int k=0; k<size/digitnum; k++){
     
   
 
    for(int i=0; i<digitnum; i++){
        value=digits[count];
    // cout<<digits[count]<<" ";
        //power of ten
       
        for(int j=digitnum-i; j>1; j--){
        decmial_power=decmial_power*10;
           
        }
       
       
         
        Values[k]=(value*decmial_power)+Values[k];
      //  cout<<value<<" "<< " : "<< k <<" : " <<Values[k] <<endl;
        decmial_power=1;
        count++;
    }
    //digits[k]=value;
   
    }

   /* for(int i=0; i<digitnum*size; i++){
       
     cout<< " "<< digits[i];  
       
    }
    cout<<endl;
    */
   
    return Values;
   
   
   
   
}


int* getvalues(int* A, int size){
 
int* Values= new int[size/2];
 
 for(int k=0; k<size/2; k++){
     Values[k]=0;
   
    }
 
 int j=0;
 for(int i=0; i<size/2; i++){
 Values[i]=A[j];

 j=j+2;

 
 }
 
return Values;
   
   
}


int* getModOrder(int* A, int size){
 
 int* ModOrder= new int[size/2];
 
 for(int k=0; k<size/2; k++){
     ModOrder[k]=0;
   
    }
 
 int j=1;
 for(int i=0; i<size/2; i++){
 ModOrder[i]=A[j];
j=j+2;
 

 
 }
 
return ModOrder;
   
   
}


int* digitcombine2(int* A, int size, int* B){
 
 int* combine= new int[2*size];
 
 for(int k=0; k<2*size; k++){
     combine[k]=0;
   
    }
 
 int j=0;
 for(int i=0; i<2*size; i=i+2){
 combine[i]=A[j];
 combine[i+1]=B[j];
 j++;

 
 }
return combine;
   
   
}


void HF1(){
    /*
    int keys[] = {1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299,
                  5078, 8239, 1208, 5098, 5195, 5329, 4543, 3344, 7698, 5412,
                  5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589,
                  5439, 8907, 4097, 3096, 4310, 5298, 9156, 3895, 6673, 7871,
                  5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523};
   
   */
   
   
   
   int keys[] = {123, 823, 786, 109, 543, 431, 342, 948, 541, 529,
                  507, 238, 120, 509, 519, 532, 454, 334, 769, 541,
                  556, 562, 793, 125, 609, 873, 309, 197, 384, 558,
                  543, 890, 409, 309, 431, 529, 915, 389, 667, 787,
                  578, 928, 455, 782, 875, 339, 677, 828, 765, 553};
                  
    int value[] ={8,2,1,3,7,9,12,25,13,17,
                  4,10,19,11,20,26,21,24,12,5,
                  7,15,16,23,18,22,6,10,21,26,
                  15,9,14,20,16,5,14,6,10,1,
                  9,14,6,20,5,14,6,16,1,2} ;                                                     
    
    
    
    int hash_order[50];
    int sum=0;
    int table[50][2];
    for(int i=0; i<50 ;i++){
        
    table[i][0]=0; //value
    table[i][1]=0; //probe
    
    
}
    int size=50;
    int hashkey=0;
    int probe=0;
    for(int i=0; i<50 ;i++){
       // cout << "key " <<keys[i] <<endl;
      //  cout << "hkey " <<gethashKey(keys[i]) <<endl;
        hashkey = gethashKey2(keys[i],value[i],size);
        hash_order[i]=hashkey*keys[i];
        while(table[hashkey][0]>0){
           // cout << "p " <<probe <<endl;
           probe++;
            
            hashkey++;
            if(hashkey>=50){
                hashkey=0;
            }
        }
        
            
             table[hashkey][0]=value[i];
             table[hashkey][1]=probe;
             probe=0;
        
        
    }
    
    
     cout << "Index Key probes  " <<endl;
     cout << "------------------------ " <<endl;
    for(int i=0; i<50 ;i++){
    sum=sumprobe(sum,table[i][1]);
    cout << i << "  " <<table[i][0]<<"  "<<table[i][1] <<endl;
    
    
}
 cout << "------------------------ " <<endl;
 

 cout << "Sum " <<sum <<endl;

for(int i=0; i<50 ;i++){
    
   cout << " " <<table[i][0]<<" "<<hash_order[i] ;
    
    
}


cout<<endl;

int index1=0;
int index2=0;
for(int i=0; i<50;i++){
    index1=hash_order[i]/keys[i];
    index2=index1;
    //cout<< "  |"<< (hash_order[i]*keys[i])%50 <<"|";
   
    while( ((table[index1][0]*keys[i])%50) !=  index2){
    // cout<< " "<<endl;
        index1++;
        
        if(index1>=50){
               index1=0;
            }
   
    }
    cout << " " <<table[index1][0];
   //  cout <<":" << ((table[index1][0]*keys[i])%50);
}

cout<<endl;














}


int recursive_text(int* text_int , int index){
   // cout<<text_int[index];
    if(index==0){
     //  cout<<  endl;
        return text_int[0]+1;
     
        
    }
   // cout<< " + ";
    return recursive_text( text_int ,  index-1)+text_int[index];
    
    
    
    
}


int* Obscure_text( int* text_int , int size){
    int x;
    int* new_text_int=new int[size];
    for(int i=size-1; i>-1 ;i--){
  x=recursive_text( text_int ,  i);
    if(x%26==0){
      new_text_int[i]=1;  
    }
      else{
      new_text_int[i]=x%26;  
    }
    
   }
    
for(int i=0; i<size; i++){
   
   //cout<<new_text_int[i]<<" ";
}   
   // cout<<""<< endl;
    
  return new_text_int;  
    
}




int* Char_to_int2(char* text_char, int size, char* key_table, int table_size){
int* text_int=new int[size]; 

for(int i=0; i<size; i++){
    
    for(int j=0; j<table_size; j++){
        if(text_char[i]==key_table[j]){
            text_int[i]=j;
            
        }
        
        
        
        
    }
    
    
    
    
    
}

 return text_int;  
    
}



int* Char_to_int(char* text_char, int size, int* key_table){
  for(int i=0; i<40; i++){
   
   cout<<text_char[i]<<" ";
}   
    cout<<""<< endl;

    int j=0;
    int* text_int=new int[size];
    for(int i=0; i<size; i++){
    j=0;
    cout<<text_char[i]<<endl;
     if(text_char[i]=='a'){
       // cout<<"a"<< endl;
           
        text_int[i]=1;
        }
    
     if(text_char[i]=='b'){
       // cout<<"b"<< endl;
            
        text_int[i]=2;
        }
     if(text_char[i]=='c'){
      //  cout<<"c"<< endl;
            
        text_int[i]=3;
        }
    
     if(text_char[i]=='d'){
       // cout<<"d"<< endl;
           
        text_int[i]=4;
        }
        
        if(text_char[i]=='e'){
      //  cout<<"e"<< endl;
           
        text_int[i]=5;
        }
        
         if(text_char[i]=='f'){
       // cout<<"f"<< endl;
           
        text_int[i]=6;
        }
        
         if(text_char[i]=='g'){
     //   cout<<"g"<< endl;
           
        text_int[i]=7;
        }
        
         if(text_char[i]=='h'){
        //cout<<"h"<< endl;
            
        text_int[i]=8;
        }
         if(text_char[i]=='i'){
      //  cout<<"i"<< endl;
           
        text_int[i]=9;
        }
        
         if(text_char[i]=='j'){
       // cout<<"a"<< endl;
           
        text_int[i]=10;
        }
    
     if(text_char[i]=='k'){
       // cout<<"b"<< endl;
            
        text_int[i]=11;
        }
     if(text_char[i]=='l'){
      //  cout<<"c"<< endl;
            
        text_int[i]=12;
        }
    
     if(text_char[i]=='m'){
        //cout<<"d"<< endl;
           
        text_int[i]=13;
        }
        
        if(text_char[i]=='n'){
        //cout<<"e"<< endl;
           
        text_int[i]=14;
        }
        
         if(text_char[i]=='o'){
       // cout<<"f"<< endl;
           
        text_int[i]=15;
        }
        
         if(text_char[i]=='p'){
       // cout<<"g"<< endl;
           
        text_int[i]=16;
        }
        
         if(text_char[i]=='q'){
       // cout<<"h"<< endl;
            
        text_int[i]=17;
        }
         if(text_char[i]=='r'){
      //  cout<<"i"<< endl;
           
        text_int[i]=18;
        }
       if(text_char[i]=='s'){
       // cout<<"i"<< endl;
           
        text_int[i]=19;
        }
        
         if(text_char[i]=='t'){
       // cout<<"a"<< endl;
           
        text_int[i]=20;
        }
    
     if(text_char[i]=='u'){
       // cout<<"b"<< endl;
            
        text_int[i]=21;
        }
     if(text_char[i]=='v'){
      //  cout<<"c"<< endl;
            
        text_int[i]=22;
        }
    
     if(text_char[i]=='w'){
        //cout<<"d"<< endl;
           
        text_int[i]=23;
        }
        
        if(text_char[i]=='x'){
        //cout<<"e"<< endl;
           
        text_int[i]=24;
        }
        
         if(text_char[i]=='y'){
        //cout<<"f"<< endl;
           
        text_int[i]=25;
        }
        
         if(text_char[i]=='z'){
       // cout<<"g"<< endl;
           
        text_int[i]=26;
        }
       
       
       
       
       
       
       
       
       
       
       
       
        
    }

return text_int;

}


char* arr_to_string(int* arr, int size){
   char* x=new char[size]; 
    char* alpha_table= new char[27];
alpha_table[0]='_';
alpha_table[1]='a';  
alpha_table[2]='b';
alpha_table[3]='c';
alpha_table[4]='d';
alpha_table[5]='e';
alpha_table[6]='f';
alpha_table[7]='g';
alpha_table[8]='h';
alpha_table[9]='i';
alpha_table[10]='j';
alpha_table[11]='k';
alpha_table[12]='l';
alpha_table[13]='m';
alpha_table[14]='n';
alpha_table[15]='o';
alpha_table[16]='p';
alpha_table[17]='q';
alpha_table[18]='r';
alpha_table[19]='s';
alpha_table[20]='t';
alpha_table[21]='u';
alpha_table[22]='v';
alpha_table[23]='w';
alpha_table[24]='x';
alpha_table[25]='y';
alpha_table[26]='z';

for(int i=0; i<size; i++){
    int j=arr[i];
   
 x[i]=alpha_table[j];
cout<<x[i];    
    
    
    
    
}
cout<<endl;


    
    
   return x; 
    
    
}


int* decrypt_hash(int* table, int* hash_order, int* keys, int size){
 
  int* text= new int[size];
  int* mods= new int[size];
int* next= new int[size];
  for(int i=0; i<size; i++){
   text[i]=0;
    next[i]=0;
      
  }
  int count=0;
  int index=0;
  
  for(int i=0; i<size; i++){
      
      index=hash_order[i]/keys[i];
     // cout<<i <<" "<<index<<" "<<table[index] <<" ||";
      count=0;
      while(next[index] == 1){
          count++;
          index++;
          if(index>=size){
              
              index=0;
          }
       
       
       if(count>2*size){
      //   cout<<i<<" break"<<endl;
           break;
           
       }        
     
 }
 
  if(index>=size){
              
              index=0;
          }
 // cout<<i <<" "<<index<<" "<<table[index] <<" " <<endl;
   next[index]=1;
  text[i]=table[index];
  }
  
 
 
 
   
   
   
   
   
   
  return text;  
   
}











int* get_keys(int size, int keyp){
 int* keys;
int p10=1;
  
     for(int j=keyp; j>1; j--){
        p10=p10*10;
           
        }
   for(int i=0; i<size;i++){
     
    keys[i]=rand()%p10;
    
}   
return keys; 
    
}

/*
 int* key_table=new int[26]; 
char* alpha_table= new char[26];
int* text_int=new int[10];
int* new_text_int=new int[10];
for(int i=0; i<26; i++){
   key_table[i]=i+1; 
    
}

for(int i=0; i<10; i++){
   
   text_int[i]=0;
}   
    //cout<<""<< endl;
    for(int i=0; i<26; i++){
   
   //cout<<key_table[i];
}   
   // cout<<""<< endl;



string text="helloworld";

cout<<text<<endl;
text_int= Char_to_int(text,10,key_table);

 for(int i=0; i<10; i++){
   
   cout<<text_int[i]<<" ";
}   
    cout<<""<< endl;

text_int=Obscure_text(text_int,10);

int* keys=new int[10];

for(int i=0; i<10;i++){
     srand((unsigned int)time(NULL));
    keys[i]=rand()%1000;
    
}   


for(int i=0; i<10; i++){
   
   cout<<text_int[i]<<" ";
}   
    cout<<""<< endl;



for(int i=0; i<10;i++){
     
    keys[i]=rand()%10;
    
}   

for(int i=0; i<10;i++){
     
    //cout<<keys[i]<<" ";
    
}   
 //cout<<""<< endl;
int* text2= encrypt_hash(keys,text_int,10);
    for(int i=0; i<20;i++){
        
      cout<<text2[i]<<" ";
}   
    cout<<""<< endl;
  
//text2= encrypt_hash_with_size(keys,text_int,10,2,3);
//srand((unsigned int)time(NULL));
//int test=rand()%100;
//test=512;

//text_int= Char_to_int(text,10,key_table);

//int* digits= digitsplit(text_int,2,10);
int* digits=encrypt_hash_with_size(keys,text_int,10,1,2);
for(int i=0; i<(2+(1+2-1))*10;i++){
        
       cout<<digits[i]<<" ";
}   
    cout<<""<< endl;

string text3= arr_to_string(digits,40);


 for(int i=0; i<40; i++){
   
   cout<<text3[i]<<" ";
}   
    cout<<""<< endl;

text_int= Char_to_int(text3,40,key_table);

 for(int i=0; i<40; i++){
   
   cout<<text_int[i]<<" ";
}   
    cout<<""<< endl;

    //HF1();
    */





int* encrypt_hash2(int* keys, int* plain_text, int size){
    int* values= new int[size];
    int hashkey=0;
    int* mod_order=new int[size];
    int* encrypted_text=new int[2*size];
        for(int i=0; i<size ;i++){
            values[i]=0;
            
        }
        
        
        for(int i=0; i<size ;i++){
            
            hashkey = gethashKey2(keys[i],plain_text[i],size);
        mod_order[i]=hashkey*keys[i];
       // cout<<" key "<< keys[i]<<" text "<<plain_text[i] <<" hashkey " << hashkey << " mod order " << mod_order[i]<< endl;
        while(values[hashkey]>0){
           
            
            hashkey++;
            //hashkey++;
            if(hashkey>=size){
                hashkey=0;
            }
        }
        values[hashkey]=plain_text[i]+keys[i];
        
        
       
 
    int j=0;
    for(int i2=0; i2<2*size; i2=i2+2){
    encrypted_text[i2]=values[j];
    encrypted_text[i2+1]=mod_order[j];
    j++;
    }
        //    
        
           // cout << mod_order[i]<< endl;
           //encrypted_text= digitcombine2(values,size,mod_order);
            
            
        }
 
    
    
    
    
    return encrypted_text;  
}



int* decrypt_hash2(int* table, int* hash_order, int* keys, int size){
 
  int* text= new int[size];
  int* mods= new int[size];
int* next= new int[size];
  for(int i=0; i<size; i++){
   text[i]=0;
    next[i]=0;
      
  }
  int count=0;
  int index=0;
  
  for(int i=0; i<size; i++){
      
      index=hash_order[i]/keys[i];
     // cout<<i <<" "<<index<<" "<<table[index] <<" ||";
      count=0;
      while(next[index] == 1){
          count++;
          index++;
          if(index>=size){
              
              index=0;
          }
       
       
       if(count>2*size){
      //   cout<<i<<" break"<<endl;
           break;
           
       }        
     
 }
 
  if(index>=size){
              
              index=0;
          }
 // cout<<i <<" "<<index<<" "<<table[index] <<" " <<endl;
   next[index]=1;
  text[i]=table[index]-keys[i];
  }
  
 
 
 
   
   
   
   
   
   
  return text;  
   
}










int* encrypt_hash(int* keys, int* plain_text, int size){
    int* values= new int[size];
    int hashkey=0;
    int* mod_order=new int[size];
    int* encrypted_text=new int[2*size];
        for(int i=0; i<size ;i++){
            values[i]=0;
            
        }
        
        
        for(int i=0; i<size ;i++){
            
            hashkey = gethashKey2(keys[i],plain_text[i],size);
        mod_order[i]=hashkey*keys[i];
       // cout<<" key "<< keys[i]<<" text "<<plain_text[i] <<" hashkey " << hashkey << " mod order " << mod_order[i]<< endl;
        while(values[hashkey]>0){
           
            
            hashkey++;
            //hashkey++;
            if(hashkey>=size){
                hashkey=0;
            }
        }
        values[hashkey]=plain_text[i];
        
        
       
 
    int j=0;
    for(int i2=0; i2<2*size; i2=i2+2){
    encrypted_text[i2]=values[j];
    encrypted_text[i2+1]=mod_order[j];
    j++;
    }
        //    
        
           // cout << mod_order[i]<< endl;
           //encrypted_text= digitcombine2(values,size,mod_order);
            
            
        }
 
    
    
    
    
    return encrypted_text;  
}




int validate(int* ogint, int* newint, int size){
    
    for(int i=0; i<size; i++){
        if(ogint[i] != newint[i]){
            
            return 0;
        }
        
        
        
    }
    
    
    return 1;
}





int main()
{

    
    
int vp=2;
int keyp=3;
int size=rand()%50;    
int size_in_char=(vp+(keyp+vp-1))*size;
char* text_char= new char[size];
int* text_int= new int[size];
int* ogtext_int= new int[size];
char* ogtext_char= new char[size];
int choice=0;
int inputmode = 0;
char* alpha_table= new char[27];
int* keys;
int* order;
int* values;
alpha_table[0]='_';
alpha_table[1]='a';  
alpha_table[2]='b';
alpha_table[3]='c';
alpha_table[4]='d';
alpha_table[5]='e';
alpha_table[6]='f';
alpha_table[7]='g';
alpha_table[8]='h';
alpha_table[9]='i';
alpha_table[10]='j';
alpha_table[11]='k';
alpha_table[12]='l';
alpha_table[13]='m';
alpha_table[14]='n';
alpha_table[15]='o';
alpha_table[16]='p';
alpha_table[17]='q';
alpha_table[18]='r';
alpha_table[19]='s';
alpha_table[20]='t';
alpha_table[21]='u';
alpha_table[22]='v';
alpha_table[23]='w';
alpha_table[24]='x';
alpha_table[25]='y';
alpha_table[26]='z';


       
       
       
       
        while(1){
                cout<<"---MAIN MENU---------"<<endl;
                cout<<"0 - Exit Program"<<endl;
                cout<<"1 - New test Message"<<endl;
                cout<<"2 - Encrypt Message"<<endl;
                cout<<"3 - Decrypt Message"<<endl;
                cout<<"4 - Validate Message"<<endl;
                cout<<"Enter choice >> ";
                cin >> choice;
                
                if(choice == 0)
                        break;
                
                else if(choice == 1){
               size=rand()%50;
              // size=100;
                
                for(int i=0; i<size; i++){
        
                text_char[i]=alpha_table[(rand()%26)+1];
               }
               
               
               //text_char=get_plain_text(size,alpha_table,27);
               ogtext_char=text_char;
               print_char(text_char,size);
               text_int=Char_to_int2(text_char,size,alpha_table,27);
               ogtext_int=text_int;
             //  print_int(text_int,size);
               
                }
                
                
                
                else if(choice == 2){
                
                    
                    
                //text_int=Obscure_text(text_int,size); 
                //keys=get_keys(size,keyp);
                keys=new int[size];
                
                for(int i=0; i<size; i++){
                    
                    
                    keys[i]=(rand()%10)+1;
                    if(keys[i]==size){
                        keys[i]=7;
                        
                    }
                    
                }
                
                
                text_int=encrypt_hash2(keys,text_int,size);    
           /// size_in_char=(vp+(keyp+vp-1))*size;    
          //  text_char=arr_to_string(text_int,size*2);
            //print_char(text_char,size*2);
         //  print_int(text_int,2*size);
                }
                
                else if(choice == 3){
               values=getvalues(text_int,size*2);
               order=getModOrder(text_int, size*2);
               text_int=decrypt_hash2(values,order,keys,size);
            //print_int(values,size);
                
            print_int(keys,size);
              //  
              //  print_int(order,size);
                
              text_char=arr_to_string(text_int,size);
                //print_char(text_char,size);
              //  print_int(text_int,size);
                
                }
  
    
     else if(choice == 4){
      
   cout<< "Holds intergrity: "<< validate(ogtext_int, text_int,size) << endl;



   
         
     }

    
    
    
    
    
    else if(choice == 5){
               size=3;
              // size=100;
                for(int i=0; i<size; i++){
        
                text_char[i]=alpha_table[i+1];
               }
               
               
               //text_char=get_plain_text(size,alpha_table,27);
               ogtext_char=text_char;
               print_char(text_char,size);
               text_int=Char_to_int2(text_char,size,alpha_table,27);
               ogtext_int=text_int;
             //  print_int(text_int,size);
               
                
                }
    
    }

    






}