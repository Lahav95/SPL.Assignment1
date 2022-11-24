#include "Party.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include "Simulation.h"


Party::Party(int id, string name, int mandates, JoinPolicy *jp) : timer(), coalitionId(-1), offers({}), mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting){ }

//destructor
Party::~Party(){
    if(mJoinPolicy) delete mJoinPolicy;
}

//copy constructor
Party::Party(const Party& other): timer(other.timer), coalitionId(other.coalitionId), offers(other.offers),
            mId(other.mId), mName(other.mName),mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->duplicate()), mState(other.mState){}


//copy assignment operator
Party& Party::operator=(const Party& other){

    if (this != &other) { 
        timer = other.timer;
        coalitionId = other.coalitionId;
        offers = other.offers;
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        if(mJoinPolicy)
            delete mJoinPolicy;
            
        mJoinPolicy = other.mJoinPolicy->duplicate();
    }   
    return *this;

}

//move constructor
Party::Party(Party&& other):  timer(other.timer), coalitionId(other.coalitionId), offers(other.offers),
            mId(other.mId), mName(other.mName),mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState) {
    other.mJoinPolicy = nullptr;
}

//move assignment operator
Party& Party::operator=(Party&& other){

    timer = other.timer;
    coalitionId = other.coalitionId;
    offers = other.offers;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
   
    other.mJoinPolicy = nullptr;

    return *this;
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
        if (timer == 3){                   //join a coalition:
            
            int aToJoin= mJoinPolicy->Join(s, offers); //returns selected offer (agent)   //JoinPolicy
            Agent& temp = s.getAgentbyId(aToJoin);
            int coToJoin= temp.coalitionId;
            s.mCoalitions.at(coToJoin).addParty(*this , mId);  //add party to coalition  //Coalition
         
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
