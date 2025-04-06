// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i]+arr[j] == value) count++;
    }
  }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int high = len - 1;
  while (high > 0) {
      if (arr[high] + arr[0] > value) {
          high--;
      }
      else break;
  }
  for (int i = 0; i < len; i++) {
      for (int j = high; j > i; j--) {
          if (arr[i]+arr[j] == value) count++;
      }
  }
  return count;
}
int binSearch(int *arr,int left, int right, int value) {
  int pos = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      pos = mid;
      if (firstone) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return pos;
}
int countPairs3(int *arr, int len, int value) {
  int countAll = 0;
  for (int i = 0; i < len; i++) {
    int item = value - arr[i];
    int firstItem = binSearch(arr, i + 1, len - 1, item, true); 
    if (firstItem != -1) {
        int lastItem = binSearch(arr, i + 1, len - 1, item, false);
        countAll+= (lastItem - firstItem + 1);
    }
  }
return countAll;
}
