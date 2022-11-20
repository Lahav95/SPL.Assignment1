#pragma once

class SelectionPolicy {

public:

    void step(Simulation &);
    bool isValid(int v1, int v2, Simulation &);
    Party biggestMandate(Simulation &);
    Party biggestEdge(Simulation &);
    virtual void join() = 0;
        
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 

    //call biggestMandate func to select the 

    void join();

    //add self to offers vector

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 

    //call biggestEdge func to select the

    void join();

    //add self to offers vector

};