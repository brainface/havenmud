#include <lib.h>
#include <damage_types.h>
#include "../keryth.h"

inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Rapha Bloodflame");
  SetRace("goden");
  SetShort("Rapha Bloodflame, Master Linguist");
  SetId( ({ "rapha bloodflame", "rapha", "bloodflame", "master linguist",
            "linguist" }) );
  SetLong("Lacking in any physical beauty whatsoever, Rapha spends most of "
          "her time alone with her books or tutoring students.  She seems to "
          "resent anything visually appealing in the world and deals with "
          "others only to get by.");
  SetGender("female");
  SetClass("evoker");
  SetStat("intelligence",55,3);
  SetLevel(40);
  SetMorality(-400);
  SetTaughtLanguages( ({ "Eetria", "Gryshnak", "Slith" }) );
  SetLocalCurrency("senones");
  SetCharge(500);
  SetCurrency("senones",10 + random(30));
  SetMeleeDamageType(SLASH);
  SetSpellBook( ([
          "sphere"     : 100,
          "ice ball" : 100,
          "fireball" : 100,
          ]) );
  SetAction(1, ({
          "!cast sphere",
          }) );
  SetCombatAction(80, ({
          "!cast sphere",
          "!cast ice ball",
          "!cast fireball",
          }) );
  SetInventory( ([
          K_OBJ + "/common_pants" : "wear pants"
          ]) );
}

void eventTeachLanguage(object who, string command, string args) {
  if (!args) {
    eventForce("speak I teach " + conjunction(Languages) );
    return;
  }
  args = capitalize(args);
  if (member_array(args, Languages) == -1) {
    eventForce("speak I don't speak that language.");
    return;
  }
  if (who->GetTown() == "Keryth") {
    if (who->GetCurrency(GetLocalCurrency()) < GetCharge()) {
      eventForce("speak You don't have enough money.");
      eventForce("speak I charge residents of Keryth " + GetCharge() + " " +
                 GetLocalCurrency() + " per class.");
      return;
    }
    who->AddCurrency(GetLocalCurrency(), -(GetCharge()));
  } else {
    if (who->GetCurrency(GetLocalCurrency()) < (GetCharge()*2)) {
      eventForce("speak You don't have enough money.");
      eventForce("speak I charge foreigners " + (GetCharge()*2) + " " +
                 GetLocalCurrency() + " per class.");
      return;
    }
    who->AddCurrency(GetLocalCurrency(), -(GetCharge()*2));
  }
  send_messages( "give",
    "$agent_name $agent_verb $target_name a lesson in " + args + ".", 
    this_object(), who, environment() );
  who->AddLanguagePoints(args,
    who->GetNextLevel(args, who->GetLanguageLevel(args)) -
    who->GetNextLevel(args, who->GetLanguageLevel(args) -1 ) / 4 );
  who->AddLanguagePoints(args, who->GetStatLevel("intelligence"));
  return;
}
