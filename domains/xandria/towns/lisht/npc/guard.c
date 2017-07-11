//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
CheckWanted();
inherit LIB_TOWNGUARD;
#include "../wanted.h"
void ChatRes();

static void create() {
  ::create();
  SetKeyName("guard");
  SetFriends( ({ "apophis", "captain_neith", "general_sefet",
                "hathor", "imhotep", "irenakhty", "neferu",
                "pharaoh", "sekhemre", "sheftu", "thoth",
                "sentry", "citizen", "child", "ptah",
                "guard", "patron", "duamutef",
                 }) );
  SetShort("a Guard of Lisht");
  SetRace("gnoll");
  SetClass("cavalier");
  SetTown("Lisht");
  SetLevel(55);
  SetBaseLanguage("Rehshai");
  SetGender("male");
  SetLong("This gnoll is the law here in Lisht. It seems he "
          "enjoys his job, and is pretty good at it, too.");
  SetInventory( ([
    LISHT_OBJ + "guard_armour" : "wear suit",
    LISHT_OBJ "spear" : 2,
    LISHT_OBJ "helm" : "wear helm",
  ]) );
  SetFirstCommands( ({ "wield spears", "wear mail" }) );
  SetCurrency("deben",random(500));
  SetLimit(15);
  SetId( ({ "guard" }) );
  SetAdjectives( ({ "lisht", "town" }) );
  SetWander(6);
 
  SetAction(1, ({
    "!speak Go about your business.",
    "!speak Selket lends Lisht her might. You would be a fool "
    " to go against her.",
    "!speak Obey the law of the Pharaoh, may he live forever!",
   }) );
  SetCombatAction(10, "!impale");
 }

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
/*   if ( (this_player()->GetTown() != "Lisht") &&
   (this_player()->GetReligion() != "Enniae") ) {
      eventForce("speak Leave this place or die!");
      eventForce("attack " + this_player()->GetKeyName());
      return 1;
      }  */
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell Fellows, help me to dispatch this fool!");
     SetAttack(this_player());
    return 1;
   }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
   }
  return 0;
 }
