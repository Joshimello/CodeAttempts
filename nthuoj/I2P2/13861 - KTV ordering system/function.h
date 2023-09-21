struct song{
    int num;
    song *pre, *next;
};

void print(song *st, song *en);

class ordering_system{
    private:
        song *head, *tmp1, *tmp2;
    public:
        void initialize();
        void order(int k);
        void play();
        void show();
        void insert(int k);
        void destroy();
};
