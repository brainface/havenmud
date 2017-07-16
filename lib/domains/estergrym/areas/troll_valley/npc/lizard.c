/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("ordinary lizard");
  SetId( ({"lizard",}) );
  SetAdjectives( ({"ordinary","green",}) );
  SetShort("a ordinary green lizard");
  SetLong("Yellow spots and a bright orange fin run down this otherwise "
          "ordinary looking lizard's back.");
  
  SetMorality(0);
  SetRace("lizard");
  SetClass("animal");
  SetLevel(6);
  SetGender("male");
  SetAction(25,({
     "The lizard freezes it's motion.",
     "Its tongue flicking into the air, the lizard searches for "
     "a bug for dinner.",
     "Incredibly quick, the lizard darts to another rock.",
     }) );
}
