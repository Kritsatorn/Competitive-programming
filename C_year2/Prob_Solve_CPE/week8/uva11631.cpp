#include <bits/stdc++.h>
using namespace std;

class FUCK {
  public:
    FUCK(int size);
    int findSet(int a);
    bool isSameSet(int a, int b);
    void unionSet(int a, int b);
    int numDisjointSets();
    int sizeOfSet(int a);
  private:
    int size;
    vector<int> pset;
    vector<int> set_size;
};

FUCK::FUCK(int size) {
  this->size = size;

  set_size.assign(size, 1);
  pset.assign(size, 0);

  for (int i = 0; i < size; i++)
    pset[i] = i;
}

int FUCK::findSet(int a) {
  return pset[a] == a ? a : (pset[a] = findSet(pset[a]));
}

bool FUCK::isSameSet(int a, int b) {
  return findSet(a) == findSet(b);
}

void FUCK::unionSet(int a, int b) {
  if (isSameSet(a, b)) return;

  size--;
  set_size[findSet(b)] += set_size[findSet(a)];
  pset[findSet(a)] = findSet(b);
}

int FUCK::numDisjointSets() {
  return size;
}

int FUCK::sizeOfSet(int a) {
  return set_size[findSet(a)];
}

int main(void) {
  int m, n;
  int a, b, c;

  while (cin >> m >> n) {
    if (m == 0 && n == 0)
      break;

    int sum = 0;
    priority_queue< pair<int, pair<int,int> > > edgeList;

    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c;
      sum += c;
      edgeList.push(make_pair(-c, make_pair(a, b)));
    }

    int mst_cost = 0;
    FUCK ds(m);

    while (!edgeList.empty()) {
      pair< int, pair<int,int> > front = edgeList.top();
      edgeList.pop();

      if (!ds.isSameSet(front.second.first, front.second.second)) {
        mst_cost += (-front.first);
        ds.unionSet(front.second.first, front.second.second);
      }
    }

    cout << sum - mst_cost << endl;
  }

  return 0;
}