import java.util.*;
import java.lang.*;


public class josephus_game{
  private static int find(int a, int b){
    if(a == 1)return 0;
    return (find(a-1, b) + b) %a ;
  }
  public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int n = sc.nextInt();
    for(int i =0 ;i < n ;i++){
      int a,b; 
      a=  sc.nextInt();
      b=  sc.nextInt();
      System.out.println(find(a,b));
    }
  }
}