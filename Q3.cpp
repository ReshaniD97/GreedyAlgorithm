#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	
	vector <int> products;
    long int product_count = 0;
	int i = 0 , k = 1, containers = 0,temp = 0;
	
    
    //input the number of product weights
	cin>>product_count;
    //adding product weights to the data structure of vector
    for(i = 0;i < product_count;i++){
    	cin>>temp;
    	products.push_back(temp);
    		
	}
    /////////////////sort vector in ascending order//////////////////
    sort(products.begin(),products.end());
    //////////////////////////////////////////////////////////
    
    // greedy strategy via get the minimum value of the vector
    // then remove the pieces in the range of 0-4
    while(products.size()>0){
    	int tmp = products[0];//get the front value before pop
    	//cout<<tmp<<" "<<endl;
    	while(tmp + 4 >= products[k] && products.size() != 1){
    		//cout<<products[k]<<" ";
    		products.erase(products.begin());
		}
		// cout<<endl;
		products.erase(products.begin());//remove the pivot
		containers++;
		k = 1;
	}
    
    cout<<containers<<endl;
    
    return 0;
}
