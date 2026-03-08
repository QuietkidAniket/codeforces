import java.util.*;
import java.io.*;

public class celebrity{
  public static void main(String args[]){
    int n= 40;
    int mat[n][n]; // adjacency  matrix
    Stack<Integer> stk = new Stack<>();
    for(int i= 0 ;i< n ; i++)stk.push(i);

    while(stk.size() > 1){
      int a = stk.pop();
      int b = stk.pop();
      if(mat[a][b])stk.push(b); // if a knows b
      else stk.push(a);
    }
    // finally check the celebrity candidate ... 
  }
}