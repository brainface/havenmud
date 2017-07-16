// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   SetDestroyOnSell(1);
   item::create();
   SetKeyName("fur");
   SetId( ({ "fur","tuft" }) );
   SetAdjectives( ({ "half-dry","tuft","of","fur" }) );
   SetShort("a half-dry tuft of fur");
   SetLong("This small, half-dry tuft of fur came from a mouse.  "
           "It looks like it could be used in some way to "
           "make clothing, but only by someone whose life "
           "is dedicated to making clothing and who has "
           "many pieces of fur.");
   SetMass(2);
   SetValue(2);
   SetClass(1);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetDamagePoints(10);
   SetVendorType(VT_FUR);
   SetMaterial(({"natural"}));
   SetRepairDifficulty(2);
   SetRepairSkills( ([
                       "natural working" : 0,
                  ]) );
   SetProperty("history","This tuft of fur came from a small "
               "mouse in the caves near Grymxoria in the "
               "Estergrym Mountains.");
}
