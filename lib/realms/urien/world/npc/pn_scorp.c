// A mortal level npc to slay
// The female version is small, less spikes, no poison
// To add to the world roadmap package
// Urien@Haven 06JUN23

#include <lib.h>
inherit LIB_NPC;
static void create(){
  ::create();
  SetId(({"scorpion"}));    
  SetAdjectives( ({ "duelspike" }) );  
  SetShort("a duelspike scorpion");
  SetLong("The scorpion has a hard dull red carapace covered "
          "in erect brown hairs. Two spikes are usually "
          "located on the head and the body in the female "
          "types. The claws are usually various in size and have "
          "different roles for crushing or smashing. In her "
          "movements a soft white colored base meat color "
          "can be seen through her various activity as she moves "
          "and wriggles in her thick chitin body.");
  SetRace("lobster","scorpion");
  AddLimb("body spike","abdomen",4, ({ }) );
  AddLimb("head spike","head",4, ({ }) );
  SetGender("female");
  SetClass("animal");
  SetKeyName("scorpion");
  SetLevel(random(1) + 5);
}

