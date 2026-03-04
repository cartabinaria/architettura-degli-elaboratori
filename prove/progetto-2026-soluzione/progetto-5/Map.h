#ifndef MAP_H
#define MAP_H

typedef struct
{
  char* key;
  int   val;
} Pair;

typedef struct Node
{
  Pair* val;
  struct Node* next;
} Node;

typedef struct
{
  Node* head;
} Map;

Map* map_init();
void map_push(Map* map, const char* key, int val);
int  map_get(Map* map, const char* key);
void map_free(Map* map);

#endif