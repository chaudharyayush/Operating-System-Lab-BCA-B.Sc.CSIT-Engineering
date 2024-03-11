#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, head, total = 0;
    int queue[20];

    printf("Enter the size of disk queue: ");
    scanf("%d", &n);

    printf("Enter the disk queue: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int seek_count = 0;

    for (i = 0; i < n; i++)
    {
        printf("%d -> ", queue[i]);
        seek_count += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\nTotal seek count = %d\n", seek_count);
    return 0;
}
