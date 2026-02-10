import java.util.*;
import java.lang.*;

public class hamiltonian_cycle{
  static List<List<Integer>> a;
  static List<Integer> path;
  static boolean vis[];
  static int n;
  public static boolean dfs(int u ){
    vis[u] = true;
    path.add(u);

    if(path.size() == n){
      boolean cycle = false;
      for(int v : a.get(u)){
        if(v == 0){
          cycle = true;
          break;
        }
      }
      if(cycle){
        return true;
      }else{
        vis[u] = false;
        path.remove(path.size()-1);
        return false;
      }
    }

    for(int v: a.get(u)){
      if(!vis[v]){
        if(dfs(v)){
          return true;
        }
      }
    }

    vis[u] = false;
    path.remove(path.size()-1);
    return false;
  }
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    int m= sc.nextInt();

    a  = new ArrayList<>();
    vis =  new boolean[ n];
    for(int i =0 ; i <n; i++){
      a.add(new ArrayList<>());
      vis[i]  = false;
    }
    path = new ArrayList<>();

    for(int i =0 ;i< m; i++){
      int u = sc.nextInt()-1;
      int v = sc.nextInt()-1;
      a.get(u).add(v);
      a.get(v).add(u);
    }

    if(dfs(0)){
      System.out.println("Hamiltonian Cycle!");
    }else{
      System.out.println("No Hamiltonian Cycle :( ");
    }
  }
}
