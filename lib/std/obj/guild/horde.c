#include <lib.h>
#include <std.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;
inherit LIB_GUILD_ITEM;

static void create() {
  armour::create();
  guild::create();
  SetShort("a leather neckstrap");
  SetArmourType(A_AMULET);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_CLOTH);
  SetProtectionBonus(MAGIC, 50);
  SetKeyName("leather neckstrap");
  SetMagicGuild(1);
  SetGuildName("horde");
  SetLeader("sdagt");
  SetGuildObject(STD_OBJ "guild/horde");
  SetId( ({ "strap", "neckstrap", "horde_guild_object" }) );
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "This leather neckstrap has several advantages to it. "
    "It marks the wearer as a member of the "
    "Goblin Horde, the strongest members of the Goblin race "
    "that spans all of Kailie."
    );
  SetMass(40);
  SetPreventDrop("");
  SetMaterials( ({ "leather" }) );
  SetRetainOnDeath(1);
}

void init() {
  armour::init();
  guild::init();
}
