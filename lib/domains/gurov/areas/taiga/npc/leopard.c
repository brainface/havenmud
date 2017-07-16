
//Illura@Haven
//leopard
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("leopard");
  SetId( ({ "leopard" }) );
  SetAdjectives( ({ "slinky", "snow" }) );
  SetShort("a slinky snow leopard");
  SetLong(
    "The lithe leopard moves with uncommon grace through "
    "her domain. Her soft coat is dappled with iron gray spots "
    "across a white field. Although perhaps she looks less "
    "powerful than the stockier lynxes, her slim body is quicker "
    "and she would probably be very dangerous. "
  );
  SetGender("female");
  SetClass("animal");
  SetLevel(30);
  SetRace("cat");
    SetAction(5, ({
    "!emote yowls a warning at you.",
     "!emote hisses. You can see her fangs. They're very sharp.",
    "!emote flexes her claws casually against a snowbank, completely ruining it.",
         }) );
  SetCombatAction(10, ({
    "The leopard screams with a terrifying noise.",
    "The leopard springs at you!",
    }) );
}
