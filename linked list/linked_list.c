/* 
       to excercise linked list 
*/	
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node *head = NULL;

void Print()
{
	Node *temp = head;

	printf("List is : ");
	while(temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Insert(Node** head, int x)
{
	Node* temp = (Node *) malloc(sizeof(Node));
	temp->data = x;
	temp->next = NULL;
	if(*head != NULL) 
		temp->next= *head;
	*head = temp;
}

//insert new node to pos from head.
void Insert_pos(int x, int pos)
{
	Node* temp2;
	int i;
	Node* temp1 = (Node *) malloc(sizeof(Node));

	temp1->data = x;
	temp1->next = NULL;

	if(pos ==1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	temp2 = head;
	for(i=0;i<pos-2;i++)
	{
		temp2 = temp2->next;
	}

	temp1->next = temp2->next;
	temp2->next = temp1;

}

void Delete(int n)
{
	int i;
	Node *temp2;
	Node *temp1 = head;

	if(n == 1) //1st node right after head
	{
		head = temp1->next;
		free(temp1);
		return;
	}

	for(i=0;i<n-2;i++)
		temp1 = temp1->next;
	
	temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
}

// to reverse inked list iterative method : converting head node to tail node.
void Reverse()
{
	Node *current, *prev, *next;

	current = head;
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;

	printf("Reverse List ->");
	Print();
}

//test recursive call in printing node
void ReversePrint(Node *p)
{
	if(p == NULL) //tail
	{
		return;
	}

	//printf("%d ", p->data);
	ReversePrint(p->next);
	printf("%d ", p->data);
}


//reverse linked list with recursion
void Reverse_recursive(Node *p)
{
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	Reverse_recursive(p->next);
	p->next->next = p;
	p->next = NULL;	
}


// insert new node from head node
void test1()
{
	int n,i,x;

	printf("how may numbers?\n");
	
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{ 
		printf("Enter num?\n");
		scanf("%d",&x);
		Insert(&head, x);
		Print(head);
	}
}

void test2()
{
	Insert_pos(2,1);
	Insert_pos(3,2);
	Insert_pos(4,1);
	Insert_pos(5,2);
	Print();
}

void test3()
{
	int n,i;

	for(i=0;i<4;i++)
	{
		printf("Enter delete position?");
		scanf("%d", &n);
		Delete(n);
		Print();
	}
}


int main()
{
		
	//test1();
	test2();
	//test3();
	//Reverse();
	//ReversePrint(head);
	//Reverse_recursive(head);
	//Print();
	calc_fibonachi();
	//sim_factorial();

	getch();
}
