import java.util.*;
import java.lang.*;

class comp implements Comparator<String>{
  @Override
  public int compare(String a, String b){
    return a.compareTo(b);
  }
}


public class natural_sort{
  public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int n = sc.nextInt();

    String a[] = new String[n];

    for(int i =0 ;i < n ;i++)a[i] = sc.next();

    // Arrays.sort(a);
    // Arrays.sort(a, Collections.reverseOrder());
    Arrays.sort(a, new comp());

    for(int i =0 ;i < n ;i++){
      System.out.println(a[i] + " ");
    }
  }
}