#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

int DoWear();

static void create() {
  ::create();
  SetKeyName("cuisse");
  SetId( ({ "cuisse","pants" }) );
  SetArmourType(A_PANTS);
  SetShort("a cuisse for platemail");
  SetLong("This shiny cuisse appears to be very sturdy and "
    "strong.  It is made of a strange metal and would serve "
    "someone very well.  It fully covers the legs and protects "
    "them from damage.");
  SetValue(750);
  SetMass(1100);
  SetDamagePoints(25000);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
 SetSize(SIZE_SMALL);
  // SetProtection(BLUNT,45);
  // SetProtection(SLASH,45);
  // SetProtection(PIERCE,45);
  // SetProtection(WATER,45);
  // SetProtection(SHOCK,45);
  // SetProtection(COLD,45);
  // SetProtection(HEAT,45);
  // SetProtection(GAS,45);
  // SetProtection(ACID,45);
  // SetProtection(MAGIC,45);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "armour smithing" : 20,
        "metal working" : 20 ]) );
  SetRepairDifficulty(30);
 }

int DoWear()
{
  write("The armour fits but seems overly restrictive.");
  say((string)this_player()->GetName() + " wears a cuisse.");
  this_player()->SetCanCast((this_player()->GetCanCast())+1);
  return 1;
}
/*
mixed eventUnequip(object who)
{
 SetSize(SIZE_SMALL);
  this_player()->SetCanCast((this_player()->GetCanCast())-1);
  ::eventUnequip(who);
}
*/
