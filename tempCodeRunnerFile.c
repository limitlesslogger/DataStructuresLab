s in first matrix\n");
    scanf("%d",&nonZero1);
    int r1,c1;
    printf("Enter number of rows and columns of sparse 1\n");
    scanf("%d %d",&r1,&c1);
    inputSparse(a,nonZero1,r1,c1);
    printf("input\n");
    displayInput(a,nonZero1);
    arrangeSparse(a,nonZero1);
    printf("Arrange\n");
    displayInput(a,nonZero1);
    printf("swap\n");
    transSparse(a,nonZero1);
    displayInput(a,nonZero1);
}
