#include "Map.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

Map* map_init()
{
  Map* map = (Map*)xmalloc(sizeof(Map));
  map->head = NULL;

  return map;
}

void map_push(Map* map, const char* key, int val)
{
  for (Node* n = map->head; n != NULL; n = n->next) 
  {
    if (strcmp(n->val->key, key) == 0) 
    {
      n->val->val = val;
      return;
    }
  }

  Pair* pair = (Pair*)xmalloc(sizeof(Pair));
  pair->val = val;
  pair->key = strdup(key);

  Node* node = (Node*)xmalloc(sizeof(Node));
  node->val = pair;
  node->next = map->head;
  map->head = node;
}

int map_get(Map* map, const char* key) 
{
  for (Node* n = map->head; n != NULL; n = n->next) 
  {
    if (strcmp(n->val->key, key) == 0)
      return n->val->val;
  }
  return -1;
}

void map_free(Map* map) 
{
  Node* n = map->head;
  while (n) 
  {
    Node* next = n->next;
    free(n->val->key);
    free(n->val);
    free(n);
    n = next;
  }
  free(map);
}