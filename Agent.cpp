#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : coalitionId(), mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) 
{
    // You can change the implementation of the constructor, but not the signature!
   // mCoalition= Coalition m();
}

//copy constructor
Agent::Agent(const Agent& other): coalitionId(), mAgentId(other.mAgentId), mPartyId(other.mPartyId), 
                                    mSelectionPolicy(other.mSelectionPolicy->duplicate()) {}



void Agent::clear(){
    // if (mSelectionPolicy != nullptr){
    //     delete(mSelectionPolicy);
        mSelectionPolicy = nullptr;
//}

}

Agent& Agent::operator=(const Agent &other) // copy assignment operator
{

    if (this != &other){
        clear();
        coalitionId = other.coalitionId;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        *mSelectionPolicy = *other.mSelectionPolicy; 
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
        if (i != mPartyId && sim.getGraph().getEdgeWeight(mPartyId, i) > 0)
            if (sim.getParty(i).getState() != Joined){
                bool offered = false;
                for(const int agent: sim.getParty(i).offers){
                    if (sim.getParty(agent).coalitionId == sim.getParty(mPartyId).coalitionId)
                        offered = true;
                }
                if (!offered)
                    validParties.push_back(i);
            }
    }


    mSelectionPolicy->select(sim, sim.getAgentbyId(mAgentId));  
    if (sim.getParty(mPartyId).getState() == Waiting) 
        sim.getParty1(mPartyId).setState(CollectingOffers);
    
}