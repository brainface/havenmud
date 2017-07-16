//
// Wisdom spell for Chorist
// Thoin@Haven

#include <lib.h>
#include <music.h>

int eventEndPlanar(object);
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("hymn of the chorist");
  SetSongType(SONG_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "vocal music" : 140,
     "instrumental music" : 140,
               ])  );
  SetMagicCost(75, 75);
  SetDifficulty(125);
  SetHelp(
          "This hymn praises the gods and asks them to bless the targets wisdom. "
          "This hymn is only available to chorists for it takes great faith and "
          "a beautiful voice to achieve such a blessing from the gods.");
}

int CanSing(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("hymn_chorist")) {
    message("system", "That person is already affected by the hymn of chorist."
            , who);
    return 0;
  }
  
  if (who->GetClass() != "chorist") {
    who->eventPrint("Only chorist may use this song.  You should forget it.");
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
  target->SetProperty("hymn_chorist", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("wisdom", -amt, dur);
      send_messages( ({ "sing", "cause" }), "$agent_name $agent_verb a note "
        "off key that $agent_verb $target_name to become dumbfounded and "
        "befuddled.", who, target,
        environment(target));
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "sing", "use" }), "$agent_name $agent_verb a beautiful hymn "
                  "praising $agent_possessive god and calls upon them to bless "
                  "$agent_possessive_noun wisdom.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "sing", "use" }), "$agent_name $agent_verb a beautiful hymn "
                  "praising $agent_possessive god and calls upon them to bless "
                  "$target_possessive_noun wisdom.", who, target, environment(target));
  }
  target->AddStatBonus("wisdom", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("hymn_chorist");
        who->RemoveStatBonus("wisdom");
        who->eventPrint("%^YELLOW%^You feel less wise.%^RESET%^");
        return 1;
}

