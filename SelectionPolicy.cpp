
#include "SelectionPolicy.h"
#include "Simulation.h"
#include "vector"

using std::vector;


bool SelectionPolicy::isValid(int offeringParty, int recievingParty, Simulation &sim){

    bool offered = false;
    for(const int agent: sim.getParty(recievingParty).offers)
    {
        if (sim.getParty(agent).coalitionId == sim.getParty(offeringParty).coalitionId)
            offered = true;
    }
    bool valid = true;
    if(sim.getGraph().getEdgeWeight(offeringParty, recievingParty) == 0 
        || sim.getParty(offeringParty).getState() == Joined || offered) 
        valid = false;

    return valid;
}

MandatesSelectionPolicy::MandatesSelectionPolicy(){};
MandatesSelectionPolicy::~MandatesSelectionPolicy(){};


void MandatesSelectionPolicy::select(Simulation &sim, Agent agent){

    int maxVal = 0;
    int i;
    const int agentId = agent.getId();

    for (int i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != agent.getPartyId()) 
            if (isValid(i, agent.getPartyId(), sim)) 
                if (sim.getParty(i).getMandates() > maxVal)
                     maxVal = sim.getParty(i).getMandates();

    sim.getParty1(agent.getId()).offers.push_back(agentId);

}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){};
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){};

void EdgeWeightSelectionPolicy::select(Simulation &sim, Agent agent){

    int maxVal = 0;
    int i;
    const int agentId = agent.getId();

    for (i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != agent.getPartyId()) 
            if (isValid(i, agent.getPartyId(), sim)) 
                if (sim.getGraph().getEdgeWeight(i, agent.getPartyId()) > maxVal)
                    maxVal = sim.getGraph().getEdgeWeight(i, agent.getPartyId());

    sim.getParty1(agent.getId()).offers.push_back(agentId); 
}

