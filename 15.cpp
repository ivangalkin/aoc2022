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
    std::vector<std::tuple<int64_t, int64_t, int64_t, int64_t>> input_test{
            {2,  18, -2, 15},
            {9,  16, 10, 16},
            {13, 2,  15, 3},
            {12, 14, 10, 16},
            {10, 20, 10, 16},
            {14, 17, 10, 16},
            {8,  7,  2,  10},
            {2,  0,  2,  10},
            {0,  11, 2,  10},
            {20, 14, 25, 17},
            {17, 20, 21, 22},
            {16, 7,  15, 3},
            {14, 3,  15, 3},
            {20, 1,  15, 3},

    };
    std::vector<std::tuple<int64_t, int64_t, int64_t, int64_t>> input_real{
            {3772068, 2853720, 4068389, 2345925},
            {78607,   2544104, -152196, 4183739},
            {3239531, 3939220, 3568548, 4206192},
            {339124,  989831,  570292,  1048239},
            {3957534, 2132743, 3897332, 2000000},
            {1882965, 3426126, 2580484, 3654136},
            {1159443, 3861139, 2580484, 3654136},
            {2433461, 287013,  2088099, -190228},
            {3004122, 3483833, 2580484, 3654136},
            {3571821, 799602,  3897332, 2000000},
            {2376562, 1539540, 2700909, 2519581},
            {785113,  1273008, 570292,  1048239},
            {1990787, 38164,   2088099, -190228},
            {3993778, 3482849, 4247709, 3561264},
            {3821391, 3986080, 3568548, 4206192},
            {2703294, 3999015, 2580484, 3654136},
            {1448314, 2210094, 2700909, 2519581},
            {3351224, 2364892, 4068389, 2345925},
            {196419,  3491556, -152196, 4183739},
            {175004,  138614,  570292,  1048239},
            {1618460, 806488,  570292,  1048239},
            {3974730, 1940193, 3897332, 2000000},
            {2995314, 2961775, 2700909, 2519581},
            {105378,  1513086, 570292,  1048239},
            {3576958, 3665667, 3568548, 4206192},
            {2712265, 2155055, 2700909, 2519581},
    };

//    auto& input = input_test;
//    constexpr int64_t part_1_row = 10;
//    constexpr int64_t part2_range_fromx = 0;
//    constexpr int64_t part2_range_tox = 20;
//    int64_t part2_range_fromy = 0;
//    int64_t part2_range_toy = 20;

    auto &input = input_real;
    constexpr int64_t part1_row = 2000000;
    constexpr int64_t part2_range_fromx = 0;
    constexpr int64_t part2_range_tox = 4000000;
    int64_t part2_range_fromy = 0;
    int64_t part2_range_toy = 4000000;

    std::array<bool, part2_range_tox + 1> possiblex;

    int64_t get_impossible_columns(int64_t row) {
        std::set<int64_t> impossibles;

        for (auto [sx, sy, bx, by]: input) {
            auto diffx = abs(bx - sx);
            auto diffy = abs(by - sy);
            auto distance = diffx + diffy;
            auto miny = sy - distance;
            auto maxy = sy + distance;
            if (miny <= row && row <= maxy) {
                int64_t expected_diffy = abs(row - sy);
                int64_t expected_diffx = distance - expected_diffy;
                assert(expected_diffx >= 0);

                int64_t testx_from = sx - expected_diffx;
                int64_t testx_to = sx + expected_diffx;
                assert(testx_from <= testx_to);

                for (int64_t testx = testx_from; testx <= testx_to; testx++) {
                    impossibles.insert(testx);
                }
            }
        }

        for (auto [sx, sy, bx, by]: input) {
            if (sy == row) {
                impossibles.erase(sx);
            }
            if (by == row) {
                impossibles.erase(bx);
            }
        }

        return impossibles.size();
    }

    std::optional<int64_t> get_possible_column(int64_t row, int64_t range_fromx, int64_t range_tox) {
        ASSERT_EQ(range_fromx, 0);
        possiblex.fill(true);

        for (auto [sx, sy, bx, by]: input) {
            auto diffx = abs(bx - sx);
            auto diffy = abs(by - sy);
            auto distance = diffx + diffy;
            auto miny = sy - distance;
            auto maxy = sy + distance;
            if (miny <= row && row <= maxy) {
                int64_t expected_diffy = abs(row - sy);
                int64_t expected_diffx = distance - expected_diffy;
                assert(expected_diffx >= 0);

                int64_t testx_from = std::max(sx - expected_diffx, range_fromx);
                int64_t testx_to = std::min(sx + expected_diffx, range_tox);
                assert(testx_from <= testx_to);

                for (int64_t testx = testx_from; testx <= testx_to; testx++) {
                    possiblex[testx] = false;
                }
            }
        }

        if (auto it = std::find(possiblex.begin(), possiblex.end(), true); it != possiblex.end()) {
            int64_t possible_position = std::distance(possiblex.begin(), it);
            myprint(possible_position);
            return possible_position;
        }

        return std::nullopt;
    }
}

// aoc2022 3200000 3600000
// The range was found while splitting the original range [0, 4000000]
// into 10 parts and running 10 instances of this program.
int _15(int argc, char **argv) {
    ASSERT_EQ(get_impossible_columns(part1_row), 5299855);

    part2_range_fromy = strtoll(argv[1], nullptr, 10);
    part2_range_toy = strtoll(argv[2], nullptr, 10);

    for (int64_t r = part2_range_fromy; r <= part2_range_toy; r++) {
        if (r % 100000 == 0)
            myprint(r);
        auto maybe_column = get_possible_column(r, part2_range_fromx, part2_range_tox);
        if (maybe_column) {
            myprint(r);
            myprint(*maybe_column);
            myprint(*maybe_column * 4000000 + r);
            ASSERT_EQ(*maybe_column * 4000000 + r, 13615843289729);
            break;
        }
    }

    return 0;
}
