/*  /verbs/players/score.c
 *  from the Dead Soulsr2 Library
 *  Displays a list of score and related info
 *  created by Blitz@Dead Souls
 *  made targettable by Amelia@Haven
 */
// mahk 2018: added offense/defense scores

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

mixed eventScore(string target);

static void create()
{
  daemon::create();
  SetNoClean(1);
  SetHelp("Syntax: score\n\n"
         "Displays information about your character.\n\n"
         "See also: status\n");
}

static string *FoodDegree =
({ "could eat a horse right now!", "could eat plenty more.",
   "could eat some more.", "are partially hungry.",
   "are feeling full.", "feel quite full." });

static string *DrunkDegree =
({ "sober", "tipsy", "drunk", "blitzed",
   "smashed out of your gord", "FUBAR" });

static string *DrinkDegree =
({ "parched", "extremely thirsty", "very thirsty", "thirsty",
   "somewhat thirsty", "not thirsty" });

static string *SmokeDegree =
({ "smoke-free", "slightly tarnished", "tarnished", "badly tarnished",
   "very badly tarnished", "blackened" });

static string *CaffeineDegree =
({ "completely calm", "fairly calm", "calm", "slightly agitated",
   "agitated", "flittering", "spastic", "jittering like a sprite trying "
                                        "to have sex with a hummingbird"
  });

mixed cmd(string target)
{
  if (creatorp(this_player()) && !target)
    return "Creators have no score, get a life.";
  eventScore(target);
  return 1;
}

varargs mixed eventScore(string target)
{
  string *str = ({ });
  int birth, age, x, y, z, c, s;
  object who;
  object printto = this_player();
  int maxdam = 0;

  if (creatorp(printto) && target)
  {
    if (!who = find_living(target))
    {
      printto->eventPrint("Unable to find anyone with that name.");
      return 1;
    }
    if (creatorp(who))
    {
      printto->eventPrint("Uhh, immortals have no score, duh.");
      return 1;
    }
      printto->eventPrint("%^BLUE%^%^BOLD%^Score for "
                               + capitalize(target) + ":%^RESET%^");
  }
  else who = this_player();

  str += ({ sprintf("You are %s, a level %d %s%s.", who->GetCapName(), (int)who->GetLevel(),
            ((int)who->GetUndead() ? "undead " : ""), capitalize((string)who->GetRace() || "nothing"))
         });
  str += ({ "You are " + (string)who->GetMoralityDescription() + " (" + who->GetMorality() + ")." });
  str += ({ "Your native town is "+(string)who->GetNationality()+", and you are a " + who->GetRank() + " of " + who->GetTown() + "." });
  str += ({ "You are " + ((string)who->GetReligion() || "agnostic") + " in faith." });
  str += ({ sprintf("You've solved %s, and have %s.", consolidate(sizeof((string *)who->GetQuests()), "one quest"),
            consolidate(sizeof((string *)who->GetTitles()), "one title") ) });
  birth = (int)who->GetBirth();
  age = ( query_year(time()) - query_year(birth) + SETUP_D->GetStartingAge(who->GetRace()) );
  str += ({ sprintf("You were born on the %d%s day of %s, year %d. (%d years old)",
            query_date(birth), ordinal(query_date(birth)), query_month(birth), (query_year(birth) - SETUP_D->GetStartingAge(who->GetRace())), age)
         });
  if( x = (int)who->GetDevelopmentPoints() < 1 ) {
      y = (int)who->GetLevel() + 1 + (x / -4);
      str += ({ "Development points await you at level " + y + "." });
  }
  else str += ({ "You have " + consolidate( (int)who->GetDevelopmentPoints(), "one development point") + "." });
  if( (int)who->GetWimpy() ) str += ({ "You are feeling wimpy. (" + who->GetWimpy() + "%)" }); else  str += ({ "You are feeling brave." });
  x = (int)who->GetFood() / 17;
  if( x > sizeof(FoodDegree) - 1 )  x = (sizeof(FoodDegree) - 1);
  y = (int)who->GetDrink() / 17;
  if( y > sizeof(DrinkDegree) - 1 ) y = (sizeof(DrinkDegree) - 1);
  z = (int)who->GetAlcohol() / 17;
  if( z > sizeof(DrunkDegree) - 1 ) z = (sizeof(DrunkDegree) - 1);
  c = (int)who->GetSmoke() / 20;
  if (c > (sizeof(SmokeDegree) - 1)) c = (sizeof(SmokeDegree) -1);
  s = (int)who->GetCaffeine() / 75;
  if (s > (sizeof(CaffeineDegree) - 1)) s = (sizeof(CaffeineDegree) -1);
  str += ({ "Caffeine: Your heart is " + CaffeineDegree[s] + " (" + who->GetCaffeine() + ")" });
  str += ({ "Smoke: Your lungs are " + SmokeDegree[c] + " (" + who->GetSmoke() + ")" });
  str += ({ "Food: You " + FoodDegree[x] + " (" + who->GetFood() + ")"});
  str += ({ "Drink: You are " + DrinkDegree[y] + " (" + who->GetDrink() + ")"   });
  str += ({ "Alcohol: You are " + DrunkDegree[z] + " (" + who->GetAlcohol() + ")" });
  str += ({ "Your body temperature is " + WEATHER_D->GetTemperatureString(who->GetWarmth()) + "." });
  
  // offense/defense
  if (sizeof(who->GetWielded())) {
    foreach ( object weapon in who->GetWielded() ) {
      str += ({ "Offense Rating (" + weapon->GetKeyName() + "): " + who->GetWeaponChance(0,weapon->GetWeaponType(),weapon->GetHands(),sizeof(who->GetWielded())) });
      maxdam = who->GetDamageModifier(weapon->GetClass(), weapon->GetWeaponType() + " combat");
      str += ({ "Damage: " + maxdam / (who->GetLevel() * 4) + " - " + maxdam });
    }
  } else {
    str += ({ "Offense Rating (unarmed):" + who->GetWeaponChance(0,"melee",1,1) });
  }  
  str += ({ "Defense Rating: " + who->GetDefense() });
  
  printto->eventPage(str, "info");
  if (who->GetProperty("mission")) {
      MISSION_D->CheckMission(who, who->GetProperty("mission"));
    }
  if (who->GetProperty("mission")) {
    object m = load_object(who->GetProperty("mission"));
    if (m) {
     printto->eventPrint("Your assigned quest is: \n" + m->GetMissionDescription());
    }
  } else {
    printto->eventPrint("You currently have no assigned quest.");
  }
  if (who->GetProperty("swimmer")) {
    printto->eventPrint("Swimming is set to %^RED%^on%^RESET%^. (Be warned!)");
  } else {
    printto->eventPrint("You are scared of the water.");
  }
  return 1;
}

