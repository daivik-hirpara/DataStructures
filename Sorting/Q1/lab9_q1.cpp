#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void selection_sort(int a[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
            swap(a[min], a[i]);
    }
}

void insertion_sort(int a[], int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = a[p + i];
    for (int i = 0; i < n2; i++)
        right[i] = a[q + i + 1];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quick_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}

void max_heapify(int a[], int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < n && a[l] > a[i])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heapify(a, largest, n);
    }
}
void build_max_heap(int a[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        max_heapify(a, i, n);
}
void heap_sort(int a[], int n)
{
    build_max_heap(a, n);
    for (int i = n; i >= 1; i--)
    {
        swap(a[0], a[i]);
        max_heapify(a, 0, i);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int a[n];
    cout << "Enter unsorted array: ";

    for (int i = 0; i < n; i++)
    cin >> a[i];

    int choice;
    cout << "1. Bubble Sort"<<endl;
    cout << "2. Selection Sort"<<endl;
    cout << "3. Insertion Sort"<<endl;
    cout << "4. Merge Sort"<<endl;
    cout << "5. Quick Sort"<<endl;
    cout << "6. Heap Sort"<<endl;
    cout << "7. Exit"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            bubble_sort(a, n);
            break;
        case 2:
            selection_sort(a, n);
            break;
        case 3:
            insertion_sort(a, n);
            break;
        case 4:
            merge_sort(a, 0, n - 1);
            break;
        case 5:
            quick_sort(a, 0, n - 1);
            break;
        case 6:
            heap_sort(a, n - 1);
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice!"<<endl;
            return 0;
    }
    

    cout << "Sorted array: "<<endl;
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
    cout << endl;
    return 0;
}
