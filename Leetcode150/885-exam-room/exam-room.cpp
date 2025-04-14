class ExamRoom {
public:
    int n; // total number of seats
    set<int> occupied; // set to store occupied seat indices (sorted)

    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (occupied.empty()) {
            occupied.insert(0);
            return 0;
        }

        int prev = -1;
        int maxDist = 0;
        int seatIndex = 0;

        for (int s : occupied) {
            if (prev == -1) {
                // check the distance from seat 0 to the first occupied seat
                if (s != 0 && s > maxDist) {
                    maxDist = s;
                    seatIndex = 0;
                }
            } else {
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    seatIndex = prev + dist;
                }
            }
            prev = s;
        }

        // Check the distance from the last occupied seat to the last seat (n - 1)
        if (prev != n - 1) {
            int dist = n - 1 - prev;
            if (dist > maxDist) {
                seatIndex = n - 1;
            }
        }

        occupied.insert(seatIndex);
        return seatIndex;
    }

    void leave(int p) {
        occupied.erase(p);
    }
};
