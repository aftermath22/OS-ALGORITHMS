// Round Robin

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
int err = -1;
class Process
{
private:
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int pid;

public:
    int &operator[](string var)
    {
        if (var == "at")
            return at;
        if (var == "bt")
            return bt;
        if (var == "ct")
            return ct;
        if (var == "tat")
            return tat;
        if (var == "id")
            return pid;
        if (var == "wt")
            return wt;
        return err;
    }
    void update_after_ct()
    {
        tat = ct - at;
        wt = tat - bt;
    }
    void display()
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid, at, bt, ct, tat, wt);
    }
};

bool comparator(Process first, Process second)
{
    if (first["at"] == second["at"])
    {
        return first["id"] < second["id"];
    }
    return first["at"] < second["at"];
}

bool alldone(vector<int> &bursts)
{
    for (auto x : bursts)
    {
        if (x)
            return 0;
    }
    return 1;
}

bool allvis(vector<bool> &vis)
{
    for (auto x : vis)
    {
        if (!x)
            return 0;
    }
    return 1;
}

bool can_insert(queue<Process> q, Process t)
{
    while (!q.empty())
    {
        auto y = q.front();
        q.pop();
        if (t["id"] == y["id"])
            return 0;
    }
    return 1;
}

void printq(queue<Process> q)
{
    auto x = q;
    cout << "queue stat...\n";
    while (!q.empty())
    {
        auto y = q.front();
        q.pop();
        cout << y["id"] << " ";
    }
    cout << endl;
}
void code()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int tq;
    cout << "Enter time quanta: ";
    cin >> tq;
    int cntr = 1;
    vector<int> bursts;
    vector<Process> p(n);
    for (Process &temp : p)
    {
        temp["id"] = cntr++;
        cout << "Enter Arrival And Burst Time for Process with id (" << cntr - 1 << ") : ";
        cin >> temp["at"] >> temp["bt"];
        bursts.pb(temp["bt"]);
    }
    sort(all(p), comparator);

    // cout << "\n\n*CHECK*\n\n";
    // for (auto x : p)
    // {
    //     x.display();
    // }
    // cout << "\n\n*CHECK*\n\n";

    printf("pid\tat\tbt\tct\ttat\twt\n");
    int curr = 0;
    vector<bool> vis(n, 0);
    double tat_avg = 0;
    double wt_avg = 0;
    bool idle = 1;
    vector<bool> completed(n, 0);
    vector<pair<int, pair<int, int>>> idleness;
    if (p[0]["at"] > 0)
    {
        cout << "CPU IDLE FOR : " << p[0]["at"] << " ms !" << endl;
        curr = p[0]["at"];
        vis[0] = 1;
    }
    curr += min(p[0]["bt"], tq);
    vis[0] = 1;
    bursts[p[0]["id"] - 1] -= curr;
    queue<Process> ready_q;
    if (bursts[p[0]["id"] - 1] == 0)
    {
        p[0]["ct"] = curr;
        p[0]["tat"] = p[0]["ct"] - p[0]["at"];
        p[0]["wt"] = 0;
        vis[0] = 1;
        tat_avg = p[0]["tat"];
        p[0].display();
    }
    while (!alldone(bursts))
    {
        idle = 1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && p[i]["at"] <= curr && bursts[p[i]["id"] - 1] != 0)
            {
                if (can_insert(ready_q, p[i]))
                    ready_q.push(p[i]);
                vis[i] = 1;
                idle = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] && p[i]["at"] <= curr && bursts[p[i]["id"] - 1] != 0)
            {
                idle = 0;
                if (can_insert(ready_q, p[i]))
                    ready_q.push(p[i]);
            }
        }
        if (idle)
        {
            for (int i = 0; i < n; i++)
            {
                if (bursts[p[i]["id"] - 1] != 0 && !vis[i])
                {
                    ready_q.push(p[i]);
                    idleness.pb({(p[i]["at"] - curr), {p[i - 1]["id"], p[i]["id"]}});
                }
            }
        }
        // printq(ready_q);
        if (!ready_q.empty())
        {
            auto x = ready_q.front();
            ready_q.pop();
            int t = curr;
            curr += min(tq, bursts[x["id"] - 1]);
            t = curr - t;
            bursts[x["id"] - 1] -= t;
            if (bursts[x["id"] - 1] == 0 && !completed[x["id"] - 1])
            {
                completed[x["id"] - 1] = 1;
                x["ct"] = curr;
                x["tat"] = curr - x["at"];
                x["wt"] = x["tat"] - x["bt"];
                tat_avg += x["tat"];
                wt_avg += x["wt"];
                x.display();
            }
        }
    }
    tat_avg /= n;
    wt_avg /= n;
    if (!idleness.empty())
    {
        cout << "\nCPU Idle Time Statistics...\n";
        for (auto x : idleness)
        {
            cout << "Idle for : " << x.first << " ms between processes with id " << x.second.first << " and " << x.second.second << endl;
        }
    }
    printf("\nAverage turn around time : %f\n", tat_avg);
    printf("\nAverage waiting time : %f\n", wt_avg);

    return;
}
int main()
{
    short int t = 1;
    while (t--)
    {
        code();
    }
    return 0;
}