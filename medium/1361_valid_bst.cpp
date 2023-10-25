#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=findroot(n,leftChild, rightChild);
        if(root==-1){
            return 0;
        }
        stack<int> st;
        set<int> seen;
        st.push(root);
        seen.insert(root);

        while (!st.empty())
        {
            int val=st.top();
            st.pop();
            
            int l=leftChild[val];
            if(l!=-1 && seen.find(l)!=seen.end()){
                return 0;
            }
            else if(l!=-1){
                st.push(l);
                seen.insert(l);
            }
            int r=rightChild[val];
            if(r!=-1 && seen.find(r)!=seen.end()){
                return 0;
            }
            else if(r!=-1){
                st.push(r);
                seen.insert(r);
            }

        }
        return seen.size()==n;
        
    }

    int findroot(int n, vector<int>& leftChild, vector<int>& rightChild){
        
        set<int> children;
        for (auto &&i : leftChild)
        {
            children.insert(i);
        }
        for (auto &&i : rightChild)
        {
            children.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if(children.find(i)==children.end()){
                return i;
            }
        }
        return -1;
        
        
    }
};