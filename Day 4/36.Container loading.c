#include <stdio.h>
#include <stdbool.h>

#define MAX_CONTAINERS 10
#define MAX_ITEMS 20
int i,j;
struct Container {
    int capacity;
    int items[MAX_ITEMS];
    int itemCount;
};

struct Item {
    int id;
    int size;
};

void initContainer(struct Container *container, int capacity) {
    container->capacity = capacity;
    container->itemCount = 0;
}

void initItem(struct Item *item, int id, int size) {
    item->id = id;
    item->size = size;
}

void naiveContainerLoader(struct Container containers[], int containerCount, struct Item items[], int itemCount) {
    for (i = 0; i < itemCount; i++) {
        bool loaded = false;
        for (j = 0; j < containerCount; j++) {
            if (items[i].size <= containers[j].capacity) {
                containers[j].items[containers[j].itemCount++] = items[i].id;
                containers[j].capacity -= items[i].size;
                loaded = true;
                break;
            }
        }
        if (!loaded) {
            printf("Item %d could not be loaded.\n", items[i].id);
        }
    }
}

int main() {
    struct Container containers[MAX_CONTAINERS];
    struct Item items[MAX_ITEMS];

    int containerCount = 3;
    int containerCapacity = 10;

    int itemCount = 5;
    int itemSizes[] = {4, 5, 2, 7, 3};

    for (i = 0; i < containerCount; i++) {
        initContainer(&containers[i], containerCapacity);
    }

    for (i = 0; i < itemCount; i++) {
        initItem(&items[i], i + 1, itemSizes[i]);
    }

    naiveContainerLoader(containers, containerCount, items, itemCount);

    for (i = 0; i < containerCount; i++) {
        printf("Container %d: [", i + 1);
        for ( j = 0; j < containers[i].itemCount; j++) {
            printf("Item%d(%d), ", containers[i].items[j], items[containers[i].items[j] - 1].size);
        }
        printf("]\n");
    }

    return 0;
}

