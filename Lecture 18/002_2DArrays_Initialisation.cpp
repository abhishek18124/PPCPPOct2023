#include<iostream>

using namespace std;

int main() {

    int arr[][4] = {
        {10, 15, 20},
        {30, 35, 40, 45},
        {50, 55}
    };

    int m = 3;
    int n = 4;

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;

    int brr[3][4] = {};

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int crr[3][4] = {0};

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << crr[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;

    int drr[3][4];

    memset(drr, 0, sizeof(drr));

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << drr[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;

    return 0;
}