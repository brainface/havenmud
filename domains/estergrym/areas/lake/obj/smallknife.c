// Coded by Zeratul 11-26-99
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a small knife");
  SetLong("This small knife has a sharp blade that comes to a point. "
          "The handle is made from leather rapped around a piece "
     			"of wood. "
     );
  SetId( ({"knife","small knife"}) );
  SetClass(15);
  SetDamagePoints(450);
  SetValue(300);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetKeyName("knife");
  SetMass(35);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "small" }) );
  SetMaterial( ({
  	"metal",
  	"leather",
  	"wood" 
  	}) );
  SetRepairDifficulty(5);
  		
}
