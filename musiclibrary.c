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
      printf(" [%s|%s] \n", (*n).artist, (*n).name);
      n = n -> next; //(*n).next
    }
}

int get_length(struct song_node *pointer){
  int length = 0;
  while (pointer){ //iterate through all the song_nodes
    length++;
    pointer = pointer->next;
  }
  return length;
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
    return insert_front(pointer, song_name, song_artist);
  }
  while (pointer->next){
      if (strcmp(song_artist, (*(pointer->next)).artist) < 0){
        (*pointer).next = insert_front(pointer->next, song_name, song_artist);
        return pointer->next;
      }
      pointer = pointer -> next;
  }
  return insert_front(pointer, song_name, song_artist);
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
  int length = get_length(n);
  srand( time(NULL) );
  int numberR = rand() % length;
  for (; numberR > 0; numberR--){
    n = n->next;
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

struct song_node * free_list(struct song_node *pointer){
  while(pointer-> next){
    remove_node(pointer, pointer->next);
  }
  pointer = NULL;
  return NULL;
}

void print_by_letter(struct song_node *pointer, char * letter){
  while(pointer){
    if ((&((*pointer).artist))[0] == letter){
      printf(" [%s|%s] \n", (*pointer).artist, (*pointer).name);
    }
    pointer = pointer-> next;
  }
}

void print_by_artist(struct song_node *pointer, char * artist){
  while(pointer){
    if (strcmp((*pointer).artist,artist) == 0){
      printf(" [%s|%s] \n", (*pointer).artist, (*pointer).name);
    }
    pointer = pointer-> next;
  }
}

void shuffle(struct song_node *pointer, int n){
  struct song_node *current = (struct song_node *)malloc(sizeof(struct song_node));
  int i = n;
  while (i > 0){
    current = random_song(pointer);
    printf(" [%s|%s] \n", (*current).artist, (*current).name);
    i--;
  }
}

int main(){
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
  //free_list(first);

  insert_in_order(first, "Sugar Sugar", "The Archies");
  insert_in_order(first, "I'm a Believer", "The Monkees");
  insert_in_order(first, "Dream Lover", "Bobby Darin");
  insert_in_order(first, "Piano Man", "Billy Joel");
  insert_in_order(first, "We Didn't Start the Fire", "Billy Joel");
  printf("Add a few more songs...\n");
  print_list(first);

  printf("Testing print all songs under B...\n");
  print_by_letter(first, "B");
  print_by_artist(first, "Billy Joel");

  printf("Testing shuffle...\n");
  shuffle(first, 1);
}
