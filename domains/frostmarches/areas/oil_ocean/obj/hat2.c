//Illura@Haven
//Nov 2010
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("hard hat");
   SetShort("a hard wooden hat");
   SetId( ({ "hat","hard", "wooden" }) );
   SetAdjectives( ({ "hat","hard", "wooden" }) );
   SetLong(
    "This hat is made out of wood strips dovetailed together. "
    "It is made to protect the head of the wearer, but looks "
    "like it probably does a shabby job.");
   SetMass(7);
   SetSize(SIZE_SMALL);
   SetValue(45);
   SetArmourClass(ARMOUR_NATURAL);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_HELMET);
   SetDamagePoints(600);
   SetMaterial( ({ "natural" }) );
   SetWarmth(5);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
        "natural working" : 1,
        ]) );
}

