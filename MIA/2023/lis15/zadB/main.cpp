#include<iostream>
using namespace std;

int main() {
    long long xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if((xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb)) == 0) {
        cout << "No";
    } else if (((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) != ((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc))) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}
