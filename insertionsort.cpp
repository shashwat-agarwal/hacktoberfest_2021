#include<iostream>
using namespace std;

void insertionSort(int a[], int n){

	for(int i=1; i<n; i++){
		// Somewhat inefficient coz we use more function overheads, hence more stack space
		// for(int j=i; j>0; j--){
		// 	if(a[j]<a[j-1]){
		// 		swap(a[j], a[j-1]);
		// 	}else{
		// 		break;
		// 	}
		// }

		int current = a[i];
		int j = i-1;
		while(j>=0 && a[j]>current){
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = current;

	}


}



int main(){
	int a[] = {5, 4, 3, 2, 1, 0};
	int n = 6;
	insertionSort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
