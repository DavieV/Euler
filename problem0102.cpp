#include <iostream>
#include <cmath>

struct point {
    int x;
    int y;
};

std::istream& operator >>(std::istream& is, point& p) {
    point tmp;
    is >> tmp.x >> tmp.y;
    if (is)
        p = std::move(tmp);
    return is;
}

int area(point a, point b, point c);
bool contains_origin(point a, point b, point c);

int main() {
    point a, b, c;
    int count = 0;
    while (std::cin >> a >> b >> c) {
        if (contains_origin(a, b, c))
            ++count;
    }
    std::cout << count << std::endl;
    return 0;
}

bool contains_origin(point a, point b, point c) {
    point o;
    o.x = 0;
    o.y = 0;
    return area(a, b, c) == (area(a, b, o) + area(a, c, o) + area(b, c, o));
}

int area(point a, point b, point c) {
    return abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y));
}
