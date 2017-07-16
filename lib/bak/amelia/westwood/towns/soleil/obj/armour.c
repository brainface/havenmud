#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_ARMOUR);
  SetShort("a suit of field plate");
  SetLong("This shiny suit of field plate armor appears to "
    "be very sturdy and strong.  It is made of mithril and "
    "would serve someone very well.");
  SetValue(1500);
  SetMass(2000);
  SetDamagePoints(2500);
  SetId( ({ "field","armour","plate" }) );
  SetAdjectives( ({ "field" }) );
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
  SetMaterial( ({ "mithril" }) );
  SetWarmth(10);
  SetRepairSkills( ([ "armour smithing" : 20,
	"mithril working" : 20 ]) );
  SetRepairDifficulty(30);
 }
