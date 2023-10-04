#include <stdio.h>


struct Distance {
int feet;
int inches;
};

void main() 
{
struct Distance distance1, distance2, result;
printf("Enter details for the first distance (feet inches): ");
scanf("%d %d", &distance1.feet, &distance1.inches);
printf("Enter details for the second distance (feet inches): "); 
scanf("%d %d", &distance2.feet, &distance2.inches);
 
 result.inches = distance1.inches + distance2.inches;
 result.feet = distance1.feet + distance2.feet + (result.inches / 12);
result.inches %= 12;
 printf("Resultant distance: %d feet %d inches \n", result.feet, result.inches);
}
