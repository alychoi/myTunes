#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

// helper make function
struct song_node * make_song(char *name, char *artist) {
    struct song_node *s = malloc(sizeof(struct song_node));
    strncpy(s->name, name, sizeof(s->name));
    strncpy(s->artist, artist, sizeof(s->artist));
    return s;
}

// insert nodes at the front
struct song_node * insert_front(struct song_node *s, char *name, char *artist) {
    struct song_node *n = make_song(name, artist);
    n->next = s;
    return n;
}

// you should have a helper function to compare song nodes effectively.
int song_compare(struct song_node *s1, struct song_node *s2) {
    //char artist1[100] = s1->artist;
    //char artist2[100] = s2->artist;
    int name_cmp_result = strcmp(s1->artist, s2->artist);

    if (name_cmp_result == 0) {
        //char name1[100] = ;
        //char name2[100] = ;
        strcmp(s1->name, s2->name);
    }
    else return name_cmp_result;
}

// insert nodes in order
// alphabetical by Artist then by Song
struct song_node * insert(struct song_node *head, char *name, char *artist) {
    struct song_node *new = make_song(name, artist);
    struct song_node *current = head;
    if (head == NULL || song_compare(head->artist, new->artist) >= 0) {
        new->next = head;
        head = new;
    }
    else {
        while (current->next != NULL & song_compare(current->next->artist, new->artist) < 0) {
            current = current->next;
        }
    }
    new->next = current->next;
    current->next = new;
    return head;
}

// helper print function 
void print_song(struct song_node *s) {
    // printf("\t{%s, %s}\n", s->artist, s->name);
    printf("\t%s by %s\n", s->artist, s->name);
}

// print the entire list
void print_list(struct song_node *s) {
    printf("[\n");
    while (s) {
        print_song(s);
        s = s->next;
    }
    printf("]\n");
}


//find and return a pointer to a node based on artist and song name
//struct song_node * find_song_node(struct song_node *s, char *n, char *a) {

//}

//find and return a pointer to the first song of an artist based on artist name
//struct song_node * find_first_song(struct song_node *s, char *a) {
//    while
//}

//return a pointer to random element in the list
// struct song_node * random(struct song_node *s) {

//     if (s == NULL) return s;

//     srand(time(NULL));

//     int final_index = 0;
//     struct song_node *looper = s;
//     while (looper) {
//         looper = looper->next;
//         size++;
//     }
    
//     int x = rand() % (final_index);

//     looper = s;
//     int i = 0;
//     while (looper || i == size) {
//         looper = looper->next;
//         i++;  
//     }

//     if (i == size) return looper;
//     else return  // shouldn't be necessary if everything works
// }

//remove a single specified node from the list
// struct song_node * remove_node(struct song_node *s, char *n, char *a) {
//     if (s == NULL) return s;
//     else if (s->name == n && s->artist == a) {
        
//     }
//     else {
        
//     }
// }

//free the entire list
struct song_node * free_list(struct song_node *s) {
    struct song_node *temp = s;
    while (s) {
        s = s->next;
        free(temp);
        temp = s;
    }
    return s;
}

int main() {
    struct song_node *test = make_song("hello", "adele");
    test = insert_front(test, "baby", "justin bieber");
    print_list(test);
    test = insert(test, "clarity", "zedd");
    printf("Testing insert function\n");
    print_list(test);
    
    return 0;
}