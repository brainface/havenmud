/* a ceremonial longsword
     kyla 4-98
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetShort("a ceremonial longsword");
  SetId( ({"longsword", "sword"}) );
  SetAdjectives( ({"ceremonial", "long"}) );
  SetLong("This longsword is highly decorated and looks incredibly "
          "expensive. It has obviously never seen battle and probably "
          "never will.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(500);
  SetClass(7);
  SetValue(300);
  SetMass(60);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({"metal" }) );
  SetRepairSkills( ([
          "metal working" : 6,
                ]) );
  SetRepairDifficulty(7);
  }
