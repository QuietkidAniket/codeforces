class stock_span{
  public static void main(String args[]){
    int n = 50;
    Stack<Integer> stk = new Stack<>();
    int arr[n+1]; // we know the values of stocks on ith day
    int ans[n+1];
    for(int i =1;i <= n; i++){
      while(!stk.empty() && arr[stk.peek()] <= arr[i])stk.pop();
      ans[i] = stk.isEmpty()? (i+1): (i-stk.peek());
      stk.push(i);
    }
  }
}