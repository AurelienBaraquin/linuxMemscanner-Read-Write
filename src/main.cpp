#include "cheat.hpp"
#include "command.hpp"

int main(int ac, char** av) {
    if (ac > 1)
        prog_pid = atoi(av[1]);

    cout << "Tap 'help' to see all commands" << endl;

    vector<pair<long, int>> values;

    string input;

    while (1) {
        cout << "> ";
        getline(cin, input);
        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        COMMAND::C_ID cmd_type = COMMAND::getOpCommand(input);
        vector<pair<long, int>> r = COMMAND::EXEC::executeCommand<int>(cmd_type, input, values);

        input.clear();

        if (r.empty())
            continue;

        values = r;
        if (find(COMMAND::mustrMatch.begin(), COMMAND::mustrMatch.end(), cmd_type) != COMMAND::mustrMatch.end()) {
            if (resultsHistory.empty())
                COMMAND::EXEC::rMatch(values);
            else
                COMMAND::EXEC::rMatch(values, resultsHistory.back() != values ? true : false);
        }
    }

    return 0;
}
