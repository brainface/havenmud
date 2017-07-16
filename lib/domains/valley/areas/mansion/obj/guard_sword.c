/* a sword for the guard
     kyla 4-98
*/
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetShort("an exquisite longsword");
  SetId( ({"longsword", "sword"}) );
  SetAdjectives( ({"exquisite", "long"}) );
  SetLong("This exquisite longsword is very finely crafted. It appears "
        "as if it could defend against anyone or anything imaginable. "
       "The hilt of the sword is highly decorated and appears very heavy.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(14);
  SetValue(200);
  SetMass(100);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
           "metal working" : 10,
           "weapon smithing" : 10,
 		]) );
  SetRepairDifficulty(15);
  }
