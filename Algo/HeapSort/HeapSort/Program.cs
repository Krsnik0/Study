using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2 {
	class Program {
		static void Main(string[] args) {
			var heap = new Heap();

			int[] a = new int[] { 6, 3, 11 , 10, 99, 2, 1, 7, 4, 35, 83, 13, 37, 17, 11};
			Console.Write("Before:");
			foreach (var item in a)
				Console.Write(" " + item);
			Console.WriteLine();

			heap.HeapSort(a, a.Length);

			Console.Write("After:");
			foreach (var item in a)
				Console.Write(" " + item);
			Console.WriteLine();

		}
	}
}
