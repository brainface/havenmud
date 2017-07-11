#include <lib.h>
#include <std.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;
inherit LIB_GUILD_ITEM;

static void create() {
  armour::create();
  guild::create();
  SetShort("an obsidian ring");
  SetArmourType(A_RING);
  SetArmourClass(ARMOUR_CHAIN);
  SetProtectionBonus(MAGIC, 50);
  SetKeyName("obsidian ring");
  SetMagicGuild(1);
  SetGuildName("twilight");
  SetLeader("sekh");
  SetGuildObject(STD_OBJ "guild/twilight");
  SetId( ({ "ring", "twilight_guild_object" }) );
  SetAdjectives( ({ "obsidian" }) );
  SetLong(
    "This obsidian ring has several advantages to it. "
    "First, it marks the wearer as a member of the rumoured "
    "Guardians of Twilight, an organization of capitalists, "
    "merchants, and thieves "
    "that spans all of Kailie.  Second, it has a fashionable "
    "obsidian color that sparkles in the light."
    );
  SetMass(40);
  SetPreventDrop("");
  SetMaterials( ({ "natural" }) );
  SetRetainOnDeath(1);
}

void init() {
  armour::init();
  guild::init();
}
