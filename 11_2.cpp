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
    struct Item {
        std::map<int64_t, int64_t> reminders;

        Item(int64_t nr) {
            for (int64_t d: {13, 7, 19, 2, 5, 3, 11, 17}) {
                reminders[d] = nr % d;
            }
        }

        void plus(int64_t nr) {
            for (auto &[key, value]: reminders) {
                value += nr;
                value %= key;
            }
        }

        void mult(int64_t nr) {
            for (auto &[key, value]: reminders) {
                value *= nr;
                value %= key;
            }
        }

        void square() {
            for (auto &[key, value]: reminders) {
                value *= value;
                value %= key;
            }
        }

        bool divisible(int64_t nr) {
            assert(reminders.find(nr) != reminders.end());
            return reminders[nr] == 0;
        }
    };

    using Monkey = std::tuple<
            std::vector<Item>,
            std::function<void(Item &)>,
            int64_t,
            int64_t,
            int64_t
    >;

    std::vector<Monkey> input = {
            {
                    {52, 60, 85, 69, 75, 75},
                    [](Item &old) { old.mult(17); },
                    13,
                    6,
                    7,},

            {
                    {96, 82, 61, 99, 82, 84, 85},
                    [](Item &old) { old.plus(8); },
                    7,
                    0,
                    7,},

            {
                    {95, 79},
                    [](Item &old) { old.plus(6); },
                    19,
                    5,
                    3,},

            {
                    {88, 50, 82, 65, 77},
                    [](Item &old) { old.mult(19); },
                    2,
                    4,
                    1,},

            {
                    {66, 90, 59, 90, 87, 63, 53, 88},
                    [](Item &old) { old.plus(7); },
                    5,
                    1,
                    0,},

            {
                    {92, 75, 62},
                    [](Item &old) { old.square(); },
                    3,
                    3,
                    4,},

            {
                    {94, 86, 76, 67},
                    [](Item &old) { old.plus(1); },
                    11,
                    5,
                    2,},

            {
                    {57},
                    [](Item &old) { old.plus(2); },
                    17,
                    6,
                    2,},

    };

    std::array<int64_t, 8> inspected;
}

int _11_2() {
    int nr_rounds = 10000;
    inspected.fill(0);
    int64_t result1 = 0;

    for (int round = 0; round < nr_rounds; round++) {
        for (int current_monkey = 0; current_monkey < 8; current_monkey++) {
            auto &[items, func, test, if_true, if_false] = input.at(current_monkey);
            for (auto &item: items) {
                inspected.at(current_monkey)++;
                func(item);
                int64_t new_monkey = (item.divisible(test)) ? if_true : if_false;
                assert(new_monkey != current_monkey);
                std::get<0>(input.at(new_monkey)).push_back(item);
            }
            items.clear();
        }
    }

    std::sort(inspected.begin(), inspected.end());
    result1 = inspected.at(6) * inspected.at(7);

    myprint(result1);
    return 0;
}
