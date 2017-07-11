#include <lib.h>
inherit LIB_NPC;
#include "../vergoth.h"

static void create() {
  npc::create();
  SetKeyName("rat");
  SetShort("a skeletal rat");
  SetId( ({ "rat" }) );
  SetAdjectives( ({ "skeletal", "small" }) );
  SetRace("rodent");
  SetClass("animal");
  SetGender("male");
  SetLevel(1);
  SetUndead(1);
  SetLong(
     "This is a small, skeletal rat.  It is literaly nothing more than "
     "bones.  It has been bleached white with age and is no more than "
     "six inches in length.  Its teeth still appear to be very sharp.");
  SetCombatAction(30, ({ 
     "!emote rattles about in an attack.",
     "!emote clicks about as it tries to flank.",
     "!emote snaps its teeth in an attack.",
     }) );
  SetNoCorpse(1);
  SetAction(10, ({
    "!emote feet clatter about the room.",
    "!emote runs in small circles.",
    "!emote nibbles on nothing.",
    }) );
  SetDie( "A skeletal rat falls down in a pile of bones." );
  }
