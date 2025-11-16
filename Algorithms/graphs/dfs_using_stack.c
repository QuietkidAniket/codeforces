#include "stdio.h"
#include "stdlib.h"
#include "string.h"
const int MAXN = 1e5+1;

int top = -1;
int* stk;

void push(int val){
  if(stk == NULL)stk = (int*)malloc(MAXN*sizeof(int));
  if(top+1 == MAXN)printf("Stack overflow!\n");
  stk[++top] = val;
}
int get_size(){
  return top;
}
int get_top(){
  return stk[top];
}
void pop(){
  if(top == -1)printf("Stack underflow!\n");
  else stk[top--] = 0;
}
int empty(){
  return top == -1;
}


int main(){
  int n, m; 
  scanf("%d", &n);
  scanf("%d", &m);
  
  int** adjl =  (int**)malloc(n*sizeof(int*));
  int* size = (int*)calloc(n, sizeof(int));
  
  for(int i = 0 ;i <n; i++)adjl[i] = NULL;

  for(int i =0 ;i < m ;i++){
    int u, v; 
    scanf("%d", &u);
    scanf("%d", &v);
    adjl[u] = realloc(adjl[u], ((size[u]+1) * (int)sizeof(int)));
    adjl[u][size[u]++] = v;
  }

  int* vis = (int*)calloc(n, sizeof(int));
  for(int node =0 ; node <n; node++){
    if(!vis[node]){
      // add the first node
      push(node);
      // do the dfs on the added node
      while(!empty()){
        int cur_node = get_top();
        printf("%d " , cur_node);
        pop();
        int sz = size[cur_node];
        for(int i =sz-1 ;i >=0 ; i--){
          int adjnode = adjl[cur_node][i];
          if(vis[adjnode])continue;
          vis[adjnode]= 1;
          push(adjnode);
        }
      }
    }
  }
  for(int i =0 ;i < n ;i++){
    free(adjl[i]);
  }
  free(adjl);
  free(size);
  free(vis);
  free(stk);
}