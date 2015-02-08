class Card {
    private:
        int value_;
        int suit_;
    public:
        Card() {}
        Card(const char v, const char s);
        int value() { return value_; }
        int suit() { return suit_; }
};

Card::Card(const char v, const char s) {
    if (v == 'A')
        value_ = 13;
    else if (v == 'K')
        value_ = 12;
    else if (v == 'Q')
        value_ = 11;
    else if (v == 'J')
        value_ = 10;
    else if (v == 'T')
        value_ = 9;
    else
        value_ = v - '0' - 2;

    if (s == 'H')
        suit_ = 0;
    else if (s == 'D')
        suit_ = 1;
    else if (s == 'S')
        suit_ = 2;
    else
        suit_ = 3;
}
