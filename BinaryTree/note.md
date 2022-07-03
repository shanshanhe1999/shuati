# 二叉树
## week2 总结
### 1 对称二叉树
``` c++
/*
 * 终止条件
 */
//单层递归逻辑
bool outside=compare(left->left,right->right);//左子树：左；右子树：右
bool inside=compare(left->right,right->left);//左子树：右；右子树：左
bool isSym=outside&&inside;//左右子树：中
return isSym;
```
