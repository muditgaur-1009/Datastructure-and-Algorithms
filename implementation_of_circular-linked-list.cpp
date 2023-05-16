#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
};
struct Node *insertInEmpty(struct Node *last, int new_data)
{
    if (last != NULL)
        return last;

    struct Node *temp = new Node;
    temp->data = new_data;
    last = temp;
    last->Next = last;
    return last;
};
void traverseList(struct Node *last)
{
    struct Node *p;

    // If list is empty, return.
    if (last == NULL)
    {
        cout << "Circular linked List is empty." << endl;
        return;
    }
    p = last->Next; // Point to the first Node in the list.

    // Traverse the list starting from first node until first node is visited again

    do
    {
        cout << p->data << "==>";
        p = p->Next;
    } while (p != last->Next);
    if (p == last->Next)
        cout << p->data;
    cout << "\n\n";
}

int main()
{

    struct Node *last = NULL;

    last = insertInEmpty(last, 30);
    cout << "The circular linked list created is as follows:" << endl;
    traverseList(last);

    return 0;
}