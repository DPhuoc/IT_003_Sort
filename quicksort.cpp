#include <bits/stdc++.h>
using namespace std;

void quickSort(double a[], int l, int r) {
    double p = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j) {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }
        if (i <= j) {
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r) {
        quickSort(a, i, r);
    }
    if (l < j) {
        quickSort(a, l, j);
    }
}

const int NMAX = 1000000;

long long dur[10];
char file_name[200];


int main() {
    auto *a = new double[NMAX + 1];

    cout << "[Quick Sort] Running..." << endl;

    for (unsigned int i = 0; i < 10; i++) {
        memset(file_name, 0, sizeof(file_name));
        sprintf(file_name, "./Testcase/test%u.inp", i + 1);
        ifstream File(file_name);

        for (unsigned int j = 0; j < NMAX && (!File.eof()); j++) File >> a[j];
        File.close();

        auto begin = std::chrono::high_resolution_clock::now();
        quickSort(a, 0, NMAX - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        dur[i] = duration.count();
        cout << "Test " << i + 1 << ": " << duration.count() << "ms" << endl;
    }

    ofstream File("out.py", ios::app);
    File << "\n";
    File << "quickSort = [";
    for (int i = 0; i < 10; i++) {
        File << dur[i];
        if (i < 9) File << ", ";
    }
    File << "]\n";

    return 0;
}