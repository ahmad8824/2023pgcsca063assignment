#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <string>
#include <vector>

struct SalesAgent {
    std::string id;
    int performanceScore;
    int seniorityMonths;
    int targetAchievedPercent;
    int activeClients;
};

struct AllocationResult {
    std::string id;
    double assignedDiscount;
    std::string justification;
};

std::vector<AllocationResult> allocateDiscounts(double totalKitty, const std::vector<SalesAgent>& agents);

#endif