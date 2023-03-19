#include <stdio.h>
#include <string.h>

int main() {
	unsigned char string1[] = u8"🏄";
	// unsigned char string2[17] = "Explicitly sized";     <-- This is commented out as by the end of the exercise string2 is unused. This would create a compiler error.
	unsigned char string3[24] = {0}; //zero initialised
	unsigned char string4[10] = {0};

	// When copying string1 into string3, only the first 24 characters can be copied across due to the length of string3
    memcpy(string3, string1, sizeof(string3));
    
    puts("Input a string:");
    fgets((char*)string4, sizeof(string4),stdin);  
    string4[strcspn((char*)string4, "\n")] = 0;  
    
    // These lines show that the array is not full if the string is shorter than the length of the array
    printf("String 3: \"%s\", array size = %ld, string length = %ld\n", string3, sizeof(string3), strlen((char*)string3));
    printf("String 4: \"%s\", array size = %ld, string length = %ld\n", string4, sizeof(string4), strlen((char*)string4));


	//this prints out the array string1 char by char
      //[giving the ASCII symbol and the literal numeric value]
      for(int i=0; i<sizeof(string1); i++) printf("String1 element %d: '%c' (%hhu)\n", i, string1[i], string1[i]);
    
    // Question 15
    // Although only one character is in string1, its length is 4. 
    // This is because the character is non-ASCII so can't be represented normally in memory in just one byte, it needs more.
}