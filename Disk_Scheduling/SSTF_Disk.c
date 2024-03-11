#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

int main()
{
    int i, j, n, head, total = 0;
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
    int current = head;
    int min_distance, closest_index;

    // Process each request
    for (i = 0; i < n; i++)
    {
        min_distance = INT_MAX; // Initialize with a large value

        // Find the closest request
        for (j = 0; j < n; j++)
        {
            if (abs(queue[j] - current) < min_distance && queue[j] != -1)
            {
                min_distance = abs(queue[j] - current);
                closest_index = j;
            }
        }

        // Print the current disk location and update variables
        printf("%d -> ", queue[closest_index]);
        seek_count += min_distance;
        current = queue[closest_index];
        queue[closest_index] = -1; // Mark the request as processed
    }

    printf("\nTotal seek count = %d\n", seek_count);
    return 0;
}
