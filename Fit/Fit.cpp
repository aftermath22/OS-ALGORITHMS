#include <bits/stdc++.h>
#define ll long long int
#define li long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define Y cout << "YES\n"
#define N cout << "NO\n"
using namespace std;
int n,units;
void display(int a,int b,int c,int d,int e){
	cout<<a<<"\t\t\t\t"<<b<<"\t\t\t"<<c<<"\t\t\t\t"<<d<<"\t\t\t\t"<<e<<endl;
}
//show units_number->unit_size->required_number->required_size->units_remaining
void first_fit(vector<int> req,vector<int> mems,int start){
	vector<int> mem=mems;
	for(int i=0;i<n;i++){
		bool vis=0;
		for(int j=start;j<units;j++){
			if(mem[j]>=req[i]){
				mem[j]-=req[i];
				display(j+1,mems[j],i+1,req[i],mem[j]);
				vis=1; break;
			}
		}
		if(!vis){
			for(int j=start-1;j>=0;j--){
				if(mem[j]>=req[i]){
					mem[j]-=req[i];
					display(j+1,mems[j],i+1,req[i],mem[j]);
					vis=1; break;
				}
			}
		}
		if(!vis){
			//no block can allocate this process
			display(-1,-1,i+1,req[i],-1);
		}
	}
}


void next_fit(vector<int> req,vector<int> mems,int nxt){
	vector<int> mem=mems;
	for(int i=0;i<n;i++){
		bool vis=0;
		for(int j=nxt;j<units;j++){
			if(mem[j]>=req[i]){
				mem[j]-=req[i];
				display(j+1,mems[j],i+1,req[i],mem[j]);
				vis=1; nxt=(j+1)%n;
				break;
			}
		}
		if(!vis){
			for(int j=nxt-1;j>=0;j--){
				if(mem[j]>=req[i]){
					mem[j]-=req[i];
					display(j+1,mems[j],i+1,req[i],mem[j]);
					vis=1; nxt=(j+1)%n;
					break;
				}
			}
		}
		if(!vis){
			//no block can allocate this process
			display(-1,-1,i+1,req[i],-1);
		}
	}
}


void best_fit(vector<int> req,vector<int> mems){
	vector<int> mem=mems;
	for(int i=0;i<n;i++){
		pair<int,int> mini={-1,-1};
		for(int j=0;j<units;j++){
			if(mem[j]>=req[i]){
				if(mini.first==-1 && mini.second==-1){
					mini={mem[j],j};
				}else{
					if(mini.first>mem[j]){
						mini={mem[j],j};
					}
				}
			}
		}
		if(mini.first==-1 && mini.second==-1){
			//no block can allocate this process
			display(-1,-1,i+1,req[i],-1);
		}
		else{
			mem[mini.second]-=req[i];
			display(mini.second+1,mems[mini.second],i+1,req[i],mem[mini.second]);
		}
	}
}


void worst_fit(vector<int> req,vector<int> mems){
	vector<int> mem=mems;
	for(int i=0;i<n;i++){
		pair<int,int> maxi={-1,-1};
		for(int j=0;j<units;j++){
			if(mem[j]>=req[i]){
				if(maxi.first==-1 && maxi.second==-1){
					maxi={mem[j],j};
				}else{
					if(maxi.first<mem[j]){
						maxi={mem[j],j};
					}
				}
			}
		}
		if(maxi.first==-1 && maxi.second==-1){
			//no block can allocate this process
			display(-1,-1,i+1,req[i],-1);
		}
		else{
			mem[maxi.second]-=req[i];
			display(maxi.second+1,mems[maxi.second],i+1,req[i],mem[maxi.second]);
		}
	}
}


void solve(){
	cin>>n>>units;
	//enter requirements
	vector<int> req(n);
	for(auto &x:req) cin>>x;
	//enter memory units
	vector<int> mem_blocks(units);
	for(auto &x:mem_blocks) cin>>x;
	cout<<"Block Number\tBlock Size\tProcess Number\tProcess Size\tBlock Size Left\n";
	int nxt=0;
	first_fit(req,mem_blocks,0); cout<<endl<<endl;
	next_fit(req,mem_blocks,nxt); cout<<endl<<endl;
	worst_fit(req,mem_blocks); cout<<endl<<endl;
	best_fit(req,mem_blocks); cout<<endl<<endl;
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