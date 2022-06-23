// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void findParent(Node * root, unordered_map<Node*,Node*>& parents)
    {
        if(root==NULL) return;
        if(root->left){
            parents[root->left] = root;
            findParent(root->left,parents);
        }
        if(root->right) {
            parents[root->right] = root;
            findParent(root->right,parents);
        }
    }
    
    Node* findTarget(Node*root, int target){
        if(!root) return nullptr;
        if(root->data == target) return root;
        Node* l = findTarget(root->left, target);
        if(l) return l;
        return findTarget(root->right,target);
    }
    
    int minTime(Node* root, int target) 
    {
        if(!root) return 0;
        unordered_map<Node*,Node*> parents;
        findParent(root,parents);
        unordered_map<Node*,bool> vis;
        queue<Node*>q;
        int time_ = 0 ;
        Node* tgt = findTarget(root,target);
        vis[tgt] = true;
        q.push(tgt);
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                if(parents.find(curr)!=parents.end()){
                    Node * par = parents[curr];
                    if(!vis[par]){
                        vis[par] = true;
                        flag = true;
                        q.push(par);
                    }
                }
                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = true;
                    flag = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = true;
                    flag = true;
                    q.push(curr->right);
                }
            }
            if(flag == true)time_+=1;
        }
        return time_;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends