#include <lib.h>
inherit LIB_SENTIENT;

static void create()
{
  sentient::create();
  SetKeyName("Mundane Mercenary");
  SetId( ({"cocky dwarf fighter","mercenary","merc","fighter",
           "mercenary fighter","dwarf","dwarf mercenary","dwarf fighter"}) );
  SetShort("a cocky dwarf fighter");
  SetLong("The tough looking dwarf quietly appraises you as a threat to his "
          "employer.");
  SetLevel(17);
  SetRace("dwarf");
  SetClass("fighter");
  SetGender("male");
  AddInventory("/std/weapon/hack/hand-axe", "wield axe in right hand");
  AddInventory("/std/weapon/blunt/war-hammer", "wield hammer in left hand");
  AddInventory("/std/armour/shirt/scale_mail", "wear scale mail");
  AddInventory("/std/armour/pants/studded_leather_pants", "wear pants");
  AddInventory("/std/armour/boot/leather_boot", "wear boots");
  AddInventory("/std/armour/helm/open_helm", "wear helm");
  AddInventory("/std/armour/cloak/r_cape", "wear cape");
  SetLanguage("Oiseau",100);
  SetFriends( ({ "gelfling","lumberjack" }) );
}
