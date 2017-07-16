/*    /domains/Ylsrim/armour/shield.c
 *    from the Nightmare V Object Library
 *    an example shield
 *    created by Lassondra@Nightmare
 */

#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>

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
    SetMass(400);
  SetSize(SIZE_MEDIUM);
    SetValue(75);
    SetArmourType(A_SHIELD);
    SetArmourClass(ARMOUR_NATURAL);
    SetMaterial( ({ "wood" }) );
    SetRepairDifficulty(20);
    SetRepairSkills( ([
                       "armour smithing" : 4,
                       "wood working" : 4,
                  ]) );
}
 
