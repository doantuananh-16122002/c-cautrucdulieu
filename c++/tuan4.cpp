//thư viện cần dùng
#include<iostream>

using namespace std;

//khai báo các CTDL để tổ chức danh sách liên kết
class Node{
public:
	int data;
	Node* next;
};

class LinkedList{
private: 
	Node* head;
public:
	//operations of List ADT
	LinkedList();
	~LinkedList();
	Node* Insert(int,int);
	void Print();
};

//chương trình chính (bắt buộc phải có)
int main(){
	LinkedList lst1;
	int n = 5;
	for(int i=0; i<n; i++){
		lst1.Insert(i,i+1);
	}
	lst1.Print();
	return 0;
}

LinkedList::LinkedList(){
	head = NULL;
}

LinkedList::~LinkedList(){}

Node* LinkedList::Insert(int index,int data){
	int currIndex = 1;
	Node* currNode = head;
	if(index < 0) return NULL;
	while(currNode && index > currIndex){
		currNode = currNode->next;
		currIndex++;
	}

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if(index == 0){
		//insert new node at front
		newNode->next = head;
		head = newNode;
	}
	if(currNode == NULL){
		//index is invalid
		return NULL;
	}

	if(index > 0){
		//insert new node at mid or back
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	cout<<"Insert "<<data<<" at position "<<index<<" of list"<<endl;
	return newNode;
}
void LinkedList::Print(){
	if(head == NULL){
		cout<<"List is empty"<<endl;
	}else{
		Node* currNode = head;
		while(currNode){
			cout<<currNode->data<<" -> ";
			currNode = currNode->next;
		}
		cout<<"NULL"<<endl;
	}
}