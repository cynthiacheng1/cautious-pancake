#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * table[26];

void print_list(struct song_node *n){
    while (n){
      printf(" [%s|%s] ", (*n).artist, (*n).name);
      n = n -> next; //(*n).next
    }
}

struct song_node * insert_front(struct song_node *pointer , char[] song_name, char[] song_artist){
  struct song_node *frontP = (struct song_node *)malloc(sizeof(struct song_node));
  (* frontP).name = song_name;
  (* frontP).artist = song_artist;
  (* frontP).next = pointer;
  return frontP;
}

struct song_node * insert_in_order(struct song_node *pointer , char[] song_name, char[] song_artist){
    if (*pointer).artist.strcmp(song_artist) < 0){
      insert_front(pointer, song_name, song_artist);
    }
  while (pointer){
      if (*pointer).next.artist.strcmp(song_artist) < 0){
        (*pointer).next = insert_front(pointer.next, song_name, song_artist);
      }
      pointer = (*pointer).next
  }
}

struct song_node * free_list(struct song_node *pointer){
  struct song_node *retpoint = pointer;
  while(pointer){
    struct song_node *updater = pointer;
    pointer = pointer->next;
    free(updater);
    updater = NULL;
  }
  return pointer;
}

struct song_node * indiv_song(char[] song){
  struct song_node * beginning = &table[song[0]-65];
  while (beginning){
    if ((*beginning).name.strcmp(song) = 0){
      return beginning;
    }
  }
  return NULL;
}

int main(){
  struct song_node *node = NULL;
  printf("insert_front w song");
  while(i <= 10){
    char[] song = "abc";
    char[] artist = "me";
    node = insert_front(node, song, artist);
    i++;
  }
  print_list(node);

}
