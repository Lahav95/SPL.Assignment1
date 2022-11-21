
#include "SelectionPolicy.h"
#include "Simulation.h"

using std::vector;


bool SelectionPolicy::isValid(int v1, int v2, Simulation &sim){

    bool valid = true;
    if(sim.getGraph().getEdgeWeight(v1, v2) == 0 || sim.getParty(v1).getState() == Joined) 
    // add || if another agent from the coaliion
    // already offered this party to join

    return valid;
}

MandatesSelectionPolicy::MandatesSelectionPolicy(){};
MandatesSelectionPolicy::~MandatesSelectionPolicy(){};


Party MandatesSelectionPolicy::select(Simulation &sim, Agent agent){

    vector<Party> connected;

    for (int i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != agent.getPartyId()) 
            if (isValid(i, agent.getPartyId(), sim)) 
                connected.push_back(sim.getParty(i));

    int maxVal = 0;
    int i;
    
    for (i = 0; i < connected.size(); i++){
        if (connected[i].getMandates() > maxVal)
            maxVal = connected[i].getMandates();
    }

    return connected[i];
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){};
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){};

Party SelectionPolicy::select(Simulation &sim, Agent agent){

    vector<Party> connected;

    int maxVal = 0;
    int i;

    for (i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != agent.getPartyId()) 
            if (isValid(i, agent.getPartyId(), sim)) 
                if (sim.getGraph().getEdgeWeight(i, agent.getPartyId()) > maxVal)
                    maxVal = sim.getGraph().getEdgeWeight(i, agent.getPartyId());

    return sim.getParty(i); 
}

