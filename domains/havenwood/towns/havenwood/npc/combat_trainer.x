#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../wood.h"
inherit LIB_TRAINER; 

static void create() {
  ::create();   
  SetKeyName("eller");
  SetId( ({"eller", "specialist"}) );
  SetAdjectives( ({"weapon", "the"}) );
  SetShort("Eller the Weapon Specialist");
  SetLong(
    "Jagged scars crawl down the face and neck of Eller "
    "a tribute to his well earned knowledge and expertise. "
    "Eller is shorter than average and husky for a wild-elf "
    "but carries himself well."
  );
  SetTown("Havenwood");
  SetRace("wild-elf");           
  SetClass("fighter");            
  SetLevel(100);
  SetMorality(0);
  SetTown("Havenwood");
  SetCurrency("imperials",random(300) + 1000);
  SetGender("male");
  SetInventory( ([
    STD_SLASH "longsword" : "wield my longsword",
    STD_HACK "large_axe" : "wield my axe",
  ]) );
  SetAction(10, ({
    "!say Those were the days!",
    "!say The orcs will never forget this wild-elf's name!",
    "!emote cackle",
    }) );
  SetTrainingSkills( ({
    "knife combat",
    "slash combat",
    "pole combat",
    "blunt combat",
    "hack combat",
    "pierce combat",
    "projectile combat",
    "multi-weapon",
  }) );
}
