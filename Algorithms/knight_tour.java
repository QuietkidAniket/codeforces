import java.util.*;
import java.lang.*;


public class knight_tour{
  static int board[][];
  static final int[] dx = {1,1,2,2,-1,-1,-2,-2};
  static final int[] dy = {2,-2,1,-1,2,-2,1,-1};
  static int n;

  static class WM implements Comparable<WM>{
    int degree;
    int move;
    public WM(int degree, int move){
      this.degree= degree;
      this.move= move;
    }

    @Override
    public int compareTo(WM a){
      return Integer.compare(this.degree, a.degree);
    }
  }


  public static boolean check(int x, int y){
    return x>= 0 && y >=0 && x < n && y< n &&  board[x][y] == -1;
  }

  public static int getDeg(int x, int y){
    int cnt = 0;  
    for(int i =0 ;i < 8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(check(nx, ny))cnt++;
    }
    return cnt;
  }

  public static boolean find(int x, int y, int mvcount){
    board[x][y] = mvcount;
    if(mvcount == n*n){
      return true;
    }

    List<WM> neighbours = new ArrayList<>();
    for(int i =0;i < 8; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(check(nx, ny)){
        neighbours.add( new WM(getDeg(nx, ny), i));
      }
    }

    Collections.sort(neighbours);

    for(WM obj : neighbours){
      int i = obj.move;
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(check(nx, ny)){
        if(find(nx, ny, mvcount+1))return true;
      }
    }
    board[x][y] = -1;
    return false;

  }



  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    n= sc.nextInt();
    board = new int[n][n];
    for(int i =0 ;i < n; i++){
      Arrays.fill(board[i], -1);
    }
    if(find(0,0,1)){
      for(int i =0 ;i < n; i++){
        for(int j =0 ;j < n; j++){
          System.out.printf("%3d",board[i][j]);
        }
        System.out.println();
      }
    }else{
      System.out.println("Solution doesnt exist");
    }
  }
}