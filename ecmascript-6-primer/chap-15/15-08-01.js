/*
  二叉树的遍历分为 广度优先 和 深度优先 两类
  深度优先分为：前序遍历，中续遍历，后续遍历，此处的前中后描述的是根节点的遍历时机。
  当前实例是深度优先算法, 其树形结构如下：
      d
   b     f
  a c   e g
 */
function Tree(left, label, right){
  this.left = left;
  this.label = label;
  this.right = right;
}

function* inorder(t){
  if (!t) return;

  yield t.label;
  yield* inorder(t.left);
  yield* inorder(t.right);
}

function make(array){
  if(array.length === 1){
    return new Tree(null, array[0], null);
  }

  return new Tree(make(array[0]), array[1], make(array[2]));
}

let tree = make([[['a'], 'b', ['c']], 'd', [['e'], 'f', ['g']]]);

var result = [...inorder(tree)];

console.log(result);