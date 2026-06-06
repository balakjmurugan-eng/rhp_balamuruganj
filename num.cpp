#include <iostream>
#include <iostream>
using namespace std;
void check(string s){
    int digits=0;
    for(char c:s){
        if(c>='0' && c<='9')
            digits |= (1<<(c-'0'));
    }
    cout<<(digits == ((1<<10)-1) ? "yes" : "no")<<endl;
}
int main(){
    string s;
    getline(cin,s);
    check(s);
    return 0;
}
