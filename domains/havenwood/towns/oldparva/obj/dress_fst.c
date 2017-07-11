#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SMELL;
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("dress");
   SetShort("a plain blue dress");
   SetId( ({ "dress" }) );
   SetAdjectives( ({ "plain","blue" }) );
   SetLong("This plain blue dress was made of a soft, warm "
           "fabric.  It is simple in style, doing little "
           "other than covering up the body and staying "
           "out of one's way.");
   SetMass(35);
   SetValue(45);
   SetVendorType(VT_CLOTHING);
   SetArmourClass(ARMOUR_CLOTH);
   SetArmourType(A_BODY_ARMOUR);
   SetDamagePoints(65);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,1);
   SetSmell("The dress stinks of fish and the ocean.");
   SetWear("It's a little damp and wet.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
   }
