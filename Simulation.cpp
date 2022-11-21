#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
  for (int i = 0; i<mGraph.getNumVertices(); i++){
    getParty1(i).step(*this); 
  }

  for (Agent agent: mAgents){
    agent.step(*this);
  }
}

bool Simulation::shouldTerminate() const
{
    bool toEnd= true;

//  for loop of coalition mandates

    for (int i=0; i< mGraph.getNumVertices(); i++){
        if (getParty(i).getState() != Joined)
            toEnd = false;
    }
    return toEnd;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty1(int partyId) 
{
    return mGraph.getParty2(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}

// Agent &Simulation::getAgentbyId(int agentId)       // Not necessarily needed
// {

//     for(Agent agent: mAgents)
//         if (agent.getId() == agentId)
//             return agent;

// }