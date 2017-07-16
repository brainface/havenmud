#include <lib.h>
#include <domains.h>
#include <damage_types.h>
#include <daemons.h>

inherit LIB_PIRATE;

void eventSpecial();

static void create() {
  ::create();
  SetKeyName( "corsair" );
  SetShort("a buxom corsair");
  SetId( ({ "corsair", "captain", "dark-elf", "female", "woman" }) );
  SetAdjectives( ({ "buxom" }) );
  SetRace("dark-elf");
  SetTown("Malveillant");
  SetReligion("Soirin");
  SetClass("sailor");
  SetClass("rogue");
  SetMorality(-2000);
  SetSkill("swashbuckling",1);
  SetSkill("dirty tricks",1);
  SetLevel(200);
  SetLong(
    "Not your average corsair, this buxom dark-elven beauty "
    "commands her ship with an iron-fist ruling. Her "
    "long, lustrous black hair and full, pouty lips belie "
    "the cruelty in her sneer and the terror of her blade. "
//  the terror of her hook???
  );
  SetGender("female");
  SetCaptainAggressiveness(150);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/rapier" : "wield rapier",
    INNERSEA_ENCOUNTERS "obj/jeweled_dagger" : "wield dagger",
    INNERSEA_ENCOUNTERS "delf_marauder/cor_boots" : "wear boots",
    INNERSEA_ENCOUNTERS "delf_marauder/cor_shirt" : "wear shirt",
    INNERSEA_ENCOUNTERS "delf_marauder/cor_corset" : "wear corset",
    INNERSEA_ENCOUNTERS "delf_marauder/cor_pants" : "wear pants",
  ]) );

  SetProperty("pirate", "pirate");
  SetShipWander(1);
  SetCurrency( "roni", 10000);
  SetAction(25, ({
    "!emote sneers menacingly.",
    "!emote winks seductively.",
    "!say secure the top sail, you filthy rats!",
    "!emote puts her hands on her hips and sighs in exasperation.",
    "!say I'm desperate for an ale.",
    }) );
  SetCombatAction(20, (:eventSpecial:) );
  //SetFriends( ({"scalawag", "donnie"}) );
  SetMinLevel(200);
  SetMaxLevel(500);
  SetEncounterDifficulty(5);
  SetBoarder(INNERSEA_ENCOUNTERS "delf_marauder/donnie");
  SetFirstMate(INNERSEA_ENCOUNTERS "delf_marauder/scalawag");
  SetPassengerAttacker(INNERSEA_ENCOUNTERS "delf_marauder/scalawag");
  // there can be only one donnie!
  SetMaxBoarders(1);
}

void eventSpecial() {
  object pirate;
  switch(random(4)) {
    case 0:
      message("enter", "A filthy scalawag scurries to the aid "
        "of his captain!", environment(this_object()));
      pirate = new(GetFirstMate());
      pirate->SetLevel( GetLevel() - 2);
      pirate->eventMove(environment());
      call_out( (: call_other, pirate, "eventForce", "yell protect the captain!" :), 2 );
      call_out( (: call_other, pirate, "eventForce", "guard first corsair" :), 2 );
      break;
    case 1:

      eventForce("harry");
      break;
    case 2:
      eventForce("lunge");
      break;
    case 3:
      eventForce("skewer");
      break;
    // arglebargle instant death by spit.
    case 4:
      eventForce("hock"); // dirty tricks, others swashbuckling
      break;
 }
}

