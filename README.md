# OS - ALGORITHMS
## CPU-Scheduling-Algorithms
1. First-Come, First-Served (FCFS):

**Description**: In FCFS, the processes are executed in the order they arrive in the ready queue. The first process that arrives is the first to be executed. \
**Advantages**: Simple and easy to implement. \
**Disadvantages**: Can lead to the "convoy effect," where shorter processes get stuck waiting behind longer ones, causing inefficiency. 

Implementation : \
![WhatsApp Image 2024-08-28 at 23 45 51_b105b1ec](https://github.com/user-attachments/assets/34b94b88-10ba-422c-84b1-57822709db6a)




2. Round Robin (RR):

**Description**: In Round Robin, each process is assigned a fixed time slice or quantum. The CPU cycles through the processes, executing each for the time quantum, then moves to the next process in the queue. \
**Advantages**: Fairly distributes CPU time among all processes, reducing the chance of starvation. \
**Disadvantages**: Performance heavily depends on the length of the time quantum. If it's too short, the overhead of context switching can be high; if too long, it behaves more like FCFS. 

Implmentation : \
![WhatsApp Image 2024-08-28 at 23 45 51_e503d1cd](https://github.com/user-attachments/assets/3c95963a-1625-4079-9aff-229555880b07)


3. Priority Scheduling (Non-preemptive):

**Description**: In Priority Scheduling, each process is assigned a priority, and the CPU is allocated to the process with the highest priority. In the non-preemptive version, the CPU will not be taken away from a running process even if a higher-priority process arrives. \
**Advantages**: Important tasks get executed first. \
**Disadvantages**: Can lead to starvation, where low-priority processes may never get executed if higher-priority processes keep arriving. 

Implementation : \
![WhatsApp Image 2024-08-28 at 23 45 51_4cba662c](https://github.com/user-attachments/assets/5f9427fb-053c-4ca2-aac1-53098a42bab7)



4. Shortest Job First (SJF):

**Description**: In SJF, the process with the shortest burst time (execution time) is selected next. This minimizes the average waiting time in the queue. \
**Advantages**: Efficient in terms of reducing average waiting time. \
**Disadvantages**: Difficult to implement since it requires precise knowledge of the burst time of processes. Also, can lead to starvation of longer processes. 

Implementation : \
![WhatsApp Image 2024-08-28 at 23 45 51_b0a4edf1](https://github.com/user-attachments/assets/772910c4-1c8f-49f2-8739-58b8fa8a3781)

## Page Replacement Algorithms
Page replacement algorithms are used in operating systems to decide which memory pages to replace when a new page is required in the page frame. 

1. FIFO (First-In, First-Out)
Replaces the oldest page in the memory.

Advantages:

Simple and easy to implement.
Requires minimal tracking.
Disadvantages:

May lead to poor performance (Belady's Anomaly).
Ignores usage patterns of pages. \
Implementation: \
![image](https://github.com/user-attachments/assets/4b2b663b-b479-4b45-8b83-ec01a274be7f)


2. LRU (Least Recently Used)
Replaces the page that has not been used for the longest time.

Advantages:

Approximates optimal performance in many scenarios.
Adapts well to practical workloads.
Disadvantages:

Implementation overhead due to tracking usage history.
Performance may degrade with frequent context switches. \
Implementation: \
![image](https://github.com/user-attachments/assets/93ab57bd-1ff4-417d-91ed-c05d40d2ccf1)


3. MRU (Most Recently Used)
Replaces the page that was most recently used.

Advantages:

Useful in specific workloads where recently used data becomes irrelevant.
Simpler to implement than LRU.
Disadvantages:

Poor performance for general workloads.
Rarely matches real-world access patterns. \
Implementation: \
![image](https://github.com/user-attachments/assets/dc5b2349-33a7-4ddd-9151-ad7925eac30f)


4. OPTIMAL (Optimal Page Replacement)
Replaces the page that will not be used for the longest time in the future.

Advantages:

Provides the best theoretical performance.
Serves as a benchmark for other algorithms.
Disadvantages:

Requires future knowledge, which is impractical.
Used primarily for analysis and comparison. \
Implementation: \
![image](https://github.com/user-attachments/assets/8cfac73e-8cb3-4f27-bb57-3b615394d89b)


## Fit Algorithms
Fit algorithms determine how memory blocks are allocated to processes based on their size requirements.

1. First Fit
Allocates the first available block that is large enough.

Advantages:

Simple and fast.
Reduces search time for allocation.
Disadvantages:

Causes external fragmentation.
Does not consider optimal utilization of space. \

2. Next Fit
Starts searching from the last allocated block and wraps around.

Advantages:

Similar speed to First Fit with improved locality.
Prevents clustering near the start of memory.
Disadvantages:

Suffers from fragmentation issues like First Fit. \

3. Best Fit
Allocates the smallest block that is large enough.

Advantages:

Reduces leftover space, minimizing fragmentation.
Optimizes memory usage.
Disadvantages:

Slower due to the need for scanning the entire list.
May create small unusable gaps. \

4. Worst Fit
Allocates the largest available block.

Advantages:

Avoids small leftover gaps.
Provides large contiguous space for future allocations.
Disadvantages:

Wastes memory by allocating unnecessarily large blocks.
May lead to more fragmentation. \
\
Fit Algorithm Implementation ( -1 indicates that the particular process has not been allocated any memory ) : \
\
![image](https://github.com/user-attachments/assets/1d32fd27-1915-4ee4-bc7a-442b1d6b4f5b)





