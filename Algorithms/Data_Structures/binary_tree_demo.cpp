#include <iostream>
#include <queue>

struct node{
    std::string position;
    node *first, *second;
};

struct org_tree{
    node *root;

    // create a new tree with the super root
    static org_tree create_org_structure(const std::string &pos){
        org_tree tree;
        tree.root = new node{pos, NULL, NULL};
        return tree;
    }

    // find the node by the name
    static node* find(node* root, const std::string& value){
        if(root == NULL){   // root empty
            return NULL;
        }
        if(root->position == value){    // root is the value
            return root;
        }
        // check the first child node
        auto firstFound = org_tree::find(root->first, value); 
        // return the first child node if value 
        if(firstFound != NULL){
            return firstFound;
        }

        // return the second child node
        return org_tree::find(root->second, value);
    }

    // add a subordinate to the manager
    bool addSubordinate(const std::string& manager, const std::string& subordinate){
        auto manager_node = org_tree::find(root, manager);
        if(!manager_node){
            std::cout << manager << " <- No position as such!\n";
            return false;
        }
        if(manager_node->first  && manager_node->second){
            std::cout << manager << " already has 2 subordinates ! \n";
        }
        if(!manager_node->first ){
            manager_node-> first = new node{subordinate, NULL, NULL};
        }
        else{
            manager_node->second = new node{subordinate, NULL, NULL};
        }
        return true;
    }

    // parent -> left -> right traversal
    static void preOrder_traversal(node* start){
        if(!start){
            return;
        }
        std::cout<< start->position << ", "; 
        preOrder_traversal(start->first);
        preOrder_traversal(start->second);
    }

    // left->parent->right traversal
    static void inOrder_traversal(node* start){
        if(!start)return;
        inOrder_traversal(start->first);
        std::cout << start-> position<< ", ";
        inOrder_traversal(start->second);
    }

    // left-> right -> parent traversal
    static void postOrder_traversal(node* start){
        if(!start)return;
        inOrder_traversal(start->first);
        inOrder_traversal(start->second);
        std::cout << start-> position << ", ";
    }

    // level order traversal : at each level all the left->parent->right are traversed
    static void levelOrder(node* start){
        if(!start)return;

        // keeping a track of each level
        std::queue<node*> q;

        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto current = q.front();

                q.pop();
                
                std::cout << current->position << ", ";
                if(current->first)q.push(current->first);
                if(current->second)q.push(current->second);
            }
            std::cout << std::endl;
        }

    }

};

int main(){
    auto tree = org_tree::create_org_structure("CEO"); 
    if(tree.addSubordinate("CEO", "Deputy Director")) std::cout << "Added Deputy Director in the tree." << std::endl; 
    else std::cout << "Couldn't add Deputy Director in the tree" << std::endl;

    if(tree.addSubordinate("Deputy Director", "IT Head")) std::cout << "Added IT Head in the tree." << std::endl;
    else std::cout << "Couldn't add IT Head in the tree" << std::endl; 

    if(tree.addSubordinate("Deputy Director", "Marketing Head"))
std::cout << "Added Marketing Head in the tree." << std::endl; else
std::cout << "Couldn't add Marketing Head in the tree" << std::endl; if(tree.addSubordinate("IT Head", "Security Head"))
std::cout << "Added Security Head in the tree." << std::endl; else
std::cout << "Couldn't add Security Head in the tree" << std::endl; if(tree.addSubordinate("IT Head", "App Development Head"))
std::cout << "Added App Development Head in the tree." << std::endl; else
std::cout << "Couldn't add App Development Head in the tree" << std::endl; if(tree.addSubordinate("Marketing Head", "Logistics Head"))
std::cout << "Added Logistics Head in the tree." << std::endl; else
std::cout << "Couldn't add Logistics Head in the tree" << std::endl; if(tree.addSubordinate("Marketing Head", "Public Relations Head"))
std::cout << "Added Public Relations Head in the tree." << std::endl; else
std::cout << "Couldn't add Public Relations Head in the tree" << std::endl; if(tree.addSubordinate("Deputy Director", "Finance Head"))
std::cout << "Added Finance Head in the tree." << std::endl;

else
std::cout << "Couldn't add Finance Head in the tree" << std::endl;

}