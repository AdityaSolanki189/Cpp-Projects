#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 * 
 *  HackerRank Answer:
 * 
 *  Node Reverse(Node head) {

    We have two conditions in this if statement.
    This first condition immediately returns null
    when the list is null. The second condition returns
    the final node in the list. That final node is sent
    into the "remaining" Node below.
    -----------------------------------------------------

    if (head == null || head.next == null) {  
        return head;  
    }

    When the recursion creates the stack for A -> B -> C
    (RevA(RevB(RevC()))) it will stop at the last node and
    the recursion will end, beginning the unraveling of the
    nested functions from the inside, out. 
    -----------------------------------------------------

    Node remaining = Reverse(head.next);

    Now we have the "remaining" node returned and accessible
    to the node prior. This remaining node will be returned
    by each function as the recursive stack unravels.

    Assigning head to head.next.next where A is the head
    and B is after A, (A -> B), would set B's pointer to A,
    reversing their direction to be A <- B.
    -----------------------------------------------------

    head.next.next = head; 

    Now that those two elements are reversed, we need to set
    the pointer of the new tail-node to null.
    -----------------------------------------------------

    head.next = null;  

    Now we return remaining so that remaining is always
    reassigned to itself and is eventually returned by the
    first function call.
    -----------------------------------------------------

    return remaining; 
    }
*/

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(head->next == NULL || head == NULL){
        return head;
    }
    SinglyLinkedListNode* remaining = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return remaining;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        SinglyLinkedListNode* llist1 = reverse(llist->head);

        print_singly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
