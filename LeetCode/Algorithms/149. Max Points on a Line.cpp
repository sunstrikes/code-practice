struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        //特殊情况：1.垂直于x轴的线 2.重复的点
        unordered_map<double, int> cal;
        int maxx = 0;
        for(int i =0;i<points.size();i++){
            cal.clear();
            int repeat = 0;
            int chui = 0;
            for(int j = 0;j<points.size()&&j!=i;j++){
                if (points[j].x == points[i].x && points[j].y == points[i].y){
                    repeat++;
                    continue;
                }
                else if (points[j].x == points[j].x){
                    chui ++;
                    continue;
                }else{
                    double k = (points[j].y - points[i].y) * 1.0/(points[j].x - points[i].x);
                    if(cal.count(k) != 0){
                        cal[k]++;
                    }else{
                        cal[k]=1;
                    }
                }
            }
            for(auto it = cal.begin();it!=cal.end();it++){
                maxx = max(maxx, it->second+repeat);
            }
            maxx = max(maxx, chui+repeat);
        }
        return maxx;
    }
};