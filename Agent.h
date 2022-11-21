#pragma once

#include <vector>

class Simulation;
class Coalition;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

    int coalitionId; //NNN
    int i=0;                    //NNN
    int& numOfMandates = i;     //NNN
    void setNumOfM(int);        //NNN
    void setCoalitionId(int); //?
    int getCoalitionId(); //?

    
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
