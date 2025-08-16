class Solution {
public:
    int count=0;

    void merge(vector<int>& arr, int st, int mid, int end)
    {
        vector<int>temp;
        int i=st;
        int j=mid+1;
        //int Count=0;
        
        while(i<=mid && j<=end)
        {
            if(arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
          //      invCount+=(mid-i+1);
            }
        }
        
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int idx=0;idx<temp.size();idx++)
        {
            arr[idx+st]=temp[idx];
        }
       
    }
    void countPairs(vector<int>& arr, int st, int mid, int end)
    {
        int j=mid+1;
        for(int i=st;i<=mid;i++)
        { 
            while(j<=end && arr[i]>(long long)arr[j] *2)
            {
                j++;   
            } 
            count+=j-(mid+1);
        }
       
        

    }


    void byMergeSort(vector<int>& arr, int st, int end)
    {
        if(st<end)
        {
            int mid=(st+end)/2;
            
            byMergeSort(arr,st,mid);
            byMergeSort(arr,mid+1,end);

            countPairs(arr,st,mid,end);

            merge(arr,st,mid,end);

        }
    }


    int reversePairs(vector<int>& nums) {


        int n=nums.size();
        byMergeSort(nums,0, n-1);

        return count;
    }
};