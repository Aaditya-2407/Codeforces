#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void processArray(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        bool is_dark = (abs(arr[i]) % 10 == 5);
        bool is_light = (arr[i] < 50);
        
        if (is_dark && is_light) {
            arr[i] = 37; 
        } else if (is_dark) {
            arr[i] = 3;
        } else if (is_light) {
            arr[i] = 7;
        }
    }
}

int main() {
    vector<int> arr;
    int num;
    
    while (true) {
        if (cin >> num) {
            if (num == -1) break;                         
            if (num >= 0 && num <= 1000) arr.push_back(num);
        } else {
            if (cin.eof()) break; 
            
            cin.clear();          
            string garbage;       
            cin >> garbage;       
        }
    }
    
    processArray(arr);
    for (int val : arr) {
        cout << val << endl;
    }
    
    return 0;
}