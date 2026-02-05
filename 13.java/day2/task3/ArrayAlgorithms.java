public class ArrayAlgorithms {
  public static int Min(int[] arr) {
    long startTime = System.nanoTime(); 
    int min=arr[0];
    for (int i = 1; i < arr.length; i++) {
      if(arr[i]<min){
        min=arr[i];
      }
    }
    long endTime = System.nanoTime(); 
    System.out.println("Time taken: " + (endTime - startTime) + " ns");
    return min;
  }

  public static int Max(int[] arr) {
    long startTime = System.nanoTime(); 
    int max=arr[0];
    for (int i = 1; i < arr.length; i++) {
      if(arr[i]>max){
        max=arr[i];
      }
    }
     long endTime = System.nanoTime(); 
     System.out.println("Time taken: " + (endTime - startTime) + " ns");

    return max;
  }
  
  public static int binarySearch(int[] arr,int target) {

    long startTime = System.nanoTime(); 

    sortArray(arr);
    int len=arr.length;
    int mid=len/2;
    int low=0;
    int high=len-1;

    while(high>=low){
      mid=(high+low)/2;
      if(target==arr[mid]){
        long endTime = System.nanoTime(); 
        System.out.println("Time taken: " + (endTime - startTime) + " ns");
        return mid;
      }else if(arr[mid]>target){
        high=mid-1;
      }else if(arr[mid]<target){
        low=mid+1;
      }
    }

    long endTime = System.nanoTime(); 
    System.out.println("Time taken: " + (endTime - startTime) + " ns");

    return -1;
  }

  private static void sortArray(int[] arr) {
      for (int i = 0; i < arr.length - 1; i++) {
          for (int j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[i]) {
              int temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
            }
          }
      }
  }
}

