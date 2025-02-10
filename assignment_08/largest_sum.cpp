//Given an array of integers, write a function in your preferred language to find the largest sum of a 
//contiguous subarray using an efficient algorithm.


#include "iostream"
#include <vector>

using namespace std;

int main(){
    vector<int> integers ;
    int n, num;
    cout <<"Enter the number of integers in the array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter: ";
        cin >> num;
        integers.push_back(num);
    }
    //Largest sum
    int largest_sum = 0, current_sum=0;
    for(int i:integers){
        current_sum = (i < current_sum+i)? (current_sum+i) : i;
        largest_sum = (largest_sum > current_sum)? largest_sum : current_sum;
    }
    cout << "largest sum of subarray = " << largest_sum << endl; 
    return 0;
}