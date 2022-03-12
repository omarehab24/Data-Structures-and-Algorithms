
#include <iostream>
#include <conio.h>
#include <queue>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node* root = nullptr;
node* newnode = nullptr;


node* insert(node*, int);
void Breadth_First_Search(node*);
void Preorder(node*);
void Inorder(node*);
void Postorder(node*);
void destroy();
node* max(node*);
node* delete_value(node*, int);
void search(node*, int);


int main()
{
	int value;
	char button = 0;
	printf("****Binary Search Tree****\n\n");

	while (button != 27)
	{
		cout << "1. Insert\n";
		cout << "2. Search\n";
		cout << "3. Display in BFS\n";
		cout << "4. Display in Preorder\n";
		cout << "5. Display in Inorder\n";
		cout << "6. Display in Postorder\n";
		cout << "7. Delete a value\n";
		cout << "8. Distroy the tree\n";
		cout << "ESC to exit\n\n";

		button = _getch();

		switch (button)
		{
		case '1':
			cout << "Enter a value : "; cin >> value;
			root = insert(root, value);
			cout << "Done!\n\n";
			break;

		case '2':
			cout << "Search for a value: "; cin >> value;
			search(root, value);
			break;

		case '3':
			cout << "BFS: \n";
			Breadth_First_Search(root);
			cout << endl;
			break;

		case '4':
			cout << "Preorder: \n";
			Preorder(root);
			cout << endl;
			break;

		case '5':
			cout << "Inorder: \n";
			Inorder(root);
			cout << endl;
			break;

		case '6':
			cout << "Postorder: \n";
			Postorder(root);
			cout << endl;
			break;

		case '7':
			cout << "Delete a value: "; cin >> value;
			delete_value(root, value);
			break;

		case '8':
			destroy();
			break;

		case 27:
			break;
		}
	}
	return 0;
}

node* insert(node* root, int val)
{
	newnode = new node();
	newnode->data = val;
	newnode->left = nullptr;
	newnode->right = nullptr;


	if (root == nullptr)
		root = newnode;

	else if (val <= root->data)
		root->left = insert(root->left, val);

	else
		root->right = insert(root->right, val);
			
	return root;
}


void Breadth_First_Search(node*root)
{
	if (root == nullptr)
	{
		cout << "Nothing to show!\n\n";
		return;
	}

	queue<node*> q;
	q.push(root);

	while (!q.empty())
	{
		node*current = q.front();
		q.pop();

		cout << current->data << endl;

		if (current->left != nullptr)
			q.push(current->left);

		if (current->right != nullptr)
			q.push(current->right);
	}
}

void Preorder(node*root)
{//if i write the condition when it should display if the tree is empty, it messes up the code, i don't know why.
	// also sometimes when i delete some values and call this function or any of the available display functions below or above, an error occurs and the program stops.
	//from Omar Ehab

/*   if (root == NULL) cout <<"Nothing to show!\n";   */

	if (root != NULL)
	{
		cout << root->data << endl;
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Inorder(node*root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		cout << root->data << endl;
		Inorder(root->right);
	}
}

void Postorder(node*root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << endl;
	}
}

void destroy()
{
	if (root != NULL)
	{
		delete root;
		cout << "Destroyed successfully!\n\n";
		root = NULL;
	}
	else
		cout << "Nothing to delete!\n\n";

}
node* max(node*root)
{
	while (root->right != nullptr)
		root = root->right;

	return root;

}
node* delete_value(node* root, int value)
{
	if (root == NULL)
	{
		cout << "Not found!\n\n";
		return root;
	}

	else if (value < root->data)
		root->left = delete_value(root->left, value);

	else if (value > root->data)
		root->right = delete_value(root->right, value);

	else
	{
		// case 1 : No childern
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			cout << "Successfully deleted!\n\n";
			return root;
		}
		// case 2 : One child
		else if (root->left == NULL)
		{
			node*temp = root;
			root = root->right;
			delete temp;
			cout << "Successfully deleted!\n\n";
			return root;
		}
		else if (root->right == NULL)
		{
			node*temp = root;
			root = root->left;
			delete temp;
			cout << "Successfully deleted!\n\n";
			return root;
		}
		// case 3 : Two Childern
		else
		{
			node*temp = max(root->left);
			root->data = temp->data;
			root->left = delete_value(root->left, temp->data);
			cout << "Successfully deleted!\n\n";
			return root;
		}

	}
	
}

void search(node*root, int value)
{
	if (root == nullptr)
	{
		cout << "Not found!\n\n";
		return;
	}
	else
	{
		if (root->data == value)
		{
			cout << "value is found!\n\n";
			return;
		}

		else
		{
			if (value < root->data)
				search(root->left, value);

			else if (value > root->data)
				search(root->right, value);
		}
	}
}

