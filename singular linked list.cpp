#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
class linkList{
	public:
		node *head, *tail;
	public:
		linkList(){
			head = NULL;
			tail = NULL;
		}
		void creatList(int value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		void printList(){
			node *temp = new node;
			temp = head;
			if(temp == NULL){
				cout << "List is empty";
				return;
			}
			while(temp != NULL){
				cout << temp -> data << "\t";
				temp = temp -> next;
			}
		}
		void search(int value){
			node *temp = new node;
			temp = head;
			bool find;
			if(temp == NULL){
				cout << endl << "List is empty" << endl;
				return;
			}
			while(temp != NULL){
				if(temp -> data == value){
					cout << temp -> data;
					find = true;
					return;
				}
				else{
					temp = temp -> next;
					find = false;
				}
			}
			if(find == false){
					cout << "\nelement is not found\n";
			}
		}
		//remove
		void removeElement(int remValue){
			if(head == NULL){
				cout<<"\n List is empty: \n";
			}
			else{
	    		node *prev = head;
	    		node *current = head->next;
	    		while(current != NULL) {
	        		if(current -> data == remValue) { 
	            		break;
	        		}
	        		else {
	           			prev = current; 
	            		current = current->next;
	        		}
	    		}
	    		if(current == NULL) {
	    			if(head -> data == remValue)
	    			{
		        		cout << "\n Head Deleted: \t";
		        		head = head -> next;
		        	}
		        	else{
		        		cout << "\n not found \n";
					}
	    		} else {
	        		cout << "\n Deleted: \n";
	        		prev->next = current->next;
	        		delete current;
	    		}
	    	}
		}
		//sorting
		void sortedList(node *prev){
			while(prev != NULL){
				node *current = prev;
				while(current != NULL){				
					if(prev -> data < current -> data){
						prev -> data = prev -> data + current -> data;
						current -> data = prev -> data - current -> data;
						prev -> data = prev -> data - current -> data;										
					}
					current = current -> next;					
				}
				prev = prev -> next;				
									
			}
		}
};
	void frontBackSplit(node *copyAhead, node *copyA2head, linkList a, node *copyA3head){
		linkList b;
		linkList c;
		int midleIndex = 0;
		int i = 1;
		while(copyAhead -> next != NULL){
			i++;
			copyAhead = copyAhead -> next;
		}
		if((i%2) == 0){
			midleIndex  = i / 2;
		}
		if((i%2) == 1){
			midleIndex = (i/2) + 1;
		}
		int f = 1;
		while(f <= midleIndex - 1 ){
			copyA2head = copyA2head -> next;
			f++;
		}
		node *temp = copyA2head -> next;
		copyA2head -> next = NULL;
		a.printList();
		a.head = temp;
		cout << endl;
		copyA3head = a.head;
		a.sortedList(copyA3head);
		while(copyA3head -> next != NULL){
			copyA3head = copyA3head -> next;
			f++;
		}
		cout << endl;
		a.printList();

	}
int main(){
	linkList a;
	a.creatList(6);
	a.creatList(2);
	a.creatList(3);
	a.creatList(8);
	a.creatList(10);
	a.creatList(11);
	a.creatList(7);
	a.creatList(8);
	frontBackSplit(a.head, a.head, a, a.head);
	
	return 0;
}
