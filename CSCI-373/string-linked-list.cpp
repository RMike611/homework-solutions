#include <iostream>
#include <string>

using namespace std;

// string version

class StringNode {
private:
    string elem;
    StringNode* next;


    friend class StringLinkedList;
};


class StringLinkedList {
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
    void addBack(const string& e);
    void removeBack();
    void printList();
    void insertElem(string value);
    void deleteElem(string value);
    void sort();

private:
    StringNode* head;
    int listLength;
};

int main()
{
    StringLinkedList list;
    list.removeBack();
    list.addFront("Element1");
    list.addFront("Element2");
    list.addFront("Element3");
    list.addFront("Element4");
    list.addBack("Element5");
    list.addBack("Element6");
    list.addFront("Element7");
    cout << list.front();
    list.printList();
    list.removeBack();
    list.removeBack();
    list.printList();

    list.insertElem("Element3");
    list.printList();

    list.deleteElem("Element2");
    list.printList();

    return 0;
}



StringLinkedList::StringLinkedList()                            // Constructor
    : head(NULL), listLength(0) { }


StringLinkedList::~StringLinkedList() {                         // Destructor
    while (!empty()) removeFront();
}


bool StringLinkedList::empty() const {
    return head == NULL;
}


const string& StringLinkedList::front() const {                // Prints head's element
    cout << "The element in front is: ";
    return head->elem;
}


void StringLinkedList::printList() {                      // Prints each node until end of list is reached
    cout << endl;
    cout << "Singly Linked List: ";
    StringNode* temp = head;
    if (temp != NULL) {
        while (temp != NULL) {
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else {
        cout << "List is empty.\n";
    }
}


void StringLinkedList::addFront(const string& e) {             // Adds node by setting new node's next to head's node and then makes the new node the head
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
    listLength++;
}


void StringLinkedList::addBack(const string& e) {              // adds element to the end of the list
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = NULL;
    if (head == NULL) {                                 // checks if list is empty
        head = v;
    }
    else {
        StringNode* temp = head;                          // if not then it goes through the list until it finds the last node (if the next points to NULL)
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = v;                                 // makes the last node in the list point to the new node
    }
    listLength++;
}


void StringLinkedList::removeFront() {                    // sets head to next node and then deletes the old head
    StringNode* oldHead = head;
    head = oldHead->next;
    delete oldHead;
    listLength--;
}


void StringLinkedList::removeBack() {                      // checks if list is empty and if it isn't it removes the last element 
    if (head == NULL) {
        cout << "List empty, can't remove anything.\n\n";
    }
    else {                                              // Checks through list until it reaches the end and then deletes last node
        StringNode* temp = head;
        StringNode* prev = temp;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        delete temp;                                    // deletes last element
        prev->next = NULL;
        listLength--;
    }
}


void StringLinkedList::sort() {                           // Sorts elements by swapping the largest one and the next smaller one
    cout << "\nList sorted:";
    StringNode* temp;
    StringNode* nextTemp;
    temp = head;
    nextTemp = head->next;

    for (int i = listLength; i > 0; i--) {
        temp = head;
        nextTemp = head->next;

        for (int j = 1; j < listLength; j++) {
            if (temp->elem > nextTemp->elem) {
                swap(temp->elem, nextTemp->elem);
            }
            temp = nextTemp;
            nextTemp = nextTemp->next;
        }
    }
}


void StringLinkedList::insertElem(string value) {              // adds element then sorts list
    addFront(value);
    sort();
    listLength++;

}


void StringLinkedList::deleteElem(string value) {              // Deletes a specific element
    StringNode* v = new StringNode;
    v->elem = value;

    if (head == NULL) {
        cout << "List empty, can't remove anything.\n";
    }
    else {
        StringNode* temp = head;
        StringNode* prev = temp;
        StringNode* toDelete = temp;
        bool continueLoop = true;
        bool isNotFound = true;
        while (temp->next != NULL && continueLoop == true) {            // Checks for element and then deletes it if found
            if (temp->elem == v->elem) {
                prev->next = temp->next;
                toDelete = temp;
                temp = temp->next;
                delete toDelete;
                listLength--;
                isNotFound = false;
                continueLoop = false;
            }
            else {
                prev = temp;
                temp = temp->next;

            }
        }
        if (isNotFound == true)                                         // Prints message if element not found
            cout << "Element not found.\n";
    }
}

