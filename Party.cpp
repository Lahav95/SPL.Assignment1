#include "Party.h"
#include "Agent.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    timer=0;
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
            // joinpolicy
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