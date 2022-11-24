#include "SelectionPolicy.h"
#include "Simulation.h"
#include "vector"

using std::vector;

int MandatesSelectionPolicy::select(Simulation &sim, Agent agent, vector<int> validParties){

    int maxVal = 0;
    int maxParty = -1;
    const int agentId = agent.getId();
    for (int j: validParties)   //change to validparties size?  *maybe for each
        if (sim.getParty(j).getMandates() > maxVal){    // update max
           maxVal = sim.getParty(j).getMandates();
            maxParty = j;
        }

    sim.getParty1(maxParty).offers.push_back(agentId);  //add offer to selected party
    return maxParty;
}

SelectionPolicy* MandatesSelectionPolicy::duplicate(){
    return new MandatesSelectionPolicy(*this);
};


int EdgeWeightSelectionPolicy::select(Simulation &sim, Agent agent, vector<int> validParties){

    int maxVal = 0;
    int maxParty = validParties[0];      // ? optional party number one (maybe only)
    for (int i: validParties){
        int temp = sim.getGraph().getEdgeWeight(i, agent.getPartyId());
        if (temp > maxVal){     //update max
                maxVal = temp;
                maxParty = i;
            }
    }

    return maxParty;
}

SelectionPolicy* EdgeWeightSelectionPolicy::duplicate(){
    return new EdgeWeightSelectionPolicy(*this);
};