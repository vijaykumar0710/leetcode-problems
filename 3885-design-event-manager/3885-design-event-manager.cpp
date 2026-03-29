class EventManager {
public:
unordered_map<int,int>keyVal;
set<pair<int,int>>valKey;
    EventManager(vector<vector<int>>& events) {
        for(auto e:events){
            int key=e[0],val=e[1];
            keyVal[key]=val;
            valKey.insert({-val,key});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(keyVal.count(eventId)){
           int oldVal=keyVal[eventId];
           valKey.erase({-oldVal,eventId});
        }
        keyVal[eventId]=newPriority;
        valKey.insert({-newPriority,eventId});
    }
    
    int pollHighest() {
        if(!valKey.empty()){
            int res=valKey.begin()->second;
            valKey.erase(valKey.begin());
            return res;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */