#pragma once

struct TreeNode {
    int a;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class BinaryTree {
    TreeNode* root = nullptr;

    public:
    ~BinaryTree() {deleteSubtree(root);}
    BinaryTree (const BinaryTree&) = delete;
    BinaryTree operator=(const BinaryTree&) = delete;
    BinaryTree (BinaryTree&&) = delete;
    BinaryTree operator=(BinaryTree&&) = delete;

    void insert (int x) {root = insertNode(root, x);} 

    int find (int x) const {return findNode(root, x); } 

    private:

    static TreeNode* insertNode(TreeNode* n, int x) {
        if (!n) return new TreeNode{ x, nullptr, nullptr };
        
        if (x < n->a)   n->left = insertNode(n->left, x);
        else            n->right = insertNode(n->right, x);
        return n;
    }

    static int findNode (TreeNode* n, int x) {
        if (n->a == x) return n->a;
        if (!n) return 0;
        return x > n->a ? findNode(n->right, x) : findNode(n->left, x); 
    }
    static void deleteSubtree(TreeNode* n) {
        if (!n) return;
        deleteSubtree(n->left);
        deleteSubtree(n->right);
        delete n;
    }
};