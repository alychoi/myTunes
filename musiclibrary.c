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
  if (library == NULL) {
    printf("[ ]\n");
  }
  char c;
  for (int i = 0; i < 27; i++) {
    if (library[i] != NULL) {
      c = i + 97;
      printf("%c: ", c);
      print_list(library[i]);
    }
  }
}


// =======================================================================================================================
// shuffle - print out a series of randomly chosen songs.
void shuffle(struct song_node **library) {
  int count = 3;
  int i;
  for (i = 0; i < 3; i++) {
    int r = rand() % 27;
    while (library[r] == NULL) {
      r = rand() % 27;
    }
    print_song(random_song(library[r]));
  }
  printf("\n");
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
  free(library);
  library = NULL;
  return library;
}


// =======================================================================================================================
// testing musiclibrary.c

int main() {
  struct song_node **library = make_library();

  srand(time(NULL));
  
  printf("===================================================== print_letter\n");
  print_letter(library, 'a'); 

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

  library = add_song(library, "example_symbol_song", "66");

  printf("===================================================== print_letter c\n");
  print_letter(library, 'c');

  printf("===================================================== print_library\n");
  print_library(library);

  printf("===================================================== search_song\n");
  print_song(search_song(library, "viva la vida", "coldplay")); // found
  print_song(search_song(library, "hello", "coldplay")); // not found

  printf("===================================================== search_artist\n");
  print_song(search_artist(library, "m83")); // found
  print_song(search_artist(library, "cAlVin HarriS")); // found
  print_song(search_artist(library, "selena")); // not found

  printf("===================================================== delete_song (hello by adele)\n");
  delete_song(library, "hello", "adele");
  print_letter(library, 'a'); // should remove adele from section a
  
  printf("===================================================== clear_library\n");
  clear_library(library);
  printf("library after clear:\n");
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
  print_artist(library, "justin bieber"); // not found

  printf("===================================================== shuffle\n");
  shuffle(library);

  return 0;
}
