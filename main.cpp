#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "allocator.h"

using json = nlohmann::json;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file.json>\n";
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        std::cerr << "Cannot open file: " << argv[1] << "\n";
        return 1;
    }

    json inputJson;
    inFile >> inputJson;

    double kitty = inputJson["siteKitty"];
    std::vector<SalesAgent> agents;

    for (auto& item : inputJson["salesAgents"]) {
        SalesAgent agent;
        agent.id = item["id"];
        agent.performanceScore = item["performanceScore"];
        agent.seniorityMonths = item["seniorityMonths"];
        agent.targetAchievedPercent = item["targetAchievedPercent"];
        agent.activeClients = item["activeClients"];
        agents.push_back(agent);
    }

    auto results = allocateDiscounts(kitty, agents);

    json output;
    output["allocations"] = json::array();
    for (auto& r : results) {
        output["allocations"].push_back({
            {"id", r.id},
            {"assignedDiscount", r.assignedDiscount},
            {"justification", r.justification}
        });
    }

    std::cout << output.dump(4) << std::endl;
    return 0;
}