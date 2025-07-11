#include <iostream>
#include <list>

using namespace std;


typedef int Elem;					// base element type
class LinkedBinaryTree {
protected:
    struct Node {					// a node of the tree
        Elem    elt;					// element value
        Node* par;					// parent
        Node* left;					// left child
        Node* right;					// right child
        Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
    };
public:
    class Position {					// position in the tree
    private:
        Node* v;						// pointer to the node
    public:
        Position(Node* _v = NULL) : v(_v) { }		// constructor
        Elem& operator*()					// returns element
        {
            return v->elt;
        }
        Position left() const				// gets left child
        {
            return Position(v->left);
        }
        Position right() const				// gets right child
        {
            return Position(v->right);
        }
        Position parent() const				// gets parent
        {
            return Position(v->par);
        }
        bool isRoot() const				// checks root
        {
            return v->par == NULL;
        }
        bool isExternal() const				// true if node is external
        {
            return v->left == NULL && v->right == NULL;
        }
        friend class LinkedBinaryTree;			// give tree access
    };
    typedef list<Position> PositionList;		// list of positions

public:
    LinkedBinaryTree();
    int size() const;
    bool empty() const;	
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
    void postOrder(const Position& p);

protected:
    void preorder(Node* v, PositionList& pl) const;
private:
    Node* _root;
    int n;
};


int main()
{
    LinkedBinaryTree newTree;

    newTree.addRoot();
    LinkedBinaryTree::Position myPosition;

    myPosition = newTree.root();
    *myPosition = 1;
    LinkedBinaryTree::Position rootP;
    cout << "Root Value: " << *myPosition << endl;

    newTree.expandExternal(myPosition);
    myPosition  = myPosition.left();
    *myPosition = 2;
    cout << "Current Node Value is: " << *myPosition << endl;
    myPosition  = myPosition.parent();
    myPosition  = myPosition.right();
    *myPosition = 3;
    cout << "Current Node Value is: " << *myPosition << endl;
    myPosition = myPosition.parent();
    myPosition = myPosition.left();
    newTree.expandExternal(myPosition);
    myPosition = myPosition.left();
    *myPosition = 5;
    cout << "Current Node Value is: " << *myPosition << endl;
    myPosition = myPosition.parent();
    myPosition = myPosition.right();
    *myPosition = 10;
    cout << "Current Node Value is: " << *myPosition << endl;

    cout << "\nList size:" << newTree.size() << endl;

    myPosition = myPosition.parent();
    myPosition = myPosition.parent();

    cout << "\nPost Order Traverse: ";
    newTree.postOrder(myPosition);                          // Post Order Traversal
	
	return 0;
}

LinkedBinaryTree::LinkedBinaryTree()			// constructor
    : _root(NULL), n(0) { }
int LinkedBinaryTree::size() const			// number of nodes
{
    return n;
}
bool LinkedBinaryTree::empty() const			// returns true if empty
{
    return size() == 0;
}
LinkedBinaryTree::Position LinkedBinaryTree::root() const // returns root
{
    return Position(_root);
}
void LinkedBinaryTree::addRoot()			// adds root
{
    _root = new Node; n = 1;
}

void LinkedBinaryTree::expandExternal(const Position& p) {  // Turns an external none into and internal node by adding 2 children
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;	
}

LinkedBinaryTree::Position				// removes p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;  Node* v = w->par;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        sib->par = NULL;
    }
    else {
        Node* gpar = v->par;
        if (v == gpar->left) gpar->left = sib; 
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;	
    n -= 2;
    return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    preorder(_root, pl);					// preorder traversal
    return PositionList(pl);				// return resulting preorder sorted list
}
// preorder traversal
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL)
        preorder(v->left, pl);
    if (v->right != NULL)
        preorder(v->right, pl);
}

// postOrder traversal
void LinkedBinaryTree::postOrder(const Position& p) {
    Position curP;
    curP = p;

    curP = curP.left();
    curP = curP.left();
    cout << *curP << " ";
    curP = curP.parent();
    curP = curP.right();
    cout << *curP << " ";
    curP = curP.parent();
    cout << *curP << " ";
    curP = curP.parent();
    curP = curP.right();
    cout << *curP << " ";
    curP = curP.parent();
    cout << *curP << " ";
    cout << endl;
}














