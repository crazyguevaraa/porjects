#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
void PrintArray (char* array, off_t size);
int main()
{
    int nVal = 2;
    struct stat statistica = {0};
    int stat_error = stat ("/Users/danilapuchkov/Proga/onegin2.0/onegin2.0/text_1.txt", &statistica);
    assert(stat_error == 0);
    printf ("%lld\n", statistica.st_size);
    //long long int size = statistica.st_size;
    FILE *input_file = fopen("/Users/danilapuchkov/Proga/onegin2.0/onegin2.0/text_1.txt", "r");
    printf("\n\n\n");
    char* buffer = (char*) calloc ((statistica.st_size), sizeof(char));
    if (input_file == NULL)
    {
        printf("\n ERROR\n");
        return -1;
    }
    else printf ("\nCOMPLETE\n");
    int val = 1;
    char* ptr = (char*) calloc (nVal, sizeof(char));
    //ptr[0] = *baffer;
    fread((void*) buffer, sizeof(char), statistica.st_size, input_file);
    ptr[0] = *buffer;
   for(int i = 0, n = 1; i < statistica.st_size;)
    {
        if (buffer[i] == '\n')
        {
            val++;
            ptr[n] = buffer[i+1];
            n++;
            i++;
            nVal++;
            char* NewPtr = (char*) realloc(ptr, nVal * sizeof(char));
            if (NewPtr == NULL)
            {
                printf("\nERROR\n");
                break;
            }
            ptr = NewPtr;
        }
        else
        {
            i++;
        }
    }
  
    PrintArray(buffer, statistica.st_size );
    PrintArray(ptr, val);
    printf("%lld", val);
    
}
void PrintArray (char* array, off_t size )
   {
   for (int i = 0 ; i < size; i++)
   {
       printf("[%d] = %c , code (%d)\n", i, array[i], array[i]);
   }
    printf("END\n");
   }

char GaySort (char* arr_1, char* arr_2, unsigned long long int size_arr_1)
{
    
}
