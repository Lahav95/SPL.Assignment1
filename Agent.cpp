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

int Agent::setPartyId(int id){
    mPartyId = id;
}

int Agent::setId(int id){
    mAgentId = id;
}

void Agent::step(Simulation &sim)
{
    mSelectionPolicy->select(sim, sim.getAgentbyId(mAgentId));  
    if (sim.getParty(mPartyId).getState() == Waiting) 
        sim.getParty1(mPartyId).setState(CollectingOffers);
    
}

Agent::Agent(const Agent& other) : mAgentId(other.mAgentId),            // copy constructor
 mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy)    
{

    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy; 

}

void Agent::clear(){
    if (mSelectionPolicy != nullptr){
        delete(mSelectionPolicy);
        mSelectionPolicy = nullptr;
    }

}

Agent& Agent::operator=(const Agent &other) // copy assignment operator
{

    if (this != &other){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        clear();
        *mSelectionPolicy = *other.mSelectionPolicy; 
    }

    return *this;
}

Agent::~Agent(){    // destructor

    clear();
}

Agent::Agent(Agent&& other) : mAgentId(other.mAgentId),                 // move constructor
 mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy){    

    other.mSelectionPolicy = nullptr;

}

Agent& Agent::operator=(Agent&& other){     // move assignment opeator

    if (this != &other){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = nullptr;
    }

    return *this;

}