#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calculateSi(int M1, int M2) {
    return (((M1 & M2) ^ (M1 | M2)) * (M1 ^ M2));
}

long long findMaxSi(const vector<int>& A) {
    int n = A.size();
    long long maxSi = 0;

    // Use a stack to efficiently find M1 and M2 for all adjacent pairs
    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && stack.back() <= A[i]) {
            int M2 = stack.back();
            stack.pop_back();
            if (!stack.empty()) {
                int M1 = stack.back();
                maxSi = max(maxSi, calculateSi(M1, M2));
            }
        }
        stack.push_back(A[i]);
    }

    // Handle remaining elements in the stack
    while (stack.size() > 1) {
        int M2 = stack.back();
        stack.pop_back();
        int M1 = stack.back();
        maxSi = max(maxSi, calculateSi(M1, M2));
    }

    return maxSi;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << findMaxSi(A) << endl;

    return 0;
}
