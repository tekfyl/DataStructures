#include <bits/stdc++.h>

#define all(c) c.begin(), c.end()
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector< vi >
#define vvl vector< vector<ll> >
#define mk make_pair
#define ii pair <int, int>
#define LL pair <ll, ll>
#define fi first
#define se second
#define mx max_element
#define mn min_element
#define rep(i,n)    for(__typeof(n) i = 0; i < n; i++)
#define rep1(i,n)   for(__typeof(n) i = 1; i <= n; i++)
double tick(){static clock_t oldt,newt=clock();double diff=100.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void print(Node *head);
void printReverse(Node *head);
Node* InsertAtEnd(Node *head, int data);
Node* InsertAtBegin(Node *head, int data);
Node* InsertAtNthPosition(Node *head, int data, int position);
Node* DeleteNthNode(Node *head, int position);
Node* Reverse(Node *head);
int CompareLists(Node *headA, Node *headB); // returns 1 if identical, 0 otherwise
Node* MergeLists(Node *headA, Node *headB);
int NthNodefromEnd(Node *head, int positionFromTail);
Node* RemoveDuplicateFromSortedList(Node *head);
bool has_cycle(Node *head);
int FindMergePoint(Node *headA, Node *headB);

int main(){
    ios_base::sync_with_stdio(false);
    Node *head, *headA, *headB; 
    int data, position;
    while(1){
        int in; cin >> in;
        cout << "Operations:\n";
        cout << "1  : print\n2  : printReverse\n3  : InsertAtEnd\n4  : InsertAtBegin\n5  : InsertAtNthPosition\n6  : DeleteNthNode\n7  : Reverse\n 8  : CompareLists\n";
        cout << "9  : MergeLists\n10 : NthNodefromEnd\n11 : RemoveDuplicateFromSortedListlicates\n12 : has_cycle\n13 : FindMergePoint\n14 : Quit\n";
        switch(in){
            case 1: 
                print(head);
                break;
            case 2:
                printReverse(head);
                break;
            case 3:
                cout << "Enter Data:  ";
                cin >> data;
                head = InsertAtEnd(head, data);
                break;
            case 4:
                cout << "Enter Data:  ";
                cin >> data;
                head = InsertAtBegin(head, data);
                break;
            case 5:
                cout << "Enter Data:  ";
                cout << endl << "Enter Position:  ";
                cin >> data >> position;
                head = InsertAtNthPosition(head, data, position);
                break;
            case 6:
                cout << "Enter Position:  ";
                head = DeleteNthNode(head, position);
                break;
            case 7:
                head = Reverse(head);
                break;
            case 8:
                cout << CompareLists(headA, headB);
                break;
            case 9:
                headA = MergeLists(headA, headB);
                break;
            case 10:
                cout << "Enter Position:  ";
                cin >> position;
                head = DeleteNthNode(head, position);
                break;
            case 11:
                head = RemoveDuplicateFromSortedList(head);
                break;
            case 12:
                cout << has_cycle(head);
                break;
            case 13:
                cout << FindMergePoint(headA, headB);
                break;
            case 14:
                return 0;
                break;
            default:
                continue;
        }
    }
    //cout<<"\n"<<"Execution time : "<<tick()<<"\n";
    return 0;
}

void print(Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// Recursive definition below. Other way is to traverse the linked list and store in vector/stack, reverse it and then print it
void printReverse(Node *head){
   if(head == NULL){
       return;
   }
   printReverse(head->next);
   cout << head->data << endl;
}

Node* InsertAtEnd(Node *head,int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }
    Node *t = head;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = temp;
    return head;
}

Node* InsertAtBegin(Node *head,int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return head;
    }
    
    temp->next = head;
    head = temp;
    return head;
}

Node* InsertAtNthPosition(Node *head, int data, int position){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(position == 0){
        temp->next = head;
        head = temp;
        return head;
    }
    Node *t = head;
    for(int i=0; i<position-1; i++){
        t = t->next;
    }
    temp->next = t->next;
    t->next = temp;
    return head;
}

Node* DeleteNthNode(Node *head, int position){
    if(head == NULL){
        return head;
    }
    if(position == 0){
        return head->next;
    }
    Node *t = head;
    for(int i=0; i<position-1; i++){
        t = t->next;
    }
    t->next = t->next->next;
    return head;
}

Node* Reverse(Node *head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* nextNode = head->next;
    head->next = NULL;
    Node* newHead = Reverse(nextNode);
    nextNode->next = head;
    return newHead;
}

// Retrun 1 if identical, 0 otherwise
int CompareLists(Node *headA, Node* headB){
    if(headA == NULL && headB == NULL) return 1;
    if(headA == NULL || headB == NULL) return 0;
    if(headA->data == headB->data){
        return CompareLists(headA->next, headB->next);
    }
    else return 0;
}

Node* MergeLists(Node *headA, Node* headB){
    if (headA == NULL && headB == NULL) return NULL;
    else if (headA == NULL) return headB;
    else if (headB == NULL) return headA;

    if(headA->data <= headB->data)
        headA->next = MergeLists(headA->next, headB);
    else{
        Node* temp = headB;
        headB = headB->next;
        temp->next = headA;
        headA = temp;
        headA->next = MergeLists(headA->next, headB);
    }

return headA;
}

int NthNodefromEnd(Node *head,int positionFromTail){
    int index = 0;
    Node* current = head;
    Node* result = head;
    while(current!=NULL){
        current=current->next;
        index++;
        if (index > positionFromTail) result=result->next;
    }
    return result->data;
}

Node* RemoveDuplicateFromSortedList(Node *head){
    if(head == NULL) return head;
        Node *current=head;
        while(current->next != NULL){
            (current->data != current->next->data) ? current=current->next : current->next = current->next->next;
            }
    return head;
}

bool has_cycle(Node* head){
   if(head == NULL) return 0;
    Node *s, *f; s=head; f=head; // s-slow, f-fast
    while(f != NULL && f->next != NULL){
        s = s->next; f=f->next->next;
        if(s==f) return 1;
    }
    return 0;
}

int FindMergePoint(Node *headA, Node *headB){
    Node *a, *b;
    a = headA;
    b = headB;
    while(a != b){
        if(a == NULL){
            a = headB;
        }
        else a = a->next;
        if(b == NULL){
            b = headA;
        }
        else b = b->next;
    }
    return a->data;
}

