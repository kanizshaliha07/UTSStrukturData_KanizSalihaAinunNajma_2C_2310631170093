#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the linked list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to delete a node with given value
    void remove(int val) {
        Node* temp = head;
        Node* prev = nullptr;

        // If head node itself holds the key to be deleted
        if (temp != nullptr && temp->data == val) {
            head = temp->next; // Changed head
            delete temp; // free old head
            return;
        }

        // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == nullptr)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp; // Free memory
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Inserting elements into the linked list
    for (int i = 1; i <= 10; ++i)
        list.insert(i);

    cout << "Normal         : ";
    list.display();

    // Reversing the linked list
    list.reverse();

    cout << "Reverse        : ";
    list.display();

    // Deleting node with value 5
    list.remove(5);

    cout << "After removal  : ";
    list.display();

    cout << endl;
    cout << "Nama : Kaniz Shaliha Ainun Najma" << endl;
    cout << "NPM : 2310631170093" << endl;
    cout << "Kelas : 2C - Informatika" << endl;
    cout << "MK : Struktur Data" << endl;

    return 0;
}
