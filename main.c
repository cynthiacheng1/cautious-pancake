#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include "headers.h"


int main(){
  my_init();
  struct song_node *first = NULL;

  printf("Testing insert front with Mariah Carey and A$AP Rocky...\n");
  first = insert_front(first, "All I Want for Christmas is You", "Mariah Carey");
  first = insert_front(first, "Goldie", "A$AP Rocky");
  print_list(first);

  printf("Testing insert in order with Ke$ha...\n");
  insert_in_order(first, "TiK ToK", "Ke$ha");
  insert_in_order(first, "Paint it Black", "Rolling Stones");
  insert_in_order(first, "Piano Man", "Billy Joel");
  print_list(first);

  printf("Testing remove song with Billy Joel...\n");
  remove_node(first, find_song(first, "Piano Man", "Billy Joel"));
  print_list(first);

  printf("Testing free list...\n");
  free_list(first);

  insert_in_order(first, "Sugar Sugar", "The Archies");
  insert_in_order(first, "I'm a Believer", "The Monkees");
  insert_in_order(first, "Dream Lover", "Bobby Darin");
  insert_in_order(first, "Piano Man", "Billy Joel");
  insert_in_order(first, "We Didn't Start the Fire", "Billy Joel");
  insert_in_order(first, "Yesterday", "Beatles");
  insert_in_order(first, "Mr. Brightside", "The Killers");
  printf("Add a few more songs...\n");
  print_list(first);

  printf("Testing print all songs under B...\n");
  print_by_letter(first, "B");

  printf("Testing print all songs under Billy Joel...\n");
  print_by_artist(first, "Billy Joel");

  printf("Testing shuffle...\n");
  shuffle(first);

}
