#include <iostream>
#include <array>
#include <iterator>


using namespace std;

template<typename  Type>
int getArrLen(Type arr[]) {
  if(sizeof(arr) <= 0) {return 0;}
  return sizeof(arr)/sizeof(Type);
}

template<typename Type>
void outputArr(Type arr[]) {
  int arrLen = getArrLen(arr);
  for(int i = 0; i < arrLen; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {2,5,3,6,18,5,99};
  outputArr(arr);
  //do some sorting
  outputArr(arr);
}
