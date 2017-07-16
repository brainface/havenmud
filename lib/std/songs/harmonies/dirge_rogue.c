//
// Luck spell for Minstrel
// Thoin@Haven

#include <lib.h>
#include <music.h>

int eventEndPlanar(object);
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("dirge of the rogue");
  SetSongType(SONG_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "vocal music" : 140,
     "instrumental music" : 140,
               ])  );
  SetMagicCost(75, 75);
  SetDifficulty(125);
  SetHelp(
          "This dirge is about famous and infamous rogues that have continuously "
          "been hunted down for there crimes. The dirge increases the luck "
          "of the target in hopes that it aids them in not getting caught.");
}

int CanSing(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("dirge_rogue")) {
    message("system", "That person is already affected by the dirge."
            , who);
    return 0;
  }
  

  return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("vocal music") +
    who->GetSkillLevel("instrumental music"))/15;
   dur = (level * (15 + 10 + who->GetSkillLevel("vocal music")/20));
  target->SetProperty("dirge_rogue", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("luck", -amt, dur);
      send_messages( ({ "sing", "cause" }), "$agent_name $agent_verb a note "
        "off key that $agent_verb $target_name to make a funny face.", who, target,
        environment(target));
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "sing", "use" }), "$agent_name $agent_verb a melancholy dirge "
                  "about rogues long gone to $agent_reflexive. At the end of the "
                  "dirge $agent_name can't help but grin.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "sing", "use" }), "$agent_name $agent_verb a melancholy dirge "
                  "about rogues long gone to $target_name. At the end of the dirge "
                  "$target_name can't help but grin.", who, target, environment(target));
  }
  target->AddStatBonus("luck", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("dirge_rogue");
        who->RemoveStatBonus("luck");
        who->eventPrint("%^YELLOW%^You feel unlucky again.%^RESET%^");
        return 1;
}

