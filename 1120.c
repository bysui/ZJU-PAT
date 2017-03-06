#include <iostream>
#include <set>
using namespace std;

int intTosum(int x)
{
  int sum;
  
  sum=0;
  while(x){
    sum+=x%10;
    x/=10;
  }
  return sum;
}

int main()
{
  int i, n, v, size;
  set<int> fid;
  
  cin>>n;
  for(i=0;i<n;i++){
    cin>>v;
    fid.insert(intTosum(v));
  }
  size=fid.size();
  cout<<size<<endl;
  auto it=fid.begin();
  cout<<*it;
  for(it++;it!=fid.end();it++)
    cout<<" "<<*it;
  return 0;
}