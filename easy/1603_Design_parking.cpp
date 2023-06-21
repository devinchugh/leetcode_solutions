#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
    int big, med, small;
    ParkingSystem(int biger, int medium, int smaller)
    {
        big = biger;
        med = medium;
        small = smaller;
        //cout<<big<<' '<<med<<' '<<small;
    }

    bool addCar(int carType)
    {
        if(carType==3 && small>0){
            small--;
            return true;
        }
        if(carType==2 &&  med>0){
            med--;
            return true;
        }
        if(carType==1 && big>0){
            big--;
            return true;
        }
        return false;
    }
};
