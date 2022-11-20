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

    void join();

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 

    void join();

};