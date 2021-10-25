#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "musiclist.h"

// =======================================================================================================================
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

// =======================================================================================================================
// helper function to compare song nodes effectively.
int song_compare(struct song_node *s1, struct song_node *s2) {
    // same artist
    if (strcasecmp(s1->artist, s2->artist) == 0) return strcasecmp(s1->name, s2->name);
    // different artists
    else return strcasecmp(s1->artist, s2->artist);
}

// =======================================================================================================================
// insert nodes in order
// alphabetical by Artist then by Song
struct song_node * insert_song(struct song_node *s, char *name, char *artist) {

  struct song_node *insert = make_song(name, artist);

  // insert into empty list
  if (s == NULL) {
    return insert;
  }

  // insert at the front
  else if (song_compare(s, insert) > 0) {
    insert->next = s;
    return insert;
  }

  else {
    struct song_node *front = s;

    while(s) {
      if (s->next == NULL) {
        s->next = insert;
        return front;
      }
      if (song_compare(s->next,insert) > 0) {
        insert->next = s->next;
        s->next = insert;
        return front;
      }
      s = s->next;
    }
    return front;
  }
}

// =======================================================================================================================
// helper print function
void print_song(struct song_node *s) {
    if (s == NULL) printf("\nsong not found\n");
    else printf("{%s, %s}", s->name, s->artist);
}

// print the entire list
void print_list(struct song_node *s) {
    printf("[ ");
    while (s) {
        print_song(s);
        printf(" | ");
        s = s->next;
    }
    printf(" ]\n");
}

// =======================================================================================================================
// find and return a pointer to a node based on artist and song name
struct song_node * find_song(struct song_node *s, char *n, char *a) {
  if (s == NULL) return s;
  while (s) {
    if (strcasecmp(s->name, n) == 0 && (strcasecmp(s->artist, a)) == 0) return s;
    s = s->next;
  }
  return NULL;
}

// =======================================================================================================================
// find and return a pointer to the first song of an artist based on artist name
struct song_node * find_first_song(struct song_node *s, char *a) {
  if (s == NULL) return s;
  while(s) {
    if (strcasecmp(a, s->artist) == 0) return s;
    s = s->next;
  }
  return NULL;
}

// =======================================================================================================================
// return a pointer to random element in the list
struct song_node * random_song(struct song_node *s) {

    if (s == NULL) return s;

    int size = 0;
    struct song_node *looper = s;
    while (looper) {
        looper = looper->next;
        size++;
    }

    int random_node = rand() % size;

    int i = 0;
    while (s) {
        if (i == random_node) return s;
        s = s->next;
        i++;
    }
    return s;
}

// =======================================================================================================================
// remove a single specified node from the list
struct song_node * remove_song(struct song_node *s, char *n, char *a) {
  if (s == NULL) return s;
  else {
    // remove the first node
    if (strcasecmp(s->name, n) == 0 && strcasecmp(s->artist, a) == 0) {
      struct song_node *tmp = s->next;
      free(s);
      return tmp;
    }
    // remove a node other than the first
    else {
      struct song_node *s_copy = s;
      struct song_node *back = s;
      while (s) {
          if (strcasecmp(s->name, n) == 0 && strcasecmp(s->artist, a) == 0) {
          back->next = s->next;
          free(s);
        }
        back = s;
        s = s->next;
      }
      return s_copy;
    }
  }
}

// =======================================================================================================================
// free the entire list

struct song_node * free_list(struct song_node *s) {
    struct song_node *temp = s;
    while (s) {
        s = s->next;
        printf("Freeing: ");
        print_song(temp);
        printf("\n");
        free(temp);
        temp = s;
    }
    return s;
}
