#include <stdio.h>
#include <stdlib.h>

struct tree {
  int value;
  struct tree *left;
  struct tree *right;
};

struct subtree_info {
  int sum;
  int size;
};

struct subtree_info check(struct tree *node) {
  if (node == NULL) {
    return (struct subtree_info){0, 0};
  }
  struct subtree_info left_info = check(node->left);
  struct subtree_info right_info = check(node->right);
  int sum = left_info.sum + right_info.sum + node->value;
  int size = left_info.size + right_info.size + 1;
  return (struct subtree_info){sum, size};
}

int main() {
  int n, x, d;
  int edge_node1, edge_node2;
  int first = 0;
  scanf("%d %d %d", &n, &x, &d);
  struct tree **nodes = malloc(n * sizeof(struct tree *));
  for (int i = 0; i < n; i++) {
    int node_value;
    scanf("%d\n", &node_value);
    nodes[i] = malloc(sizeof(struct tree));
    nodes[i]->value = node_value;
    nodes[i]->left = NULL;
    nodes[i]->right = NULL;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &edge_node1, &edge_node2);
    edge_node1--;
    edge_node2--;
    if (nodes[edge_node1]->left == NULL) {
      nodes[edge_node1]->left = nodes[edge_node2];
    } else {
      nodes[edge_node1]->right = nodes[edge_node2];
    }
    if (nodes[edge_node2]->left == NULL) {
      nodes[edge_node2]->left = nodes[edge_node1];
    } else {
      nodes[edge_node2]->right = nodes[edge_node1];
    }
  }
  check(nodes[0]);
  for (int i = 0; i < n; i++) {
    int subtree_sum = check(nodes[i]).sum;
    if (abs(subtree_sum - x) < d) {
      if (first == 0) {
        printf("%d", i + 1);
        first = 1;
      } else {
        printf(" %d", i + 1);
      }
    }
  }
  printf("\n");
  return 0;
}