#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"



Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : coalitionId(-1), mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) { }

//copy constructor
Agent::Agent(const Agent& other): coalitionId(other.coalitionId), mAgentId(other.mAgentId), mPartyId(other.mPartyId), 
                                    mSelectionPolicy(other.mSelectionPolicy->duplicate()) {}


Agent& Agent::operator=(const Agent &other) // copy assignment operator
{

    if (this != &other){
        if(mSelectionPolicy)
            delete mSelectionPolicy;
        coalitionId = other.coalitionId;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->duplicate(); 
    }

    return *this;
}

Agent::~Agent(){    // destructor

    if(mSelectionPolicy) delete mSelectionPolicy;
}

Agent::Agent(Agent&& other) : coalitionId(other.coalitionId), mAgentId(other.mAgentId),                 // move constructor
 mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy){    

    other.mSelectionPolicy = nullptr;

}

Agent& Agent::operator=(Agent&& other){     // move assignment opeator

    if (this != &other){
        coalitionId = other.coalitionId;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->duplicate();
        other.mSelectionPolicy = nullptr;
    }

    return *this;

}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent:: setPartyId(int id){
    mPartyId = id;
}

void Agent:: setId(int id){
    mAgentId = id;
}


void Agent::step(Simulation &sim)
{
     vector<int> validParties; 
    for (int i = 0; i < sim.getGraph().getNumVertices(); i++){
        bool offered = true;
        if (i != mPartyId && sim.getGraph().getEdgeWeight(mPartyId, i) > 0)     // not this & connected
            if (sim.getParty(i).getState() != Joined){                              //not joined
                for(int agent: sim.getParty(i).offers){
                    if (sim.getAgentbyId(agent).coalitionId == (*this).coalitionId)    // offered by the same coalition
                        offered = false;
                }
            
                if (offered)
                    validParties.push_back(i);  // all checked, optional party
            }
    }

    if(!validParties.empty()){      // optional party exist
        int i = mSelectionPolicy->select(sim, sim.getAgentbyId(mAgentId), validParties);  // return selected party id & add offer to it
        sim.getParty1(i).addOffer(mAgentId);
        if (sim.getParty(i).getState() == Waiting) 
            sim.getParty1(i).setState(CollectingOffers);    // update party state
    }
}       
