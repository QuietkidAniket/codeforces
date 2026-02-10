import java.util.*;
import java.lang.*;


public class generate_permutations{


  private static boolean next_permutation(int a[]){ 
    int n= a.length;
    int pivot = n -2;
    while(pivot >= 0 && a[pivot] >= a[pivot+1])pivot--;
    if(pivot < 0){
      reverse(a, 0, n-1);
      return false;
    }

    int succ = n-1;
    while(succ >= 0 && a[succ] <= a[pivot])succ--;

    swap(a, succ, pivot);

    reverse(a, pivot+1, n-1);
    return true;
  }

  private static void reverse(int a[], int start, int end){
    while(start < end){
      swap(a, start, end);
      start++;
      end--;
    }
  }
  private static void swap(int a[], int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);

    int n= sc.nextInt();
    int a[] =  new int[n];
    for(int i =1; i <= n; i++){
      a[i-1] =i;
    }
    int cnt = 0;
    do{ 
      cnt++;
      for(int i =0 ;i <n; i++)System.out.print(a[i] + " ");
      System.out.println();
    }while(next_permutation(a));
    System.out.println("count : " + cnt);
  }
}