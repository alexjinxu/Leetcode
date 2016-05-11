/*

Task: You are given an n x n 2D matrix representing an image.

      Rotate the image by 90 degrees (clockwise).

Statues:Accepted

The thinking:

First doing a transpose of the given nxn matrix

Second doing a head-end rotating for each line of the transposed matrix.

*/


int** rotate(int** matrix, int matrixRowSize, int matrixColSize) {

    int index,tempStore;



    if (matrixRowSize == matrixRowSize)

    	    index = matrixRowSize -1;

       

    if (index == 0 )

    {

         return matrix;

    }

    

    

    for(int i = 0; i<index; i++)

    {

        for(int j =index; j>0; j--)

    

    	{

    		if(i!=j) 

    		{

    		  tempStore=matrix[i][j];

    		  matrix[i][j]=matrix[j][i];

    		  matrix[j][i]=tempStore;

    		}

    		else break;	

    	}

    }

    

    for(int i=0; i<=index; i++)

    {

    	for(int j=0; j<index-j; j++)

    	{

    		tempStore=matrix[i][j];

    		matrix[i][j]=matrix[i][index-j];

    		matrix[i][index-j]=tempStore;

    	}

    }

    

}