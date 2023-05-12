int binSearch(int arr[], int x, int left, int right) {

    if (right >= left) {

        int pivot = left + (right - left)/2;

        if (arr[pivot] == x) {
            return pivot;
        }

        if (arr[pivot] > x) {
            return binSearch(arr, x, left, pivot-1);
        }

        return binSearch(arr, x, pivot+1, right);
    }

    return -1;
}