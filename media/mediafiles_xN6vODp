#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

#define ll long long
ll INF = 1000000000000;
vector<vector<pair<ll,ll>>> adj;
ll x,m;

void dijkstra(int s, vector<ll> & d, vector<ll> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        //cout<<d_v<<" "<<d[v]<<" "<<v<<endl;
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                //cout<<d[to]<<endl;
                q.push({d[to], to});
            }
        }
    }
}

int main(){
		
	    cin>>x>>m;
	ll a,b,c;
	adj.resize(x+10);
	
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b>>c;

		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));

	}
	vector<ll>d;
	vector<ll>p;
	dijkstra(1,d,p);
	if(d[x]==INF) cout<<-1;
	else{
		vector<ll>path;
		for(ll i=x;i!=-1;i=p[i]) path.pb(i);
		reverse(path.begin(),path.end());
		for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
	}
	
}