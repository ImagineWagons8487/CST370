/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw7_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw7_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Binary Search Tree Implementations
 * Abstract: Emulates a binary search tree with a little bit of UI
 * ID: 9908
 * Name: Jackie Luc
 * Date: 04/10/2025
 */

#include <iostream>
#include <queue>
struct TreeNodeInt
{
    public:
        TreeNodeInt()
        {
            TreeNodeInt(0);
        }

        TreeNodeInt(int val)
        {
            left = nullptr; right = nullptr;
            value = val;
        }

        TreeNodeInt *left, *right;
        int value;
};

class BST
{
    private:
        TreeNodeInt* root;

        void _printPreOrder(TreeNodeInt* n)
        {
            if(n)
            {
                std::cout << n->value << " ";
                _printPreOrder(n->left);
                _printPreOrder(n->right);
            }
        }

        void _printInOrder(TreeNodeInt* n)
        {
            if(n)
            {
                _printInOrder(n->left);
                std::cout << n->value << " ";
                _printInOrder(n->right);
            }
        }

        void _printPostOrder(TreeNodeInt* n)
        {
            if(n)
            {
                _printPostOrder(n->left);
                _printPostOrder(n->right);
                std::cout << n->value << " ";
            }
        }

        void insert(TreeNodeInt *&n, int val)
        {
            if(!n)
            {
                n = new TreeNodeInt(val);
            }
            else
            {
                if(val <= n->value)
                {
                    insert(n->left, val);
                }
                else
                {
                    insert(n->right, val);
                }
            }
        }

        int getHeight(TreeNodeInt* n)
        {
            //use algorithms to find height
            //use iterative bfs?
            if(!n)
                return 0;
            return 1 + std::max(getHeight(n->left), getHeight(n->right));
        }

        int _getOneChildNodes(TreeNodeInt* n)
        {
            int count = 0;
            if(!n)
            {
                return count;
            }
            if(n->left && !n->right)
            {
                ++count;
            }
            else if(n->right && !n->left)
            {
                ++count;
            }
            return count + _getOneChildNodes(n->left) + _getOneChildNodes(n->right);
        }

    public:
        BST()
        {
            root = nullptr;
        }

        TreeNodeInt* getRootNode()
        {
            if(root)
                return root;
            else
                return nullptr;
        }

        void insert(int val)
        {
            if(!root)
            {
                TreeNodeInt *n = new TreeNodeInt(val);
                root = n;
            }
            else
            {
                insert(root, val);
            }
        }

        void printPreOrder()
        {
            _printPreOrder(root);
        }

        void printInOrder()
        {
            _printInOrder(root);
        }

        void printPostOrder()
        {
            _printPostOrder(root);
        }

        int height()
        {
            return getHeight(root)-1;
        }

        int countLeaves()
        {
            //traverse somehow, bfs or dfs, increase a counter if curr->left and curr->right both don't exist
            //use bfs for this one
            std::queue<TreeNodeInt*> q;
            int count = 0;
            q.push(root);
            while(!q.empty())
            {
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                if(!q.front()->left && !q.front()->right)
                {
                    ++count;
                }
                q.pop();
            }
            return count;
        }

        int countOneChildNodes()
        {
            //dfs
            return _getOneChildNodes(root);
        }

};


int main() 
{
    // BST b;
    // b.insert(5);
    // b.insert(20);
    // b.insert(2);
    // b.insert(1);
    // std::cout << b.countLeaves();
    int input;
    BST bst;
    std::cin >> input;
    while(input--)
    {
        std::string instruction;
        std::cin >> instruction;
        if(instruction == "add")
        {
            int value;
            std::cin >> value;
            bst.insert(value);
        }
        else if(instruction == "preOrder")
        {
            bst.printPreOrder();
            std::cout << std::endl;
        }
        else if(instruction == "inOrder")
        {
            bst.printInOrder();
            std::cout << std::endl;
        }
        else if(instruction == "postOrder")
        {
            bst.printPostOrder();
            std::cout << std::endl;
        }
        else if(instruction == "height")
        {
            std::cout << bst.height() << std::endl;
        }
        else if(instruction == "countLeaves")
        {
            std::cout << bst.countLeaves() << std::endl;
        }
        else if(instruction == "countOneChildNodes")
        {
            std::cout << bst.countOneChildNodes() << std::endl;
        }
    }
    return 0;
}


/*
7
add 15
add 10
add 50
preOrder
add 45
height
postOrder

10
add 20
add 30
add 40
add 15
countLeaves
countOneChildNodes
add 25
add 70
countLeaves
countOneChildNodes
*/
