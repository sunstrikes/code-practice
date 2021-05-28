//
// Created by Sun,Minqi on 2021/5/28.
//

#pragma once
#include "../util.h"
namespace adapter {
    struct Point {
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
    };

    struct Line {
        Point start, end;
        Line(Point point, Point point1) :start(point), end(point1) {}
    };

    struct VectorObject {
        virtual std::vector<Line>::iterator begin() = 0;

        virtual std::vector<Line>::iterator end() = 0;
    };

    struct VectorRectangle: public VectorObject{
        VectorRectangle(int x, int y, int width, int height) {
            _lines.emplace_back(Line{Point(x, y), Point(x + width, y)});
            _lines.emplace_back(Line{Point(x, y), Point(x, y + height)});
            _lines.emplace_back(Line{Point(x + width, y), Point(x + width, y + height)});
            _lines.emplace_back(Line{Point(x, y + height), Point(x + width, y + height)});
        }
        std::vector<Line>::iterator begin() override {
            return _lines.begin();
        }

        std::vector<Line>::iterator end() override {
            return _lines.end();
        }
    private:
        std::vector<Line> _lines;
    };
    //绘画Line的时候需要挨个添加像素, 这时候通过增加适配器的方法实现
    class Adapter {
        typedef std::vector<Point> Points;
        Points points;
    public:
        explicit Adapter(Line& line) {
            int left = std::min(line.start.x, line.end.x);
            int right = std::max(line.start.x, line.end.x);
            int top = std::min(line.start.y, line.end.y);
            int bottom = std::max(line.start.y, line.end.y);
            int dx = right - left;
            int dy = line.end.y - line.start.y;
            if (dx == 0) {
                for (int y = top; y <= bottom; ++y) {
                    points.emplace_back(Point(left, y));
                }
            } else if (dy == 0) {
                for (int x = left; x <= right; ++x) {
                    points.emplace_back(Point(x, top));
                }
            }
        }
        friend std::ostream& operator<<(std::ostream& os, Adapter& obj) {
            for (auto& point: obj.points) {
                os << "[" << point.x << "," << point.y << "] ";
            }
            return os;
        }
    };
}


