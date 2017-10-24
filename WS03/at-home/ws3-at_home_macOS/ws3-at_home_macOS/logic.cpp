#include <iostream>
using namespace std;


int main() {
    
    
    int sin = 193456787;
    int tmp, ss, sum, sum10s;
    // by iteration: 8, 7, 6, 5, 4, 3, 9, 2
    int even = 0, odd = 0;
    for (int i = 0; i < 9; ++i) {
        ss = sin/10;
        tmp = ss%10;
        if (tmp%2 == 0) {   // add by itself
            even += int(tmp*2/10) + int(tmp*2%10);
        }
        else {
            // number is odd
            odd += tmp;
        }
    }
    sum = even + odd;
    sum10s = int(sum/10) * 10 + 10;
    
}
