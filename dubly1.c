#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

struct node
{
	int Data;
	struct node * Next;
	struct node * Prev;
};

///////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Description   : use to perfrom Add first NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE Newn=NULL;
	Newn=(PNODE)malloc(sizeof(NODE));
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	
	if(*Head!=NULL)
	{
		Newn->Next=*Head;
		(*Head)->Prev=Newn;
	}
	*Head=Newn;
}

///////////////////////////////////////////////////////////////
//
// Function name : Display
// Description   : use to perfrom Display NODE
// Input	      : Pointer
//	output	      : Integer
//////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
	printf("Element of node is :\n");
	while(Head!=NULL)
	{
		printf("|%d|<-->",Head->Data);
		Head=Head->Next;
	}
	printf("NULL\n");
}

///////////////////////////////////////////////////////////////
//
// Function name : Count
// Description   : use to perfrom count NODE
// Input	      : Pointer
// Output	      : Integer
//////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head=Head->Next;
	}
	return iCnt;
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Description   : use to perfrom Add last NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int iNo)
{
	PNODE Newn=NULL;
	PNODE Temp=NULL;
	Newn=(PNODE)malloc(sizeof(NODE));
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	
	if(*Head==NULL)
	{
		*Head=Newn;
	}
	else
	{
		Temp=*Head;
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Newn;
		Newn->Prev=Temp;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Description   : use to perfrom Delete first NODE
//
//////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->Next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=(*Head)->Next;
		free((*Head)->Prev);
		(*Head)->Prev=NULL;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Description   : use to perfrom Delete Last NODE
//
//////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
	PNODE Temp=NULL;
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->Next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		Temp=*Head;
		while(Temp->Next->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		free(Temp->Next);
		Temp->Next=NULL;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Description   : use to perfrom Add  at position NODE
// Input	      : Integer,Integer
//
//////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
	int iCnt=0,iSize=0;
	PNODE Newn=NULL;
	PNODE Temp=NULL;
	iSize=Count(*Head);
	
	if((iPos<1)||(iPos>iSize+1))
	{
		printf("Invalid position\n");
		return;
	}
	else if(iPos==1)
	{
		InsertFirst(Head,iNo);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(Head,iNo);
	}
	else
	{
		Temp=*Head;
		Newn=(PNODE)malloc(sizeof(NODE));
		Newn->Data=iNo;
		Newn->Next=NULL;
		Newn->Prev=NULL;
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next->Next->Prev=Newn;
		Temp->Next=Newn;
		Newn->Prev=Temp->Next;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Description   : use to perfrom Delete at position NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int iPos)
{
	int iCnt=0,iSize=0;
	PNODE Temp=NULL;
	iSize=Count(*Head);
	
	if((iPos<1)||(iPos>iSize))
	{
		printf("Invalid position\n");
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst(Head);
	}
	else if(iPos==iSize-1)
	{
		DeleteLast(Head);
	}
	else
	{
		Temp=*Head;
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Temp->Next->Next;
		free(Temp->Next->Prev);
		Temp->Next->Next->Prev=Temp;
	}
}

/////////////////////////////////////////////////////////////
// Write a program doubly linked list
// to perform multiple Function use to add nodes
/////////////////////////////////////////////////////////////

int main()
{
	int iRet=0,iValue=0,iPos=0,iChoice=1;
	
	PNODE First=NULL;
	
	while(iChoice!=0)
	{
		printf("Choice the operation you want to you\n");
		printf("1 : Insert first NODE\n");
		printf("2 : Insert last NODE\n");
		printf("3 : Insert at Position NODE\n");
		printf("4 : Delete first NODE\n");
		printf("5 : Delete Last NODE\n");
		printf("6 : Delete at Position NODE\n");
		printf("7 : Display NODEs\n");
		printf("8 : Total count NODE\n");
		printf("9 : Terminated application\n");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
				printf("Enter first element of NODE\n");
				scanf("%d",&iValue);
				InsertFirst(&First,iValue);
				break;
			
			case 2:
				printf("Enter last element of NODE\n");
				scanf("%d",&iValue);
				InsertLast(&First,iValue);
				break;
				
			case 3:
				printf("Enter Position of NODE\n");
				scanf("%d",&iPos);
				printf("Enter element of NODE\n");
				scanf("%d",&iValue);
				InsertAtPos(&First,iPos,iValue);
				
				break;
			
			case 4:
				printf("Delete first element of NODE\n");
				DeleteFirst(&First);
				break;
			
			case 5:
				printf("Delete last element of NODE\n");
				DeleteLast(&First);
				break;
			
			case 6:
				printf("Delete at Position element of NODE\n");
				scanf("%d",&iPos);
				DeleteAtPos(&First,iPos);
				break;
				
			case 7:
				printf("Display  NODEs\n");
				Display(First);
				break;
				
			case 8:
				iRet=Count(First);
				printf("Element of linked present in NODE : %d \n",iRet);
				break;
				
			case 9:
				printf("Thank you for using this application\n");
				iChoice=0;
				break;
				
			default:
				printf("Choice perfect operation\n");
				break;
		}
	}
	return 0;
}