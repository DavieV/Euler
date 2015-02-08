/*
* Model a line in the form y = mx + b
*/
class Line {
    public:
        Line(int x1, int y1, int x2, int y2);
        bool on_line(int x, int y);

    private:
        double m_;
        double b_;
};

Line::Line(int x1, int y1, int x2, int y2) {
    m_ = (y2 - y1) / (x2 - x1);
    b_ = y1 - (m_ * x1);
}

bool Line::on_line(int x, int y) {
    return y == (m_ * x) + b_;
}
