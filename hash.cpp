#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<long long> d;
    int n = 1e5;
    long long t = 1LL << 32;
    for (int i = 0; i < n; i++) {
        d.insert(i * t);
    }
    cout << d.size() << endl;
}