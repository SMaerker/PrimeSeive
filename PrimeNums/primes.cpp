#include <stdio.h>
#include <chrono>
#include <iostream>



int main(){

	int array[100000];
	int index = 0;

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	for (int i = 2; i < 10001; i++){
		for (int j = 2; j < i; j++){
			if (i % j == 0){j++;break;}
			if (j == i - 1){
				array[index] = i;
				index++;
				
			}		
		}		
	}

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

	for (int i = 0; i < sizeof(array) / sizeof(int); i++){
		if(array[i] == 0){break;}
		printf("%i\n", array[i]);
	}

	printf("%F seconds to execute (without printf) \n", static_cast<double>(duration) / 1000000);

	return 0;
}