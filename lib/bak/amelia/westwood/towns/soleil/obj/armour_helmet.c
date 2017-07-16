#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

int DoWear();

static void create() {
  ::create();
  SetKeyName("helmet");
  SetId( ({ "helmet" }) );
  SetArmourType(A_HELMET);
  SetShort("a helmet for platemail");
  SetLong("This shiny helmet appears to be very sturdy and "
    "strong.  It is made of a strange metal and would serve someone "
    "very well.  It fully covers the head and protects it from damage.");
  SetValue(750);
  SetMass(400);
  SetMaterial("metal");
  SetWarmth(0);
  SetDamagePoints(2500);
  SetProtection(BLUNT,45);
  SetProtection(SLASH,45);
  SetProtection(PIERCE,45);
  SetProtection(WATER,45);
  SetProtection(SHOCK,45);
  SetProtection(COLD,45);
  SetProtection(HEAT,45);
  SetProtection(GAS,45);
  SetProtection(ACID,45);
  SetProtection(MAGIC,45);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ "armour smithing" : 20,
        "metal working" : 20 ]) );
  SetRepairDifficulty(30);
 }

int DoWear()
{
  write("The armour fits but seems overly restrictive.");
  say((string)this_player()->GetName() + " wears a helmet.");
  this_player()->SetCanCast((this_player()->GetCanCast())+1);
  return 1;
}

/*
mixed eventUnequip(object who)
{
  this_player()->SetCanCast((this_player()->GetCanCast())-1);
  ::eventUnequip(who);
}
*/
