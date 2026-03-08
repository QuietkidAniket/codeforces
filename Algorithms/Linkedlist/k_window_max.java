import java.util.*;
import java.io.*;

class k_window_max{
  public static void main(String args[]){
    int n = 50,k =10;
    int arr[]= new int[50];
    ArrayList<Integer> ans = new ArrayList<>();
    Deque<Integer> dq = new ArrayDeque<>();
    for(int i =0; i < n; i++){
      while(!dq.isEmpty() && i-k+1 > dq.peekFirst())dq.removeFirst();
      while(!dq.isEmpty() && arr[i] > arr[dq.peekLast()])dq.removeLast();
      dq.addLast(i);
      if(i >= k-1)ans.add( arr[dq.peekFirst()]);
    }
  }
}