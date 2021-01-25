class poker{
    int card[13][4];
    int n[52];
    int s[52];
    int total,amount,c,action,row;
public:
    void setpoker();
    void input();
    int choice();
    void shuffle();
    void save();
    void print();
};
