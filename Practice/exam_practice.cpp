#include<bits/stdc++.h>
using namespace std;


void deleteValue(list<int> &l, int value) {
  for (auto i = l.begin(); i != l.end(); i++) {
    if (*i == value) {
      l.erase(i);
      break;
    }
  }
}

int main() {
  list<int> l;
  int n, value;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int item;
    cin >> item;
    l.push_back(item);
  }
  cin >> value;
  deleteValue(l, value);


  for (auto i= l.begin(); i != l.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;
  return 0;
}
