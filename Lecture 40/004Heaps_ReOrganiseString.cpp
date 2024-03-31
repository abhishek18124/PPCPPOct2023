
#include<iostream>
#include<queue>

using namespace std;

string reOrganise(string str) {

    int freq[26] = {0};

    // n steps

    for (char ch : str) {
        freq[ch - 'a']++;
    }

    // in the worst case we will do 26 push ops, size of maxheap will be 26

    priority_queue<pair<int, char>> maxHeap; // by default when you build a maxHeap of pair<> then maxHeap is built using the first member of the pair<>

    for (int i = 0; i < 26; i++) {

        if (freq[i] > 0) {

            maxHeap.push({freq[i], i + 'a'});

        }

    }

    // n * log (no. of distinct character)

    string out = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();

            if (maxPair.first == 1) {

                out += maxPair.second;

            } else {

                out = "";

            }

        } else { // maxHeap.size() >= 2

            pair<int, char> firstMaxPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> secondMaxPair = maxHeap.top();
            maxHeap.pop();

            out += firstMaxPair.second;
            firstMaxPair.first--;

            out += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }

        }

    }

    return out;

}

int main() {

    string str = "aaaaaabbbd";

    cout << reOrganise(str) << endl;

    return 0;
}