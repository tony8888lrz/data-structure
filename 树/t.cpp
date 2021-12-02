Status CreateHuffmanTree_HT(FILE *fp, HuffmanTree *HT)
{
	int m, n;
	int w[MAX_TREE_SIZE];
	HuffmanTree p;
	int i;
	int s1, s2;

	Scanf(fp, "%d", &n); 	
	printf("录入哈夫曼树叶子结点个数→ %d\n", n);
	
	printf("依次录入各叶子结点的权值→ ");
	for(i=1; i<=n; i++)									//0号单元弃用
	{
		Scanf(fp, "%d", &w[i]);
		printf("%d ", w[i]);
	}
	printf("\n");
	
	m = 2*n - 1;										//哈夫曼树有效结点个数
		
	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0号单元弃用
	if(!(*HT))
		exit(OVERFLOW);
	
	(*HT)[0].weight = n;								//利用0号单元的权值存储哈夫曼树叶子个数
 		
	for(i=1; i<=m; i++)									//初始化结点[1...2*n+1]，存储叶子结点及双亲结点 
	{		
		if(i<=n)										 
			(*HT)[i].weight = w[i];						//[1...n]，叶子结点
		else											 
			(*HT)[i].weight = 0;						//[n+1...2*n+1]，双亲结点

		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0; 
	} 
	
	for(i=n+1; i<=m; i++)								//建立哈夫曼树
	{
		Select_HT(*HT, i-1, &s1, &s2);
	
		(*HT)[s1].parent = (*HT)[s2].parent = i;

		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	
	return OK;
} 