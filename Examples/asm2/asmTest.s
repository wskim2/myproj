      AREA  MYCODE, CODE, READONLY 
	   
      ENTRY
	  EXPORT __main

__main
             MOV r0, #1
		
STOP    
              MOV r1, #2
			  ADD r0, r0,r1
              B STOP
              END