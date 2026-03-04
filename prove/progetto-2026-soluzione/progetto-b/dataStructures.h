#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdbool.h>

typedef struct ListNode
{
  char* val;
  struct ListNode* next;
} ListNode;

ListNode* list_push(ListNode* head, const char* val);
void list_free(ListNode* list);

typedef struct BstNode 
{
  char* key;
  struct BstNode* left;
  struct BstNode* right;
} BstNode;

BstNode* bst_insert(BstNode* root, const char* s);
bool bst_contains(const BstNode* root, const char* s);
void bst_free(BstNode* root);

typedef struct BstListNode 
{
  char* key;
  ListNode* list;
  struct BstListNode* left;
  struct BstListNode* right;
} BstListNode;

BstListNode* bstlist_insert(BstListNode* root, const char* key, const char* val);
const ListNode* bstlist_get(const BstListNode* root, const char* key);
void bstlist_free(BstListNode* root);

#endif