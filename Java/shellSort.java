class shellSort
{
	public static void main(String args[])
	{
		int arr[] = {20, 7, 35, -22, 1};
		display(arr);
		int gap = arr.length/2;
		for(int i=gap;i<5;i++)
		{
			int key = arr[i];
			int j=i;
			while(j>0 && key<arr[j-gap])
			{
				arr[j] = arr[j-gap];
				j = j-gap;
			}
			arr[	]
		}

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
