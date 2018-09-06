#include <lib.h>  // Needs to be included in all files
#include "../vaashan.h"
inherit LIB_NPC;
static void create() {
  ::create();

  SetKeyName("bear");
  SetId( "bear" );
  SetAdjectives( ({"imposing","brown"}) );
  SetShort("an imposing brown bear");
  SetLong(
    "This brown bear is massive, with powerful muscles evident even beneath "
    "the thick fur. Fifteen centimeter claws extend from his paws, and his "
    "eyes glow faintly red. His lips are pulled back to reveal large white "
    "teeth, stained pink with blood. He looks hungry, and very dangerous. "
    );
  SetRace("bear");
  SetClass("animal");
  SetLevel(100);
  SetGender("male");
  SetAction(5, ({
    "The bear stands up on his rear paws, towering three meters into the air.",
    "!roar",
    "!sniff"
    }) );
  SetMeleeAttackString("claws");
  SetCombatAction(10, ({
    "The bear swipes at you.",
    "The bear attempts to take a big bite out of you!",
    }) );
  SetCorpseItems( ([VAAS_OBJ + "claws" : 1]) );
}

