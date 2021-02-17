#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int>  > v;
main() {
    int n, a, b;
    for(int i=0 ; i<n ;i++){
        scanf("%d %d",&a,&b);
        v.push_back( make_pair(b,a) );
    }
    sort( v.begin() , v.end() );
}
