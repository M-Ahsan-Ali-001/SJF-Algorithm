# SJF-Algorithm (batch file)


 # Compiler Used
 <h2>g++</h2> is a comipler used to run c++ batch files in Linux Terminal 
 <h2> Execution</h2>
   ./a.out is used to excute c++ batch file.
 
 # Explanation
 - Dynamically Allocated 2D array is used to take input (BT & AT)
 - Separate 1D Dynamically Allocated  arrays are used for  CT , TAT , WT and POS
 
 - For sorting Buble Sort is used
 - CALULCATED CT using formula :
   ( <br>
     <br> ( AT[i]>AT[j] && 
    <br>  (AT[j]<(AT[i]+BT[i])&&(BT[j]<BT[i]) ) 
    <br>  )
      <br>         ||
      <br>  (
       <br>         (AT[i]<AT[j])
        <br>         &&
         <br>   (
           <br>       (BT[j]<BT[i]) &&
            <br>      ( AT[j]<(AT[i]+BT[i]) )
           <br>  )
         <br> )
   <br>  )
   
 - CALULCATED TAT using formula :
       TAT [i] = CT[i] - TW_D[0][i]
 
 - Calculated WT using formula:
      WT [i] = TAT[i] - TW_D[1][i]


 # Output ScreenShot
![Screenshot from 2022-12-07 18-35-09](https://user-images.githubusercontent.com/91987110/206231390-9299a784-d82f-4afd-9c3e-20cec275861a.png)
 
