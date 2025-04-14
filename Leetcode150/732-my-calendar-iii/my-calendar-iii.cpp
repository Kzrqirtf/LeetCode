class MyCalendarThree {
    private: 
    map<int,int> timeline;
    int maxBooking=0;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;
        int ongoing = 0;
        maxBooking=0;

        for(auto &[time,countChange]:timeline){
            ongoing+=countChange;
            maxBooking = max(maxBooking,ongoing);
        }
        return maxBooking;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */