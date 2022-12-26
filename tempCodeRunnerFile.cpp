
    vector<int>temp;
    int n = nums.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(nums[j]);
            subsets.push_back(temp);
        }
        temp.clear();   
    }
    return subsets;
}


void printSubsets(vector<vector<int>>&subsets){
    for(auto x : subsets){
        cout<<"[";
        for(auto y : x)
            cout<<y<<",";
        cout<<"],";
    }
    cout<<"\n\n";
}


int main() {
    fastio();

    vector<int>nums{1,2,49,31,8};

    auto temp = makeSubsets(nums);
    printSubsets(temp);

    return 0;
}