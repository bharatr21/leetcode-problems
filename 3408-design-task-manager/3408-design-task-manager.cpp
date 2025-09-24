class TaskManager {
public:
    unordered_map<int, pair<int, int>> tmap;
    set<pair<int, int>, greater<pair<int, int>>> tpq;
    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int> v: tasks) {
            int userId = v[0], taskId = v[1], priority = v[2];
            tmap[taskId] = {priority, userId};
            tpq.insert({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tmap[taskId] = {priority, userId};
        tpq.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [priority, userId] = tmap[taskId];
        tmap[taskId] = {newPriority, userId};
        tpq.erase({priority, taskId});
        tpq.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        auto [priority, userId] = tmap[taskId];
        tpq.erase({priority, taskId});
        tmap.erase(taskId);
    }
    
    int execTop() {
        auto [priority, taskId] = *tpq.begin();
        tpq.erase(tpq.begin());
        auto [pr, userId] = tmap[taskId];
        tmap.erase(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */