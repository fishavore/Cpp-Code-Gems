#pragma once

#include <sstream>

// AVL Tree data structure.
// Each tree node store values of template type VALUE.
// Nodes are sorted by keys of template type KEY.
// KEY should have overloaded comparation operators.
// VALUE should have copy constructor.
// KEY ans VALUE should have overloaded operator<< for printing.
template<class KEY, class VALUE>
class AVLTree
{
private:
    // Tree node.
    // Contains key and value.
    // Leaf nodes have height=1 and empty left/right subtrees.
    struct Node
    {
        KEY key;
        VALUE value;
        Node* left = nullptr;
        Node* right = nullptr;
        unsigned height = 1;

        Node(KEY _key, VALUE _value) : key(_key), value(_value) {}
        ~Node()
        {
            delete left;
            delete right;
        }

        friend std::ostream& operator<< (std::ostream& stream, const Node& node) 
        {
            stream << "(" << node.key << ", " << node.value << ") ";
            return stream;
        }
    };

    // Root of the tree.
    Node* mRoot;

public:
    // Constructor. Create empty tree.
    AVLTree() : mRoot(nullptr) {}
    // Destructor. Delete all tree nodes.
    ~AVLTree() { DeleteAll(); }
    // Add new node to the tree.
    void Insert(KEY key, VALUE value) { mRoot = insertNode(mRoot, key, value); }
    // Delete node required key from the tree.
    void Delete(KEY key) { mRoot = deleteNode(mRoot, key); }
    // Delete all nodes from the tree.
    void DeleteAll() { delete mRoot; mRoot = nullptr; }
    // Check if tree has node with required key.
    bool Has(KEY key) const { return findNode(mRoot, key) != nullptr; }
    // Get value from the node of the tree with required key.
    // A node required key MUST exist (can be checked with method Has(...)).
    // If tree has more than one node with required key, it returns one of them
    // (first found during searching).
    VALUE Get(KEY key) const { return findNode(mRoot, key)->value; }
    // Get the tree as string in pre order traversal.
    std::string PrintPreOrder() const { return printPreOrder(mRoot); }

private:
    static Node* insertNode(Node* node, KEY key, VALUE value);
    static Node* deleteNode(Node* node, KEY key);
    static Node* findNode(Node* node, KEY key);
    static Node* leftRotate(Node* node);
    static Node* rightRotate(Node* node);
    static Node* balanceNode(Node* node);
    static std::string printPreOrder(Node* node);

    static unsigned getHeight(Node* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    static void updateHeight(Node* node)
    {
        const unsigned leftHeight = getHeight(node->left);
        const unsigned rightHeight = getHeight(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    static int getBalanceFactor(Node* node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    static Node* getMinValueNode(Node* node)
    {
        Node* currentNode = node;
        while (currentNode->left != nullptr)
            currentNode = currentNode->left;
        return currentNode;
    }
};

template<class KEY, class VALUE>
typename AVLTree<KEY, VALUE>::Node* AVLTree<KEY, VALUE>::insertNode(Node* node, KEY key, VALUE value)
{
    if (node == nullptr)
        return new Node(key, value);

    if (key < node->key)
        node->left = insertNode(node->left, key, value);
    else
        node->right = insertNode(node->right, key, value);

    return balanceNode(node);
}

template<class KEY, class VALUE>
typename AVLTree<KEY, VALUE>::Node* AVLTree<KEY, VALUE>::deleteNode(Node* node, KEY key)
{
    if (node == nullptr)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            Node* newCurrentNode = node->left != nullptr ? node->left : node->right;

            if (newCurrentNode == nullptr)
            {
                newCurrentNode = node;
                node = nullptr;
            }
            else
            {
                node->key = newCurrentNode->key;
                node->value = newCurrentNode->value;
                node->left = newCurrentNode->left;
                node->right = newCurrentNode->right;
            }

            newCurrentNode->left = nullptr;
            newCurrentNode->right = nullptr;
            delete newCurrentNode;
        }
        else
        {
            Node* newCurrentNode = getMinValueNode(node->right);

            node->key = newCurrentNode->key;
            node->value = newCurrentNode->value;
            node->right = deleteNode(node->right, newCurrentNode->key);
        }
    }

    if (node == nullptr)
        return node;

    return balanceNode(node);
}

template<class KEY, class VALUE>
typename AVLTree<KEY, VALUE>::Node* AVLTree<KEY, VALUE>::findNode(Node* node, KEY key)
{
    if (node == nullptr)
        return node;

    if (key < node->key)
        return findNode(node->left, key);
    if (key > node->key)
        return findNode(node->right, key);
    return node;
}

template<class KEY, class VALUE>
typename AVLTree<KEY, VALUE>::Node* AVLTree<KEY, VALUE>::leftRotate(Node* node)
{
    Node* newCurrentNode = node->right;

    node->right = newCurrentNode->left;
    newCurrentNode->left = node;

    updateHeight(node);
    updateHeight(newCurrentNode);

    return newCurrentNode;
}

template<class KEY, class VALUE>
typename AVLTree<KEY, VALUE>::Node* AVLTree<KEY, VALUE>::rightRotate(Node* node)
{
    Node* newCurrentNode = node->left;

    node->left = newCurrentNode->right;
    newCurrentNode->right = node;

    updateHeight(node);
    updateHeight(newCurrentNode);

    return newCurrentNode;
}

template<class KEY, class VALUE>
typename AVLTree<KEY, VALUE>::Node* AVLTree<KEY, VALUE>::balanceNode(Node* node)
{
    updateHeight(node);

    const int balance = getBalanceFactor(node);

    if (balance > 1)
    {
        if (getBalanceFactor(node->left) < 0)
            node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1)
    {
        if (getBalanceFactor(node->right) > 0)
            node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<class KEY, class VALUE>
std::string AVLTree<KEY, VALUE>::printPreOrder(Node* node)
{
    if (node == nullptr)
        return "";

    std::stringstream ss;
    ss << *node << printPreOrder(node->left) << printPreOrder(node->right);
    return ss.str();
}
