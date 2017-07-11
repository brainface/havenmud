/*    /domains/Ylsrim/armour/shield.c
 *    from the Nightmare V Object Library
 *    an example shield
 *    created by Lassondra@Nightmare
 */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("wooden shield");
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "wooden" }) );
    SetShort("a wooden shield");
    SetLong("This shield is a simple circle of wood with no markings.");
    SetDamagePoints(600);
    SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
    SetMass(400);
    SetValue(75);
    SetArmourType(A_SHIELD);
   SetRepairDifficulty(20);
   SetMaterial( ({ "wood" }) );
   SetRepairSkills( ([
                       "armour smithing" : 4,
                       "wood working" : 4,
                  ]) );
}
 
