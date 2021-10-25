#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "musiclibrary.h"
#include "musiclist.h"


int main() {

  srand(time(NULL));

  struct song_node *list = NULL;

  printf("===================================================== make_song, insert_front, insert_song\n");

  list = insert_front(list, "Hello", "Adele");
  list = insert_song(list, "Rolling in the Deep", "Adele");

  list = insert_song(list, "Summer", "Calvin Harris");
  list = insert_song(list, "Outside", "Calvin Harris");

  list = insert_song(list, "Viva la Vida", "Coldplay");
  list = insert_song(list, "A Sky Full of Stars", "Coldplay");
  list = insert_song(list, "Paradise", "Coldplay");
  list = insert_song(list, "Hymm for the Weekend", "Coldplay");
  list = insert_song(list, "Clocks", "Coldplay");

  list = insert_song(list, "Time", "Hans Zimmer");

  list = insert_song(list, "Latch", "Disclosure");

  list = insert_song(list, "Midnight City", "M83");
  list = insert_song(list, "Oblivion", "M83");

  printf("===================================================== print_list, print_song\n");
  print_list(list);

  printf("===================================================== random_song\n");
  print_song(random_song(list));
  print_song(random_song(list));
  print_song(random_song(list));
  print_song(random_song(list));
  print_song(random_song(list));
  print_song(random_song(list));
  printf("\n");


  printf("===================================================== find_first_song\n");
  printf("First song by COLD\n");
  print_song(find_first_song(list, "COLD"));
  printf("\n");

  printf("First song by COLDPLAY\n");
  print_song(find_first_song(list, "COLDPLAY"));
  printf("\n");

  printf("First song by CALVIN HARRIS\n");
  print_song(find_first_song(list, "CALVIN HARRIS"));
  printf("\n");


  printf("===================================================== find_song\n");
  printf("OUTSIDE by CALVIN HARRIS\n");
  print_song(find_song(list, "OUTSIDE", "CALVIN HARRIS"));
  printf("\n");

  printf("SUMMER by CALVIN HARRIS\n");
  print_song(find_song(list, "SUMMER", "CALVIN HARRIS"));
  printf("\n");

  printf("VIVA LA VIDA by COLDPLAY\n");
  print_song(find_song(list, "VIVA LA VIDA", "COLDPLAY"));
  printf("\n");


  printf("===================================================== song_compare\n");
  printf("Comparing ");
  print_song(find_song(list, "SUMMER", "CALVIN HARRIS"));
  printf(" to ");
  print_song(find_song(list, "OUTSIDE", "CALVIN HARRIS"));
  printf("\n%d\n\n", song_compare(find_song(list, "SUMMER", "CALVIN HARRIS"), find_song(list, "OUTSIDE", "CALVIN HARRIS")));

  printf("Comparing ");
  print_song(find_song(list, "VIVA LA VIDA", "COLDPLAY"));
  printf(" to ");
  print_song(find_song(list, "SUMMER", "CALVIN HARRIS"));
  printf("\n%d\n\n", song_compare(find_song(list, "VIVA LA VIDA", "COLDPLAY"), find_song(list, "SUMMER", "CALVIN HARRIS")));\

  printf("Comparing ");
  print_song(find_song(list, "SUMMER", "CALVIN HARRIS"));
  printf(" to ");
  print_song(find_song(list, "SUMMER", "CALVIN HARRIS"));
  printf("\n%d\n\n", song_compare(find_song(list, "SUMMER", "CALVIN HARRIS"), find_song(list, "SUMMER", "CALVIN HARRIS")));



  printf("===================================================== remove_song\n");
  printf("Remove Latch by Disclosure\n");
  list = remove_song(list, "Latch", "Disclosure");
  print_list(list);

  printf("Remove hELlo by adElE\n");
  list = remove_song(list, "hELlo", "adElE");
  print_list(list);

  printf("Remove He by AdELe\n");
  list = remove_song(list, "hE", "adElE");
  print_list(list);

  printf("===================================================== free_list\n");
  free_list(list);

  // ============================================================================================
  // there is occasionally a segmentation fault that occurs around here
  // (make clean --> make --> make run) usually resolves this issue

  printf("===================================================== make_library\n");
  struct song_node **library = make_library();

  printf("===================================================== print_library (empty)\n");
  print_library(library);

  printf("===================================================== add_song\n");
  library = add_song(library, "Hello", "Adele");
  library = add_song(library, "Viva la Vida", "Coldplay");

  library = add_song(library, "Summer", "Calvin Harris");
  library = add_song(library, "Outside", "Calvin Harris");

  library = add_song(library, "A Sky Full of Stars", "Coldplay");
  library = add_song(library, "Paradise", "Coldplay");
  library = add_song(library, "Hymm for the Weekend", "Coldplay");
  library = add_song(library, "Clocks", "Coldplay");

  library = add_song(library, "Ripples in the Sand", "Hans Zimmer");
  // library = add_song(library, "Time", "Hans Zimmer");

  // library = add_song(library, "Midnight City", "M83");
  // library = add_song(library, "Oblivion", "M83");

  // library = add_song(library, "example_symbol_song", "66");

  printf("===================================================== print_library (full)\n");
  print_library(library);

  printf("===================================================== print_letter ('c')\n");
  print_letter(library, 'c');

  printf("===================================================== print_artist\n");
  print_artist(library, "hans zimmer"); // found
  print_artist(library, "justin bieber"); // not found

  printf("===================================================== search_song\n");
  print_song(search_song(library, "viva la vida", "coldplay")); // found
  print_song(search_song(library, "hello", "coldplay")); // not found

  printf("===================================================== search_artist\n");
  print_song(search_artist(library, "m83")); // not found
  print_song(search_artist(library, "cAlVin HarriS")); // found
  print_song(search_artist(library, "selena")); // not found

  printf("===================================================== shuffle\n");
  shuffle(library);

  printf("===================================================== delete_song\n");
  delete_song(library, "hello", "adele");
  print_letter(library, 'a'); // should remove adele from section a

  printf("===================================================== clear_library\n");
  clear_library(library);
  printf("library after clear:\n");
  print_library(library);

  return 0;
}
