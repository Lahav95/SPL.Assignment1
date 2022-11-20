#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void select(Agent agent);


    
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
