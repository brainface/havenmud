/*  Portia 10-15-98 
      A glittering sword.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetShort("a glittering sword");
  SetId( ({ "sword"}) );
  SetAdjectives( ({"glittering"}) );
  SetLong("This sword is highly decorated and appears to never have seen battle. The hilt is"
          " decorated with many gems.");
  SetMass(50);
  SetClass(8);
  SetValue(600);
  SetRepairSkills( ([
     "metal working" : 8,
     "weapon smithing" : 8,
     ]) );
  SetRepairDifficulty(50);
  SetMaterials( ({"metal"}) );
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  }
