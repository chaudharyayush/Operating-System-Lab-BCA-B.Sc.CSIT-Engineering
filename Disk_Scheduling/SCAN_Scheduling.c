#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j,last_queue, n, head, total = 0;
    int queue[20], left[20], right[20];

    printf("Enter the size of disk queue: ");
    scanf("%d", &n);

    printf("Enter the disk queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter last position of queue: ");
    scanf("%d", &last_queue);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // sort the queue
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // find the left and right end of disk
    for (i = 0; i < n; i++) {
        if (queue[i] < head) {
            left[i] = 1;
        } else {
            left[i] = 0;
        }
        if (queue[i] > head) {
            right[i] = 1;
        } else {
            right[i] = 0;
        }
    }

    int seek_count = 0;
    int direction;
    printf("Enter the direction (0 for left and 1 for right): ");
    scanf("%d", &direction);

    // if direction is right
    if (direction == 1) {
        for (i = 0; i < n; i++) {
            if (right[i] == 1) {
                printf("%d -> ", queue[i]);

                seek_count += abs(head - queue[i]);
                
                head = queue[i];
            }
        }
        printf("%d -> ", last_queue);
        seek_count += abs(head - last_queue);
        head = last_queue;

        for (i = n - 1; i >= 0; i--)
        {
            if (left[i] == 1)
            {
                printf("%d -> ", queue[i]);
                seek_count += abs(head - queue[i]);
                head = queue[i];
            }
        }
    }
    // if direction is left
    else {
        for (i = n - 1; i >= 0; i--) {
            if (left[i] == 1) {
                printf("%d -> ", queue[i]);

                seek_count += abs(head - queue[i]);
                head = queue[i];
            }
        }
        printf("%d -> ", 0);
        seek_count += abs(head -0);
        head= 0;


        for (i = 0; i < n; i++)
        {
            if (right[i] == 1)
            {
                printf("%d -> ", queue[i]);
                seek_count += abs(head - queue[i]);
                head = queue[i];
            }
        }
    }

    printf("\nTotal seek count = %d\n", seek_count);
    return 0;
}
