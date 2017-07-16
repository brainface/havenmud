/* An average kobold warrior - male */
// mahkefel 2010: made into "guard"

#include <lib.h>
inherit LIB_SENTIENT;
#include "../ruins.h"
#include "../wanted.h"
int CheckPoster();

static void create() {
  ::create();
  SetKeyName("kobold");
  SetId( ({ "warrior", "guard", "arcanith_person" }) );
  SetAdjectives( ({ "kobold", "male", "man" }) );
  SetShort("a kobold warrior");
  SetLong("This short squat humanoid looks like the cross between a dog and "
          "a lizard.  The dog-like head has too large eyes that seem to glow "
          "red and two short horns.  Scales cover his body and are dirty "
          "brown.  He looks undernourished.");
  SetRace("kobold");
  SetClass("fighter");
  SetGender("male");
  SetLevel(2);
  SetMorality(-25);
  SetAction(5, ({ "!growl", "!snarl",
                  "The kobold searches around for anything valuble." }) );
  SetInventory( ([
      OBJ "/small_shield" : "wear shield on right arm",
      OBJ "/shortsword_old" : "wield sword" ]) );
  SetDie("The kobold howls as he falls to the ground.");
  SetFriends("arcanith_person");
}

int CheckPoster() {
  if (this_player()->GetInvis())
  {
    return 0;
  }

  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1)
  {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("say Hate stranger!");
    eventForce("say Kill stranger!");
    SetAttack(this_player());
    return 1;
   }
  return 0;
}
