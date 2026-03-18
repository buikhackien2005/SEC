#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> status;
    vector <int> seed;
    for(int i = 0; i < 10; i++)
        status.push_back(i);
    seed.push_back(2); seed.push_back(4);
    seed.push_back(1); seed.push_back(7);
    int index = 0;
    while(seed.size() < 10){
        seed.push_back(seed[index]);
        index = (index + 1) % seed.size();
    }
    for(int i = 0; i < 10; i++)
        cout << seed[i] << ' ';
}