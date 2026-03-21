#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> status;
    vector <int> seed;
    vector <int> T;
    for(int i = 0; i < 10; i++)
        status.push_back(i);
    seed.push_back(1); seed.push_back(2);
    seed.push_back(3); seed.push_back(6);
    int index = 0;
    while(T.size() < 10){
        T.push_back(seed[index]);
        index = (index + 1) % seed.size();
    }
     for(int i = 0; i < 10; i++)
         cout << T[i] << ' ';
     cout << '\n';

    int j = 0;
    for(int i = 0; i < 10; i++){
        j = (j + status[i] + T[i]) % 10;
        swap(status[i], status[j]);
        for(int i = 0; i < 10; i++)
         cout << status[i] << ' ';
     cout << '\n';
    }


    string input = "cybersecurity";
    int times = 0;
    int i = 0;
    j = 0;
    while(times < 10){
        i = (i + 1)%10;
        j = (j + status[i])%10;
        swap(status[i], status[j]);
        int ti = (status[i] + status[j])%10;
        int k = status[ti];
        int c = input[times] - 'a';
        cout << char(k ^ c);
        times++;
    }
    cout << '\n';
}
