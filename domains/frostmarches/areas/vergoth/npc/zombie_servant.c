#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("zombie servant");
  SetRace("human");
  SetId( ({ "human", "zombie", "zombie servant", "servant" }) );
  SetAdjectives( ({ "zombie" }) );
  SetClass("fighter");
  SetGender("female");
  SetShort("zombie servant");
  SetLevel(2);
  SetUndead(1);
  SetNoCorpse(1);
  SetLong(
     "This zombie appears to have been a servant before its untimely "
     "death.  It is still dressed in a white outfit and wearing an "
     "apron.  It stands about five and a half feet tall as it wanders "
     "about the room performing its before death duties.");
  SetMorality(-300);
  SetInventory( ([
     V_OBJ + "rags" : "wear rags",
     ]) );
  SetCombatAction(30, ({ 
     "!say the master will hear about this",
     "!say you are not welcome here",
     "!say visitors are not allowed in this part of the tower",
     "!emote wobbles about in an attack.",
     }) );
  SetAction(10, ({
     "!emote makes the beds up.",
     "!emote dusts the walls.",
     "!emote sweeps the floor.",
     "!emote moves about the room.",
     }) );
  SetDie( "Zombie crumples into a heap on the ground." );
}
