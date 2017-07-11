//Selket@Haven
//2006
//Zalbar 2014 changed to fighter for blunt combat
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Big Snow");
  SetId( ({ "snow", "giant" }) );
  SetShort("Big Snow, the Giant");
  SetAdjectives( ({ "big" }) );
  SetLong("Big Snow, so named because of his obvious towering "
          "height and the white fur that covers his bulky mass, "
          "is a more reticent giant than the others of his kind. "
          "He has been pushed from their society and dwells alone "
          "with his wife in this small hut.");
  SetRace("giant");
  SetClass("fighter");
  SetTown("Ungkh");
  SetLevel(160);
  SetGender("male");
  SetMorality(300);
  SetBaseLanguage("Uruk");
  SetLimit(1);
  SetAction(1, ({
    "!say Nobody like me. But I no care.",
    "!stretch",
    "!grunt",
    "!scratch",
    }) );
  SetCombatAction(1, ({
    "!grunt angrily",
    "!emote nearly brains you with his enormous club.",
    }) );
  SetCurrency("skins", 500+random(250));
  SetInventory(([
    U_OBJ "club" : "wield club in right hand",
    U_OBJ "shield" : "wear shield on left hand",
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
