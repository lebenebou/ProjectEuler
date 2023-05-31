
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef short num;
typedef vector<vector<num>> triangle;

void display(const vector<num>& v){

    for(auto num : v) cout << num << " ";
}

void display(const triangle& pyramid){

    for(auto row : pyramid){

        display(row);
        cout << endl;
    }
}

template<typename Type>
const Type max(const vector<Type>& v){

    if(v.size()==0) return -1;
    if(v.size()==1) return v[0];
    if(v.size()==2) return (v[0] > v[1] ? v[0]:v[1]);

    // size is at least 3
    Type answer = v[0];
    for(size_t i=1; i<v.size(); i++){

        if(v[i] > answer) answer = v[i];
    }
    return answer;
}

void fill(triangle& pyramid, vector<num>& values, const size_t& rows){

    for(size_t r=0; r<rows; r++){

        num start_index = r*(r+1)/2;
        vector<num> row;

        for(num i=start_index; i<=start_index+r; i++){

            row.push_back(values[i]);
        }
        pyramid.push_back(row);
    }
}

int main(){

    vector<num> values = {75, 95, 64, 17, 47, 82, 18, 35, 87, 10, 20, 4, 82, 47, 65, 19, 1, 23, 75, 3, 34, 88, 2, 77, 73, 7, 63, 67, 99, 65, 4, 28, 6, 16, 70, 92, 41, 41, 26, 56, 83, 40, 80, 70, 33, 41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
    const size_t row_count = 15;

    triangle pyramid; // this pyramid has sets of rows, each row has values
    fill(pyramid, values, row_count);
    
    // method
    // https://www.youtube.com/watch?v=LbkwKLqpi0w&ab_channel=JakeGoodman
    for(size_t r = row_count-1; r>0; r--){

        for(size_t index = 0; index < r; index++){

            pyramid[r-1][index] += max(pyramid[r][index], pyramid[r][index+1]);
        }
    }
    cout << pyramid[0][0] << endl;

    return 0;
}
