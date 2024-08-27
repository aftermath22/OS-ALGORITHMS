// SJF

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
    bool operator<(const Process &second) const
    {
        auto first = *this;
        return first.bt > second.bt;
    }
};

bool comparator(Process first, Process second)
{
    if (first["at"] == second["at"])
    {
        if (first["bt"] == second["bt"])
        {
            return first["id"] < second["id"];
        }
        return first["bt"] < second["bt"];
    }
    return first["at"] < second["at"];
}

bool allvis(vector<bool> &vis)
{
    bool ye = 1;
    for (auto x : vis)
    {
        if (!x)
            return 0;
    }
    return 1;
}

void code()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int cntr = 1;
    vector<Process> p(n);
    for (Process &temp : p)
    {
        temp["id"] = cntr++;
        cout << "Enter Arrival And Burst Time for Process with id (" << cntr - 1 << ") : ";
        cin >> temp["at"] >> temp["bt"];
    }
    sort(all(p), comparator);
    printf("pid\tat\tbt\tct\ttat\twt\n");
    priority_queue<Process> pq;
    int curr = 0;

    if (p[0]["at"] > 0)
    {
        cout << "CPU IDLE FOR : " << p[0]["at"] << " ms !" << endl;
        curr = p[0]["at"];
    }

    vector<bool> vis(n, 0);
    double tat_avg = 0;
    double wt_avg = 0;
    bool idle = 1;
    vector<pair<int, pair<int, int>>> idleness;
    while (!allvis(vis))
    {
        idle = 1;
        for (int i = 0; i < n; i++)
        {
            if (p[i]["at"] <= curr && !vis[i])
            {
                pq.push(p[i]);
                vis[i] = 1;
                idle = 0;
            }
        }
        if (idle)
        {
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    pq.push(p[i]);
                    idleness.pb({(p[i]["at"] - curr), {p[i - 1]["id"], p[i]["id"]}});
                    curr = p[i]["at"];
                    vis[i] = 1;
                    break;
                }
            }
        }
        while (!pq.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (p[i]["at"] <= curr && !vis[i])
                {
                    pq.push(p[i]);
                    vis[i] = 1;
                }
            }
            Process temp = pq.top();
            pq.pop();
            curr += temp["bt"];
            temp["ct"] = curr;
            temp["tat"] = temp["ct"] - temp["at"];
            temp["wt"] = temp["tat"] - temp["bt"];
            tat_avg += temp["tat"];
            wt_avg += temp["wt"];
            temp.display();
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
    printf("\nAverage waiting time : %f\n", tat_avg);
    printf("\nAverage turn around time : %f\n", wt_avg);
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