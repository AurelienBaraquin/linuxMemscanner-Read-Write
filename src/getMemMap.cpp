#include "cheat.hpp"

vector<long> getUsedMemorySpace(pid_t pid) {
    vector<long> addresses;

    FILE* maps_file = fopen(("/proc/" + to_string(pid) + "/maps").c_str(), "r");

    if (maps_file == NULL) {
        perror("fopen");
        return addresses;
    }

    char* line = NULL;
    size_t len = 0;

    while (getline(&line, &len, maps_file) != -1) {
        char* token = strtok(line, " \t-");
        if (token != NULL) {
            addresses.push_back(strtol(token, NULL, 16));
        }
    }

    fclose(maps_file);

    if (line != NULL) {
        free(line);
    }

    return addresses;
}
