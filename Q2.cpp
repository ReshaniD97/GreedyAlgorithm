#include <bits/stdc++.h>
#include <vector>

using namespace std;

int maxval(int a,int b){
	return a > b ? a : b;
}

int main(){
	
	vector <int> marks;//student marks vector
	vector <int> masks;//mask vector min amount of masks for each student
    int n,i = 0,tmp = 0,temp = 0;
    long long total_masks = 0;
    
    
	//input the number of students
    cin >> n;
    
	while(i<n){
		cin >> temp;
		marks.push_back(temp);
		i++;
	}
	
    //student should get at least one mask
    //then it should denoted in the masks vector at initially
    masks.push_back(1);
    
    // greedy approach via left to right
	// apply masks for students                                    
    for(int i = 1; i < n; i++){         
		if(marks[i]>marks[i-1]){
			masks.push_back(masks[i-1]+1);//min value
		}else{
			masks.push_back(1);//min value
		}
    }

    total_masks = masks[n - 1];               

	// greedy approach to right to left for specify equal number of masks 
	// and having different amount of masks 
    for(int i = n - 2; i >= 0; i--){    
		if(marks[i] > marks[i+1]){
			tmp = masks[i+1] + 1;
		}else{
			tmp = 1;
		}
		
		//get the maximum of two values
		total_masks += maxval(tmp,masks[i]);
		//assign the values to seating orders
		masks[i] = tmp;
    }

    cout << total_masks;

    return 0;
}
