/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    // time : O(nlogn)

    // priority_queue<int, vector<int>, greater<int>> minHeap;

    // for(int i=0; i<ropeLengths.size(); i++) {
    //     minHeap.push(ropeLengths[i]);
    // }

    // priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end()); // [start, end)

    // int total = 0;

    // while (minHeap.size() > 1) {

    //     int fs = minHeap.top();
    //     minHeap.pop();

    //     int ss = minHeap.top();
    //     minHeap.pop();

    //     total += fs + ss;

    //     minHeap.push(fs + ss);

    // }

    // cout << total << endl;

    // time : O(nlogn)

    set<int> s(ropeLengths.begin(), ropeLengths.end()); // [start, end)

    int total = 0;

    while (s.size() > 1) {

        int fs = *s.begin();
        s.erase(s.begin()); // s.erase(fs)

        int ss = *s.begin();
        s.erase(s.begin()); // s.erase(ss)

        total += fs + ss;

        s.insert(fs + ss);

    }

    cout << total << endl;



    return 0;
}