// C++ program 
#include <bits/stdc++.h>
using namespace std;

//  Trapping Water Function
long long trappingWater(int arr[], int n)
{
    long long ans = 0;
    int right [n] , left [n];
    right[0] = arr[0];
        for(int i=1; i<n; i++)
    {
        if(arr[i] > right[i-1])
          right[i] = arr[i];
        else
          right[i] = right[i-1];
    }
    
    left[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] > left[i+1])
          left[i] = arr[i];
        else
          left[i] = left[i+1];
    }
    
    for(int i=0; i<n; i++)
    {
        ans = ans + min(right[i] , left[i]) - arr[i];
    }
    
    return ans;
}

// Driver code
int main()
{
  int n;
  cout<<"Enter the size of Array : "<<endl;
  cin>>n;

  int arr[n];
  cout<<"Enter the elements of Array (Heights of blocks ) : "<<endl;
  for(int i = 0; i < n; i++)
    cin>>arr[i];

  long long ans = trappingWater(arr , n);

  cout<<"Total Trapped water = "<<ans;

  return 0;
}
