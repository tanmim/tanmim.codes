#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(void){
    long long n,px,py;
    cin>>n>>px>>py;
    map<long long,long long> distance_coordinates;
    vector<long long> v;
    long long coordinates[n][2];
    for(int i=0;i<n;i++){
        cin>>coordinates[i][0]>>coordinates[i][1];
        long long dist = coordinates[i][0]*coordinates[i][0]
                + coordinates[i][1]*coordinates[i][1];
        //mymap.insert ( std::pair<char,int>('z',200) )
        distance_coordinates.insert(pair<long long, long long>(dist,i));
        v.push_back(dist);
    }
    sort(v.begin(),v.end());
    int nearest1=distance_coordinates[v[0]];
    int nearest2=distance_coordinates[v[1]];

    ;
}
