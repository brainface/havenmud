// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

int type = random(2);

static void create() {
  sentient::create();
  SetMorality(100);

  if (type == 0) {
  SetKeyName("small boy");
  SetId( ({ "boy" }) );
  SetAdjectives( ({ "a", "small" }) );
  SetShort("a small boy");
  SetLong(
     "This young child is one of the local residents living within the "
     "trading post. He runs around playing as children do with little "
     "care in the world. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("male");
  SetSize(SIZE_SMALL);
  SetSkill("blunt combat", 1, 1);
  SetLevel(1);
  SetInventory( ([
     S_OBJ + "rock" : "wield rock in right hand",
     S_OBJ + "stick" : "wield stick in left hand",
     S_OBJ + "s_pants" : "wear pants",
  ]) );
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetAction(1, ({
     "!laugh merr",
     "!whee",
     "!chuckle merr",
  }) );
  SetCombatAction(1, ({
     "!say This is the happiest day of my sad life...",
  }) );
}

  if (type == 1) {
  SetKeyName("little girl");
  SetId( ({ "girl" }) );
  SetAdjectives( ({ "a", "little" }) );
  SetShort("a little girl");
  SetLong(
     "This young child is one of the local residents living within the "
     "trading post. She runs around playing as children do with little "
     "care in the world. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("female");
  SetSize(SIZE_SMALL);
  SetSkill("melee combat", 1, 1);
  SetLevel(1);
  SetInventory( ([
     S_OBJ + "s_dress" : "wear dress",
  ]) );
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetAction(1, ({
     "!laugh merr",
     "!whee",
     "!chuckle merr",
  }) );
  SetCombatAction(1, ({
     "!say You're mean!",
  }) );
}

}
