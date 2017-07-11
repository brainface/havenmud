#include <lib.h>
#include "../rook.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("lost adventurer");
  SetRace("human");
  SetId( ({ "adventurer","lost adventurer" }) );
  SetAdjectives( ({ "lost" }) );
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetGender("female");
  SetShort("a lost adventurer");
  SetLevel(25);
  SetLong("This adventurer looks ragged and lost.  She is average "
    "size for a human but looks very prepared to defend herself.");
  SetMorality(500);
  SetAction(15, ({ 
     "!emote looks about as though lost.",
     "!emote walks around the room pondering.",
    }) );
  SetDie( "The woman screams in pain as she collapses." );
 }
