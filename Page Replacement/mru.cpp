#include <bits/stdc++.h>
#define ll long long int
#define li long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define Y cout << "Hit "
#define N cout << "Miss "
using namespace std;
int n,pg;
void print(unordered_map<int,bool> &m){
	for(auto &x:m){
		if(x.second) cout<<x.first<<" ";
	}
	cout<<endl;
}
int get_replacement(unordered_map<int,bool> &m,int i,vector<int> &req){
	
	// ind -> index that holds the page number which is to be replaced

	int ind=-1;
	for(int j=i-1;j>=0;j--){
		if(m[req[j]]){
			ind=j;
			return ind;
		}
	}
	return ind;
}
void solve(){
	
	// n -> # of page requests
	// pg -> frame size
	// req -> array of page requests
	// present -> page number(s) currently present in the main memory
	// hit -> total hit(s)
	
	int hit=0;
	cin>>n>>pg;
	vector<int> req(n);
	for(auto &x:req) cin>>x;
	unordered_map<int,bool> present;
	for(int i=0;i<n;i++){
		if(present[req[i]]){
			hit++;
			Y; print(present);
		}
		else if((int)present.size()<=pg){
			N;
			present[req[i]]=1;
			print(present);
		}
		else{
			
			//replace the page which is closest in the past
			
			N;
			int j=get_replacement(present,i,req);
			if(j==-1){
				cout<<"some error\n";
				exit(0);
			}
			present[req[i]]=1; 
			present[req[j]]=0;
			print(present);
		}
	}
	cout<<"finished\n"; 
	cout<<"total hits : "<<hit<<endl<<"total misses : "<<(n-hit)<<endl;
	return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    li tc = 1;
    // cin >> tc;
    while (tc--)
    {	
		solve();  
    }
    return 0;
}