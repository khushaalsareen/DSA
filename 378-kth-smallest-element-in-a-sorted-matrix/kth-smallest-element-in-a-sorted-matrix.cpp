class Solution {
public:
    int count(vector<vector<int>> &matrix,int x){
	int total=0;
	int n=matrix.size();
	for(int i=0;i<n;i++){
		int l=0;
		int h=n-1;
		int m;
		if(x>= matrix[i][0] && x>=matrix[i][n-1]){
			total+=n;
		    continue;
		}
		else if(x<matrix[i][0])
			continue;
		else{
		while(l<=h){
			m=l+(h-l)/2;
			if(matrix[i][m]<=x) l=m+1;
			else{
				if( m-1>=0 && matrix[i][m-1]<=x) {
					total+=m;
					break;
				}
				else{
			     h=m-1;
				}
			}
		}
		}
	}
	return total;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l= matrix[0][0];
	int h= matrix[n-1][n-1];
	int mid;
	while(l<=h){
		mid=l+(h-l)/2;
		if(count(matrix,mid)<k)
			l=mid+1;
		else{
			if(count(matrix,mid-1)<k){
				return mid;
				break;
			}
			else{
				h=mid-1;
			}
		}
	}
    return -1;
    }
};