#include "SelectionPolicy.h"
#include "Simulation.h"
#include "vector"

using std::vector;

void MandatesSelectionPolicy::select(Simulation &sim, Agent agent, vector<int> validParties){

    int maxVal = 0;
    const int agentId = agent.getId();

    for (int i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != agent.getPartyId()) 
            if (sim.getParty(i).getMandates() > maxVal)
                maxVal = sim.getParty(i).getMandates();

    sim.getParty1(agent.getId()).offers.push_back(agentId);

}

SelectionPolicy* MandatesSelectionPolicy::duplicate(){
    return new MandatesSelectionPolicy(*this);
};


void EdgeWeightSelectionPolicy::select(Simulation &sim, Agent agent, vector<int> validParties){

    int maxVal = 0;
    int i;
    const int agentId = agent.getId();

    for (i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != agent.getPartyId())  
            if (sim.getGraph().getEdgeWeight(i, agent.getPartyId()) > maxVal)
                maxVal = sim.getGraph().getEdgeWeight(i, agent.getPartyId());

    sim.getParty1(agent.getId()).offers.push_back(agentId); 
}

SelectionPolicy* EdgeWeightSelectionPolicy::duplicate(){
    return new EdgeWeightSelectionPolicy(*this);
};