#pragma once
#include <vector>

using std::vector;

class Agent;
class Simulation;
class Party;

class JoinPolicy {
    public:
        virtual ~JoinPolicy()=default;
        virtual int Join(Simulation& sim, vector<int> offerList)=0;

        virtual JoinPolicy* duplicate()=0;
    
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual int Join(Simulation& sim, vector<int> offerList); 
        virtual JoinPolicy* duplicate();
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual int Join(Simulation &sim, vector<int> offerList);
        virtual JoinPolicy* duplicate();

};