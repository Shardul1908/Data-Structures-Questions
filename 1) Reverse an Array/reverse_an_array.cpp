#include <iostream>
#include <vector>
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
		
		cout << "Array before reversal: ";
		for(int i = 0;i<n;i++) {
			cout << arr[i] << " "; 
		}
		cout << "\n";

		int first = 0;
		int last = n-1;

		while(first<last) {
			int temp = arr[first];
			arr[first] = arr[last];
			arr[last] = temp;

			first++;
			last--;
		}
		
		cout << "Array after reversal: ";
		for(int i = 0;i<n;i++) {
            cout << arr[i] << " ";
        }
		cout << "\n";

	}
	return 0;	
}
