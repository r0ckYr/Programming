#include<iostream>
using namespace std;
void display(int arr[]);


void display(int arr[3], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n'<< endl;
}

void display2(int r, int c, int arr[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n'<< endl;
}


void second(int arr[10], int k)
{
    int arr2[9];
    int c = 0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]!=k)
        {
            arr2[c] = arr[i];   
            c++;
        }
    }
    display(arr2, 9);
}


void first(int arr[10], int n, int k)
{

    bool f = false;
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
            f = true;
        if(f)
        {
            arr[i] = temp;
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    display(arr, 10);
}


void Deletion()
{
    int n = 10;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = i+1;
    }
    display(arr, 10);
    cout << "Enter element to delete :";
    int k=0; 
    cin >> k;
    cout << '\n' << endl;
    cout << "Approach 1: ";
    first(arr, n, k);
    cout << "Approach 2: ";
    second(arr, k);

}

void multiplyTwoMatrices()
{
    int arr1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int arr2[3][3] = {{1,1,1}, {1,2,1}, {1,1,1}};
    int arr3[3][3];
    for(int i=0;i<3;i++)
    {   
        for(int j=0;j<3;j++)
        {
            int sum = 0;
            for(int k=0;k<3;k++)
            {
                sum = sum + (arr1[i][k]*arr2[k][i]);
            }
            arr3[i][j] = sum;
        }
    }

}

void multiplyTwoMatrices2()
{
    int r1,c1,r2,c2;
    cout << "Enter size of first matrix\nRows :";
    cin >> r1;
    cout << "Columns :";
    cin >> c1;
    cout <<"\nEnter Elements" << endl;

    int arr1[r1][c1];
    for(int i=0;i<3;i++)
    {   
        for(int j=0;j<3;j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "\nEnter size of second matrix\nRows :";
    cin >> r2;
    cout << "Columns :";
    cin >> c2;
    cout <<"\nEnter Elements" << endl;

    if(c1!=r2)
    {   
        cout << "Cannot multiply matrices" << endl;
        exit(0);
    }

    int arr2[r1][c1];
    for(int i=0;i<3;i++)
    {   
        for(int j=0;j<3;j++)
        {
            cin >> arr2[i][j];
        }
    }
    
    int r3 = r1;
    int c3 = c1;
    int arr3[r3][c3];
    for(int i=0;i<r3;i++)
    {   
        for(int j=0;j<c3;j++)
        {
            int sum = 0;
            for(int k=0;k<c3;k++)
            {
                sum = sum + (arr1[i][k]*arr2[k][i]);
            }
            arr3[i][j] = sum;
        }
    }
    cout << "1st matrix\n" << endl;
    display2(r1, c1, arr1);
    cout << "2nd matrix\n" << endl;
    display2(r2, c2, arr2);
    cout << "final matrix\n" << endl;
    display2(r3, c3, arr3);
}

int main()
{
    //Deletion();
    multiplyTwoMatrices2();
    return 0;
}
