#include "cheat.hpp"

template <typename T>
bool writeValueToMemory(pid_t pid, long address, T value) {
    if (!attachAndPause(pid)) {
        return false;
    }

    int data_size = sizeof(T);
    for (int i = 0; i < data_size; i += sizeof(long)) {
        long* target_address = reinterpret_cast<long*>(address + i);
        long value_to_write;
        memcpy(&value_to_write, reinterpret_cast<char*>(&value) + i, sizeof(long));
        ptrace(PTRACE_POKEDATA, pid, target_address, value_to_write);
    }

    detach(pid);
    return true;
}