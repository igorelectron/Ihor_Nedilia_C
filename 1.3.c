/*1.3. Вивести на екран текст:
- а - а - а
a | a | a
- a - a - a,
де а - введена цифра з клавіатури*/

#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    printf("- %d - %d - %d\n%d | %d | %d\n- %d - %d - %d",
           a, a, a, a, a, a, a, a, a); /*а чи можна без багаторазового повтору змінної а?*/
}