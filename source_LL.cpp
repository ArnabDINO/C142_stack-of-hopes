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
				cout<<"Nothing to delete";
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
			/*
			else if(pos==i){
				while(current->next->next!=NULL){
					current=current->next;
				}
				node* temp=current->next;
				current->next=NULL;
				delete temp;
			}
			*/
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
		
		/*void rev(){
			//node* current=head;
			head=head->next;
			if (head->next!=NULL)
			rev();
			cout <<head->data;
		}*/
};

int main(){
	list l1;
	l1.display();
	l1.count();
	l1.insert(10);
	l1.insert(11);
	l1.insAt(9,9);
	l1.insAt(9,3);
	//l1.insAt(51,1);
	//l1.insAt(5,-1); 
	l1.display();
	for(int i=1;i<4;i++){
		l1.insert(i);
	}
	l1.display();
	l1.count();
	//l1.rev();
	l1.del();
	l1.display();
	l1.delAt(0);
	l1.delAt(2);
	l1.display();
	return 0;
}
