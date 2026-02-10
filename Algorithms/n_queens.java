import java.util.*;
import java.lang.*;


class Main{
  public static boolean check(int grid[][], int row, int col){ 
    int n = grid.length;
    boolean flag = false;
    for(int r =0 ;r < n; r++){
      if(grid[r][col] == 1)return false;
    }
    for(int c =0 ;c < n; c++){
      if(grid[row][c] == 1)return false;
    }
    // upper left diagonal
    int r = row;
    int c = col;
    while(r >= 0 && c >=0){
      if(grid[r][c] == 1){
        return false;
      }
      r--; c--;
    }

    // upper right diagonal
    r = row; c = col;
    while(r >= 0 && c < n){
      if(grid[r][c] == 1){
        return false;
      }
      r--; c++;
    }

    // lower left diagonal
    r = row; c = col;
    while(r < n && c >= 0){
      if(grid[r][c] == 1){
        return false;
      }
      r++; c--;
    }

    // lower right diagonal
    r = row; c = col;
    while(r < n && c < n){
      if(grid[r][c] == 1){
        return false;
      }
      r++; c++;
    }
    return true;
  }

  public static int find(int col, int grid[][]){
    int n = grid.length;
    if(col == n){
      return 1;
    }
    int cnt = 0;
    for(int row = 0 ; row < n; row++){
      if(check(grid, row, col)){
        grid[row][col] = 1;
        cnt += find(col+1, grid);
        grid[row][col] = 0;
      }
    }
    return cnt;
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int grid[][]  = new int[n][n]; //  0 - > no Q, 1 -> Q
    for(int i =0 ;i < n; i++){
      for(int j = 0; j <n; j++){
        grid[i][j] = 0;
      }
    }
    System.out.println("count : " + find(0, grid));
  }
}