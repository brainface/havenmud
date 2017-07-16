// by Dahaka
// Aug 2004

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
  item::create();
  SetKeyName("lance");
  SetId( ({ "lance" }) );
  SetAdjectives( ({"footman's","footman","footmans"}) );
  SetShort("a footman's lance");
  SetLong(
     "This long metal shaft is topped off with a double bladed spear head. "
     "Leather wrapping in the middle of the lance gives the wield a better "
     "grip.");
  SetMaterial( ({"metal","wood"}) );
  SetRepairSkills( ([
     "metal working"   : 2,
     "weapon smithing" : 2,
     ]) );
  SetRepairDifficulty(10);
  SetMass(175);
  SetValue(10);
  SetDamagePoints(800);
  SetWeaponType("pole");
  SetDamageType(SLASH);
  SetClass(6);
  SetVendorType(VT_WEAPON);
}