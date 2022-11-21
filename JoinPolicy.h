#pragma once
#include <vector>

using std::vector;

class Agent;
class Simulation;
class Party;

class JoinPolicy {
    public:
        virtual ~JoinPolicy(){};
        virtual int Join(Simulation& sim, vector<int> offerList)=0;
    
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy();
        virtual ~MandatesJoinPolicy();
        virtual int Join(Simulation& sim, vector<int> offerList); 
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy();
        virtual ~LastOfferJoinPolicy();
        virtual int Join(Simulation &sim, vector<int> offerList);
};