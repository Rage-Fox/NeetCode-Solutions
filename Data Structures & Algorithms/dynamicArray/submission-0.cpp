class DynamicArray {
private:
    int *harr;
    int l;
    int cap;
public:
    DynamicArray(int capacity) : cap(capacity),l(0) {
        harr=new int[cap];
    }

    int get(int i) {
        return harr[i];
    }

    void set(int i, int n) {
        harr[i]=n;
    }

    void pushback(int n) {
        if(l==cap){
            resize();
        }
        harr[l]=n;
        l++;
    }

    int popback() {
        if(l>0){
            l--;
        }
        return harr[l];
    }

    void resize() {
        cap*=2;
        int* newharr=new int[cap];
        for(int i=0;i<l;i++){
            newharr[i]=harr[i];
        }
        delete harr;
        harr=newharr;
    }

    int getSize() {
        return l;
    }

    int getCapacity() {
        return cap;
    }
};
