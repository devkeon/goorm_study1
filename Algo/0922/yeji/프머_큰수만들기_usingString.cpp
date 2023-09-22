#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) {
  stack<int> s;
  string answer;
  int cnt=0;

  for(int i=0;i<number.length();i++){
    
    while(!answer.empty() && answer.back() < number[i] && k>0){
      answer.pop_back();
      k-=1;
    }
    answer.push_back(number[i]);
  }
  

  
  while(k>0){
    answer.pop_back();
    k--;
  }
  
  
  
  return answer;
   
}

int main(){
  string answer ="";
  string number = "4177252841";
  int k = 4;

  answer = solution(number,k);

  cout << "정답:" << answer << endl;
}