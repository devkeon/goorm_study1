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

  for(int i=number.length()-1;i>0;i--){
    s.push(number[i]-'0');
  }

  while(!s.empty()){
    if(cnt>=k){
      break;
    }
    if(answer==""){
      answer+=s.top()+'0';
      s.pop();
    }else if(s.top()>answer.back()-'0'){
      if(cnt<k-1){
        cnt++;
        answer.pop_back();
        answer.push_back(s.top()+'0');
        s.pop();
      }else{
        answer.push_back(s.top()+'0');
        s.pop();
      }
     
    }else if(s.top()<=answer.back()-'0'){
      answer.push_back(s.top()+'0');
      s.pop();
    }
  }
  if(!s.empty()){
    answer.push_back(s.top()+'0');
    s.pop();
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