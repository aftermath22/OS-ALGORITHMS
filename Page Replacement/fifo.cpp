//if you feel like your count can exceed value of 'int' you can use 'll'/'li' instead of 'int' and replace unordered_map with a simple map
#include <bits/stdc++.h>
#define ll long long int
#define li long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define Y cout << "Hit "
#define N cout << "Miss "
using namespace std;
int n,pg;
void print(unordered_map<int,int> &m){
	for(auto &x:m){
		if(x.second) cout<<x.first<<" ";
	}
	cout<<endl;
}
int get_replacement(unordered_map<int,int> &m,int i,vector<int> &req){
	
	// replacement -> first => page number
	//             -> second => time in the form of count the page number has been
	
	pair<int,int> replacement={-1,-1};
	for(auto &x:m){
		if(replacement.first==-1 || replacement.second<x.second){
			replacement.first=x.first; replacement.second=x.second;
		}
	}
	return replacement.first;
}
void update(unordered_map<int,int> &present){
	for(auto &x:present) if(x.second!=0) x.second++;
}
void solve(){
	
	// n -> # of page requests
	// pg -> frame size
	// req -> array of page requests
	// present -> how long particular page number(s) are currently present in the main memory
	// hit -> total hit(s)
	
	int hit=0;
	cin>>n>>pg;
	vector<int> req(n);
	for(auto &x:req) cin>>x;
	unordered_map<int,int> present;
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
			
			//replace the page which has been present in the main memory the longest
			
			N;
			int j=get_replacement(present,i,req);
			if(j==-1){
				cout<<"some error\n";
				exit(0);
			}
			present[req[i]]=1; 
			present[j]=0;
			print(present);
		}
		update(present);
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