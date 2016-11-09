#include <iostream>
using namespace std;

void radix(int[],int,int);
int getMax(int[],int);

int main(){
	int A[] = {23,847,96,3,128,41,463,237,612,25};
	int n=10,i;
	
	cout << "Array before sorting : ";
	for(i=0;i<n;i++)	cout << A[i] << " ";
	cout << endl;
	
	int max = getMax(A,n);

	for(int exp=1;(max/exp)>0;exp*=10)
		radix(A,n,exp);
	
	cout << "Array after sorting  : ";
	for(i=0;i<n;i++)	cout << A[i] << " ";
	cout << endl;
}

void radix(int A[],int n,int exp){
		
	int B[n],pos1[n] = {0},pos2[n] = {0},i;
	
	for(i=0;i<n;i++) pos1[(A[i]/exp)%10]++;
	
	pos2[0] = pos1[0];
	
	for(i=1;i<n;i++) pos2[i] = pos2[i-1] + pos1[i];
		
	for(i=n-1;i>=0;i--) B[--pos2[(A[i]/exp)%10]] = A[i];
	
	for(i=0;i<n;i++) A[i] = B[i];
}

int getMax(int A[],int n){
	int max = A[0];
	
	for(int i=1;i<n;i++){
		if(A[i]>max)
			max = A[i];
	}
	return max;
}
