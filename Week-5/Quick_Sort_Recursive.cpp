#include <iostream>
#include <chrono>

using namespace std;

// Swap the given values using pointers.
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Different data sets of different sizes.
    int input_arr[] = {100,1000,2500,5000,10000};

    // Filling the each array is reverse order of elements(To obtain the worst-case)
    for (int count : input_arr){
        int arr[count];
            for(int i=0;i<count;i++){
                arr[count-1] = i;
        }
    
        int duration_total=0;
        
        // Run the same code for 5 times and get the mean value.
        for(int j=0;j<5;j++){
            
            auto t_start = chrono::high_resolution_clock::now();       
            quickSort(arr, 0, count - 1);
            auto t_end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(t_end - t_start).count();
            duration_total = duration_total + duration;

        }
        cout << "Size of array - " << count << "\n";
        cout << "Time taken (Avg) - " <<(duration_total/5) <<"\n";
        
    }
    return 0;
}
