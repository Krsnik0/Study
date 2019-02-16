using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MergeSort {
	class Program {
		static void Main(string[] args) {
			int[] a = { 1, 4, 6, 7, 8, 10, 14 }; // p == 7
			int[] b = { 2, 5, 7, 9, 11, 14, 16, 17 }; //q == 15
			int[] c = new int[15];
			int i = 0, j = 0, k = 0;

			while (i != 7 || j != 8) {
				if (i == 7)
					c[k++] = b[j++];
				else if (j == 8)
					c[k++] = a[i++];
				else {
					if (a[i] <= b[j])
						c[k++] = a[i++];
					else
						c[k++] = b[j++];
				}
			}

			foreach (int item in c)
				Console.WriteLine(item);

			/*
			a: 1 ~ p, b: p+1 ~ q, c: merged array
			i, j, k: index of a, b, c

			while(i!=p||j!=q-p){
				if(i==p) c[k++] = b[j++];
				else if(j==q-p) c[k++] = a[i++];
				else{
					if(a[i]<=b[j]) c[k++] =a[i++];
					else c[k++] = b[j++];
				}
			}
			굳이 이렇게 나눠서 쓰는게 싫으면 a, b배열을 만들때 원래 길이+1해서 마지막칸에
			a, b의 원소 중 어떤 수보다도 큰 수를 넣고 돌리면 된다. 혹은 마지막 원소 더해서 넣던가.
			 */
		}
	}
}
