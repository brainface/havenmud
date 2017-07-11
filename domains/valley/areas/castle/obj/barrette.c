#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shiny barrette");
   SetShort("a shiny barrette");
   SetId( ({ "barrette" }) );
   SetAdjectives( ({ "shiny","clay" }) );
   SetLong("A shiny coat has been applied over this clay barrette, "
           "coloring it in a variety of shades and hues.");
   SetMass(3);
   SetValue(15);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
   SetDamagePoints(30);
   // SetProtection(PIERCE,2);
   // SetProtection(SLASH,5);
   // SetProtection(ACID,1);
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "natural working" : 1,
                  ]) );
   SetSize(SIZE_MEDIUM);
}
