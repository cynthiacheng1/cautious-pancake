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
  (*n).next = 0;
  strcopy((*n).name, song_name);
  strcopy((*n).artist, song_artist);
  return n;
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

struct song_node * indiv_song(struct song_node *pointer){
  char[] input_artist = (*pointer).artist;
  char[] input_song = (*pointer).name;
  struct song_node * beginning = &table[input_artist[0]-'a'];
  while (beginning){
    if ((*beginning).name.strcmp(input_song) = 0){
      return beginning;
    }
  }
  return NULL;
}

struct song_node * indiv_artist(struct song_node *pointer){
  char[] input_artist = (*pointer).artist;
  char[] input_song = (*pointer).name;
  struct song_node * beginning = &table[input_artist[0]-'a'];
  while (beginning){
    if ((*beginning).artist.strcmp(input_artist) = 0){
      return beginning;
    }
  }
  return NULL;
}

struct song_node * random_song(struct song_node *n){
  srand(time(NULL));
  // int r = rand()%26; -> figure out array yo
  struct song_node *length = n;
  int len = 0
  while (length){
    n = n -> next;
    len++;
  }
  int r = rand()%len;
  while (r){
    n = n -> next;
    r--;
  }
  return n;
}

struct song_node * remove_node(struct song_node *pointer){

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
