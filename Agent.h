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

    int setPartyId(int);
    int setId(int);
    int coalitionId; 

    void clear();

    // rule of 3
    Agent(const Agent& other);  // copy constructor
    Agent& operator=(const Agent& other);  // copy assignment operator
    ~Agent();   // destructor

    // rule of 5
    Agent(Agent&& other);   // move constructor
    Agent& operator=(Agent&& other);    // move assignment operator


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
