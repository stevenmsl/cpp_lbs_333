#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol333
{
  struct Node
  {
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val), left(nullptr), right(nullptr){};
  };

  struct NodeData
  {
    int size;
    /*
       - record the lowest value of this subtree
         among all its nodes
    */
    int lower;
    int upper;
    bool bst;
    /*
      - set lower to INT_MAX so it can pick the initial value
        in the first comparison
      - same idea for the upper
    */
    NodeData() : size(0), lower(INT_MAX), upper(INT_MIN), bst(false){};
  };

  class Solution
  {
  private:
  public:
    static int findBST(Node *root);
  };
}
#endif