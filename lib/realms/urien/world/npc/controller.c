// Wandering World Mayor to assign quests to kill animals
// A blanket quester to assign. This can be changed 
// If I find a domain like 'all' to sit him in...
// Urien@Haven 22JUN2023

#include <lib.h>
#include <domains.h>

inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("hunter");
  SetShort("a hooded bounty hunter");
  SetId( ({ "hunter" }) );
  SetAdjectives( ({ "hooded","bounty"}) );
  SetClass("rogue");
  SetLevel(40);
  SetLimit(1);
  SetRace("half-elf");
  SetGender("male");
  SetBaseLanguage("Oiseau");  // Should be Enlan due to trade
  SetTown("BrandeBountyHunter");      
  SetLong(
    "An average heighted half-elf with long black hair and vanilla "
    "features. Soft and unmarred pale skin can be seen exposed "
    "in-between his roguelike armour and tooling. He looks to be "
    "at a young age, fed and groomed well with no scars that are "
    "visible. His head hangs downward in shame looking to either "
    "be in protest or regret to his current duties lacking in "
    "success. Overall, he looks as if he should be doing something "
    "else more entertaining to his desires with contempt and "
    "unrhythmic breathing."
    );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(5, ({
    "!speak You can ask me for quests, if you desire to assist the Brande.",
    "!speak The mages of the Brande need assistance to nullify some..."
           "otherworldly...animals released into Kailie.",
    "!speak Ask me for quests but only after I deem that you can fulfill "
           "the contract or if I have any available for you at this time.",

  }) );
}
