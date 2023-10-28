#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<double> &A, vector<double> &B) {
    if (A.size() > B.size()) {
        swap(A, B);
    }

    int m = A.size();  // Length of the smaller array
    int n = B.size();  // Length of the larger array

    int low = 0;
    int high = m;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (n + m + 1) / 2 - i;

        double A_left_max = (i > 0) ? A[i - 1] : numeric_limits<double>::min();
        double A_right_min = (i < m) ? A[i] : numeric_limits<double>::max();
        double B_left_max = (j > 0) ? B[j - 1] : numeric_limits<double>::min();
        double B_right_min = (j < n) ? B[j] : numeric_limits<double>::max();

        if (A_left_max <= B_right_min && B_left_max <= A_right_min) {
            if ((m + n) % 2 == 0) {
                return (max(A_left_max, B_left_max) + min(A_right_min, B_right_min)) / 2.0;
            } else {
                return max(A_left_max, B_left_max);
            }
        } else if (A_left_max > B_right_min) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted or not in the correct order.");
}

int main() {
    vector<double> A = {1.0, 3.0, 8.0};
    vector<double> B = {2.0, 7.0};

    double result = findMedianSortedArrays(A, B);
    cout << "Median: " << result << endl;

    return 0;
}
