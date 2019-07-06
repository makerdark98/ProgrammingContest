#include <iostream>
#define sci(n) scanf("%d", &(n))
#define scc(n) scanf(" %c", &(n))
using namespace std;
struct cell {
  char color;
  int value;
};
struct ind {
  cell data[4][4];
};
cell now[5][5];
int n;
ind inds[10];
using P_T = cell[5][5];
P_T cal_ind[10][4][4];
int visited[10];
void init_now(){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      now[i][j].color = 'W';
      now[i][j].value = 0;
    }
  }
}
void push_ind(int x, int dir, int pos) {
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      now[i][j].color = cal_ind[x][dir][pos][i][j].color=='W' ? now[i][j].color : cal_ind[x][dir][pos][i][j].color;
      now[i][j].value += cal_ind[x][dir][pos][i][j].value;
      now[i][j].value = now[i][j].value > 0 ? now[i][j].value : 0;
      now[i][j].value = now[i][j].value < 9 ? now[i][j].value : 9;
    }
  }
}
void init_cal_ind(){
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        for(int l=0;l<5;l++){
          for(int m=0;m<5;m++){
            cal_ind[i][j][k][l][m].color = 'W';
            cal_ind[i][j][k][l][m].value = 0;
          }
        }
      }
    }
  }
}

int cal_value() {
  int result = 0;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      switch(now[i][j].color) {
        case 'R':
          result += 7*now[i][j].value;
          break;
        case 'B':
          result += 5*now[i][j].value;
          break;
        case 'G':
          result += 3*now[i][j].value;
          break;
        case 'Y':
          result += 2*now[i][j].value;
          break;
      }
    }
  }
  return result;
}
inline int getr(int r, int c, int dir){
  switch(dir) {
    case 0:
      return r;
    case 1:
      return c;
    case 2:
      return 3-r;
    case 3:
      return 3-c;
  }
  return 0;
}
inline int getc(int r, int c, int dir){
  switch(dir) {
    case 0:
      return c;
    case 1:
      return 3-r;
    case 2:
      return 3-c;
    case 3:
      return r;
  }
}
int main(){
  sci(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        sci(inds[i].data[j][k].value);
      }
    }
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        scc(inds[i].data[j][k].color);
      }
    }
  }

  init_cal_ind();



  int rs[4] = {0, 0, 1, 1};
  int cs[4] = {0, 1, 0, 1};
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        for(int dir=0;dir<4;dir++){
          for(int pos=0;pos<4;pos++){
            cal_ind[i][dir][pos][rs[pos]+ getr(j,k,dir) ][cs[pos]+ getc(j,k,dir)].color = inds[i].data[j][k].color;
            cal_ind[i][dir][pos][rs[pos]+ getr(j,k,dir) ][cs[pos]+ getc(j,k,dir)].value = inds[i].data[j][k].value;
          }
        }
      }
    }
  }

  int result = 0;
  for(int i=0;i<n;i++){
    visited[i] = 1;
    for(int j=0;j<n;j++){
      if (visited[j]) continue;
      visited[j] = 1;
      for(int k=0;k<n;k++){
        if (visited[k]) continue;
        visited[k] = 1;
        for(int id=0;id<4;id++){
          for(int jd=0;jd<4;jd++){
            for(int kd=0;kd<4;kd++){
              for(int ip=0;ip<4;ip++){
                for(int jp=0;jp<4;jp++){
                  for(int kp=0;kp<4;kp++){
                    init_now();
                    push_ind(i, id, ip);
                    push_ind(j, jd, jp);
                    push_ind(k, kd, kp);
                    int tmp = cal_value();
                    result = result > tmp ? result : tmp;
                  }
                }
              }
            }
          }
        }
        visited[k] = 0;
      }
      visited[j] = 0;
    }
    visited[i] = 0;
  }
  printf("%d", result);
  return 0;
}
