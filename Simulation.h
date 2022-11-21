#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Party &getParty1(int partyId);
    Agent &getAgentbyId(int agentId);   // Not necessarily needed
    void addParty(int coalitionId,int partyId);
     void addCoalition(); // initialize coalitions list      //NNN
    vector<vector<int>> partiesByCoalitions;
    vector<Coalition> mCoalitions;
    


private:
    Graph mGraph;
    vector<Agent> mAgents;
};