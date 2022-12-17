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

using ll = int64_t;

namespace {

    const std::string input_real{
            ">>><<<>>><><>>><<>>>><<>>>><<<<><<<<>>>><>>><<<>><<<>>><<<<>><<<<>><<<<>>><><<<<>><><<<<>>>><<<>><><<<><><<>><<<<>>>><<><<<<>>>><<<<>>><>><<>>><<>><<><>>>><<<>>><<<>>><<<>>>><>>><>><<<<>><<<<>><>>><><>><<<>>>><<<>>>><<>>>><<<>><<<>>><><<<>>><<<<>>><<<<>>><<<>><<><<<>><><<<>>>><>><<>><<><<<<><<<<>>><<<><<>>><>>><<><<><<>>><<<>><<<><>><<<>><<<><<<>>>><<><>><<<>>><<<>>><>>><<<<>>><<<<>>><>><>>><<>><<<>>>><<>>><<>>>><>>>><><<<>>><>><<>><<<<><<>>><<<><<>>><<<>>><<<<>>><<<<>>>><<<<>><<>><<<><<<<>><<<><>>><<<>>><<<><<<<><<<<>>><<>>>><<><<<><>>><<<<>>>><<<>><<<>><<<<><>><>><<<>><<<<><<><<<><<>>>><<<><<<>>>><<<<>>>><<>>><<><<>>><<>><<<>><>><<>>><<<<><<<>>><<<>>>><<<<><<<>>><<<>><<<>>>><<>>><<<>>>><<<<>>>><>>>><<>>><>><<>>><<<<><><<<<>>>><<<>><<<>>><<<<>>>><<<<>>><<>>>><>>>><<<<>>><<<>>>><<<<><<<<>>>><<<<>><<<><<<><<<>>><<<<>>>><<>><<>>>><<>>><<<<><>>>><<>>><<>><>>><<<<>>>><<<<>>><<<><<<>>><<><<<><<<><>>>><<<<>>>><<<<>><<<>>><><>>><<<<>><<<>>>><<<>>>><<>>>><<<<>><<><<<>><<<<><<<>>><<<<>><>>><<<>>>><<<<>>>><<<><><<<<>><<<>><<>>><<<<><>>><<<<>>>><<>>><<>><<><<>>><<>>>><<>>><>><>>>><>>>><>>><>>>><<>><<<<><>>><>>><>><<>>>><>><<>>>><<>>>><<<>><>><>><>>><><>>>><>>>><>><<><<<>>><<>><<<<>>><<<<>>><<<>>><<<>>><<<<>>>><>><<<<>><<<<>>><<<>>>><<<><>>>><<<<>>>><>><<>>><<<<>>><<<>><<>>>><<>><<<<><<<>><>><<<<>><<<<>>><<<<><<<>>><<>>><<><><<>>><<<>><<<>>><<<<>>><<>>><><<>>><<<<><<>>><<<<>>><<>><<<<>><<<>>>><<<>>>><<<<>><<>><<<>><<<>>><<<>>><<<>>>><<>><<>>><>><<<<>>><<<<><<>>><<<<>><<<<>>><<<<>>><<<<>>>><<<<><>>><>><<<>>><>>><<<<><<>><<>><<<<>><<><<<>><<<>>>><<<>>>><<<>>><<<<>><>><<<<>>><<>><<<<>>><<<>>><<>><<<>>><<>>>><<<>>>><<<>>>><><><<<<><<<<>><<>><>>>><<>><>>><>>>><<<<>>>><><<<>>>><>><>>>><<><<>><<><>>><<<<>>><>>>><<<><<>>>><<><<<>>>><<<>><<<><<>>>><<<><<<>>>><<>><>>>><<>>><<<<><<<>>><<>>><<<<><><<<<><>><><><<<<><><<>>>><<<>><<<<>><>><<<><<<<>>>><<>><<>>>><>>><<<><<<>><<<<>>><>><><><<>>>><><<<>><<>>><<<>>><<<<>>><<>>>><<<>><<<>>><<>><<>>>><<<<>>><<>>>><><<<>><>><<<>><<<><<><>>>><><<<>>>><>>><<>><<><<<<>>>><<>>><<<<>>>><>><><<>>><<<><>><<><>><>>>><>>>><<<><><<<>>><<>>>><<<>>><<<<>>>><<<>><<<<>>>><<<>>><<<<><<<><<<>>><><<><>><<<<>>><<<<>>><<<>>>><<<<>><<<>>><><<>><<><<>>>><<>><>>><<<<>><<<>>>><<<>>><<<><<><<><<<>>><<<<>>><>>>><<<>>>><>>>><<<>>>><<>>>><<>>><<<>><<<>>>><>><<>>><<<>>>><<>>><<<>>>><<><<>><<>>>><<<>><<>>>><<<>><>><>><<<<>>>><<<>>>><>>><>>>><<<>><<>><><<<<>>><<<<>>><<<<><<<>>><<<<><<>>>><<>><<>>><<<>>><<<<><<<>>><<><<<<><<>><><>><<>>><>>>><<<><>>>><<>><>><><<<<><<<<>>>><<<><<<><<<<>><<>>><<<<><<<>>><<<<>><<<><><<<<><<>>><<>>>><<>>>><<<<>><<<<><<>>><<>>><<<<>><<<<><<<>><<<>><>><>>><<><<<<><<>><>><<<><<>><<>>>><<<<>>><<<<>><<<><<<><<>>><<>>>><<>><>>>><<<>>>><<<><<<<><<<<>>><>>>><<<<>>>><<<>>><>>><<<>><<<<><>>>><>>><><<<>>>><>>><>><<><<>><<<<>><<<>><<<>><<<<>>>><<<<>>>><<>>><<<<>>>><<<<>><<>>><<>>><<<<><<>>><<<>>><>>>><<><<<<>><>><>>>><>>>><><<><<>>><<><<>>><>>>><<>>><<<<>><<<><<>><>>><>><<>>><<><<>>>><<<<>>><<<>>>><>>>><>>><<>>>><<<<>><<><<<<>>>><<<><<>>>><>>><<<><<>>><>>>><<><<>><<>><<<>>><<><><<<<>><<<<><>>>><<<>>>><>><<<<>><<<>>><<<>>>><<<<>>>><><<<>>><<>><><>>>><<<<>>>><<<<><>>><<<>>>><<><<<>><<<<><>>>><<>><<<>><<<>>><<><<<>>><<<><<<>><<><>><><<<<>>><<<<>>><<><<<<><>>>><<<<>>><<>>>><>>>><<<><>><>><<<<>><<>><<><<>>><<><<<<>><>><<<>>><<<>><<<><<<<>>><<<>>><<>>><>><<<>><<<>><<<>><<><<><><<>>>><<<<>><>>>><<<>>>><<<>>>><><<<<>>><<<<>><<>><<<>>>><>><<<<>>><<<>><<><>>><<<<><<<>>>><<<>>><<<<>>>><><<>>>><>><<<<><<<><><>><<<>>>><<<>><>>><<<>>>><<<<>>>><<<<><><>><<<<>><>><>><<<<>>><<<<>>><<<<>>>><<<><>>><>>><>><>>>><<<<>>>><<>><<>>><<<<><<<<>><<<<>><<<>><<<<>><<><<<>>>><>>><<><<<>><<<>><<><>>>><<<<>>><><><<<<>><>>><<><<>><<<>>>><>><<<><<<<>>><<>>><<<<><<<<>><<><<>><><<<<>>>><<<><<>>><<<<>>><>><<<<>>>><<>>>><<><<>>>><<<<>><<<>>>><<>>><<<><<>>>><><<>><>><<<><<>>>><<>>>><<><<><<<<>>><<<<>><<<<><>>>><<<><<><<><<<>><<<<><<<><<<<>>><<<<>>><<>>><>>>><<<>><<>><><<>>><>><<<><>><<<>>><<<<>>>><><<<<>>><<<>><>><<<<>>><<<><<<<>>><><<>>>><>>>><<<<>><<<>>><<<>>><<<<><<>><<>><<<<>>>><<>>>><<><<>>><<>>><<<>>><><>>>><>>><<>>><<<<>>>><>>>><>>><<<<>>><<<<>>><><<<>>><<<<>>>><>><><<>>><<<><>>><<<>>><<<>>><<<>>>><>>>><<<<>>>><<<<>>>><<<>>>><<><<>><<<<>>><<<>>>><<<>><<<<>>><<><<><<<<>>><>><<<><<<>>>><<>><<><<<>>>><<<><<<>>><<<<>>>><<>>>><<<<>>><><<><<<<><<<<>>><<>>><>>>><><><>>>><<<<>>><<<>>><<<><<<<>>>><>><><<<>><>><<<<>>><><<<<>>>><<<>>>><>><<<>>>><>><<<><<<<><><>>><>>><<<>>><<><<<>>>><>>>><<<>>><>><><<<<><<><<<>>>><<><<><<><<<>>>><<<><<<>>><<<<>><<<<>>>><>>>><><<<>>><<<<>>>><<><>>>><<<>><>>>><<><<<<>><<<>><<>>>><<><>><><<<<><<<<>>>><>>><<>><<><>>>><<<><<<>><<><>>>><<>>>><<<>>><<<>>>><<>>>><<<>><<<>>><<<>><<<<>>><<>>>><<<>>>><<<>><<<<>>><>>>><>>><<<<>>>><<<<>><>>><<>>>><<<><><><<>>><<<<>>><>>><<<<>>>><<>>>><<<<>>>><<<>>><<<<>><<>>>><>>><>>><<>>><<<<>>>><<<><><<<<>>>><<<>>>><<<<>>><<<<>>><<<>><<<>>>><<>>>><><<<<>>>><<<<>><>><<<><<<><<<<>>><<<<>>>><>>><>><>>>><<<<>>><<>><<<>>><<>><<>><<><<>>><<>>><<<>>>><<<><><<<><<<<>>><<<>><<<<>>>><<>><<<><>><<<><>>>><<<<>>><<<<>><<><>><<<>>><<>>><<<>>><<<<>>>><<<>><<<<>><<>><>>>><>>><>><<<>>><<<><<<<>><<>>><<>>>><<>>><><<>><<<>>>><<><<>>>><<<>>>><<<<>>>><<<<>><<<<>>><>><<<>><>>>><<<><<>><<><<<<><<>>><>>><>>>><<><<<<>><>>><<<<><<<<>><<><>>>><<>><<<>>><<<>>>><<<><><<<>><<<>>>><<<>>><<<<>><<<<>><>><>><<<<>>><<><<<<>><>>><<<>><<><<>><<>>>><>><<<<><<<<>>><>>><<<>><<<>><>><<<<><<<>>>><>><>>><<<>>>><<<<>>><<>>>><<<>><<>>>><<<<>>><<<<>>><<<<>>>><<<<>><<<<>>><>>><>>><<<<>>><<<<>>><<>>>><<<<>>><<<>>><<<>><><<<>>>><<>>><<><<<>>>><<<>><>><>>>><><<><<<>>><<>>>><<<<>><<<<>>>><>>><<><<<<><<<<>>><>>>><<<>><><>>>><<<>><>><<<>><<><<>><<<>>><>>><<>>><<><<<>>><<<>>>><>><>><<<<><<<<>>>><<<>>>><<<>>><<>><<>>><>><<<<>><<>>><<<<><>><<>>><<<>>><<<<>>><>>><<>>>><<<<><>>>><<<>><<<>>>><<<>>><<<<>>>><<>><<<<>>><<><>><>>>><>>>><<<>><<>>><<<>>>><<<>>>><<><<><<<>><>>>><<>>><<<<>>>><><<>>>><<>>>><<<>><<<>>><<<>>>><<<>><<>>>><><><<<><<>><>>>><<>>>><<>><<<><<<><><<<<>>><><<<><<><<<>><<<><<<>>>><<<>><<>>><<<<>>>><>>><>>>><<<<>>><<<>><<<<>>>><><>>><><>><<>><<>>>><><>>><<<><>>><<<>>>><<><<<<>>><>><<>>>><>><<<>>><<<<>>>><>><<>>><<<>>><<<<>><<>>><<<<>><<>>><<<<>>>><<>>><<<<>><><<<<>><<<>>><<<><<<<>>><<<<>>><<><>>>><<>>><<<>><>>>><<<<><><<<><<>>>><<><<><>>>><<<>>>><<<<>>><<><<>><<<>>>><<>>>><>>>><<><<<>><<><<>><<>><<<>>><>>>><<<<><<<>><<<<><<><<<<><<<<>><<<<>>>><<><<>>><>>><<<>>><>><<<>><<<>>><<<<><<<>><<<<>>>><<>>>><<<<>><<<<>>><<<>>><<<<>>>><<><<>><<><<<>>><<<<>>>><<><<>>>><>><<<<><<>>>><><<<<>>><<<>><<<<>>><<>>>><<<<>>><<<<><<<<>>><>>><>>><<<>><<<><>>>><><<<><>><<<<><<<><<<>>>><<<>><>><<<><>>>><<>>><>><<>>>><<>>>><<<>><<<<>>><<<>>>><<<<><<<<>><<<<>>><><<<<>>><<><>><<<<>><<>><>>><<<<>><<><<>>>><<<>>><<<<><<<<>>><<<>><<<><<<>><<<<><<<<><>>>><>>><<<>>>><>>><<>><<<<>><<<>>><<<<>><<<<>>><<<<><<<>>>><<>>><<>>><>>>><>><<>>>><<>><>>><<><<<<>>>><<<>>><<<>><<<><<<>>><>>>><<<><<<<><<<><<>>><<<>><<<<>><>><<>><<<<><><<<<>>><>>><<<<>>>><<>><<<<><<<<>>><<>>><<>><<<<>><><<<><<>>>><><<<><<<<>>>><>>><>><<<<>>><>>>><<<><<<<>>><<<<><<<><<<>>><<<<>>><<<>>><>>>><<<>><<<<>>><<>><<>>><>>><>>><<<><<><<<<><<<>><<<>><<<<>><>>>><<<<>>><<>>><>>>><<<<>><<<<><>>>><<<<>><>>><<<<>>>><<>>>><<<<>><<<<>><<<>>>><<<>>>><<>>><<<<>>>><>>>><<<>>><><<<><<<<>><<>><<<>><>>><>><<><<<<>>>><<<<>>>><>><<>><<<>>><>>>><>>>><><<<<><<<>>>><<<<><<<>>><>>><<>>><<>>><<<<>>>><>>>><>>><<<<>>>><<<<>><<<<><<<>><<<<><<>><<>>><>><<>><>>>><<><<<<>><><>>><<<<>><<<><<>>>><>>>><<<<><><<<<><<>><<<>><<<<>>><<<><<<>><<<>>><><>>><><>>><<<<><<>><<<>>>><<<<>>><<<<>>>><>>>><>><<<<>><<<>><<>>>><<>><<>>><>>>><><><<>>>><<<<>>><>>>><<<>>>><<<<>><>>><<<<>>>><>><<<>><<><<<<>>><<<<>>><<<>>>><<<<>><<>>><<>>>><<<<>>>><<<<>>><<>><<<<>><<<>>>><<<>>>><<<>><<<<>>><<>>><>>>><><<>>>><<<<>>><<>>><<<><<<<>>>><>>><<<<>><<<<>><<<>><>>><>><<<<>>><<><>>><<>><<>>><<><<>><><><>>><<<>>>><<<<>>>><>>><<<>>>><<<><<>>>><>><<<<><<<<>>>><<<>>>><<<<>>><<<><<>>><><<<><<<>><<<>>>><<>>><<<<>>>><<<<>><<>><<<<>>>><<>><<<>>><<<><<<>><>><<<>>><<><<<><<><<<><<<<>>><<<><<<<>><>>><<<>>><>><<>>><<<><<>><<<<>>>><<<<>><<<>>>><<><>><<>>>><<<><<>><<<<>>><<>>><<<<>>>><<<>>><<><<>>><<>>>><<<>><>>><<<<>>><<>>><><>><>>><<<>><<<><<>><<>><<<<>>>><<<<><>><<<>>><<>>><><<<<>><<<<>><<>>><<><<<<><<><>>><<<><>>>><>><<<>><>><<<<>>>><<<>>>><<<<>>><<<<>>>><<>>><<>><<<<><>>>><<<>>>><<>><>><<><<<<>>>><<<>>>><<>>>><>><<<>><<><<<>>><<<>><<><<><<>>><<<>>><<<>><<<>><<><<<<>>>><<<>>><<><<<<>><<<>>><<>>><<>>><>><<<>>>><<<<>>><<<<>><<<>><>>>><<<>>><<<<>>><<><<<><<>><>><<>>><<>>><<><<>>><<<<>><<>>>><<>>><<<>>>><<<>><<><<>><<<<>><<>>>><<<<>><<>>><>>><<<>><<<><<>>><>><<<<>>>><<<<>><<<<><<><<<>>><<<<>>>><<<>>>><<><<<>><<<<>>>><<<<><<><<<>>>><<>>><<<>>>><<<<><>>>><>>>><<<<>>><>>>><<<><>>><<>>><>>><<<><<<<>>><<>>><>>>><<>><>>>><<>>><<<<>>>><<<<>>>><<<<>>><<>><<<<>>>><<<<>>><<<>><><<<<>>><<>><>>><>>>><<<<>><>>>><<<<>>><<<<>>><<<<><>>><<<<>><<<>>><<<>><<<<>>>><<<><<<<>>><<>><<<<>>><<<><<<<>>><<<>><>>>><<<<>>>><>>>><<<>>>><>>><<<>>><<<>><<>>>><<>><<<<>><>><<<><<<>>><<<<>>><>><<<>><>><<<>>>><<<<>>>><<<<><>>>><<<<><<<<><<<<>>>><<<<>><<>>>><>><<<<>><<>>><<<<><<<<>><<<>><<>>><<<>>>><<<<>>><<>><<<<>><<<<>><<>><<<<>>>><<><>><>><<><<<>>>><<>>><<<<>><<<><>>>><<<<><<>>>><<<<>>>><<>>><<<><<<>><>>><>>>><>>><<<>>>><>><>><>><<>><>><>>><<><>>>><<<>>><>><>>>><<<<>>><<<>><<>>>><>>>><<<>><>><<<<>><<><<<>>><<>>><<>>><<<<>><>>><>>><<<>><<>>>><<>>>><<><<<<>>>><<<<>>><>>><<<<><<<>>>><>><<<<>>>><<<<><<>><<<>>><<<<>>><><<><<>>><<<><<<>><<<<><<<<>><<>>>><><<<>>>><<<<>>><<<>><>>>><<>>><<<<>>>><><<><<<><<<>>><<<<>><<<>>><<<<><<<<>>>><><>><<<<><<><<>><<>><><<>><<<<>><<<<>>>><<<>>>><<<<>>><>>><<<>>>><<<<>>><<<><<<<>><<<>><<<>><<<>><>>>><<<>><<>>><>>>><>>>><<<><<<<>>>><<>>>><<<>>><<<><<<>>>><>>>><<><>>><><><<>>><<>>><>><<<><>>><<>>><<><<<><<<>><<>><>>>><>><<<><<<><<<>><>><>>><<><<>><<<<>>><<<<>>>><<<<><<>>>><<>>>><<>><<<>>>><>>>><<><<<>>>><<<<>>>><<<<>>><<>>><<><<>><<<<>>>><>>><<<>><<<>>><>>>><<<>>><<<>><<<<><<<>><<<<><<<>>>><<>>>><<<<><>>><>>>><>>><<<>>><<<>>><<>>><<<<>>><<<>><<>><<>><<<<>>>><<<>><<<<><<<>>>><>>><<><<><<<<><<<<>>>><<<><><<<>><><<<>>><<<<>>><<<<>><<<><<<<><<<<>><<<<>><<<>>><<<<>><<<><>>>><<<<>>>><<<><<<>"
    };

    decltype(input_real) input_test = ">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>";
//    auto &input = input_test;
    auto &input = input_real;

    using FieldT = std::vector<std::string>;
    using ShapeT = std::vector<std::string>;

    // shapes are flipped vertically - most bottom line goes first
    const std::vector<ShapeT> shapes{
            {
                    "  #### "
            },
            {
                    "   #   ",
                    "  ###  ",
                    "   #   "
            },
            {
                    "  ###  ",
                    "    #  ",
                    "    #  ",
            },
            {
                    "  #    ",
                    "  #    ",
                    "  #    ",
                    "  #    "
            },
            {
                    "  ##   ",
                    "  ##   "
            },

    };

    /*new shape, was shifted*/
    std::tuple<ShapeT, bool> shiftShape(const ShapeT &old_shape, char DIR) {
        ll inc = 0;
        switch (DIR) {
            case '<': {
                inc = -1;
                for (auto &line: old_shape) {
                    if (line.at(0) == '#') {
                        inc = 0;
                        break;
                    }
                }
                break;
            }
            case '>': {
                inc = 1;
                for (auto &line: old_shape) {
                    if (line.at(6) == '#') {
                        inc = 0;
                        break;
                    }
                }
                break;
            }
        }
        if (inc == 0) {
            return {old_shape, false};
        }
        auto new_shape = old_shape;
        for (auto &line: new_shape) {
            ASSERT_EQ(line.length(), 7);
            if (inc == -1) {
                line = line.append(" ").substr(1);
                ASSERT_EQ(line.length(), 7);
            } else {
                line = " " + line.substr(0, 6);
                ASSERT_EQ(line.length(), 7);
            }
        }
        return {new_shape, true};
    }

    /*merged line, overlaps*/
    std::tuple<std::string, bool> merge_line(const std::string &background_line, const std::string &shape_line) {
        ASSERT_EQ(background_line.length(), 7);
        ASSERT_EQ(shape_line.length(), 7);

        auto background_blocks = std::count(background_line.begin(), background_line.end(), '#');
        auto shape_blocks = std::count(shape_line.begin(), shape_line.end(), '#');
        auto result = background_line;
        for (ll i = 0; i < shape_line.length(); i++) {
            if (shape_line.at(i) == '#') {
                result.at(i) = '#';
            }
        }
        ASSERT_EQ(result.length(), 7);
        return {result, std::count(result.begin(), result.end(), '#') != background_blocks + shape_blocks};
    }

    void print_field(const FieldT &f) {
        for (auto it = f.rbegin(); it != f.rend(); ++it) {
            std::cout << "|" << *it << "|" << std::endl;
        }
    }

    /*new field, overlaps*/
    std::tuple<FieldT, bool> merge_shape(const FieldT &background, const ShapeT &shape, ll shape_pos_bottom) {
        auto result = background;
        bool shape_overlaps = false;
        for (ll shape_line = 0; shape_line < shape.size(); shape_line++) {
            auto [current_line_with_background, line_overlaps] = merge_line(
                    background.at(shape_pos_bottom + shape_line), shape.at(shape_line));
            if (line_overlaps) {
                shape_overlaps = true;
            }
            result.at(shape_pos_bottom + shape_line) = current_line_with_background;
        }
        return {result, shape_overlaps};
    }

    const std::string empty_line = "       ";
    const std::string floor_line = "#######";

    void remove_empty_top(FieldT &field) {
        while (true) {
            auto &top = field.back();
            if (std::count(top.begin(), top.end(), '#') == 0) {
                field.pop_back();
            } else {
                break;
            }
        }
    }

    std::vector<std::string> add_shape(FieldT &field, ll shape_index) {
        // 3 empty lines between the highest brick and the new shape
        field.push_back(empty_line);
        field.push_back(empty_line);
        field.push_back(empty_line);
        // empty lines to place the new shape
        auto shape = shapes.at(shape_index);
        for (ll i = 0; i < shape.size(); i++) {
            field.push_back(empty_line);
        }
        return shape;
    }

    using SnapshotCommandsT = std::string;
    // 0: some upper lines of the field when the shape starts falling
    //    (initially I thought that it's sufficient to track the traveled background + 1,
    //     which might be > 60 lines. Later I had to extend it up to 100 additional lines.
    //     Otherwise, cycle detection returned too small false cycles.)
    // 1: the shape index
    // 2: sequence of commands received while shape was falling
    // 3: height increase after the shape felt
    using Snapshot = std::tuple<FieldT, ll, SnapshotCommandsT, ll>;

    std::optional<std::tuple<ll, ll, ll>> analyze_snapshots(const std::vector<Snapshot> &snapshots) {
        for (ll i = 0; i < snapshots.size() - 1; ++i) {
            auto &current_snapshot = snapshots.at(i);

            auto maybe_next = std::find(std::next(snapshots.begin(), i + 1), snapshots.end(), current_snapshot);
            if (maybe_next != snapshots.end()) {
                std::cout << "!found cycle " << i << " -> " << std::distance(snapshots.begin(), maybe_next)
                          << " total increase =  ";
                ll sum = 0;
                for (auto it = std::next(snapshots.begin(), i); it != maybe_next; ++it) {
                    sum += std::get<3>(*it);
                }
                std::cout << sum << std::endl;
                return std::tuple<ll, ll, ll>{i, std::distance(snapshots.begin(), maybe_next), sum};
            }
        }
        return std::nullopt;
    }

    ll solution(ll part) {
        std::vector<std::string> field = {floor_line};
        std::vector<Snapshot> snapshots;

        ll move_index = 0;
        ll shape_index = 0; // 5 figures
        ll total_shapes = 1;
        ll cycle = 0;
        auto current_shape = add_shape(field, shape_index);
        ll shape_pos_bottom = field.size() - current_shape.size();

        Snapshot snapshot;
        auto &[snapshot_field, snapshot_shape, snapshot_sequence, snapshot_inc] = snapshot;
        snapshot_shape = shape_index;
        snapshot_inc = 0;

        while (true) {
            // move left/right
            auto move_direction = input.at(move_index);
            snapshot_sequence.push_back(move_direction);

//        std::cout << "MOVE " << move_direction << " cycle " << cycle << std::endl;
            move_index++;
            if (move_index == input.length()) {
                move_index = 0;
            }

            auto [current_shape_after_shift, shift_possible] = shiftShape(current_shape, move_direction);
            if (shift_possible) {
                auto [maybe_background, overlaps] = merge_shape(field, current_shape_after_shift, shape_pos_bottom);
                shift_possible = (!overlaps);
//            std::cout << "AFTER SHIFT (" << shift_possible << ") " << move_direction << " cycle " << cycle << std::endl;
                if (shift_possible) {
                    current_shape = std::move(current_shape_after_shift);
                }
//            print_field(maybe_background);
            }

            bool fall_possible = true;

            auto [background_BEFORE_FALL, overlaps_BEFORE_FALL] = merge_shape(field, current_shape, shape_pos_bottom);
            assert(!overlaps_BEFORE_FALL);
            auto [background_AFTER_FALL, overlaps_AFTER_FALL] = merge_shape(field, current_shape, shape_pos_bottom - 1);
            if (overlaps_AFTER_FALL) {
                fall_possible = false;
            }


            if (fall_possible) {
                shape_pos_bottom--;
            }

//            std::cout << "AFTER FALL (" << fall_possible << ") " << move_direction << " cycle " << cycle << std::endl;
//            print_field((fall_possible) ? background_AFTER_FALL : background_BEFORE_FALL);

            // add the traveled line to the snapshot
            snapshot_field.insert(snapshot_field.begin(), field.at(shape_pos_bottom));

            if (!fall_possible) {
                field = std::move(background_BEFORE_FALL);
                shape_index++;
                if (shape_index == shapes.size()) {
                    shape_index = 0;
                }

                remove_empty_top(field);

                // part 1 - simple calculation
                if (total_shapes == 2022 && part == 1) {
                    return field.size() - 1;
                }

                // add 100 more lines below the one we stopped at to the snapshot
                ll additional_fields_added = 0;
                for (ll additional_fields = shape_pos_bottom - 1; additional_fields >= 0; additional_fields--) {
                    snapshot_field.insert(snapshot_field.begin(), field.at(additional_fields));
                    if (++additional_fields_added == 100) {
                        break;
                    }
                }

                snapshot_inc = (field.size() - 1) - snapshot_inc;
                snapshots.push_back(snapshot);
                if (part == 2) {
                    if (auto maybe_cycle = analyze_snapshots(snapshots)) {
                        auto [from, to, sum] = *maybe_cycle;
                        // We already happened to add the first element of a cycle.
                        // Finish the cycle to simplify the math.
                        ll current_height = (field.size() - 1);
                        for (ll finialize_cycle_index = from + 1; finialize_cycle_index < to; finialize_cycle_index++) {
                            total_shapes++;
                            current_height += std::get<3>(snapshots.at(finialize_cycle_index));
                        }

                        ll missing_shapes = 1000000000000 - total_shapes;
                        ll cycles_needed = missing_shapes / (to - from);
                        ll shapes_after_cycles_done = total_shapes + (cycles_needed * (to - from));
                        ll shapes_remainder = 1000000000000 - shapes_after_cycles_done;

                        ll height_after_cycles = current_height + sum * cycles_needed;
                        for (ll additional_figures = from;
                             additional_figures < from + shapes_remainder; ++additional_figures) {
                            height_after_cycles += std::get<3>(snapshots.at(additional_figures));
                        }

                        myprint(height_after_cycles);
                        return height_after_cycles;
                    }
                }

                snapshot_field.clear();
                snapshot_sequence.clear();
                snapshot_inc = (field.size() - 1);
                snapshot_shape = shape_index;

                total_shapes++;
                current_shape = add_shape(field, shape_index);
                shape_pos_bottom = field.size() - current_shape.size();
            }
            cycle++;
        }
    }
}

int _17() {
    ASSERT_EQ(solution(1), 3090);
    ASSERT_EQ(solution(2), 1530057803453);
    return 0;
}
