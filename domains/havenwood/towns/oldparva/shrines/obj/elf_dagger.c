/* Portia  10-14-98
     Malveillant  An elf dagger.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dagger");
  SetShort("a tiny dagger");
  SetId( ({"dagger"}) );
  SetAdjectives( ({"tiny"}) );
  SetLong("This dagger is very small but appears quite deadly. It was obviously made by "
                "someone who takes great pride in their work.");
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetDamagePoints(800);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
             "metal working" : 5,
            "weapon smithing" : 5,
      ]) );
  SetRepairDifficulty(30);
  SetClass(15);
  SetValue(150);
  SetMass(30);
  }
