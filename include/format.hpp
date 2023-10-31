/*
** EPITECH PROJECT, 2023
** cheatEngine
** File description:
** format
*/

#ifndef FORMAT_HPP_
#define FORMAT_HPP_

#include "cheat.hpp"

namespace FORMAT_ADDR {
    template <typename T>
    vector<pair<long, T>> equalTo(vector<pair<long, T>> input_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (addr_value.second == value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> greaterThan(vector<pair<long, T>> input_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) > value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> lessThan(vector<pair<long, T>> input_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) < value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> greaterThanOrEqualTo(vector<pair<long, T>> input_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) >= value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> lessThanOrEqualTo(vector<pair<long, T>> input_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) <= value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> notEqualTo(vector<pair<long, T>> input_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) != value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> between(vector<pair<long, T>> input_values, T min_value, T max_value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) >= min_value && static_cast<T>(addr_value.second) <= max_value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> notBetween(vector<pair<long, T>> input_values, T min_value, T max_value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : input_values) {
            if (static_cast<T>(addr_value.second) < min_value || static_cast<T>(addr_value.second) > max_value) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }
}


#endif /* !FORMAT_HPP_ */
