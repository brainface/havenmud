// mahkefel 20111017
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_SHIPCAPTAIN;

void doAction();
int killDaPolice();


static void create() {
  string gender;
  string possessive;
  string pronoun;

  ::create();
  // random gender
  gender = random(2) ? "male" : "female";
  possessive = "his";
  pronoun = "he";
  if (gender == "female") {
    possessive = "her";
    pronoun = "she";
  }

  // descriptive text
  SetGender(gender);

  SetKeyName("slave");
  SetShort("an escaped slave (elf)");
  SetId( ({ "slave","elf" }) );
  SetAdjectives( ({ "escaped","slave","elf" }) );
  SetRace("elf");
  SetTown("Haven");
  SetMorality(500);
  SetClass("merchant");
  SetSkill("blunt combat",1);
  SetLevel(10);
  SetLong("This poor wretch looks to have been a "
    "prosperous merchant or adventurer before being captured by "
    "slavers. "+ capitalize(pronoun) + " does not seem to have taken "
    "well to captivity, judging by "+possessive+" improvised "
    "weaponry." );
  SetCaptainAggressiveness(80);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/broken_timber" : "wield timber",
  ]) );
  SetProperty("pirate", "haven");
  SetShipWander(1);
  SetProperty("will_pirate",0); // will not pirate your ship
  SetCombatAction(10, ({
    "!say I won't be taken alive!",
    "!say Better dead than a slave!",
  }) );
  SetAction(10, ({
    "!say Do you know the way to Haven Town?",
    "!say They caught me off Imperial Road, in the dead of night.",
    "!say I have a mate and child, they must wonder what happened to me.",
  }) );
  SetEncounter( (:killDaPolice:) );
}

int killDaPolice() {
  object target = this_player();

  if(target->GetRace() == "gnoll"
    || target->GetRace() == "orc"
    || target->GetRace() == "nosferatu") {

    send_messages( ({"howl", "rush" }),
      "$agent_name $agent_verb in defiance "
      "and $agent_verb at $target_name!",
      this_object(), target, environment(target) );
    return 1;
  }
  return 0;
}
