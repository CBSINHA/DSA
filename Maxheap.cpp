#include<iostream>
using namespace std;
class MaxHeap{
    public:
    int heap[100];
    int size=0;
    void Heapify(int value){
        int largest=value;
        int left=2*value+1;
        int right=2*value+2;
        if(size>left&&heap[left]>heap[largest]){
            swap(heap[largest],heap[left]);
            largest=left;
        }
        if(size>right&&heap[right]>heap[largest]){
            swap(heap[largest],heap[right]);
            largest=right;
        }
        if(value!=largest){
            swap(heap[largest],heap[value]);
            Heapify(largest);
        }
    }
    void displayHeap(){
        for(int i=0;i<size;i++){
            cout<<heap[i]<<" ";
        }
    }
    void insert(int value){
        if(size>=100){
            return;
        }
        heap[size]=value;
        int i=size;
        size++;
        while(i>0){
            int parent=(i-1)/2;
            if(heap[parent]<heap[i]){
                swap(heap[parent],heap[i]);
                i=parent;
            }
            else break;
        }
    }
    int Find(int value){
        for(int i=0;i<size;i++){
            if(heap[i]==value) return i;
        }
    }
    void deleteValue(int value){
        int index=Find(value);
        heap[index]=heap[size-1];
        size--;
        Heapify(index);
    }
};
int main(){
    MaxHeap m;
    m.insert(70);
    m.insert(90);
    m.insert(100);
    m.insert(50);
    m.insert(23);
    m.displayHeap();
    cout<<endl;
    m.deleteValue(100);
    m.displayHeap();
    return 0;
}