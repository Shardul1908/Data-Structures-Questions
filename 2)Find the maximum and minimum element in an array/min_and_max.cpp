#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int testcases;
	cin >> testcases;

	while(testcases--) {
		int n;
		cout << "Enter the size of the array:\n";
		cin >> n;
		vector<int> arr(n);
		cout << "Enter the Array:\n";
		for(int i = 0;i<n;i++) {
			cin >> arr[i];
		}	
		
		int mini = INT_MAX;
		int maxi = INT_MIN;
	
		for(int i = 0;i<n;i++) {
			if(mini > arr[i]) {
				mini = arr[i];
			}			

			if(maxi < arr[i]) {
				maxi = arr[i];
			}
		}		

		cout << "Minimum element = " << mini << endl;
		cout << "Maximum element = " << maxi << endl;
	}
	return 0;	
}
