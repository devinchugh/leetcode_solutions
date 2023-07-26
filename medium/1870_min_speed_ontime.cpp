#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double timetravel(vector<int> &dist, int speed){

        double ans = 0;
        for (int i = 0; i < dist.size()-1; i++)
        {
            int x= ceil((double)dist[i]/speed);
            ans+=x;
        }
        ans+=dist[dist.size()-1]/(double)speed;
        return ans;
        
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        // dist -> Train Detials in series to be used
        // hour -> total hours available;

        int n = dist.size();

        if (n-1>=hour)
        {
            return -1;
        }

        int l = 1;
        int r = 10000000;
        bool found = 0;
        int mid;

        while (l <= r)
        {
            mid = l+(r-l)/2;
            double timetotravel = timetravel(dist,mid);
            //cout<<mid<<' '<<timetotravel<<endl;
            if(timetotravel==(double)hour){
                return mid;
            }
            else if (timetotravel < hour)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};