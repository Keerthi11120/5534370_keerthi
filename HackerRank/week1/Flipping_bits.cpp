#include <iostream>
#include <cstdint>   // for uint32_t
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

// Function to trim whitespace from the left
string ltrim(const string &s) {
    string result = s;
    result.erase(result.begin(), find_if(result.begin(), result.end(),
                                        [](unsigned char ch) { return !isspace(ch); }));
    return result;
}

// Function to trim whitespace from the right
string rtrim(const string &s) {
    string result = s;
    result.erase(find_if(result.rbegin(), result.rend(),
                         [](unsigned char ch) { return !isspace(ch); }).base(), result.end());
    return result;
}

// Function to flip all bits of a 32-bit unsigned integer
uint32_t flippingBits(uint32_t n) {
    return ~n;  // Bitwise NOT flips all bits
}

int main() {
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        uint32_t n = stoul(ltrim(rtrim(n_temp)));
        uint32_t result = flippingBits(n);

        cout << result << "\n";
    }

    return 0;
}
