	AREA MyFirstExample, CODE, READONLY
	ENTRY
	MOV r0,#4 ;load 4 into r0
	MOV r1,#5 ;load 5 into r1
	ADD r2,r0,r1 ;add r0 to r1 and put the result in r2
S 	B S ;force infinite loop by branching to this line
	END ;end of program