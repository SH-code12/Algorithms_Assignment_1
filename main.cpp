#include <iostream>
using namespace std;
int bin_se_re( int arr[8], int target, int l, int h) {
    if (l > h) {
        return -1;
    }
    int mi = (h + l) / 2;
    if (arr[mi] == target) {
        return mi;
    }
    else if (arr[mi] > target) {
        return bin_se_re(arr, target, l, mi - 1);
    }
    else {
        return bin_se_re(arr, target, mi + 1, h);
    }

}

int main() {
    int arr [8];
    cout <<"please enter sorted array of 8 elements"<< endl;
    for (int i=0; i<8;i++){
        cin >> arr[i];
    }
int target;
    cout <<"please enter the target value"<< endl;
    cin >> target;

    int res = bin_se_re(arr, target, 0, 7);

    if (res != -1) {
        cout << "Target found at index: " << res << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}
