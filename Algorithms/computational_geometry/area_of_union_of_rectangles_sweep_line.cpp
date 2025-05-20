#include <bits/stdc++.h>
using namespace std;

struct data {
    int x, y1, y2, type;
};

// Sweep Line Algorithm for Union Area of Rectangles
long long unionArea(vector<tuple<int, int, int, int>>& rects) {
    vector<data> events;
    for (auto& r : rects) {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = r;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
    }
    sort(events.begin(), events.end(), [](data a, data b) { return a.x < b.x; });

    map<int, int> active;
    int prevX = 0;
    long long area = 0;

    for (auto& e : events) {
        int x = e.x, y1 = e.y1, y2 = e.y2, type = e.type;
        long long width = x - prevX;
        long long height = 0, prevY = -1;

        for (auto it = active.begin(); it != active.end(); ++it) {
            if (prevY == -1) prevY = it->first;
            else height += it->first - prevY, prevY = it->first;
        }
        area += width * height;

        if (type == 1) active[y1]++, active[y2]--;
        else if (--active[y1] == 0) active.erase(y1), active[y2]--;
    }
    return area;
}
