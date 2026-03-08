#undef int
template<typename T>
using mset = tree<
   pair<T, int>, // use index or timestamp to break ties
   null_type,
   less<pair<T, int>>,
   rb_tree_tag,
   tree_order_statistics_node_update>;
#define int long long