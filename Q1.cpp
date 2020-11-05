#include <iostream>

using namespace std;
void knapSack(int N,float* price,float* volume,int M);

int main(){
	
	int N,M;
	cout<<"\n                               ................Wine Yard................ \n\n";
	cout<<" Enter the number of bottles : ";
	cin>>N;
	cout<<" Enter the number of barrels : ";
	cin>>M;
	
	float volume[M];
	float price[M];
	cout<<"\n";
	for(int i=0;i<M;i++){
		cout<<" Enter volume and price for barrels : ";
		cin>>volume[i];
		cin>>price[i];
	}
	knapSack(N,price,volume,M);
	return 0;
}

void knapSack(int N,float* price,float* volume,int M){
	int i,j,temp1,temp2;
	float x[M],result=0,wt;
	for(i=0;i<M;i++){
		for(j=i+1;j<M;j++){
			if((price[i]/volume[i])<(price[j]/volume[j])){    //sort the volume[] array and price[] array
				temp1=price[i];
				price[i]=price[j];
				price[j]=temp1;
				temp2=volume[i];
				volume[i]=volume[j];
				volume[j]=temp2;
			}
		}
	}
	for(i=0;i<M;i++){
		x[i]=0;
	}
	i=0;
	wt=0;
	while(wt<N){
		if(wt+volume[i]<=N){    //volume[i] is the greedy choice
			x[i]=1;    //decision variables
			wt=wt+volume[i];
		}
		else{
		    x[i]=((N-wt)/volume[i]);
			wt=N;
		}
	i=i+1;
	}
	
	for(int l=0;l<M;l++){
		result=result+(x[l]*price[l]);
	}
	cout<<" \n Maximum value of wines : "<<result;
}
