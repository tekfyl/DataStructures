#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* insert(node *root, int value);
void find_bst(node *bst, int e);
void levelOrder(node *root);
int height(node *root);
void inOrder(node *root);
void postOrder(node *root);
void visit(node *root);
void preOrder(node *root);
void topViewLeft(node *root);
void topViewRight(node *root);
void topView(node *root);
void decode_huff(node *root, string s);

int main(){
    std::ios_base::sync_with_stdio(false);
    int choice;
    node *root = new node;
        root = NULL;
     while(1){
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout << "2.Find Element "<<endl;
        //cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Level Order"<<endl;
        cout<<"7. Top View"<<endl;
        cout<<"8.Height of BST"<<endl;
        cout<<"15.Quit"<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;
        cout << "\n\n\n\n";
        
        switch(choice){
            case 1:
                int value; cin >> value;
                root = insert(root, value);
                break;
            case 2:
                int e; cin >> e;
                find_bst(root,e);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                preOrder(root);
                break;
            case 5:
                postOrder(root);
                break;
            case 6:
                levelOrder(root);
                break;
            case 7:
                topView(root);
                break;
            case 8:
                cout << height(root) << endl;
                break;

            case 15:
                return 0;
                break;

            default:
                cout << "Number not in option" << endl;
        }
        cout << endl << "Want to Continue? (y/n)" << endl;
        char c; cin >> c;
        c == 'y' ? 1 : cout << "Quit then!" << endl;
    }
    return 0;
}

node* insert(node *root, int value) {
    if(root == NULL){
        node *temp = new node;
        temp->data = value;
        temp->left = temp->right = NULL;
        root = temp;
    }
    else if(root->data > value){
       root->left =  insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
   return root;
}

void find_bst(node *bst, int e){
    if (bst == NULL) cout << "NOT FOUND\n";
    else if (bst->data == e) cout << "Found\n";
    else if (bst->data<e) return find_bst(bst->right, e);
    else return find_bst(bst->left, e);
}

void levelOrder(node *root) {
      queue<node*> q;
      node *temp = root;
      q.push(temp);
      while(!q.empty()){
          if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            visit(temp);
      
        q.pop();
        temp = q.front(); 
    }
}

int height(node *root) {
        return (root == NULL ? -1 : max(height(root->left), height(root->right)) +1);
}

void inOrder(node *root) {
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    visit(root);
    inOrder(root->right);
}

void postOrder(node *root) {
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    visit(root);
}

void visit(struct node *root){
    cout << root->data << " ";
}

void preOrder(node *root) {
        if (root == NULL){
            return;
        }
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
}

void topViewLeft(node *root){
    if(root == NULL){
            return;
        }
    topViewLeft(root->left);
    visit(root);
}

 void topViewRight(struct node *root){
     if(root == NULL){
            return;
        }
     visit(root);
     topViewRight(root->right);     
 }

void topView(node * root) {
    if(root == NULL){
        return;
    }
    topViewLeft(root->left);
    visit(root);
    topViewRight(root->right);
}

node* lca_bst(node *root, int v1,int v2)
{
        if(root->data > v1 && root->data > v2) return lca_bst(root->left, v1, v2);
        else if(root->data < v1 && root->data < v2) return lca_bst(root->right, v1, v2);
    return root;
}

void decode_huff(node * root,string s)
{
    node *t = root;
    for(auto c:s){
        t = (c == '0'? t->left : t->right);
        if(t->data){
            cout << t->data;
            t = root;
        }
    }
}

