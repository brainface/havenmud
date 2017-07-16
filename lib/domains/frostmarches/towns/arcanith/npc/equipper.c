#include <lib.h>
#include <std.h>
#include "../ruins.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("misha");
  SetGender("male");
  SetRace("human");
  SetTown("Arcanith");
  SetBaseLanguage("Koblich");
  SetClass("mystic");
  SetReligion("Magildan");
  SetLevel(15);
  SetCurrency("senones", 200);
  SetShort("Misha Nikolaevich, expedition supplier");
  SetId( ({ "Misha", "supplier" }) );
  SetLong(
    "Misha is large, dour man with an immense shaggy beard. A "
    "low-ranking priest of the Gurov order of the Magildan faith, "
    "he was sent to assist and supply any expeditions into the ruins of "
    "Acanith by its natives. One could simply <ask misha for help>."
  );
  SetCombatAction( 30, ({
    "!cast ice ball",
    "!yell Help!",
  }) );
  SetLevelLimit(8);
  SetLimit(1);
  SetFreeEquipment( ([
    "staff" : STD_WEAPON "/staff",
    "pickaxe" : OBJ "/pickaxe",
    "knife" : STD_WEAPON "/knife/small_knife" ,
    "sword" : STD_WEAPON "/dented_sword",
  ]) );
  SetAction(10, ({
    "!say Ask me for a pickaxe!",
    "!say Ask me for a staff!",
    "!say Ask me for help!",
  }) );
}
