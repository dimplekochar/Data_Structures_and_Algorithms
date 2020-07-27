#include <iostream> 
#include <cstdlib>
using namespace std; 
  
struct node {
    int value;
    node* left;
    node* right;
};

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
}

node* createNode(int value){
    node* newNode;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insertLeft(node *root, int value) {
    root->left = createNode(value);
    return root->left;
} 


node* insertRight(node *root, int value){
    root->right = createNode(value);
    return root->right;
}


  int main(){
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    struct node* root=createNode(a[0]);
    struct node* root1=root;
    for (int i=1; i<n; i++){
      int b=0;
      root=root1;
      cin >> a[i];
      if (a[i]<root->value && root->left==NULL)
        insertLeft(root, a[i]);
      else if (a[i]>root->value && root->right==NULL)
        insertRight(root, a[i]);
      else if (root->left!=NULL && root->right!=NULL){
        while(b==0){
          root=root->left;
          if (a[i]<root->value && root->left==NULL){
            insertLeft(root, a[i]); 
            b=1;
          }
          else if (a[i]>root->value && root->right==NULL){
            insertRight(root, a[i]); 
            b=1;
          }
          else{
            root=root->right;
            if (a[i]<root->value && root->left==NULL){
              insertLeft(root, a[i]); 
              b=1;
            }
            else if (a[i]>root->value && root->right==NULL){
              insertRight(root, a[i]); 
              b=1;
            }

          }
        }
      }
    } 
  }