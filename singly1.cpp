
#include<iostream>
using namespace std;

struct node
{
	int Data;
	struct node * Next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class Singly_LinkedList
{
	private:
		PNODE Head;
		
	public: 
		Singly_LinkedList();
		
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int pos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int pos);
		void Display();
		int Count();
};
Singly_LinkedList::Singly_LinkedList()
{
	Head=NULL;
}

///////////////////////////////////////////////////////////////
//
// Function name : Display
// Description   : use to perfrom Display NODE
// Input	      : Pointer
//	output	      : Integer
//////////////////////////////////////////////////////////////

void Singly_LinkedList::Display()
{
	PNODE Temp=Head;
	
	cout<<"Element of singly liner linnked list are :"<<endl;
	
	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
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

int Singly_LinkedList::Count()
{
	int iCnt=0;
	PNODE Temp=Head;
	
	while(Temp!=NULL)
	{
		iCnt++;
		Temp=Temp->Next;
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

void Singly_LinkedList::InsertFirst(int no)
{
	PNODE newn=NULL;
	newn=new NODE;
	
	if(newn==NULL)
	{
		return;
	}
	
	newn->Data=no;
	newn->Next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	
	else
	{
		newn->Next=Head;
		Head=newn;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Description   : use to perfrom Add last NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void Singly_LinkedList::InsertLast(int no)
{
	PNODE newn=NULL;
	PNODE Temp=NULL;
	
	newn =new NODE;
	
	if(newn==NULL)
	{
		return;
	}
	
	newn->Data=no;
	newn->Next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	
	else
	{
		Temp=Head;
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=newn;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Description   : use to perfrom Add  at position NODE
// Input	      : Integer,Integer
//
//////////////////////////////////////////////////////////////

void Singly_LinkedList::InsertAtPos(int no,int pos)
{
	int iSize=0;
	int iCnt=0;
	
	PNODE newn=NULL;
	PNODE Temp=NULL;
	
	iSize=Count();
	
	if((pos<1)||(pos>iSize+1))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	
	else if(pos==1)
	{
		InsertFirst(no);
	}
	
	else if(pos==iSize+1)
	{
		InsertLast(no);
	}
	
	else
	{
		newn=new NODE;
		newn->Data=no;
		newn->Next=NULL;
		
		Temp=Head;
		
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			Temp=Temp->Next;
		}
		newn->Next=Temp->Next;
		Temp->Next=newn;
	}
	
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Description   : use to perfrom Delete first NODE
//
//////////////////////////////////////////////////////////////

void Singly_LinkedList::DeleteFirst()
{
	PNODE Temp=NULL;
	Temp=Head;
	
	if(Head==NULL)
	{
		return;
	}
	
	else
	{
		Head=Head->Next;
		delete Temp;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Description   : use to perfrom Delete Last NODE
//
//////////////////////////////////////////////////////////////

void Singly_LinkedList::DeleteLast()
{
	PNODE Temp=NULL;
	
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		Temp=Head;
		
		while(Temp->Next->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		delete(Temp->Next);
		Temp->Next=NULL;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Description   : use to perfrom Delete Last NODE
//
//////////////////////////////////////////////////////////////

void Singly_LinkedList::DeleteAtPos(int pos)
{
	int iSize=0;
	int iCnt=0;
	
	PNODE Temp=NULL;
	
	iSize=Count();
	
	if((pos<1)||(pos>iSize))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	
	else if(pos==1)
	{
		DeleteFirst();
	}
	
	else if(pos==iSize)
	{
		DeleteLast();
	}
	
	else
	{	
		Temp=Head;
		PNODE Temp2=NULL;
		
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			Temp=Temp->Next;
		}
		Temp2=Temp->Next;
		Temp->Next=Temp2->Next;
		delete Temp2;
		}
	}
}


/////////////////////////////////////////////////////////////
// Write a program Singly liner linked list
// to perform multiple Function use to add nodes
/////////////////////////////////////////////////////////////

int main()
{
	int iRet=0,iValue=0,iPos=0,iChoice=1;
	
	Singly_LinkedList obj;
	
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
