#include<iostream>
using namespace std;

struct node
{
	int Data;
	struct node * Next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLLC
{
	private:
		PNODE Head;
		PNODE Tail;
		
	public:
		SinglyLLC()
		{
			Head=NULL;
			Tail=NULL;
		}
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int ipos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);
		void Display();
		int Count();
};

///////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Description   : use to perfrom Add first NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void SinglyLLC::InsertFirst(int no)
{
	PNODE Newn=NULL;
	Newn= new NODE;
	
	Newn->Data=no;
	Newn->Next=NULL;
	
	if(Head==NULL&&Tail==NULL)
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
	}
	Tail->Next=Head;
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Description   : use to perfrom Add last NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void SinglyLLC::InsertLast(int no)
{
	PNODE Newn=NULL;
	Newn= new NODE;
	
	Newn->Data=no;
	Newn->Next=NULL;
	
	if(Head==NULL&&Tail==NULL)
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Tail->Next=Newn;
		Tail=Newn;
	}
	Tail->Next=Head;
}

///////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Description   : use to perfrom Add  at position NODE
// Input	      : Integer,Integer
//
//////////////////////////////////////////////////////////////

void SinglyLLC::InsertAtPos(int no,int ipos)
{
	int iSize=Count();
	
	if((ipos<1)||(ipos>iSize+1))
	{
		cout<<"Invalid positiob=n"<<endl;
		return;
	}
	if(ipos==1)
	{
		InsertFirst(no);
	}
	if(ipos==iSize+1)
	{
		InsertLast(no);
	}
	
	else
	{
		PNODE Newn=NULL;
		Newn= new NODE;

		Newn->Data=no;
		Newn->Next=NULL;
		
		PNODE Temp=Head;
		for(int iCnt=1;iCnt<ipos-1;iCnt++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next=Newn;
		Tail->Next=Head;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Description   : use to perfrom Delete first NODE
//
//////////////////////////////////////////////////////////////

void SinglyLLC::DeleteFirst()
{
	if(Head==NULL&&Tail==NULL)
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->Next;
		delete Tail->Next;
		Tail->Next=Head;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Description   : use to perfrom Delete Last NODE
//
//////////////////////////////////////////////////////////////

void SinglyLLC::DeleteLast()
{
	if(Head==NULL&&Tail==NULL)
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		PNODE Temp=Head;
		while(Temp->Next!=Tail)
		{
			Temp=Temp->Next;
		}
		delete Temp->Next;
		Tail=Temp;
		Tail->Next=Head;
	}
}

///////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Description   : use to perfrom Delete at position NODE
// Input	      : Integer
//
//////////////////////////////////////////////////////////////

void SinglyLLC::DeleteAtPos(int ipos)
{
	int iSize=Count();
	
	if((ipos<1)||(ipos>iSize))
	{
		cout<<"Invalid positiob=n"<<endl;
		return;
	}
	if(ipos==1)
	{
		DeleteFirst();
	}
	if(ipos==iSize)
	{
		DeleteLast();
	}
	
	else
	{
		PNODE Temp1=Head;
		PNODE Temp2=Head;
		for(int iCnt=1;iCnt<ipos-1;iCnt++)
		{
			Temp1=Temp1->Next;
		}
		Temp2=Temp1->Next;
		Temp1->Next=Temp2->Next;
		delete Temp2;
	}	
}

///////////////////////////////////////////////////////////////
//
// Function name : Display
// Description   : use to perfrom Display NODE
// Input	      : Pointer
//	output	      : Integer
//////////////////////////////////////////////////////////////

void SinglyLLC::Display()
{
	PNODE Temp=Head;
	
	if(Head==NULL&&Tail==NULL)
	{
		return;
	}
	do
	{
		cout<<"|"<<Temp->Data<<"|"<<"->";
		Temp=Temp->Next;
	}while(Temp!=Tail->Next);
	cout<<endl;
}

///////////////////////////////////////////////////////////////
//
// Function name : Count
// Description   : use to perfrom count NODE
// Input	      : Pointer
// Output	      : Integer
//////////////////////////////////////////////////////////////

int SinglyLLC::Count()
{
	PNODE Temp=Head;
	int iCnt=0;
	
	if(Head==NULL&&Tail==NULL)
	{
		return 0;
	}
	do
	{
		iCnt++;
		Temp=Temp->Next;
	}while(Temp!=Tail->Next);
	return iCnt;
}

/////////////////////////////////////////////////////////////
// Write a program circular linked list
// to perform multiple Function use to add nodes
/////////////////////////////////////////////////////////////

int main()
{
	int iRet=0,iChoice=1,ipos=0,iValue=0;
	SinglyLLC obj;
	
	while(iChoice!=0)
	{
		cout<<"Enter your choice :"<<endl;
		cout<<"1 : Insert First"<<endl;
		cout<<"2 : Insert Last"<<endl;
		cout<<"3 : Insert At Position"<<endl;
		cout<<"4 : Delete First"<<endl;
		cout<<"5 : Delete LAST"<<endl;
		cout<<"6 : Delete At position"<<endl;
		cout<<"7 : Display the data"<<endl;
		cout<<"8 : Count the number of nodes"<<endl;
		cout<<"9 : Terminate the application"<<endl;
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter the insert first"<<endl;
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;
			
			case 2:
				cout<<"Enter the Insert last node"<<endl;
				cin>>iValue;
				obj.InsertLast(iValue);
				break;
			
			case 3:
				cout<<"Enter the Insert at node "<<endl;
				cin>>iValue;
				cout<<"Enetr the Insert at position node "<<endl;
				cin>>ipos;
				obj.InsertAtPos(iValue,ipos);
				break;
			
			case 4:
				cout<<"Enter the Delete first"<<endl;
				obj.DeleteFirst();
				break;
			
			case 5:
				cout<<"Enter the Delete Last"<<endl;
				obj.DeleteLast();
				break;
			
			case 6:				
				cout<<"Enetr the Delete at position node "<<endl;
				cin>>ipos;
				obj.DeleteAtPos(ipos);
				break;
			
			case 7:
				obj.Display();
				
				break;
			
			case 8:
				iRet=obj.Count();
				cout<<"Number of nodes is :"<<iRet<<endl;
				break;
				
			case 9:
				cout<<"Thank you for using this application "<<endl;
				iChoice=0;
				break;
				
			default:
				cout<<"plese enter correct choice"<<endl;
				break;
		}		//end of switch loop
	}		//end of while loop
	
	
	return 0;
}
