#include <iostream>
#include <vector>

using namespace std;

void add_element(vector<int> &out, int element);
float get_median(vector<int> out);

int main(){

    // This array refers to the output in the take home assignment.
    int input_array[] = {35,7,12,5,2,73,6,8,19,3,56};
    vector<int> out;

    for(int element : input_array){

        add_element(out,element);
        // Printing the ouput array.
        for(int ele : out){
            cout<<ele<<" ";
        }
        cout<<"    ";
        //Printing the median.
        cout << "Median is ";
        printf("%.2f",get_median(out));
        cout<<"\n";
    }
    return 0;
}

void add_element(vector<int> &out, int element){
    // If the array lenght is 0 then add the element to the vector.
    if (out.size() == 0){
        out.push_back(element);
        return;
    }
    int index = 0;
    // To check whether the vector updated.
    bool changed = false;

    for(int i=0;i<out.size();i++){
        if (element < out[i]){
            index=i;
            changed = true;
            break;
        }
    }
    // If vector didn't change, the element should go to the last index.
    if (! changed){
        out.push_back(element);
        return;
    }
    else{
        out.insert(out.begin()+index,element);
        return;
    }
    return;
}

float get_median(vector<int> out){
    if (out.size()%2==1){
        return out[(out.size()-1)/2.0];
    }
    else{
        return ((out[out.size()/2]+out[(out.size()/2)-1])/2.0);
    }
}
