//COUNT SORT

void countSort(int arr[], int n, int exp) {

    int output[n];
    int count[10] = { 0 };
 
    for (int i = 0; i < n; ++i) {
        if (exp == 0) {
            ++count[arr[i]];
        } else {
            ++count[(arr[i] / exp) % 10];
        }
    }
 
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
 
    for (int i = n - 1; i >= 0; --i) {
        if (exp == 0) {
            output[count[arr[i]]-1] = arr[i];
            --count[arr[i]];
        } else {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            --count[(arr[i] / exp) % 10];
        }
    }
 
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

//RADIX SORT POWERED WITH COUNT SORT
 
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}