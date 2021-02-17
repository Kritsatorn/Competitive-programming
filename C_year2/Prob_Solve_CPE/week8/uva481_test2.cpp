#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int lis[1000000];
queue<int> path[100000];

int main(){

    int n;
    while(cin>>n){
        v.push_back(n);
    }
    n = v.size();

    for(int i=0;i<n;i++){
       lis[i] = 1;
       path[i].push(v[i]);
    }

    int maior = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j] < v[i] && lis[j]+1 > lis[i]){
                lis[i] = lis[j]+1;

                path[i] = path[j];
                path[i].push(v[i]);
            }
        }
    }


    for(int i=0;i<n;i++)
        if (lis[i] > maior) maior = lis[i];

    for(int i=n-1;i>=0;i--){
        if(maior == lis[i]){
            printf("%d\n-\n", maior);
            while(!path[i].empty()){
                printf("%d\n", path[i].front());
                path[i].pop();
                //if(j+1 == maior) printf("%d", path[i][j+1]);
            }
            //printf("%d", path[i][maior-1]);
            return 0;
        }
    }
    return 0;

}