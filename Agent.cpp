#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // select party ()
    // add self to offers vector (offer to join)
    if (sim.getParty().getState() == Waiting) //insert party ID 
        sim.getParty().setState(CollectingOffers);
    
}

// void Agent::select(Agent agent)    // Select a policy
// {

//     agent.mSelectionPolicy



// }

// Agent::Agent(const Agent &other){
//     mSelectionPolicy = other.mSelectionPolicy;
//     mAgentId = other.mAgentId;
//     mPartyId = other.mPartyId;
// }

