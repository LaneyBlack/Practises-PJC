#include <iostream>
#include <cmath>

const double *aver(const double *arr, size_t size, double &average) {
    for (int i = 0; i < size; ++i) {
        average+=arr[i];
    }
    average/=size;
    const double *closest = &arr[0];
    for (int i = 0; i < size; ++i) {
        closest = (fabs((*closest-average)) < fabs((arr[i]-average)))?closest:&arr[i];
    }
    return closest;
}

int main() {
    using std::cout, std::endl;
    double arr[] = {1, 2, -1.5, 3.25, 5.5, 7.75, -0.25, 5.75};
        size_t size = std::size(arr); //sizeof(arr)/arr[0]);
        double average = 0;
        const double * p=aver(arr,size,average);
        cout << *p << " " << average << endl;
    return 0;
}

