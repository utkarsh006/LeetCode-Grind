/* Problem:
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
Implement the MyCalendar class:
MyCalendar(): Initializes the calendar object.
boolean book(int start, int end): Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
*/

/* Approach 1:(Brute-Force)

Check the start and end to see whether they fall within the range of any already booked dates;
if so, return false;
otherwise, return true.
Suppose ,
[s1, e1] : Range of new slot to be booked, [s2, e2] : Range of previously booked slots
A range [s1,e1] and [s2, e2] can cross in a variety of different ways.
Let's focus on the scenarios in which the ranges won't overlap rather than considering all of those other possibilities.
Only two scenarios are possible- s2 >= e1 and s1 >= e2.
*/

class MyCalendar
{
    unordered_map<int, int>bookings;
public:
    bool book(int s1, int e1)
    {
        for(auto& [s2, e2] : bookings)
            if(!(s1 >= e2 || s2 >= e1))
			    return false;
        bookings[s1] = e1;
        return true;
    }
};

/*
Time Complexity : O(N),
Space Complexity : O(N).
*/


/* Approach 2: (Maintain sorted bookings)

We may just keep track of all the reserved times in the starting order rather than iterating over them all.
Then, we only need to look at two scenarios:
Again, for reference, [s1, e1] is the range of the new slot to be reserved, and [s2, e2] is the range of the spaces that have already been reserved.

1. s2 >= e1 (Find a previously reserved space with a start time that is just above or below the start time of the new slot):
    In this scenario, we merely need to check that s2 >= e1 to make sure that these two slots don't cross.
    This indicates that the closest reserved slot will not begin until the new slot has ended.
2. e2 <= s1 (Find an already-booked time slot whose start time is just before the start of the new session):
    In this example, we merely need to check that e2 = s1 to make sure that these two slots don't cross.
    In other words, the closest booked session that begins earlier than the new slot also finishes earlier than the new slot.

Together, these two situations make sure that none of the already reserved spaces and the new slot to be added would overlap.
*/

class MyCalendar
{
    set<pair<int, int>>bookings;
public:
    bool book(int s1, int e1)
    {
        auto slot = bookings.lower_bound({s1, e1});
        if( slot != end(bookings)   && !(slot -> first >= e1) || slot != begin(bookings) && !(prev(slot) -> second <= s1))
			    return false;
        bookings.insert({s1, e1});
        return true;
    }
};

/*
Time Complexity : O(logN), {for insert and lower_bound functions}
Space Complexity : O(N).
*/
