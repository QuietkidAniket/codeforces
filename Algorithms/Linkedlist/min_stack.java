import java.util.*;
import java.io.*;

public class min_stack{
  Stack<Integer> stk;
  Stack<Integer> minstk;

  min_stack(){
    stk = new Stack<Integer>();
    minstk = new Stack<Integer>();
  }
  int getMin(){
    if(minstk.isEmpty())return -1;
    else return minstk.peek().intValue();
  }

  int peek(){
    if(stk.empty())return -1;
    else return stk.peek().intValue();
  }

  void push(int val){
    stk.push(val);
    if(!minstk.empty() && minstk.peek().intValue() >= val ){
      minstk.push(val);
    }
  }
  int pop(){
    if(stk.empty())return -1;
    int t= stk.pop();
    if(t == minstk.peek().intValue())minstk.pop();
    return t;
  }
}
