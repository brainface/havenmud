// A newbie level npc to slay
// To add to the world roadmap package
// Urien@Haven 06JUN23

#include <lib.h>
inherit LIB_NPC;
static void create(){
  ::create();
  SetId(({"snail"}));    
  SetAdjectives( ({ "tackish" }) );  
  SetShort("a tackish snail");
  SetLong("It has a brown and slimy membrane body that rests inside "
          "of a spiral shell. The shell seems dim from exposure or lack "
          "of moisture. It is nearly transparent but keeps "
          "a soft brown colour with dark gray striations. This snail "
          "is above average in size and is much larger than an "
          "adult human foot in quick comparison. A barbed tail "
          "juts out from the end of the snail.");
  SetRace("slug","snail");
  AddLimb("barbed tail","torso",4, ({ }) );
  AddLimb("shell","torso",5, ({ }) );
  SetGender("nueter");
  SetClass("animal");
  SetKeyName("snail");
  SetLevel(random(1) + 1);
}
