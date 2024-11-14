#include <iostream>
#include <climits>
using namespace std;

// Function to find the minimum number of multiplications needed to multiply the matrices
int matrixChainOrder(int p[], int n) {
    // m[i][j] will hold the minimum number of multiplications needed to compute the product of matrices i through j
    int m[n][n];

    // No cost for multiplying one matrix
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            // Calculate minimum cost of splitting the chain at every possible point
            for (int k = i; k <= j - 1; k++) {
                // q is the cost of splitting at k
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    // The minimum cost is found in m[1][n-1]
    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter the dimensions of matrices:\n";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int minCost = matrixChainOrder(p, n + 1);
    cout << "Minimum number of multiplications is " << minCost << endl;

    return 0;
}
