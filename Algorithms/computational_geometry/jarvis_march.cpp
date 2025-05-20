#include <bits/stdc++.h>
using namespace std;

struct data {
    int x, y;
};

// Orientation function to check turn direction
int orientation(data a, data b, data c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Jarvis March Algorithm
vector<data> jarvisMarch(vector<data>& points) {
    int n = points.size();
    if (n < 3) return {};

    vector<data> hull;
    int l = 0;

    // Find leftmost point
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x) l = i;

    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;

        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) > 0)
                q = i;

        p = q;
    } while (p != l);

    return hull;
}
