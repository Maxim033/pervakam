#include <algorithm> 
#include <iostream> 
#include <set> 
using namespace std;

int main2()
{
    // int[]
    set<int> set1 = {10, 20, 30, 40, 11, 60};
    set<int> set2 = {10, 30, 50, 40, 60, 80, 10, 11};

    set<int> result;
 
    set_intersection(set1.begin(), set1.end(), set2.begin(),
        set2.end(),
        inserter(result, result.begin()));
 
    cout << "Intersection of two sets: ";
    for (int i : result)
        cout << i << " ";

}