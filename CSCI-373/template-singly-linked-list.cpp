#include <iostream>
#include <string>

using namespace std;

// template version

template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;

    template <typename E>
    friend class SLinkedList;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();
    void addBack(const E& e);
    void removeBack();
    void printList();
    void insertElem(E value);
    void deleteElem(E value);
    void sort();

private:
    SNode<E>* head;
    int listLength;
};

int main()
{
    cout << "Singly Linked List\n";
    SLinkedList<double> list;
    list.removeBack();
    list.addFront(1.1);
    list.addFront(1.2);
    list.addFront(1.3);
    list.addFront(1.4);
    list.addBack(1.5);
    list.addBack(1.6);
    list.addFront(1.7);
    cout << list.front();
    list.printList();

    list.removeBack();
    list.removeBack();
    list.printList();

    cout << "\nDeleted 1.4";
    list.deleteElem(1.4);
    list.printList();

    cout << "\nInteger list with the same Singly Linked List class:\n";

    SLinkedList<int> intList;
    intList.addFront(1);
    intList.addFront(2);
    intList.addFront(3);
    intList.addFront(4);
    intList.addBack(5);
    intList.addBack(6);
    intList.addFront(7);
    cout << intList.front();
    intList.printList();

    intList.removeBack();
    intList.removeBack();
    intList.printList();

    intList.addFront(2);
    intList.sort();
    intList.printList();

    intList.insertElem(3);
    intList.printList();

    intList.deleteElem(4);
    cout << "\nDeleted 4";
    intList.printList();

    cout << "\nTest Delete Non-Existant Element\n";
    intList.deleteElem(40);

    cout << "\nString Singly Linked List\n";
    SLinkedList<string> stringList;
    stringList.addFront("Element1");
    stringList.addFront("Element2");
    stringList.addFront("Element3");
    stringList.addFront("Element4");
    stringList.addBack("Element5");
    stringList.addBack("Element6");
    stringList.addFront("Element7");
    cout << stringList.front();
    stringList.printList();

    stringList.removeBack();
    stringList.removeBack();
    stringList.printList();

    stringList.insertElem("Element3");
    stringList.printList();

    stringList.deleteElem("Element2");
    stringList.printList();
    return 0;
}

template <typename E>
SLinkedList<E>::SLinkedList()                           // Constructor
    : head(NULL), listLength(0) { }

template <typename E>
SLinkedList<E>::~SLinkedList() {                        // Destructor
    while (!empty()) removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {                // Prints head's element
    cout << "The element in front is: ";
    return head->elem;
}

template <typename E>
void SLinkedList<E>::printList() {                      // Prints each node until end of list is reached
    cout << endl;
    cout << "Singly Linked List: ";
    SNode<E>* temp = head;
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

template <typename E>
void SLinkedList<E>::addFront(const E& e) {             // Adds node by setting new node's next to head's node and then makes the new node the head
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
    listLength++;
}

template <typename E>
void SLinkedList<E>::addBack(const E& e) {              // adds element to the end of the list
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = NULL;
    if (head == NULL) {                                 // checks if list is empty
        head = v;
    }
    else {
        SNode<E>* temp = head;                          // if not then it goes through the list until it finds the last node (if the next points to NULL)
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = v;                                 // makes the last node in the list point to the new node
    }
    listLength++;
}

template <typename E>
void SLinkedList<E>::removeFront() {                    // sets head to next node and then deletes the old head
    SNode<E>* oldHead = head;
    head = oldHead->next;
    delete oldHead;
    listLength--;
}

template <typename E>
void SLinkedList<E>::removeBack() {                      // checks if list is empty and if it isn't it removes the last element 
    if (head == NULL) {
        cout << "List empty, can't remove anything.\n\n";
    }
    else {                                              // Checks through list until it reaches the end and then deletes last node
        SNode<E>* temp = head;
        SNode<E>* prev = temp;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        delete temp;                                    // deletes last element
        prev->next = NULL;
        listLength--;
    }
}

template <typename E>
void SLinkedList<E>::sort() {                           // Sorts elements by swapping the largest one and the next smaller one
    cout << "\nList sorted:";
    SNode<E>* temp;
    SNode<E>* nextTemp;
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

template <typename E>
void SLinkedList<E>::insertElem(E value) {              // adds element then sorts list
    addFront(value);
    sort();
    listLength++;
}

template <typename E>
void SLinkedList<E>::deleteElem(E value) {              // Deletes a specific element
    SNode<E>* v = new SNode<E>;
    v->elem = value;

    if (head == NULL) {
        cout << "List empty, can't remove anything.\n";
    }
    else {
        SNode<E>* temp = head;
        SNode<E>* prev = temp;
        SNode<E>* toDelete = temp;
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




