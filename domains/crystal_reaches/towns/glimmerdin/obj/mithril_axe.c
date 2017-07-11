#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("mithril battleaxe");
  SetId( ({ "battleaxe", "axe" }) );
  SetAdjectives( ({ "mithril", "battle",}) );
  SetShort("a mithril battleaxe");
  SetLong(
    "Forged by the great dwarven smiths from before the Gods War, "
    "axe is of a quality unseen in millennia.  An ultra-thin blade "
    "of mithril caps a near white haft made of the rare llonitir "
    "wood, making it incredibly light."
    );
  SetMass(170);
  SetValue(3000);
  SetDamagePoints(6000);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(23);
  SetVendorType(VT_WEAPON);
  SetProperty("magic","The material of the axe itself glows with power.");
  SetProperty("history","Originally forged for Kalas Orcbane, the holy axe "
              "has been passed down to his successors for well over two "
              "thousand years before the Gods War.  The haft itself was "
              "formed from a piece of the holy wood, llonitir, that was "
              "given as a gift from the elves cementing a bond of "
              "brotherhood between the two races.");
  SetMaterials( ({ "mithril" }) );
  SetRepairSkills( ([
    "mithril working" : 16,
    "weapon smithing" : 16,
    "wood working" : 8
    ]) );
  SetRepairDifficulty(60);
}
