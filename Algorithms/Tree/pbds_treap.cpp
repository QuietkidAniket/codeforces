struct TreapNode {
    int key, priority, size;
    TreapNode *left, *right;
    TreapNode(int k) : key(k), priority(rand()), size(1), left(nullptr), right(nullptr) {}
};

int get_size(TreapNode* t) {
    return t ? t->size : 0;
}

void update_size(TreapNode* t) {
    if (t) t->size = 1 + get_size(t->left) + get_size(t->right);
}

void split(TreapNode* t, int key, TreapNode*& left, TreapNode*& right) {
    if (!t) left = right = nullptr;
    else if (key < t->key) split(t->left, key, left, t->left), right = t;
    else split(t->right, key, t->right, right), left = t;
    update_size(t);
}

TreapNode* merge(TreapNode* left, TreapNode* right) {
    if (!left || !right) return left ? left : right;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        update_size(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update_size(right);
        return right;
    }
}

TreapNode* insert(TreapNode* t, int key) {
    TreapNode *l, *r;
    split(t, key, l, r);
    return merge(merge(l, new TreapNode(key)), r);
}

TreapNode* erase(TreapNode* t, int key) {
    if (!t) return nullptr;
    if (t->key == key) {
        TreapNode* temp = merge(t->left, t->right);
        delete t;
        return temp;
    } else if (key < t->key) t->left = erase(t->left, key);
    else t->right = erase(t->right, key);
    update_size(t);
    return t;
}

int order_of_key(TreapNode* t, int key) {
    if (!t) return 0;
    if (key <= t->key) return order_of_key(t->left, key);
    return 1 + get_size(t->left) + order_of_key(t->right, key);
}

int find_by_order(TreapNode* t, int k) {
    if (!t) return -1;
    int left_size = get_size(t->left);
    if (k < left_size) return find_by_order(t->left, k);
    if (k == left_size) return t->key;
    return find_by_order(t->right, k - left_size - 1);
}