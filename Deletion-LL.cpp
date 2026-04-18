#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

Node *InputLL(Node *head)
{
  int n;
  cout << "Enter number of elements to create LL:";
  cin >> n;
  Node *temp = NULL;
  for (int i = 0; i < n; i++)
  {
    Node *newnode = new Node();
    cout << "Enter data :";
    cin >> newnode->data;
    newnode->next = NULL;

    if (head == NULL)
    {
      head = newnode;
      temp = newnode;
    }
    else
    {
      temp->next = newnode;
      temp = newnode;
    }
  }
  return head;
}
void printLL(Node *head)
{
  Node *temp = head;
  cout << "Linked List :";
  while (temp != NULL)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

Node *removeHead(Node *head)
{
  if (head == NULL)
  {
    return head;
  }
  Node *temp = head;
  head = head->next;
  delete temp;
  return head;
}

Node *removeTail(Node *head)
{

  if (head == NULL)
    return head;

  if (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  Node *temp = head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = NULL;
  return head;
}

Node *deleteK(Node *head)
{
  int k;
  cout << "Enter node position to delete :";
  cin >> k;

  if (head == NULL || k <= 0)
    return head;

  if (k == 1)
  {
    return removeHead(head);
  }
  Node *temp = head;
  int count = 1;
  Node *prev = NULL;
  while (temp != NULL && count < k)
  {
    prev = temp;
    temp = temp->next;
    count += 1;
  }
  if (temp == NULL)
  {
    return head;
  }
  prev->next = temp->next;
  delete temp;
  return head;
}

Node *deleteVal(Node *head)
{
  int value;
  cout << "Enter value(data) to delete :";
  cin >> value;
  if (head == NULL)
    return head;

  if (head->data == value)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL && temp->data != value)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
  {
    return head;
  }

  prev->next = temp->next;
  delete temp;
  return head;
}

int main()
{
  Node *head = NULL;
  head = InputLL(head);
  cout << "Your Linked List is created :" << endl;
  printLL(head);

  head = removeHead(head);
  cout << "Removing Head :" << endl;
  printLL(head);

  head = removeTail(head);
  cout << "Removing Tail :" << endl;
  printLL(head);

  head = deleteK(head);
  cout << "Removing Kth node :" << endl;
  printLL(head);

  head = deleteVal(head);
  cout << "Removing element by value :" << endl;
  printLL(head);

  return 0;
}