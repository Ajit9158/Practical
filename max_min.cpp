#include <iostream>
#include <omp.h>
#include <climits>

using namespace std;
void Min_reduction(int arr[],int n) {

	int min_value = INT_MAX;
	#pragma omp parallel for reduction(min: min_value)
	for(int i=0;i<n;i++){
		if(arr[i]<min_value) {
			min_value = arr[i];
		}
	}
	cout<<" min value is" << min_value<<endl;

}

void Max_reduction(int arr[],int n) {

	int max_value = INT_MIN;
	#pragma omp parallel for reduction(max: max_value)
	for(int i=0;i<n;i++){
		if(arr[i]>max_value) {
			max_value = arr[i];
		}
	}
	cout<<" max value is" << max_value<<endl;

}

void sum_reduction(int arr[],int n) {

  int sum= 0;

	#pragma omp parallel for reduction(+: sum)
	for(int i=0;i<n;i++){

		sum += arr[i];
		
	}
	cout<<" sum is" << sum<<endl;

}

void avg_reduction(int arr[],int n) {

  int sum= 0;

	#pragma omp parallel for reduction(+: sum)
	for(int i=0;i<n;i++){

		sum += arr[i];
		
	}
	cout<<" avg value is" << sum/n<<endl;

}


int main() {
	
	int *arr,n;
	cout<<"\n enter total no of elements=>";
    cin>>n;
	arr = new int[n];

	cout<<"\n enter elements:- "<<endl;
	for(int i = 0;i<n;i++){

		cin>>arr[i];	
	}
	
	Min_reduction(arr,n);
 	Max_reduction(arr,n);
  	sum_reduction(arr,n);
	avg_reduction(arr,n);
	
	
	return 0 ;
	
}