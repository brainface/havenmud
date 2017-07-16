#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"
int CheckVale();

static void create() {
   sentient::create();
   SetKeyName("dark ghoul");
   SetShort("a dark ghoul");
   SetId( ({ "ghoul" }) );
   SetAdjectives( ({ "dark" }) );
   SetLong("The demon fades into the atmosphere with his shady image "
           "and dark, half-present features.  His eyes gaze out "
           "with a haunted expression, bulging slightly from his sockets, "
           "fearing the spirits of the graves he robs and, at the same "
           "time, almost laughing at them.");
  
   SetGender("male");
   SetProperty("vale_undead", 1);
   SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   SetRace("demon");
   SetClass("rogue");
   SetLevel(17);
   SetEncounter( (: CheckVale :) );
   SetInventory( ([
                    VC_OBJ + "/c_skull" : 1,
                    VC_OBJ + "/c_brclt" : 1+random(2),
                    VC_OBJ + "/c_rg_og" : 1+random(3),
                    VC_OBJ + "/c_neckl" : 1+random(2),
                    VC_OBJ + "/c_anklet" : 1,
               ]) );
   SetMorality(-390);
   SetLimit(3); SetWander(22);
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
