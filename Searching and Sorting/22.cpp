// Find pivot element in a sorted and rotated array
// http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/

int peakElement(int arr[], int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;
     
    if (mid == lowerBound) 
    {
        if (mid == upperBound)
            return mid;

        else if (arr[mid] >= arr[mid + 1]) 
            return mid;
        
        else if (mid == upperBound) 
            if (arr[mid] >= arr[mid - 1])
                return mid;
    } 
    else 
    {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
            return mid;
        
        else if (arr[mid] > arr[high]) 
            return peakElement(arr, mid + 1, high, lowerBound, upperBound);
        
        else if (arr[mid] < arr[high]) 
            return peakElement(arr, low, mid - 1, lowerBound, upperBound);
    }
     
    return -1;
}