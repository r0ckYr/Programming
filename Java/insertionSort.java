import java.io.*;
class insertionSort
{
	public static void main(String args[])throws IOException
	{
		int arr[]={2,4,1,6,-1};
		int j=0,key;
		for(int i=0;i<5;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		for(int i=1;i<5;i++)
		{
			key = arr[i];
			j=i;
			while(j>0 && key<arr[j-1])
			{
				arr[j] = arr[j-1];
				j--;
				display(arr);
			}
			arr[j] = key;
		}
		for(int i=0;i<5;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();

	}
	static void display(int arr[])
	{

		for(int i=0;i<5;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
}
