#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "tall" }) );
  SetShort("a tall necromancers' staff");
  SetLong(
    "This long staff is one and a half the height of the average "
    "gnome. The head is crested with a long curving bough of "
    "thick ivy that has been tied together with many thin threads "
    "simulating a spider web. The web is adorned with beads that "
    "look like dew drops on the spider web."
  );
  SetHands(2);
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT|HUNGER|POISON);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1800);
  SetValue(8000);
  SetMass(125);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(75);
  SetRepairSkills( ([
    "wood working" : 90,
    "weapon smithing" : 90,
     ]) );
 }
