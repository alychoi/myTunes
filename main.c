#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "musiclibrary.h"
#include "musiclist.h"

int main() {

  srand(time(NULL));


  struct song_node **library = make_library();
  
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

  printf("===================================================== print_letter\n");
  print_letter(library, 'c');

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