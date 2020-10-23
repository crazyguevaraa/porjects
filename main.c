#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

void gay_print_array(char* array, off_t size);
int  gay_compar_str(const char  *str_1, const char *str_2);
void gay_sort(char* arr_1, unsigned long long int size_arr_1);
void gay_swap(char* ptr_1, char* ptr_2);

int main()
{
    int         nVal       = 2;
    struct stat statistica = {0};
    int         stat_error = stat ("/Users/danilapuchkov/Proga/onegin2.0/onegin2.0/text_1.txt", &statistica);
   
    assert(stat_error == 0);
    printf ("%lld\n", statistica.st_size);
    
    FILE  *input_file = fopen("/Users/danilapuchkov/Proga/onegin2.0/onegin2.0/text_1.txt", "r");
    char* buffer      = (char*) calloc ((statistica.st_size), sizeof(char));
    
    if (input_file == NULL)
    {
        printf("\n ERROR\n");
        return -1;
    }
    else printf ("\nCOMPLETE\n");
    
    unsigned long long int val = 1;
    char*                  ptr = (char*) calloc (nVal, sizeof(char));
    
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
        else i++;
    }
   // char* arr = (char*) calloc (val, sizeof(char*));
    
    gay_print_array(buffer, statistica.st_size );
    gay_print_array(ptr, val);
    gay_sort(ptr, val);
    printf("%lld\n\n\n", val);
    gay_print_array(ptr, val);
}
//---------------------------------------------------
void gay_print_array(char* array, off_t size )
{
   for (int i = 0 ; i < size; i++)
   {
       printf("[%d] = %c , code (%d)\n", i, array[i], array[i]);
   }
    printf("END\n");
}
//---------------------------------------------------
int gay_compar_str(const char  *str_1, const char *str_2)
{
    const unsigned char *name_1 = (const unsigned char*) str_1;
    const unsigned char *name_2 = (const unsigned char*) str_2;
   /*int i = 0;
    if((str_1) >= (str_2))
    {
       i = 1;
    }
    else if(str_1 <= str_2);
    else
    {
        str_1++;
        str_2++;
        gay_compar_str(str_1, str_2);
    }
    return i;*/
    while (*name_1 == *name_2 && *name_1 != '\0' && *name_2 != '\0')
    {
      name_1++;
      name_2++;
    }
    return (*name_1 > *name_2) - (*name_1 < *name_2);
}
//----------------------------------------------------
void gay_swap(char* ptr_1, char* ptr_2)
{
    int swap_const = *ptr_1;
            *ptr_1 = *ptr_2;
            *ptr_2 = swap_const;
}
//----------------------------------------------------
void gay_sort(char* arr_1, unsigned long long int size_arr_1)
{
    unsigned long long int i         = size_arr_1 / 2;
    char                   ptr_left  = arr_1[1];
    char                   ptr_right = arr_1[size_arr_1];
    char                   ptr_pivot = arr_1[i];
    
    for(unsigned long long int k = 0, j = size_arr_1 - 1; k < j; i++, j--)
    {
        while(gay_compar_str(ptr_left, ptr_pivot))
            ptr_left++;
        while(gay_compar_str(ptr_pivot, ptr_right))
            ptr_right--;
        
        gay_swap(ptr_left, ptr_right);
        //gay_sort(arr_1, i);
        //gay_sort(arr_1 + i, size_arr_1 - i);
    }
    gay_sort(arr_1, i);
    gay_sort(arr_1 + i, size_arr_1 - i);
}
