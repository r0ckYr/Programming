import java.util.Arrays;
import java.util.*; 
class GFG {
  
	static int[] push(int arr[], int element)
	{
		int arr2[] = Arrays.copyOf(arr, arr.length+1);
		arr2[arr2.length-1] = element;
		return arr2;
	}
	
	static int[] pop(int arr[])
	{
		int arr2[] = Arrays.copyOf(arr, arr.length-1);
		return arr2;
	}

    public static void main(String[] args)
    {
		/*
		 Arrays.sort() - parameters (an array) -  returns (nothing)
		 Arrays.copyOf() - parameters (an array, length of new array) - returns (an array)
		 Arrays.equals() - parameters (two arrays) - returns (boolean)
		 */
        int intArr[]=new int[5];
		for(int i=0;i<5;i++)
		{
			intArr[i] = i+1*3;
		}
		Scanner sc=new Scanner(System.in);
		String sArr[] = sc.nextLine().split(" ");
		System.out.println(sArr.length);
		for(int i=0;i<5;i++)
		{
			intArr[i] = Integer.parseInt(sArr[i]);
		}


        System.out.println("Integer Array as List: "+ Arrays.toString(intArr));
		intArr = push(intArr, 69);
		//int arr2[] = Arrays.copyOf(intArr, intArr.length-1);
		//Arrays.sort(intArr);
		//boolean f = Arrays.equals(arr1, arr2);
        System.out.println("Integer Array as List: "+ Arrays.toString(intArr));
		intArr = pop(intArr);   
		System.out.println("Integer Array as List: "+ Arrays.toString(intArr));
    }
}
