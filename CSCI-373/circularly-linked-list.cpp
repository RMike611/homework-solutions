#include <iostream>
#include <string>

using namespace std;

class CNode {
private:
    string elem;
    CNode* next;

    friend class CircleList;
};

class CircleList {
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const string& front() const;
    const string& back() const;
    void advance();
    void add(const string& e);
    void remove();

private:
    CNode* cursor;
};

int main()
{
    CircleList list;
    list.add("Song1");
    list.add("Song2");
    list.add("Song3");
    list.add("Song4");
    list.add("Song5");
    list.advance();
    list.advance();
    list.advance();
    list.advance();
    list.advance();
    list.advance();
    cout << list.front();
    cout << list.back();

    return 0;
}

CircleList::CircleList()                                // Constructor
    : cursor(NULL) { }

CircleList::~CircleList() {                             // Destructor
    while (!empty()) remove();
}

bool CircleList::empty() const {                        // Checks if list is empty by checking if the cursor points to nothing
    return cursor == NULL;
}

const string& CircleList::front() const {                // Prints head's element
    cout << "\nThe element in front of the cursor is: ";
    return cursor->next->elem;
}

const string& CircleList::back() const {
    cout << "\nThe element at cursor is: ";
    return cursor->elem;
}

void CircleList::advance() {                        // Advances the cursor and then displays song title
    cursor = cursor->next;

    cout << "Now Playing: ";
    cout << cursor->elem << endl;
}

void CircleList::add(const string& e) {             // adds after cursor
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove() {                         // removes node after cursor
    CNode* old = cursor->next;
    if (old == cursor)
        cursor = NULL;
    else
        cursor->next = old->next;
    delete old;
}







