#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Job structure to store job details
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit if the job is completed
};

// Comparator function to sort jobs in descending order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit using job scheduling
void jobScheduling(vector<Job>& jobs, int n) {
    // Step 1: Sort all jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find the maximum deadline
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 3: Create a time slots array to keep track of scheduled jobs
    vector<int> timeSlots(maxDeadline + 1, -1); // -1 indicates the slot is free
    int maxProfit = 0; // Total profit
    int jobCount = 0;  // Number of jobs completed

    // Step 4: Schedule jobs
    for (const auto& job : jobs) {
        // Check slots from job.deadline down to 1
        for (int t = job.deadline; t > 0; t--) {
            if (timeSlots[t] == -1) {
                // Slot is free; assign this job
                timeSlots[t] = job.id;
                maxProfit += job.profit;
                jobCount++;
                break;
            }
        }
    }

    // Step 5: Output results
    cout << "Scheduled jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (timeSlots[i] != -1) {
            cout << "Job" << timeSlots[i] << " ";
        }
    }
    cout << "\nTotal profit: " << maxProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details (ID, Deadline, Profit):\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobScheduling(jobs, n);

    return 0;
}
