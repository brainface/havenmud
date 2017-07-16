//coded by Syra@haven 1/98

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("a decorated staff");
  SetLong("The long wooden staff is decorated elaborately by "
          "engraved designs on its handle. It looks like it once "
          "belonged to a master.");
  SetHands(2);
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "long","wooden","decorated" }) );
  SetClass(15);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetDamagePoints(800);
  SetValue(200);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(9);
  SetRepairSkills( ([
     "wood working" : 5,
     "weapon smithing" : 3,
     ]) );
  SetProperty("history","This staff was once used by the revered "
              "Sagoth of Keryth.");
 }
