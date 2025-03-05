/*
Problem: Palindrome Checker
Write a C program that checks whether a given string is a palindrome. A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).

Input:
A string (up to 100 characters).
Output:
Print "Palindrome" if the string is a palindrome.
Print "Not Palindrome" if the string is not a palindrome

EX: MOM --> MOM == Valid
    Dog --> god == not valid
    bird --. drib == not valid
*/


/*
1. Get string from user
2. If more than 100 chars, end the program
3. Get string and copy it into another place
4. For each character, shift it to the right to make it backwards on temp placeholder
5. Compare user string and temp
6. IF true, print "Palindrome", if not print "Not Palindrome"
Note: make all letter lowercase for accurate comparisons
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void reverse_word(char* word_set_to_be_backwards);

void reverse_word(char* word_set_to_be_backwards){

    int i, len = strlen(word_set_to_be_backwards);
    char temp;

    for(i = 0; i < len / 2; ++i){
        temp = word_set_to_be_backwards[i];
        word_set_to_be_backwards[i] = word_set_to_be_backwards[len - i - 1];
        word_set_to_be_backwards[len - i - 1] = temp;
    }
}

void make_word_lowercase(char* user_word){
  
    for(int k = 0; user_word[k] != '\0'; ++k){
        user_word[k] = tolower(user_word[k]);
    }
}


int main(void){
    char user_word[100];
    int len;

    printf("Give me a word: ");
    scanf("%100s", user_word);

    len = strlen(user_word);

    if(len > 100){
        perror("You put more than 100 characters. Ending Program.\n");
        exit(EXIT_FAILURE);
    }
    
    make_word_lowercase(user_word);

    char modified_user_word[100];
    strcpy(modified_user_word, user_word);

    reverse_word(modified_user_word);

    if(strcmp(user_word, modified_user_word) == 0){
        printf("Palindrome.\n");
    }else{
        printf("Not a Palindrome.\n");
    }

    printf("Your original word is \'%s\' and your reversed word is \'%s\'\n", user_word, modified_user_word);

    return 0;
}


