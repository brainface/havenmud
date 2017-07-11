#include <lib.h>
#include "../path.h"
#include <std.h>

inherit LIB_TRAINER;


static void create() {
  ::create();
  SetKeyName("vladimir");
  SetShort("Vladimir the Wise, WeaponsMaster of the Shire");
  SetId( ({ "vladimir", "weaponsmaster", "master", "vlad" }) );
  SetAdjectives( ({ "wise", "weapons", "weapon" }) );
  SetRace("halfling");
  SetTown("Lloryk");
  //RemoveClass("merchant");
  SetClass("fighter");
  SetLevel(30);
  SetMorality(-100);
  SetTrainingSkills( ({
  	"knife combat", 
  	"slash combat",
  	"blunt combat", 
  	"melee combat",
    "weapon smithing", 
    "armour smithing", 
    "metal working", 
    "leather working",
  	"multi-weapon", 
  	"pole combat",
  	"projectile combat", 
  	"pierce combat",
    "textile working",
  	"hack combat",
     }) );
 SetLong("Vladimir is a slightly aging halfling, but his reflexes are "
         "as sharp as any in town. His fervent desire is to teach all "
         "halflings the arts of war to defend the Shire from the swamp."
         );
 SetInventory( ([
   STD_SLASH "bluesword" : 2,
   ]) );
 SetFirstCommands( ({
 	 "wield swords",
 	 }) );
}




