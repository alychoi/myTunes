struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node * make_song(char *name, char *artist);

struct song_node * insert_front(struct song_node *s, char *name, char *artist);

int song_compare(struct song_node *s1, struct song_node *s2);

struct song_node * insert_song(struct song_node *s, char *name, char *artist);

void print_song(struct song_node *s);

void print_list(struct song_node *s);

struct song_node * find_song(struct song_node *s, char *n, char *a);

struct song_node * find_first_song(struct song_node *s, char *a);

struct song_node * random_song(struct song_node *s);

struct song_node * remove_song(struct song_node *s, char *n, char *a);

struct song_node * free_list(struct song_node *s);