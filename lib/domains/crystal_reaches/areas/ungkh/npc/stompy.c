//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Stompy");
  SetId( ({ "giant", "stompy" }) );
  SetAdjectives( ({ "great" }) );
  SetShort("Stompy the Great");
  SetLong("Stompy's big feet are good for stomping down offending "
          "trees or kicking herds of deer out of the way, but his "
          "brain isn't good for much more than padding the thick "
          "skull of this brawny giant.");
  SetRace("giant");
  SetClass("fighter");
  SetTown("Ungkh");
  SetLevel(140);
  SetGender("male");
  SetMorality(-100);
  SetLimit(1);
  SetBaseLanguage("Uruk");
  SetAction(1, ({
    "!say Stompy stomp you!.",
    "!emote stomps things idly.",
    "!grunt",
    "!say SQUISH YA SQUISH YA!",
    "!snort",
    "!spit",
    }) );
  SetCombatAction(1, ({
    "!roar",
    "!disarm",
    }) );
  SetCurrency("skins", 500+random(150));
  SetInventory(([
    U_OBJ "sword" : "wield sword",
  ]) );
}

int eventDie(object killer) {
  object ogre_inv;
  if(!random(500)) {
     ogre_inv = new(DIR_INVASIONS + "/soleil_ogre/ois_inv");
    INVASION_D->eventRegisterInvasion(ogre_inv, killer);
  }
  return ::eventDie(killer);
}
