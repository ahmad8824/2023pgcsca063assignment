#include "allocator.h"
#include <numeric>

std::vector<AllocationResult> allocateDiscounts(double totalKitty, const std::vector<SalesAgent>& agents) {
    std::vector<AllocationResult> results;
    std::vector<double> scores;

    for (const auto& agent : agents) {
        double score =
            agent.performanceScore * 0.4 +
            agent.targetAchievedPercent * 0.3 +
            agent.seniorityMonths * 0.2 +
            agent.activeClients * 0.1;
        scores.push_back(score);
    }

    double totalScore = std::accumulate(scores.begin(), scores.end(), 0.0);

    for (size_t i = 0; i < agents.size(); ++i) {
        double share = (totalScore > 0) ? (scores[i] / totalScore) * totalKitty : 0;

        std::string justification;
        if (scores[i] > 80) justification = "High performance and long-term contribution";
        else if (scores[i] > 60) justification = "Moderate performance";
        else justification = "Needs support";

        results.push_back({agents[i].id, static_cast<int>(share + 0.5), justification});
    }

    return results;
}