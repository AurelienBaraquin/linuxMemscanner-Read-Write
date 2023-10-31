/*
** EPITECH PROJECT, 2023
** cheatEngine
** File description:
** comp
*/

#ifndef COMP_HPP_
#define COMP_HPP_

#include "cheat.hpp"

namespace COMP_ADDR {
    template <typename T>
    vector<pair<long, T>> greater(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second) > static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> less(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second) < static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> equal(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second) == static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> notEqual(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second) != static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> greaterOrEqual(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second) >= static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> lessOrEqual(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second) <= static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> add(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second + value) == static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }

    template <typename T>
    vector<pair<long, T>> sub(vector<pair<long, T>> new_values, vector<pair<long, T>> old_values, T value) {
        vector<pair<long, T>> output_values;
        for (auto addr_value : new_values) {
            if (static_cast<T>(addr_value.second - value) == static_cast<T>(old_values[0].second)) {
                output_values.push_back(addr_value);
            }
        }
        return output_values;
    }
}

#endif /* !COMP_HPP_ */
