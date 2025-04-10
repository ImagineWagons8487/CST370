/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw7_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw7_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Binary Tree Implementations
 * Abstract: Emulates a binary tree with a little bit of UI, can identify if binary tree is a BST
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

class BinaryTree
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

        TreeNodeInt* _findFirstNode(TreeNodeInt* n)
        {
            if(n->left)
            {
                return _findFirstNode(n->left);
            }
            else
            {
                return n;
            }
        }

    public:
        BinaryTree()
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
                root = new TreeNodeInt(val);
            }
            else
            {
                std::queue<TreeNodeInt*> q, pQ;
                q.push(root);
                pQ.push(root);
                while(!q.empty())
                {
                    TreeNodeInt* curr = q.front();

                    if(!curr->left)
                    {
                        curr->left = new TreeNodeInt(val);
                        return;
                    }
                    else
                    {
                        q.push(curr->left);
                    }
                    if(!curr->right)
                    {
                        curr->right = new TreeNodeInt(val);
                        return;
                    }
                    else
                    {
                        q.push(curr->right);
                    }
                    q.pop();
                }
            }
        }

        void printPreOrder()
        {
            _printPreOrder(root);
            std::cout << std::endl;
        }

        void printInOrder()
        {
            _printInOrder(root);
            std::cout << std::endl;
        }

        void printPostOrder()
        {
            _printPostOrder(root);
            std::cout << std::endl;
        }

        void printLevelOrder()
        {
            std::queue<TreeNodeInt*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNodeInt* curr = q.front();
                std::cout << curr->value << " ";
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
                q.pop();
            }
            std::cout << std::endl;
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

        bool isBST()
        {
            std::queue<TreeNodeInt*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNodeInt* curr = q.front();
                if(curr->left)
                {
                    if(curr->value < curr->left->value)
                    {
                        return false;
                    }
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    if(curr->value > curr->right->value)
                    {
                        return false;
                    }
                    q.push(curr->right);
                }
                q.pop();
            }
            return true;
        }

        TreeNodeInt* findFirstNode()
        {
            return _findFirstNode(root);
        }

};

int main() 
{
    BinaryTree b;
    // b.insert(15);
    // b.insert(10);
    // b.insert(50);
    // b.insert(45);
    // b.insert(1);
    // b.insert(2);
    // b.printInOrder();
    int rtVal, instructions;
    std::cin >> rtVal >> instructions;
    b.insert(rtVal);
    while(instructions--)
    {
        std::string command;
        std::cin >> command;
        if(command == "append")
        {
            int n;
            std::cin >> n;
            b.insert(n);
        }
        else if(command == "isBST")
        {
            bool isBST = b.isBST();
            if(isBST)
            {
                std::cout << "true\n";
            }
            else
            {
                std::cout << "false\n";
            }
        }
        else if(command == "preOrder")
        {
            b.printPreOrder();
        }
        else if(command == "inOrder")
        {
            b.printInOrder();
        }
        else if(command == "postOrder")
        {
            b.printPostOrder();
        }
        else if(command == "height")
        {
            std::cout << b.height() << std::endl;
        }
        else if(command == "levelOrder")
        {
            b.printLevelOrder();
        }
        else if(command == "findFirstNode")
        {
            std::cout << b.findFirstNode()->value << std::endl;
        }
    }
    return 0;
}

