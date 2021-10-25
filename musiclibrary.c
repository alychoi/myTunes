#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "musiclibrary.h"
#include "musiclist.h"

// =======================================================================================================================
// make library; allocate enough memory for 27 linked lists, make sure each entry is an empty list
struct song_node ** make_library() {
  struct song_node **library = malloc(27 * sizeof(struct song_node *));
  int i;
  for (i = 0; i < 27; i++) {
    library[i] = NULL;
  }
  return library;
}


// =======================================================================================================================
// add song nodes
struct song_node ** add_song(struct song_node **library, char *name, char *artist) {

  if (isalpha(artist[0])) {
    library[toupper(artist[0])-65] = insert_song(library[toupper(artist[0])-65], name, artist);
  }
  else {
    library[26] = insert_song(library[26], name, artist);
  }

  return library;
}


// =======================================================================================================================
// search for a song given song and artist name (return a pointer)
struct song_node * search_song(struct song_node **library, char *name, char *artist) {
  if (isalpha(artist[0])) {
    return find_song(library[toupper(artist[0])-65], name, artist);
  }
  else return find_song(library[26], name, artist);
}

// =======================================================================================================================
// search for an artist (return a pointer)
struct song_node * search_artist(struct song_node **library, char *artist) {
  if (isalpha(artist[0])) return find_first_song(library[toupper(artist[0])-65], artist);
  else return find_first_song(library[26], artist);
}


// =======================================================================================================================
// print out all the entries under a certain letter
void print_letter(struct song_node **library, char letter) {
  if (isalpha(letter)) {
    print_list(library[toupper(letter)-65]);
  }
  else {
    print_list(library[26]);
  }
}


// =======================================================================================================================
// print out all the songs of a certain artist
void print_artist(struct song_node **library, char *artist) {
  struct song_node *s = search_artist(library, artist);
  printf("%s: ", artist);
  while (s && strcasecmp(s->artist, artist) == 0) {
    print_song(s);
    s = s->next;
  }
  printf("\n");
}


// =======================================================================================================================
// print out the entire library
void print_library(struct song_node **library) {
  if (library == NULL) printf("");
  else {
    int i;
    for (i = 0; i < 27; i++) {
      print_list(library[i]);;
    }
  }

}



// =======================================================================================================================
// shuffle - print out a series of randomly chosen songs.
void shuffle(struct song_node **library) {
  int count = 3;
  int i;
  printf("[ ");
  for (i = 0; i < count; i++) {
    int r = rand() % 27;
    while (library[r] == NULL) {
      r = rand() % 27;
    }
    if (i > 0 && i < count) printf(" | ");
    print_song(random_song(library[r]));
  }
  printf(" ]\n");
}


// =======================================================================================================================
// delete a song
struct song_node ** delete_song(struct song_node **library, char *name, char *artist) {
  struct song_node *gone;

  if (isalpha(artist[0])) {
    gone = find_song(library[toupper(artist[0]) - 65], name, artist);
  }
  if (!isalpha(artist[0])) {
    gone = find_song(library[26], name, artist);
  }

  if (gone == NULL) {
    return library;
  }

  else {
    if (isalpha(artist[0])) {
      library[toupper(artist[0]) - 65] = remove_song(library[toupper(artist[0]) - 65], name, artist);
      return library;
    }
    else {
      library[26] = remove_song(library[26], name, artist);return library;
    }
  }
}


// =======================================================================================================================
// clear out all the linked lists in the library
struct song_node ** clear_library(struct song_node **library) {
  int i;
  for (i = 0; i < 27; i++) {
    library[i] = free_list(library[i]);
  }
  return library;
}
