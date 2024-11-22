#include<iostream>
using namespace std;
class Minheap{
    public:
    int heap[100];
    int size=0;
    void insert(int value){
        heap[size]=value;
        int i=size;
        size++;
        while(i>0){
            int parent=(i-1)/2;
            if(heap[parent]>heap[i]){
                swap(heap[parent],heap[i]);
                i=parent;
            }
            else break;
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<heap[i]<<" ";
        }
    }
    void Heapify(int i){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<size&&heap[smallest]>heap[left]){
            swap(heap[smallest],heap[left]);
            smallest=left;
        }
        if(right<size&&heap[smallest]>heap[right]){
            swap(heap[smallest],heap[right]);
            smallest=right;
        }
        if(smallest!=i){
            swap(heap[smallest],heap[i]);
            Heapify(smallest);
        }
    }
    void HeapSort(){
        int original=size;
        while(size>1){
            swap(heap[0],heap[size-1]);
            size--;
            Heapify(0);
        }
        size=original;
    }
    int Find(int value){
        for(int i=0;i<size;i++){
            if(heap[i]==value) return i;
        }
        return -1;
    }
    void deleteValue(int value){
        int index=Find(value);
        if(index==-1)return;
        heap[index]=heap[size-1];
        size--;
        if(index<size) Heapify(index);
    }
};
int main(){
    Minheap m;
    m.insert(34);
    m.insert(23);
    m.insert(32);
    m.insert(234);
    m.insert(11);
    m.insert(2);
    m.display();
    m.HeapSort();
    cout<<endl;
    m.display();
    m.deleteValue(2);
    cout<<endl;
    m.display();
    return 0;
}