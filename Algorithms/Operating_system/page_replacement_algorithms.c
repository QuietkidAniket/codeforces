#include <stdio.h>
#include <limits.h>

void fifo(int pages[], int n, int frames) {
    int frame[frames], index = 0, faults = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i]) { found = 1; break; }
        
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }
    }
    printf("FIFO Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int frames) {
    int frame[frames], time[frames], faults = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0, lru_index = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }
        
        if (!found) {
            int min_time = INT_MAX;
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) { lru_index = j; break; }
                if (time[j] < min_time) { min_time = time[j]; lru_index = j; }
            }
            frame[lru_index] = pages[i];
            time[lru_index] = i;
            faults++;
        }
    }
    printf("LRU Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int frames) {
    int frame[frames], faults = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0, replace_index = -1, farthest = i;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i]) { found = 1; break; }
        
        if (!found) {
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) { replace_index = j; break; }
                int next_use = n;
                for (int k = i + 1; k < n; k++)
                    if (frame[j] == pages[k]) { next_use = k; break; }
                if (next_use > farthest) { farthest = next_use; replace_index = j; }
            }
            frame[replace_index] = pages[i];
            faults++;
        }
    }
    printf("Optimal Page Faults: %d\n", faults);
}

int main() {
    int frames, n;
    printf("Enter the number of page frames: ");
    scanf("%d", &frames);
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    fifo(pages, n, frames);
    lru(pages, n, frames);
    optimal(pages, n, frames);

    return 0;
}
