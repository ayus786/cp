int dp[101][101];
int chain(int ar[],int i,int j){
  if(i>=j){
    return 0;
  }
  if(dp[i][j]!=-1) return dp[i][j];
  int mn=INT_MAX;
  for(int k=i; k<j; k++){
    int temp=chain(ar,i,k)+chain(ar,k+1,j)+ar[i-1]*ar[k]*ar[j];
    mn=min(mn,temp);
  }
  return dp[i][j]=mn;
}
int matrixMultiplication(int N, int arr[])
{
  memset (dp,-1,sizeof dp);
  return chain (arr,1,N-1);
}
