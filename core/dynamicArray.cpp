#include <vector>
#include <iostream>

class DynamicArray {
public:
    DynamicArray(int cap, int initValue = 0) {
        if (cap <= 0) {
            std::cerr << "Invalid initialization: cap <= 0\n";
            exit(1);
        }
        this->p = new int[cap];
        this->sz = cap;
        for (int i = 0; i < cap; ++i){
            this->p[i] = initValue;
        }
    }

    ~DynamicArray() {
        delete[] this->p;
    }

    int& operator[](int i) {
        return this->p[i];
    }

    int size() const {
        return this->sz;
    }

    void pushback(int n) {
        this->p[this->sz++] = n;
    }

private: 
    int sz;
    int* p;
};

int main() {
    DynamicArray a1 = DynamicArray(5);

    a1[1] = 4;
    a1[5] = 6;
    a1.pushback(5);

    for (int i = 0; i < a1.size(); i++) {
        std::cout << a1[i] << '\n';
    }
    
    std::vector<int> a2;
}