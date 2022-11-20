
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

Party SelectionPolicy::biggestMandate(Simulation &sim){

    vector<Party> connected;

    for (int i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != ) // compare it with party ID
            if (isValid(i, getPartyId())) // same ID as above
                connected.push_back(sim.getParty(i));

    int maxVal = 0;
    int i;
    
    for (i = 0; i < connected.size(); i++){
        if (connected[i].getMandates() > maxVal)
            maxVal = connected[i].getMandates();
    }

    return connected[i];
}

Party SelectionPolicy::biggestEdge(Simulation &sim){

    vector<Party> connected;

    for (int i = 0; i < sim.getGraph().getNumVertices(); i++)
        if (i != ) // compare it with party ID
            if (isValid(i, sim.getAgentbyId().)) // same ID as above
                connected.push_back(sim.getParty(i));

    int maxVal = 0;
    int i;
    
    for (i = 0; i < connected.size(); i++){
        if (sim.getGraph().getEdgeWeight() > maxVal) // insert both party's ID
            maxVal = sim.getGraph().getEdgeWeight();  // same IDs as above
    }

    return connected[i];
}

