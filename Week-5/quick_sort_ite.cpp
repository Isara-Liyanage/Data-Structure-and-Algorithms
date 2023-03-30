#include <iostream>
#include <stack>
#include <chrono>
using namespace std;

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
    stack<int> stack;
    stack.push(low);
    stack.push(high);

    while (!stack.empty())
    {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            stack.push(low);
            stack.push(pi - 1);
        }

        if (pi + 1 < high)
        {
            stack.push(pi + 1);
            stack.push(high);
        }
    }
}

int main() {
    int input_arr[] = {100,1000,2500,5000,10000};

    for (int count : input_arr){
        int arr[count];
            for(int i=0;i<count;i++){
                arr[count-1] = i;
        }
    
        int duration_total=0;

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
