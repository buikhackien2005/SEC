#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    string c;
    string p = "";
    while(true){
        cout << "Cipher text: ";
        cin >> c;
        cout << "Input a and b: ";
        cin >> a >> b;
        if(a > 25 || b > 25 || __gcd(a, 26) != 1){
            cout << "K is not valid! Please try again!\n";
            continue;
        }
        for(int i = 1; i < 26; i++)
            if((a*i)%26 == 1){
                a = i;
                break;
            }
        for(int i = 0; i < c.size(); i++){
            int x = ((a * ((c[i] - 'a') - b))%26 + 26)%26;
            p = p + char(x + 'a');
        }
        cout << "Plain text: " << p << '\n';
    }
}
