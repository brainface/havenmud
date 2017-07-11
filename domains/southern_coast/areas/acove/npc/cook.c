#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("pirate cook");
  SetShort("the ship cook");
  SetId( ({"cook", "pirate"}) );
  SetAdjectives( ({"undead","ship","well-fed","ample"}) );
  SetLong("This pirate appears very well-fed. His ample girth "
         "is barely covered by a greasy, once-white apron.");
  SetGender("male");
  SetRace("human");
  SetMorality(-1000);
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("rogue");
  SetLevel(25);
  SetAction(5,
        ({"!emote moves quickly despite his weight."})
       );
  SetInventory( ([
      ACOVE_OBJ + "bknife" : "wield butcher knife",
       ]) );
}

int eventDie(object killer) {
  object pirate_inv;
  if(!random(200)) {
     pirate_inv = new(DIR_INVASIONS + "/haven_pirate/pip_inv");
    INVASION_D->eventRegisterInvasion(pirate_inv, killer);
  }
  return ::eventDie(killer);
}
