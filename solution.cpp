#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol333;
using namespace std;

/*takeaways
  - you need a data structure to record info for a subtree
    - number of nodes (size)
    - range of values (lower, and upper)
    - if it's a BST (bst)

  - visit the tree
    - to verify if a subtree is a BST
      and keep track the max size among
      found BSTs

  - edge cases
    - leaf node is a BST; nullptr is not
      - you need to deal with these two separately
    - use >= and <= when checking if node value
      is within the bound (lower, upper) to include
      the case for leaf nodes

  - TODO: check the time complexity. Goal is O(n)
*/

int Solution::findBST(Node *root)
{
  if (root == nullptr)
    return 0;

  auto max = 0;

  function<NodeData(Node *)> visit = [&max, &visit](Node *node)
  {
    auto data = NodeData();

    if (node == nullptr)
    {
      /* you can't just say it's a bst, or you will be wrong
         in this case
            15
           / \
         null 7
      */
      data.bst = false;
      return data;
    }
    else if (node->left == nullptr && node->right == nullptr)
    {
      /*
         - make a leaf node a BST or its parent will
           have no chance to be considered as a BST
           even the entire subtree is
         - you also need to update the bound and size
           accordingly
      */
      data.bst = true;
      data.size = 1;
      data.lower = node->val;
      data.upper = node->val;
      return data;
    }

    auto left = visit(node->left);
    auto right = visit(node->right);
    /* update the min and max values of this tree
       - remember we don't know if it's a BST yet
    */
    data.lower = std::min(node->val,
                          std::min(left.lower, right.lower));
    data.upper = std::max(node->val,
                          std::max(left.upper, right.upper));
    /* check if this a BST
       - make sure the node value is within bound
       - you need to use the >= and <= or the
         leaf nodes will not be qualified
    */
    if (left.bst && right.bst &&
        node->val >= data.lower &&
        node->val <= data.upper)
    {
      data.bst = true;
      data.size = left.size + right.size + 1;
      max = std::max(max, data.size);
    }

    return data;
  };

  visit(root);

  return max;
}