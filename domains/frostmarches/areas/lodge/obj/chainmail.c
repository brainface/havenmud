#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;
static void create() {
  armour::create();
  SetKeyName("chainmail");
  SetId( ({"chainmail"}) );
  SetShort("a skin covered chainmail");
  SetLong("This chainmail has been grotesquely made out of skin.  It is"
  "quite thick and can cover a great deal of the body.  The skin on it "
  "is old and starting to corrode away leaving a metal vest underneath "
  "it.  It seems able to hold its own in a battle."); 
  SetAdjectives( ({"skin"}) );
  SetMass(450);
  SetProperty("multiples", 1);
  SetValue(310);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "natural", "metal"}) );
  SetWarmth(10);
  SetRepairSkills( ([
  "armour smithing" : 7,
  "metal working" : 7,
  ]) );
  SetRepairDifficulty(18);
  SetDamagePoints(700);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  // SetProtection(SLASH,25);
  // SetProtection(BLUNT,20);
  // SetProtection(PIERCE,25);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:30:26 2000. */
