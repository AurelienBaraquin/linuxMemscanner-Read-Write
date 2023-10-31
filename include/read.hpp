#include "cheat.hpp"

// Osef
template <typename T>
bool isTypeReadableInMemory(pid_t pid, long address) {
    if (address % sizeof(T) != 0) {
        return false;
    }

    if (!std::is_integral<T>::value) {
        return false;
    }

    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        return false;
    }

    waitpid(pid, NULL, 0);

    T value;
    long* target_address = reinterpret_cast<long*>(address);
    long value_read = ptrace(PTRACE_PEEKDATA, pid, target_address, NULL);
    memcpy(&value, &value_read, sizeof(T));

    ptrace(PTRACE_DETACH, pid, NULL, NULL);

    return true;
}

template <typename T>
T convertBytesToValue(const char* bytes) {
    T value = 0;
    for (size_t i = 0; i < sizeof(T); ++i) {
        value |= (static_cast<T>(bytes[i]) & 0xFF) << (i * 8);
    }
    return value;
}

template <typename T>
T readAddress(pid_t pid, long address) {
    T value;

    int data_size = sizeof(T);
    char bytes[data_size];
    for (int i = 0; i < data_size; i += sizeof(long)) {
        long* target_address = reinterpret_cast<long*>(address + i);
        long value_read = ptrace(PTRACE_PEEKDATA, pid, target_address, NULL);
        memcpy(bytes + i, &value_read, sizeof(long));
    }

    return convertBytesToValue<T>(bytes);
}

template <typename T>
vector<pair<long, T>> updateAddress(vector<pair<long, T>> addrs) {
    if (!attachAndPause(prog_pid)) {
        return {};
    }
    int pourcentage_max = addrs.size() / 100;
    vector<pair<long, T>> values;
    cout << "Updating " << addrs.size() << " addresses :" << endl;
    for (auto addr_value : addrs) {
        T value = readAddress<T>(prog_pid, addr_value.first);
        values.push_back(make_pair(addr_value.first, value));
    }
    cout << "Done." << endl;
    detach(prog_pid);
    return removeDuplicateAddresses(values);
}
