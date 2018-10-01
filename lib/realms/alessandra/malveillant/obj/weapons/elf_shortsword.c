/*  Portia Ruins 10-7-98
     A shortsword for a dark elf.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("shortsword");
  SetId( ({"sword", "shortsword"}) );
  SetAdjectives( ({"short"}) );
  SetShort("a small shortsword");
  SetLong("This sword has obviously been taken care of very well. "
          "There are no signs that it has ever been used. It seems "
          "to have been made for someone with somewhat small hands.");
  SetMass(75);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
         "metal working" : 5,
        "weapon smithing" : 5,
         ]) );
  SetRepairDifficulty(13);
  SetValue(200);
  SetDamagePoints(700);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(11);
  }
/*   [ Portia approved ] */
