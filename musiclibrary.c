#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_list(struct song_node *n){
    while (n){
      printf(" [%s|%s] ", (*n).artist, (*n).name);
      n = n -> next; //(*n).next
    }
}

struct song_node * insert_front(struct song_node *currentF, char * song_name, char * song_artist){
  struct song_node *newF = (struct song_node *)malloc(sizeof(struct song_node));
  (*newF).next = currentF;
  strcpy((*newF).name, song_name);
  strcpy((*newF).artist, song_artist);
  return newF;
}

struct song_node * insert_in_order(struct song_node *pointer, char * song_name, char * song_artist){
  struct song_node *retVal = (struct song_node *)malloc(sizeof(struct song_node));
  if (strcmp(song_artist, (*pointer).artist) < 0){
    retVal = insert_front(pointer, song_name, song_artist);
  }
  while (pointer){
      if (strcmp(song_artist, (*(pointer->next)).artist) < 0){
        pointer->next = insert_front(pointer->next, song_name, song_artist);
      }
      pointer = (*pointer).next;
      retVal = pointer;
  }
  return retVal;
}

struct song_node * find_song(struct song_node *pointer, char * song_name, char * song_artist){
  while (pointer){
    if ((strcmp(song_name, (*pointer).name) == 0) && (strcmp(song_artist, (*pointer).artist) == 0)){
      return pointer;
    }
    else{
      pointer = (*pointer).next;
    }
  }
  return NULL;
}

struct song_node * find_song_by_artist(struct song_node *pointer, char * song_artist){
  while (pointer){
    if (strcmp(song_artist, (*pointer).artist) == 0){
      return pointer;
    }
    pointer = pointer-> next;
  }
  return NULL;
}

struct song_node * random_song(struct song_node *n){
  srand(time(NULL));
  int len = rand();
  while (len){
    n = n -> next;
    len--;
  }
  return n;
}

struct song_node * remove_node(struct song_node *pointer, struct song_node *removeN){
  if (pointer == removeN){
    (*pointer).next = pointer->next->next;
    return removeN;
    free(removeN);
  }
  else{
    while (pointer){
      if ((*pointer).next == removeN){
        (*pointer).next = pointer->next->next;
        free(removeN);
      }
      else{
        pointer = (*pointer).next;
      }
    }
    return removeN;
  }

}

int main(){
}
