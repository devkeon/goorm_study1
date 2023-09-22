#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 상어 상태
// 바다 맵의 상태


/*
🦈 일단 상어
1. 상어는 돌아다니며 냄새를  뿌린다 -> 좌표필요
2. 각 상어 마다 방향 우선순위가 있다 -> 방향 우선순위필요
3. 
*/ 
struct shark{
  // 상어의 위치
  int y;
  int x;
  // 상어의 생존 여부
  bool live;
  // 상어의 방향(이 방향에 따라 우선순위가 결정)
  int dir;
  // 상어의 방향 우선순위
  vector<int> priority[5];
};

int dy[]={0,-1,1,0,0};
int dx[]={0,0,0,-1,1};



//상어들을 모아두기 위한 배열
shark sharks[500];


/*
🌊 바다맵
1. 상어마다 뿌리고 간 냄새를 위치별로 기록해야 한다.
(몇번 상어가 뿌렸는가? 언제 뿌렸는가?)
2. 한 칸에 여러 마리의 상어가 남아 있으면 가장 작은 번호를 가진 상어를 제외하고 죽여야한다.
*/

struct Sea{
  int time;
  int host;
  vector<int> stay;
};


Sea sea[21][21];


// 이제 입력을 받자
int N,M,k;


void input(){
  
  // 순서대로 격자의 크기, 상어의 갯수, 우선순위의 갯수, 냄새 소멸 시간 
  cin >> N >> M >> k;
  
  for(int i =0;i<N;i++){
    for(int j=0;j<N;j++){
      int pos;
      cin >> pos;
      if(pos==0){
        // 아무도 냄새 안뿌림, 아직 냄새 없음
        sea[i][j].time = 0;
        sea[i][j].host = 0;
      }else{
        // 상어 냄새 기록
        sea[i][j].stay.emplace_back(i); // 이 자리에는 pos 번 상어가 냄새 뿌림
        //sea[i][j].time = k; // 냄새 지속 시간 힛

        // 상어에게도 정보를
        sharks[pos].y = i;
        sharks[pos].x = j;
      }
    }
  }


  for(int i=1;i<=M;i++){
    // 상어마다 방향 부여와 함께 생명을 불어넣어 주기
    cin >> sharks[i].dir;
    sharks[i].live = true;
  }

  for(int i=1;i<=M;i++){
    for(int j=1;j<=4;j++){
      for(int k=1;k<=4;k++){
        int p;
        cin >> p;
        sharks[i].priority[j].emplace_back(p);
      }
    }
  }
}

// 냄새 뿌리기
void setting_smell(int Time){
  for(int i=1;i<=M;i++){
    if(sharks[i].live == false)
      continue;
    
    int x = sharks[i].x;
    int y = sharks[i].y;
    sea[y][x].time = Time + k; // 현재시간 + 냄새유지시간
    sea[y][x].host = i; // 해당 좌표에 호스트를 i번 상어로 셋팅
  }
}


// 상어이동
void move(int Time){
  // sea stay 배열 비워주고 시작하좌
  for(int i=1;i<=M;i++){
    if(sharks[i].live == false){
      continue;
    }
    int y = sharks[i].y;
    int x = sharks[i].x;
    sea[y][x].stay.clear();
  }

  // sharks move
  for(int i=1;i<=M;i++){

    if(sharks[i].live== false){
      continue;
    }

    bool success = false;
    // 못 움직일 경우 원래 위치에서 꼼짝 못하니 원래 위치 값 저장해두고 있짜.
    int init_y, init_x, init_dir;
    init_y= init_x= init_dir = -1;
    // 현재 위치 값 넣어주기
    int y = sharks[i].y;
    int x = sharks[i].x;
    int d = sharks[i].dir;
    
    for(int s=0;s<sharks[i].priority[d].size();s++){

      int go = sharks[i].priority[d][s]; // 우선순위대로 시작
      int ny = y + dy[go];
      int nx = x + dx[go];

      // 범위 체크
      if(ny>=0 && nx>=0 && ny<N && nx<N){
        if(sea[ny][nx].time <=Time){
          sharks[i].y = ny;
          sharks[i].x = nx;
          sharks[i].dir = go;
          sea[ny][nx].stay.emplace_back(i);// i 번 상어 들어갑니다
          success = true; // 이동했따는 플래그
          break;// 한번에 한칸만

        }else{ // 범위 밖을 넘어가진 않았지만, 냄새가 남아있어서 못감
          if(sea[ny][nx].host == i){ // 못움직였는데 이 자리..내 냄샌가?
            if(init_y==-1){
              init_x = nx;
              init_y = ny;
              init_dir = go;
            }
          }
        }
      }
    }
    if(!success){
      sharks[i].y = init_y;
      sharks[i].x = init_x;
      sharks[i].dir = init_dir;
      sea[init_y][init_x].stay.push_back(i);// 특정 지점에 상어 쏙
    }
  }
}



// 상어제거
void kill(){
  // 상어의 정보로 딱 그 좌표만 조사하자.
  for(int i=1;i<=M;i++){

    if(sharks[i].live == false){
      continue;
    }
    int y = sharks[i].y;
    int x = sharks[i].x;

    if(sea[y][x].stay.size()>=2){
      sort(sea[y][x].stay.begin(),sea[y][x].stay.end());
      int live_shark = sea[y][x].stay[0];// 맨 앞 상어는 일단 뺴고
      for(int j =1;j<sea[y][x].stay.size();j++){
        //상어 죽이기
        int kill_shark = sea[y][x].stay[j];
        sharks[kill_shark].live = false;
      }
      sea[y][x].stay.clear();// 다시 초기화
      sea[y][x].stay.push_back(live_shark);// 맨 앞 상어였던 애를 다시 넣어줌
      sea[y][x].host=live_shark; // 맨 앞 상어였던 애를 그 좌표의 호스트로
    }
  }
}

// 생존확인
bool isLive(){
  
  for(int i=2;i<=M;i++){
    if(sharks[i].live == true){
      return false;
    }
  }
  return true;
}


void play(){

  input();

  for(int time = 0;time<1001;time++){
    if(isLive()==true){
      cout << time << '\n';
      return;
    }
    setting_smell(time);
    move(time);
    kill();
  }
  cout << -1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  play();

  return 0;
}