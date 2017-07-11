/*  Portia  10-20-98
   A child for Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("child");
  SetShort("a small child");
  SetId( ({"child"}) );
  SetAdjectives( ({"small"}) );
  SetLong("This child looks as though he is no older than two or three years of age.");
  SetGender("male");
  SetRace("dark-elf"); 
 
  SetStat("strength", 1, 5);
  SetStat("durability", 5, 5);
SetInventory( ([ ]) );
  SetMorality(-5);
  SetClass("rogue");
  SetLevel(1);
  }
