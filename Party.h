#pragma once
#include <string>
#include <vector>


using std::string;
using std::vector;


class Agent;
class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int timer;
    int coalitionId = -1;
    void setCoalitionId(int);
    vector <int> offers;
    void addOffer(int agentId);
    int getPartyId();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
};