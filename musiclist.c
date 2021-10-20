#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char artist1[100] = s1->artist;
    char artist2[100] = s2->artist;
    int name_cmp_result = strcmp(artist1, artist2);

    if (name_cmp_result == 0) {
        char name1[100] = s1->name;
        char name2[100] = s2->name;
        strcmp(name1, name2);
    }
    else return name_cmp_result;
}

// insert nodes in order
// alphabetical by Artist then by Song
struct song_node * insert(struct song_node *s, char *name, char *artist) {
    struct song_node *new = make_song(name, artist);
    struct song_node *current;
    while ()
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
struct song_node * find_song_node(char n, char a) {

}

//find and return a pointer to the first song of an artist based on artist name
struct song_node * find_first_song(char a) {
    
}

//return a pointer to random element in the list
struct song_node * random() {
    
}

//remove a single specified node from the list
struct song_node * remove_node(char n, char a) {
    
}

//free the entire list
struct song_node * free_list() {
    
}