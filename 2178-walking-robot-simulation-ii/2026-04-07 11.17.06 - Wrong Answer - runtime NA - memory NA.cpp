class Robot {
private:
    int w, h, P;
    int pos = 0; 

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        P = 2 * (w + h - 2);
    }

    void step(int num) {
        pos = (pos + num) % P;
    }

    vector<int> getPos() {
        int p = pos;

       
        if (p < w) {
            return {p, 0};
        }
        p -= w - 1;

       
        if (p < h) {
            return {w - 1, p};
        }
        p -= h - 1;

        
        if (p < w) {
            return {w - 1 - p, h - 1};
        }
        p -= w - 1;

        
        return {0, h - 1 - p};
    }

   string getDir() {
    if (pos == 0) return "East";

    if (pos < w - 1) return "East";
    else if (pos < w + h - 2) return "North";
    else if (pos < w + h - 2 + (w - 1)) return "West";
    else return "South";
}
};