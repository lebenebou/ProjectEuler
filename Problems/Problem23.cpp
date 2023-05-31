
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

typedef unsigned int pos_int;

map<pos_int, pos_int> prime_factorization(const pos_int& number){

    map<pos_int, pos_int> answer;
    pos_int copy = number;

    while(copy%2==0){

        answer[2] = (answer.count(2) ? answer[2]+1 : 1);
        copy /= 2;
    }

    pos_int div = 3;

    while(copy>1){

        while(copy%div==0){

            answer[div] = (answer.count(div) ? answer[div]+1 : 1);
            copy /= div;
        }
        div+=2;
    }

    if(answer.empty()) answer[number] = 1;

    return answer;
}

pos_int sum_divisors(const pos_int& prime, const pos_int& power){

    return (pow(prime, power+1) - 1) / (prime - 1);
}

pos_int sum_divisors(const pos_int& number){

    pos_int answer = 1;
    for(auto& [prime, power] : prime_factorization(number)){

        answer *= sum_divisors(prime, power);
    }
    return answer-number;
}

const bool is_abundant(const pos_int& number){

    return sum_divisors(number)>number;
}

int main(){

    const short limit = 28123;

    pos_int answer = limit*(limit+1)/2;

    set<pos_int> cbw;
    vector<pos_int> ab_nums;

    for(short i=12; i<limit; i++){
        if(is_abundant(i)) ab_nums.push_back(i);
    }

    cout << "Filled abundant numbers" << endl;

    for(short i=0; i<ab_nums.size()-1; i++){
        
        for(short j=i; j<ab_nums.size(); j++){

            pos_int candidate = ab_nums[i] + ab_nums[j];
            // cout << "Candidate: " << candidate << " = " << ab_nums[i] << " + " << ab_nums[j] << endl;
            if(candidate <= limit){

                if(cbw.insert(candidate).second){
                    
                    answer -= candidate;
                    // cout << "Subtracted " << candidate << " became " << answer << endl;
                }
            }
        }
    }
    
    cout << answer << endl;


    return false;
}