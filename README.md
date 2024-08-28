# CPU-Scheduling-Algorithms
C++ implementation (with OOPS concept) of various CPU Scheduling Algorithms 
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

