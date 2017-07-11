#include <lib.h>
#include "../rath.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("diplomat");
  SetShort("an ancient diplomat");
  SetId( ({ "diplomat" }) );
  SetFriends( ({ "guard","rath","elite guard","priest","diplomat" }) );
  SetAdjectives( ({ "ancient" }) );
  SetGender("male");
  SetRace("elf");
  SetUndead(1);
  SetUndeadType("skeleton");
  SetClass("merchant");
  SetSkill("knife combat", 1, 1);
  SetLevel(random(30)+30);
  SetCurrency("imperials", random(500));
  SetAction(5, 
    ({ "!emote chatters uselessly.",
       "!emote looks important.",
       "!speak I've grown tired of this.",
     }) );
  RemoveLanguage("Eltherian");
  SetLanguage("Archaic", 100, 1);
  SetInventory( ([
   TOWER_O + "/dip_robe"  : "wear robes",
   TOWER_O + "/dip_knife" : "wield knife",
    ]) );
  SetLong("This ancient human is cursed to wander about the tower "
          "due to his status under the old Empire of Rath Khan.  "
          "His fate is to continue to function in his useless role "
          "as supplicant for all time.");
}
