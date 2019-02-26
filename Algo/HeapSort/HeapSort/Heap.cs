using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2 {
	class Heap {
	
		public int Parent(int i) {return (i - 1) / 2;}
		public int Left(int i) {return i * 2 + 1;}
		public int Right(int i) {return i * 2 + 2;}
		public void Swap(ref int a, ref int b) {int tmp = a; a = b; b = tmp;}

		public void MaxHeapify(int[] arr, int index, int heapSize) {
			if (Left(index) >= heapSize) return;
			int largest = index;
			if (Left(index) < heapSize) {
				if (arr[index] < arr[Left(index)]) {
					largest = Left(index);
					if (Right(index) < heapSize) {
						if (arr[largest] < arr[Right(index)]) largest = Right(index);
					}					
				}
				else {
					if (Right(index) < heapSize) {
						if (arr[largest] < arr[Right(index)]) largest = Right(index);
					}
				}
			}
			

			if (largest == index) return;
			else if (largest == Left(index)) {
				Swap(ref arr[index], ref arr[largest]);
				MaxHeapify(arr, Left(index), heapSize);
			}
			else if (largest == Right(index)) {
				Swap(ref arr[index], ref arr[largest]);
				MaxHeapify(arr, Right(index), heapSize);
			}
		}

		public void HeapSort(int[] arr, int heapSize) {
			for (int i = Parent(heapSize - 1); i >= 0; i--) {
				MaxHeapify(arr, i, heapSize);
			} // Build MaxHeap
			for (int j = arr.Length - 1; j > 0; j--) {
				Swap(ref arr[0], ref arr[j]);
				heapSize--;
				MaxHeapify(arr, 0, heapSize);
			}
		}
	}
}
