// Largest Positive Integer That Exists With Its Negative

int findMaxK(vector<int>& a) {
    unordered_set<int> st(begin(a),end(a));
    int res = -1;
    for(int p : a) 
        if(p > 0 and st.count(-p)) res = max(res , p);
    return res;
}
