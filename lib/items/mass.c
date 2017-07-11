/*    /lib/props/mass.c
 *    From the Dead Souls V Object Library
 *    Handles object massiveness and weight
 *    Created by Descartes of Borg 970101
 *    Version: @(#) mass.c 1.1@(#)
 *    Last modified: 97/01/01
 */

#include <config.h>

private int Mass = 0;

int AddMass(int x) {
    int cmass = Mass;
    if( Mass += x <= 0) {
        Mass = 0;
        x = -cmass;
    }
      else { Mass += x; }
    if( environment() ) {
	environment()->AddCarriedMass(x);
    }
    return Mass;
}
 
int GetMass() {
    return Mass;
}

int SetMass(int x) {
    if( x < 0 ) {
	x = 0;
    }
    return (Mass = x);
}
 
string array GetSave() {
    return ({ "Mass" });
}

int GetWeight() {
    float h;
 
    if( environment() ) {
	h = environment()->GetGravity();
    }
    else {
	h = DEFAULT_GRAVITY;
    }
    return to_int(GetMass() * h);
}
 
