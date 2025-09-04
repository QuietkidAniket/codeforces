class Solution {
public:
    int maxPoints(vector<string>& crd, char x) {
        vector<string> flt;
        for (auto &c : crd) {
            if (c[0] == x || c[1] == x) flt.push_back(c);
        }
        if (flt.size() == 0) return 0;

        unordered_map<char,int> fx, sx; 
        int bx = 0;

        for (auto &c : flt) {
            if (c[0] == x && c[1] == x) bx++;
            else if (c[0] == x) fx[c[1]]++;
            else sx[c[0]]++;
        }

        int ans = 0;

        while (true) {
            vector<char> v;
            for (auto &p : fx) if (p.second > 0) v.push_back(p.first);
            if (v.size() < 2) break;
            fx[v[0]]--; fx[v[1]]--;
            ans++;
        }

        while (true) {
            vector<char> v;
            for (auto &p : sx) if (p.second > 0) v.push_back(p.first);
            if (v.size() < 2) break;
            sx[v[0]]--; sx[v[1]]--;
            ans++;
        }

        int left = 0;
        for (auto &p : fx) if (p.second > 0) { left = 1; break; }
        for (auto &p : sx) if (p.second > 0) { left++; break; }

        ans += min(left, bx);
        ans += (bx - min(left, bx)) / 2;

        return ans;
    }
};