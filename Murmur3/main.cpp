#include <stdio.h>
#include <ctime>
#include <locale.h>
#include "murmur3.h"
using namespace std;

#define default_path "C:/Users/Admin/Desktop/murmur_hash.txt"

 
char* read_hash(const char* path)
{
	char* hash = new char[hash_size+1];
	FILE* file = fopen(path, "r");
	for(int i = 0; i < hash_size; ++i)
		hash[i] = getc(file);
	hash[hash_size] = '\0';
	fclose(file);
	return hash;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL,".1251");
	printf("Брутфорс хэша Murmur3 в одном потоке\n\n");
	clock_t start_time, span;	
	
	char* hash = read_hash((argc > 1) ? argv[1] : default_path);	
	uint password;

	start_time = clock();
	for(uint i = 0; i < 1000000000; ++i)
	{
		if (compare(i, hash))
		{
			password = i;
			break;
		}
	}	
	span = clock()-start_time;

	printf("Пароль: '%d'.\n", password);
	printf("Время: %d s %d ms\n\n", span/1000, span-1000*(span/1000));
	
	getchar();
    return 0;
}