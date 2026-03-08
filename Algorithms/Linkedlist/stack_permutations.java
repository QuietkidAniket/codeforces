import java.util.*;
import java.io.*;

public class stack_permutations{
  public static void main(String args[]){
    int n = 50;
    int arr =  new arr[n+1];
    Stack<Integer> stk = new Stack<>();
    int j = 0;
    for(int i  = 0; i < n; i++){
      stk.push(i);
      while(!stk.empty() && stk.peek() == op[j]){
        stk.pop();
        j++;
      }
    }
    // if(s.isEmpty())return True;
    // else return False;
  }
}