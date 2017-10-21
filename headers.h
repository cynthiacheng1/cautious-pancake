//structs
struct song_node { char name[256]; char artist[256]; struct song_node *next; };
struct song_node * arr[26];

void print_list(struct song_node *);
void my_init();
int get_length(struct song_node *);
struct song_node * insert_front(struct song_node *, char * , char * );
struct song_node * insert_in_order(struct song_node *, char * , char * );
struct song_node * remove_node(struct song_node *, struct song_node *);
struct song_node * free_list(struct song_node *);
void print_by_letter(struct song_node *, char * );
void print_by_artist(struct song_node *, char * );
void shuffle(struct song_node *);
