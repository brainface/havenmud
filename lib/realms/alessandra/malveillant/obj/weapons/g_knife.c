/*  Portia  10-15-98
   A knife for the guard.
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("stileto");
  SetShort("a deadly stiletto");
  SetId( ({"knife","stiletto"}) );
  SetAdjectives( ({"deadly"}) );
  SetLong( "This stiletto looks very deadly and "
    			 "should only be used by skilled hands.");
  SetMass(30);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
          "metal working" : 3,
         "weapon smithing" : 4,
            ]) );
  SetRepairDifficulty(20);
  SetValue(50);
  SetClass(10);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetDamagePoints(600);
  }
