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

    Party(const Party &other);
    Party &operator=(const Party &other);
    ~Party();
    Party(Party&& other);
    Party& operator=(Party&& other);
   void clear();

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;


    int timer;

    int coalitionId;
    void setCoalitionId(int);
    int getPartyId();

    vector <int> offers;
    void addOffer(int agentId);
    

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
};