#include <bits/stdc++.h>

using namespace std;

void heapify(double array[], int N, int i) {
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && array[left] > array[largest]) largest = left;
    if (right < N && array[right] > array[largest]) largest = right;
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, N, largest);
    }
}

void heapSort(double array[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) heapify(array, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}


const int NMAX = 1000000;

long long dur[10];
char file_name[200];

int main() {
    auto *a = new double[NMAX + 10];

    cout << "[Heap Sort] Running..." << endl;

    for (unsigned int i = 0; i < 10; i++) {
        memset(file_name, 0, sizeof(file_name));
        sprintf(file_name, "./Testcase/test%u.inp", i + 1);
        ifstream File(file_name);

        for (unsigned int j = 0; j < NMAX && (!File.eof()); j++) File >> a[j];
        File.close();

        auto begin = std::chrono::high_resolution_clock::now();
        heapSort(a, NMAX);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        dur[i] = duration.count();
        cout << "Test " << i + 1 << ": " << duration.count() << "ms" << endl;
    }

    ofstream File("out.py", ios::app);
    File << "\n";
    File << "heapSort = [";
    for (int i = 0; i < 10; i++) {
        File << dur[i];
        if (i < 9) File << ", ";
    }
    File << "]\n";
    return 0;
}