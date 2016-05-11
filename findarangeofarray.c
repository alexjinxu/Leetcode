/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

     int * pp;
     int  temp, tempPos ;
     *returnSize=2;
     pp = (int)malloc(sizeof(int)*2);
     pp[0]=pp[1]=-1;
     
     tempPos = binarySearch(nums, 0,numsSize-1,target);
     if (tempPos == -1)
     {
    	 return pp;
     }
     else
     {
         pp[0]=pp[1]=tempPos;
         
    	 temp=tempPos-1;
    	 
    	 while( temp=binarySearch(nums,0,temp,target) >-1)
         {
            pp[0]=temp;
            temp=temp-1;        
         }

    	 temp=tempPos+1;
    	 
    	 while( temp=binarySearch(nums,temp,numsSize-1,target) >-1)
    	 {    
          
          pp[1]=temp;
          temp=temp+1;
          
    	 }

    	 
    	 return pp;
     }


}

int binarySearch(int* nums, int lowPos, int highPos, int target)
{
	int il, ih, midPos;
	il = lowPos;
	ih = highPos;
	midPos=(il+ih)/2;

	while(il<=ih)
	{
		 if (target == nums[midPos])
	    	 {
                return midPos;
	    	 }
	    	 if (target < nums[midPos])
	    	 {
	    		 ih = midPos-1;
	    		 midPos = (il+ih)/2;

	    	 }
	    	 else
	    	 {
	    		 il = midPos+1;
	    		 midPos = (il+ih)/2;
	    	 }

	}

	return -1;
}