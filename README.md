# Discount Allocation System

## Objective
Distribute a fixed discount kitty among sales agents in a fair, explainable, and data-driven way.

## Inputs
- JSON file with siteKitty and salesAgents list
- Each agent has:
  - performanceScore (0–100)
  - seniorityMonths
  - targetAchievedPercent
  - activeClients

## Approach
Weighted score calculation:
- 40% performance
- 30% target achieved
- 20% seniority
- 10% clients

Allocated amount = (agent_score / total_scores) × siteKitty

Justification is given based on score bands.

## How to Run

1. Compile:
```
g++ -std=c++17 main.cpp allocator.cpp -o discount_allocator
```

2. Run:
```
./discount_allocator sample_input.json
```