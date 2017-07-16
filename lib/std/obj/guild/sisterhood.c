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
  SetShort("a small silver ring");
  SetArmourType(A_RING);
  SetArmourClass(ARMOUR_PLATE);
  SetProtectionBonus(MAGIC, 50);
  SetKeyName("silver ring");
  SetMagicGuild(1);
  SetGuildName("order");
  SetLeader("kaiya");
  SetGuildObject(STD_OBJ "guild/sisterhood");
  SetId( ({ "ring", "sisterhood_guild_object" }) );
  SetAdjectives( ({ "small", "silver" }) );
  SetLong(
    "This silver ring has several advantages to it. "
    "It marks the wearer as a member of the "
    "Order of the Sword and Dragon, and it provides an impeccible "
    "fashion statement."
    );
  SetMass(5);
  SetPreventDrop("");
  SetMaterials( ({ "mithril" }) );
  SetRetainOnDeath(1);
}

void init() {
  armour::init();
  guild::init();
}

int GetSize() {
  if (living(environment())) {
    return environment()->GetSize();
  }
  return SIZE_MEDIUM;
}
