#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
#include "../vergoth.h"

static void create() {
  ::create();
  SetKeyName("ring");
  SetArmourType(A_RING);
  SetShort("a mithril ring");
  SetLong("The ring is made from a shiny %^WHITE%^mithril%^RESET%^.  The "
	"edging is carved into ivy runners and there is a small inscription "
	"on the inside.  The inscription says 'From perfection comes "
	"protection.'");
  SetValue(600);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(5);
  SetDamagePoints(750);
  SetId( ({ "ring" }) );
  SetAdjectives( ({ "mithril" }) );
  // SetProtection(SLASH, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(BLUNT, 2);
  // SetProtection(SHOCK, 2);
  // SetProtection(HEAT, 2);
  // SetProtection(ACID, 2);
  // SetProtection(COLD, 2);
  SetMaterial( ({ "mithril" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "metal working" : 25 ]) );
  SetRepairDifficulty(25);
 }
