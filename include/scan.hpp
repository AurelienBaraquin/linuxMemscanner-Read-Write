#include "cheat.hpp"

template <typename T>
vector<pair<long, T>> scanAddressSpace(pid_t pid, long addr, int max_null_values) {
    vector<pair<long, T>> values;
    int nb_null_values = 0;

    // if (!isTypeReadableInMemory<T>(pid, addr)) {
    //     return values;
    // }
    T value = readAddress<T>(pid, addr);

    int nb_read_values = 0;

    int pourcentage_max = read_range / 100;

    while (value != -1) {
        values.push_back(make_pair(addr, value));
        addr += sizeof(T);
        value = readAddress<T>(pid, addr);

        nb_read_values++;

        if (nb_read_values % pourcentage_max == 0)
            cout << "-" << flush;

        if (value == 0)
            nb_null_values++;
        else
            nb_null_values = 0;
        if (nb_null_values > max_null_values || nb_read_values >= read_range)
            break;
    }
    return values;
}

template <typename T>
vector<pair<long, T>> multiScanAddressSpace(pid_t pid, vector<long> addrs) {
    if (!attachAndPause(prog_pid)) {
        return {};
    }
    vector<pair<long, T>> values;

    for (auto addr : addrs) {
        cout << ": " << hex << addr << " " << flush;
        vector<pair<long, T>> values_at_addr = scanAddressSpace<T>(pid, addr);
        values.insert(values.end(), values_at_addr.begin(), values_at_addr.end());
        cout << " | " << dec << values_at_addr.size() << " values" << endl;
    }

    detach(prog_pid);
    return values;
}
