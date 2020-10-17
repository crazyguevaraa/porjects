#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
void PrintArray (char* array, off_t size);
int main()
{
    int   nVal = 1;
    struct lenBuf
    {
        int   len;
        char* pt;
    };
    struct lenBuf* arr = (struct lenBuf*) calloc((nVal), sizeof(*arr));
    struct stat statistica = {0};
    int stat_error = stat ("/Users/danilapuchkov/Proga/onegin2.0/onegin2.0/text_1.txt", &statistica);
    assert(stat_error == 0);
    printf ("%lld\n", statistica.st_size);
    FILE *input_file = fopen("/Users/danilapuchkov/Proga/onegin2.0/onegin2.0/text_1.txt", "rb");
    for (int i = 0; i < statistica.st_size + 1 ; i++)
    {
        int symbol = fgetc(input_file);
        printf ("symbol (%c) code (%d);", symbol, symbol);
    }
    fclose (input_file);

    printf("\n\n\n");
    char* buffer = (char*) calloc ((nVal), sizeof(*buffer));
    if (input_file == NULL)
    {
        printf("\n ERROR\n");
        return -1;
    }
    else printf ("\nCOMPLETE\n");
    int i = 0;
    for(;;)
    {
        arr->len = fread(*buffer, sizeof(char), statistica.st_size, input_file);
        struct lenBuf* newArr = (struct lenBuf*) realloc (arr, nVal * sizeof (*arr));
        if (newArr == NULL)
        {
            printf("\nERROR arr\n");
            break;
        }
        if (arr != newArr)
        {
            printf("\nWELL DONE arr\n");
        }
        arr = newArr;
               
        if (sscanf (buffer, "%s", &buffer[nVal-1]) != 1)
        break;

        nVal++; //Сдвиг на 1 ячейку.
        
        char* newBuffer = (char*) realloc (buffer, nVal * sizeof (char));
        if (newBuffer == NULL)
        {
            printf("\nERROR\n");
            break;
        }
        if (buffer != newBuffer)
        {
            printf("\nWELL DONE\n");
        }
        buffer = newBuffer;
        
    }
    printf("%lld\n", sizeof(arr));
    printf("%lu\n", sizeof(struct lenBuf*));
    PrintArray(buffer, statistica.st_size );
    
}
void PrintArray (char* array, off_t size ) //Функция печати массива
   {
   for (int i = 0 ; i < size + 1 ; i++)
   {
       printf("[%d] = %c , code (%d)\n", i, array[i], array[i]);
      // printf("END\n");
   }
    printf("END\n");
   }
