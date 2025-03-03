#include <iostream>
#include <omp.h>

using namespace std;

double calculateAvarage(int arr[], int N) {
    long long tong = 0;  

    #pragma omp parallel for reduction(+:tong) 
    for (int i = 0; i < N; i++) {
        tong += arr[i];
    }

    return (double)tong / N; 
}

int main() {
    int N;
    cout << "Nhập số phần tử của mảng: ";
    cin >> N;

    int *arr = new int[N]; 
    cout << "Nhập các phần tử của mảng:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    double trungBinh = calculateAvarage(arr, N);
    cout << "Giá trị trung bình của mảng là: " << trungBinh << endl;

    delete[] arr; 
    return 0;
}
