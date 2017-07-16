// Song of forgotten battles
// increases str and dur
// Thoin@haven

#include <lib.h>
#include <music.h>

int eventEndForce(object);
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("song of forgotten battles");
  SetSongType(SONG_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "vocal music" : 125,
     "instrumental music" : 125,
  ]) );
  SetMagicCost(100, 100);
  SetDifficulty(152);  //Should fail till ~30%
  SetHelp(
          "Using this spell, a powerful bard will sing about long forgotten "
          "battles inspiring those who listen to it to preform better in "
          "battle as well as to grant them strength and durability they "
          "did not previously have."
     );
}
int CanSing(object who, int level, mixed limb, object array targets)
{
  object target = targets[0];
  if( target->GetProperty("forgotten_battle"))
  {
    message("system", "The melody of long lost battles already reverberates "
            "around the target.", who);
    return 0;
  }
  return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("vocal music") +  who->GetSkillLevel("instrumental music"))/15;
   if (amt > 50) amt = 50;
   dur = (level * (15 + 10 + who->GetSkillLevel("vocal music")/20));
  target->SetProperty("forgotten_battle", 1);
  call_out( (: eventEndForce, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("durability", -amt, dur);
    target->AddStatBonus("strength", -amt, dur);
      send_messages( ({ "sing", "cause" }), "$agent_name $agent_verb a note "
        "off key that $agent_verb $target_name to become weak and "
        "sluggish.", who, target,
        environment(target));
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

    send_messages( ({ "sing", "cause" }), "$agent_name $agent_verb "
      "a beautiful melody of battles long pass to $target_name that "
      "$agent_verb $target_objective to become strong and courageous. ",
      who, target, environment(target));
  target->AddStatBonus("durability", amt, dur);
  target->AddStatBonus("strength", amt, dur);
  return 1;
}

int eventEndForce(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("forgotten_battle");
        who->RemoveStatBonus("strength");
        who->RemoveStatBonus("durability");
        who->eventPrint("%^YELLOW%^You return to normal.%^RESET%^");
        return 1;
}
