#include <stdio.h>
#include <stdlib.h>

#include "musiclibrary.h"
#include "musiclist.h"

int main() {
    struct population *list = NULL;
    list = insert_front(list, "Hello", "Adele");
    list = insert_front(list, "Rolling in the Deep", "Adele");
    list = insert_front(list, "Set Fire to the Rain", "Adele");

    print_list(list);


}