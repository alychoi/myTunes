#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// #include "musicibrary.h"
#include "musiclist.h"

// =======================================================================================================================
// make library; allocate enough memory for 27 linked lists, make sure each entry is an empty list
struct song_node ** make_library() {
  struct song_node **library = malloc(27 * sizeof(struct song_node *));
  int i;
  for (i = 0; i < 27; i++) {
    library[i] = NULL;
  }
  return library
}

// =======================================================================================================================
// add song nodes
struct song_node ** add_song(struct song_node **library, char *name, char *artist) {
  if (isalpha(letter)) return insert_song(library[toupper(artist[0])-65], name, artist);
  else return insert_song(library[26], name, artist);
}

// =======================================================================================================================
// search for a song given song and artist name (return a pointer)
struct song_node * search_song(struct song_node **library, char *name, char *artist) {
  if (isalpha(letter)) return find_song(library[toupper(artist[0])-65], name, artist);
  else return find_song(library[26], name, artist);
}

// =======================================================================================================================
// search for an artist (return a pointer)
struct song_node * search_artist(struct song_node **s, char *artist) {
  if (isalpha(letter)) return find_first_song(library[toupper(artist[0])-65], artist);
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
  while (s && strcmp(s->artist, artist) == 0) {
    print_song(s);
    s = s->next;
  }
}


// =======================================================================================================================
// print out the entire library
void print_library(struct song_node **library) {
  for (int i = 0; i < 27; i++) {
    print_list(library[i]);
  }
}


// =======================================================================================================================
// shuffle - print out a series of randomly chosen songs.
void shuffle(struct song_node **library) {
  struct song_node *list
  int count = 3;
  int r = rand() % 27;
  int i;
  for (i = 0; i < 3; i++) {
    rand_list = library[r];
    print_song(random_song(rand_list));
    free_list(rand_list);
  }
}


// =======================================================================================================================
// delete a song
struct song_node ** delete_song(struct song_node **library, char *name, char *artist) {
  struct song_node *gone = find_song(name, artist);

  if (gone == NULL) {
    return library;
  }
  else {
    if (isalpha(letter)) {
      library[toupper(artist[0]) - 65] = remove_song(library[toupper(artist[0]) - 65], name, artist);
    } 
    else {
      library[26] = remove_song(library[26], name, artist);
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


// =======================================================================================================================
// testing musiclibrary.c
int main() {
  struct song_node **library = make_library();
  
  printf("===================================================== print_letter\n");
  print_letter(library, "a");

  printf("===================================================== print_library\n");
  print_library(library);

  library = add_song(library, "Hello", "Adele");
  library = add_song(library, "Rolling in the Deep", "Adele");

  library = add_song(library, "Summer", "Calvin Harris");
  library = add_song(library, "Outside", "Calvin Harris");

  library = add_song(library, "Viva la Vida", "Coldplay");
  library = add_song(library, "A Sky Full of Stars", "Coldplay");
  library = add_song(library, "Paradise", "Coldplay");
  library = add_song(library, "Hymm for the Weekend", "Coldplay");
  library = add_song(library, "Clocks", "Coldplay");

  library = add_song(library, "Time", "Hans Zimmer");

  library = add_song(library, "Latch", "Disclosure");

  library = add_song(library, "Midnight City", "M83");
  library = add_song(library, "Oblivion", "M83");

  printf("===================================================== print_letter\n");
  print_letter(library, "c");

  printf("===================================================== print_library\n");
  print_library(library);

  printf("===================================================== search_song\n");
  search_song(library, "viva la vida", "coldplay"); // found
  search_song(library, "hello", "coldplay"); // not found

  printf("===================================================== search_artist\n");
  search_artist(library, "m83"); // found
  search_artist(library, "cAlVin HarriS"); // found
  search_artist(library, "selena"); // not found

  printf("===================================================== delete_song\n");
  delete_song(library, "hello", "adele");
  print_letter(a) // should remove adele from section a
  
  printf("===================================================== clear_library\n");
  clear_library(library);
  printf("library after clear:\n")
  print_library(library);
  
  library = add_song(library, "Hello", "Adele");
  library = add_song(library, "Rolling in the Deep", "Adele");

  library = add_song(library, "Summer", "Calvin Harris");
  library = add_song(library, "Outside", "Calvin Harris");

  library = add_song(library, "Viva la Vida", "Coldplay");
  library = add_song(library, "A Sky Full of Stars", "Coldplay");
  library = add_song(library, "Paradise", "Coldplay");
  library = add_song(library, "Hymm for the Weekend", "Coldplay");
  library = add_song(library, "Clocks", "Coldplay");

  library = add_song(library, "Time", "Hans Zimmer");

  library = add_song(library, "Latch", "Disclosure");

  library = add_song(library, "Midnight City", "M83");
  library = add_song(library, "Oblivion", "M83");
  library = add_song(library, "Hallo", "Adele");
  
  printf("===================================================== print_artist\n");
  print_artist(library, "hans zimmer"); // found
  print_artist(library, "justin bieber") // not found

  printf("===================================================== shuffle\n");
  shuffle(library);

  return 0;
}