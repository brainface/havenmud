#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("cooking slave");
   SetShort("a cooking slave");
   SetId( ({ "slave" }) );
   SetAdjectives( ({ "cooking" }) );
   SetLong("The slave has burns on his hands in a few places, "
           "but none of the damage from the kitchen stove looks "
           "permanent.  He has some fat on his bones, strange " 
           "among slaves, but probably coming from eating all the "
           "left overs from the Lord's banquets and munching "
           "on the enormous amounts of food that constantly "
           "surround him.");
   
   SetClass("rogue");
   SetRace("human");
   SetLevel(15);
   SetGender("male");
   SetMorality(75);
}