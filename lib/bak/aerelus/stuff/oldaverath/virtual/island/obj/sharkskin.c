// Amelia
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("skin");
   SetShort("a dog shark's skin");
   SetId(({ "skin" }) );
   SetAdjectives( ({ "dog","shark's" }) );
   SetLong("Lined with a thin layer of blubber, the dog shark's skin repels water like "
           "an aquaphobic perfectionist.  Its outer coloring ranges from pale olive "
           "green to a dirty green-brown, camoflaging its bearer.  Unfortunately, "
           "the camoflage did not work for the dog shark that once wore it.");
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_CLOAK);
   SetArmourClass(ARMOUR_NATURAL);
   SetMass(20);
   SetValue(500);
   SetDamagePoints(450);
   SetSize(SIZE_SMALL);

 //  SetMaterial( ({ "natural" }) );
 //  SetRepairDifficulty(15);
 //  SetRepairSkills( ([
 //                      "natural working" : 0,
 //                 ]) );
}

