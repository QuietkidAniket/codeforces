#undef int
template<typename Key, typename Value>
using omap = tree<
    Key,
    Value,
    less<Key>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
#define int long long