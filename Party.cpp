#include "Party.h"
#include "Agent.h"
#include "JoinPolicy.h"

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
        else{
            int aToJoin;
            mJoinPolicy->Join(s,offers);
            aToJoin= mJoinPolicy->Join(s, offers);
            setState(Joined);
            //clone
        }    

    }
    else{   // waiting

    }
    
}

void Party::setCoalitionId(int id){
    coalitionId = id;
}

//void Party::clone(){}

void Party:: addOffer(int agentId){
    offers.push_back(agentId);
}