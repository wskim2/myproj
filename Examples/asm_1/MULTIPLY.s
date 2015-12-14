    AREA sum_of_product, CODE, READONLY
	ENTRY 
	EXPORT __main

;;; find product of sume of 2 array
__main

	mov r0, #3
	cmps r0, #3


	mov      r1, #0xaa;;MOV 	R0, #5 ; N=5
	LDR		R1, =X
	LDR		R2, =Y
	MOV		R5, #0	; LOW RESULT
	MOV 	R6, #0	; HIGH 32BIT RESULT

NEXT	LDR R3, [R1], #4 ; postInc R3<=[MEM R1] & R1<-R1+4(ADDR+4)
			LDR R4, [R2], #4

	
			;; SUM = SUM + X*Y
			UMLAL R5, R6, R3, R4   ; UNSIGNED MUL ACCUMULATED LONG
			SUBS	R0, #1
			BNE		NEXT

B1		B	B1

X	DCD 1,2,3,4,5 ;;; DEFINE CONSTANT DOUBLE WORD(32BIT)
Y	DCD 1,2,3,4,5 

	END