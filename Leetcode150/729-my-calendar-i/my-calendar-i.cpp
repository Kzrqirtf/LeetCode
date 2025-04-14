class MyCalendar {
private:
    vector<pair<int,int>> bookings; //start time , end time
public:

    MyCalendar()
    {

        
    }
    
    bool book(int start, int end)
    {
        for(auto &event : bookings){
            int s = event.first;
            int e = event.second;
            if(!(end <= s|| start >=e)){
                return false;
            }
        }
        bookings.emplace_back(start,end);
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */