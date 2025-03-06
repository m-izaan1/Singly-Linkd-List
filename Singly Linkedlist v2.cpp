#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    // Constructor:
    LinkedList() {
        head = nullptr;
    }

    // Destructor:
    ~LinkedList() {
        Node* current = head;
        // Delete each node to free memory
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        cout << "List destroyed." << endl;
    }

    // Insert a node at the top of the list
    void InsertNodeAtTop(const string &value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "New Node inserted at the top" << endl;
    }

    // Display the nodes in the list
    void DisplayNode() {
        Node* current = head;
        cout << "List: ";
        if (current == nullptr) { // Correctly check if the list is empty
            cout << "Empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " --> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Append a node at the end of the list
    void AppendNode(const string &value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            cout << "New Node added (List was empty)" << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        cout << "Appended at the end of the list" << endl;
    }

    // Insert a node in between after the node with the given 'point' data
    void InsertNodeInBetween(const string &value, const string &point) {
        Node* current = head;
        // Traverse the list
        while (current != nullptr) {
            if (current->data == point) {
                Node* newNode = new Node;
                newNode->data = value;
                // Use assignment to set the new node's next pointer
                newNode->next = current->next;
                current->next = newNode;
                cout << "Inserted node with value '" << value << "' after node with value '" << point << "'" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Node with value '" << point << "' not found. Insertion failed." << endl;
    }

    // Delete a node by key
    void DeleteNodeInBetween(const string &key) {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }
        // Check if the head needs to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "The key was the head; the node has been deleted." << endl;
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        // Traverse the list to find the node with data equal to key
        while (current != nullptr) {
            if (current->data == key) {
                previous->next = current->next;
                delete current;
                cout << "Deleted node with key '" << key << "'" << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Key '" << key << "' not found" << endl;
    }
};

int main() {
    // Create an instance of LinkedList
    LinkedList list;

    // Test inserting nodes at the top
    list.InsertNodeAtTop("apple");
    list.InsertNodeAtTop("banana");
    list.DisplayNode();

    // Test appending nodes to the end
    list.AppendNode("cherry");
    list.AppendNode("date");
    list.DisplayNode();

    // Test inserting a node in between
    list.InsertNodeInBetween("elderberry", "banana");
    list.InsertNodeInBetween("grape", "fig");
    list.DisplayNode();

    // Test deleting nodes by key
    list.DeleteNodeInBetween("cherry");
    list.DeleteNodeInBetween("apple");
    list.DisplayNode();

    // Test deleting a non-existent node
    list.DeleteNodeInBetween("kiwi");
    list.DisplayNode();

    return 0;
}
