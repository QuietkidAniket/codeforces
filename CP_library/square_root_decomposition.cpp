square class Sqrt_decomposition{
 private:
int n;
vector<int> a; // actual array
vector<int> block; // block representation of the array, stores minimum in each block
int block_size; // size of block
int s; // no . of blocks
public:
void init(const vector<int>& arr){
  this->n = arr.size();
  this->a= arr;
  this->block_size = max(1ll,(int)sqrt((int)a.size()));
  this->s = (n+block_size-1)/block_size;
  build();
}
void build(){
  block.resize(s, 1e9);
  for(int i = 0; i < n; i++){
    int idx= i/block_size;
    block[idx] = min(block[idx], a[i]);
  }
}

int query(int l, int r){
  int ans = 1e9;
  int left_block = l / block_size;
  int right_block = r / block_size;

  // l,r within a single block
  if (left_block == right_block) {
      for (int i = l; i <= r; ++i) ans = min(ans, a[i]);
      return ans;
  }

  // left partial block
  int left_end = min(n - 1, (left_block + 1) * block_size - 1);
  for (int i = l; i <= left_end; ++i) ans = min(ans, a[i]);

  // full blocks
  for (int b = left_block + 1; b <= right_block - 1; ++b) {
      ans = min(ans, block[b]);
  }

  // right partial block
  int right_start = right_block * block_size;
  for (int i = right_start; i <= r; ++i) ans = min(ans, a[i]);

  return ans;
}
void update(int i, int new_val){
  a[i]  = new_val;
  int blk_id = i/block_size;
  block[blk_id] = 1e9;
  for(int idx = blk_id*block_size; idx < min(n, (blk_id+1)*block_size) ; idx++){
    block[blk_id] = min(a[idx], block[blk_id]);
  }
}
};