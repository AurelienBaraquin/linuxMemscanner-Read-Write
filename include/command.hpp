/*
** EPITECH PROJECT, 2023
** cheatEngine
** File description:
** command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "cheat.hpp"


// commande pause a faire, jai mis les fonction là mais je sais pas si elle marche
// TODO
void interruptProcess(pid_t pid) {
    if (ptrace(PTRACE_INTERRUPT, pid, NULL, NULL) == -1) {
        perror("ptrace(PTRACE_INTERRUPT)");
    }
}

// TODO
void resumeProcess(pid_t pid) {
    if (ptrace(PTRACE_CONT, pid, NULL, NULL) == -1) {
        perror("ptrace(PTRACE_CONT)");
    }
}

namespace COMMAND {
    enum class C_ID {
        EQUAL_TO,
        GREATER_THAN,
        LESS_THAN,
        GREATER_THAN_OR_EQUAL_TO,
        LESS_THAN_OR_EQUAL_TO,
        NOT_EQUAL_TO,
        EQUAL_TO_NEW,
        RANGE,
        RANGE_START,
        RANGE_END,
        EQUAL,
        GREATER,
        LESS,
        GREATER_OR_EQUAL,
        LESS_OR_EQUAL,
        NOT_EQUAL,
        ADD,
        SUB,
        SHOW,
        PID,
        EXIT,
        HELP,
        CLEAR,
        SCAN,
        SCAND,
        RESET,
        SET,
        SETALL,
        TYPE,
        MATCH,
        MAX_READ,
        BACK,
        PAUSE,
        UNKNOWN,
    };

    // X is a parameter
    const unordered_map<C_ID, string> cmd = {
        {C_ID::EQUAL_TO, "=X"},
        {C_ID::GREATER_THAN, ">X"},
        {C_ID::LESS_THAN, "<X"},
        {C_ID::GREATER_THAN_OR_EQUAL_TO, ">=X"},
        {C_ID::LESS_THAN_OR_EQUAL_TO, "<=X"},
        {C_ID::NOT_EQUAL_TO, "!=X"},
        {C_ID::EQUAL_TO_NEW, "X"},
        {C_ID::RANGE, "X..X"},
        {C_ID::RANGE_START, "X.."},
        {C_ID::RANGE_END, "..X"},
        {C_ID::EQUAL, "="},
        {C_ID::GREATER, ">"},
        {C_ID::LESS, "<"},
        {C_ID::GREATER_OR_EQUAL, ">="},
        {C_ID::LESS_OR_EQUAL, "<="},
        {C_ID::NOT_EQUAL, "!="},
        {C_ID::ADD, "+X"},
        {C_ID::SUB, "-X"},
        {C_ID::SHOW, "show"}, // show all addresses and there values
        {C_ID::PID, "pidX"}, // set pid
        {C_ID::EXIT, "exit"},
        {C_ID::HELP, "help"},
        {C_ID::CLEAR, "clear"}, // clear screen
        {C_ID::SCAN, "scan"}, // scan memory
        {C_ID::SCAND, "scand"}, // scan dynamic memory
        {C_ID::RESET, "reset"}, // reset addresses
        {C_ID::SET, "setX"}, // set all addresses to value
        {C_ID::TYPE, "typeX"}, // type = nb byte : 16, 32, 64 for short, int, long
        {C_ID::MATCH, "match"}, // display number of match
        {C_ID::MAX_READ, "rangeX"}, // set max read
        {C_ID::BACK, "back"}, // go back to previous results
        {C_ID::PAUSE, "pause"}, // pause
    };

    C_ID getOpCommand(string command) {
        regex numberRegex("\\d+");
        string commandX = regex_replace(command, numberRegex, "X");
        if (commandX == "X")
            return C_ID::EQUAL_TO_NEW;
        for (auto& c : cmd) {
            if (c.second == commandX)
                return c.first;
        }
        return C_ID::UNKNOWN;
    }

    const vector<C_ID> mustrMatch = {
        C_ID::EQUAL_TO,
        C_ID::GREATER_THAN,
        C_ID::LESS_THAN,
        C_ID::GREATER_THAN_OR_EQUAL_TO,
        C_ID::LESS_THAN_OR_EQUAL_TO,
        C_ID::NOT_EQUAL_TO,
        C_ID::EQUAL_TO_NEW,
        C_ID::RANGE,
        C_ID::RANGE_START,
        C_ID::RANGE_END,
        C_ID::EQUAL,
        C_ID::GREATER,
        C_ID::LESS,
        C_ID::GREATER_OR_EQUAL,
        C_ID::LESS_OR_EQUAL,
        C_ID::NOT_EQUAL,
        C_ID::ADD,
        C_ID::SUB,
        C_ID::SET,
        C_ID::SCAN,
        C_ID::SCAND,
        C_ID::RESET,
        C_ID::MATCH,
        C_ID::BACK,
    };

    namespace EXEC {
        void rMatch(vector<pair<long, int>> values, bool push = true) {
            if (push)
                resultsHistory.push_back(values);
            cout << "Match : " << values.size() << endl;
        }

        template <typename T>
        vector<pair<long, T>> executeCommand(C_ID cmd_type, string command, vector<pair<long, T>> values) {
            vector<long> address;
            static int paused = -1;
            if (values.empty()) {
                goto shell;
            }
            switch (cmd_type) {
                case C_ID::EQUAL_TO:
                    return FORMAT_ADDR::equalTo<T>(values, stoi(command.substr(1)));
                case C_ID::GREATER_THAN:
                    return FORMAT_ADDR::greaterThan<T>(values, stoi(command.substr(1)));
                case C_ID::LESS_THAN:
                    return FORMAT_ADDR::lessThan<T>(values, stoi(command.substr(1)));
                case C_ID::GREATER_THAN_OR_EQUAL_TO:
                    return FORMAT_ADDR::greaterThanOrEqualTo<T>(values, stoi(command.substr(2)));
                case C_ID::LESS_THAN_OR_EQUAL_TO:
                    return FORMAT_ADDR::lessThanOrEqualTo<T>(values, stoi(command.substr(2)));
                case C_ID::NOT_EQUAL_TO:
                    return FORMAT_ADDR::notEqualTo<T>(values, stoi(command.substr(2)));
                case C_ID::RANGE:
                    return FORMAT_ADDR::between<T>(values, stoi(command.substr(0, command.find(".."))), stoi(command.substr(command.find("..") + 2)));
                case C_ID::RANGE_START:
                    return FORMAT_ADDR::greaterThanOrEqualTo<T>(values, stoi(command.substr(0, command.find(".."))));
                case C_ID::RANGE_END:
                    return FORMAT_ADDR::lessThanOrEqualTo<T>(values, stoi(command.substr(command.find("..") + 2)));

                case C_ID::EQUAL_TO_NEW:
                    return FORMAT_ADDR::equalTo<T>(updateAddress<T>(values), stoi(command));
                case C_ID::EQUAL:
                    return COMP_ADDR::equal<T>(updateAddress<T>(values), values);
                case C_ID::GREATER:
                    return COMP_ADDR::greater<T>(updateAddress<T>(values), values);
                case C_ID::LESS:
                    return COMP_ADDR::less<T>(updateAddress<T>(values), values);
                case C_ID::GREATER_OR_EQUAL:
                    return COMP_ADDR::greaterOrEqual<T>(updateAddress<T>(values), values);
                case C_ID::LESS_OR_EQUAL:
                    return COMP_ADDR::lessOrEqual<T>(updateAddress<T>(values), values);
                case C_ID::NOT_EQUAL:
                    return COMP_ADDR::notEqual<T>(updateAddress<T>(values), values);
                case C_ID::ADD:
                    return COMP_ADDR::add<T>(updateAddress<T>(values), values, stoi(command.substr(1)));
                case C_ID::SUB:
                    return COMP_ADDR::sub<T>(updateAddress<T>(values), values, stoi(command.substr(1)));
                default:
                    break;
            }

            shell:
            switch (cmd_type) {
                case C_ID::SHOW:
                    printAllAddr(values);
                    return values;
                case C_ID::PID:
                    prog_pid = stoi(command.substr(3));
                    return values;
                case C_ID::EXIT:
                    cout << "Bye" << endl;
                    exit(0);
                case C_ID::HELP:
                    printHelp();
                    return values;
                case C_ID::CLEAR:
                    system("clear");
                    return values;
                case C_ID::SCAN:
                    return multiScanAddressSpace<T>(prog_pid, getUsedMemorySpace(prog_pid));
                case C_ID::SCAND:
                    for (auto addr : getUsedMemorySpace(prog_pid))
                        if (addr < 0x7f0000000000)
                            address.push_back(addr);
                    return multiScanAddressSpace<T>(prog_pid, address);
                case C_ID::RESET:
                    return multiScanAddressSpace<T>(prog_pid, getUsedMemorySpace(prog_pid));
                case C_ID::SET:
                    cout << "Writing " << stoi(command.substr(3)) << " to " << values.size() << " addresses" << endl;
                    for (auto& addr : values)
                        writeValueToMemory<T>(prog_pid, addr.first, stoi(command.substr(3)));
                    cout << "Done." << endl;
                    return values;
                // case C_ID::TYPE:
                //     type = stoi(command.substr(4));
                case C_ID::MATCH:
                    return values;
                case C_ID::MAX_READ:
                    read_range = stoi(command.substr(5));
                    if (read_range < 100) {
                        cout << "Range must be greater than 100" << endl;
                        read_range = 100;
                    }
                    cout << "Range set to " << read_range << endl;
                    return values;
                case C_ID::BACK:
                    if (resultsHistory.size() > 1) {
                        resultsHistory.pop_back();
                        return resultsHistory.back();
                    } else {
                        cout << "No previous results" << endl;
                    }
                    return values;
                case C_ID::PAUSE:
                    paused *= -1;
                    if (paused == 1) {
                        cout << "Paused" << endl;
                        interruptProcess(prog_pid);
                    } else {
                        cout << "Unpaused" << endl;
                        resumeProcess(prog_pid);
                    }
                    return values;
                default:
                    break;
            }
            cout << "Unknown command" << flush << endl;
            return {};
        }
    }
}

#endif /* !COMMAND_HPP_ */
