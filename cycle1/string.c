#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

void getString(char str[MAX_LENGTH])
{
  printf("Enter a string : ", MAX_LENGTH);
  scanf(" %[^\n]s", str);
}

void searchSubstring(char str[MAX_LENGTH], char subStr[MAX_LENGTH])
{
  if (strstr(str, subStr))
  {
    printf("'%s' is a substring of '%s'.\n", subStr, str);
  }
  else
  {
    printf("'%s' is not a substring of '%s'.\n", subStr, str);
  }
}

void concatenateStrings(char str1[MAX_LENGTH], char str2[MAX_LENGTH])
{
  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);
}

void getSubstring(char str[MAX_LENGTH], int start, int length)
{
  char subStr[MAX_LENGTH];
  if (start >= 0 && start < strlen(str) && length > 0 && (start + length) <= strlen(str))
  {
    strncpy(subStr, str + start, length);
    subStr[length] = '\0';
    printf("Substring: %s\n", subStr);
  }
  else
  {
    printf("Invalid start position or length for substring operation.\n");
  }
}

int main()
{
  char str1[MAX_LENGTH], str2[MAX_LENGTH], subStr[MAX_LENGTH];
  int choice, start, length;

  getString(str1);
  getString(str2);

  while (1)
  {
    printf("\nSelect an operation:\n");
    printf("1. Search for substring\n");
    printf("2. Concatenate strings\n");
    printf("3. Get substring\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:

        printf("Enter the substring to search for: ");
        scanf(" %[^\n]s", subStr);
        searchSubstring(str1, subStr);
        break;

      case 2:

        concatenateStrings(str1, str2);
        break;

      case 3:
  
        printf("Enter the start position: ");
        scanf("%d", &start);
        printf("Enter the length: ");
        scanf("%d", &length);
        getSubstring(str1, start, length);
        break;

      case 4:
        return 0;	

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}
