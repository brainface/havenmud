/*  The rapier wielded by the cleric */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetShort("a fine elven rapier");
  SetId( ({ "rapier" }) );
  SetAdjectives( ({ "fine", "elven" }) );
  SetClass(15);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(10);
  SetDamagePoints(600);
  SetValue(175);
  SetMass(80);
  SetRepairSkills( ([
     "metal working" : 1,
     "weapon smithing" : 1,
     ]) );
   SetVendorType(VT_WEAPON);
  SetLong("This is a fine elven rapier, similiar to the ones used by "
          "the Haven Town Guard. It is sharp and looks highly deadly.");
  SetWield("The rapier feels warm to the touch.");
  SetProperty("magic", "The rapier only seems magical, it is not truly.");
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  }
