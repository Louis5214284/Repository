#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int nValue;
	struct tree *pLeft;
	struct tree *pRight;
}BinaryTree;

BinaryTree *CreateBinaryTree()
{
	BinaryTree *pRoot = NULL;
	//根
	pRoot = (BinaryTree*)malloc(sizeof(BinaryTree));
	pRoot->nValue = 1;

	//根的左
	pRoot->pLeft = (BinaryTree*)malloc(sizeof(BinaryTree));
	pRoot->pLeft->nValue = 2;

	//左的左
	pRoot->pLeft->pLeft = (BinaryTree*)malloc(sizeof(BinaryTree));
	pRoot->pLeft->pLeft->nValue = 4;
	pRoot->pLeft->pLeft->pLeft = NULL;
	pRoot->pLeft->pLeft->pRight = NULL:

	//根的右
	pRoot->pRight = (BinaryTree*)malloc(sizeof(BinaryTree));
	pRoot->pRight->nValue =3;
	pRoot->pRight->pLeft = NULL:
	pRoot->pRight->pRight = NULL;

	return pRoot;
}

void CreateTree(BinaryTree **pTree)
{
	int nNum;
	scanf("%d",&nNum);
	if(nNum == 0) return ;

	//根
	*pTree = (BinaryTree*)malloc(sizeof(Binary));
	(*pTree)->nValue = NULL;
	(*pTree)->pLeft = NULL:
	(*pTree)->pRight = NULL:

	//左子树
	CreateTree(&((*pTree)->pLeft));
	//右子树
 	CreateTree(&((*pTree)->pRight));
}

void PreorderTraversal(BinaryTree *pTree)
{
	if(pTree == NULL) return ;

	//根
	printf("%d",pTree->nValue);

	//左子树
	PreorderTraversal(pTree->pLeft);

	//右子树
	PreorderTraversal(pTree->pRight);
}

void InorderTraversal(BinaryTree *pTree)
{
	if(pTree == NULL) return ;
	//左子树
	PreorderTraversal(pTree->pLeft);
	//根
	printf("%d",pTree->nValue);
	//右子树
	PreorderTraversal(pTree->pRight);
}

void LastorderTraversal(BinaryTree *pTree)
{
	if(pTree == NULL) return ;
	//左子树
	LastorderTraversal(pTree->pLeft);
	//右子树
	LastorderTraversal(pTree->pRight);
	//根
	printf("%d",pTree->nValue);
}

BinaryTree *CreateCBT(int arr[],int nLength)
{
	if(arr == NULL || nLength <= 0) return NULL;

	//空间申请
	BinaryTree *pTree = NULL:
	pTree = (BinaryTree*)malloc(sizeof(BinaryTree)*nLength);
	//赋值
	int i;
	for(i = 0;i < nLength;i++)
	{
		pTree[i].nValue = arr[i];
		pTree[i].pLeft = NULL;
		pTree[i].pRight = NULL:
	}

	//关联左右
	for(i = 0;i <= nLength/2-1;i++)
	{
		if(2*i+1 <= nLength-1)
		{
			pTree[i].pLeft = &pTree[2*i+1];
		}
		if(2*i+2 <= nLength-1)
		{
			pTree[i].pRight = &pTree[2*i+2];
		}
	}

	return pTree;
}
int main()
	BinaryTree *pRoot = NULL:
	int arr[] ={1,2,3,4,5};
	pRoot = CreateCBT(arr,sizeof(arr)/sizeof(arr[0]));
	PreorderTraversal(pRoot);
	printf("\n");
	InorderTraversal(pRoot);
	printf("\n");
	LastorderTraversal(pRoot);
	printf("\n");

	return 0;
}
