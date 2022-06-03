#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

///////////////////////////////////////////////////////////////
//
// Description   : use to perfrom of N Elements
// Input	      : Pointer,Integer
// Output	      : Integer
// Date	          : 21/05/2022
// Author	      : Suraj Sanjay Thanage
//
//////////////////////////////////////////////////////////////

typedef struct node NODE;
typedef struct node *PNODE;

class Doubly_LinkedList
{
	private:
		PNODE head;
	
	public:
		Doubly_LinkedList();
		void InsertFirst(int iNo);
		void InsertLast(int iNo);
		void InsertAtPos(int iNo,int iPos);
		void DeleteLast();
		void DeleteFirst();
		void DeleteAtPos(int iPos);
		void Display();
		int Count();
};

Doubly_LinkedList::Doubly_LinkedList()
{
	head=NULL;
}

///////////////////////////////////////////////////////////////
//
// Function name : Display
// Description   : use to perfrom Display NODE
// Input	      : Pointer
//	output	      : Integer
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::Display()
{
	PNODE temp=head;
	cout<<"Element of doubly linked list are :";
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<endl;
}

///////////////////////////////////////////////////////////////
//
// Function name : Count
// Description   : To perfrom count of NODE
// Input	      : Pointer
// Output	      : Integer
//////////////////////////////////////////////////////////////

int Doubly_LinkedList::Count()
{
	PNODE temp=head;
	int iCnt=0;
	while(temp!=NULL)
	{
		iCnt++;
		temp=temp->next;
	}
	return iCnt;
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Description   : use to perfrom Add first NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::InsertFirst(int iNo)
{
	PNODE newn=NULL;
	newn=new NODE;
	if(newn==NULL)
	{
		return;
	}	
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(head!=NULL)
	{
		newn->next=head;
		head->prev=newn;
		
	}
	head=newn;
	
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Description   : use to perfrom Add last NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::InsertLast(int iNo)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	newn=new NODE;
	if(newn==NULL)
	{
		return;
	}	
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(head==NULL)
	{
		head=newn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
	
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Description   : use to perfrom Add  at position NODE
// Input	 : Integer,Integer
//
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::InsertAtPos(int iNo,int iPos)
{
	PNODE temp=head;
	PNODE newn=NULL;
	
	int iCnt=0,iSize=0;
	iSize=Count();
	
	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Invalid Position";
		return;
	}
	else if(iPos==1)
	{
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(iNo);
	}
	else
	{
		newn=new NODE;
		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;
		temp=head;
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Description   : use to perfrom Delete first NODE
//
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::DeleteFirst()
{
	PNODE temp=head;
	if(head==NULL)
	{
		return;
	}
	else
	{
		head=head->next;
		delete(temp->prev);
		temp->prev=NULL;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Description   : use to perfrom Delete Last NODE
//
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::DeleteLast()
{
	PNODE temp=NULL;
	if(head==NULL)
	{
		return;
	}
	else if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		delete(temp->next);
		temp->next=NULL;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Description   : use to perfrom Delete Last NODE
//
//////////////////////////////////////////////////////////////

void Doubly_LinkedList::DeleteAtPos(int iPos)
{
	PNODE temp=head;
	
	int iCnt=0,iSize=0;
	iSize=Count();
	
	if((iPos<1)||(iPos>iSize))
	{
		cout<<"Invalid Position";
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		temp=head;
		PNODE temp2=NULL;
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=temp2->next;
		delete temp2;
		temp->next->prev=temp;
	}
}

/////////////////////////////////////////////////////////////
// Write a program doubly linked list
// to perform multiple Function use to add nodes
/////////////////////////////////////////////////////////////

int main()
{
	int iRet=0,iValue=0,iPos=0,iChoice=1;
	
	Doubly_LinkedList obj;
	
	while(iChoice!=0)
	{
		cout<<"Choice the operation you want to you"<<endl<<endl;
		cout<<"1 : Insert first NODE"<<endl;
		cout<<"2 : Insert last NODE"<<endl;
		cout<<"3 : Insert at Position NODE"<<endl;
		cout<<"4 : Delete first NODE"<<endl;
		cout<<"5 : Delete Last NODE"<<endl;
		cout<<"6 : Delete at Position NODE"<<endl;
		cout<<"7 : Display NODEs"<<endl;
		cout<<"8 : Total count NODE"<<endl;
		cout<<"9 : Terminated application"<<endl;
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter first element of NODE"<<endl;
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;
			
			case 2:
				cout<<"Enter last element of NODE"<<endl;
				cin>>iValue;
				obj.InsertLast(iValue);
				break;
				
			case 3:
				cout<<"Enter Position of NODE"<<endl;
				cin>>iPos;
				cout<<"Enter element of NODE"<<endl;				
				cin>>iValue;
				obj.InsertAtPos(iValue,iPos);
				
				break;
			
			case 4:
				cout<<"Delete first element of NODE"<<endl<<endl;
				obj.DeleteFirst();
				break;
			
			case 5:
				cout<<"Delete last element of NODE"<<endl<<endl;
				obj.DeleteLast();
				break;
			
			case 6:
				cout<<"Delete at Position element of NODE"<<endl;
				cin>>iPos;
				obj.DeleteAtPos(iPos);
				break;
				
			case 7:
				cout<<"Display  NODEs"<<endl<<endl;
				obj.Display();
				break;
				
			case 8:
				iRet=obj.Count();
				cout<<"Element of element present in NODE : "<<iRet<<endl;
				break;
				
			case 9:
				cout<<"Thank you for using this application"<<endl;
				iChoice=0;
				break;
				
			default:
				cout<<"Choice perfect operation"<<endl;
				break;
		}
	}
	return 0;
}
