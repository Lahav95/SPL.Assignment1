#pragma once

#include <vector>

using std:: vector;

class Coalition;
class Simulation;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

   // rule of 3
    Agent(const Agent& agent);  // copy constructor
    Agent& operator=(const Agent& other);  // copy assignment operator
    ~Agent();   // destructor

    // rule of 5
    Agent(Agent&& other);   // move constructor
    Agent& operator=(Agent&& other);    // move assignment operator

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    
    int coalitionId; 
    
    void setPartyId(int);
    void setId(int);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
