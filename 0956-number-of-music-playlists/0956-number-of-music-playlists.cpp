typedef long long ll;
const int M=1e9+7;
class Solution {
public:
ll t[101][101];
ll f(int song_cnt,int unique_cnt,int n,int goal,int k){
    if(song_cnt==goal){
        return unique_cnt==n;
    }
    if(t[song_cnt][unique_cnt]!=-1) return t[song_cnt][unique_cnt];
    ll res=0;
    if(unique_cnt<n) res+=(n-unique_cnt)*f(song_cnt+1,unique_cnt+1,n,goal,k);
    if(unique_cnt>k) res+=(unique_cnt-k)*f(song_cnt+1,unique_cnt,n,goal,k);
    return t[song_cnt][unique_cnt]=res%M;
}
    int numMusicPlaylists(int n, int goal, int k) {
        memset(t,-1,sizeof(t));
        return f(0,0,n,goal,k);
    }
};