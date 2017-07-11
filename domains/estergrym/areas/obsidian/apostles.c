#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>

inherit LIB_ARMOUR;
inherit LIB_GUILD_ITEM;

static void create() {
  armour::create();
  guild::create();
  SetKeyName("an obsidian amulet");
  SetRetainOnDeath(1);
  SetId( ({"amulet"}) );
  SetAdjectives( ({ "obsidian"}) );
  SetGuildName("apostles");
  SetArmourType(A_AMULET);
  SetLeader("zoka");
  SetPreventGet("The amulet cannot be moved.");
  SetPreventDrop("You cannot drop the amulet.");
  SetGuildObject(STD_GUILD + "obsidianapostles.c");
  SetClass(1);
  SetShort("an obsidian amulet");
  SetMass(15);
   SetArmourClass(ARMOUR_CLOTH);
  SetValue(0);
  SetLong("This obsidian amulet is mysteriously dark.  A faint "
          "spark glows inside of it with an aura of evil.  This "
          "is the symbol of the Obsidian Apostles.");
  SetProperty("history", 
    "The original whereabouts of this amulet is unknown.");
  SetProperty("magic", 
    "This amulet permits telepathy as well as indicating leadership.");
  SetVendorType(VT_TREASURE);
  }

void init() {
  armour::init();
  guild::init();
  }
