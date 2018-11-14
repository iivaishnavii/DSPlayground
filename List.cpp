#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
class List {
public:

	typedef struct node {
		int data;
		node *next;
	} *nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
public:
	List();
	void AddNode(int addData);
	void DeleteNode(int delData);
	void PrintList();
	void insertNode(int index, int d);
	int findLength(nodePtr h);
	nodePtr getNode(int i);
	bool search(nodePtr n, int key);
	//nodePtr getFromLast(int size,int index);
	nodePtr getFromLast(int index);
	nodePtr printMiddle(int size);
};
List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void List::AddNode(int addData)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
	//cout<<curr->data;
}
void List::DeleteNode(int delData) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while ((curr != NULL) && (curr->data != delData))
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << "Not found" << endl;
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "Deleted!!!";
	}
}
void List::PrintList() {
	curr = head;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}
int List::findLength(nodePtr head)
{
	if (head == NULL)
		return 0;
	else
		return 1 + findLength(head->next);
}
List::nodePtr List::getNode(int index)
{
	curr = head;
	int pos = 1;
	while ((curr != NULL) && (pos < index))
	{
		curr = curr->next;
		pos = pos + 1;
	}
	if (pos == index)
	{
		return curr;
	}
	else if (curr == NULL)
	{
		cout << "index out of bounds";
	}
}
bool List::search(List::nodePtr n, int key)
{
	if (n == NULL)
	{
		return false;
	}
	else
	{
		if (n->data == key)
		{
			return true;
		}
		else
		{
			return search(n->next, key);
		}
	}
}
List::nodePtr List::getFromLast(int index)
{
	stack<nodePtr> s;
	curr = head;

	if (curr->next == NULL)
		s.push(curr);
	while (curr->next != NULL)
	{
		//cout<<curr->data;
		s.push(curr);
		curr = curr->next;
	}
	s.push(curr);
	int count = 1;
	while (count < index)
	{
		s.pop();
		count++;

	}

	return s.top();
}
List::nodePtr List::printMiddle(int size)
{
	int size = findLength(head);
	curr = head;
	for (int i = 0; i < size / 2; i++) {
		curr = curr->next;
	};
	return curr;
}
int main()
{
	List l;
	l.AddNode(2);
	l.AddNode(3);
	l.AddNode(4);
	l.AddNode(5);
	l.AddNode(6);
	int size = l.findLength(l.getNode(1));//<<endl;
	cout << size << endl;
	cout << l.printMiddle()->data;
}