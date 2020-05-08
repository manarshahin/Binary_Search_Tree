#include <iostream>
using namespace std;
class Binary
{
    struct Node
	{
		int Value;
		Node* right;
		Node* left;
	};
	Node* Root = NULL;
	void insertH(Node* temp, int data)
	{
		if (data <= temp->Value)
		{
			if (temp->left == NULL)
			{
				Node* newnode = new Node;
				newnode->left = NULL;
				newnode->right = NULL;
				newnode->Value = data;
				temp->left = newnode;
			}
			else
			insertH(temp->left, data);
			
		}
		if (data >= temp->Value)
		{
			
			if (temp->right == NULL)
			{
				Node* newnode = new Node;
				newnode->left = NULL;
				newnode->right = NULL;
				newnode->Value = data;
				temp->right = newnode;
			}
			else
			insertH(temp->right, data);
		}
	}
	int searchH(Node* temp, int data)
	{
		if (Root == NULL)
			return false;
	    if (data == Root->Value)
		return true;
		if (data <= temp->Value)
		{
            return searchH(temp->left, data);
		}
		if (data >= temp->Value)
		{
			return searchH(temp->right, data);
		}
	}
	void displyH(Node* node) {
		if (node == NULL)
			return;
		displyH(node->left);
		cout << node->Value << " ";
		displyH(node->right);
	}
public:
    void insert(int data)
	{
		if (Root == NULL)
		{
			Node* newnode = new Node;
			newnode->Value = data;
			newnode->right = NULL;
			newnode->left = NULL;
			Root = newnode;
		}
		else
		{
			insertH(Root, data);
		}
	}
	bool search(int data) 
	{
		if (Root == NULL)
			return false;
		else
		return searchH(Root, data);
	}
	void display()
	{
		displyH(Root);
		cout << endl;
	}
	
};
int main()
{
	Binary binary;
	binary.insert(22);
	binary.insert(15);
	binary.insert(13);
	binary.insert(10);
	binary.insert(12);
	binary.insert(19);
	binary.insert(33);
	binary.insert(31);
	binary.display();
	cout<<binary.search(22);
	return 0;
}
