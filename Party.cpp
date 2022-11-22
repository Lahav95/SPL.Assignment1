#include "Party.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    timer=0;
    
}

int Party::getPartyId(){
    return mId;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if (getState() == CollectingOffers){
        if (timer<=2){
            timer++;
        }
        else{                   //join a coalition:
            
            int aToJoin= mJoinPolicy->Join(s, offers); //returns selected offer (agent)   //JoinPolicy
            Agent& temp = s.getAgentbyId(aToJoin);
            int coToJoin= temp.coalitionId;
            s.mCoalitions.at(coToJoin).addParty(*this , mId);  //add party to coalition  //Coalition
            
            // check all
         
            s.clone(aToJoin, mId);               //clone agent and update        //simulation
            
            setState(Joined);
        }    

    }
    else{   // waiting

    }
    
}

void Party::setCoalitionId(int id){
    coalitionId = id;
}


void Party:: addOffer(int agentId){
    offers.push_back(agentId);
}