#include <lib.h>
#include <domains.h>
#include "../underland.h"
inherit LIB_ROOM;

void create() {
   ::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("Main Gate of Underland - West");
   SetLong("You are standing at the west entrance of Underland. A massive gate made of "
           "iron bars is set into the rocky walls of the underground cavern. The gate is "
           "currently open, allowing you to see into the city beyond. The streets are "
           "bustling with activity as the residents of Underland go about their daily "
           "lives. The walls to the north, south, and east are made of the same rough "
           "stone as the rest of the cavern, but the wall to the west is the gate itself. "
           "You can see the other side of the gate, which leads out into the dark tunnels "
           "beyond.");
   SetExits( ([ "east" : __DIR__"gate", "west" : __DIR__"darktunnels" ]) );
   SetItems( ([       ({ "gate", "iron gate", "massive gate", "gate made of iron bars" }) :         
   "The gate is made of thick iron bars, set into a sturdy frame. It looks like it could "
   "withstand a great deal of force.",      
    ({ "walls", "cavern walls", "stone walls", "rough stone walls" }) :
            "The walls are made of rough stone, as is the rest of the cavern. They are "
            "uneven in places, with jagged edges jutting out at odd angles.",
                   ({ "city", "underland" }) :
                   "The city of Underland is spread "
                   "out before you, with buildings and streets filling the cavern as "
                   "far as the eye can see.",
       ({ "streets", "cobblestone streets" }) :         
       "The streets of Underland are made of rough cobblestone. They are well-worn from "
       "years of use, but still sturdy and serviceable.",       
       ({ "residents", "people", "dwarves" }) :         "The residents of Underland are "
       "mostly dwarves, although there are a few other races represented as well. They are "
       "all going about their business, seemingly oblivious to your presence.",       
       ({ "dark tunnels", "tunnels" }) :         "The dark tunnels lead off to the west, "
       "disappearing into the unknown depths of the earth. They look forbidding and dangerous, "
       "but perhaps there is treasure to be found within." 
       
               ]) );
}

