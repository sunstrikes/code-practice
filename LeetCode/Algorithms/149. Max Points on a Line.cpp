struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
int maxPoints(vector<Point>& points) {
    unordered_map<double, int> slope;
    int i = 0, max_p = 0, same_p = 1, same_v = 1;
    for (i = 0; i < points.size(); same_p = 1, same_v = 1, i++) {
        for (int j = i+1; j < points.size(); j++) {
            if (points[i].y == points[j].y) 
                { if (++same_v && points[i].x == points[j].x && ++same_p); }
            else 
                slope[double(points[i].x - points[j].x) / double(points[i].y - points[j].y)]++;
        }
        max_p = max(max_p, same_v);
        for (auto item : slope) 
            { max_p = max(max_p, item.second + same_p); }
        slope.clear();
    }
    return max_p;
}
};