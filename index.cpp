#include <string>
#include <iostream>

using namespace std;

struct node
{
	node()
	{
		data = nullptr;
		next = nullptr;
	}

	node(const string &aCopy)
	{
		data = new string(aCopy);
		next = nullptr;
	}

	~node()
	{
		if(data)
			delete data;
		data = nullptr;
		next = nullptr;
	}

	string * data;
	node * next;

};
// find a node in the list, and return a pointer to it.
node * findNode(node * head,string search)
{
	node * found = nullptr;
	node * curr = head;

	if(!head)
	{
		cout << "List is empty " << endl;
		return NULL;
	}

	while(curr)
	{
		if(*curr->data == search)
		{
			cout << "Node found!" << endl;
			found = curr;
			break;
		}

		curr = curr->next;
	}

	if(!found)
	{
		cout << "Node not in the list " << endl;
	}
	// found will either be a pointer to the element if found, or it will be
	// returned as a nullptr. so we will need to check the caller to see if its
	// actually a node, or a nullptr.
		return found; 
	
}
void deleteNode(node *&head)
{
	string target;
	cout << "Please enter a name to delete: ";
	getline(cin, target);

	node * curr = head;
	node * prev = nullptr;
	while(curr)
	{
		if(*curr->data == target)
		{
			break;
		}

		prev = curr;
		curr = curr->next;
	}

	// node with name not in list
	if(!curr)
	{
		cout << "node not here" << endl;
	}

	// delete from the head node
	if(curr == head)
	{
		head = head->next;
		delete curr;
	}
	// delete elsewhere in the list. meaning we don't need to update the head
	// pointer.
	else
	{
		// link the prev node
		// to the node that comes
		// after curr
		prev->next = curr->next;
		delete curr; // delete curr
	}

	for(curr = head; curr; curr = curr->next)
	{
		cout << *curr->data << endl;
	}

}


int main()
{
	cout << "Hello, lets get some string data! " << endl;
	string myString("Gregory");
	string sString("Sean");
	string jString("Jennifer");
	string kString("Karin");
	// add some dummy nodes to the list for fun. 
	node * head = new node(myString);
	node * addNode = new node(sString);
	head->next = addNode;
	node * j = new node(jString);
	addNode->next = j;
	node * k = new node(kString);
	j->next = k;
	node * searchElem = findNode(head, jString);
	if(!searchElem)
	{
		cout << "No match :O" << endl;
	}
	else
	{
		cout << "found: " << *searchElem->data << endl;
	}

	// lets loop through our nodes and have them print their data
	node * curr;
	for(curr = head; curr; curr = curr->next)
	{

		cout << *curr->data << endl;
	}
	deleteNode(head);

	// delete the nodes as the program is about to exit.
	node * temp = head; // get a temp copy of the head.
	int counter = 0; // lets count how many we delete.
	while(temp)
	{
		cout << "Deleting: " << *temp->data 
				<< " which has a length of: " << temp->data->length() << endl;

		node * holder = temp->next; // temp hold of the next node in the list as we are about delete the next pointer when we delete the first node;
		delete temp;
		temp = holder; // advanced temp to the next node in the list.
		counter++; // increment the number of deletions.
	}

	cout << "Deleted: " << counter << " nodes!" << endl;
	return 0;
};


