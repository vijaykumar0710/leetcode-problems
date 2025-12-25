class Solution {

    enum class LogType { START, END };

    static constexpr string_view START = "start";
    static constexpr string_view END = "end";

    stack<int> stkFuncIds;
    int previousTimestamp = 0;

    inline tuple<int, LogType, int> getLogData(const string& log) {

        int p1 = log.find(':');
        int p2 = log.find(':', p1 + 1);

        int id = stoi(log.substr(0, p1));
        int time = stoi(log.substr(p2 + 1));

        LogType type = (log.compare(p1 + 1, 5, START) == 0) ? LogType::START
                                                            : LogType::END;

        return {id, type, time};
    }

    inline void handleFuncLog(LogType type, int id, int timestamp,
                          vector<int>& exclusiveFuncTime) {

        switch (type) {
        case LogType::START: {
            if (!stkFuncIds.empty()) {
                exclusiveFuncTime[stkFuncIds.top()] +=
                    (timestamp - previousTimestamp);
            }
            previousTimestamp = timestamp;
            stkFuncIds.push(id);
            break;
        }

        case LogType::END: {
            exclusiveFuncTime[stkFuncIds.top()] +=
                (timestamp - previousTimestamp + 1);
            previousTimestamp = timestamp + 1;
            stkFuncIds.pop();
            break;
        }
        }
    }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> exclusiveFuncTime(n, 0);

        for (const string& log : logs) {
            auto [id, type, timestamp] = getLogData(log);
            handleFuncLog(type, id, timestamp, exclusiveFuncTime);
        }

        return exclusiveFuncTime;
    }
};