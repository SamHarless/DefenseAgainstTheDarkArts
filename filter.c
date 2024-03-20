
#include <stdio.h>


int main(){
	unsigned char buffer[512];
	size_t numBytesRead;

	while((numBytesRead = fread(buffer, 1, sizeof(buffer), stdin)) > 0){
		
		for(size_t i = 0; i < numBytesRead; i++){

			printf("%02x", buffer[i]);

		}
	}

	return 0;
}
