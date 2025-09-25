#include <iostream>
#include <algorithm>
using namespace std;

string decToBinary(int n) {
  
  	// String to store the binary representation
    string bin = ""; 
	
    while (n > 0) {
      
        // Finding (n % 2) using bitwise AND operator
        // (n & 1) gives the least significant bit (LSB)
        
        int bit = n & 1;
        bin.push_back('0' + bit);
      	
        // Right shift n by 1 (equivalent to n = n / 2)
        // This removes the least significant bit (LSB)
        n = n >> 1;
    }
  	
    reverse(bin.begin(), bin.end());
    return bin;
}

int main() {
    int n = 12;
    cout << decToBinary(n);
    return 0;
}
