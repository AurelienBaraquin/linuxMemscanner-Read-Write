#include "cheat.hpp"

// Attache au processus cible et attend qu'il soit en pause
bool attachAndPause(pid_t pid) {
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        perror("ptrace(PTRACE_ATTACH)");
        return false;
    }

    waitpid(pid, NULL, 0);
    return true;
}

// Détache du processus cible
void detach(pid_t pid) {
    ptrace(PTRACE_DETACH, pid, NULL, NULL);
}
