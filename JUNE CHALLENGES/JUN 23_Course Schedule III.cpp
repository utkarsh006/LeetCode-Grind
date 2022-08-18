/* Problem :
There are n different online courses numbered from 1 to n.
You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
You will start on the 1st day and you cannot take two or more courses simultaneously.
Return the maximum number of courses that you can take.
*/


/* Approach :
The key idea is to complete the courses with the shortest deadlines first.
If you are unable to complete a course before the deadline,
see if you can reduce the amount of time required by substituting the current course with any earlier courses with longer deadlines.



Steps :
1. Sort the courses first in ascending order of the last day or deadline. In order for shorter deadline courses to be finished before others.
    Declare a priority queue as well for storing the duration of completed courses. Declare a variable that contains the entire time spent up to this point as well.

2. Iterating through the list We can complete a course if the cumulative duration of the current and previous terms is shorter than the course's last day.
    In order to add it to the priority queue, add its duration to the total duration.

3. We cannot take the course if the first requirement is not satisfied. Therefore, we can aim to cut down on the total amount of time needed to free up more time for future courses.
    Therefore, if a course has already been completed (we can verify this by determining if the priority queue is empty or not), we determine if it is the longest course to date;
    if it is not, we replace the longest course with the current course. The top course time will be subtracted from the queue and total time, and the current course time will be added to both.
    Since the current last day is always shorter than any previous last day, this replacement will always be effective.

4. You should skip a course if it does not meet any requirements since you cannot complete it.

5. Finally, the priority queue will only include the completed courses.
*/


class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> maxD;
        int time = 0;
        for (auto course : courses)
        {
            if (time + course[0] <= course[1])
            {
                time += course[0];
                maxD.push(course[0]);
            }
            else if (!maxD.empty() && maxD.top() >= course[0])
            {
                time = time - maxD.top() + course[0];
                maxD.pop();
                maxD.push(course[0]);
            }
        }
        return maxD.size();
    }
};


/*
Time Complexity :- O(nlog),
Space Complexity :- O(n))
*/
