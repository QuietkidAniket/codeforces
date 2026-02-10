import java.util.*;
import java.lang.*;

public class manachers{
  static int[] p;

  public static void run_manacher(String s){
    int n = s.length();
    p = new int[n];
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = Math.min(right - i, p[mirror]);

        // Expand around center i
        while (s.charAt(i + p[i] + 1) == s.charAt(i - p[i] - 1))
            p[i]++;

        // Update center and right boundary
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
  }

  public static void build(String s){
    StringBuilder  t = new StringBuilder();
    t.append("^");
    for(char c : s.toCharArray()){
      t.append("#");
      t.append(c);
    }
    t.append("#$");
    run_manacher(t.toString());
  }
  public static int get_longest(){
    int best = 0;
    int n = p.length;
    for(int i =1 ; i <n-1; i++){
      best = Math.max(best, p[i]);
    }
    return best;
    
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    String s=  sc.next();
    build(s);
    System.out.println("" + get_longest());
  }
}


// abbabba
// babbabbabc