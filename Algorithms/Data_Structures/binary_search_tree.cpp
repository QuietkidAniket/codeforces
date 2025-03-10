// value of the left child <= value of parent node  <= value of the right child

#include <iostream>

struct node
{
    int data;
    node *left, *right;
};
struct bst
{
public:
    // Root
    node *root = nullptr;

    node *find(int value)
    {
        return find_impl(root, value);
    }
    void *insert(int value)
    {
        if (!root)
        {
            root = new node{value, NULL, NULL};
        }
        else
        {
            insert_impl(root, value);
        }
    }
    void inorder()
    {
        return inorder_impl(root);
    }

    node *successor(node *start)
    { // traverse to the right subtree's smallest element
        auto current = start->right;
        while (current && current->left)
            current = current->left;
        return current;
    }

    void deleteValue(int value)
    {
        this->root = delete_impl(root, value);
    }

private:
    node *find_impl(node *current, int value)
    {

        // if the current node doesn't exist
        if (!current)
        {
            std::cout << std::endl;
            return NULL;
        }

        // if the current node have the required value
        if (current->data == value)
        {
            std::cout << "Found " << value << std::endl;
            return current;
        }

        if (value < current->data)
        { // Value will be in the left tree
            std::cout << "Going left from " << current->data << ", ";
            return find_impl(current->left, value);
        }
        if (value > current->data)
        { // Value will be in the right tree
            std::cout << "Going right from " << current->data << ", ";
            return find_impl(current->right, value);
        }
    }

    void insert_impl(node *current, int value)
    {
        if (current->data < value)
        {
            if (!current->left)
                current->left = new node{value, NULL, NULL};
            else
                insert_impl(current->left, value);
        }
        else
        {
            if (!current->right)
                current->right = new node{value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }
    }

    void inorder_impl(node *start)
    {
        if (!start)
            return;
        inorder_impl(start->left);
        std::cout << start->data << " ";
        inorder_impl(start->right);
    }

    node *delete_impl(node *start, int value)
    {

        if (!start)
        {
            return NULL;
        }
        if (start->data < value)
            return delete_impl(start->left, value);
        else if (start->data > value)
            return delete_impl(start->right, value);
        else
        {
            if (!start->left)
            { // if either all children are absent or only the left child is absent
                auto tmp = start->right;
                delete start;
                return tmp;
            }
            if (!start->right)
            { // if only right child is absent
                auto tmp = start->left;
                delete start;
                return tmp;
            }
            // traverse the right subtree for the smallest node
            auto succNode = successor(start);
            // replace the start node with the successor
            start->data = succNode->data;
            // delete the successor node from the right subtree
            delete_impl(start->right, succNode->data);

            return start;
        }
    }
};
int main()
{
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);
    std::cout << "Inorder: ";
    tree.inorder(); // This will print all the elements in ascending order std::cout << std::endl;
    tree.deleteValue(12);
    std::cout << "\nInorder after deleting 12: ";
    tree.inorder(); // This will print all the elements in ascending order std::cout << std::endl;
    std::cout << std::endl;
    if (tree.find(12))
        std::cout << "Element 12 is present in the tree" << std::endl;
    else
        std::cout << "Element 12 is NOT present in the tree" << std::endl;
}
