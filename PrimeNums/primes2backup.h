#include <stdio.h>
#include <chrono>
#include <iostream>

//limit is 10 000



int main(){
	int limit = 100;
	int array[100000];
	int marked[100000];
	int indexA = 0;
	int indexM = 0;

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	int i = 2;
	while(i < limit){
		array[indexA] = i;
		indexA++;
		for(int z = i; z < limit; z += i){
			marked[indexM] = z;
			indexM++;
		}
		for(int d = 0; d < sizeof(marked) / sizeof(int); d++){
			if (marked[d ] != i){
				i = marked[d];
			}

			if (marked[d] == i){
				break;
			}
		}
		printf("%i\n", i);
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

	