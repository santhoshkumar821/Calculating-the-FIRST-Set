#include<stdio.h>;
#include<ctype.h>;
#include<string.h>;
// Function to calculate First
void findfirst(char, int, int);
int count, n = 0;
// Stores the final result
// of the First Sets
char calc_first[10][100];
int m = 0;
// Stores the production rules
char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main(int argc, char **argv)

{
int jm = 0;
int km = 0;
int i, choice;
char c, ch;
count = 8;

strcpy(production[0], "E=TR");
strcpy(production[1], "R=+TR");
strcpy(production[2], "R=#");
strcpy(production[3], "T=FY");
strcpy(production[4], "Y=*FY");
strcpy(production[5], "Y=#");
strcpy(production[6], "F=(E)");
strcpy(production[7], "F=i");

int kay;
char done[count];
int ptr = -1;

// Initializing the calc_first array
for(k = 0; k<count; k++) {
for(kay = 0; kay<100; kay++) {
calc_first[k][kay] = '!';
}
}
int point1 = 0, point2, x;

for(k = 0; k<count; k++)
{
c = production[k][0];
point2 = 0;
x = 0;

// Checking if First of c has
// already been calculated
for(kay = 0; kay<= ptr; kay++)
if(c == done[kay])
x = 1;

if (x == 1)
continue;

// Function call
findfirst(c, 0, 0);
ptr += 1;

// Adding c to the calculated list
done[ptr] = c;
printf("\n First(%c) = { ", c);
calc_first[point1][point2++] = c;

// Printing the First Sets of the grammar
for(i = 0 + jm; i<n; i++) {
int lark = 0, chk = 0;

for(lark = 0; lark<point2; lark++)
{

if (first[i] == calc_first[point1][lark])
{

chk = 1;
break;

}
}
if(chk == 0)
{

printf("%c", first[i]);
calc_first[point1][point2++] = first[i];

}
}
printf("}\n");
jm = n;
point1++;
}
printf("\n&");

}
void findfirst(char c, int q1, int q2)
{
int j;

// The case where we
// encounter a Terminal
if(!(isupper(c))) {
first[n++] = c;
}
for(j = 0; j<count; j++)
{
if(production[j][0] == c)
{
if(production[j][2] == '#')
{
if(production[q1][q2] == '\0')
first[n++] = '#';
else if(production[q1][q2] != '\0'
&&(q1 != 0 || q2 != 0))

{

// Recursion to calculate First of New
// Non-Terminal we encounter after epsilon
findfirst(production[q1][q2], q1, (q2+1));

}
else
first[n++] = '#';

}
else if(!isupper(production[j][2]))
{
first[n++] = production[j][2];
}
else
{
// Recursion to calculate First of
// New Non-Terminal we encounter
// at the beginning
findfirst(production[j][2], j, 3);
}
}
}
}
