// FCFS

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
        return first.at > second.at;
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
    bool ye = 1;
    if (p[0]["at"] > 0)
    {
        cout << "CPU IDLE FOR : " << p[0]["at"] << " ms !" << endl;
        curr = p[0]["at"];
    }
    curr += p[0]["bt"];
    p[0]["ct"] = curr;
    p[0]["tat"] = p[0]["bt"];
    p[0]["wt"] = 0;
    p[0].display();
    tat_avg = p[0]["tat"];
    wt_avg = p[0]["wt"];

    for (int i = 1; i < (int)p.size(); i++)
    {
        if (curr < p[i]["at"])
        {
            cout << "\n\nCPU IDLE FOR : " << p[i]["at"] - curr << " ms !" << endl
                 << endl;
            curr = p[i]["at"];
        }
        curr += p[i]["bt"];
        p[i]["ct"] = curr;
        p[i]["tat"] = p[i]["ct"] - p[i]["at"];
        p[i]["wt"] = p[i]["tat"] - p[i]["bt"];
        tat_avg += p[i]["tat"];
        wt_avg += p[i]["wt"];
        p[i].display();
    }

    tat_avg /= n;
    wt_avg /= n;
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