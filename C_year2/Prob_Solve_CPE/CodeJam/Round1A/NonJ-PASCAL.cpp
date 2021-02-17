#include <bits/stdc++.h>

using namespace std;

struct Frontier {
    int layer, pos;
    uint64_t sum;
};

bool global_done;
uint64_t global_goal;

pair<int, int> global_travel_mask[] = {{-1, -1},
                                       {-1, +0},
                                       {+0, -1},
                                       {+0, +1},
                                       {+1, +0},
                                       {+1, +1}};

void dfs(Frontier front, vector<Frontier>& history, const vector<vector<uint64_t>>& pascal) {
    if (global_done) {
        return;
    }

    history.push_back(front);

    if (front.sum == global_goal) {
        for (const auto& x : history) {
            cout << x.layer + 1 << ' ' << x.pos + 1 << endl;
        }
        global_done = true;
        return;
    }

    vector<Frontier> nexts;

    for (auto travel_mask : global_travel_mask) {
        auto next = front;
        next.layer += travel_mask.first;
        next.pos += travel_mask.second;

        if (next.layer < 0 or next.layer >= 64 or next.pos < 0 or next.pos >= next.layer + 1) {
            continue;
        }
        next.sum += pascal[next.layer][next.pos];
        if (next.sum > global_goal) {
            continue;
        }

        bool found = false;
        for (const auto& x: history) {
            if (x.layer == next.layer and x.pos == next.pos) {
                found = true;
                break;
            }
        }

        if (found) {
            continue;
        }

        nexts.push_back(next);
    }

    sort(nexts.begin(), nexts.end(), [](const Frontier& l, const Frontier& r) {
        return l.sum > r.sum;
    });

    for (const auto& next: nexts) {
        dfs(next, history, pascal);
    }

    history.pop_back();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto pascal = vector<vector<uint64_t>>(64);

    pascal[0] = vector<uint64_t>(1, 1);
    for (auto layer = 1; layer < pascal.size(); layer++) {
        pascal[layer] = vector<uint64_t>(layer + 1);
        for (auto pos = 0; pos < layer; pos++) {
            pascal[layer][pos] += pascal[layer - 1][pos];
            pascal[layer][pos + 1] += pascal[layer - 1][pos];
        }
    }

    std::size_t T;
    cin >> T;

    for (auto t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": \n";
        global_done = false;
        cin >> global_goal;

        vector<Frontier> history;
        history.reserve(501);

        dfs(Frontier{0, 0, 1}, history, pascal);
    }

    return 0;
}