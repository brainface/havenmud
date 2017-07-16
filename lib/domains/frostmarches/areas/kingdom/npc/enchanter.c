
/* an enchanter
   Elasandria 4/19/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("enchantress");
  SetShort("Belasaire, Faerie Enchantress");
  SetId( ({"faerie","enchantress","woman","belasaire","Belasaire"}) );
  SetAdjectives( ({"vivacious","young","wise","powerful"}) );
  SetLong("The woman's skin has a warm green cast to it and brilliant "
         "silver eyes. Her long black hair is streaked with silver, adding "
         "a hint of age to her otherwise young appearance. Wisdom and power "
         "radiate from this vivacious woman.");
  SetGender("female");
  SetRace("faerie");
  SetClass("enchanter");
  SetSkill("shock magic",1,2);
  SetLevel(30);
  SetMorality(600);
  SetAction(5,
         ({"!emote flips through one of her books agitatedly, muttering under "
          "her breath.", "Belasaire flips through one of her books "
          "agitatedly, muttering under her breath."})
         );
  SetInventory( ([
         KINGDOM_OBJ + "rowan staff" : "wield rowan staff",   
         ]) );
  SetSpellBook( ([
         "aura"     : 100,
         "shock"    : 100,
         "fireball" : 50,
         ]) );
  SetCombatAction(80, ({
  	     "!cast aura",
         "!cast shock",
         "!cast fireball"
         }) );
}
