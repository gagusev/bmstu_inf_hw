#define SWAP(a, b) ({ IndexSizeBundle tmp = *a; *a = *b; *b = tmp; })

typedef struct
{
    int index;
    int size;
} IndexSizeBundle;

int partition(IndexSizeBundle arr[], int low, int high)
{
    int pivot = arr[high].size;

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j].size < pivot)
        {

            i++;
            SWAP(&arr[i], &arr[j]);
        }
    }
    SWAP(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(IndexSizeBundle arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}