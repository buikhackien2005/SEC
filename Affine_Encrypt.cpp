#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    string p;
    string c = "";
    while(true){
        cout << "Plain text: ";
        cin >> p;
        cout << "Input a and b: ";
        cin >> a >> b;
        if(a > 25 || b > 25 || __gcd(a, 26) != 1){
            cout << "K is not valid! Please try again!\n";
            continue;
        }
        for(int i = 0; i < p.size(); i++){
            c = c + char((a * (p[i] - 'a') + b)%26 + 'a');
        }
        cout << "Cipher text: " << c << '\n';
    }

}

