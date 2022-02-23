#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol333;

/*
Input: [10,5,15,1,8,null,7]

   10
   / \
  5  15
 / \   \
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the subtree [5,1,8].
The return value is the subtree's size, which is 3.
*/
tuple<Node *, int>
testFixture1()
{
  auto left = new Node(5);
  left->left = new Node(1);
  left->right = new Node(8);

  auto right = new Node(15);
  right->right = new Node(7);

  auto root = new Node(10);
  root->left = left;
  root->right = right;
  return make_tuple(root, 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findBST(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}