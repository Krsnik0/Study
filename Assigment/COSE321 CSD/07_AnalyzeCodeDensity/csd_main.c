#include <stdio.h>

int indata[32] = {	2, 0, -7, -1, 3, 8, -4, 10,
					-9, -16, 15, 13, 1, 4, -3, 14,
					-8, -10, -15, 6, -13, -5, 9, 12,
					-11, -14, -6, 11, 5, 7, -2, -12 };
int outdata[32];

#pragma GCC target("thumb")
void bubble_thumb(){
	int i, j;
	int tmp;
	for (i = 0; i < 32; i++){
		outdata[i] = indata[i];
	}
	for (i = 0; i < 32; i++){
		for (j = 0; j < 31 - i; j ++){
			if(outdata[j]>outdata[j+1]){
				tmp = outdata[j];
				outdata[j] = outdata[j+1];
				outdata[j+1] = tmp;
			}
		}
	}
}

#pragma GCC target("arm")
void bubble_arm(){
	int i, j;
	int tmp;
	for (i = 0; i < 32; i++){
		outdata[i] = indata[i];
	}
	for (i = 0; i < 32; i++){
		for (j = 0; j < 31 - i; j ++){
			if(outdata[j]>outdata[j+1]){
				tmp = outdata[j];
				outdata[j] = outdata[j+1];
				outdata[j+1] = tmp;
			}
		}
	}

}
