#include <bits/stdc++.h>
using namespace std;

struct data {
    int x, y;
};

// Cross product to determine orientation
int crossProduct(data a, data b, data c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Comparator for sorting points based on angle
bool compare(data a, data b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// Graham Scan Algorithm
vector<data> grahamScan(vector<data>& points) {
    sort(points.begin(), points.end(), compare);
    vector<data> hull;

    // Construct lower hull
    for (auto p : points) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size()-2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    // Construct upper hull
    int t = hull.size() + 1;
    for (int i = points.size() - 2; i >= 0; i--) {
        while (hull.size() >= t && crossProduct(hull[hull.size()-2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove duplicate
    return hull;
}
