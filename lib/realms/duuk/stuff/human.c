/*  This is a level 0 human */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("human");
  SetRace("human");
  SetLevel(0);
  SetId( ({ "human", "target" }) );
  SetAdjectives( ({ "0", "level" }) );
  SetShort("a 0 level human target");
  SetLong("This is a target.");
  SetGender("male");
  SetAction(5, ({ 
    "!emote mumbles.",
    "!speak Yes M'Lord",
    }) );
 }
