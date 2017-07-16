//coded by Syra 8/97

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("gelfling child");
    SetId( ({"gelfling child","boy","youth","child" }) ); 
    SetAdjectives( ({"gelfling"}) );
    SetShort("a gelfling child");
    SetLong("This awkward youth stands at four feet tall, \n"
            "and has deep brown eyes with a dark shade of skin. \n"
            "He flashes a gleeful grin as he builds a fort from \n"
            "sticks lying about. ");
    SetRace("gelfling");
    SetGender("male");
    
    SetClass("fighter");
    SetSkill("melee combat",2,1);
    SetLevel(random(2)+3);
    SetSmell("He smells like he hasn't been bathed lately.");
}


/* Approved by Amelia on Sun Sep 14 16:29:52 1997. */
