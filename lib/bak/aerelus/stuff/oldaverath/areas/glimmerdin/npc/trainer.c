#include <lib.h>
#include "../glim.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("bralor");
  SetShort("Bralor Ironfist, the Trainer of Weapon Skills");
  SetReligion("Kylin",);
  SetTown("Glistendin");
  SetId( ({ "bralor", "ironfist",  "trainer" }) );
  SetLong("Bralor Ironfist is an ancient dwarf with a pure white "
          "beard.  He old for a dwarf, but he is far from frail.  He is one "
          "of the finest warriors in the entire province, and his will "
          "defies time itself.");
  SetRace("dwarf");
  SetGender("male");
  SetClass("fighter");
  SetLevel(75);
  SetInventory( ([
    G_OBJ + "leader_weapon" : "wield hammer",
    ]) );
  SetTrainingSkills( ({ 
  	"hack attack", "hack defense", "slash attack",  
  	"slash defense", "multi-weapon", "multi-hand", 
  	"blunt attack", "blunt defense", "knife attack",
  	"knife defense", "pole attack", "pole defense",
  	}) );
  SetMorality(200);
}
