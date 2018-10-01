/*  Portia  Ruins 10-7-98
    A longsword for a dark elf
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetId( ({"longsword", "sword"}) );
  SetAdjectives( ({"long", "shining" }) );
  SetShort("a shining longsword");
  SetLong("This longsword shines as though it has just been polished. "
         "Its owner must take wonderful care of it as it does not have a "
         "single spot of rust.");
  SetValue(50);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
       "metal working" : 6,
      "weapon smithing" : 6,
           ]) );
  SetRepairDifficulty(10);
  SetClass(14);
  SetMass(200);
  SetDamagePoints(900);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  }
/*   [ Portia approved ] */
