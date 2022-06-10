#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
    int value;
    TreeNode *left_node, *right_node;

public:
    TreeNode(int value, TreeNode *left_node = nullptr, TreeNode *right_node = nullptr)
    {
        this->value = value; // Reminder: "this" is a pointer to an object
        this->left_node = left_node;
        this->right_node = right_node;
    }

    friend class BinarySearchTree;
};

class BinarySearchTree
{

public:
    // See page 270
    // O(Log N)
    void searchNode(int search_value, TreeNode *node) // TreeNode *node is the current node
    {

        if (node == nullptr)
        {
            cout << "Node not found!\n";
            return;
        }
        else if (node->value == search_value)
        {
            cout << "Node found: " << node->value << endl;
            return;
        }
        else if (search_value < node->value)
            searchNode(search_value, node->left_node);
        else
            searchNode(search_value, node->right_node);
    }

    // O(log N)
    void insertNode(int new_value, TreeNode *node)
    {

        if (new_value < node->value)
        {
            if (node->left_node == nullptr) // This is the base case
                node->left_node = new TreeNode(new_value);
            else
                insertNode(new_value, node->left_node);
        }

        if (new_value > node->value)
        { // This is the base case
            if (node->right_node == nullptr)
                node->right_node = new TreeNode(new_value);
            else
                insertNode(new_value, node->right_node);
        }
    }

    // See page 281
    // O(log N)
    TreeNode *deleteNode(int value_to_delete, TreeNode *node)
    {

        if (node == NULL)
            return NULL;

        else if (value_to_delete < node->value)
            node->left_node = deleteNode(value_to_delete, node->left_node);

        else if (value_to_delete > node->value)
            node->right_node = deleteNode(value_to_delete, node->right_node);

        else if (value_to_delete == node->value)
        {

            if (node->left_node == NULL)
                return node->right_node;
            else if (node->right_node == NULL)
                return node->left_node;
            else
            {
                // https://www.programiz.com/dsa/binary-search-tree
                TreeNode *temp_node = lift(node->right_node); // find the successor
                node->value = temp_node->value;
                node->right_node = deleteNode(temp_node->value, node->right_node); // delete the temp node
            }
        }
        return node;
    }

private:
    TreeNode *lift(TreeNode *node)
    {

        if (node->left_node != NULL)
            node->left_node = lift(node->left_node);

        return node;
    }

public:
    // See page 288
    // O(N)
    void traverseTree(TreeNode *node)
    {

        if (node == NULL) // Base case // Once we reach the base case, this function will be popped off the call stack.
            return;

        // inorder traversal (ascending order)
        traverseTree(node->left_node); // keep recursing until we reach the base case, then this function's instance will be popped off the call stack. then continue on to the next line of code
        cout << node->value << " ";
        traverseTree(node->right_node);
    }
};

int main()
{

    TreeNode tree_node1(25), tree_node2(75);
    TreeNode root_node(50, &tree_node1, &tree_node2);

    printf("(Binary Search Tree)\n");
    BinarySearchTree node;
    node.searchNode(5, &root_node);
    node.insertNode(100, &root_node);
    node.searchNode(100, &root_node);
    node.insertNode(0, &root_node);
    node.searchNode(0, &root_node);
    node.traverseTree(&root_node);
    node.deleteNode(50, &root_node);
    cout << endl;
    node.traverseTree(&root_node);

    return 0;
}