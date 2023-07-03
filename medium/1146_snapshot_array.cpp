#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
    vector<vector<pair<int, int>>> arr;
    int size;
    int curr;
    SnapshotArray(int length)
    {
        curr = 0;
        size = length;
        vector<pair<int, int>> temp;
        temp.push_back({curr, 0});
        for (int i = 0; i < length; i++)
        {
            arr.push_back(temp);
        }
    }

    void set(int index, int val)
    {
        for (auto &&i : arr[index])
        {
            if(i.first==curr){
                i.second=val;
                return;
            }
        }
        
        arr[index].push_back({curr, val});
    }

    int snap()
    {
        curr++;
        return curr - 1;
    }

    int get(int index, int snap_id)
    {
        int n=arr[index].size();
        int l=0, r=n-1;
        int ans=0;
        while (l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[index][mid].first==snap_id){
                return arr[index][mid].second;
            }
            else if(arr[index][mid].first>snap_id){
                r=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return arr[index][ans].second;
    }
};