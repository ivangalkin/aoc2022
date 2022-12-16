#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <queue>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#define ASSERT_EQ(a, b) \
   do { __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     if (_a != _b)       \
     {                 \
       std::cout << _a << " != " << _b << std::endl; \
       assert(0);                  \
     }                  \
     }while(0)

#define myprint(arg) do { std::cout << "" #arg << " = " << arg << std::endl; } while(0)

namespace {
    using Tunnel = std::tuple<int64_t, std::vector<std::string>>;
    std::map<std::string, Tunnel> input_real{
            {"OQ", {17, {"NB", "AK", "KL"}}},
            {"HP", {0,  {"ZX", "KQ"}}},
            {"GO", {0,  {"HR", "GW"}}},
            {"PD", {9,  {"XN", "EV", "QE", "MW"}}},
            {"NQ", {0,  {"HX", "ZX"}}},
            {"DW", {0,  {"IR", "WE"}}},
            {"TN", {24, {"KL", "EI"}}},
            {"JJ", {0,  {"EV", "HR"}}},
            {"KH", {0,  {"ZQ", "AA"}}},
            {"PH", {0,  {"FN", "QE"}}},
            {"FD", {0,  {"SM", "HX"}}},
            {"SM", {7,  {"WW", "RZ", "FD", "HO", "KQ"}}},
            {"PU", {0,  {"VL", "IR"}}},
            {"OM", {0,  {"CM", "AA"}}},
            {"KX", {20, {"PC"}}},
            {"IR", {3,  {"PU", "CM", "WW", "DW", "AF"}}},
            {"XG", {0,  {"RX", "OF"}}},
            {"QE", {0,  {"PH", "PD"}}},
            {"GW", {0,  {"JQ", "GO"}}},
            {"HO", {0,  {"SM", "TY"}}},
            {"WU", {0,  {"SG", "RZ"}}},
            {"MS", {0,  {"UE", "OF"}}},
            {"JS", {0,  {"DO", "ZX"}}},
            {"YQ", {0,  {"BC", "SG"}}},
            {"EJ", {0,  {"AA", "LR"}}},
            {"EI", {0,  {"BV", "TN"}}},
            {"NC", {0,  {"TS", "BC"}}},
            {"AF", {0,  {"IR", "HX"}}},
            {"OX", {0,  {"HR", "BV"}}},
            {"BF", {0,  {"JQ", "SY"}}},
            {"CA", {0,  {"YD", "HX"}}},
            {"KQ", {0,  {"HP", "SM"}}},
            {"NB", {0,  {"OQ", "OF"}}},
            {"SY", {0,  {"BF", "BV"}}},
            {"AA", {0,  {"KH", "EJ", "OM", "TY", "DO"}}},
            {"BC", {11, {"WE", "RX", "YQ", "LR", "NC"}}},
            {"HR", {14, {"OX", "GO", "JJ"}}},
            {"WE", {0,  {"DW", "BC"}}},
            {"MW", {0,  {"JQ", "PD"}}},
            {"DO", {0,  {"JS", "AA"}}},
            {"PC", {0,  {"AK", "KX"}}},
            {"YD", {0,  {"CA", "OF"}}},
            {"RX", {0,  {"XG", "BC"}}},
            {"CM", {0,  {"IR", "OM"}}},
            {"HX", {6,  {"ZQ", "NQ", "AF", "FD", "CA"}}},
            {"ZQ", {0,  {"KH", "HX"}}},
            {"BV", {21, {"SY", "OX", "EI"}}},
            {"AK", {0,  {"PC", "OQ"}}},
            {"UE", {0,  {"MS", "JQ"}}},
            {"LR", {0,  {"BC", "EJ"}}},
            {"JQ", {8,  {"MW", "UE", "BF", "GW"}}},
            {"VL", {0,  {"PU", "ZX"}}},
            {"EV", {0,  {"JJ", "PD"}}},
            {"TS", {0,  {"NC", "ZX"}}},
            {"RZ", {0,  {"SM", "WU"}}},
            {"OF", {13, {"XG", "YD", "NB", "MS", "XN"}}},
            {"WW", {0,  {"SM", "IR"}}},
            {"TY", {0,  {"HO", "AA"}}},
            {"XN", {0,  {"OF", "PD"}}},
            {"SG", {15, {"WU", "YQ"}}},
            {"FN", {25, {"PH"}}},
            {"KL", {0,  {"TN", "OQ"}}},
            {"ZX", {5,  {"JS", "HP", "VL", "NQ", "TS"}}},
    };

    decltype(input_real) input_test{
            {"AA", {0,  {"DD", "II", "BB"}}},
            {"BB", {13, {"CC", "AA"}}},
            {"CC", {2,  {"DD", "BB"}}},
            {"DD", {20, {"CC", "AA", "EE"}}},
            {"EE", {3,  {"FF", "DD"}}},
            {"FF", {0,  {"EE", "GG"}}},
            {"GG", {0,  {"FF", "HH"}}},
            {"HH", {22, {"GG"}}},
            {"II", {0,  {"AA", "JJ"}}},
            {"JJ", {21, {"II"}}},
    };
//    auto &input = input_test;
    auto &input = input_real;


// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
    using namespace std;
# define INF 0x3f3f3f3f
// iPair ==> Integer Pair
    typedef pair<int, int> iPair;

// To add an edge (assumes the same weight u->v and v->u, therefore not usable in our task)
    void addEdge(vector<pair<int, int> > adj[], int u,
                 int v, int wt) {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }


// Prints shortest paths from src to all other vertices
    int shortestPath(const vector<pair<int, int> > adj[], int V, int src, int target) {
        // Create a priority queue to store vertices that
        // are being preprocessed. This is weird syntax in C++.
        // Refer below link for details of this syntax
        // http://geeksquiz.com/implement-min-heap-using-stl/
        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> dist(V, INF);

        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push(make_pair(0, src));
        dist[src] = 0;

        /* Looping till priority queue becomes empty (or all
        distances are not finalized) */
        while (!pq.empty()) {
            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // Get all adjacent of u.
            for (const auto &[v, weight]: adj[u]) {
                // If there is shorted path to v through u.
                if (dist[v] > dist[u] + weight) {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print shortest distances stored in dist[]
//        printf("Vertex Distance from Source\n");
//        for (int i = 0; i < V; ++i)
//            printf("%d \t\t %d\n", i, dist[i]);

        return dist[target];

    }

    struct SearchPath {
        std::vector<std::string> tunnels;
        int64_t remaining_time = 30;
        int64_t pressure = 0;
    };

    struct DuoSearchPath {
        SearchPath walker0;
        SearchPath walker1;

        DuoSearchPath() {
            walker0.remaining_time = 26;
            walker1.remaining_time = 26;
        }
    };

    std::vector<std::string>
    get_next_steps(const std::vector<std::string> &opened_tunnels,
                   const std::vector<std::string> &unique_tunnels_sorted) {
        std::vector<std::string> opened_tunnels_sorted = opened_tunnels;
        std::sort(opened_tunnels_sorted.begin(), opened_tunnels_sorted.end());

        std::vector<std::string> diff;
        std::set_difference(unique_tunnels_sorted.begin(), unique_tunnels_sorted.end(), opened_tunnels_sorted.begin(),
                            opened_tunnels_sorted.end(),
                            std::inserter(diff, diff.begin()));

        return diff;
    }

    template<typename CallableT>
    void part1(CallableT memorizeShortestPath, const std::vector<std::string> &unique_tunnels_with_rate) {
        int64_t max_pressure1 = 0;
        std::vector<SearchPath> queue;
        SearchPath first;
        first.tunnels.emplace_back("AA");
        queue.push_back(first);
        while (!queue.empty()) {
            auto top = queue.back();
            queue.pop_back();
            const auto &current_tunnel = top.tunnels.back();
            max_pressure1 = std::max(max_pressure1, top.pressure);

            auto possible_next_steps = get_next_steps(top.tunnels, unique_tunnels_with_rate);
            for (const auto &next_tunnel: possible_next_steps) {
                // calculate price of the next step
                auto price = memorizeShortestPath(current_tunnel, next_tunnel) /* walk */+ 1 /* opening */;
                int64_t new_remaining_time = top.remaining_time - price;
                if (new_remaining_time >= 0) {
                    SearchPath new_search_path = top;
                    new_search_path.remaining_time = new_remaining_time;
                    new_search_path.tunnels.push_back(next_tunnel);
                    new_search_path.pressure += new_remaining_time * std::get<0>(input[next_tunnel]);
                    queue.push_back(new_search_path);
                }
            }
        }
        myprint(max_pressure1);
    }


// This approach is very naive. It implements parallel progress for the human & the elefant.
// Parallel execution doesn't allow DP/memorization :facepalm:
// Later I discovered a read about a better approach:
// 1. Introduce memorization for {start position, set of opened tunnels, remaining time} : {best possible score}
// 2. For every finished human walk-through find the elephant's best score (use memorization for both steps)
    template<typename CallableT>
    void part2(CallableT memorizeShortestPath, const std::vector<std::string> &unique_tunnels_with_rate) {
        int64_t max_pressure2 = 0;
        std::vector<DuoSearchPath> queue;
        DuoSearchPath first;
        first.walker0.tunnels.emplace_back("AA");
        first.walker1.tunnels.emplace_back("AA");

        queue.push_back(first);
        while (!queue.empty()) {
            auto top = queue.back();
            queue.pop_back();
            const auto &current_tunnel_walker0 = top.walker0.tunnels.back();
            const auto &current_tunnel_walker1 = top.walker1.tunnels.back();
            if (max_pressure2 < top.walker0.pressure + top.walker1.pressure) {
                max_pressure2 = top.walker0.pressure + top.walker1.pressure;
                myprint(max_pressure2);
            }

            auto possible_next_steps_walker0 = get_next_steps(top.walker0.tunnels, unique_tunnels_with_rate);
            possible_next_steps_walker0 = get_next_steps(top.walker1.tunnels, possible_next_steps_walker0);

            for (auto next_tunnel_walker0: possible_next_steps_walker0) {
                // calculate price of the next step for human
                auto price_walker0 = memorizeShortestPath(current_tunnel_walker0, next_tunnel_walker0) + 1;
                int64_t new_remaining_time_walker0 = top.walker0.remaining_time - price_walker0;
                if (new_remaining_time_walker0 < 0) {
                    continue;
                }

                DuoSearchPath new_search_path_walker0 = top;
                new_search_path_walker0.walker0.remaining_time = new_remaining_time_walker0;
                new_search_path_walker0.walker0.tunnels.push_back(next_tunnel_walker0);
                new_search_path_walker0.walker0.pressure +=
                        new_remaining_time_walker0 * std::get<0>(input[next_tunnel_walker0]);
                queue.push_back(new_search_path_walker0);

                auto possible_next_steps_walker1 = possible_next_steps_walker0;
                possible_next_steps_walker1 = get_next_steps({next_tunnel_walker0}, possible_next_steps_walker1);

                // do the same in nested way for an elefant
                for (auto next_tunnel_walker1: possible_next_steps_walker1) {
                    auto price_walker1 = memorizeShortestPath(current_tunnel_walker1, next_tunnel_walker1) + 1;
                    int64_t new_remaining_time_walker1 = top.walker1.remaining_time - price_walker1;
                    if (new_remaining_time_walker1 >= 0) {
                        DuoSearchPath new_search_path_walker1 = new_search_path_walker0;
                        new_search_path_walker1.walker1.remaining_time = new_remaining_time_walker1;
                        new_search_path_walker1.walker1.tunnels.push_back(next_tunnel_walker1);
                        new_search_path_walker1.walker1.pressure +=
                                new_remaining_time_walker1 * std::get<0>(input[next_tunnel_walker1]);
                        queue.push_back(new_search_path_walker1);
                    }
                }
            }
        }
        myprint(max_pressure2);
    }
}


int _16() {
    std::vector<std::string> unique_tunnels;
    for (auto &[tunnel, tunnel_properties]: input) {
        auto &[_, connections] = tunnel_properties;
        unique_tunnels.push_back(tunnel);
        unique_tunnels.insert(unique_tunnels.end(), connections.begin(), connections.end());
    };
    std::sort(unique_tunnels.begin(), unique_tunnels.end());
    unique_tunnels.erase(std::unique(unique_tunnels.begin(), unique_tunnels.end()), unique_tunnels.end());

    auto tunnel_to_id = [&unique_tunnels](const std::string &name) -> int {
        auto it = std::lower_bound(unique_tunnels.begin(), unique_tunnels.end(), name);
        return std::distance(unique_tunnels.begin(), it);
    };

    const size_t vertex = unique_tunnels.size() * unique_tunnels.size();
    auto *adj = new std::vector<pair<int, int>>[vertex];

    for (auto &[from_tunnel, from_tunnel_properties]: input) {
        auto from_tunnel_id = tunnel_to_id(from_tunnel);
        auto &[_, to_tunnels] = from_tunnel_properties;
        for (auto &to_tunnel: to_tunnels) {
            auto to_tunnel_id = tunnel_to_id(to_tunnel);
            adj[from_tunnel_id].emplace_back(to_tunnel_id, 1);
            adj[to_tunnel_id].emplace_back(from_tunnel_id, 1);
        }
    };

    auto unique_tunnels_with_rate = unique_tunnels;
    unique_tunnels_with_rate.erase(std::remove_if(unique_tunnels_with_rate.begin(), unique_tunnels_with_rate.end(),
                                                  [](const std::string &tunnel) {
                                                      return std::get<0>(input[tunnel]) == 0;
                                                  }), unique_tunnels_with_rate.end());

    int *shortestPathMemory = new int[vertex];
    std::fill(&shortestPathMemory[0], &shortestPathMemory[vertex], INT_MAX);
    auto memorizeShortestPath = [adj, vertex, shortestPathMemory, tunnel_to_id, dimension = unique_tunnels.size()](
            const std::string &from_tunnel,
            const std::string &to_tunnel) -> int {
        auto from_tunnel_id = tunnel_to_id(from_tunnel);
        auto to_tunnel_id = tunnel_to_id(to_tunnel);
        auto key = from_tunnel_id * dimension + to_tunnel_id;
        if (shortestPathMemory[key] == INT_MAX) {
            auto result = shortestPath(adj, vertex, from_tunnel_id, to_tunnel_id);
            shortestPathMemory[key] = result;
            shortestPathMemory[to_tunnel_id * dimension + from_tunnel_id] = result;
        }
        return shortestPathMemory[key];
    };

    part1(memorizeShortestPath, unique_tunnels_with_rate);
    part2(memorizeShortestPath, unique_tunnels_with_rate);

    return 0;
}
