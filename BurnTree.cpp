#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    return temp;
        
}

int height(Node* root){
    if(root==NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int find_target_tree(Node* root, int target){
    if(root==NULL)
        return 1;
    if(root->data == target)
        return 1;
    int l = find_target_tree(root->left, target);
    int r = find_target_tree(root->right, target);
    if(l==1)
        return -1;
    else
        return 1;
}

int dist_target_root(Node* root, int target){
    if(root==NULL)
        return -1;
    if(root->data == target)
        return 0;
    int l = dist_target_root(root->left, target);
    int r = dist_target_root(root->left, target);
    return (l>=0) ? l+1 : r+1;
}

int time_to_Burn(Node* root, int target){
    //check if the target is present in tree (here ignored and made sure that its always present)

    //get height of left and right sub tree;
    if(root == NULL || (root->left == NULL && root->right == NULL))
            return 0;

    int lh = height(root->left);
    int rh = height(root->right); // root is not included

    //find which tree does the taget belongs to
    int flg = find_target_tree(root, target);
    cout << flg << endl;
    //root node is target
    if(flg == 0)
        return max(lh, rh)+1;
    
    //target is in left sub tree
    else if(flg == -1){
        int dist = dist_target_root(root->left, target) +1; //root is included
        cout << dist << endl;
        return rh + dist;
    }
    //target is in right sub tree
    int dist = dist_target_root(root->right, target) +1;
    cout << dist << endl;
    return lh + dist;
}

int main(){
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->left->left->left = newNode(8); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(10); 
    root->left->right->left->left = newNode(11); 
    int target = 10 ;
    //cout << "Target can be (8, 11, 10, 6)\n";
    //enter only leaf node, tis wont work for inbetween nodes
    //cin >> target;
    cout << time_to_Burn(root, target) << endl;
}