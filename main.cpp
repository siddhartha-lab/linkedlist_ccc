/*
 * ========================================
 * SINGLY LINKED LIST SIMULATION PROJECT
 * ========================================
 * 
 * PROJECT OBJECTIVE:
 * To visually demonstrate how a Singly Linked List works internally
 * by simulating memory addresses, pointer updates, and all operations.
 * 
 * FEATURES:
 * - Node creation with simulated memory addresses
 * - Insert at beginning, end, and specific position
 * - Delete from beginning, end, and specific position
 * - Search with step-by-step comparison
 * - Traversal showing memory addresses
 * 
 * AUTHOR: [Your Name]
 * DATE: [Current Date]
 * ========================================
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Node structure representing a single element in the linked list
class Node {
public:
    int data;           // Data stored in the node
    Node* next;         // Pointer to the next node
    void* address;      // Simulated memory address for visualization
    
    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
        address = this;  // Use actual memory address for simulation
    }
};

// Singly Linked List class with all operations
class SinglyLinkedList {
private:
    Node* head;         // Pointer to the first node
    int size;           // Number of nodes in the list
    
    // Helper function to print separator line
    void printSeparator() {
        cout << "\n" << string(70, '=') << "\n";
    }
    
    // Helper function to print node details
    void printNodeDetails(Node* node, string label = "Node") {
        cout << label << " Details:\n";
        cout << "  Address: " << node->address << "\n";
        cout << "  Data: " << node->data << "\n";
        cout << "  Next: " << (node->next ? node->next->address : (void*)0) << "\n";
    }

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
        size = 0;
        cout << "✓ Linked List initialized. Head = NULL\n";
    }
    
    // Destructor to free all allocated memory
    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    
    // ========================================
    // INSERT AT BEGINNING - O(1)
    // ========================================
    void insertAtBeginning(int data) {
        printSeparator();
        cout << "OPERATION: Insert at Beginning (Value: " << data << ")\n";
        printSeparator();
        
        // Step 1: Create new node
        Node* newNode = new Node(data);
        cout << "\n[Step 1] Creating new node...\n";
        printNodeDetails(newNode, "New Node");
        
        // Step 2: Check if list is empty
        if (head == nullptr) {
            cout << "\n[Step 2] List is empty.\n";
            cout << "  Setting head = newNode (" << newNode->address << ")\n";
            head = newNode;
        } else {
            cout << "\n[Step 2] List is not empty. Current head: " << head->address << "\n";
            
            // Step 3: Update pointers
            cout << "\n[Step 3] Updating pointers...\n";
            cout << "  newNode->next = head (" << head->address << ")\n";
            newNode->next = head;
            
            cout << "  head = newNode (" << newNode->address << ")\n";
            head = newNode;
        }
        
        size++;
        cout << "\n✓ Insert at beginning completed!\n";
        cout << "  New size: " << size << "\n";
        cout << "  New head: " << head->address << "\n";
    }
    
    // ========================================
    // INSERT AT END - O(n)
    // ========================================
    void insertAtEnd(int data) {
        printSeparator();
        cout << "OPERATION: Insert at End (Value: " << data << ")\n";
        printSeparator();
        
        // Step 1: Create new node
        Node* newNode = new Node(data);
        cout << "\n[Step 1] Creating new node...\n";
        printNodeDetails(newNode, "New Node");
        
        // Step 2: Check if list is empty
        if (head == nullptr) {
            cout << "\n[Step 2] List is empty.\n";
            cout << "  Setting head = newNode (" << newNode->address << ")\n";
            head = newNode;
        } else {
            cout << "\n[Step 2] List is not empty. Traversing to find last node...\n";
            
            // Step 3: Traverse to last node
            Node* temp = head;
            int position = 1;
            
            cout << "\n[Step 3] Traversal:\n";
            while (temp->next != nullptr) {
                cout << "  Position " << position << ": " << temp->address 
                     << " (data: " << temp->data << ") → next exists\n";
                temp = temp->next;
                position++;
            }
            
            cout << "  Position " << position << ": " << temp->address 
                 << " (data: " << temp->data << ") → next is NULL (LAST NODE)\n";
            
            // Step 4: Update last node's next pointer
            cout << "\n[Step 4] Updating last node's next pointer...\n";
            cout << "  temp->next = newNode (" << newNode->address << ")\n";
            temp->next = newNode;
        }
        
        size++;
        cout << "\n✓ Insert at end completed!\n";
        cout << "  New size: " << size << "\n";
    }
    
    // ========================================
    // INSERT AT POSITION - O(n)
    // ========================================
    void insertAtPosition(int data, int position) {
        printSeparator();
        cout << "OPERATION: Insert at Position (Value: " << data << ", Position: " << position << ")\n";
        printSeparator();
        
        // Validate position
        if (position < 1 || position > size + 1) {
            cout << "\n✗ ERROR: Invalid position!\n";
            cout << "  Valid range: 1 to " << (size + 1) << "\n";
            return;
        }
        
        // If position is 1, insert at beginning
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }
        
        // Step 1: Create new node
        Node* newNode = new Node(data);
        cout << "\n[Step 1] Creating new node...\n";
        printNodeDetails(newNode, "New Node");
        
        // Step 2: Traverse to position-1
        cout << "\n[Step 2] Traversing to position " << (position - 1) << "...\n";
        Node* temp = head;
        int currentPos = 1;
        
        while (currentPos < position - 1) {
            cout << "  Position " << currentPos << ": " << temp->address 
                 << " (data: " << temp->data << ")\n";
            temp = temp->next;
            currentPos++;
        }
        
        cout << "  Reached position " << currentPos << ": " << temp->address 
             << " (data: " << temp->data << ")\n";
        
        // Step 3: Update pointers
        cout << "\n[Step 3] Updating pointers...\n";
        cout << "  newNode->next = temp->next (" 
             << (temp->next ? temp->next->address : (void*)0) << ")\n";
        newNode->next = temp->next;
        
        cout << "  temp->next = newNode (" << newNode->address << ")\n";
        temp->next = newNode;
        
        size++;
        cout << "\n✓ Insert at position " << position << " completed!\n";
        cout << "  New size: " << size << "\n";
    }
    
    // ========================================
    // DELETE FIRST NODE - O(1)
    // ========================================
    void deleteFirst() {
        printSeparator();
        cout << "OPERATION: Delete First Node\n";
        printSeparator();
        
        // Check if list is empty
        if (head == nullptr) {
            cout << "\n✗ ERROR: Cannot delete from empty list!\n";
            return;
        }
        
        // Step 1: Store reference to node to be deleted
        cout << "\n[Step 1] Storing reference to first node...\n";
        Node* temp = head;
        printNodeDetails(temp, "Node to Delete");
        
        // Step 2: Update head pointer
        cout << "\n[Step 2] Updating head pointer...\n";
        cout << "  head = head->next (" 
             << (head->next ? head->next->address : (void*)0) << ")\n";
        head = head->next;
        
        // Step 3: Free memory
        cout << "\n[Step 3] Freeing memory...\n";
        cout << "  Deleting node at address: " << temp->address << "\n";
        delete temp;
        
        size--;
        cout << "\n✓ Delete first completed!\n";
        cout << "  New size: " << size << "\n";
        cout << "  New head: " << (head ? head->address : (void*)0) << "\n";
    }
    
    // ========================================
    // DELETE LAST NODE - O(n)
    // ========================================
    void deleteLast() {
        printSeparator();
        cout << "OPERATION: Delete Last Node\n";
        printSeparator();
        
        // Check if list is empty
        if (head == nullptr) {
            cout << "\n✗ ERROR: Cannot delete from empty list!\n";
            return;
        }
        
        // If only one node exists
        if (head->next == nullptr) {
            deleteFirst();
            return;
        }
        
        // Step 1: Traverse to second-to-last node
        cout << "\n[Step 1] Traversing to find second-to-last node...\n";
        Node* temp = head;
        int position = 1;
        
        while (temp->next->next != nullptr) {
            cout << "  Position " << position << ": " << temp->address 
                 << " (data: " << temp->data << ")\n";
            temp = temp->next;
            position++;
        }
        
        cout << "  Position " << position << ": " << temp->address 
             << " (data: " << temp->data << ") → SECOND-TO-LAST\n";
        
        // Step 2: Store reference to last node
        cout << "\n[Step 2] Last node details:\n";
        Node* lastNode = temp->next;
        printNodeDetails(lastNode, "Node to Delete");
        
        // Step 3: Update second-to-last node's next pointer
        cout << "\n[Step 3] Updating second-to-last node's next pointer...\n";
        cout << "  temp->next = NULL\n";
        temp->next = nullptr;
        
        // Step 4: Free memory
        cout << "\n[Step 4] Freeing memory...\n";
        cout << "  Deleting node at address: " << lastNode->address << "\n";
        delete lastNode;
        
        size--;
        cout << "\n✓ Delete last completed!\n";
        cout << "  New size: " << size << "\n";
    }
    
    // ========================================
    // DELETE AT POSITION - O(n)
    // ========================================
    void deleteAtPosition(int position) {
        printSeparator();
        cout << "OPERATION: Delete at Position " << position << "\n";
        printSeparator();
        
        // Validate
        if (head == nullptr) {
            cout << "\n✗ ERROR: Cannot delete from empty list!\n";
            return;
        }
        
        if (position < 1 || position > size) {
            cout << "\n✗ ERROR: Invalid position!\n";
            cout << "  Valid range: 1 to " << size << "\n";
            return;
        }
        
        // If position is 1, delete first
        if (position == 1) {
            deleteFirst();
            return;
        }
        
        // Step 1: Traverse to position-1
        cout << "\n[Step 1] Traversing to position " << (position - 1) << "...\n";
        Node* temp = head;
        int currentPos = 1;
        
        while (currentPos < position - 1) {
            cout << "  Position " << currentPos << ": " << temp->address 
                 << " (data: " << temp->data << ")\n";
            temp = temp->next;
            currentPos++;
        }
        
        cout << "  Reached position " << currentPos << ": " << temp->address 
             << " (data: " << temp->data << ")\n";
        
        // Step 2: Store reference to node to be deleted
        cout << "\n[Step 2] Node to delete:\n";
        Node* nodeToDelete = temp->next;
        printNodeDetails(nodeToDelete, "Node to Delete");
        
        // Step 3: Update pointers
        cout << "\n[Step 3] Updating pointers...\n";
        cout << "  temp->next = temp->next->next (" 
             << (nodeToDelete->next ? nodeToDelete->next->address : (void*)0) << ")\n";
        temp->next = nodeToDelete->next;
        
        // Step 4: Free memory
        cout << "\n[Step 4] Freeing memory...\n";
        cout << "  Deleting node at address: " << nodeToDelete->address << "\n";
        delete nodeToDelete;
        
        size--;
        cout << "\n✓ Delete at position " << position << " completed!\n";
        cout << "  New size: " << size << "\n";
    }
    
    // ========================================
    // SEARCH - O(n)
    // ========================================
    int search(int value) {
        printSeparator();
        cout << "OPERATION: Search for value " << value << "\n";
        printSeparator();
        
        if (head == nullptr) {
            cout << "\n✗ ERROR: List is empty!\n";
            return -1;
        }
        
        cout << "\n[Searching...]\n";
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            cout << "  Position " << position << " (" << temp->address << "): ";
            cout << "Comparing " << temp->data << "... ";
            
            if (temp->data == value) {
                cout << "MATCH!\n";
                cout << "\n✓ Found " << value << " at position " << position << "\n";
                return position;
            } else {
                cout << "no\n";
            }
            
            temp = temp->next;
            position++;
        }
        
        cout << "\n✗ Value " << value << " not found in list\n";
        return -1;
    }
    
    // ========================================
    // TRAVERSE - O(n)
    // ========================================
    void traverse() {
        printSeparator();
        cout << "OPERATION: Traverse List\n";
        printSeparator();
        
        if (head == nullptr) {
            cout << "\nList is empty - nothing to traverse\n";
            return;
        }
        
        cout << "\n[Traversal Output]\n\n";
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            cout << "Position " << position << ": ";
            cout << "[" << temp->address << " | " << temp->data << " | next → ";
            cout << (temp->next ? temp->next->address : (void*)0) << "]";
            
            if (temp->next != nullptr) {
                cout << " →\n";
            } else {
                cout << " → NULL\n";
            }
            
            temp = temp->next;
            position++;
        }
        
        cout << "\n✓ Traversal completed. Total nodes: " << size << "\n";
    }
    
    // Display list in simple format
    void display() {
        if (head == nullptr) {
            cout << "List: [EMPTY]\n";
            return;
        }
        
        cout << "List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " → ";
            temp = temp->next;
        }
        cout << " → NULL\n";
    }
    
    // Get size
    int getSize() {
        return size;
    }
};

// ========================================
// MAIN FUNCTION - Menu-driven interface
// ========================================
int main() {
    SinglyLinkedList list;
    int choice, value, position;
    
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║   SINGLY LINKED LIST - INTERNAL WORKING SIMULATION        ║\n";
    cout << "║   Demonstrates memory addresses and pointer operations    ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    while (true) {
        cout << "\n";
        cout << "┌────────────────────────────────────────────────────────┐\n";
        cout << "│                    MAIN MENU                           │\n";
        cout << "├────────────────────────────────────────────────────────┤\n";
        cout << "│  1. Insert at Beginning                                │\n";
        cout << "│  2. Insert at End                                      │\n";
        cout << "│  3. Insert at Position                                 │\n";
        cout << "│  4. Delete First Node                                  │\n";
        cout << "│  5. Delete Last Node                                   │\n";
        cout << "│  6. Delete at Position                                 │\n";
        cout << "│  7. Search for Value                                   │\n";
        cout << "│  8. Traverse List                                      │\n";
        cout << "│  9. Display List (Simple)                              │\n";
        cout << "│  0. Exit                                               │\n";
        cout << "└────────────────────────────────────────────────────────┘\n";
        cout << "\nCurrent Size: " << list.getSize() << "\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (1 to " << (list.getSize() + 1) << "): ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
                
            case 4:
                list.deleteFirst();
                break;
                
            case 5:
                list.deleteLast();
                break;
                
            case 6:
                cout << "Enter position to delete (1 to " << list.getSize() << "): ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
                
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
                
            case 8:
                list.traverse();
                break;
                
            case 9:
                list.display();
                break;
                
            case 0:
                cout << "\n✓ Exiting program. Thank you!\n\n";
                return 0;
                
            default:
                cout << "\n✗ Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
