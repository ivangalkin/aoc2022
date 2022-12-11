#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>

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
    using Monkey = std::tuple<
            std::vector<int64_t>,
            std::function<int64_t(int64_t)>,
            int64_t,
            int64_t,
            int64_t
    >;

    std::vector<Monkey> input = {
            {
                    {52, 60, 85, 69, 75, 75},
                    [](int64_t old) { return old * 17; },
                    13,
                    6,
                    7,},

            {
                    {96, 82, 61, 99, 82, 84, 85},
                    [](int64_t old) { return old + 8; },
                    7,
                    0,
                    7,},

            {
                    {95, 79},
                    [](int64_t old) { return old + 6; },
                    19,
                    5,
                    3,},

            {
                    {88, 50, 82, 65, 77},
                    [](int64_t old) { return old * 19; },
                    2,
                    4,
                    1,},

            {
                    {66, 90, 59, 90, 87, 63, 53, 88},
                    [](int64_t old) { return old + 7; },
                    5,
                    1,
                    0,},

            {
                    {92, 75, 62},
                    [](int64_t old) { return old * old; },
                    3,
                    3,
                    4,},

            {
                    {94, 86, 76, 67},
                    [](int64_t old) { return old + 1; },
                    11,
                    5,
                    2,},

            {
                    {57},
                    [](int64_t old) { return old + 2; },
                    17,
                    6,
                    2,},

    };

    std::array<int64_t, 8> inspected;
}

int _11_1() {
    int nr_rounds = 20;
    inspected.fill(0);
    int64_t result0 = 0;

    for (int round = 0; round < nr_rounds; round++) {
        for (int current_monkey = 0; current_monkey < 8; current_monkey++) {
            auto &[items, func, test, if_true, if_false] = input.at(current_monkey);
            for (auto item: items) {
                inspected.at(current_monkey)++;
                auto level = func(item);
                assert(level > item);
                level /= 3;
                int64_t new_monkey = (level % test == 0) ? if_true : if_false;
                assert(new_monkey != current_monkey);
                std::get<0>(input.at(new_monkey)).push_back(level);
            }
            items.clear();
        }
    }

    std::sort(inspected.begin(), inspected.end());
    result0 = inspected.at(6) * inspected.at(7);

    myprint(result0);
    return 0;
}
