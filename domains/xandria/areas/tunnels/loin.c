/*  Portia  Ruins  10-7-98
     A loin cloth for the nekkid Lizardmen.
*/

#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("loincloth");
  SetId( ({"cloth", "loincloth"}) );
  SetAdjectives( ({"loin"}) );
  SetShort("a tattered loincloth");
  SetLong("This hide acts as the bare minimum of clothing. It's tattered "
         "edges indicate it has been worn quite a bit.");
  SetValue(5);
  SetMaterial( ({"natural"}) );
  SetWarmth(8);
  SetRepairSkills( ([
         "natural working" : 1,
           ]) );
  SetRepairDifficulty(5);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(100);
  SetMass(10);
  //BLUNT, 3);
  //COLD, 3);
  //PIERCE, 3);
  SetArmourType(A_PANTS);
  }
/*   [ Portia approved ] */
