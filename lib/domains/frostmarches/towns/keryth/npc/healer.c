#include <lib.h>
#include <damage_types.h>
#include "../keryth.h"

inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("ziona");
  SetGender("female");
  SetLong("Ziona's gaze pierces through all she surveys.  Her dark eyes "
          "could penetrate into the very soul and read one's hopes, dreams, "
          "passions, and fears like an open book.  Her long fingernails "
          "look razor sharp and she appears disappointed with her "
          "surroundings, as if she wanted to be something other than a "
          "healer.");
  SetShort("Ziona the Healer");
  SetRace("goden");
  SetId( ({ "ziona", "healer" }) );
  SetReligion("Soirin", "Soirin");
  SetTown("Keryth");
  SetMorality(-1000);
  SetClass("priest");
  SetSkill("melee combat", 20, 1);
  SetLevel(15);
  SetCurrency("senones", random(8)+10);
  SetLocalCurrency("senones");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  	]) );
  SetMeleeDamageType(SLASH);
  SetInventory( ([
    K_OBJ + "/common_pants" : "wear pants"
  	]) );
 
  SetSpellBook( ([
  	"choking shadows"   : 100,
  	"asphyxiation"      : 100,
  	"cloak of darkness" : 100,
  	"poison arrow"      : 100,
  	]) );
  SetCombatAction(40, ({
  	"!cast choking shadows",
  	"!cast asphyxiation",
  	"!cast cloak of darkness",
  	"!cast poison arrow",
  	}) );
}
