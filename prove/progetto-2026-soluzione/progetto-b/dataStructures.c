#include "dataStructures.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

ListNode* list_push(ListNode* head, const char* val)
{
  if (!val) return head;

  ListNode* l = xmalloc(sizeof(ListNode));
  l->val = xstrdup(val);
  l->next = head;
  return l;
}

void list_free(ListNode* list)
{
  while (list) 
  {
    ListNode* next = list->next;
    free(list->val); 
    free(list);
    list = next;
  }
}

BstNode* bst_insert(BstNode* root, const char* s) 
{
  if (!s) return root;

  if (root == NULL) 
  {
    BstNode* n = xmalloc(sizeof(BstNode));
    n->key = xstrdup(s);
    n->left = n->right = NULL;
    return n;
  }

  int cmp = strcmp(s, root->key);

  if      (cmp < 0) root->left = bst_insert(root->left, s);
  else if (cmp > 0) root->right = bst_insert(root->right, s);

  return root;
}

bool bst_contains(const BstNode* root, const char *s) 
{
  if (!s) return false;
  while (root) 
  {
    int cmp = strcmp(s, root->key);
    if (cmp == 0) return true;
    root = (cmp < 0) ? root->left : root->right;
  }
  return false;
}

void bst_free(BstNode* root)
{
  if (!root) return;
  bst_free(root->left);
  bst_free(root->right);
  free(root->key);
  free(root);
}

BstListNode* bstlist_insert(BstListNode* root, const char* key, const char* val)
{
  if (!key || !val) return root;

  if (!root) 
  {
    root = xmalloc(sizeof(*root));
    root->key = xstrdup(key);
    root->list = NULL;
    root->left = root->right = NULL;
  }

  int c = strcmp(key, root->key);
  if (c == 0) 
  {
    root->list = list_push(root->list, val);
  } 
  else if (c < 0) 
  {
    root->left = bstlist_insert(root->left, key, val);
  } 
  else 
  {
    root->right = bstlist_insert(root->right, key, val);
  }
  return root;
}

const ListNode* bstlist_get(const BstListNode* root, const char* key)
{
  if (!key) return NULL;

  while (root) 
  {
    int c = strcmp(key, root->key);
    if (c == 0) return root->list;
    root = (c < 0) ? root->left : root->right;
  }
  return NULL;
}

void bstlist_free(BstListNode* root)
{
  if (!root) return;
  bstlist_free(root->left);
  bstlist_free(root->right);
  list_free(root->list);
  free(root->key);
  free(root);
}