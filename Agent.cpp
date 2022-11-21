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
    mSelectionPolicy->select(sim, sim.getAgentbyId(mAgentId));  
    if (sim.getParty(mPartyId).getState() == Waiting) 
        sim.getParty1(mPartyId).setState(CollectingOffers);
    
}

void Agent:: setCoalitionId(int id){
    coalitionId=id;
}

int Agent:: getCoalitionId(){
    return coalitionId;
}

