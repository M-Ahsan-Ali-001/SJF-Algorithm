#include <iostream>
using namespace std;

int main()
{
    int * AT, *BT,*CT,*TAT,*WT,*POS,n,HOLD ;
   
    cout<<"Enter total number of process";
    cin>>n;
   
    AT= new int [n];
    BT= new int [n];
    POS= new int [n];
    CT= new int [n];
    TAT= new int [n];
    WT= new int [n];
   
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER AT"<<i+1<<":";
        cin>>AT[i];
        POS[i]=i;
    }
    
     for(int i=0;i<n;i++)
    {
           cout<<"ENTER BT"<<i+1<<":";
        cin>>BT[i];
       
       
    }
   
    //sort
   
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++){
           
            if(BT[i]>BT[j])  {
                 int tempBT = BT[j];
                 BT[j]=BT[i];
                 BT[i]=tempBT;
                 
                 
                 int tempAT = AT[j];
                 AT[j]=AT[i];
                 AT[i]=tempAT;
                 
                 int tempPOS = POS[j];
                 POS[j]=POS[i];
                 POS[i]=tempPOS; }
        }
       
    }
   
     /* cout<<"\ntestprint\n";
        for(int i=0;i<n;i++)
    {
        cout<<AT[i]<<"\t"<<BT[i]<<endl;
    }*/
   
      int low=AT[0],idx=0;
        for(int i=1;i<n;i++)
       {
     
         // cout<<"\n"<<low<<" "<<AT[i]<<endl;
           if(low>AT[i] || (low==AT[i]  && BT[i-1]>BT[i])){
               low=AT[i];
               idx=i;
               cout<<"\nFound\n";
             //  cout<<"\nnow low is :"<<low<<endl;
            }
                 
                 
          if(i+1 == n){
                //cout<<"\nhere\n";
               
                int tempBT = BT[0];
                 BT[0]=BT[idx];
                 BT[idx]=tempBT;
                 
                 
                 int tempAT = AT[0];
                 AT[0]=AT[idx];
                 AT[idx]=tempAT;
                 
                 int tempPOS = POS[0];
                 POS[0]=POS[idx];
                 POS[idx]=tempPOS; }
    }
   
      /* cout<<"\n2testprint\n";
        for(int i=0;i<n;i++)
    {
        cout<<AT[i]<<"\t"<<BT[i]<<endl;
    }*/
   
      for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n-1;j++){
           
            if((AT[i]>AT[j] && (AT[j]<(AT[i]+BT[i]) &&
                (BT[j]<BT[i]))
               )
                 ||
               ((AT[i]<AT[j])
                 &&
                 ((BT[j]<BT[i]) &&
                  (AT[j]<(AT[i]+BT[i]))
                 )
               )
            )
             {
                 
              //  cout<<"ATi:"<<AT[i]<<" BTi :"<<BT[i]<<"ATj:"<<AT[j]<<" BTj :"<<BT[j]<<endl;  
                 int tempBT = BT[j];
                 BT[j]=BT[i];
                 BT[i]=tempBT;
                 
                 
                 int tempAT = AT[j];
                 AT[j]=AT[i];
                 AT[i]=tempAT;
                 
                 int tempPOS = POS[j];
                 POS[j]=POS[i];
                 POS[i]=tempPOS;
                 
             }// if statement closing
           
        }//inner loop closing
       
    }
    
    
    //Complettion Time(CT) calculation
    CT[0] =BT[0]+AT[0];
    for(int i=1 ;i<n;i++)
    {
    
    CT[i] =BT[i]+CT[i-1];
    CT[1] =BT[1]+CT[0];    
    }
//TAT
  for(int i=0 ;i<n;i++)
  {
      TAT[i]=CT[i]-AT[i];
      WT[i]=TAT[i]-BT[i];
      
      
  }
cout<<"Pno\tAT\tBT\tCT\tTAT\tWT\n"<<endl;

for(int i=0;i<n;i++){
  
     for(int y=0 ;y<n;y++)
    {
        if(i == POS[y])
        {
            HOLD=y;
        }
       
       
    }
    

cout<<"P"<<i+1<<"\t"<<AT[HOLD]<<"\t"<<BT[HOLD]<<"\t"<<CT[HOLD]<<"\t"<<TAT[HOLD]<<"\t"<<WT[HOLD]<<endl ;   
  
}

   
}
