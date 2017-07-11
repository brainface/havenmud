/*  A wakasashi */
#include <damage_types.h>
#include <vendor_types.h>
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("rusted wakizashi");
  SetShort("a rusted wakizashi");
  // Mahkefel: making sure bandits wield the thing
  SetId( ({ "wakizashi", "wakasashi" }) );
  SetAdjectives( ({ "rusted" }) );
  SetClass(11);
  SetDamagePoints(1500);
  SetMass(100);
  SetWeaponType("pierce");
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetMaterial("metal");
  SetRepairSkills( ([
    "metal working" : 5,
    "weapon smithing" : 5,
    ]) );
  SetRepairDifficulty(40);
  SetLong(
     "This is a short piercing weapon from the Province of Tairi."
     " Old and rusted, this blade has apparently been through many"
     " battles but has been poorly cared for, and thus, probably the"
     " property of a warrior without a master, a Ronin. "
  );

  SetValue(300);
}

