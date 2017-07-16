#include <lib.h>
#include <music.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("harmonic replenishment");
  SetSongType(SONG_OTHER);
  SetRules("");
  SetSkills( ([
     "vocal music" : 10,
     "instrumental music" : 10,
    ]) );
  SetStaminaCost(20, 10);
  SetDifficulty(35);
  SetHelp( 
     "The bard sings voice and plays their instrument in perfect harmony "
     "allowing them to draw upon their physical endurance to replenish their "
     "magical energies. Attempting to replenish your magical energies when they "
    "are full will cause extreme damage, be warned."
    );
  }

varargs int eventSing(object who, int level, mixed limb, object array tars) {
  int amt, base, rat;

  rat = who->GetSkillLevel("vocal music");
  rat += who->GetLevel();
  switch (rat) {
    case 0..20:
       rat = 5;
       break;
    case 21..40:
       rat = 4;
       break;
    case 41..60:
       rat = 3;
       break;
   default:
       rat = 2;
       break;
    }
  amt = 30 / rat;
  if (who->GetMagicPoints () == who->GetMaxMagicPoints()) {
    send_messages("",
      "$agent_possessive_noun body rebels at sound of the beautiful harmony. ",
      who, 0, environment(who) );
    who->eventReceiveDamage(load_object(STD_DUMMY "magicshock"), MAGIC, amt, who->GetTorso(), 1);
    who->eventDisplayStatus();
    return 1;
   }
  if (who->GetStaminaPoints () < 30) {
    send_messages("fail",
      "$agent_name $agent_verb in creating a harmony.",
      who, 0, environment(who) );
     return 1;
   }
  who->AddMagicPoints(amt);
  send_messages("create", 
    "$agent_possessive_noun voice echoes out melding with $agent_possessive "
    "instrument creating a perfect harmony.",
    who, 0, environment(who) );
  who->eventDisplayStatus();
  return 1;
  }
