#include <iostream>
#include <array>
#include <iterator>


using namespace std;

template<typename  T>
int getArrLen(T arr[]) {
  if(sizeof(arr) <= 0) {return 0;}
  return sizeof(arr)/sizeof(T);
}

int main() {
  int arr[] = {2,5,3,6,18,5,99};
  int arrLen = getArrLen(arr);
  for(auto i = 0; i < arrLen; i++) {
    cout << arr[i] << " ";
  }
  //do some sorting

}
