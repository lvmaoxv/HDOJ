//Problem Description
//The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
//
//For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
// 
//
//Input
//There are multiple test cases. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100. A test case with N = 0 denotes the end of input. This test case is not to be processed.
// 
//
//Output
//Print the total time on a single line for each test case. 
// 
//
//Sample Input
//1 2
//3 2 3 1
//0
// 
//
//Sample Output
//17
//41

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N,elem,i;
	while(cin>>N && N!=0)
	{
		vector<int>a(N);
		for(i=0;i<N;i++)
		{
			cin>>elem;
			a[i] = elem;
		}
		int sum = 6*a[0]+5;
		for(int i=1;i<N;++i)
		{
			int b = a[i]-a[i-1];
			if(b>0)sum += b*6+5;
			else
				sum += abs(b)*4+5;
		}
		cout<<sum<<endl;
	}
	return 0;
}