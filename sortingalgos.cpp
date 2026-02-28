#include <cstddef>
#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <iterator>
#include <unordered_map>

using namespace std;


int partition(vector<int> &arr, int lo, int hi) {
  int i = lo;
  int j = hi;
  int pivot = arr[lo];
  while (true) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i >= j) {
      return j;
    }
    swap(arr[i], arr[j]);
  }
}

void quickSort(vector<int> &arr, int lo, int hi) {
  if (!(lo >= 0 && hi >= 0 && lo < hi)) {
    return;
  }
  int pivot = partition(arr, lo, hi);
  quickSort(arr, lo, pivot);
  quickSort(arr, pivot+1, hi);
}

void merge(vector<int>& arr, int left, int mid, int right) {
  int n1 = mid-left+1;
  int n2 = right-mid;

  vector<int> r;
  r.resize(n1);
  vector<int> l;
  l.resize(n2);
  for (int i = 0; i < n1; i++) {
    l[i] = arr[left+i];
  }
  for (int i = 0; i < n2; i++) {
    r[i] = arr[mid+i+1];
  }
  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (l[i] <= r[j]) {
      arr[k] = l[i];
      i++;
    } else {
      arr[k] = r[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = l[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = r[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int>& arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left+right)/2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, right);
}

void bubbleSort(vector<int>& arr) {

}

void insertionSort(vector<int>& arr) {

}

void countingSort(vector<int>& arr) {
  int min = INT_MAX;
  int max = -INT_MAX;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else if (arr[i] > max) {
      max = arr[i];
    }
  }
  vector<int> counts;
  counts.resize(max-min+1);
  for (int i = 0; i < arr.size(); i++) {
    counts[arr[i]-min]++;
  }

  for (int i = 0, k = 0; i < arr.size(); i++) {
    while (counts[k] == 0) {
      k++;
    }
    arr[i] = k+min;
    counts[k]--;
  }

}



void heapSort(vector<int>& arr) {

}

int main() {
  vector<int> arr = {-2,1,-3,6,-99,18,7,0};

  int arrlen = arr.size();

  for(int i = 0; i < arrlen; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  countingSort(arr);
  //mergeSort(arr, 0, arrlen-1);
  //do some sorting


  for(size_t i = 0; i < arrlen; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
