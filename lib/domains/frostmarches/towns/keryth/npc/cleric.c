#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../keryth.h"

inherit LIB_LEADER;

void DoSomething();

static void create() {
  leader::create();
  SetKeyName("azogar");
  SetShort("Azogar, High Priest of Soirin");
  SetId( ({ "azogar", "priest", "soirin priest", "soirin" }) );
  SetLong("Like a building, Azogar stands here almost completely immovable.  "
          "His rugged countenance conveys power and duty to his faith, while "
          "hinting at a keen intelligence.  Though most Goden prefer to wear "
          "a minimal amount of clothing to be comfortable in the coldness of "
          "Keryth, Azogar chooses to never allow himself that comfort, as he "
          "feels that it can only serve to weaken him.");
  SetRace("goden");
  SetClass("priest");
  SetSkill("pole combat", 1, 2);
  SetLevel(85);
  SetGender("male");
  SetReligion("Soirin", "Soirin");
  SetTown("Keryth");
  SetMorality(-1500);
  SetCurrency("senones", 10);
  SetUniqueSkills( ([
    "blunt combat" : 0,
    "knife combat" : 1,
    "stealth" : 2,
    ]) );
  SetSpellBook( ([
    "barrier of faith" : 100,
    "poison arrow"     : 100,
    "purify"           : 100,
    "pain touch"       : 100,
    ]) );
  SetAction(10, ({
    "!cast barrier of faith"
     }) );
  SetCombatAction(60, (: DoSomething :)); 
  SetTaughtSpheres( ({
    "clerical",
    "clerical necromancy",
    "clerical evokation",
    "religion soirin"
  }) );
  SetInventory( ([
    K_OBJ + "/cleric_staff" : "wield staff"
  ]) );
  
  SetPlayerTitles( ([
      "newbie" : "the Tempted",
      "mortal" : "the Wielder of the Black Rose",
      "hm"     : "the Divine Theorist of Avarice",
      "legend" : "the Zealous Preacher of Lust",
      "avatar" : "the Ravenous Hierophant",
  ]) );
  SetFreeEquip( ([
       STD_KNIFE + "freeknife" : 1,
    ]) );
  SetFirstCommands( ({
      "cast barrier of faith",
      "cast barrier of faith",
      "cast barrier of faith",
      "cast barrier of faith",
      }) );
}

void DoSomething() {
  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast barrier of faith");
    return;
  }
  
  if (random(2)) {
    eventForce("cast " + (random(3) ? "poison arrow" : "pain touch" ));
    return;
  }
  
  if (random(2)) {
    eventForce("cast purify");
    return;
  }
  

  /*if ((!random(3)) &&
      (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2))) &&
      (sizeof(GetCurrentEnemy()->GetWielded()) != 0)) {
    eventForce("disarm");
    return;
  }*/


}

