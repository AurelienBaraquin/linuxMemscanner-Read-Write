/*
** EPITECH PROJECT, 2023
** cheatEngine
** File description:
** cheat
*/

#ifndef CHEAT_HPP_
#define CHEAT_HPP_

#include "std.h"
using namespace std;

static int prog_pid;
static vector<vector<pair<long, int>>> resultsHistory;
static int read_range = 0x1000000;

template <typename T>
vector<pair<long, T>> removeDuplicateAddresses(const vector<pair<long, T>>& addresses) {
    vector<pair<long, T>> uniqueAddresses;
    unordered_set<long> seenAddresses;

    for (const auto& address : addresses) {
        if (seenAddresses.find(address.first) == seenAddresses.end()) {
            uniqueAddresses.push_back(address);
            seenAddresses.insert(address.first);
        }
    }

    return uniqueAddresses;
}

template <typename T>
vector<pair<long, T>> updateAddress(vector<pair<long, T>> addrs);
template <typename T>
bool isTypeReadableInMemory(pid_t pid, long address);
template <typename T>
T readAddress(pid_t pid, long address);
template <typename T>
T convertBytesToValue(const char* bytes);

template <typename T>
vector<pair<long, T>> multiScanAddressSpace(pid_t pid, vector<long> addrs);
template <typename T>
vector<pair<long, T>> scanAddressSpace(pid_t pid, long addr, int max_null_values = 10000);

template <typename T>
bool writeValueToMemory(pid_t pid, long address, T value);

vector<long> getUsedMemorySpace(pid_t pid);

bool attachAndPause(pid_t pid);
void detach(pid_t pid);

void printHelp(void);
void printAddr(pair <long, int> addr);
void printAllAddr(vector<pair <long, int>> addrs);

#include "scan.hpp"
#include "write.hpp"
#include "read.hpp"

#include "format.hpp"
#include "comp.hpp"

#endif /* !CHEAT_HPP_ */
