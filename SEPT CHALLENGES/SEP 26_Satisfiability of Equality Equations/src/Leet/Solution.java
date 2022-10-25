package Leet;

public class Solution {
    public boolean equationsPossible(String[] equations) {
        UnionFind unionFind = new UnionFind();
        for(int i=0; i < equations.length; i++) {
        if (equations[i].charAt(1) == '=') {
            unionFind.union(equations[i].charAt(0)-'a', equations[i].charAt(3)-'a');
        }
    }
        for (int i=0; i< equations.length; i++) {
            if (equations[i].charAt(1)=='!'&&unionFind.isConnect(equations[i].charAt(0)-'a', equations[i].charAt(3)-'a')) {
                return false;
            }
        }
        return true;
}
public class UnionFind{
        private int[] parent;
        public UnionFind() {
            this.parent = new int[26];
            for (int i=0; i<26; i++) {
                parent[i] = i;
            }
        }
        public int find(int x) {
            if (x!=parent[x]) {
            parent[x] = find(parent[x]);
        }
            return parent[x];
    }
    public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if( rootX==rootY ) {
                return;
            }
            parent[rootX]=rootY;
        }
        public boolean isConnect(int x, int y) {
            return find(x)==find(y);
        }
}
}