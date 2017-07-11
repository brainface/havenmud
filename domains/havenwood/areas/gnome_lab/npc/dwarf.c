
#include <lib.h>
#include "../gnome_lab.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("dwarf");
  SetId( ({"dwarf","guard"}) );
  SetShort("a dwarven guard");
  SetAdjectives( ({"dwarven"}) );
  SetLong(
     "This attentive guard is of average height for a dwarf. He "
                 "has dark skin, short braid brown hair and a unkept long "
                 "beard. The dwarf views the world through dark green eyes. "
                 "He is relaxed in his stance but he keeps his footing ready "
                 "for trouble.");
  SetClass("fighter");
  AddSkill("pole combat",1,1);
  RemoveSkill("hack combat");
  RemoveSkill("slash combat");
  SetRace("dwarf");
  SetLevel(6);
  SetGender("male");
  SetMorality(100);
  SetAction(5, ({
     "!say did you bring me my specimens? Always about the specimens.",
                 "!emote raises an eyebrow to your intrusion.",
                 "!say never again will I work for a mage.",
                 "!say I cannot wait to finish this job.",
     }) );
  SetCombatAction(4, ({ 
     "!yell Brothers come to my aid!",
     }) );
  SetInventory( ([
     G_OBJ + "pole"       : "wield pole",
     G_OBJ + "pants"  : "wear pants",
                 G_OBJ + "jacket" : "wear jacket",
                 G_OBJ + "boots"  : "wear boots",
     ]) );
//  SetEncounter();
}
