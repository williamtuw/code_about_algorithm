#include <iostream>
using namespace std;

//下标从 0 开始
void percDown(int array[], int from, int size) { 
	int tmp,parent, child;
	tmp = array[from];
	for (parent = from; parent * 2 + 1 <= size - 1; parent = child) {
		child = parent * 2 + 1;
		if (child != size - 1 && array[child] < array[child + 1]) child++;
		if (tmp < array[child]) {
			array[parent] = array[child];
		}
		else break;
	}
	array[parent] = tmp;
}
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}
void heapSort(int array[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) { //build maxheap
		percDown(array, i, size);
	}	
	for (int i = size -1; i >=1; i--) {
		swap(array, array + i );
		percDown(array, 0, i);	
	}
}

int main_moudle()
{
	int count = 0;
	int array[100];
	while (array[count-1] != 0) {
		cin >> array[count++];
	}
	heapSort(array, count);
	for (int i = 0; i < count; i++) {
		cout << array[i] << " ";
	}
	return 0;

}