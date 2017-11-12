#include <iostream>
#include <stdio.h>
#include <pthread.h>
//#include <random>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>
//#define myT 8
int **myM;
int M;
int *M2 ;
int counter;
int N ;
int error ;
bool valid = false;
int x;
int y;

using namespace std;
void binFile(char * myFile);
void calcMet(char * myFile);
void *metrix(void *arg );
void metrixx();
void printBin(char * myFile);

int main(int argc , char **argv){

 N = atoi(argv[1]);
 M = atoi(argv[2]);
 char * fileName = argv[3];
char * myFile ;
 if (fileName != NULL){
	 myFile = fileName;
	}else{
 	
	 myFile = "defult.bin";}

	ofstream myFile2(myFile);

myFile2.close();

cout<<"Your N value =  "<< N<< ", your M value = " << M << " within your file" << myFile<<endl;
	myM = new int*[M];
	
		for(int j = 0; j < M; j ++){
			myM[j] = new int[M];
			
		}

	pthread_t threads[M]; 
	for (int i=0; i<M; i++) { 

		if (error = pthread_create(&threads[i],0, metrix, (void *)&i)){
			cout<<"error"<<endl;
			exit(1); 
		}
		
	}

for (int i=0; i<M; i++){
 
pthread_join(threads[i], 0);
}

for(int j = 0 ; j < M ; j++){
	for(int k = 0; k < M ; k++){
	myM[j][k] = rand() % 2 ;
	cout<<myM[j][k]<<" ";
	
	}
	cout<<"\n"<<endl;
}

for (int i=0; i<M; i++){
pthread_join(threads[i], 0);
}
cout<<"Tour Transposed Matrix is "<<endl;
int counter ;
srand(time(NULL));
for(int j = 0 ; j < M ; j++){
	for(int k = 0; k < M ; k++){
	myM[j][k] = rand() % 2 ;
	cout<<myM[j][k]<<" ";
	

	}
	cout<<"\n"<<endl;
}

binFile(myFile);
//printBin(myFile);
//=alcMet(myFile);
pthread_exit(NULL);

	return 0; 
}

void *metrix(void *arg){
	srand(time(NULL));
	mutex mut;
	int ret;

//ret = pthread_mutex_lock(&mp);

	mut.lock();
	for(int i = 0 ; i < M ; i++)
		myM[counter][i] = rand() % 2 ;
		counter++;
//ret = pthread_mutex_unlock(&mp);
mut.unlock();
}


void metrixx(){
mutex mut;
int ret;

//ret = pthread_mutex_lock(&mp);
//mut.lock();
for(int i = 0 ; i < M ; i++)
myM[counter][i] = rand() % 2 ;
counter++;
//ret = pthread_mutex_unlock(&mp);
//mut.unlock();
}


void binFile(char * myFile){
ofstream file;
file.open(myFile );
for(int i = 0 ; i < M ; i++){
	for(int j = 0 ; j < M ; j++){

		file<<myM[i][j]<< "	";

	}
	file<<"\n";
}
file.close();

}

void printBin(char * myFile){

fstream file;
file.open(myFile);

for(int i = 0 ; i < M ; i++){

	for(int j = 0 ; j < M ; j++){

		cout<<file<< "	";

	}
	cout<<"\n"<<endl;
}
file.close();


}

void oneOrZero (){
	int val = -1, val2 = -1;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++){
			if(myM[i][j] == 0)
				val = 0;
			else
				val2 = 1;
		} // End of inner for loop
	if(val == 0 && val2 == 1) valid = false;
	else if(val != 0 && val2 == 1) valid = true;
	else if(val == 0 && val2 != 1) valid = true;
	else valid = false;
}

void calcMet(char * myFile){
int row =0, col = 0;
int zeros = 0;
int ones = 0;
row=N/M;
col=N%M;
for(int i = row ; i < M ; i++){
	for(int j = col ; j < M ; j++){	
	}
}
oneOrZero();
while(valid ==false){

for(int i = 0 ; i < M ; i++){
	for(int j = 0 ; j < M ; j++){

	}

}
	oneOrZero();
}

}

