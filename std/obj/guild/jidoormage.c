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
  SetShort("a luminous green cloak");
  SetArmourType(A_CLOAK);
  SetArmourClass(ARMOUR_CLOTH);
  SetProtectionBonus(MAGIC, 50);
  SetKeyName("green cloak");
  SetMagicGuild(1);
  SetGuildName("jidoormage");
  SetLeader("luna");
  SetMaterials( ({ "textile" }) );
  SetGuildObject(STD_OBJ "guild/jidoormage");
  SetId( ({ "cloak" , "jidoormage_guild_object" }) );
  SetAdjectives( ({ "luminous", "green" }) );
  SetLong(
    "This luminous green cloak has several advantages to it. "
    "First, it marks the wearer as a member of the famed "
    "Jidoor Mage's Guild, a conclave of witches and wizards "
    "that spans all of Kailie.  Second, it has a fashionable "
    "green color that sparkles in the light."
    );
  SetMass(40);
  SetPreventDrop("");
  SetRetainOnDeath(1);
}

void init() {
  armour::init();
  guild::init();
}
