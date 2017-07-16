#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;
inherit LIB_WEAPON;

static void create() {
   armour::create();
   SetKeyName("plain antlers");
   SetShort("a set of plain antlers");
   SetId( ({ "set","antlers","antler" }) );
   SetAdjectives( ({ "set of","plain","beautiful" }) );
   SetLong("The antlers are beautiful, but plain and have little to "
           "note.  They are a nice solid brown color.");
   SetMass(200);
   SetValue(50);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(300);
   SetProtection(BLUNT,5);
   SetProtection(SLASH,5);
   SetProtection(PIERCE,2);
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(8);
   SetRepairSkills( ([
                       "natural working" : 2,
                       "armour smithing" : 2,
                  ]) );
   SetClass(7);
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
   SetSize(SIZE_SMALL);
}
