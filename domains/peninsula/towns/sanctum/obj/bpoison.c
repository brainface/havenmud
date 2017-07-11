#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_POISON_WITH;

string BlahRead();

static void create() {
   ::create();
   SetKeyName("black vial");
   SetShort("a clear black vial");
   SetId( ({ "vial" }) );
   SetAdjectives( ({ "glass","black", "clear"}) );
   SetLong(
     "This black vial contains only the residue of some pale "
     "liquid. A label is stuck to the outside of it. The glass has a "
     "design carved into it, shaped as a skull."
   );
   SetMass(5);
   SetValue(500);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetRead( (: BlahRead :) );
   SetDamagePoints(50);
   SetPoisonStrength(200);
   SetPoisonUses(20);
}

string BlahRead() {
   object who = this_player();
   if(who->GetSkillLevel("stealth") > 200) {
      who->eventPrint("The label on the vial reads:\n"
             "%^BOLD%^%^YELLOW%^**** Deadly Poison ****%^RESET%^");
      return "";
   }
   who->eventPrint("You can't seem to understand what the label says.");
   return "";
}
