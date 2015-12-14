      AREA myData, DATA
COUNT  	EQU 10
SUM			 EQU 0

	  AREA  MYCODE, CODE, READONLY 
	   
      ENTRY
	  EXPORT __main

__main
             LDR r0, =COUNT
			 LDR r1, =SUM
			 LDR r2,  =2

loop
              ADD r1, r2, r1
			  ADD r2, r2, #1
			  SUBS r4, r0, r2
			  
			  BNE loop
              ADD r1, r2, r1

stop        B  	stop
		 
			 END