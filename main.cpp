#include <iostream>
using namespace std;
int search(int sorted[], int target,int size){
int ri= size-1;
int le= 0;
while(le<=ri){
    int mid = le + (ri - le) / 2;
    if (sorted[mid] == target) {
        return mid;}
    else if (sorted[mid] < target) {
        le = mid + 1;}
    else
        ri= mid-1;
}
return -1;

}
int main() {
    int n;
cout<< "please enter size of the sorted list"<<endl;
cin >>n;
    int list[n];
cout <<"please enter the sorted list"<< endl;
for (int i=0; i<n;i++){
    cin >> list[i];
}
    int value ;
cout<<"please enter the target value"<<endl;
    cin >> value;
   int res= search(list,value,n);
    if (res!=-1)
        cout <<"the index of target num is "<< res<<endl;
    else
        cout<<"target value not found"<<endl;

    return 0;
}
