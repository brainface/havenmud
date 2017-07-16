#include <lib.h>
#include "../tairi.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("samurai warrior");
  SetShort("a samurai warrior");
  SetId( ({ "samurai", "warrior" }) );
  SetAdjectives( ({ "samurai" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetTown("Tairi");
  SetClass("cavalier");
  SetLevel(random(30) + 25);
  SetGender("male");
  SetLong("This proud warrior wears the Minamoto colors. His bearing "
         "suggests he keeps the peace in Tairi through violence as "
         "often as through other means.");
  SetAction(5, ({ 
     "!emote stands proudly.",
     "!emote scans the horizon.",
     "!emote looks around carefully.",
     "!say Keep the peace, travellers",
    }) );
  SetInventory( ([
      TAI_RI_OBJ "katana" : "wield katana",
      TAI_RI_OBJ "wakasashi" : "wield wakasashi",
      TAI_RI_OBJ "oyoroi" : "wear oyoroi",
    ]) );
  SetWanderSpeed(20);
  SetFriends( ({ "citizen", "daimyo", "samurai", "warrior" }) );
  SetMorality(200);
  SetTown("Tairi");
}
