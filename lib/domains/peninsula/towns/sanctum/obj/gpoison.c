#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_POISON_WITH;

string BlahRead();

static void create() {
   ::create();
   SetKeyName("grey vial");
   SetShort("a clear grey vial");
   SetId( ({ "vial" }) );
   SetAdjectives( ({ "glass","grey", "clear"}) );
   SetLong(
     "This grey vial contains only the residue of some pale "
     "liquid. A label is stuck to the outside of it. The glass has a "
     "design carved into it, shaped as a skull."
   );
   SetMass(5);
   SetValue(40);
   SetVendorType(VT_TREASURE);
   SetMaterial( ({ "natural" }) );
   SetRead( (: BlahRead :) );
   SetDamagePoints(20);
   SetPoisonStrength(20);
   SetPoisonUses(5);
}

string BlahRead() {
   object who = this_player();
   if(who->GetSkillLevel("stealth") > 20) {
      who->eventPrint("The label on the vial reads:\n"
             "%^BOLD%^%^YELLOW%^**** Minor Poison ****%^RESET%^");
      return "";
   }
   who->eventPrint("You can't seem to understand what the label says.");
   return "";
}   
