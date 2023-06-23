#include <stdio.h>
#include <ctype.h>
int main()
{
    char op;
    int key;
    scanf("%c%d", &op, &key);
    getchar();
    if (op == 'd') {
        key = -key;
    }
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        if (isdigit(ch)) {
            ch = ((ch - '0') + key + 10) % 10 + '0';
        }
        printf("%c", ch);
    }
    return 0;
}