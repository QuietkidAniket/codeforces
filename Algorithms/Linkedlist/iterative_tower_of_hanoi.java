import java.util.*;
import java.io.*;

class iterative_tower_of_hanoi{
  int f(int n, int s, int d, int a){
    if(n == 1){
      // move disk 1 from s to d
      return ;
    }
    f(n-1, s, a, d); // source to auxiliary
    // move disk n from s to a
    f(n-2, a, d, s) //  from auxiliary to destination
  }
}