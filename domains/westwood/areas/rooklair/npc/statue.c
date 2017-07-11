#include <lib.h>
#include "../rook.h"
inherit LIB_SENTIENT;
int eventCheckPlayer();

static void create() {
  ::create();
  SetKeyName("statue");
  SetRace("golem", "statue");
  SetId( ({ "statue",}) );
  SetAdjectives( ({ "stone", "massive" }) );
  SetClass("fighter");
  SetGender("male");
  SetShort("a massive stone statue");
  SetLevel(80);
  SetEncounter( (:eventCheckPlayer:) );
  SetLong(
    "This statue is about seven feet tall and is made of "
    "plain stone. It is humanoid in appearance and has armour "
    "carved with it. It appears to be a warrior of an older "
    "age because his armour looks archaic and very decorative."
    );
  SetMorality(0);
  SetCombatAction(30, ({ 
     "!emote pounds its fist together creating a cloud of dust.",
     "!emote attempts to crush its enemies.",
    }) );
  SetInventory( ([
    R_OBJ + "weapon" : "wield weapon",
    ]) );
  SetFriends("statue");
  SetNoCorpse(1);
  SetDie("The statue %^RED%^crumbles%^RESET%^ into dust.");
 }

int eventCheckPlayer() {
    object who = this_player();
    if (userp(who)){
    SetAttack(who);
    return 1;
  }
  else return 0;
}
