# CPU-Scheduling-Algorithms
C++ implementation (with OOPS concept) of various CPU Scheduling Algorithms 
1. First-Come, First-Served (FCFS):

Description: In FCFS, the processes are executed in the order they arrive in the ready queue. The first process that arrives is the first to be executed.
Advantages: Simple and easy to implement.
Disadvantages: Can lead to the "convoy effect," where shorter processes get stuck waiting behind longer ones, causing inefficiency.

Implementation : \
![image](https://github.com/user-attachments/assets/937469c7-418e-48f5-845b-185101afdc9a)


2. Round Robin (RR):

Description: In Round Robin, each process is assigned a fixed time slice or quantum. The CPU cycles through the processes, executing each for the time quantum, then moves to the next process in the queue.
Advantages: Fairly distributes CPU time among all processes, reducing the chance of starvation.
Disadvantages: Performance heavily depends on the length of the time quantum. If it's too short, the overhead of context switching can be high; if too long, it behaves more like FCFS.

Implmentation : \
![image](https://github.com/user-attachments/assets/5071d174-a5c3-4d04-aa2f-92f9c47716ba)


3. Priority Scheduling (Non-preemptive):

Description: In Priority Scheduling, each process is assigned a priority, and the CPU is allocated to the process with the highest priority. In the non-preemptive version, the CPU will not be taken away from a running process even if a higher-priority process arrives.
Advantages: Important tasks get executed first.
Disadvantages: Can lead to starvation, where low-priority processes may never get executed if higher-priority processes keep arriving.

Implementation : \
![image](https://github.com/user-attachments/assets/9b414b56-f394-4617-bc8b-259185f682cc)


4. Shortest Job First (SJF):

Description: In SJF, the process with the shortest burst time (execution time) is selected next. This minimizes the average waiting time in the queue.
Advantages: Efficient in terms of reducing average waiting time.
Disadvantages: Difficult to implement since it requires precise knowledge of the burst time of processes. Also, can lead to starvation of longer processes.

Implementation : \
![image](https://github.com/user-attachments/assets/d55041ec-e057-4f51-ac61-1db289ad873b)

