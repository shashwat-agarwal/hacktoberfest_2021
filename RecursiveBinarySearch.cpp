#include<iostream>
using namespace std;

int binsearch(int a[], int l, int h, int key){

// search only if l<h, otherwise element is not present
	if(h>=l){
		int mid = l + (h-l)/2;
		if(a[mid]==key) return mid;
		if(a[mid]<key) return binsearch(a, mid+1, h, key);
		if(a[mid]>key) return binsearch(a, l, mid-1, key);
	}

	return -1;
	
	
}


int main(){

	int a[] = {5, 6, 7, 8, 9, 10};
	int n = sizeof(a)/sizeof(a[0]);
	int k = 5;
	int pos = binsearch(a, 0, n-1, k);
	if(pos != -1) cout<<k<<" Found at "<<pos;
	else cout<<k<<" not found";

	return 0;
}
