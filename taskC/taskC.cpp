#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>


int main()
{
    std::map<std::string, std::vector<int>> variables;
    std::vector< std::vector<std::string> > changes;
    changes.push_back(std::vector<std::string>());

    std::vector<int> printOut;

    std::string line;
    while (std::cin >> line) {
        if (line == "{") {
            changes.push_back(std::vector<std::string>());
        }
        else if (line == "}") {
            std::vector<std::string> lastblockchanges = changes.back();
            changes.pop_back();
            while (!lastblockchanges.empty()) {
                if (!variables.at(lastblockchanges.back()).empty()) {
                    variables.at(lastblockchanges.back()).pop_back();
                }
                lastblockchanges.pop_back();
            }

        }
        else {
            std::string variableName;
            int variableValue = 0;
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '=') {
                    if (std::isdigit(line[i + 1])) {
                        variableName = line.substr(0, i);
                        variableValue = std::stoi(line.substr(i + 1, (line.length() - i - 1)));
                    }
                    else if (line[i + 1] == '-') {
                        variableName = line.substr(0, i);
                        variableValue = std::stoi(line.substr(i + 1, (line.length() - i - 1)));
                    }
                    else {
                        variableName = line.substr(0, i);
                        std::string variableName2 = line.substr(i + 1, (line.length() - i - 1));
                        //std::map<std::string, std::vector<int>>::iterator it = variables.find(variableName);
                        if (variables.count(variableName2) == 0 || variables.at(variableName2).empty()) {
                            variableValue = 0;
                            //variables.insert(variableName, std::vector<int>())
                            //variables.insert(variableName, std::vector<int>());
                        }
                        else {
                            variableValue = variables.at(variableName2).back();
                        }

                        printOut.push_back(variableValue);
                    }
                }
            }

            changes.back().push_back(variableName);
            if (variables.count(variableName) == 0) {
                variables.insert({ variableName, std::vector<int>() });
                //duplicatecodefix
            }
            variables.at(variableName).push_back(variableValue);
        }
    }

    for (int print : printOut) {
        std::cout << print << std::endl;
    }

    return 0;
}

