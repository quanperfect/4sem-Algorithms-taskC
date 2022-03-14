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
            //std::cout << "here}0" << std::endl;
            std::vector<std::string> lastblockchanges = changes.back();
            //std::cout << "here}1" << std::endl;
            changes.pop_back();
            //std::cout << "here}2" << std::endl;
            while (!lastblockchanges.empty()) {
                //std::cout << "here}3" << std::endl;
                if (!variables.at(lastblockchanges.back()).empty()) {
                    variables.at(lastblockchanges.back()).pop_back();
                }
                //std::cout << "here}4" << std::endl;
                lastblockchanges.pop_back();
                //std::cout << "here}5" << std::endl;
            }
            //std::cout << "here}6" << std::endl;

        }
        else {
            std::string variableName;
            int variableValue = 0;
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '=') {
                    if (std::isdigit(line[i + 1])) {
                        variableName = line.substr(0, i);
                        variableValue = std::stoi(line.substr(i + 1, (line.length() - i - 1)));
                        //std::cout << "here-1" << std::endl;
                    }
                    else if (line[i + 1] == '-') {
                        variableName = line.substr(0, i);
                        variableValue = std::stoi(line.substr(i + 1, (line.length() - i - 1)));
                        //std::cout << "here0" << std::endl;
                    }
                    else {
                        variableName = line.substr(0, i);
                        std::string variableName2 = line.substr(i + 1, (line.length() - i - 1));
                        //std::map<std::string, std::vector<int>>::iterator it = variables.find(variableName);
                        if (variables.count(variableName2) == 0 || variables.at(variableName2).empty()) {
                            variableValue = 0;
                            //variables.insert(variableName, std::vector<int>())
                            //variables.insert(variableName, std::vector<int>());
                            //std::cout << "here1" << std::endl;
                        }
                        else {
                            //std::cout << "here2" << std::endl;
                            variableValue = variables.at(variableName2).back();
                        }
                        //std::cout << "here3" << std::endl;

                        printOut.push_back(variableValue);
                    }
                }
            }

            //std::cout << "variableName: " << variableName << " ; variableValue=" << variableValue << std::endl;
            changes.back().push_back(variableName);
            //std::cout << "here4" << std::endl;
            if (variables.count(variableName) == 0) {
                variables.insert({ variableName, std::vector<int>() });
                //duplicatecodefix
            }
            variables.at(variableName).push_back(variableValue);
            //std::cout << "here5" << std::endl;
        }
    }

    //std::cout << "here6" << std::endl;

    for (int print : printOut) {
        std::cout << print << std::endl;
    }

    return 0;
}

