#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"


int MandatesJoinPolicy::Join(Simulation& sim, vector<int> offerList){
    int answerId = offerList[0];
    int coalitionId= sim.getAgentbyId(answerId).coalitionId;
    int maxMandates = sim.mCoalitions.at(coalitionId).numOfMandates;        //instead of numMandates of agent
    for(int a: offerList){
        int cId= sim.getAgentbyId(a).coalitionId;
        int mandates = sim.mCoalitions.at(cId).numOfMandates;        //instead of numMandates of agent
        if (mandates > maxMandates){
            maxMandates = mandates;
            answerId = a;
        }
    }
    return answerId;
}

JoinPolicy* MandatesJoinPolicy::duplicate(){
    return new MandatesJoinPolicy(*this);
}

int LastOfferJoinPolicy::Join(Simulation& sim, vector<int> offerList){

    int a = offerList.back() ;
    return a;
}

JoinPolicy* LastOfferJoinPolicy::duplicate(){
    return new LastOfferJoinPolicy(*this);
}