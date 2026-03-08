import java.io.*;
import java.util.*;

class Node{
  int val;
  Node next;
  Node(int val){
    this.val =val;
    this.next = null;
  }
}

class LinkedList{
  Node head;
  LinkedList(){
    head = null;
  }
  void insert(int val){
    if(head == null){
      Node new_node = new Node(val);
      head= new_node;
      return;
    }
    Node ptr = head;
    int cnt  =0 ;
    while(ptr.next != null)ptr  = ptr.next;
    Node new_node = new Node(val);
    ptr.next = new_node;
  }
  void insert(int val, int a){
    Node ptr = head;
    int cnt  =0 ;
    while(cnt != a && ptr != null)ptr  = ptr.next;
    Node new_node = new Node(val);
    ptr.next = new_node;
  }
  void create_cycle(int a, int b){
    Node ptra = head, ptrb = head;
    int cnta = 1, cntb = 1;
    while(cnta != a || cntb != b){
      if(cnta!=a){
        ptra = ptra.next;
        cnta++;
      }
      if(cntb!=b){
        ptrb = ptrb.next;
        cntb++;
      }
    }
    ptrb.next = ptra;
  }
  boolean detect_cycle(){
    Node slow= head, fast = head;
    while(slow.next != null && fast.next.next != null){
      fast = fast.next.next;
      slow = slow.next;
      if(fast == slow)return true;
    }
    return false;
  }
  Node split(){
    Node slow = head, fast =head;
    while(slow.next != null && fast.next.next != null){
      fast = fast.next.next;
      slow= slow.next;
      if(fast == slow)return true;
    }
    Node temp = slow.next;
    slow.next = null;
    return temp;
  }
  Node mergeSort(Node node){
    if(node == null || node.next == null)return node;
    Node second = split(node);
    node = mergeSort(node);
    second= mergeSort(second);
    return merge(node, second);
  }
  public merge(Node first, Node second){
    if(first == null)return second;
    if(second == null)return first;
    if(first.val < second.val){
      first.next = merge(first.next, second);
      // first.next.prev = first;
      // first.prev = null;
      return first;
    }else{
      second.next = merge(first, second.next);
      // second.next.prev = second;
      // second.prev = null;
      return second;
    }
  }
}

public class floyd_cycle{
  public static void main(String args[]){
    // Scanner sc=  new Scanner(System.in);
    Map<Node, Integer> mp = new HashMap<>();
    LinkedList l = new LinkedList();
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.create_cycle(1,3);
    Node ptr = l.head;
    boolean flag= false;
    List<Integer> ans = new ArrayList<>();
    while(ptr != null){
      if(mp.containsKey(ptr)){
        flag = true;
        break;
      }
      mp.put(ptr,1);
      ans.add(ptr.val);
      ptr = ptr.next;
    }
    if(flag)System.out.println("Cycle!");

    // for(Map.Entry<Node, Integer> e: mp.entrySet()){
    //   System.out.println("Key: "+ e.getKey().val + " Value: " +  e.getValue());
    // }
    for(Integer x: ans){
      System.out.print( x +" ");
    }
    Collections.sort(ans, Collections.reverseOrder());
    for(Integer x: ans){
      System.out.print( x +" ");
    }
  }
}