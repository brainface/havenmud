#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Patriarch Grigory");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("priest");
  SetGender("male");
  SetShort("Grigory the Patriarch of Kylin in Gurov");
  SetId( ({ "grigory", "patriarch", "priest", "gurov_citizen" }) );
  SetAdjectives( ({ "grigory", "patriarch", "gurov", "kylin", "of", "in" }) );
  SetLong(
    "Patriarch Grigory is a large man with a flowing grey beard.  His "
    "girth is matched by an intense gaze on his face that seems to spell "
    "disaster for those opposed to his philosophy. He has large, thick "
    "hands which seem prepared for both war and religion. His orthodox belief "
    "in the superiority of Kylin is a burning torch in the north."
    );
  SetTown("Gurov");
  SetReligion("Kylin", "Kylin");
  SetMorality(1000);
  SetUniqueSkills( ([
    ]) );
  SetLevel(75);
  SetSpellBook( ([
    "divine magic fully" : 100,
    "mend"               : 100,
    "revive"             : 100,
    "sanctify"           : 100,
    "bless"              : 100,
    "divine mana"        : 100,
    "blessed water"      : 100,
    "wall of force"      : 100,
    ]) );
  SetPlayerTitles( ([
    "newbie"   : "the Orthodox Mendicant of Kylin",
    "mortal"   : "the Orthodox Priest of Kylin",
    "hm"       : "the Orthodox Metropolitan of Gurov",
    "avatar"   : "the Patriarch of the North",
    "fighter"  : "the Orthodox Monk",
    "cavalier" : "the Orthodox Paladin of Kylin",
    ]) );
  SetFreeEquip( ([
    STD_BLUNT "iron_mace" : 1,
    ]) );
  SetAction(5, ({
  	"!cast wall of force",
  	"!cast wall of force",
  	"!speak For the glory of Kylin, we preach!",
  	"!speak Convert and be saved!",
  	"!speak Join the religion, become a cleric!",
  	}) );
  SetCombatAction(30, ({
    "!cast sanctify",
    "!cast bless on hammer",
    "!cast bless on grigory",
    "!cast wall of force",
    }) );
  SetInventory( ([ 
    GUROV_OBJ "crobes"         : "wear robes",
    GUROV_OBJ "mithril_hammer" : "wield hammer"
   ]) );
  SetFirstCommands( ({ 
  	"cast wall of force", 
  	"cast wall of force" 
  	}) );
}
