struct segtree{
    vector<int>tree;
    int sz;
    void init(int n){
        sz=1;
        sz<<=__lg(n)+1;
        tree.assign(sz*2-1,0);
    }
    void set(int x,int lx,int rx,int i,int v){
        if(rx-lx==1){
            tree[x]+=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(x*2+1,lx,m,i,v);
        }
        else{
            set(x*2+2,m,rx,i,v);
        }
        tree[x]=tree[x*2+1]+tree[x*2+2];
    }
    void set(int i,int v){
        set(0,0,sz,i,v);
    }
    int get(int x,int lx,int rx,int l,int r){
        if(r<=lx || rx<=l){
            return 0;
        }
        if(l<=lx && r>=rx){
            return tree[x];
        }
        int m=(lx+rx)/2;
        return get(x*2+1,lx,m,l,r)+get(x*2+2,m,rx,l,r);
    }
    int get(int l,int r){
        return get(0,0,sz,l,r);
    }
};