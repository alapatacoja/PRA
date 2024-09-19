class SortNet {
    private: 
        int len;
        int *a;
    
        void swap(int i, int j);

    public:
        SortNet(int n);
        SortNet(int *v);
        ~SortNet();
        void input(int *v);
        void print();
        void sort();
};
