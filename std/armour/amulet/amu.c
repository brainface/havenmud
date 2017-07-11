#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

int CheckRace();

static void create() {
   armour::create();
   SetKeyName("orc amulet");
   SetShort("an orc amulet");
   SetId( ({ "amulet" }) );
   SetAdjectives( ({ "orc" }) );
   SetLong("The amulet is made of chain links with a pendant of "
           "an orc brandishing a sword hanging from it.");
   SetMass(25);
   SetValue(45);
   SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
   SetArmourType(A_AMULET);
  SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(125);
   SetClass(5);
   SetProperty("magic","The amulet was made for only orcs, and was "
               "cursed so that only they could wear it.  It was "
               "given magical protection properties, however.");
   SetWear((: CheckRace :));
}

int CheckRace() {
   if(this_player()->GetRace()=="orc") {
      send_messages(({"wear"}),"The amulet shimmers as $agent_name "
                      "$agent_verb it.",this_player(),0,this_player());
      return 1;
   }
   else return 0;
}
