class Robot {
    int w, h, pos, total;
    bool moved;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        pos = 0;
        total = 2 * (w - 1) + 2 * (h - 1);
        moved = false;
    }
    void step(int num) {
        moved = true;
        pos = (pos + num) % total;
    }
    vector<int> getPos() {
        if (pos <= w - 1) 
            return {pos, 0};
        if (pos <= (w - 1) + (h - 1)) 
            return {w - 1, pos - (w - 1)};
        if (pos <= 2 * (w - 1) + (h - 1)) 
            return {w - 1 - (pos - (w - 1) - (h - 1)), h - 1};
        return {0, h - 1 - (pos - 2 * (w - 1) - (h - 1))};
    }
    string getDir() {
        if (!moved) return "East";
        if (pos >= 1 && pos <= w - 1) return "East";
        if (pos > w - 1 && pos <= (w - 1) + (h - 1)) return "North";
        if (pos > (w - 1) + (h - 1) && pos <= 2 * (w - 1) + (h - 1)) return "West";
        return "South";
    }
};