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
    enum CMD {
        noop, addx
    };
    using Instruction = std::tuple<CMD, int64_t>;
    std::vector<Instruction> input = {
            {addx, 1},
            {addx, 5},
            {noop, 0},
            {addx, -1},
            {noop, 0},
            {noop, 0},
            {addx, 6},
            {addx, 15},
            {addx, -9},
            {noop, 0},
            {addx, -1},
            {addx, 4},
            {addx, 2},
            {addx, -22},
            {addx, 27},
            {addx, -1},
            {addx, 4},
            {noop, 0},
            {addx, 1},
            {addx, 2},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {addx, 1},
            {addx, -33},
            {addx, 2},
            {addx, 5},
            {addx, 2},
            {addx, 3},
            {addx, -2},
            {addx, 7},
            {noop, 0},
            {addx, -2},
            {addx, -8},
            {addx, 15},
            {addx, 5},
            {noop, 0},
            {noop, 0},
            {addx, -2},
            {addx, 2},
            {noop, 0},
            {noop, 0},
            {addx, 7},
            {addx, -14},
            {noop, 0},
            {addx, -2},
            {addx, -17},
            {addx, 5},
            {addx, -4},
            {noop, 0},
            {addx, 23},
            {addx, -18},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {addx, 28},
            {addx, -18},
            {addx, 4},
            {noop, 0},
            {noop, 0},
            {addx, -5},
            {addx, 1},
            {addx, 10},
            {addx, 2},
            {noop, 0},
            {noop, 0},
            {addx, -30},
            {addx, 33},
            {addx, -32},
            {noop, 0},
            {noop, 0},
            {addx, -2},
            {addx, 6},
            {addx, -2},
            {addx, 4},
            {addx, 3},
            {addx, 19},
            {addx, 10},
            {addx, -5},
            {addx, -16},
            {addx, 3},
            {addx, -2},
            {addx, 17},
            {addx, -19},
            {addx, 11},
            {addx, 2},
            {addx, 9},
            {noop, 0},
            {addx, -4},
            {addx, -6},
            {addx, -7},
            {addx, -24},
            {noop, 0},
            {addx, 7},
            {addx, -2},
            {addx, 5},
            {addx, 2},
            {addx, 3},
            {addx, -2},
            {addx, 2},
            {addx, 5},
            {addx, 2},
            {addx, 7},
            {addx, -2},
            {noop, 0},
            {addx, 3},
            {addx, -2},
            {addx, 2},
            {addx, 7},
            {noop, 0},
            {addx, -2},
            {addx, -34},
            {addx, 1},
            {addx, 1},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {addx, 5},
            {noop, 0},
            {noop, 0},
            {addx, 5},
            {addx, -1},
            {noop, 0},
            {addx, 6},
            {addx, -1},
            {noop, 0},
            {addx, 4},
            {addx, 3},
            {addx, 4},
            {addx, -1},
            {addx, 5},
            {noop, 0},
            {addx, 5},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {noop, 0},
            {addx, 1},
            {noop, 0},
            {noop, 0},
    };
}

int _10() {
    int64_t result0 = 0;
    int64_t X = 1;
    int64_t cycle = 1;
    int64_t drawing_pos = 0;

    auto do_one_cycle = [&]() {
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220) {
            result0 += cycle * X;
        }
        if (X - 1 <= drawing_pos && drawing_pos <= X + 1) {
            std::cout << "#";
        } else {
            std::cout << " ";
        }
        if (drawing_pos == 39) {
            std::cout << std::endl;
        }
        ++drawing_pos;
        drawing_pos %= 40;
        cycle++;
    };

    for (auto [cmd, count]: input) {
        switch (cmd) {
            case noop: {
                do_one_cycle();
                break;
            }
            case addx: {
                do_one_cycle();
                do_one_cycle();
                X += count;
                break;
            }
        }
    }
    myprint(result0);
    return 0;
}
