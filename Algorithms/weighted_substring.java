import java.util.*;
import java.lang.*;

public class weighted_substring{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int target= sc.nextInt();

    int l = (target + 25)/26;
    int miss = target - l;
    char res[] = new char[l];
    Arrays.fill(res,'A');

    for(int i = l-1; i >= 0 ; i++){
      if(miss == 0)break;
      int add = Math.min(25, miss);
      res[i] = (char)(res[i] + add);
      miss -= add;
    }

    System.out.println(new String(res));
  }
}