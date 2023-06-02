#include<bits/stdc++.h>

using namespace std;

class Tv {
  static int _watchVideoCnts;
  static int _watchDvdCnts;
  int _volume, _model, _videoId, _tvId;
  public:
  Tv():_volume(50),_model(1),_videoId(1), _tvId(0){}
  void say () {
    printf("第%d号电视机--%s模式--频道%d--音量%d\n",_tvId, getModel().c_str(), _videoId, _volume);
  }
  string getModel () {
    if(_model == 1) return "TV";
    return "DVD";
  }
  void setId (int x) {
    _tvId = x ;
  }
  int getModelId () {
    return _model;
  }
  friend void go (Tv& target, int model, int videoId,int changeVolume);
};
int Tv::_watchDvdCnts = 0;

void go (Tv& target, int model, int videoId,int changeVolume){
  // if (model == 2) {
  //   target._videoId = 99;
  //   target._model = 2;
  // } else {
  //   target._model = 1 ;
  //   target._videoId = videoId;
  // }
  target._model = model;
  target._videoId = (model==2) ? 99:videoId;
  target._volume += changeVolume;
  target._volume = target._volume > 100 ? 100: target._volume;
  target._volume = target._volume < 0 ? 0 : target._volume;
  target.say();
}

int main(){
  int n,T; scanf("%d%d",&n,&T);
  Tv* ttvv = new Tv[n]();
  for (int i = 1;i <=n ; i++) {
    ttvv[i-1].setId(i);
  }
  while(T--){
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    go (ttvv[a-1], b, c, d);
  }
  int cnt = 0 ;
  for(int i=0;i<n;i++){
    if(ttvv[i].getModelId() == 1 ) cnt++;
  }
  printf("播放电视的电视机数量为%d\n播放DVD的电视机数量为%d",cnt, n-cnt);
}