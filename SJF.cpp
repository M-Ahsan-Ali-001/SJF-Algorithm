#include <iostream>
#include<iomanip>
using namespace std;

int main() {
int ** ar,n,*pos , *CT , *WT ,*TAT;



ar = new int *[2];

cout<<"Enter total no of process:";
cin>>n;
pos = new int[n];
CT = new int[n];
TAT = new int[n];
WT = new int[n];
int i =0,k=0;

while(i<n){
   
    ar[i]= new int [n];
    pos[i]=i;
    i++;
}

// taking inputs
for(int y=0;y<2;y++)
{
    for(int x=0;x<n;x++)
    {
        if(y==0){cout<<"Enter AT- "<<x+1<<":";}
        else{cout<<"Enter BT- "<<x+1<<":";}
        cin>>ar[y][x];
    }
   
}


//Sorting

for(int y=0;y<n-1;y++)
{
    for(int x=0;x<n-y-1;x++)
    {

     if(ar[1][x]>ar[1][x+1])
     {
         int hld = ar[1][x];
         ar[1][x] = ar[1][x+1];
         ar[1][x+1] = hld;
         
           int hld2 = ar[0][x];
         ar[0][x] = ar[0][x+1];
         ar[0][x+1] = hld2;
       
       
        int posh = pos[x];
        pos[x] = pos[x+1];
        pos[x+1] = posh;
         
     }

    }
   
}




//Completion Time
CT[0] = ar[1][0]+ar[0][0];
for(int r=1 ; r<n ;r++)
{
     CT[1] = ar[1][1] + CT[0];
    CT[r] = ar[1][r] + CT[r-1];
   
   
   
}

//TAT

for (int x=0;x< n;x++){
   
TAT[x] = CT[x]-ar[0][x];
}


//WT

for (int x=0;x< n;x++){
   
WT[x] = TAT[x]-ar[1][x];
}


cout<<"\n\n\n"<<"Pno"<<setw(4)<< "AT"<<setw(5)<<"BT"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT"<<endl;
int p;
for (int x=0;x< n;x++){
   
    for(int y=0 ;y<n;y++)
    {
        if(x == pos[y])
        {
            p=y;
        }
       
       
    }
     cout<<"P"<<x+1<<setw(5)<<ar[0][p]<<setw(5)<<ar[1][p]<<setw(5)<<CT[p]<<setw(5)<<TAT[p]<<setw(5)<<WT[p]<<endl;
     
      //cout<<"\npos parent:"<<p<<endl;
    }

   
   



    return 0;
}
