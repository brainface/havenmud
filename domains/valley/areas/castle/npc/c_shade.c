#include <lib.h>
inherit LIB_SENTIENT;
int CheckVale();

static void create() {
   sentient::create();
   SetKeyName("dim shade");
   SetShort("a dim shade");
   SetId( ({ "shade" }) );
   SetAdjectives( ({ "dim" }) );
   SetLong("The dim shade is hard to make out with his dark ghost-like "
           "figure and the great similarity between him and the shadows "
           "hiding in the corners of the room.  Dimness flickers inside "
           "of the shade.");
   SetGender("male");
  
   SetProperty("vale_undead", 1);
   SetClass("rogue");
   SetLevel(12);
   SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   SetRace("wraith");
   SetLimit(3); SetWander(20);
   SetMorality(-150);
   SetEncounter( (: CheckVale :) );
   SetNoCorpse(1);
   SetUndead(1);
}
int CheckVale() {
  object who = this_player();
  if (!(who->GetProperty("vale_undead"))) {
    SetAttack(who);
  return 1;
  }
return 0;
}
