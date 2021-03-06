//***************** STACK_WITH_QUEUE *******************

#include<iostream>
using namespace std;

class node{
	public:
		
		int data;
		node* next;
		node(){
			next=NULL;
		}
};

class list{
	public:
		node* head;
		//default constructor
		list(){
			head=NULL;
		}
	
		void insert(int input){
			node* curr=head;
			node* temp=new node; // temporary placeholder, later to be integrated into the list
			//input 
			temp->data=input;
			if(head==NULL){
				head=temp;
			}
			else{
				while(curr->next!=NULL){
				curr=curr->next;
			}
			temp->next=curr->next;
			curr->next=temp;
			}
		}
		
		//insret at
		void insAt(int input,int pos){
			node* temp=new node;
			temp->data=input;
			node* current=head;
			int i;
			if (head==NULL){
				i=0;
			}
			else{
				i=1;
				while(current->next!=NULL){
					current=current->next;
					i++;
				}
			}
			if(pos-1>i||pos<1){
				cout<<"given position is out of scope\n";
			}
			
			else if(pos==1){
				temp->next=head;
				head=temp;
			}
			
			else{
				//reach the position
				node* current=head;
				int i=1;
				while(i<pos-1){
					current=current->next;
					i++;
				}
				temp->next=current->next;
				current->next=temp;
			}
		}
		
		void del(){
			//find the tail
			//reach upto the element just before the tail.
			//store the address of tail in temp
			//modify tail
			//delete temp
			//here tail refers to the node whose pointer points to the NULL
			node* curr=head;
			node* temp=new node;
			//no element
			if(head==NULL){
				cout<<"Nothing to delete\n";
			}
			//only one element
			else if(head->next==NULL){
				temp=head;
				head=NULL;
				delete temp;
			}
			//more than one element
			else{
				while(curr->next->next!=NULL){
					curr=curr->next;
				}
				temp=curr->next;
				curr->next=NULL;
				delete temp;
			}
		}
		
		//deleteAt
		void delAt(int pos){
			node* current=head;
			int i;
			if (head==NULL){
				i=0;
			}
			else{
				i=1;
				while(current->next!=NULL){
					current=current->next;
					i++;
				}
			}//now i stores the number of notes
			
			if (pos>i||pos<1){
				cout<<"position out of scope\n";
			}
			else if(pos==1){
				node* temp=new node;
				temp=head;
				head=head->next;
				delete temp;
			}
			
			else{
				node* current=head;
				int j=1;
				while(j<pos-1){
					j++;
					current=current->next;
				}//position reached
				node* temp=current->next;
				current->next=temp->next;
				delete temp;
			}
		}
		
		void count(){
			node* current=head;
			if(head==NULL){
				cout<<"There are 0 elements\n";
			}
			else{
				int i=1;
				while(current->next!=NULL){
					i++;
					current=current->next;
				}
				cout<<"There are "<<i<<" elements\n";
			}
		}
		
		
		void display(){
			node* curr=head;
			if (head==NULL){
				cout<<"NULL"<<endl;
			}
			else{
				while(curr!=NULL){
					cout<<curr->data<<"->";
					curr=curr->next;
				}
				cout<<"NULL\n";
			}
		}
};

class q{
	public:
		//node* front;
		node * end;
		list l1;
		//default constructor
		q(){
			end=l1.head;	
		}
		
		//enqueue
		void enq(int input){
			l1.insAt(input,1);
			end=l1.head;
		}
		//deqeue
		void dq(){
			l1.del();
		}
		//sizeOf
		int sizeOf(){
			int i;
			if (end==NULL){
				i=0;
			}
			else {
				i=1;
				node* current=l1.head;
				while (current->next!=NULL){
					current=current->next;
					i++;
				}
			}
			
			return i;
			//cout<<"There are/is "<<i<<" element(s)\n";
		}
		//isEmpty function
		bool isEmpty(){
			if (end==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		//print_end
		void prnt_end(){
			if (end==NULL){
				cout<<"there is no element\n";
			}
			else{
				cout<<"The end element is "<<end->data<<"\n";
			}
		}
		//print_front
		void prnt_frnt(){
			if(end!=NULL){
				node* current=l1.head;
				while(current->next!=NULL){
					current=current->next;
				}
				cout<<"the front element is"<<current->data<<endl;
			}
			else{
				cout<<"there is no element\n";
			}
		}
};

class stwq{
	public:
		q q1;
		int size;
		//default constructor
		
		stwq(){
			size=0;
		}
		//push
		void push(int input){
			
		}
		//pop
		void pop(){
			q1.dq();
		}
		//
		
};

int main(){
	stwq s1;
/*	s1.pop();
	for(int i=1;i<=5;i++){
		s1.push(i);
		s1.disp_t();
	}
	s1.pop();
	s1.disp_t();*/
	return 0;
}
