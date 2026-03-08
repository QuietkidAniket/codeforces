import java.util.*;
import java.io.*;

public class pq{
  public static void main(String args[]){
    PriorityQueue<Integer> p = new PriorityQueue<>();
    p.add(1);
    p.add(2);
    p.add(3);

    p.poll();
    p.peek();
  }
}